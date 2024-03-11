#include<iostream>
#include <stdio.h>
#include<string.h>
using namespace std;
#include "prototipo.h"
#include "estructura.h"
#include "prototipo_tiporet.h"

int main (int argc, char *argv[]) {
	
	Sistema Raiz= new _sistema;
	char *c;
	Cadena tezto;
	tezto= new char[T];
	Cadena Comando=new char[T];
	Cadena NombreArchivo=new char[T];
	Cadena InfoArchivo= new char[T];
	Cadena numero= new char[T];
	Cadena parametro= new char[T];
	Cadena NombreDirectorio=new char[T];
	
	
	
	
	mostrarRetorno(CREARSISTEMA(Raiz));
	
	while(strcmp(Comando, "FIN")!=0){
	cout<<"Comandos: CREATEFILE/DIR/IF/DF/TYPE/ATTRIB/SEARCH/DC/MKDIR/DELETE/CD/ICRMDIR/DESTRUIRSISTEMA"<<endl;	
	
	cout<<"Ingrese instrucciones: "<<endl;
		cin.getline(tezto,T);
	c = strtok(tezto," ");
			strcpy(Comando, c);
	if(strcmp(Comando, "CREATEFILE")==0){
		c = strtok(NULL, " ");
		strcpy(NombreArchivo, c);
		mostrarRetorno(CREATEFILE(Raiz, NombreArchivo));
	}
	if(strcmp(Comando, "DIR")==0){
		c = strtok(NULL, " ");
		strcpy(parametro, c);
		mostrarRetorno(DIR(Raiz,parametro));
	}
	if(strcmp(Comando, "IF")==0){
		c = strtok(NULL, " ");
		strcpy(NombreArchivo, c);
		c = strtok(NULL, " ");
		strcpy(InfoArchivo, c);	
		mostrarRetorno(IF (Raiz,NombreArchivo,InfoArchivo));
	}
	if(strcmp(Comando, "DF")==0){
		c = strtok(NULL, " ");
		strcpy(NombreArchivo, c);
		c = strtok(NULL, " ");
		strcpy(numero, c);
		mostrarRetorno( DF (Raiz, NombreArchivo, atof(numero)));
	}
	if(strcmp(Comando, "TYPE")==0){
		c = strtok(NULL, " ");
		strcpy(NombreArchivo, c);
		mostrarRetorno(TYPE (Raiz,NombreArchivo));
	}
	if(strcmp(Comando, "ATTRIB")==0){
		c = strtok(NULL, " ");
		strcpy(NombreArchivo, c);
		c = strtok(NULL, " ");
		strcpy(parametro, c);
		mostrarRetorno(ATTRIB (Raiz,NombreArchivo,parametro));
	}
	if(strcmp(Comando, "SEARCH")==0){
		c = strtok(NULL, " ");
		strcpy(NombreArchivo, c);
		c = strtok(NULL, " ");
		strcpy(tezto, c);
		mostrarRetorno(SEARCH(Raiz,NombreArchivo, tezto));
	}
	if(strcmp(Comando, "DC")==0){
		c = strtok(NULL, " ");
		strcpy(NombreArchivo, c);
		c = strtok(NULL, " ");
		strcpy(numero, c);
		mostrarRetorno(DC (Raiz,NombreArchivo, atof(numero)));
	}
	if(strcmp(Comando, "MKDIR")==0){
		c = strtok(NULL, " ");
		strcpy(NombreDirectorio, c);
		mostrarRetorno(MKDIR(Raiz,NombreDirectorio));
	}
	if(strcmp(Comando, "DELETE")==0){
		c = strtok(NULL, " ");
		strcpy(NombreArchivo, c);
		mostrarRetorno(DELETE (Raiz,NombreArchivo));
	}
	if(strcmp(Comando, "CD")==0){
		c = strtok(NULL, " ");
		strcpy(NombreDirectorio, c);
		c = strtok(NULL, " ");
		mostrarRetorno(CD(Raiz,NombreDirectorio));
	}
	if(strcmp(Comando, "IC")==0){
		c = strtok(NULL, " ");
		strcpy(NombreArchivo, c);
		c = strtok(NULL, " ");
		strcpy(tezto, c);
		mostrarRetorno(IC (Raiz,NombreArchivo, tezto));
	}
	if(strcmp(Comando,"RMDIR")==0){
		c = strtok(NULL, " ");
		strcpy(NombreDirectorio, c);
		mostrarRetorno(RMDIR(Raiz,NombreDirectorio));
	}

	
	if(strcmp(Comando, "DESTRUIRSISTEMA")==0){
	//system("clear");
	cout<<"El programa a sido borrado"<<endl;
	return 0;
	}
	
	
	}

	
	return 0;
}

