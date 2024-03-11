#include<iostream>
using namespace std;
#include <stdlib.h>
#include "prototipo.h"

int main (int argc, char *argv[]){
	int x=0;
	int juego=0;
	james jugadores[CANTJ];
	int ins, tablero [4][4];
	bool juja=true,salir=false;
	InicializoPartidas(jugadores);
	bienvenido();
	do{	
		ins=0;
		do{
			system("clear");
			printf ("Que quiere hacer?\n1-Gestionar un usuario\n2-Jugar\n3-Informes\n4-Salir\n->");
			scanf ("%d",&ins);
		}while(ins!=1&&ins!=2&&ins!=3&&ins!=4);
		switch(ins){
		case 1:MenuGestion(jugadores,x);
			break;
		case 2:generarTablero (tablero);
			system("clear"); 
			juja=jugar(tablero, juja,jugadores,x,juego);
			break;
		case 3:MenuInformes(jugadores,x,juego);
			break;
		case 4:juja=false;
			break;
		}
		if (juja==false)
			salir=true;
		/*switch(ins){
		case 1:generarTablero (tablero);
		system("clear"); 
		jugar(tablero, juja);
		break;
		case 2:juja=false;
		} */
	}while(salir==false&&(ins==1||ins==2||ins==3));
	
	if (ins==4){
		system("clear");
		printf ("Gracias por usar el programa.");
	}
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*IngresoJames(jugadores,x);
	printf ("\nCant X=%d",x);
	getchar();
	bajaUsuario(jugadores,x);
	printf ("\n\nEstado=%c",jugadores[0].estado);
	modificarUsuario(jugadores,x);
	muestroAlias(jugadores[0].alia);
	muestroNombre(jugadores[0].nombre);
	muestroapellido(jugadores[0].apeyido);
	muestrocedula(jugadores[0].cedula);
	muestroEdad(jugadores[0].edad);
	muestroFechanaci(jugadores[0].fechanacimiento);
	muestroLocalidad(jugadores[0].loca);
	*/
	return 0;
}

