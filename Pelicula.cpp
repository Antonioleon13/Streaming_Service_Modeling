#include <iostream>
#include <string>
#include <windows.h>

#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula():Video(){
}

Pelicula::Pelicula(string iden, string nom, string gene , string nomi, string dura, int cali, string anioLanz, int numCrit):Video(iden, nom,gene, dura, cali, anioLanz, numCrit){
    nominaciones=nomi;
}

string Pelicula::getNominaciones(){
    return nominaciones;
}

void Pelicula::setNominaciones(string nomi){
    nominaciones=nomi;
}

void Pelicula::muestraDatos() {
    cout << "Nombre: " << nombre << endl;
    cout << "Genero: " << genero << endl;
    cout << "Nominaciones: " << nominaciones << endl;
    cout << "Duracion: " << duracion << "min" << endl;
    cout << "Lanzamiento: " << anioLanzamineto << endl;
    cout << "Calificacion: " << calificacion << endl;
    cout << endl;
}

int Pelicula::quesoy() {
    return 1;
}
void Pelicula::consultaSerieyEpi() {
    cout << endl;
}

void Pelicula::printLista() {
    cout << "Pelicula--->" << ident <<" , "<< nombre << " , " << genero << " , " << duracion <<" , "<< calificacion <<" , "<<anioLanzamineto<< endl;
}



