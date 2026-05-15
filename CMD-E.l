%{
#include "CMD-E.tab.h"
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#include <direct.h>
#define chdir _chdir
#else
#include <unistd.h>
#endif
%}

%option noyywrap
%option caseless

%%

"ASOCIAR"        { return ASSOC; }
"ATRIBUTO"       { return ATTRIB; }
"INTERRUMPIR"    { return BREAK; }
"EDITAR_B_D_A"   { return BCDEDIT; }
"LISTAS_A_C"     { return CACLS; }
"LLAMAR"         { return CALL; }
"ENTRAR"         { return CD; }
"CD"             { return CD; }
"CP_ACTIVA"      { return CHCP; }
"CHDIR"          { return CHDIR; }
"REVISAR_DISCO"  { return CHKDSK; }
"REVISAR_NTFS"   { return CHKNTFS; }
"LIMPIAR"        { return CLS; }
"CMD"            { return CMD; }
"COLOR"          { return COLOR; }
"COMPARAR"       { return COMP; }
"COMPRIMIR"      { return COMPACT; }
"CONVERTIR"      { return CONVERT; }
"COPIAR"         { return COPY; }
"FECHA"          { return DATE; }
"ELIMINAR"       { return DEL; }
"LISTAR"         { return DIR; }
"PARTICION"      { return DISKPART; }
"TECLAS_DOS"     { return DOSKEY; }
"CONSULTAR_DRV"  { return DRIVERQUERY; }
"ECO"            { return ECHOTK; }
"FIN_LOCAL"      { return ENDLOCAL; }
"BORRAR"         { return ERASE; }
"SALIR"          { return EXIT; }
"COMP_ARCH"      { return FC; }
"BUSCAR"         { return FIND; }
"BUSCAR_CAD"     { return FINDSTR; }
"PARA"           { return FOR; }
"FORMATEAR"      { return FORMAT; }
"UTIL_SIST"      { return FSUTIL; }
"TIPO_ARCH"      { return FTYPE; }
"IR_A"           { return GOTO; }
"RES_DIR"        { return GPRESULT; }
"AYUDA"          { return HELP; }
"ATRIBUTOS_AC"   { return ICACLS; }
"SI"             { return IF; }
"ETIQUETA"       { return LABEL; }
"MD"             { return MD; }
"CREARDIR"       { return MKDIR; }
"VINCULO"        { return MKLINK; }
"MODO"           { return MODO; }
"MODE"           { return MODE; }
"MAS"            { return MORE; }
"MOVER"          { return MOVE; }
"ARCH_ABIERTOS"  { return OPENFILES; }
"RUTA"           { return PATH; }
"PAUSA"          { return PAUSE; }
"RESTAURAR_DIR"  { return POPD; }
"IMPRIMIR"       { return PRINT; }
"INDICADOR"      { return PROMPT; }
"GUARDAR_DIR"    { return PUSHD; }
"RD"             { return RD; }
"RECUPERAR"      { return RECOVER; }
"COMENTARIO"     { return REM; }
"REN"            { return REN; }
"RENOMBRAR"      { return RENAME; }
"REEMPLAZAR"     { return REPLACE; }
"BORRARDIR"      { return RMDIR; }
"COPIA_ROBUSTA"  { return ROBOCOPY; }
"ESTABLECER"     { return SET; }
"INICIO_LOCAL"   { return SETLOCAL; }
"CONTROL_SERV"   { return SC; }
"TAREAS_PROG"    { return SCHTASKS; }
"DESPLAZAR"      { return SHIFT; }
"APAGAR"         { return SHUTDOWN; }
"ORDENAR"        { return SORT; }
"INICIAR"        { return START; }
"ASOCIAR_RUTA"   { return SUBST; }
"INFO_SISTEMA"   { return SYSTEMINFO; }
"LISTA_TAREAS"   { return TASKLIST; }
"MATAR_TAREA"    { return TASKKILL; }
"HORA"           { return TIME; }
"TITULO"         { return TITLE; }
"ARBOL"          { return TREE; }
"MOSTRAR"        { return TYPE; }
"VERSION"        { return VER; }
"VERIFICAR"      { return VERIFY; }
"VOLUMEN"        { return VOL; }
"VOLVER"         { return VOLVER; }
"COPIA_X"        { return XCOPY; }
"INFO_WMI"       { return WMIC; }

[a-zA-Z0-9\\._\-\*\/:\?\+\=\$\#\%\&\^\|\>\<\!\~\(\)\[\]\{\}\,\;]+ { yylval.string = strdup(yytext); return STRING; }
\"[^\"]*\"       { yylval.string = strdup(yytext); return STRING; }
"\n"             { return NLINE; }
[ \t]            { /* ignorar espacios */ }
.                { printf("Caracter no reconocido: %s\n", yytext); }

%%
