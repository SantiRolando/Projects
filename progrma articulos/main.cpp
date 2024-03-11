#include<iostream>
using namespace std;
#include "prototipo.h"





int main (int argc, char *argv[]) {
	super Nodos;
	Nodos=NULL;
	Cadena Nombreart = new char[T];
	Cadena Nombreart2 = new char[T];
	Cadena Nombreart3 = new char[T];
	Cadena nombrebusco = new char[T];
	Cadena nombreelimino = new char[T];	
	
	cout<<"Ingresa nombre del poducto"<<endl;
	cin.getline(Nombreart,20,'\n');
	Nodos = Ingresoarticulo(Nodos,Nombreart,3, 300);
	
	cout<<"Ingresa nombre del poducto"<<endl;
	cin.getline(Nombreart2,20,'\n');
	Nodos = Ingresoarticulo(Nodos,Nombreart2,2, 200);
	
	
	cout<<"Ingresa nombre del poducto"<<endl;
	cin.getline(Nombreart3,20,'\n');
	Nodos = Ingresoarticulo(Nodos,Nombreart3,10, 340);
	
	Muestronodo(Nodos);
	cout<<endl;
	
	cout<<"Ingrese nombre del articulo que quiere saber su mercaderia"<<endl;
	cin.getline(nombrebusco, T, '\n');
	calcularcapital(Nodos,nombrebusco);
	cout<<"//"<<endl;
	cout<<"Ingrese nombre del articulo que quiere eliminar"<<endl;
	cin.getline(nombreelimino, T, '\n');
	Eliminoarti(Nodos,nombreelimino);
	
	Muestronodo(Nodos);
	
	return 0;
}

