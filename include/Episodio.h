#ifndef EPISODIO_H
#define EPISODIO_H

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include<cmath>
#include <stdio.h>
#include <cstdlib>

using namespace std;
	
class Episodio {
	private:
		string id;
		string idepi;
		string titulo;
		string duracionE;
		int ncali;
		int temporada; 
		
	public:
		Episodio();
		Episodio(string idux, string idepiux,string tituliux, string duraiux,int ncaliux, int tempiux);
		void print();
		void setId(string idux); 
		void setIdepi(string idepiux);
		void setTitulo(string tituliux);
		void setDuracionE(string duraiux);
		void setnCali(int ncaliux);
		void setTemp(int tempiux);
		string getId();
		string getIdepi();
		string getTitulo();
		string getDuracionE();
		int getnCali();
		int getTemp();
		void califica(int valor);
		void consultaCalificacion(int ncaliux);
		void printLista();
		void setEpi(string idux, string idepiux, string tituliux, string duraiux, int ncaliux, int tempiux);
		friend std::ostream& operator<<(std::ostream&, const Episodio&);
};

#endif
