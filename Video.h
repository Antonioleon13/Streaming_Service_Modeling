#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>

using namespace std;

class Video{
    protected:
        string nombre, genero, ident,duracion, anioLanzamineto;
        int numCriticos, calificacion;
    public:
        Video();
        Video(string iden, string nom, string gene, string dura, int cali, string anioLanz, int numCrit);
        
        string getIdentificador();
        string getNombre();
        string getGenero();
        string getDuracion();
        int getCalificacion();
        string getAnioLanzamiento();

        void setIdentificador(string iden);
        void setNombre(string nom);
        void setGenero(string gene); 
        void setDuracion(string dura);
        void setCalificacion(int cali);
        void setAnioLanzamiento(string anioLanz);

        virtual void muestraDatos()=0;
        void califica(int cali);
        virtual void printLista();
        virtual int quesoy()=0;
        virtual void consultaSerieyEpi()=0;
};

#endif