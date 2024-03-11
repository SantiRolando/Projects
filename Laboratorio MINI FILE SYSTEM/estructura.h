#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
#define T 22



enum _retorno{
	OK, ERROR, NO_IMPLEMENTADA
};
typedef enum _retorno TipoRet;

typedef char *Cadena;

typedef struct _archivo{
	_archivo *sig;
	Cadena NombreArchivo= new char[T];
	Cadena DiceArchivo= new char[T];
	Cadena TipoArchivo= new char[T];
	Cadena RellenoArchivo= new char[T];
	
	
}*Archivo;

typedef struct _directorio{
	Archivo Archivohijo;
	_directorio *Directhermano;
	_directorio *ApuntaRaiz;
	_directorio *Directoriohijo;
	Cadena NombreDirectorio= new char[T];
	
}*Directorio;

struct _sistema{
	
	Directorio NodoRaiz=NULL;
	Archivo NodoPrincipal=NULL;
	
};

typedef _sistema *Sistema;




#endif
