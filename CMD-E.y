%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd
#define chdir _chdir
#else
#include <unistd.h>
#endif

int yylex();
void yyerror(const char *s);

char ruta_anterior[1024] = "";

void mostrar_prompt() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("\n%s> ", cwd);
    } else {
        printf("\n> ");
    }
}
void ejecutar_comando(const char* cmd_base, const char* args) {
    char buffer[2048];
    if (args && strlen(args) > 0) {
        snprintf(buffer, sizeof(buffer), "%s %s", cmd_base, args);
    } else {
        strncpy(buffer, cmd_base, sizeof(buffer));
    }
    system(buffer);
}

void cambiar_directorio(const char* path) {
    char cwd_actual[1024];
    if (getcwd(cwd_actual, sizeof(cwd_actual)) != NULL) {
        if (path == NULL || strlen(path) == 0) {
            printf("%s\n", cwd_actual);
        } else {
            // Guardar la ruta actual como anterior antes de cambiar
            strcpy(ruta_anterior, cwd_actual);

            char limpio[1024];
            strncpy(limpio, path, sizeof(limpio));
            if (limpio[0] == '\"') {
                int len = strlen(limpio);
                if (limpio[len-1] == '\"') {
                    limpio[len-1] = '\0';
                    memmove(limpio, limpio + 1, len);
                }
            }

            if (chdir(limpio) != 0) {
                perror("Error al cambiar de directorio");
            }
        }
    }
}

void volver_directorio() {
    if (strlen(ruta_anterior) > 0) {
        char temporal[1024];
        getcwd(temporal, sizeof(temporal));
        if (chdir(ruta_anterior) == 0) {
            printf("Regresando a: %s\n", ruta_anterior);
            strcpy(ruta_anterior, temporal); 
        } else {
            perror("Error al volver al directorio anterior");
        }
    } else {
        printf("No hay un directorio previo registrado.\n");
    }
}

void imprimir_ayuda_general() {
    printf("\nLista de comandos disponibles en ESPAÑOL:\n");
    printf("-----------------------------------------\n");
    printf("ASOCIAR         Muestra o modifica las asociaciones de extensiones.\n");
    printf("ATRIBUTO        Muestra o cambia los atributos del archivo.\n");
    printf("INTERRUMPIR     Establece/elimina comprobacion Ctrl+C.\n");
    printf("EDITAR_B_D_A    Establece propiedades en la base de datos de arranque.\n");
    printf("LISTAS_A_C      Muestra o modifica listas de control de acceso (ACL).\n");
    printf("LLAMAR          Llama a un programa por lotes desde otro.\n");
    printf("ENTRAR          Cambia el directorio actual.\n");
    printf("CP_ACTIVA       Muestra o establece el numero de pagina de codigos activa.\n");
    printf("REVISAR_DISCO   Chequea un disco y muestra un informe de estado.\n");
    printf("REVISAR_NTFS    Muestra o modifica la comprobacion de disco al arrancar.\n");
    printf("LIMPIAR         Borra la pantalla.\n");
    printf("CMD             Inicia una nueva instancia del interprete de comandos.\n");
    printf("COLOR           Establece los colores de primer plano y fondo.\n");
    printf("COMPARAR        Compara el contenido de dos archivos o conjuntos.\n");
    printf("COMPRIMIR       Muestra o altera la compresion de archivos.\n");
    printf("CONVERTIR       Convierte volumenes FAT a NTFS.\n");
    printf("COPIAR          Copia uno o mas archivos a otra ubicacion.\n");
    printf("FECHA           Muestra o establece la fecha.\n");
    printf("ELIMINAR        Elimina uno o mas archivos.\n");
    printf("LISTAR          Muestra una lista de archivos y subdirectorios.\n");
    printf("PARTICION       Muestra o configura las propiedades de particion.\n");
    printf("TECLAS_DOS      Edita lineas de comando, recupera comandos y crea macros.\n");
    printf("CONSULTAR_DRV   Muestra el estado y propiedades del controlador.\n");
    printf("ECO             Muestra mensajes o activa/desactiva el eco del comando.\n");
    printf("SALIR           Sale del interprete de comandos.\n");
    printf("COMP_ARCH       Compara dos archivos o conjuntos de archivos.\n");
    printf("BUSCAR          Busca una cadena de texto en uno o mas archivos.\n");
    printf("BUSCAR_CAD      Busca cadenas en archivos.\n");
    printf("PARA            Ejecuta un comando para cada archivo en un conjunto.\n");
    printf("FORMATEAR       Formatea un disco para usar con Windows.\n");
    printf("UTIL_SIST       Muestra o configura las propiedades de sistema de archivos.\n");
    printf("TIPO_ARCH       Muestra o modifica los tipos de archivo.\n");
    printf("IR_A            Dirige el interprete a una linea con etiqueta.\n");
    printf("AYUDA           Proporciona informacion de ayuda para los comandos.\n");
    printf("SI              Realiza el procesamiento condicional.\n");
    printf("ETIQUETA        Crea, cambia o elimina la etiqueta de volumen.\n");
    printf("CREARDIR        Crea un directorio.\n");
    printf("MOVER           Mueve uno o mas archivos de un directorio a otro.\n");
    printf("PAUSA           Suspende el proceso de un archivo por lotes.\n");
    printf("IMPRIMIR        Imprime un archivo de texto.\n");
    printf("INDICADOR       Cambia el simbolo del sistema.\n");
    printf("BORRARDIR       Quita un directorio.\n");
    printf("RECUPERAR       Recupera informacion legible de un disco defectuoso.\n");
    printf("COMENTARIO      Registra comentarios en archivos por lotes.\n");
    printf("RENOMBRAR       Cambia el nombre de uno o mas archivos.\n");
    printf("REEMPLAZAR      Reemplaza archivos.\n");
    printf("COPIA_ROBUSTA   Utilidad avanzada para copiar archivos y directorios.\n");
    printf("ESTABLECER      Muestra, establece o quita variables de entorno.\n");
    printf("APAGAR          Permite el apagado local o remoto de un equipo.\n");
    printf("ORDENAR         Ordena la entrada.\n");
    printf("INICIAR         Inicia una ventana separada para ejecutar un programa.\n");
    printf("INFO_SISTEMA    Muestra propiedades y configuracion del equipo.\n");
    printf("LISTA_TAREAS    Muestra todas las tareas que se ejecutan actualmente.\n");
    printf("MATAR_TAREA     Termina procesos o aplicaciones en ejecucion.\n");
    printf("HORA            Muestra o establece la hora del sistema.\n");
    printf("TITULO          Establece el titulo de la ventana para una sesion.\n");
    printf("ARBOL           Muestra graficamente la estructura de directorios.\n");
    printf("MOSTRAR         Muestra el contenido de un archivo de texto.\n");
    printf("VERSION         Muestra la version de Windows.\n");
    printf("VOLUMEN         Muestra la etiqueta de volumen y el numero de serie.\n");
    printf("COPIA_X         Copia archivos y arboles de directorios.\n");
    printf("VOLVER          Regresa al directorio anterior.\n");
    printf("-----------------------------------------\n");
}
%}

%union {
    char* string;
}

%token <string> STRING
%token ASSOC ATTRIB BREAK BCDEDIT CACLS CALL CD CHCP CHDIR CHKDSK CHKNTFS CLS CMD COLOR COMP COMPACT CONVERT COPY DATE DEL DIR DISKPART DOSKEY DRIVERQUERY ECHOTK ENDLOCAL ERASE EXIT FC FIND FINDSTR FOR FORMAT FSUTIL FTYPE GOTO GPRESULT HELP ICACLS IF LABEL MD MKDIR MKLINK MODE MORE MOVE OPENFILES PATH PAUSE POPD PRINT PROMPT PUSHD RD RECOVER REM REN RENAME REPLACE RMDIR ROBOCOPY SET SETLOCAL SC SCHTASKS SHIFT SHUTDOWN SORT START SUBST SYSTEMINFO TASKLIST TASKKILL TIME TITLE TREE TYPE VER VERIFY VOL XCOPY WMIC NLINE MODO VOLVER

%type <string> argumentos

%%

input: 
     | input linea
     ;

linea: NLINE { mostrar_prompt(); }
     | HELP NLINE { imprimir_ayuda_general(); mostrar_prompt(); }
     | HELP STRING NLINE { printf("Ayuda para %s: (funcionalidad en desarrollo)\n", $2); free($2); mostrar_prompt(); }
     | comando NLINE { mostrar_prompt(); }
     | error NLINE { yyerrok; mostrar_prompt(); }
     ;

argumentos: { $$ = strdup(""); }
          | STRING { $$ = $1; }
          | argumentos STRING { 
                char* combined = malloc(strlen($1) + strlen($2) + 2);
                sprintf(combined, "%s %s", $1, $2);
                free($1); free($2);
                $$ = combined;
            }
          ;

comando:
       ASSOC argumentos      { ejecutar_comando("assoc", $2); free($2); }
     | ATTRIB argumentos     { ejecutar_comando("attrib", $2); free($2); }
     | BREAK argumentos      { ejecutar_comando("break", $2); free($2); }
     | BCDEDIT argumentos    { ejecutar_comando("bcdedit", $2); free($2); }
     | CACLS argumentos      { ejecutar_comando("cacls", $2); free($2); }
     | CALL argumentos       { ejecutar_comando("call", $2); free($2); }
     | CD argumentos         { cambiar_directorio($2); free($2); }
     | CHCP argumentos       { ejecutar_comando("chcp", $2); free($2); }
     | CHDIR argumentos      { cambiar_directorio($2); free($2); }
     | CHKDSK argumentos     { ejecutar_comando("chkdsk", $2); free($2); }
     | CHKNTFS argumentos    { ejecutar_comando("chkntfs", $2); free($2); }
     | CLS                   { ejecutar_comando("cls", ""); }
     | CMD argumentos        { ejecutar_comando("cmd", $2); free($2); }
     | COLOR argumentos      { ejecutar_comando("color", $2); free($2); }
     | COMP argumentos       { ejecutar_comando("comp", $2); free($2); }
     | COMPACT argumentos    { ejecutar_comando("compact", $2); free($2); }
     | CONVERT argumentos    { ejecutar_comando("convert", $2); free($2); }
     | COPY argumentos       { ejecutar_comando("copy", $2); free($2); }
     | DATE argumentos       { ejecutar_comando("date", $2); free($2); }
     | DEL argumentos        { ejecutar_comando("del", $2); free($2); }
     | DIR argumentos        { ejecutar_comando("dir", $2); free($2); }
     | DISKPART argumentos   { ejecutar_comando("diskpart", $2); free($2); }
     | DOSKEY argumentos     { ejecutar_comando("doskey", $2); free($2); }
     | DRIVERQUERY argumentos { ejecutar_comando("driverquery", $2); free($2); }
     | ECHOTK argumentos     { ejecutar_comando("echo", $2); free($2); }
     | ENDLOCAL              { ejecutar_comando("endlocal", ""); }
     | ERASE argumentos      { ejecutar_comando("erase", $2); free($2); }
     | EXIT                  { exit(0); }
     | FC argumentos         { ejecutar_comando("fc", $2); free($2); }
     | FIND argumentos       { ejecutar_comando("find", $2); free($2); }
     | FINDSTR argumentos    { ejecutar_comando("findstr", $2); free($2); }
     | FOR argumentos        { ejecutar_comando("for", $2); free($2); }
     | FORMAT argumentos     { ejecutar_comando("format", $2); free($2); }
     | FSUTIL argumentos     { ejecutar_comando("fsutil", $2); free($2); }
     | FTYPE argumentos      { ejecutar_comando("ftype", $2); free($2); }
     | GOTO argumentos       { ejecutar_comando("goto", $2); free($2); }
     | GPRESULT argumentos   { ejecutar_comando("gpresult", $2); free($2); }
     | ICACLS argumentos     { ejecutar_comando("icacls", $2); free($2); }
     | IF argumentos         { ejecutar_comando("if", $2); free($2); }
     | LABEL argumentos      { ejecutar_comando("label", $2); free($2); }
     | MD argumentos         { ejecutar_comando("md", $2); free($2); }
     | MKDIR argumentos      { ejecutar_comando("mkdir", $2); free($2); }
     | MKLINK argumentos     { ejecutar_comando("mklink", $2); free($2); }
     | MODO argumentos       { ejecutar_comando("mode", $2); free($2); }
     | MODE argumentos       { ejecutar_comando("mode", $2); free($2); }
     | MORE argumentos       { ejecutar_comando("more", $2); free($2); }
     | MOVE argumentos       { ejecutar_comando("move", $2); free($2); }
     | OPENFILES argumentos  { ejecutar_comando("openfiles", $2); free($2); }
     | PATH argumentos       { ejecutar_comando("path", $2); free($2); }
     | PAUSE                 { ejecutar_comando("pause", ""); }
     | POPD                  { ejecutar_comando("popd", ""); }
     | PRINT argumentos      { ejecutar_comando("print", $2); free($2); }
     | PROMPT argumentos     { ejecutar_comando("prompt", $2); free($2); }
     | PUSHD argumentos      { ejecutar_comando("pushd", $2); free($2); }
     | RD argumentos         { ejecutar_comando("rd", $2); free($2); }
     | RECOVER argumentos    { ejecutar_comando("recover", $2); free($2); }
     | REM argumentos        { ejecutar_comando("rem", $2); free($2); }
     | REN argumentos        { ejecutar_comando("ren", $2); free($2); }
     | RENAME argumentos     { ejecutar_comando("rename", $2); free($2); }
     | REPLACE argumentos    { ejecutar_comando("replace", $2); free($2); }
     | RMDIR argumentos      { ejecutar_comando("rmdir", $2); free($2); }
     | ROBOCOPY argumentos   { ejecutar_comando("robocopy", $2); free($2); }
     | SET argumentos        { ejecutar_comando("set", $2); free($2); }
     | SETLOCAL              { ejecutar_comando("setlocal", ""); }
     | SC argumentos         { ejecutar_comando("sc", $2); free($2); }
     | SCHTASKS argumentos   { ejecutar_comando("schtasks", $2); free($2); }
     | SHIFT argumentos      { ejecutar_comando("shift", $2); free($2); }
     | SHUTDOWN argumentos   { ejecutar_comando("shutdown", $2); free($2); }
     | SORT argumentos       { ejecutar_comando("sort", $2); free($2); }
     | START argumentos      { ejecutar_comando("start", $2); free($2); }
     | SUBST argumentos      { ejecutar_comando("subst", $2); free($2); }
     | SYSTEMINFO argumentos { ejecutar_comando("systeminfo", $2); free($2); }
     | TASKLIST argumentos   { ejecutar_comando("tasklist", $2); free($2); }
     | TASKKILL argumentos   { ejecutar_comando("taskkill", $2); free($2); }
     | TIME argumentos       { ejecutar_comando("time", $2); free($2); }
     | TITLE argumentos      { ejecutar_comando("title", $2); free($2); }
     | TREE argumentos       { ejecutar_comando("tree", $2); free($2); }
     | TYPE argumentos       { ejecutar_comando("type", $2); free($2); }
     | VER                   { ejecutar_comando("ver", ""); }
     | VERIFY argumentos     { ejecutar_comando("verify", $2); free($2); }
     | VOL argumentos        { ejecutar_comando("vol", $2); free($2); }
     | XCOPY argumentos      { ejecutar_comando("xcopy", $2); free($2); }
     | WMIC argumentos       { ejecutar_comando("wmic", $2); free($2); }
     | VOLVER                { volver_directorio(); }
     ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("CMD EN ESPAÑOL\n");
    mostrar_prompt();
    yyparse();
    return 0;
}
