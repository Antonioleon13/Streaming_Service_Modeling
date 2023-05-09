#include "Serie.h"
#include "Episodio.h"

Episodio::Episodio() {
   
    id = "N/A";
    idepi = "N/A";
    titulo = "n/a";
    duracionE = "N/A";
    ncali = 0;
    temporada = 0;
   
}
Episodio::Episodio(string idux, string idepiux, string tituliux, string duraiux, int ncaliux, int tempiux) {
    id = idux;
    idepi = idepiux;
    titulo = tituliux;
    duracionE = duraiux;
    ncali = ncaliux;
    temporada = tempiux;
}
// implementa los m�todos
void Episodio::setId(string idux) {
    id = idux;
}
void Episodio::setIdepi(string idepiux) {
    idepi = idepiux;
}
void Episodio::setTitulo(string tituliux) {
    titulo = tituliux;
}
void Episodio::setDuracionE(string duraiux) {
    duracionE = duraiux;
}
void Episodio::setnCali(int ncaliux) {
    ncali = ncaliux;
}void Episodio::setTemp(int temporiux) {
    temporada = temporiux;
}
string Episodio::getId() {
    return id;
}
string Episodio::getIdepi() {
        return idepi;
}
string Episodio::getTitulo() {
    return titulo;
}
string Episodio::getDuracionE() {
    return duracionE;
}
int Episodio::getnCali() {
    return ncali;
}
int Episodio::getTemp() {
    return temporada;
}
void Episodio::print() {
    cout << "########## Episodio ##########" << endl;
    cout << "Id Serie: " << id << endl;
    cout << "Id Episodio: " << idepi << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion: " << duracionE << endl;
    cout << "Calificacion: " << ncali << endl;
    cout << "Temporada: " << temporada << endl;
}
void Episodio::printLista() {
    cout << "Episodio--->" << id<< " , " << idepi<<" , " << titulo << " , " << duracionE << " , " << ncali<< " , " << temporada << endl;
}
void Episodio::setEpi(string idux, string idepiux, string tituliux, string duraiux, int ncaliux, int tempiux) {
    id = idux;
    idepi = idepiux;
    titulo = tituliux;
    duracionE = duraiux;
    ncali = ncaliux;
    temporada = tempiux;
}
void Episodio::consultaCalificacion(int ncaliux) {
    if (ncali == ncaliux) {
        print();
    }
}

ostream& operator<<(ostream& salida, const Episodio& numero) {
    salida << "Id Serie "<< numero.id << " Id Episodio: " << numero.idepi << " Titulo: " << numero.titulo << " Duracion: " << numero.duracionE << " Calificacion: " << numero.ncali << " Numero de Temporada: " << numero.temporada << endl;
    return salida;
}
void Episodio::califica(int valor) {
    ncali = (ncali + valor) / 2;
    cout << "Nueva Calificacion " << ncali << endl;
}