#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#include "prototipo.h"
#include "estructura.h"




bool esVacio(Sistema Raiz){
	if(Raiz==NULL){
		return true;
	}else{
		return false;
	}
}
	

	
	
bool BuscaNombre(Sistema Raiz, Cadena NombrePuesto){
	
	Archivo auxi=Raiz->NodoPrincipal;
	while(auxi!=NULL){
		if(strcmp(auxi->NombreArchivo, NombrePuesto)==0){
			return true;
		}
		auxi=auxi->sig;
	}
	return false;
}

Directorio Cd (Sistema &s, Cadena nombreDirectorio){
	return s->NodoRaiz;
}

	
Directorio vuelvoaRaiz(Sistema &s){
	Directorio aux=s->NodoRaiz;
	while(aux->ApuntaRaiz!=NULL){
		aux=aux->ApuntaRaiz;
	}
	return aux;
}

void Dir (Sistema &s, Cadena parametro)
{
	Directorio auxPad=s->NodoRaiz;
	Directorio auxD=s->NodoRaiz->Directoriohijo;
	Archivo aux=s->NodoRaiz->Archivohijo;
	if(strcmp(parametro, "/S")==0){
		//Dirs(s, auxD);
	cout<<"NO_IMPLEMENTADA"<<endl;
	 return;
	}else{
	while(auxPad!=NULL){
		cout<<auxPad->NombreDirectorio<<"/";
		auxPad=auxPad->ApuntaRaiz;
	}
	cout<<endl;
	if(aux!=NULL){
		cout<<aux->NombreArchivo<<"     ";
		if(strcmp(aux->TipoArchivo, "+W")==0){
			cout<<"Lectura / Escritura"<<endl;
		}else{
			cout<<"Lectura"<<endl;
		}
		while(aux->sig!=NULL){
			aux=aux->sig;
			cout<<aux->NombreArchivo<<"     ";
			if(strcmp(aux->TipoArchivo, "+W")==0){
				cout<<"Lectura / Escritura"<<endl;
			}else{
				cout<<"Lectura"<<endl;
			}
		}
	}
	if(auxD!=NULL){
		cout<<auxD->NombreDirectorio<<endl;
		while(auxD->Directhermano!=NULL){
			auxD=auxD->Directhermano;
			cout<<auxD->NombreDirectorio<<endl;
		}
	}

}
}

//void Muestroruta(Sistema s){
// if(s->ApuntaRaiz==NULL){
//	 return;
// }
//	Muestroruta(s->NodoRaiz->ApuntaRaiz->NodoRaiz);
//	cout<<s->NombreDirectorio<<"/";
//}

//}
	
//void Dirshijo(Sistema &s){
//	
//	if(s->NodoRaiz->Directoriohijo->Archivijohijo!=NULL){
//		if(s->NodoRaiz->Archivohijo!=NULL){
//			cout<<"El archivo: "<<s->NodoRaiz->Archivohijo->NombreArchivo<<endl;
//			while(s->NodoRaiz->Archivohijo->sig!=NULL){
//				cout<<"El archivo: "<<s->NodoRaiz->Archivohijo->NombreArchivo<<endl;
//				aux=aux->sig;
//			}
//		}	
//	}
//	if(auxD==NULL){
//			return NULL;
//		}else{
//			cout<<"El Directorio: "<<auxD<<endl;
//			Dirs(s, auxD->Directhermano);
//			cout<<"El Directorio: "<<auxD<<endl;
//			Dirs(s, auxD->Directoriohijo);
//		}
//
//
//
//
//
//
//
//}
	
	void Delete(Sistema &s, Cadena nombreArchivo){
		Archivo auxA=s->NodoPrincipal;
		Archivo auxAnt=NULL;
		while(auxA!=NULL){
			if(strcmp(auxA->NombreArchivo, nombreArchivo)==0){
				if(auxA->sig==NULL){
					delete auxA;
				}else{
					auxAnt->sig=auxA->sig;
					delete auxA;
				}
			}	
			auxAnt=auxA;
			auxA=auxA->sig;
		}
	}
	
		/*Sistema eliminoarchivos(Sistema &s,Directorio aux)
		{
			if(s==NULL){
				cout<<"Borrado Correctamente"<<endl;
				return s;
			}else{
				return eliminoarchivos(s->NodoRaiz->Archivohijo);
				return eliminoarchivos(s->NodoRaiz->Archivohijo->sig);
				return eliminoarchivos(s->NodoRaiz->Directoriohijo);
				return eliminoarchivos(NodoRaiz->Directoriohermano);
				delete s;
			}
			return 0;
		}*/
		
Directorio cD(Sistema &s, Cadena nombreDirectorio){
	Directorio aux=s->NodoRaiz;
	aux=aux->Directoriohijo;
	if(strcmp(aux->NombreDirectorio,nombreDirectorio)==0){
		s->NodoRaiz=aux;
		return s->NodoRaiz;
	}
	while(aux->Directhermano!=NULL){
		if(strcmp(aux->	Directhermano->NombreDirectorio, nombreDirectorio)==0){
			s->NodoRaiz=aux->Directhermano;
			return s->NodoRaiz;
		}
		aux=aux->Directhermano;
	}
}

Directorio cDpadre(Sistema &s, Cadena nombreDirectorio){
	Directorio aux=s->NodoRaiz;
		if(aux->ApuntaRaiz!=NULL){
			aux=aux->ApuntaRaiz;
			s->NodoRaiz=aux;
			return s->NodoRaiz;
		}
}
