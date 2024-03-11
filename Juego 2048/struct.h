#ifndef STRUCT_H
#define STRUCT_H
#define CANTJ 10
#define LARGOA 10
#define LARGOC 8
#define LARGON 20
#define LARGOAPE 30
#define LARGOL 30	
#define LARGOJUG 10
/*b. Baja de Usuario: permitirá marcar como inactivo al jugador, de manera que en
el listado del punto "a" y del punto "c" no aparecerá, pero si� en el listado del punto "b"
y del punto "d". Si el jugador dado de baja se registra nuevamente, simplemente se
cambiará su estado de inactivo a activo.*/


typedef struct _cadena{
	char palabra[LARGON];  //contiene los caracteres que forman el nombre del paciente.
	int largopalabra; //cantidad de caracteres del nombre
}cadena; //defino estructura cadena para ser utilizada en el nombre del paciente

typedef struct _apellido{
	char ape[LARGOAPE];  //contiene los caracteres que forman el nombre del paciente.
	int largoapellido; //cantidad de caracteres del nombre
}rolando;

typedef struct _digito{
	int numero[LARGOC];  //contiene la cantidad de digitos de la ci.
	int largodigito;  //cantidad de digitos de la ci.
}digito; // defino estructura digito para ser utilizada en la cedula del paciente

typedef struct _fecha{
	int dia;
	int mes;
	int anio;
}fecha; //defino estructura fecha para ser utilizada en la fecha de nacimiento
typedef struct _alias{
	char alias[LARGOA];
	int largoalias;
}elpibe;

typedef struct _localidad{
	char ciudad[LARGOL];
	int largocity;
}doxeado;

typedef struct _juegos{
	fecha fecha;
	int hs;
	int min;
	int condicion;
}juegos;

typedef struct _jugador{
	elpibe alia;
	cadena nombre;
	rolando apeyido;
	digito cedula;
	int edad;
	fecha fechanacimiento;
	doxeado loca;
	char estado;
	juegos partidas[20];
}james; // defino estructura paciente para ser utilizada en el arreglo que guarda los pacientes.







#endif
