#ifndef SERIE_H
#define SERIE_H

#include <iostream>
#include <string>

#include "Video.h"
#include "Episodio.h"

using namespace std;

class Serie:public Video{
    private:
        int numEpisodios;
        Episodio arrEpi[147];
    public:
        Serie();
        Serie(string iden, string nom, string gene, string dura, int cali, string anioLanz, int numEpi, int numCrit, Episodio arregliux[]);
        int getNumEpisodios();
        void setNumEpisodios(int numEpi);
        void muestraDatos();
        void printLista();
        int quesoy();
        void consultaSerieyEpi();
};

#endif