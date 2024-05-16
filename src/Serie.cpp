#include <iostream>
#include <string>
#include <windows.h>

#include "Serie.h"
#include "Episodio.h"

using namespace std;

Serie::Serie():Video(){
}

Serie::Serie(string iden, string nom, string gene, string dura, int cali, string anioLanz, int numEpi, int numCrit, Episodio arregliux[]):Video(iden, nom, gene, dura, cali, anioLanz, numCrit){
    numEpisodios=numEpi;
    for (int indice = 0; indice < numEpisodios; indice++) {
        arrEpi[indice] = arregliux[indice];
    }
}

int Serie::getNumEpisodios(){
    return numEpisodios;
}

void Serie::setNumEpisodios(int numEpi){
    numEpisodios=numEpi;
}

void Serie::muestraDatos() {
    cout << "Nombre: " << nombre << endl;
    cout << "Genero: " << genero << endl;
    cout << "Duracion por episodio: " << duracion << "min" << endl;
    cout << "Numero de episodios: " << numEpisodios << endl;
    cout << "Lanzamiento: " << anioLanzamineto << endl;
    cout << "Calificacion: " << calificacion << endl;
    cout << endl;
}

void Serie::consultaSerieyEpi() {
    Episodio despliega;
   
        muestraDatos();
        for (int indice = 0; indice < numEpisodios; indice++) {
            despliega = arrEpi[indice];
            cout << despliega;   //SOBRECARGA 
        }
}

int Serie::quesoy() {
    return 0;
}

void Serie::printLista() {
    cout << "Serie--->" << ident << " , " << nombre << " , " << genero << " , " << duracion << " , " << calificacion << " , " << numEpisodios<< endl;
}