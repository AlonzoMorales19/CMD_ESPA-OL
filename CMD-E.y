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
    if (path == NULL || strlen(path) == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s\n", cwd);
        }
    } else {
        if (chdir(path) != 0) {
            perror("Error al cambiar de directorio");
        }
    }
}

void imprimir_ayuda_general() {
    printf("\nPara obtener mas informacion acerca de un comando especifico, escriba AYUDA\n");
    printf("seguido del nombre de comando\n");
    printf("ASOCIAR        Muestra o modifica las asociaciones de las extensiones de archivos.\n");
    printf("ATRIBUTO       Muestra o cambia los atributos del archivo.\n");
    printf("INTERRUMPIR    Establece o elimina la comprobacion extendida de Ctrl+C.\n");
    printf("ENTRAR         Cambia al directorio especificado (sustituye a CD).\n");
    printf("LIMPIAR        Borra la pantalla.\n");
    printf("LISTAR         Muestra una lista de archivos y subdirectorios.\n");
    printf("SALIR          Sale del programa.\n");
}
%}

%union {
    char* string;
}

%token <string> STRING
%token ASSOC ATTRIB BREAK BCDEDIT CACLS CALL CD CHCP CHDIR CHKDSK CHKNTFS CLS CMD COLOR COMP COMPACT CONVERT COPY DATE DEL DIR DISKPART DOSKEY DRIVERQUERY ECHOTK ENDLOCAL ERASE EXIT FC FIND FINDSTR FOR FORMAT FSUTIL FTYPE GOTO GPRESULT HELP ICACLS IF LABEL MD MKDIR MKLINK MODE MORE MOVE OPENFILES PATH PAUSE POPD PRINT PROMPT PUSHD RD RECOVER REM REN RENAME REPLACE RMDIR ROBOCOPY SET SETLOCAL SC SCHTASKS SHIFT SHUTDOWN SORT START SUBST SYSTEMINFO TASKLIST TASKKILL TIME TITLE TREE TYPE VER VERIFY VOL XCOPY WMIC NLINE MODO

%type <string> argumentos

%%

input: /* vacio */
     | input linea
     ;

linea: NLINE { mostrar_prompt(); }
     | HELP NLINE { imprimir_ayuda_general(); mostrar_prompt(); }
     | HELP STRING NLINE { printf("Ayuda para %s: (funcionalidad en desarrollo)\n", $2); free($2); mostrar_prompt(); }
     | comando NLINE { mostrar_prompt(); }
     | error NLINE { yyerrok; mostrar_prompt(); }
     ;

argumentos: /* vacio */ { $$ = strdup(""); }
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
     ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Microsoft Windows [Version 10.0.19045.3803]\n");
    printf("(c) Microsoft Corporation. Todos los derechos reservados.\n");
    mostrar_prompt();
    yyparse();
    return 0;
}
