#include<iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#include "prototipo.h"
#include "struct.h"






super Ingresoarticulo(super Nodos, Cadena nombreart, int canti, int preci){
	super aux1=Nodos;
	
	if(Nodos==NULL){
		super Nuevoproducto = new _super;
		Nuevoproducto->cantidad = canti;
		Nuevoproducto->precio = preci;
		strcpy(Nuevoproducto->nombre, nombreart);
		Nuevoproducto->sig=NULL;
		Nuevoproducto->ant=NULL;
	
		return Nuevoproducto;
	}else{
		super aux2;
		while(aux1->sig!=NULL){
			aux1=aux1->sig;
		}
		aux2=aux1->sig;
		super Nuevoproducto = new _super;
		Nuevoproducto->cantidad = canti;
		Nuevoproducto->precio= preci;
		strcpy(Nuevoproducto->nombre, nombreart);
		Nuevoproducto->sig=NULL;
		Nuevoproducto->ant=aux1;
		aux1->sig=Nuevoproducto;
	}
	return Nodos;
	
}
	
	
	
	
void Muestronodo(super Nodos){
	super aux=Nodos;
	while(aux->sig!=NULL){
		aux=aux->sig;
	}
	while(aux!=NULL){
		cout<<"El producto es: "<<aux->nombre<<"||";
		aux=aux->ant;
	}
}
	

void calcularcapital(super Nodos,Cadena nombreart){
	super aux=Nodos;
	int mercaderia;
	while (aux!=NULL){
		if(strcmp(aux->nombre, nombreart)==0){
			cout<<"Usted busco "<<aux->nombre<<endl;
			mercaderia=aux->cantidad*aux->precio;
			cout<<"La mercaderia del mismo es: "<<mercaderia<<endl;
			return;
		}
		aux=aux->sig;
	}
	cout<<"El producto no existe"<<endl;
}
	
	
	
void Eliminoarti(super Nodos, Cadena nombreart){
		super aux=Nodos;
		while(aux!=NULL){
			if(strcmp(aux->nombre, nombreart)==0){
				super aux2=aux->ant;
				super aux3=aux->sig;
				aux2->sig=aux->sig;
				aux3->ant=aux->ant;
				delete aux;
				return;
			}
			aux=aux->sig;
		}
	cout<<"El producto no existe"<<endl;
	
}







