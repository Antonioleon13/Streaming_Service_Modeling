#include <iostream>
#include <string>

#include "Video.h"

using namespace std;

Video::Video() {
    nombre = "Sin nombre";
    genero = "Sin genero";
    duracion = "0";
    calificacion = 0;
    anioLanzamineto="0";
    numCriticos=0;
}

Video::Video(string iden, string nom, string gene, string dura, int cali, string anioLanz, int numCrit){
    ident=iden;
    nombre=nom;
    genero=gene;
    duracion=dura;
    calificacion=cali;
    anioLanzamineto=anioLanz;
    numCriticos=numCrit;
}

string Video::getIdentificador(){
    return ident;
}

string Video::getNombre(){
    return nombre;
}

string Video::getGenero(){
    return genero;
}

string Video::getDuracion(){
    return duracion;
}

int Video::getCalificacion(){
    return calificacion;
}

string Video::getAnioLanzamiento(){
    return anioLanzamineto;
}

void Video::setIdentificador(string iden){
    ident=iden;
}

void Video::setNombre(string nom){
    nombre=nom;
}

void Video::setGenero(string gene){
    genero=gene;
}

void Video::setDuracion(string dura){
    duracion=dura;
}

void Video::setCalificacion(int cali){
    calificacion=cali;
}

void Video::setAnioLanzamiento(string anioLanz){
    anioLanzamineto=anioLanz;
}

void Video::califica(int cali){
    calificacion=(calificacion*numCriticos+cali)/(numCriticos+1);
    numCriticos++;  
    cout << "**********Nueva Calificacion------------> "<< calificacion << endl;
}

void Video::printLista() {
     cout <<"Video --->" << ident << nombre << genero << duracion << calificacion << endl;
}
