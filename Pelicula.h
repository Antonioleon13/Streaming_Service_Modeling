#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <string>

#include "Video.h"

using namespace std;

class Pelicula:public Video{
    private:
        string nominaciones;
    public:
        Pelicula();
        Pelicula(string iden, string nom, string gene, string nomi, string dura, int cali, string anioLanz, int numCrit);
        string getNominaciones();
        void setNominaciones(string);
        void muestraDatos(); 
        void printLista();
        int quesoy();
        void consultaSerieyEpi();
};

#endif