#ifndef STRUCT_H
#define STRUCT_H
#define T 200
typedef char *Cadena;


typedef struct _super{
	Cadena nombre=new char[T];
	int precio;
	int cantidad;
	_super *sig;
	_super *ant;
}*super;


#endif
