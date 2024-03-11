#include<iostream>
#include<stdio.h>
#include<string.h>
#include "prototipo_tiporet.h"
#include "estructura.h"
#include "prototipo.h"
using namespace std;


void mostrarRetorno(TipoRet retorno){
	switch(retorno){
	case OK:
		cout<<"OK"<<endl;
		break;
	case ERROR:
		cout<<"ERROR"<<endl;
		break;
	case NO_IMPLEMENTADA:
		cout<<"NO_IMPLEMENTADA"<<endl;
		break;
	}
}


	
	TipoRet DC (Sistema &s, Cadena nombreArchivo, int k)
	{
		int cant=0, cantD=0;
		Archivo auxA=s->NodoPrincipal;
		if(auxA==NULL){
			cout<<"El Directorio esta vacio"<<endl;
		return ERROR;
		}
		while(auxA!=NULL){
			if(strcmp(auxA->NombreArchivo, nombreArchivo)==0){
				if(strcmp(auxA->TipoArchivo, "-W")==0){
					cout<<"El Archivo es solo lectura no se puede borrar"<<endl;
					return ERROR;
				}else{
					cant=strlen(auxA->RellenoArchivo);
					if(cant<k){
						k=cant;
					}
					strcpy(auxA->RellenoArchivo, auxA->RellenoArchivo + k);
					cout<<"La cadena de texto ahora es: "<<auxA->RellenoArchivo<<endl;
					return OK;
				}
				auxA=auxA->sig;
			}
		}
		cout<<"No se ecnontro el archivo"<<endl;
		return ERROR;
	}
	
TipoRet MKDIR (Sistema &s, Cadena nombreDirectorio)
{
	Directorio aux=s->NodoRaiz;
	if(strcmp(nombreDirectorio, "RAIZ")==0){
		cout<<"El directorio no puede llamarse RAIZ"<<endl;
			return ERROR;
	}
	if(strlen(nombreDirectorio)>16){
		cout<<"El directorio no puede ser mas largo de 15 caracteres"<<endl;
			return ERROR;
	}
	if(aux->Directoriohijo==NULL){
		Directorio NuevoDirectorio = new _directorio;
		NuevoDirectorio->Archivohijo=NULL;
		NuevoDirectorio->Directhermano=NULL;
		NuevoDirectorio->ApuntaRaiz=aux;
		NuevoDirectorio->Directoriohijo=NULL;
		aux->Directoriohijo=NuevoDirectorio;
		strcpy(NuevoDirectorio->NombreDirectorio, nombreDirectorio);
		
		return OK;
	}else{
		aux=aux->Directoriohijo;
		if(strcmp(aux->NombreDirectorio, nombreDirectorio)==0){
			cout<<"El Directorio ya existe "<<endl;
			return ERROR;
		}
		while(aux->Directhermano!=NULL){
			if(strcmp(aux->	Directhermano->NombreDirectorio, nombreDirectorio)==0){
				cout<<"El Directorio ya existe"<<endl;
				return ERROR;
			}
			aux=aux->Directhermano;
		}
		
		Directorio NuevoDirectorio=new _directorio;
		NuevoDirectorio->Archivohijo=NULL;
		NuevoDirectorio->Directhermano=NULL;
		NuevoDirectorio->ApuntaRaiz=s->NodoRaiz;
		NuevoDirectorio->Directoriohijo=NULL;
		aux->Directhermano=NuevoDirectorio;
		strcpy(NuevoDirectorio->NombreDirectorio, nombreDirectorio);
	
		return OK;
		
	}
}
	
TipoRet RMDIR (Sistema &s, Cadena nombreDirectorio)
{
//	Directorio aux=s->NodoRaiz;
//	Directorio aux2=s->NodoRaiz;
//	while(aux!=NULL){
//		cout<<"llega"<<endl;
//		if(strcmp(aux->NombreDirectorio, nombreDirectorio)==0){
//			cout<<"Si nao"<<endl;
//			aux2->Directhermano=aux->Directhermano;
//			
//			//eliminoarchivos(s,aux);
//			return OK;
//		}
//		aux2=aux;
//		aux=aux->Directhermano;
//	}
//	cout<<"El directorio no existe"<<endl;
//	return ERROR;
	return NO_IMPLEMENTADA;
}
	
TipoRet MOVE (Sistema &s, Cadena nombre, Cadena directorioDestino)
	{
	return NO_IMPLEMENTADA;
	}
	
TipoRet DIR (Sistema &s, Cadena parametro)
{
	
	Dir (s,parametro);
	return OK;
}
	
TipoRet CREATEFILE (Sistema &s, Cadena nombreArchivo)
{
	char *p;
	char auxnombre[15]="";
	char tipoarch[3]="";
	strcpy(auxnombre, nombreArchivo);
	p = strtok(auxnombre, ".");
	strcpy(auxnombre, p);
	p = strtok(NULL, " ");
	strcpy(tipoarch, p);
	if(strlen(tipoarch)<=3&&strlen(auxnombre)<16){
		Directorio aux=s->NodoRaiz;
		Archivo auxA=s->NodoPrincipal;
		if(aux->Archivohijo==NULL){
			Archivo NuevoFile= new _archivo;
			strcpy(NuevoFile->NombreArchivo,nombreArchivo);
			strcpy(NuevoFile->TipoArchivo, "+W");
			s->NodoRaiz->Archivohijo=NuevoFile;
			NuevoFile->sig=NULL;
			s->NodoPrincipal=NuevoFile;
			strcpy(NuevoFile->RellenoArchivo,"");
			return OK;
		}else{
			if(strcmp(auxA->NombreArchivo, nombreArchivo)==0){
				cout<<"El Archivo ya existe "<<endl;
				return ERROR;
			}
			while(auxA->sig!=NULL){
				if(strcmp(auxA->NombreArchivo, nombreArchivo)==0){
					cout<<"El Archivo ya existe"<<endl;
					return ERROR;
				}
				auxA=auxA->sig;
			}
		}
		
		auxA=aux->Archivohijo;
		while(auxA->sig!=NULL){
			auxA=auxA->sig;
		}
		Archivo NuevoFile= new _archivo;
		strcpy(NuevoFile->NombreArchivo, nombreArchivo);
		strcpy(NuevoFile->TipoArchivo, "+W");
		auxA->sig=NuevoFile;
		NuevoFile->sig=NULL;
		strcpy(NuevoFile->RellenoArchivo,"");
		return OK;
	}
	
	else{
		cout<<"El archivo no es de ningun tipo"<<endl;
	return ERROR;
	}
}
TipoRet DELETE (Sistema &s, Cadena nombreArchivo)
	{
	Archivo cosa=s->NodoRaiz->Archivohijo;
	Archivo auxA=s->NodoRaiz->Archivohijo;
	if(strcmp(auxA->NombreArchivo,nombreArchivo)==0){
		if(strcmp(auxA->TipoArchivo, "-W")==0){
			cout<<"El Archivo es solo lectura no se puede borrar"<<endl;
			return ERROR;
		}else{
			Archivo coso=auxA;
			s->NodoRaiz->Archivohijo=coso->sig;
			delete coso;
			return OK;
		}
	}
	auxA=auxA->sig;
	if(auxA->sig!=NULL){
		while(auxA!=NULL){
			if(strcmp(auxA->NombreArchivo,nombreArchivo)==0){
				if(strcmp(auxA->TipoArchivo, "-W")==0){
					cout<<"El Archivo es solo lectura no se puede borrar"<<endl;
					return ERROR;
				}else{
					cosa->sig=auxA->sig;
					delete auxA;
					return OK;
				}
			}
			cosa=auxA;
			auxA=auxA->sig;
		}
	}
	cout<<"No se encontro el archivo"<<endl;
	return ERROR;
	}

TipoRet ATTRIB (Sistema &s, Cadena nombreArchivo, Cadena parametro)
	{
		Archivo aux=s->NodoPrincipal;
		Cadena resp= new char[T];
		while(aux!=NULL){
			if(strcmp(aux->NombreArchivo,nombreArchivo)==0){
				if(strcmp(aux->TipoArchivo, "+W")==0){
					cout<<"El Archivo es Lectura y Escritura"<<endl;
					cout<<"Seguro que quiere cambiarlo? si/no"<<endl;
					cin.getline(resp, T);
					if(strcmp(resp, "si")==0){
						strcpy(aux->TipoArchivo, "-W");
						cout<<"El archivo fue cambiado exitosamente"<<endl;
						cout<<aux->TipoArchivo<<endl;
						return OK;
					}else{
						cout<<"El archivo no fue cambiado."<<endl;
						return OK;
					}
				}else{
					cout<<"El archivo es solo Lectura"<<endl;
					cout<<"Seguro que quiere cambiarlo?"<<endl;
					cin.getline(resp, T);
					if(strcmp(resp, "si")==0){
						strcpy(aux->TipoArchivo, "+W");
						cout<<"El arcihov fue cambiado exitosamente"<<endl;
						cout<<aux->TipoArchivo;
						return OK;
					}else{
						cout<<"El archivo no fue cambiado"<<endl;
						return OK;
					}
				}
			}
			aux=aux->sig;
		}
		cout<<"Ese archivo no existe"<<endl;
		return ERROR;
	}  
	
	
TipoRet IC (Sistema &s, Cadena nombreArchivo, Cadena texto)
	{
	Cadena auxtexto= new char [T];
	Archivo aux=s->NodoPrincipal;
	int cant=0, cantD=0;
	if(aux==NULL){
		cout<<"No hay archivos"<<endl;
		return ERROR;
	}
	while(aux!=NULL){
		if(strcmp(aux->NombreArchivo, nombreArchivo)==0){
		if(strcmp(aux->TipoArchivo, "+W")==0){
			cant=strlen(aux->RellenoArchivo);
			cant=T-cant;
			cantD=strlen(texto);
			cantD=cantD-cant;
			texto[strlen(texto)-cantD]='\0';
			strcpy(auxtexto, aux->RellenoArchivo);
			strcpy(aux->RellenoArchivo, texto);
			strcat(aux->RellenoArchivo, auxtexto);
			return OK;
		}else{
		
		cout<<"El Archivo es solo Lectura"<<endl;
		return ERROR;
		}
		}
	}
	cout<<"El Archivo no exciste"<<endl;
	return ERROR;
}
	
TipoRet IF (Sistema &s, Cadena nombreArchivo, Cadena texto)
	{
	int cant=0;
	int cantD=0;
	Archivo auxA=s->NodoPrincipal;
	if(auxA==NULL){
		cout<<"El Directorio no tiene archivos"<<endl;
		return ERROR;
	}
	if(strcmp(auxA->NombreArchivo, nombreArchivo)==0){
		if(strcmp(auxA->TipoArchivo,"+W")==0){
			cant=strlen(auxA->RellenoArchivo);
			cant=T-cant;
			cantD=strlen(texto);
			cantD=cantD-cant;
			texto[strlen(texto)-cantD]='\0';
			strcat(auxA->RellenoArchivo,texto);
			cout<<"El Archivo es: "<<auxA->NombreArchivo<<endl;
			cout<<"El relleno es: "<<auxA->RellenoArchivo<<endl;
			return OK;
		}else{
			cout<<"El archivo es de tipo lectura"<<endl;
			return ERROR;
		}
	}
	while(auxA!=NULL){
		if(strcmp(auxA->NombreArchivo, nombreArchivo)==0){
			if(strcmp(auxA->TipoArchivo,"+W")==0){
				cant=strlen(auxA->RellenoArchivo);
				cant=T-cant;
				cantD=strlen(texto);
				cantD=cantD-cant;
				texto[strlen(texto)-cantD]='\0';
				strcat(auxA->RellenoArchivo,texto);
				cout<<"El Archivo es: "<<auxA->NombreArchivo<<endl;
				cout<<"El relleno es: "<<auxA->RellenoArchivo<<endl;
				return OK;
			}else{
				cout<<"El archivo es de tipo lectura"<<endl;
				return ERROR;
			}
		}
		auxA=auxA->sig;
	}
	cout<<"El archivo no fue encontrado"<<endl;
	return ERROR;
}
	
TipoRet DF (Sistema &s, Cadena nombreArchivo, int k)
{
	int cant=0;
	Archivo aux=s->NodoRaiz->Archivohijo;
	if(aux!=NULL){
		while(aux!=NULL){
			if(strcmp(aux->NombreArchivo,nombreArchivo)==0){
				cant=strlen(aux->RellenoArchivo);
				if(cant<k){
					k=cant;
				}
				aux->RellenoArchivo[strlen(aux->RellenoArchivo)-k]='\0';
				cout<<aux->RellenoArchivo<<endl;
				return OK;
			}else{
				aux=aux->sig;
			}
		}
	}else{
		cout<<"El archivo no existe"<<endl;
		return ERROR;
	}

}
	
TipoRet TYPE (Sistema &s, Cadena nombreArchivo)
	{
		Archivo aux=s->NodoPrincipal;
		while(aux!=NULL){
			if(strcmp(aux->NombreArchivo,nombreArchivo)==0){
				if(strlen(aux->RellenoArchivo)!=1){
					cout<<"El contenido del archivo es: "<<aux->RellenoArchivo<<endl;
					return OK;
				}else{
					cout<<"El archivo no tiene contenido"<<endl;
					return OK;
				}
			}else{
				aux=aux->sig;
			}
		}
		cout<<"El archivo no existe"<<endl;
		return ERROR;
	}
TipoRet SEARCH (Sistema &s, Cadena nombreArchivo, Cadena texto)
{
	Archivo auxPrinci=s->NodoPrincipal;
	Directorio auxD=s->NodoRaiz;
	auxPrinci=auxD->Archivohijo;
	while(auxPrinci!=NULL){
		if(strcmp(auxPrinci->NombreArchivo, nombreArchivo)==0){
			if(strcmp(auxPrinci->RellenoArchivo, texto)==0){
				cout<<"Si se pudo encontrar el texto dentro del archivo"<<endl;
				return OK;
			}else{
				cout<<"No se pudo encontrar el texto dentro del archivo"<<endl;
				return ERROR;
			}
		}
		auxPrinci=auxPrinci->sig;
	}
	cout<<"No existe un archivo con ese nombre en el Directorio actual"<<endl;
	return ERROR;
}		
TipoRet REPLACE (Sistema &s, Cadena nombreArchivo, Cadena texto1, Cadena texto2)
	{
	return NO_IMPLEMENTADA;
	}
	
TipoRet CREARSISTEMA(Sistema &s)
{
	Directorio NuevoDirectorio= new _directorio;	
		s->NodoRaiz=NuevoDirectorio;
		NuevoDirectorio->Archivohijo=NULL;
		NuevoDirectorio->Directhermano=NULL;
		NuevoDirectorio->ApuntaRaiz=NULL;
		NuevoDirectorio->Directoriohijo=NULL;
		strcpy(NuevoDirectorio->NombreDirectorio, "Raiz");
		return OK;
}
	
TipoRet DESTRUIRSISTEMA(Sistema &s)
	{
		return NO_IMPLEMENTADA;	
	}	

	TipoRet CD (Sistema &s, Cadena nombreDirectorio)
	{
		if(strcmp(nombreDirectorio, "RAIZ")==0){
			vuelvoaRaiz(s);
			return OK;
		}
		if(strcmp(nombreDirectorio, "..")==0&&s->NodoRaiz->ApuntaRaiz!=NULL){
			s->NodoRaiz=s->NodoRaiz->ApuntaRaiz;
			return OK;
		}
		if(s->NodoRaiz->Directoriohijo==NULL){
			cout<<"No existe subdirectorio destino"<<endl;
			return ERROR;
		}
		
		Directorio aux=s->NodoRaiz;
		
		aux=aux->Directoriohijo;
		
		if(strcmp(aux->NombreDirectorio,nombreDirectorio)==0){
			cD(s, nombreDirectorio);
			return OK;
		}
		while(aux->Directhermano!=NULL){
			if(strcmp(aux->	Directhermano->NombreDirectorio, nombreDirectorio)==0){
				cD(s, nombreDirectorio);
				return OK;
			}
			aux=aux->Directhermano;
			}
		return ERROR;
	}

		
	

	
