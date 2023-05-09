// Videos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <exception>
#define NOMBRE_ARCHIVO1 "PELIS.csv"
#define NOMBRE_ARCHIVO2 "Series2.csv"
#define NOMBRE_ARCHIVO3 "Episodios2.csv"
using namespace std;

#include "Video.h"
#include "Serie.h"
#include "Pelicula.h"
#include "Episodio.h"

Video* vide[300];
Episodio epis[147];
void menu();


string nombre, genero, duracion, generob;
int numVideos=0, valor = 0, numSerie = 3, numPeli=0, numEpi = 0;

class  InvalidConfigurationException : public exception {
    virtual const char* what() const throw()
    {
        return " Valor invalido ";

    }
} myex;

void leeDatosPeli() {
    ifstream archivo(NOMBRE_ARCHIVO1);
    string linea;
    int i = 0, ncali=0;
    char delimitador = ',';
    // Leemos la primer l�nea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las l�neas
    while (getline(archivo, linea))
    {
        stringstream stream(linea); // Convertir la cadena a un stream
        string id, nom, dura, gene, cali, nomi,anLanz, numCrit;
        // Extraer todos los valores de esa fila
        getline(stream, id, delimitador);
        getline(stream, nom, delimitador);
        getline(stream, gene, delimitador);
        getline(stream, nomi, delimitador);
        getline(stream, dura, delimitador);
        getline(stream, cali, delimitador);
        getline(stream, anLanz, delimitador);
        ncali = atoi(cali.c_str());

        vide[i] = new Pelicula(id, nom, gene, nomi, dura, ncali, anLanz, 10);
        i = i + 1;
    }
    numPeli = i;
    archivo.close();
 
 }
void leeDatosEpisodio() {
    ifstream archivo(NOMBRE_ARCHIVO3);
    string linea;
    char delimitador = ',';
    int i = 0, ncali = 0, ntemp=0;

    // Leemos la primer l�nea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las l�neas
    while (getline(archivo, linea))
    {
         stringstream stream(linea); // Convertir la cadena a un stream
        string id, idepi, nom, dura, cali, temp;
        // Extraer todos los valores de esa fila
        getline(stream, id, delimitador);
        getline(stream, idepi, delimitador);
        getline(stream, nom, delimitador);
        getline(stream, dura, delimitador);
        getline(stream, cali, delimitador);
        getline(stream, temp, delimitador);
        ncali = atoi(cali.c_str());
        ntemp = atoi(temp.c_str());
        epis[i].setEpi(id, idepi, nom, dura, ncali,ntemp);
        i = i + 1;
    }
    numEpi = i;
    archivo.close();  
  
}

void leeDatosSerie() {
    Episodio epiE[100];
    ifstream archivo(NOMBRE_ARCHIVO2);
    string linea;
    char delimitador = ',';
    int i = 0, ncali = 0, tepi;
    i = numPeli;
   
    // Leemos la primer l�nea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las l�neas
    while (getline(archivo, linea))
    {
        stringstream stream(linea); // Convertir la cadena a un stream
        string id, nom, gene, dura, cali, totEpi, anioLan;
        // Extraer todos los valores de esa fila
        getline(stream, id, delimitador);
        getline(stream, nom, delimitador);
        getline(stream, gene, delimitador);
        getline(stream, dura, delimitador);
        getline(stream, cali, delimitador);
        getline(stream, anioLan, delimitador);
        getline(stream, totEpi, delimitador);
        ncali = atoi(cali.c_str());
        tepi = atoi(totEpi.c_str());
        int j = 0;
        for (int i = 0; i < numEpi; i++) {
            if (id == epis[i].getId()) {
                epiE[j] = epis[i];
                j = j + 1;
            }
        }
        tepi = j;
        vide[i] = new Serie(id, nom, gene, dura, ncali,anioLan, tepi ,10, epiE);
;
        i = i + 1;
    }
    numSerie = i;
    numVideos = i;
    archivo.close();
 }
void imprimeDatos() {
    for (int i = 0; i < numVideos; i++) {
        Video* current2 = vide[i];
        current2->printLista();
    }
    for (int i = 0; i < numEpi; i++) {
        epis[i].printLista();
    }
}
void leeDatos() {
    leeDatosEpisodio();
    leeDatosPeli();
    leeDatosSerie(); 
 }
//1. Consultar Videos por Genero
void videoXGenero() {
    int encontrado = 0;
    
    do {
        cout << "Genero a buscar (Drama - Misterio - Accion) -->"; 
        cin >> generob;
        try {
            if ((generob != "Drama") && (generob!="Misterio") && (generob != "Accion") || !cin) throw InvalidConfigurationException();
         }
        catch (exception& e) {
            cout << e.what() << endl;
            // exit(1);
        }
    } while ((generob != "Drama") && (generob != "Accion") && (generob != "Misterio"));
    
    for (int i = 0; i < numVideos; i++) {
        if (generob == vide[i]->getGenero()) {
            Video* current2 = vide[i];
            current2->printLista();
            encontrado = 1;
        }

    }
    if (encontrado == 0) { cout << "No hay Videos con ese Genero" << endl; }
}

int ingresaCalif() {
    int error = 0, letra =0, valido =0;
    int califb = 0;
    do {
            cout << "Calificacion? ";
            cin >> califb;
            if (califb == 0) { valido = 1; }
            else  if ((califb >= 0) && (califb <= 5))  { valido = 1;}
            else { error = error + 1; }
            if (error > 4) {
                cout << "Invalid menu choice exceeded";
                exit(1);
                valido = 1;
            }
    } while (!valido );
    return califb;
}
//2. Consultar Videos por Calificacion
void videoXCalificacion() {

    int  califb = 0, encontrado = 0;
   
    califb = ingresaCalif();
    if (califb == 0) {
        menu();
     }
    else {
        for (int i = 0; i < numVideos; i++) {

            if (califb == vide[i]->getCalificacion()) {
                Video* current3 = vide[i];
                current3->printLista();
                encontrado = 1;
            }
        }
        for (int i = 0; i < numEpi; i++) {
            if (califb == epis[i].getnCali()) {
                epis[i].printLista();
                encontrado = 1;
            }
        }
    }
    if (encontrado == 0) { cout << "No hay Peliculas, ni Series, ni Episodios con esa calificacion" << endl; }
}
//3. Consultar todas las series por Calificacion
void consultarSeriesXCalif() {
    int  califb = 0, encontrado =0;
  //  cout << "Calificacion a buscar ";
    califb = ingresaCalif();
    for (int i = 0; i < numVideos; i++) {

        if (califb == vide[i]->getCalificacion()) {

            Video* current3 = vide[i];
            if (current3->quesoy() == 1) { i = i + 1; 
            }
            else {
                current3->printLista();
                encontrado = 1;
            }
        }
    }
    if (encontrado == 0) { cout << "No hay Series con esa calificacion" << endl; } 
}
//4. Consultar una serie con episodios
void consultarSerieYEpi() {
    int encontrado = 0;
    string  idb = "";
    for (int i = 0; i < numVideos; i++) {
        Video* current3 = vide[i];
            if (current3->quesoy() == 1) {
                i = i + 1;
            }
            else {
                current3->printLista();
            }
    }
    cout << "Serie a buscar ";
    cin >> idb;
    for (int i = 0; i < numVideos; i++) {

        if (idb == vide[i]->getIdentificador()) {

            Video* current3 = vide[i];
            if (current3->quesoy() == 1) { i = i + 1; }
            else {
                current3->consultaSerieyEpi();
                encontrado = 1;
            }
            }
        
        }
    if (encontrado == 0) { cout << "No hay Series con ese Identificador" << endl; }
 }

//5. Consultar peliculas con cierta calificacion
void consultarPelixCalif() {
    int  califb = 0, encontrado =0;
//    cout << "Calificacion a buscar ";
    califb = ingresaCalif();
    for (int i = 0; i < numVideos; i++) {

        if (califb == vide[i]->getCalificacion()) {

            Video* current3 = vide[i];
            if (current3->quesoy() == 0) { i = i + 1; }
            else {
                current3->printLista();
                encontrado = 1;
            }
        }
           }
    if (encontrado == 0) { cout << "No hay Peliculas con esa calificacion" << endl; }
 }
//6. Calificar un video
void calificarVideo() {
    int encontrado = 0;
    string idb = "";
    cout << "Video a calificar ";
    cin >> idb;
   for (int i = 0; i < numVideos; i++) {

        if (idb == vide[i]->getIdentificador()) {

            Video* current3 = vide[i];
            current3->muestraDatos();
        //    cout << "Calificacion a otorgar? ";
            valor = ingresaCalif();
            current3->califica(valor);
            current3->printLista();
            encontrado = 1;
            
        }
   }
    for (int i = 0; i < numEpi; i++) {
        if (idb == epis[i].getIdepi() ) {
            epis[i].print();
       //     cout << "Calificacion a otorgar? ";
            valor = ingresaCalif();
            epis[i].califica(valor);
            epis[i].print();
            encontrado = 1;
        }
    
    }
    if (encontrado == 0) { cout << "No hay Videos con ese Identificador" << endl; }
    
 }

void menu() {
    int error = 0;
    char opcion = ' ';
    do {
        cout << "MENU" << endl;
        cout << "1. Cargar Datos" << endl;
        cout << "2. Consultar Videos por Genero" << endl;
        cout << "3. Consultar Videos por Calificacion" << endl;
        cout << "4. Consultar todas las series por Calificacion" << endl;
        cout << "5. Consultar una serie con episodios" << endl;
        cout << "6. Consultar peliculas con cierta calificacion" << endl;
        cout << "7. Calificar un video" << endl;
        cout << "0. Salir" << endl;
        opcion = cin.get();
       
        switch (opcion) {
        case '1':
            imprimeDatos();
            break;
        case '2':
            videoXGenero();
            break;
        case '3':
            videoXCalificacion();
            break;
        case '4':
            consultarSeriesXCalif();
            break;
        case '5':
            consultarSerieYEpi();
            break;
        case '6':
            consultarPelixCalif();
            break;
        case '7':
            calificarVideo();
            break;
        case '0':
            cout << "Adios" << endl;
            break;
        default:
            try {
                if (((opcion != '5') && (opcion != '2') && opcion != '1' && opcion != '3' && opcion != '4' && opcion != '6' && opcion != '7' && opcion != '0')) throw InvalidConfigurationException();

            }
            catch (exception& e) {
                cout << e.what() << endl;
                error = error + 1;
                if (error > 4) {
                    cout << "Invalid menu choice exceeded";
                    exit(1);
                }
            }
            break;
        }
        cin.ignore();

    } while (opcion != '0');

 }
 
int main() {
    
    leeDatos();
    menu();
   
    return 0;

}
