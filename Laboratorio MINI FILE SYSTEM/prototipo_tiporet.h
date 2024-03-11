#ifndef PROTOTIPO_TIPORET_H
#define PROTOTIPO_TIPORET_H
#include "estructura.h"
void mostrarRetorno(TipoRet retorno);
TipoRet CD (Sistema &s, Cadena nombreDirectorio);
TipoRet MKDIR (Sistema &s, Cadena nombreDirectorio);
TipoRet RMDIR (Sistema &s, Cadena nombreDirectorio);
TipoRet MOVE (Sistema &s, Cadena nombre, Cadena directorioDestino);
TipoRet DIR (Sistema &s, Cadena parametro);
TipoRet CREATEFILE (Sistema &s, Cadena nombreArchivo);
TipoRet DELETE (Sistema &s, Cadena nombreArchivo);
TipoRet ATTRIB (Sistema &s, Cadena nombreArchivo, Cadena parametro);
TipoRet IC (Sistema &s, Cadena nombreArchivo, Cadena texto);
TipoRet IF (Sistema &s, Cadena nombreArchivo, Cadena texto);
TipoRet DF (Sistema &s, Cadena nombreArchivo, int k);
TipoRet TYPE (Sistema &s, Cadena nombreArchivo);
TipoRet SEARCH (Sistema &s, Cadena nombreArchivo, Cadena texto);
TipoRet REPLACE (Sistema &s, Cadena nombreArchivo, Cadena texto1, Cadena texto2);
TipoRet CREARSISTEMA(Sistema &s);
TipoRet DESTRUIRSISTEMA(Sistema &s);
TipoRet DC (Sistema &s, Cadena nombreArchivo, int k);


#endif
