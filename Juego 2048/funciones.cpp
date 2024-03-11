#include<iostream>
using namespace std;
#include "prototipo.h"


void MenuGestion(james jugadores[],int &x){
	int op;
	getchar();
	system("clear");
	do{
		printf ("Que quiere hacer?\n1-Generar un nuevo usuario o pasar uno de ""Inactivo"" a ""Activo""\n2-Dar de baja un usuario existente\n3-Modificar un usuario existente\n4-Regresar.\n->");
		scanf ("%d",&op);
		
		system("clear");
	} while(op!=1&&op!=2&&op!=3&&op!=4);
	switch(op){
	case 1:IngresoJames(jugadores,x);
		system("clear");
		break;
	case 2:bajaUsuario(jugadores,x);
		system("clear");
		break;
	case 3:getchar();
		modificarUsuario(jugadores,x);
		system("clear");
		break;
	case 4:
		break;
	}
}





cadena ingresonombre(){
	int nom=0;
	cadena nombre;
	printf("\ningrese el nombre del jugador:");
	while(nom<LARGON&&(nombre.palabra[nom]=getchar())!='\n'){
		nom++;	
	}
	nombre.largopalabra=nom;
	return nombre;
}

	
	
rolando ingresoapellido(){
	int apen=0;
	rolando apellido;
	printf("\ningrese el apellido del jugador:");
	while(apen<LARGOAPE&&(apellido.ape[apen]=getchar())!='\n'){
		apen++;	
	}
	apellido.largoapellido=apen;
	return apellido;
}
	
	
digito ingresoCedula(){
	/*digito cedaux;
	int ci=0; 
	printf("\nIngrese cedula del paciente sin guiones ni puntos:");
	while(ci<LARGOC&&((cedaux.numero[ci]=getchar())=-48&&getchar()!='\n')){
		ci++;
	}
	cedaux.largodigito=ci;
	return cedaux;
}*/	
	int i=0;
	digito ced;
	printf("\nIngrese la cedula del jugador sin puntos ni guiones: ");
	while(i < LARGOC&&(ced.numero[i]=getchar())!='\n'){
		ced.numero[i]=ced.numero[i]-48;
		i++;
	}
	ced.largodigito=i;
	return ced;
}


int ingresoEdad(){
	int edad;
	printf("\ningrese la edad del jugador:");
	scanf("%d", &edad);
	return edad;
}
	
	
fecha ingresoFechanacimiento(){
	_fecha fecha;
	printf("\nIngrese la fecha denacimiento del jugador d/m/a:");
	scanf("%d/%d/%d",&fecha.dia,&fecha.mes,&fecha.anio);	
	return fecha;
}   	//aun no declarada, tampoco la de ingreso
bool comparoCedulas(james jugadores[], int x){ //Hay que comprar entre las cedulas de los jugadores, no solo con un es particular
		bool cond1=false, cond2=false;
		int j=0, i=0;
		do{
			if (jugadores[x].cedula.largodigito == jugadores[j].cedula.largodigito){
				cond1=true;
			}
			if (jugadores[x].cedula.largodigito != jugadores[j].cedula.largodigito){
				j++;
			}
		}while(cond1==false&&j<x);
		if (cond1==true){
			do{
				int veces=0;
				i=0;
				do{
					if (jugadores[x].cedula.numero[i]==jugadores[j].cedula.numero[i]){
						veces++;
					}
					i++;
					if (veces==jugadores[x].cedula.largodigito){
						cond2=true;
					}
				}while(cond2==false&&i<=jugadores[x].cedula.largodigito);
			}while(cond2==false&&i<jugadores[x].cedula.largodigito);
		}else{
			cond2=false;
		}
		return cond2;
	}

	
bool AuxcomparoCedulas(digito cedaux,james jugadores[],int x){ //unicamente para dar de baja
	bool cond2=false;
	int  i=0;
	/*do{
		if (cedaux.largodigito == jugadores[j].cedula.largodigito){
			cond1=true;
		}
		if (cedaux.largodigito != jugadores[j].cedula.largodigito){
			j++;
		}
	}while(cond1==false&&j<x);
	if (cond1==true){*/
	for (int ju=0;ju<x;ju++){
		do{
			int veces=0;
			i=0;
			do{
				if (cedaux.numero[i]==jugadores[ju].cedula.numero[i]){
					veces++;
				}
				i++;
				if (veces==cedaux.largodigito){
					cond2=true;
				}
			}while(cond2==false&&i<=cedaux.largodigito);
		}while(cond2==false&&i<cedaux.largodigito);
	}
	/*}else{
		cond2=false;
	}*/
	return cond2;
}
	
int XdeAuxcomparoCedulas(digito cedaux,james jugadores[],int x){ //unicamente para dar de baja
	bool cond1=false, cond2=false;
	int j=0, i=0;
	do{
		if (cedaux.largodigito == jugadores[j].cedula.largodigito){
			cond1=true;
		}
		if (cedaux.largodigito != jugadores[j].cedula.largodigito){
			j++;
		}
	}while(cond1==false&&j<x);
	if (cond1==true){
		do{
			int veces=0;
			i=0;
			do{
				if (cedaux.numero[i]==jugadores[j].cedula.numero[i]){
					veces++;
				}
				i++;
				if (veces==cedaux.largodigito){
					cond2=true;
				}
			}while(cond2==false&&i<=cedaux.largodigito);
		}while(cond2==false&&i<cedaux.largodigito);
	}else{
		cond2=false;
	}
	return j;
}
bool legitimidad(james jugadores[],int x){   //<8,1,2,3,4,7,6> 1234678 2987634   mayor numero que se puede formar es 279
	bool cumple=false,termino=false;
	int cuenta=0,rango=0;
	cuenta=jugadores[x].cedula.numero[0]*2+jugadores[x].cedula.numero[1]*9+jugadores[x].cedula.numero[2]*8+jugadores[x].cedula.numero[3]*7+jugadores[x].cedula.numero[4]*6+jugadores[x].cedula.numero[5]*3+jugadores[x].cedula.numero[6]*4;
	//*printf ("\n %d",cuenta);
	do{
		rango=rango+10;
		if (rango>=cuenta){
			cuenta=rango-cuenta;
			termino=true;
		}
	} while(termino==false);
	digito cedaux;
	cedaux=jugadores[x].cedula;
	int ultimo;
	ultimo=jugadores[x].cedula.largodigito;
	cedaux.numero[ultimo]=cuenta;
	/*int veces=0;
	for (int l=0;l<=jugadores[x].cedula.largodigito;l++){
		if (cedaux.numero[l]==jugadores[x].cedula.numero[l]){
			veces=veces+1;
		}
		if (veces==cedaux.largodigito){
			cumple=true;
		}
	}*/
	if(cuenta==jugadores[x].cedula.numero[7]){
		cumple=true;
	}else{
		cumple=false;
	}
	
	return cumple;
}

	
void IngresoJames(james jugadores[],int &x){
	char sino='b';
	int equi;
	bool esite=false,legit=false;
	//digito cedaux;
	elpibe aliaux;
	getchar();
	aliaux=ingresoAlias();
	//cedaux=ingresoCedula();
	
	if(x<10&&sino=='b'){
	if (x<=10){
		
		if(x>0){
		esite=comparoAlias(jugadores,x,aliaux);
		//esite=AuxcomparoCedulas(cedaux,jugadores, x);
		}
		if (esite==false){
			jugadores[x].alia=aliaux;
			do{
				jugadores[x].cedula=ingresoCedula();
				legit=legitimidad(jugadores,x);
				if (legit==false){
					printf ("\nLA CEDULA INGRESADA NO ES VALIDA\n");
					//getchar();
				}
			}while(legit==false);
			//jugadores[x].cedula=cedaux;
			//jugadores[x].alia=ingresoAlias();
			getchar();
			jugadores[x].nombre=ingresonombre();
			
			jugadores[x].apeyido=ingresoapellido();
			//jugadores[x].edad=ingresoEdad();
			
			jugadores[x].fechanacimiento=ingresoFechanacimiento();
			jugadores[x].loca=ingresolocalidad();
			printf ("\nConfirmar los ingresos? S/N\n");
			scanf ("%c",&sino);
			if(sino=='s'||sino=='S'){
				jugadores[x].estado='A';
				x++;
			}
			if(sino=='n'||sino=='N'){
				printf ("\nNo se han almacenado los datos ingresados.");
			}
		}
		if (esite==true){
			printf ("\nYa existe un jugador con ese alias");
			equi=XdeComparoAlias(jugadores,x,aliaux);
			if (jugadores[equi].estado=='I'){
				printf (", quiere cambiar su estado a Activo? S/N\n");
				scanf ("%c",&sino);
				if (sino=='s'||sino=='S'){
					jugadores[equi].estado='A';
				}
			}
		}
	}
	getchar();
	
	}
	if (x>=10){
		printf("\n\n");
		printf ("Se ha alcanzado el limite de usuarios permitidos.");
	}
}
	
void bajaUsuario(james jugadores[], int x){ //tengo que saber cual es el jugador al que tengo que cambiarle es estado
	elpibe auxali;
	int equi;
	char sino;
	bool esite=false;
	getchar();
	auxali=ingresoAlias();
	//cedaux=ingresoCedula();
	esite=comparoAlias(jugadores,x,auxali);
	//esite=AuxcomparoCedulas(cedaux,jugadores,x);
	if (esite==true){
		equi=XdeComparoAlias(jugadores,x,auxali);
		//equi=XdeAuxcomparoCedulas(cedaux,jugadores,x);
		if(jugadores[equi].estado=='I'){
			printf ("\nEl jugador ya está marcado como inactivo, si desea cambiar su estado\na activo intente ingresar un usuario con la cedula\nya registrada.");
		}
		printf ("\nSeguro que quiere cambiar el estado del jugador indicado a ""Inctivo""? S/N ");
		scanf ("%c",&sino);
		if (sino=='s'||sino=='S'){
			jugadores[equi].estado='I';
			printf("\nEl estado del jugador se cambio a Inactivo exitosamente.");
		}
	}
	if (esite==false){
		//getchar();
		printf ("\nEl alias ingresado no coincide con el de nungun jugador");
	}
	getchar();
}
	
bool comparoAlias(james jugadores[],int x,elpibe nick){
	bool cond2=false;
	int  i=0;
	for (int ju=0;ju<x;ju++){
		do{
			int veces=0;
			i=0;
			do{
				if (nick.alias[i]==jugadores[ju].alia.alias[i]){
					veces++;
				}
				i++;
				if (veces==nick.largoalias){
					cond2=true;
				}
			}while(cond2==false&&i<=nick.largoalias);
		}while(cond2==false&&i<nick.largoalias);
	}
	/*}else{
	cond2=false;
	}*/
	return cond2;
}


	
int	XdeComparoAlias(james jugadores[],int x,elpibe nick){
	bool cond1=false, cond2=false;
	int j=0, i=0;
	do{
		if (nick.largoalias == jugadores[j].alia.largoalias){
			cond1=true;
		}
		if (nick.largoalias != jugadores[j].alia.largoalias){
			j++;
		}
	}while(cond1==false&&j<x);
	if (cond1==true){
		do{
			int veces=0;
			i=0;
			do{
				if (nick.alias[i]==jugadores[j].alia.alias[i]){
					veces++;
				}
				i++;
				if (veces==nick.largoalias){
					cond2=true;
				}
			}while(cond2==false&&i<=nick.largoalias);
		}while(cond2==false&&i<nick.largoalias);
	}else{
		cond2=false;
	}
	return j;
}

void modificarUsuario(james jugadores[],int x){ //Hay que mencionar al usuario que solo se puede modificar la localidad 
	elpibe nick;
	doxeado locaux;
	int equi;
	char sino;
	bool esite;
	
	nick=ingresoAlias();
	esite=comparoAlias(jugadores,x,nick);
	equi=XdeComparoAlias(jugadores,x,nick);
	if (jugadores[equi].estado=='A'){
		if (esite==true){
			printf ("\nDatos del jugador:\n");
			muestroNombre(jugadores[equi].nombre);
			muestroapellido(jugadores[equi].apeyido);
			muestrocedula(jugadores[equi].cedula);
			//muestroEdad(jugadores[equi].edad);
			muestroFechanaci(jugadores[equi].fechanacimiento);
			muestroLocalidad(jugadores[equi].loca);
			printf ("\n\nIngrese la nueva localidad de la siguiente manera: -NuevaLocalidad\n");
			locaux=ingresolocalidad();
			printf ("\nConfirma que esta sera la nueva localidad? S/N ");
			scanf (" %c",&sino);
			if (sino=='s'||sino=='S'){
				jugadores[equi].loca=locaux;
				printf ("\nSe modifico la localidad con exito.");
				getchar();
			}
		}
		if (esite==false){
			printf ("\nEl alias ingresado no coincide con ningun usuario");
		}
	}else{
		printf ("\nNo se pueden modificar usuarios Inactivos.");
	}
	getchar();
}
	
	
	
void muestroNombre(cadena nombre){
		int i;
		for (i=0;i<nombre.largopalabra;i++)
		{
			printf("%c", nombre.palabra[i]);
		}
		printf (" ");
	}
	
	
	void muestroapellido(rolando apeyido){
		int i;
		for (i=0;i<apeyido.largoapellido;i++)
		{
			printf("%c", apeyido.ape[i]);
		}
		printf (" ");
	}
	
	void muestrocedula(digito cedula){
		int i;
		for (i=0;i<cedula.largodigito;i++)
		{
			printf("%d", cedula.numero[i]);
		}
		printf (" ");
	}
	
	
	/*void muestroEdad(int edad){
		
		printf ("%d ",edad);
		
	}*/
	
	
	void muestroFechanaci(fecha fechanacimiento){
		
		printf ("%d/%d/%d ",fechanacimiento.dia, fechanacimiento.mes, fechanacimiento.anio);
		
		
	}
	

	doxeado ingresolocalidad(){
		doxeado local;
		int l=0;
		printf("\ningrese la localidad del jugador: ");
		getchar();
		while(l<LARGOL&&(local.ciudad[l]=getchar())!='\n'){
			l++;	
		}
		local.largocity=l;
		return local;
	}
	
	
	void muestroLocalidad(doxeado loca){
		int i;
		for (i=0;i<loca.largocity;i++)
		{
			printf("%c", loca.ciudad[i]);
		}
		printf (" ");
	}
	
	elpibe ingresoAlias(){
		elpibe nick;
		int i=0;
		printf ("\nIngrese un alias: ");
		while(i<LARGOA&&((nick.alias[i]=getchar())!='\n')){
			i++;
		}
		nick.largoalias=i;
		return nick;
	}
	
	void muestroAlias(elpibe alia){
		int i;
		for (i=0;i<alia.largoalias;i++)
		{
			printf("%c", alia.alias[i]);
		}
		
	}
	

		
	/*	bool comparoCedulas(jugador jugadores[], int x){ //Hay que comprar entre las cedulas de los jugadores, no solo con un es particular
			for(int j=0;j<x;j++){
				if (jugadores[x].cedula.largodigito != jugadores[j].cedula.largodigito)
					return false;
				for (int i=0;i<jugadores[x].cedula.largodigito;i++) {
					if(jugadores[x].cedula.numero[i]!=jugadores[j].cedula.numero[i]){
						return false;
					}
				}
			}
			return true;
		}
			
			ESTO ERA EL PREVIO COMPARO CEDULAS, PERO SOLO COMPARA SI PASABAMOS POR PARAMETRO CEDULAS DE DOS USUARIOS EN ESPECIFICO
		*/
		

void ListaDeJugadoresA(james jugadores[],int x){
	james jugAux[10];
	int j;
	getchar();
	system("clear");
	printf ("Solo se muestran los jugadores activos: \n=======================================\n\n");
	//el error era que en el MenuGestion no se estaba pasando la x por referencia, entonces el crecimiento de x nunca volvia al main sino al MenuGestion
	OrdenoXAlias(jugAux,x,jugadores);
	for (j=0;j<=x-1;j++){
		if (jugadores[j].estado=='A'){
			muestroAlias(jugadores[j].alia);
			printf (" ");
			muestroNombre(jugadores[j].nombre);
			muestroapellido(jugadores[j].apeyido);
			muestrocedula(jugadores[j].cedula);
			//muestroEdad(jugadores[j].edad);
			//muestroFechanaci(jugadores[j].fechanacimiento);
			muestroLocalidad(jugadores[j].loca);
			printf ("\n");
		}
	}
	getchar();
	
}
	
void OrdenoXAlias(james jugAux[],int x,james jugadores[]){
	
	for (int e=0;e<x-1;e++){
		for (int j=0;j<x-1;j++){
			if ((int)jugadores[j].alia.alias[0]>(int)jugadores[j+1].alia.alias[0]){
				jugAux[0]=jugadores[j];
				jugadores[j]=jugadores[j+1];
				jugadores[j+1]=jugAux[0];
			}
			/*if((int)jugadores[j].alia.alias[0]==(int)jugadores[j+1].alia.alias[0]){
				for (int s=0;s<x-1;s++){
					if ((int)jugadores[s].alia.alias[1]>(int)jugadores[s+1].alia.alias[1]){
						jugAux[0]=jugadores[s];
						jugadores[s]=jugadores[s+1];
						jugadores[s+1]=jugAux[0];
					}	
				}
			}*/
		}
	}
}
	
void MenuInformes(james jugadores[],int x,int juego){
	int op;
	system("clear");
	do{
		printf ("Que quiere hacer?\n1-Jugadores ordenados por alias\n2-Lista de partidas jugadas\n3-Listado de partidas por usuario\n4-Listado de partidas por fecha\n5-Regresar\n->");
		scanf ("%d",&op);
	}while(op!=1&&op!=2&&op!=3&&op!=4&&op!=5);
	switch(op){
	case 1:ListaDeJugadoresA(jugadores,x);
		break;
	case 2:ListaDeJugadoresB(jugadores,x,juego);
		break;
	case 3:ListaDeJugadoresC(jugadores,x,juego);
		break;
	case 4:ListaDeJugadoresD(jugadores,x,juego);
		break;
	case 5:
		break;
	}
}
	
	
	//Controles: y(arriba) g(izquierda) b(abajo) h(derecha)
	//Error de permisson denied es xq ya se esta ejecutando
void generarTablero (int tablero[4][4]){
	int i, j;
	for (int x=0;x<4;x++){
		for (int y=0;y<4;y++){
			tablero[x][y]=0;
		}
	}
	srand(time(NULL));
	i=rand()%4;
	j=rand()%4;
	tablero[i][j]=2;
	do{
		i=rand()%4;
		j=rand()%4;
	}while(tablero[i][j]!=0);
	tablero[i][j]=2;
}


bool jugar (int tablero[4][4], bool &juja,james jugadores[],int x,int &juego){		
	bool sigue=true, lleno=false, nomueve=false;	
	int puntaje=0, puntaje_total=0,equi;
	char letra;
	bool esite=false,jugas=false;
	elpibe nick;
	getchar();
	nick=ingresoAlias();
	esite=comparoAlias(jugadores,x,nick);
	if (esite==true){				//AQUI ES DONDE EMPIEZA LA FUNCION PARA VARIFICAR SI EXISTE EL ALIAS Y SI ES ACTIVO
		equi=XdeComparoAlias(jugadores,x,nick);
		if (jugadores[equi].estado=='A'){
			jugas=true;
		}else{
			printf ("\nEl jugador esta marcado como inactivo, no puede jugar.");
		}
	}
if (jugas==true){     //SI QUITAMOS DESDE EL COMENTARIO ANTERIOR HASTA ACA, EL JUEGO ANDA, PERO SI INCLUIMOS LA VERIFICACION EL JUEGO NO TE PERMITE HACER NINGUN MOVIMIENTO
	printf ("\nIngrese la fecha de hoy en el siguiente formato: X/X/X\n");
	scanf ("%d/%d/%d",&jugadores[equi].partidas[juego].fecha.dia,&jugadores[equi].partidas[juego].fecha.mes,&jugadores[equi].partidas[juego].fecha.anio);
	printf ("\nIngrese la hora actual XX:XX\n");
	scanf ("%d:%d",&jugadores[equi].partidas[juego].hs,&jugadores[equi].partidas[juego].min);
	system("clear");
	
	do{
		do{
			printf("\nLos controles son: y(arriba), b(abajo), g(izquierda), h(derecha), a(abortar)");
			printf ("\n===============================================================\n");
			printf("\n|Su puntaje actual es:%d|", puntaje);
			printf("\t\t\t|Su mayor puntaje es:%d|\n",puntaje_total);
			printf ("\n====================================\n");
			for (int x=0;x<4;x++){
				for (int y=0;y<4;y++){
					printf ("|   %d   |",tablero[x][y]);
				}
				printf ("\n====================================\n");
				
			}
			int clleno=0;
			for(int r=0; r<4;r++){
				for(int w=0;w<4;w++){
					if(tablero[r][w]==0){
						clleno++;
						if(clleno==15){
							lleno=true;
						}
					}
				} //llevar contardor que se reseta por jugada que se fije si los 16 numeros son distintos
			}
			for(int r=0;r<4;r++){
				for(int w=0;w<4;w++){
					if (tablero[r][w]!=tablero[r-1][w]&&tablero[r][w]!=tablero[r+1][w]&&tablero[r][w]!=tablero[r][w-1]&&tablero[r][w]!=tablero[r][w+1]){
						nomueve=true;
					}
				}
			}
			if (lleno&&nomueve){
				sigue=false;
				juja=false;
				jugadores[equi].partidas[juego].condicion=2;
				juego=juego+1;
				return juja;
			}
			else{
				//if((tablero[0][0]!=tablero[0][1]&&tablero[0][0]!=tablero[1][0])&&(tablero[0][1]!=tablero[0][0]&&tablero[0][1]!=tablero[0][2]&&tablero[0][1]!=tablero[1][1])&&(tablero[0][2]!=tablero[0][3]&&tablero[0][2]!=tablero[0][1]&&tablero[0][2]!=tablero[1][2])&&(tablero[0][3]!=tablero[0][2]&&tablero[0][3]!=tablero[1][3])&&(tablero[1][0]!=tablero[0][0]&&tablero[1][0]!=tablero[2][0]&&tablero[1][0]!=tablero[1][1])&&(tablero[1][1]!=tablero[0][1]&&tablero[1][1]!=tablero[1][0]&&tablero[1][1]!=tablero[1][2]&&tablero[1][1]!=tablero[2][1])&&(tablero[1][2]!=tablero[0][2]&&tablero[1][2]!=tablero[1][1]&&tablero[1][2]!=tablero[1][3]&&tablero[1][2]!=tablero[2][2])&&(tablero[1][3]!=tablero[0][3]&&tablero[1][3]!=tablero[2][3]&&tablero[1][3]!=tablero[1][2]&&(tablero[2][0]!=tablero[1][0]&&tablero[2][0]!=tablero[3][0]&&tablero[2][0]!=tablero[2][1]&&(tablero[2][1]!=tablero[2][0]&&tablero[2][1]!=tablero[2][2]&&tablero[2][1]!=tablero[1][1]&&tablero[2][1]!=tablero[3][1])&&(tablero[2][2]!=tablero[2][1]&&tablero[2][2]!=tablero[2][3]&&tablero[2][2]!=tablero[3][2]&&tablero[2][2]!=tablero[1][2])&&(tablero[2][3]!=tablero[3][3]&&tablero[2][3]!=tablero[2][2]&&tablero[2][3]!=tablero[1][3]&&(tablero[3][0]!=tablero[2][0]&&tablero[3][0]!=tablero[3][1])&&(tablero[3][1]!=tablero[3][0]&&tablero[3][1]!=tablero[3][2]&&tablero[3][1]!=tablero[2][1])&&(tablero[3][2]!=tablero[3][1]&&tablero[3][2]!=tablero[2][2]&&tablero[3][2]!=tablero[2][3])&&(tablero[3][3]!=tablero[3][2]&&tablero[3][3]!=tablero[2][3]))))&&(tablero[0][0]!=0&&tablero[0][1]!=0&&tablero[0][2]!=0&&tablero[0][3]!=0&&tablero[1][0]!=0&&tablero[1][1]!=0&&tablero[1][2]!=0&&tablero[1][3]!=0&&tablero[2][0]!=0&&tablero[2][1]!=0&&tablero[2][2]!=0&&tablero[2][3]!=0&&tablero[3][0]!=0&&tablero[3][1]!=0&&tablero[3][2]!=0&&tablero[3][3]!=0)){                                                     
				//printf("perdiste");
				//sigue=false;
				//juja=false;
				//}
				printf("\nIngrese su movimiento:h, g, y, b\n");
				getchar();
				letra=getchar();
				if(letra=='a'){
					jugadores[equi].partidas[juego].condicion=0;
					juego=juego+1;
					sigue=false;
					juja=true;
					return juja;
				}
			}
			system("clear");//(clear) o (cls)
		}while (letra!='y'&&letra!='g'&&letra!='h'&&letra!='b'&&letra!='a');
		int cn=0;
		if (letra=='y'){ 
			while(cn<3){
				for (int x=0;x<4;x++){
					if (tablero[1-1][x]==0){
						tablero[1-1][x]=tablero[1][x];
						tablero[1][x]=0;
					}
					if (tablero[1-1][x]==tablero[1][x]){
						tablero[1-1][x]=tablero[1][x]+tablero[1-1][x];
						tablero[1][x]=0;
						puntaje=puntaje+tablero[1-1][x];
					}
					if (tablero[2-1][x]==0){
						tablero[2-1][x]=tablero[2][x];
						tablero[2][x]=0;
					}
					if (tablero[2-1][x]==tablero[2][x]){
						tablero[2-1][x]=tablero[2][x]+tablero[2-1][x];
						tablero[2][x]=0;
						puntaje=puntaje+tablero[2-1][x];
					}
					if (tablero[3-1][x]==0){
						tablero[3-1][x]=tablero[3][x];
						tablero[3][x]=0;
					}
					if (tablero[3-1][x]==tablero[3][x]){
						tablero[3-1][x]=tablero[3][x]+tablero[3-1][x];
						tablero[3][x]=0;
						puntaje=puntaje+tablero[3-1][x];
					}
				}
				cn++;	
			}
		}	
		cn=0;
		if (letra=='b'){
			while(cn<3){
				for (int x=0;x<4;x++){
					if (tablero[2+1][x]==0){
						tablero[2+1][x]=tablero[2][x];
						tablero[2][x]=0;
					}
					if (tablero[2+1][x]==tablero[2][x]){
						tablero[2+1][x]=tablero[2][x]+tablero[2+1][x];
						tablero[2][x]=0;
						puntaje=puntaje+tablero[2+1][x];
					}
					if (tablero[1+1][x]==0){
						tablero[1+1][x]=tablero[1][x];
						tablero[1][x]=0;
					}
					if (tablero[1+1][x]==tablero[1][x]){
						tablero[1+1][x]=tablero[1][x]+tablero[1+1][x];
						tablero[1][x]=0;
						puntaje=puntaje+tablero[1+1][x];
					}
					if (tablero[0+1][x]==0){
						tablero[0+1][x]=tablero[0][x];
						tablero[0][x]=0;
					}
					if (tablero[0+1][x]==tablero[0][x]){
						tablero[0+1][x]=tablero[0][x]+tablero[0+1][x];
						tablero[0][x]=0;
						puntaje=puntaje+tablero[0+1][x];
					}
				}
				cn++;	
			}
		}    //Acá intentamos reemplazar el 2+1 1+1 y eso por un for pero no nos salió
			cn=0;
			if (letra=='g'){
				while(cn<3){
					for (int x=0;x<4;x++){
						if (tablero[x][1-1]==0){
							tablero[x][1-1]=tablero[x][1];
							tablero[x][1]=0;
						}
						if (tablero[x][1-1]==tablero[x][1]){
							tablero[x][1-1]=tablero[x][1]+tablero[x][1-1];
							tablero[x][1]=0;
							puntaje=puntaje+tablero[x][1-1];
						}
						if (tablero[x][2-1]==0){
							tablero[x][2-1]=tablero[x][2];
							tablero[x][2]=0;
						}
						if (tablero[x][2-1]==tablero[x][2]){
							tablero[x][2-1]=tablero[x][2]+tablero[x][2-1];
							tablero[x][2]=0;
							puntaje=puntaje+tablero[x][2-1];
						}
						if (tablero[x][3-1]==0){
							tablero[x][3-1]=tablero[x][3];
							tablero[x][3]=0;
						}
						if (tablero[x][3-1]==tablero[x][3]){
							tablero[x][3-1]=tablero[x][3]+tablero[x][3-1];
							tablero[x][3]=0;
							puntaje=puntaje+tablero[x][3-1];
						}
					}
					cn++;	
				}
			}

		cn=0;
		if (letra=='h'){
			while(cn<3){
				for (int x=0;x<4;x++){
					if (tablero[x][2+1]==0){
						tablero[x][2+1]=tablero[x][2];
						tablero[x][2]=0;
					}
					if (tablero[x][2+1]==tablero[x][2]){
						tablero[x][2+1]=tablero[x][2]+tablero[x][2+1];
						tablero[x][2]=0;
						puntaje=puntaje+tablero[x][2+1];
					}
					if (tablero[x][1+1]==0){
						tablero[x][1+1]=tablero[x][1];
						tablero[x][1]=0;
					}
					if (tablero[x][1+1]==tablero[x][1]){
						tablero[x][1+1]=tablero[x][1]+tablero[x][1+1];
						tablero[x][1]=0;
						puntaje=puntaje+tablero[x][1+1];
					}
					if (tablero[x][0+1]==0){
						tablero[x][0+1]=tablero[x][0];
						tablero[x][0]=0;
					}
					if (tablero[x][0+1]==tablero[x][0]){
						tablero[x][0+1]=tablero[x][0]+tablero[x][0+1];
						tablero[x][0]=0;
						puntaje=puntaje+tablero[x][0+1];
					}
				}
				cn++;	
			}
		}

		//Ahora falta ir sumando mas numeros por cada moviemiento
		int x, y;
		//if (veces>=1){ <-----Ésto decidimos no usarlo, al consultarle al profe el problema de doble generacios de nuevos numeros

		do{
			x=rand()%4;
			y=rand()%4;
		}while(tablero[x][y]!=0);
		tablero[x][y]=2;
	
	
		if(puntaje>puntaje_total){
			puntaje_total=puntaje;
		}
		for(int x=0;x<4;x++){
			for(int l=0;l<4;l++){
				if(tablero[x][l]==G){
					system("clear");
					printf("\nFELICIDADES USTED A GANADO EL JUEGO");
					printf("\n==============================================\n");
					jugadores[equi].partidas[juego].condicion=1;
					juego=juego+1;
					printf("\n si quiere volver a jugar ingrese 1, si quiere salir ingrese 0\n");
					int sesigue;
					scanf("%d", &sesigue);
					if(sesigue==0){
						sigue=false;
						juja=true;
					}else{
						sigue=false;
					}
					system("clear");
					//system("cls");
				}	
			}
		}//aca lo que hicimos fue con un if poner cuando gana si una casilla llega a G 
		
		//}
		//veces++;
	} while(sigue==true||lleno);	
}
return juja;
}

void bienvenido(){
	printf ("==============BIENVENIDO A 2048==============\nPara jugar debe existir previamente un usuario\nPulse cualquier tecla para continuar");
	getchar();
	system("clear");
	//system("cls");
}

	

void ListaDeJugadoresB(james jugadores[],int x,int juego){
	getchar();
	system("clear");
	printf ("Listado de todas las partidas jugadas: \n======================================\n");
	for (int j=0;j<=x-1;j++){
		printf ("\n");
		muestroAlias(jugadores[j].alia);
		for (int p=0;p<juego;p++){
			if (jugadores[j].partidas[p].fecha.dia!=-1){
				printf ("\n%d/%d/%d",jugadores[j].partidas[p].fecha.dia,jugadores[j].partidas[p].fecha.mes,jugadores[j].partidas[p].fecha.anio);
				printf (" %d:",jugadores[j].partidas[p].hs);
				if (jugadores[j].partidas[p].min<10&&jugadores[j].partidas[p].min>=0) printf ("0");
				printf ("%d",jugadores[j].partidas[p].min);
				if (jugadores[j].partidas[p].condicion==0) printf (" Abortada"); 
				if (jugadores[j].partidas[p].condicion==1) printf (" Lograda");
				if (jugadores[j].partidas[p].condicion==2) printf (" No Lograda");
				//printf (" %d",jugadores[j].partidas[p].condicion); //tengo que chequear que hay adentro y mostrar logrado no logrado o abortado
			}
		}
		
		
	}
	getchar();
}	
	
void ListaDeJugadoresC(james jugadores[],int x,int juego){
	elpibe nick;
	bool esite=false;
	int equi;
	getchar();
	nick=ingresoAlias();
	esite=comparoAlias(jugadores,x,nick);
	if (esite==true){	
		equi=XdeComparoAlias(jugadores,x,nick);
		if (jugadores[equi].estado=='A'){
			printf ("\nListado de partidas por usuario:\n================================\n");
			for (int p=0;p<juego;p++){
				if (jugadores[equi].partidas[p].fecha.dia!=-1){
					printf ("\n%d/%d/%d",jugadores[equi].partidas[p].fecha.dia,jugadores[equi].partidas[p].fecha.mes,jugadores[equi].partidas[p].fecha.anio);
					printf (" %d:",jugadores[equi].partidas[p].hs);
					if (jugadores[equi].partidas[p].min<10&&jugadores[equi].partidas[p].min>=0) printf ("0");
					printf ("%d",jugadores[equi].partidas[p].min);
					if (jugadores[equi].partidas[p].condicion==0) printf (" Abortada"); 
					if (jugadores[equi].partidas[p].condicion==1) printf (" Lograda");
					if (jugadores[equi].partidas[p].condicion==2) printf (" No Lograda");
				}
			}
			getchar();
		}else{
			printf ("\nEl jugador esta inactivo");
			getchar();
		}
	}else{
		printf ("\nEl alias no corresponde a ningun jugador");
		getchar();
	}
}

void ListaDeJugadoresD(james jugadores[],int x,int juego){	
	int dia,mes,anio,lugar=0;
	int pj[10]{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	bool esite=false;
	printf ("Ingrese una fecha (XX/XX/XXXX) para consultar las partidas de ese dia:\n");
	scanf ("%d/%d/%d",&dia,&mes,&anio);
	for (int j=0;j<x;j++){
		for (int p=0;p<juego;p++){
			if (jugadores[j].partidas[p].fecha.dia==dia&&jugadores[j].partidas[p].fecha.mes==mes&&jugadores[j].partidas[p].fecha.anio==anio){
				esite=true;
				pj[lugar]=j;
				lugar++;
			}
		}		
	}
	if (esite==true){
		for (int xd=0;xd<x;xd++){
			for (int pt=0;pt<juego;pt++){ //jugadores[pj[pt]]
				if (pj[xd]!=-1&&jugadores[pj[xd]].partidas[pt].hs!=-1&&dia==jugadores[xd].partidas[pt].fecha.dia&&mes==jugadores[xd].partidas[pt].fecha.mes&&anio==jugadores[xd].partidas[pt].fecha.anio){
					printf (" %d:",jugadores[pj[xd]].partidas[pt].hs);
					if (jugadores[pj[xd]].partidas[pt].min<10&&jugadores[pj[xd]].partidas[pt].min>=0) printf ("0");
					printf ("%d ",jugadores[pj[xd]].partidas[pt].min);
					muestroAlias(jugadores[pj[xd]].alia);
					if (jugadores[pj[xd]].partidas[pt].condicion==0) printf (" Abortada"); 
					if (jugadores[pj[xd]].partidas[pt].condicion==1) printf (" Lograda");
					if (jugadores[pj[xd]].partidas[pt].condicion==2) printf (" No Lograda");
					printf ("\n");
					
				}
				
			}
			
		}
		getchar();
	}else{
		printf ("\nNo hay ninguna partida registrada en esa fecha");
		getchar();
	}
	
}
	
	
void InicializoPartidas(james jugadores[10]){
	for (int j=0;j<10;j++){
		for (int p=0;p<20;p++){
			jugadores[j].partidas[p].fecha.dia=-1;
			jugadores[j].partidas[p].fecha.mes=-1;
			jugadores[j].partidas[p].fecha.anio=-1;
			jugadores[j].partidas[p].hs=-1;
			jugadores[j].partidas[p].min=-1;
		}
	}
}
	
