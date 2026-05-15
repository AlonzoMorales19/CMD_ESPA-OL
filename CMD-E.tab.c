
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "CMD-E.y"

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


/* Line 189 of yacc.c  */
#line 220 "CMD-E.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRING = 258,
     ASSOC = 259,
     ATTRIB = 260,
     BREAK = 261,
     BCDEDIT = 262,
     CACLS = 263,
     CALL = 264,
     CD = 265,
     CHCP = 266,
     CHDIR = 267,
     CHKDSK = 268,
     CHKNTFS = 269,
     CLS = 270,
     CMD = 271,
     COLOR = 272,
     COMP = 273,
     COMPACT = 274,
     CONVERT = 275,
     COPY = 276,
     DATE = 277,
     DEL = 278,
     DIR = 279,
     DISKPART = 280,
     DOSKEY = 281,
     DRIVERQUERY = 282,
     ECHOTK = 283,
     ENDLOCAL = 284,
     ERASE = 285,
     EXIT = 286,
     FC = 287,
     FIND = 288,
     FINDSTR = 289,
     FOR = 290,
     FORMAT = 291,
     FSUTIL = 292,
     FTYPE = 293,
     GOTO = 294,
     GPRESULT = 295,
     HELP = 296,
     ICACLS = 297,
     IF = 298,
     LABEL = 299,
     MD = 300,
     MKDIR = 301,
     MKLINK = 302,
     MODE = 303,
     MORE = 304,
     MOVE = 305,
     OPENFILES = 306,
     PATH = 307,
     PAUSE = 308,
     POPD = 309,
     PRINT = 310,
     PROMPT = 311,
     PUSHD = 312,
     RD = 313,
     RECOVER = 314,
     REM = 315,
     REN = 316,
     RENAME = 317,
     REPLACE = 318,
     RMDIR = 319,
     ROBOCOPY = 320,
     SET = 321,
     SETLOCAL = 322,
     SC = 323,
     SCHTASKS = 324,
     SHIFT = 325,
     SHUTDOWN = 326,
     SORT = 327,
     START = 328,
     SUBST = 329,
     SYSTEMINFO = 330,
     TASKLIST = 331,
     TASKKILL = 332,
     TIME = 333,
     TITLE = 334,
     TREE = 335,
     TYPE = 336,
     VER = 337,
     VERIFY = 338,
     VOL = 339,
     XCOPY = 340,
     WMIC = 341,
     NLINE = 342,
     MODO = 343,
     VOLVER = 344
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 147 "CMD-E.y"

    char* string;



/* Line 214 of yacc.c  */
#line 351 "CMD-E.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 363 "CMD-E.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  5
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNRULES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   344

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    16,    19,    22,
      23,    25,    28,    31,    34,    37,    40,    43,    46,    49,
      52,    55,    58,    61,    63,    66,    69,    72,    75,    78,
      81,    84,    87,    90,    93,    96,    99,   102,   104,   107,
     109,   112,   115,   118,   121,   124,   127,   130,   133,   136,
     139,   142,   145,   148,   151,   154,   157,   160,   163,   166,
     169,   172,   174,   176,   179,   182,   185,   188,   191,   194,
     197,   200,   203,   206,   209,   212,   214,   217,   220,   223,
     226,   229,   232,   235,   238,   241,   244,   247,   250,   253,
     256,   258,   261,   264,   267,   270
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      91,     0,    -1,    -1,    91,    92,    -1,    87,    -1,    41,
      87,    -1,    41,     3,    87,    -1,    94,    87,    -1,     1,
      87,    -1,    -1,     3,    -1,    93,     3,    -1,     4,    93,
      -1,     5,    93,    -1,     6,    93,    -1,     7,    93,    -1,
       8,    93,    -1,     9,    93,    -1,    10,    93,    -1,    11,
      93,    -1,    12,    93,    -1,    13,    93,    -1,    14,    93,
      -1,    15,    -1,    16,    93,    -1,    17,    93,    -1,    18,
      93,    -1,    19,    93,    -1,    20,    93,    -1,    21,    93,
      -1,    22,    93,    -1,    23,    93,    -1,    24,    93,    -1,
      25,    93,    -1,    26,    93,    -1,    27,    93,    -1,    28,
      93,    -1,    29,    -1,    30,    93,    -1,    31,    -1,    32,
      93,    -1,    33,    93,    -1,    34,    93,    -1,    35,    93,
      -1,    36,    93,    -1,    37,    93,    -1,    38,    93,    -1,
      39,    93,    -1,    40,    93,    -1,    42,    93,    -1,    43,
      93,    -1,    44,    93,    -1,    45,    93,    -1,    46,    93,
      -1,    47,    93,    -1,    88,    93,    -1,    48,    93,    -1,
      49,    93,    -1,    50,    93,    -1,    51,    93,    -1,    52,
      93,    -1,    53,    -1,    54,    -1,    55,    93,    -1,    56,
      93,    -1,    57,    93,    -1,    58,    93,    -1,    59,    93,
      -1,    60,    93,    -1,    61,    93,    -1,    62,    93,    -1,
      63,    93,    -1,    64,    93,    -1,    65,    93,    -1,    66,
      93,    -1,    67,    -1,    68,    93,    -1,    69,    93,    -1,
      70,    93,    -1,    71,    93,    -1,    72,    93,    -1,    73,
      93,    -1,    74,    93,    -1,    75,    93,    -1,    76,    93,
      -1,    77,    93,    -1,    78,    93,    -1,    79,    93,    -1,
      80,    93,    -1,    81,    93,    -1,    82,    -1,    83,    93,
      -1,    84,    93,    -1,    85,    93,    -1,    86,    93,    -1,
      89,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   158,   158,   159,   162,   163,   164,   165,   166,   169,
     170,   171,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "ASSOC", "ATTRIB", "BREAK",
  "BCDEDIT", "CACLS", "CALL", "CD", "CHCP", "CHDIR", "CHKDSK", "CHKNTFS",
  "CLS", "CMD", "COLOR", "COMP", "COMPACT", "CONVERT", "COPY", "DATE",
  "DEL", "DIR", "DISKPART", "DOSKEY", "DRIVERQUERY", "ECHOTK", "ENDLOCAL",
  "ERASE", "EXIT", "FC", "FIND", "FINDSTR", "FOR", "FORMAT", "FSUTIL",
  "FTYPE", "GOTO", "GPRESULT", "HELP", "ICACLS", "IF", "LABEL", "MD",
  "MKDIR", "MKLINK", "MODE", "MORE", "MOVE", "OPENFILES", "PATH", "PAUSE",
  "POPD", "PRINT", "PROMPT", "PUSHD", "RD", "RECOVER", "REM", "REN",
  "RENAME", "REPLACE", "RMDIR", "ROBOCOPY", "SET", "SETLOCAL", "SC",
  "SCHTASKS", "SHIFT", "SHUTDOWN", "SORT", "START", "SUBST", "SYSTEMINFO",
  "TASKLIST", "TASKKILL", "TIME", "TITLE", "TREE", "TYPE", "VER", "VERIFY",
  "VOL", "XCOPY", "WMIC", "NLINE", "MODO", "VOLVER", "$accept", "input",
  "linea", "argumentos", "comando", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    92,    92,    92,    92,    92,    93,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     3,     2,     2,     0,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,    23,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,    37,
       9,    39,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     0,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,    61,    62,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,    75,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,    90,     9,     9,     9,     9,     4,     9,    95,
       3,     0,     8,    10,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    38,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,     5,
      49,    50,    51,    52,    53,    54,    56,    57,    58,    59,
      60,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    91,    92,    93,
      94,    55,     7,    11,     6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    90,    94,    91
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -86
static const yytype_int8 yypact[] =
{
     -86,     0,   -86,   -85,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,   -86,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,   -86,
      88,   -86,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,   -86,   -86,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,   -86,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,   -86,    88,    88,    88,    88,   -86,    88,   -86,
     -86,   -84,   -86,   -86,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,     6,   -86,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,   -86,   -86,   -86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -86,   -86,   -86,    92,   -86
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       2,     3,    92,   172,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
     128,    93,   173,   174,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,   118,     0,   119,   120,   121,   122,   123,   124,
     125,   126,   127,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   129,   167,   168,   169,   170,     0,
     171
};

static const yytype_int8 yycheck[] =
{
       0,     1,    87,    87,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       3,     3,     3,    87,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    87,    83,    84,    85,    86,    -1,
      88
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    91,     0,     1,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      92,    94,    87,     3,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,     3,    87,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    87,     3,    87
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 162 "CMD-E.y"
    { mostrar_prompt(); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 163 "CMD-E.y"
    { imprimir_ayuda_general(); mostrar_prompt(); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 164 "CMD-E.y"
    { printf("Ayuda para %s: (funcionalidad en desarrollo)\n", (yyvsp[(2) - (3)].string)); free((yyvsp[(2) - (3)].string)); mostrar_prompt(); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 165 "CMD-E.y"
    { mostrar_prompt(); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 166 "CMD-E.y"
    { yyerrok; mostrar_prompt(); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 169 "CMD-E.y"
    { (yyval.string) = strdup(""); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 170 "CMD-E.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 171 "CMD-E.y"
    { 
                char* combined = malloc(strlen((yyvsp[(1) - (2)].string)) + strlen((yyvsp[(2) - (2)].string)) + 2);
                sprintf(combined, "%s %s", (yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string));
                free((yyvsp[(1) - (2)].string)); free((yyvsp[(2) - (2)].string));
                (yyval.string) = combined;
            ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 180 "CMD-E.y"
    { ejecutar_comando("assoc", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 181 "CMD-E.y"
    { ejecutar_comando("attrib", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 182 "CMD-E.y"
    { ejecutar_comando("break", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 183 "CMD-E.y"
    { ejecutar_comando("bcdedit", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 184 "CMD-E.y"
    { ejecutar_comando("cacls", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 185 "CMD-E.y"
    { ejecutar_comando("call", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 186 "CMD-E.y"
    { cambiar_directorio((yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 187 "CMD-E.y"
    { ejecutar_comando("chcp", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 188 "CMD-E.y"
    { cambiar_directorio((yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 189 "CMD-E.y"
    { ejecutar_comando("chkdsk", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 190 "CMD-E.y"
    { ejecutar_comando("chkntfs", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 191 "CMD-E.y"
    { ejecutar_comando("cls", ""); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 192 "CMD-E.y"
    { ejecutar_comando("cmd", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 193 "CMD-E.y"
    { ejecutar_comando("color", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 194 "CMD-E.y"
    { ejecutar_comando("comp", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 195 "CMD-E.y"
    { ejecutar_comando("compact", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 196 "CMD-E.y"
    { ejecutar_comando("convert", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 197 "CMD-E.y"
    { ejecutar_comando("copy", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 198 "CMD-E.y"
    { ejecutar_comando("date", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 199 "CMD-E.y"
    { ejecutar_comando("del", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 200 "CMD-E.y"
    { ejecutar_comando("dir", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 201 "CMD-E.y"
    { ejecutar_comando("diskpart", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 202 "CMD-E.y"
    { ejecutar_comando("doskey", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 203 "CMD-E.y"
    { ejecutar_comando("driverquery", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 204 "CMD-E.y"
    { ejecutar_comando("echo", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 205 "CMD-E.y"
    { ejecutar_comando("endlocal", ""); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 206 "CMD-E.y"
    { ejecutar_comando("erase", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 207 "CMD-E.y"
    { exit(0); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 208 "CMD-E.y"
    { ejecutar_comando("fc", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 209 "CMD-E.y"
    { ejecutar_comando("find", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 210 "CMD-E.y"
    { ejecutar_comando("findstr", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 211 "CMD-E.y"
    { ejecutar_comando("for", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 212 "CMD-E.y"
    { ejecutar_comando("format", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 213 "CMD-E.y"
    { ejecutar_comando("fsutil", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 214 "CMD-E.y"
    { ejecutar_comando("ftype", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 215 "CMD-E.y"
    { ejecutar_comando("goto", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 216 "CMD-E.y"
    { ejecutar_comando("gpresult", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 217 "CMD-E.y"
    { ejecutar_comando("icacls", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 218 "CMD-E.y"
    { ejecutar_comando("if", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 219 "CMD-E.y"
    { ejecutar_comando("label", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 220 "CMD-E.y"
    { ejecutar_comando("md", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 221 "CMD-E.y"
    { ejecutar_comando("mkdir", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 222 "CMD-E.y"
    { ejecutar_comando("mklink", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 223 "CMD-E.y"
    { ejecutar_comando("mode", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 224 "CMD-E.y"
    { ejecutar_comando("mode", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 225 "CMD-E.y"
    { ejecutar_comando("more", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 226 "CMD-E.y"
    { ejecutar_comando("move", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 227 "CMD-E.y"
    { ejecutar_comando("openfiles", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 228 "CMD-E.y"
    { ejecutar_comando("path", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 229 "CMD-E.y"
    { ejecutar_comando("pause", ""); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 230 "CMD-E.y"
    { ejecutar_comando("popd", ""); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 231 "CMD-E.y"
    { ejecutar_comando("print", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 232 "CMD-E.y"
    { ejecutar_comando("prompt", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 233 "CMD-E.y"
    { ejecutar_comando("pushd", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 234 "CMD-E.y"
    { ejecutar_comando("rd", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 235 "CMD-E.y"
    { ejecutar_comando("recover", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 236 "CMD-E.y"
    { ejecutar_comando("rem", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 237 "CMD-E.y"
    { ejecutar_comando("ren", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 238 "CMD-E.y"
    { ejecutar_comando("rename", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 239 "CMD-E.y"
    { ejecutar_comando("replace", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 240 "CMD-E.y"
    { ejecutar_comando("rmdir", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 241 "CMD-E.y"
    { ejecutar_comando("robocopy", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 242 "CMD-E.y"
    { ejecutar_comando("set", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 243 "CMD-E.y"
    { ejecutar_comando("setlocal", ""); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 244 "CMD-E.y"
    { ejecutar_comando("sc", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 245 "CMD-E.y"
    { ejecutar_comando("schtasks", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 246 "CMD-E.y"
    { ejecutar_comando("shift", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 247 "CMD-E.y"
    { ejecutar_comando("shutdown", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 248 "CMD-E.y"
    { ejecutar_comando("sort", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 249 "CMD-E.y"
    { ejecutar_comando("start", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 250 "CMD-E.y"
    { ejecutar_comando("subst", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 251 "CMD-E.y"
    { ejecutar_comando("systeminfo", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 252 "CMD-E.y"
    { ejecutar_comando("tasklist", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 253 "CMD-E.y"
    { ejecutar_comando("taskkill", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 254 "CMD-E.y"
    { ejecutar_comando("time", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 255 "CMD-E.y"
    { ejecutar_comando("title", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 256 "CMD-E.y"
    { ejecutar_comando("tree", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 257 "CMD-E.y"
    { ejecutar_comando("type", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 258 "CMD-E.y"
    { ejecutar_comando("ver", ""); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 259 "CMD-E.y"
    { ejecutar_comando("verify", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 260 "CMD-E.y"
    { ejecutar_comando("vol", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 261 "CMD-E.y"
    { ejecutar_comando("xcopy", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 262 "CMD-E.y"
    { ejecutar_comando("wmic", (yyvsp[(2) - (2)].string)); free((yyvsp[(2) - (2)].string)); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 263 "CMD-E.y"
    { volver_directorio(); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2367 "CMD-E.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 266 "CMD-E.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("CMD EN ESPAÑOL\n");
    mostrar_prompt();
    yyparse();
    return 0;
}

