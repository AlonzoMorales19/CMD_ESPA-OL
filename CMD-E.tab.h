
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 147 "CMD-E.y"

    char* string;



/* Line 1676 of yacc.c  */
#line 147 "CMD-E.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


