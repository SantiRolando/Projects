#ifndef PROTOTIPO_H
#define PROTOTIPO_H
#include "struct.h"
#include <stdlib.h>
#include <time.h>
#define G 2048

void MenuGestion(james jugadores[10],int &x);
cadena ingresonombre();
rolando ingresoapellido();
fecha ingresoFechanacimiento();
james estado();
digito ingresoCedula();
//int ingresoEdad();
doxeado ingresolocalidad();
elpibe ingresoAlias();
void InicializoPartidas(james jugadores[10]);
bool comparoCedulas(james jugadores[10], int x);
bool AuxcomparoCedulas(digito cedaux,james jugadores[10]);
void IngresoJames(james jugadores[10],int &x);
int XdeAuxcomparoCedulas(digito cedaux,james jugadores[],int x);
void bajaUsuario(james jugadores[10],int x);
int	XdeComparoAlias(james jugadores[10],int x,elpibe nick);
void modificarUsuario(james jugadores[10],int x);
bool comparoAlias(james jugadores[10],int x,elpibe nick);
void MenuInformes(james jugadores[10],int x,int juego);
void ListaDeJugadoresA(james jugadores[10],int x);
void ListaDeJugadoresB(james jugadores[],int x,int juego);
void ListaDeJugadoresC(james jugadores[],int x,int juego);
void ListaDeJugadoresD(james jugadores[],int x,int juego);
void OrdenoXAlias(james jugAux[10],int x,james jugadores[10]);
bool legitimidad(james jugadores[10],int x);

void muestroNombre(cadena nombre);
void muestroapellido(rolando apeyido);
void muestrocedula(digito cedula);
//void muestroEdad(int edad);
void muestroFechanaci(fecha fechanacimiento);
void muestroLocalidad(doxeado loca);
void muestroAlias(elpibe alia);




void bienvenido();
void generarTablero (int tablero[4][4]);
bool jugar (int tablero [4][4], bool &juja,james jugadores[10],int x, int &juego);

#endif
