#ifndef PROTOTIPO_H
#define PROTOTIPO_H
#include "prototipo_tiporet.h"
#include "estructura.h"
#include "prototipo.h"

bool esVacio(Sistema Raiz);
 Sistema cREARSISTEMA(Sistema Raiz);
 //void DIR (Sistema &s, Cadena parametro);
 //Sistema Ingresonombre(Sistema Raiz,Cadena tezto);
 //void muestronombre(Sistema Raiz);
 Sistema cREATEFILE (Sistema Raiz, Cadena NombrePuesto);
 bool BuscaNombre(Sistema Raiz, Cadena NombrePuesto); void MuestroFile(Sistema Raiz);
 bool BuscarNombreGeneral(Sistema Raiz, Cadena nombreDirectorio,Cadena NombreArchivo);
 Directorio vuelvoaRaiz(Sistema &s);
 Directorio Cd (Sistema &s, Cadena nombreDirectorio);
 void Dir (Sistema &s, Cadena parametro);
 void Dirs (Sistema &s, Cadena parametro);
 void Delete(Sistema &s, Cadena nombreArchivo);
 bool es_vacio(Sistema s);
 Directorio esHijo(Directorio s);
 void mKDIR (Sistema &s, Cadena nombreDirectorio);
 Directorio cD(Sistema &s, Cadena nombreDirectorio);
 Directorio cDpadre(Sistema &s, Cadena nombreDirectorio);
 Sistema eliminoarchivos(Sistema &s,Directorio aux);
 void Muestroruta(Sistema s);
#endif
