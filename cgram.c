
# line 2 "/home/faculty/uh/cis4930/proj5/cgram.y"
#include <stdio.h>
#include <stdlib.h>
#include "cc.h"
#include "scan.h"
#include "semutil.h"
#include "sem.h"
#include "sym.h"

# line 11 "/home/faculty/uh/cis4930/proj5/cgram.y"
typedef union
#ifdef __cplusplus
	YYSTYPE
#endif
 {
   int inttype;
   char *str_ptr;
   struct sem_rec *rec_ptr;
   struct id_entry *id_ptr;
} YYSTYPE;
# define ID 257
# define CON 258
# define STR 259
# define ELSE 260
# define DOUBLE 261
# define FOR 262
# define IF 263
# define INT 264
# define RESERVED 265
# define RETURN 266
# define WHILE 267
# define DO 268
# define CONTINUE 269
# define BREAK 270
# define GOTO 271
# define LVAL 272
# define SET 273
# define SETOR 274
# define SETXOR 275
# define SETAND 276
# define SETLSH 277
# define SETRSH 278
# define SETADD 279
# define SETSUB 280
# define SETMUL 281
# define SETDIV 282
# define SETMOD 283
# define OR 284
# define AND 285
# define BITOR 286
# define BITXOR 287
# define BITAND 288
# define EQ 289
# define NE 290
# define GT 291
# define GE 292
# define LT 293
# define LE 294
# define LSH 295
# define RSH 296
# define ADD 297
# define SUB 298
# define MUL 299
# define DIV 300
# define MOD 301
# define UNARY 302
# define NOT 303
# define COM 304

#include <inttypes.h>

#ifdef __STDC__
#include <stdlib.h>
#include <string.h>
#define	YYCONST	const
#else
#include <malloc.h>
#include <memory.h>
#define	YYCONST
#endif

#include <values.h>

#if defined(__cplusplus) || defined(__STDC__)

#if defined(__cplusplus) && defined(__EXTERN_C__)
extern "C" {
#endif
#ifndef yyerror
#if defined(__cplusplus)
	void yyerror(YYCONST char *);
#endif
#endif
#ifndef yylex
	int yylex(void);
#endif
	int yyparse(void);
#if defined(__cplusplus) && defined(__EXTERN_C__)
}
#endif

#endif

#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern int yyerrflag;
YYSTYPE yylval;
YYSTYPE yyval;
typedef int yytabelem;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
#if YYMAXDEPTH > 0
int yy_yys[YYMAXDEPTH], *yys = yy_yys;
YYSTYPE yy_yyv[YYMAXDEPTH], *yyv = yy_yyv;
#else	/* user does initial allocation */
int *yys;
YYSTYPE *yyv;
#endif
static int yymaxdepth = YYMAXDEPTH;
# define YYERRCODE 256

# line 198 "/home/faculty/uh/cis4930/proj5/cgram.y"

# include <stdio.h>
# include <stdlib.h>
extern int lineno;

/* 
 * main - read a program, and parse it
 */
int main(int argc, char *argv[])
{
   int yyparse();

   enterblock();
   initlex();
   enterblock();
   if (yyparse())
      yyerror("syntax error");
   exit(0);
}

/*
 * yyerror - issue error message
 */
void yyerror(char msg[])
{
   fprintf(stderr, " %s.  Line %d\n", msg, lineno);
}
static YYCONST yytabelem yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
-1, 15,
	40, 17,
	-2, 10,
	};
# define YYNPROD 95
# define YYLAST 526
static YYCONST yytabelem yyact[]={

    49,   158,    64,    65,    66,    67,    68,    69,    70,   190,
   169,    61,    62,    63,   144,    49,    68,    69,    70,    43,
    64,    65,    66,    67,    68,    69,    70,   180,   168,   139,
   145,   144,    49,    29,    43,    61,    62,    63,   146,   147,
   151,   149,   150,   148,    64,    65,    66,    67,    68,    69,
    70,    49,   124,     9,   143,    20,     8,    62,    63,    66,
    67,    68,    69,    70,   123,    64,    65,    66,    67,    68,
    69,    70,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    52,    11,    96,    77,    15,     9,    60,
   120,     8,   140,    49,   115,    22,    63,    25,    52,    82,
    82,    57,    49,    64,    65,    66,    67,    68,    69,    70,
    14,    82,    78,    26,    83,    21,   194,   104,    81,    13,
    13,     6,   184,   183,    19,   155,   122,    76,    75,     4,
   157,    16,    45,   156,   141,    12,   198,    31,    54,    56,
    28,    55,   176,    74,    72,    71,    18,   119,    32,    24,
    83,    83,    42,    27,    17,     7,    53,     5,     3,     2,
    10,     1,    83,   177,   125,     0,     0,     0,     0,     0,
    58,     0,     0,     0,     0,   102,     0,   103,     0,    95,
     0,     0,     0,   101,   100,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    61,    62,    63,     0,    30,     0,
     0,     0,     0,    64,    65,    66,    67,    68,    69,    70,
     0,     0,   152,   153,   142,     0,     0,    59,    50,    51,
     0,     0,    37,    34,     0,     0,    41,    35,    36,    38,
    39,    40,    44,    50,    51,     0,     0,    37,    34,     0,
     0,    41,    35,    36,    38,    39,    40,     0,    46,    80,
    50,    51,   145,   144,    23,   173,   174,     0,    47,     0,
     0,     0,     0,    46,    48,   178,     0,     0,    80,    50,
    51,   145,   144,    47,    61,    62,    63,   186,   191,    48,
    46,     0,     0,    64,    65,    66,    67,    68,    69,    70,
    47,    61,    62,    63,     0,   117,    48,   145,   144,    46,
    64,    65,    66,    67,    68,    69,    70,     0,   189,    47,
    80,    50,    51,   116,   195,    48,    61,    62,    63,    80,
    50,    51,    73,   181,   202,    64,    65,    66,    67,    68,
    69,    70,     0,     9,     0,     0,     8,     0,    33,     0,
     0,    46,     0,     0,     0,     0,    33,   200,     0,     0,
    46,    47,     0,     0,     0,    79,     0,    48,     0,     0,
    47,    97,    98,    99,     0,     0,    48,     0,     0,     0,
     0,     0,     0,     0,   154,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,     0,     0,     0,   121,     0,
     0,     0,     0,     0,     0,   118,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
     0,     0,     0,     0,   172,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   185,     0,     0,     0,
     0,     0,     0,   192,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   201,     0,     0,     0,     0,
   162,   163,   164,   165,   166,   167,   159,   160,   161,     0,
   171,     0,     0,     0,     0,     0,     0,     0,   170,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   175,     0,     0,     0,   179,     0,     0,     0,   182,
     0,   121,     0,     0,     0,     0,   187,   188,     0,     0,
     0,     0,   193,     0,     0,   196,     0,   197,     0,     0,
     0,   199,     0,     0,     0,   203 };
static YYCONST yytabelem yypact[]={

-10000000,-10000000,  -173,-10000000,    76,-10000000,  -170,-10000000,-10000000,-10000000,
   106,-10000000,-10000000,  -202,-10000000,    24,   -30,   -26,    72,-10000000,
    24,   -60,-10000000,-10000000,   -25,-10000000,-10000000,    97,  -202,-10000000,
     8,-10000000,   -40,    30,   105,   104,-10000000,   103,    69,    68,
  -171,    53,-10000000,-10000000,    60,  -201,  -172,    62,    62,    62,
-10000000,-10000000,-10000000,  -208,-10000000,  -208,-10000000,-10000000,-10000000,    59,
-10000000,    62,    62,    62,    62,    62,    62,    62,    62,    62,
    62,    -8,-10000000,-10000000,    62,-10000000,-10000000,    67,-10000000,     5,
    71,-10000000,    11,    62,    62,    62,    62,    62,    62,    62,
    62,    62,    62,    62,    62,-10000000,    23,-10000000,-10000000,   -12,
   -33,    75,  -202,  -202,-10000000,  -230,  -192,  -293,  -238,  -238,
  -283,  -283,-10000000,-10000000,-10000000,    13,  -251,    -8,    -8,-10000000,
    66,  -275,-10000000,-10000000,-10000000,    89,  -275,   -92,  -275,  -275,
  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,-10000000,
-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,    62,    62,    62,    62,
    62,    62,-10000000,   -13,  -257,-10000000,    62,-10000000,-10000000,-10000000,
    -8,    -8,  -275,  -275,  -275,  -275,  -275,  -275,-10000000,   102,
    -8,  -275,  -233,-10000000,  -271,-10000000,-10000000,    64,  -254,-10000000,
-10000000,-10000000,    -8,-10000000,-10000000,-10000000,   -32,    62,-10000000,-10000000,
    57,-10000000,-10000000,-10000000,-10000000,    95,-10000000,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000 };
static YYCONST yytabelem yypgo[]={

     0,   132,   313,   164,    94,   122,   163,   161,   129,   110,
   160,   121,   322,   159,   158,   157,   156,   155,   131,   154,
   153,   147,   152,   254,   149,   137,   148,    90 };
static YYCONST yytabelem yyr1[]={

     0,     7,    13,    13,    14,    14,    16,    16,     8,     8,
     9,     9,     9,    11,    11,    15,    17,    10,    10,    19,
    19,    20,    20,    21,    12,     5,    22,    18,    18,    23,
    23,    26,    26,    24,    25,    25,    25,    25,    25,    25,
    25,    25,    25,    25,    25,    25,    25,     6,     6,     4,
     4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
     3,    27,    27,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     1,     1 };
static YYCONST yytabelem yyr2[]={

     0,     3,     1,     5,     5,     3,     1,     7,     5,     7,
     3,     7,     9,     3,     3,     7,     9,     5,     3,     5,
     7,     5,     9,     1,     1,     1,     7,     1,     5,     5,
     7,     5,     7,     1,     5,    15,    23,    21,    23,    33,
     5,     5,     7,     5,     7,     3,     3,     1,     3,     7,
     7,     7,     7,     7,     7,     9,     9,     5,     3,     3,
     7,     1,     3,     7,     7,     7,     7,     7,     7,     7,
     7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
     7,     7,     7,     7,     5,     5,     5,     3,     7,     9,
     7,     3,     3,     3,     9 };
static YYCONST yytabelem yychk[]={

-10000000,    -7,   -13,   -14,    -8,   -15,   -11,   -17,   264,   261,
   -10,   257,    59,    44,    -9,   257,   -18,   -19,    40,    -9,
   257,    91,   125,   -23,   -24,   123,    41,   -20,   -11,    93,
   258,   -25,   -26,    -2,   263,   267,   268,   262,   269,   270,
   271,   266,   -22,    59,   257,    -1,   288,   298,   304,    40,
   258,   259,   123,   -16,    41,    44,    -9,    93,   -25,   257,
    59,   286,   287,   288,   295,   296,   297,   298,   299,   300,
   301,    40,    40,   -12,    40,    59,    59,   257,    59,    -2,
   257,    58,    40,    91,   273,   274,   275,   276,   277,   278,
   279,   280,   281,   282,   283,    -1,   257,    -2,    -2,    -2,
   -18,    -8,   -11,   -11,    58,    -2,    -2,    -2,    -2,    -2,
    -2,    -2,    -2,    -2,    -2,    -4,    -2,   303,   -12,   -21,
   -27,    -2,    59,    59,    41,    -3,    -2,    -2,    -2,    -2,
    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    41,
   125,    59,    -9,    41,   285,   284,   289,   290,   294,   292,
   293,   291,    -4,    -4,   -23,    59,    44,    41,    93,   -12,
   -12,   -12,    -2,    -2,    -2,    -2,    -2,    -2,    41,   267,
   -12,    -2,   -23,    -4,    -4,   -12,    40,    -6,    -4,   -12,
   260,   -21,   -12,    59,    -5,   -23,    -4,   -12,   -12,    -5,
    41,   -27,   -23,   -12,    59,    -5,   -12,   -12,    41,   -12,
   -21,   -23,    -5,   -12 };
static YYCONST yytabelem yydef[]={

     2,    -2,     1,     3,     0,     5,     0,    27,    13,    14,
     0,    18,     4,     0,     8,    -2,    33,     0,     0,     9,
    10,     0,    15,    28,     0,     6,    19,     0,     0,    11,
     0,    29,     0,     0,     0,     0,    24,     0,     0,     0,
     0,     0,    45,    46,    93,    87,     0,     0,     0,     0,
    91,    92,    27,    16,    20,     0,    21,    12,    30,    93,
    34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    24,    23,    61,    40,    41,     0,    43,     0,
    93,    31,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    84,    93,    85,    86,     0,
    33,     0,     0,     0,    32,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,     0,    58,     0,     0,    33,
     0,    62,    42,    44,    88,     0,    59,     0,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    90,
    26,     7,    22,    24,    24,    24,     0,     0,     0,     0,
     0,     0,    57,     0,     0,    24,     0,    89,    94,    33,
     0,     0,    49,    50,    51,    52,    53,    54,    24,     0,
    47,    60,    24,    55,    56,    23,    24,     0,    48,    35,
    25,    33,     0,    24,    24,    25,     0,    61,    33,    24,
     0,    25,    24,    37,    24,     0,    36,    38,    24,    23,
    33,    25,    24,    39 };
typedef struct
#ifdef __cplusplus
	yytoktype
#endif
{
#ifdef __cplusplus
const
#endif
char *t_name; int t_val; } yytoktype;
#ifndef YYDEBUG
#	define YYDEBUG	0	/* don't allow debugging */
#endif

#if YYDEBUG

yytoktype yytoks[] =
{
	"ID",	257,
	"CON",	258,
	"STR",	259,
	"ELSE",	260,
	"DOUBLE",	261,
	"FOR",	262,
	"IF",	263,
	"INT",	264,
	"RESERVED",	265,
	"RETURN",	266,
	"WHILE",	267,
	"DO",	268,
	"CONTINUE",	269,
	"BREAK",	270,
	"GOTO",	271,
	"LVAL",	272,
	"SET",	273,
	"SETOR",	274,
	"SETXOR",	275,
	"SETAND",	276,
	"SETLSH",	277,
	"SETRSH",	278,
	"SETADD",	279,
	"SETSUB",	280,
	"SETMUL",	281,
	"SETDIV",	282,
	"SETMOD",	283,
	"OR",	284,
	"AND",	285,
	"BITOR",	286,
	"BITXOR",	287,
	"BITAND",	288,
	"EQ",	289,
	"NE",	290,
	"GT",	291,
	"GE",	292,
	"LT",	293,
	"LE",	294,
	"LSH",	295,
	"RSH",	296,
	"ADD",	297,
	"SUB",	298,
	"MUL",	299,
	"DIV",	300,
	"MOD",	301,
	"UNARY",	302,
	"NOT",	303,
	"COM",	304,
	"-unknown-",	-1	/* ends search */
};

#ifdef __cplusplus
const
#endif
char * yyreds[] =
{
	"-no such reduction-",
	"prog : externs",
	"externs : /* empty */",
	"externs : externs extern",
	"extern : dcl ';'",
	"extern : func",
	"dcls : /* empty */",
	"dcls : dcls dcl ';'",
	"dcl : type dclr",
	"dcl : dcl ',' dclr",
	"dclr : ID",
	"dclr : ID '[' ']'",
	"dclr : ID '[' CON ']'",
	"type : INT",
	"type : DOUBLE",
	"func : fhead stmts '}'",
	"fhead : fname fargs '{' dcls",
	"fname : type ID",
	"fname : ID",
	"fargs : '(' ')'",
	"fargs : '(' args ')'",
	"args : type dclr",
	"args : args ',' type dclr",
	"s : /* empty */",
	"m : /* empty */",
	"n : /* empty */",
	"block : '{' stmts '}'",
	"stmts : /* empty */",
	"stmts : stmts lblstmt",
	"lblstmt : b stmt",
	"lblstmt : b labels stmt",
	"labels : ID ':'",
	"labels : labels ID ':'",
	"b : /* empty */",
	"stmt : expr ';'",
	"stmt : IF '(' cexpr ')' m lblstmt m",
	"stmt : IF '(' cexpr ')' m lblstmt ELSE n m lblstmt m",
	"stmt : WHILE '(' m cexpr ')' m s lblstmt n m",
	"stmt : DO m s lblstmt WHILE '(' m cexpr ')' ';' m",
	"stmt : FOR '(' expro ';' m cexpro ';' m expro n ')' m s lblstmt n m",
	"stmt : CONTINUE ';'",
	"stmt : BREAK ';'",
	"stmt : GOTO ID ';'",
	"stmt : RETURN ';'",
	"stmt : RETURN expr ';'",
	"stmt : block",
	"stmt : ';'",
	"cexpro : /* empty */",
	"cexpro : cexpr",
	"cexpr : expr EQ expr",
	"cexpr : expr NE expr",
	"cexpr : expr LE expr",
	"cexpr : expr GE expr",
	"cexpr : expr LT expr",
	"cexpr : expr GT expr",
	"cexpr : cexpr AND m cexpr",
	"cexpr : cexpr OR m cexpr",
	"cexpr : NOT cexpr",
	"cexpr : expr",
	"exprs : expr",
	"exprs : exprs ',' expr",
	"expro : /* empty */",
	"expro : expr",
	"expr : lval SET expr",
	"expr : lval SETOR expr",
	"expr : lval SETXOR expr",
	"expr : lval SETAND expr",
	"expr : lval SETLSH expr",
	"expr : lval SETRSH expr",
	"expr : lval SETADD expr",
	"expr : lval SETSUB expr",
	"expr : lval SETMUL expr",
	"expr : lval SETDIV expr",
	"expr : lval SETMOD expr",
	"expr : expr BITOR expr",
	"expr : expr BITXOR expr",
	"expr : expr BITAND expr",
	"expr : expr LSH expr",
	"expr : expr RSH expr",
	"expr : expr ADD expr",
	"expr : expr SUB expr",
	"expr : expr MUL expr",
	"expr : expr DIV expr",
	"expr : expr MOD expr",
	"expr : BITAND lval",
	"expr : SUB expr",
	"expr : COM expr",
	"expr : lval",
	"expr : ID '(' ')'",
	"expr : ID '(' exprs ')'",
	"expr : '(' expr ')'",
	"expr : CON",
	"expr : STR",
	"lval : ID",
	"lval : ID '[' expr ']'",
};
#endif /* YYDEBUG */
# line	1 "/usr/ccs/bin/yaccpar"
/*
 * Copyright (c) 1993 by Sun Microsystems, Inc.
 */

#pragma ident	"@(#)yaccpar	6.16	99/01/20 SMI"

/*
** Skeleton parser driver for yacc output
*/

/*
** yacc user known macros and defines
*/
#define YYERROR		goto yyerrlab
#define YYACCEPT	return(0)
#define YYABORT		return(1)
#define YYBACKUP( newtoken, newvalue )\
{\
	if ( yychar >= 0 || ( yyr2[ yytmp ] >> 1 ) != 1 )\
	{\
		yyerror( "syntax error - cannot backup" );\
		goto yyerrlab;\
	}\
	yychar = newtoken;\
	yystate = *yyps;\
	yylval = newvalue;\
	goto yynewstate;\
}
#define YYRECOVERING()	(!!yyerrflag)
#define YYNEW(type)	malloc(sizeof(type) * yynewmax)
#define YYCOPY(to, from, type) \
	(type *) memcpy(to, (char *) from, yymaxdepth * sizeof (type))
#define YYENLARGE( from, type) \
	(type *) realloc((char *) from, yynewmax * sizeof(type))
#ifndef YYDEBUG
#	define YYDEBUG	1	/* make debugging available */
#endif

/*
** user known globals
*/
int yydebug;			/* set to 1 to get debugging */

/*
** driver internal defines
*/
#define YYFLAG		(-10000000)

/*
** global variables used by the parser
*/
YYSTYPE *yypv;			/* top of value stack */
int *yyps;			/* top of state stack */

int yystate;			/* current state */
int yytmp;			/* extra var (lasts between blocks) */

int yynerrs;			/* number of errors */
int yyerrflag;			/* error recovery flag */
int yychar;			/* current input token number */



#ifdef YYNMBCHARS
#define YYLEX()		yycvtok(yylex())
/*
** yycvtok - return a token if i is a wchar_t value that exceeds 255.
**	If i<255, i itself is the token.  If i>255 but the neither 
**	of the 30th or 31st bit is on, i is already a token.
*/
#if defined(__STDC__) || defined(__cplusplus)
int yycvtok(int i)
#else
int yycvtok(i) int i;
#endif
{
	int first = 0;
	int last = YYNMBCHARS - 1;
	int mid;
	wchar_t j;

	if(i&0x60000000){/*Must convert to a token. */
		if( yymbchars[last].character < i ){
			return i;/*Giving up*/
		}
		while ((last>=first)&&(first>=0)) {/*Binary search loop*/
			mid = (first+last)/2;
			j = yymbchars[mid].character;
			if( j==i ){/*Found*/ 
				return yymbchars[mid].tvalue;
			}else if( j<i ){
				first = mid + 1;
			}else{
				last = mid -1;
			}
		}
		/*No entry in the table.*/
		return i;/* Giving up.*/
	}else{/* i is already a token. */
		return i;
	}
}
#else/*!YYNMBCHARS*/
#define YYLEX()		yylex()
#endif/*!YYNMBCHARS*/

/*
** yyparse - return 0 if worked, 1 if syntax error not recovered from
*/
#if defined(__STDC__) || defined(__cplusplus)
int yyparse(void)
#else
int yyparse()
#endif
{
	register YYSTYPE *yypvt = 0;	/* top of value stack for $vars */

#if defined(__cplusplus) || defined(lint)
/*
	hacks to please C++ and lint - goto's inside
	switch should never be executed
*/
	static int __yaccpar_lint_hack__ = 0;
	switch (__yaccpar_lint_hack__)
	{
		case 1: goto yyerrlab;
		case 2: goto yynewstate;
	}
#endif

	/*
	** Initialize externals - yyparse may be called more than once
	*/
	yypv = &yyv[-1];
	yyps = &yys[-1];
	yystate = 0;
	yytmp = 0;
	yynerrs = 0;
	yyerrflag = 0;
	yychar = -1;

#if YYMAXDEPTH <= 0
	if (yymaxdepth <= 0)
	{
		if ((yymaxdepth = YYEXPAND(0)) <= 0)
		{
			yyerror("yacc initialization error");
			YYABORT;
		}
	}
#endif

	{
		register YYSTYPE *yy_pv;	/* top of value stack */
		register int *yy_ps;		/* top of state stack */
		register int yy_state;		/* current state */
		register int  yy_n;		/* internal state number info */
	goto yystack;	/* moved from 6 lines above to here to please C++ */

		/*
		** get globals into registers.
		** branch to here only if YYBACKUP was called.
		*/
	yynewstate:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;
		goto yy_newstate;

		/*
		** get globals into registers.
		** either we just started, or we just finished a reduction
		*/
	yystack:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;

		/*
		** top of for (;;) loop while no reductions done
		*/
	yy_stack:
		/*
		** put a state and value onto the stacks
		*/
#if YYDEBUG
		/*
		** if debugging, look up token value in list of value vs.
		** name pairs.  0 and negative (-1) are special values.
		** Note: linear search is used since time is not a real
		** consideration while debugging.
		*/
		if ( yydebug )
		{
			register int yy_i;

			printf( "State %d, token ", yy_state );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ++yy_ps >= &yys[ yymaxdepth ] )	/* room on stack? */
		{
			/*
			** reallocate and recover.  Note that pointers
			** have to be reset, or bad things will happen
			*/
			long yyps_index = (yy_ps - yys);
			long yypv_index = (yy_pv - yyv);
			long yypvt_index = (yypvt - yyv);
			int yynewmax;
#ifdef YYEXPAND
			yynewmax = YYEXPAND(yymaxdepth);
#else
			yynewmax = 2 * yymaxdepth;	/* double table size */
			if (yymaxdepth == YYMAXDEPTH)	/* first time growth */
			{
				char *newyys = (char *)YYNEW(int);
				char *newyyv = (char *)YYNEW(YYSTYPE);
				if (newyys != 0 && newyyv != 0)
				{
					yys = YYCOPY(newyys, yys, int);
					yyv = YYCOPY(newyyv, yyv, YYSTYPE);
				}
				else
					yynewmax = 0;	/* failed */
			}
			else				/* not first time */
			{
				yys = YYENLARGE(yys, int);
				yyv = YYENLARGE(yyv, YYSTYPE);
				if (yys == 0 || yyv == 0)
					yynewmax = 0;	/* failed */
			}
#endif
			if (yynewmax <= yymaxdepth)	/* tables not expanded */
			{
				yyerror( "yacc stack overflow" );
				YYABORT;
			}
			yymaxdepth = yynewmax;

			yy_ps = yys + yyps_index;
			yy_pv = yyv + yypv_index;
			yypvt = yyv + yypvt_index;
		}
		*yy_ps = yy_state;
		*++yy_pv = yyval;

		/*
		** we have a new state - find out what to do
		*/
	yy_newstate:
		if ( ( yy_n = yypact[ yy_state ] ) <= YYFLAG )
			goto yydefault;		/* simple state */
#if YYDEBUG
		/*
		** if debugging, need to mark whether new token grabbed
		*/
		yytmp = yychar < 0;
#endif
		if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
			yychar = 0;		/* reached EOF */
#if YYDEBUG
		if ( yydebug && yytmp )
		{
			register int yy_i;

			printf( "Received token " );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ( ( yy_n += yychar ) < 0 ) || ( yy_n >= YYLAST ) )
			goto yydefault;
		if ( yychk[ yy_n = yyact[ yy_n ] ] == yychar )	/*valid shift*/
		{
			yychar = -1;
			yyval = yylval;
			yy_state = yy_n;
			if ( yyerrflag > 0 )
				yyerrflag--;
			goto yy_stack;
		}

	yydefault:
		if ( ( yy_n = yydef[ yy_state ] ) == -2 )
		{
#if YYDEBUG
			yytmp = yychar < 0;
#endif
			if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
				yychar = 0;		/* reached EOF */
#if YYDEBUG
			if ( yydebug && yytmp )
			{
				register int yy_i;

				printf( "Received token " );
				if ( yychar == 0 )
					printf( "end-of-file\n" );
				else if ( yychar < 0 )
					printf( "-none-\n" );
				else
				{
					for ( yy_i = 0;
						yytoks[yy_i].t_val >= 0;
						yy_i++ )
					{
						if ( yytoks[yy_i].t_val
							== yychar )
						{
							break;
						}
					}
					printf( "%s\n", yytoks[yy_i].t_name );
				}
			}
#endif /* YYDEBUG */
			/*
			** look through exception table
			*/
			{
				register YYCONST int *yyxi = yyexca;

				while ( ( *yyxi != -1 ) ||
					( yyxi[1] != yy_state ) )
				{
					yyxi += 2;
				}
				while ( ( *(yyxi += 2) >= 0 ) &&
					( *yyxi != yychar ) )
					;
				if ( ( yy_n = yyxi[1] ) < 0 )
					YYACCEPT;
			}
		}

		/*
		** check for syntax error
		*/
		if ( yy_n == 0 )	/* have an error */
		{
			/* no worry about speed here! */
			switch ( yyerrflag )
			{
			case 0:		/* new error */
				yyerror( "syntax error" );
				goto skip_init;
			yyerrlab:
				/*
				** get globals into registers.
				** we have a user generated syntax type error
				*/
				yy_pv = yypv;
				yy_ps = yyps;
				yy_state = yystate;
			skip_init:
				yynerrs++;
				/* FALLTHRU */
			case 1:
			case 2:		/* incompletely recovered error */
					/* try again... */
				yyerrflag = 3;
				/*
				** find state where "error" is a legal
				** shift action
				*/
				while ( yy_ps >= yys )
				{
					yy_n = yypact[ *yy_ps ] + YYERRCODE;
					if ( yy_n >= 0 && yy_n < YYLAST &&
						yychk[yyact[yy_n]] == YYERRCODE)					{
						/*
						** simulate shift of "error"
						*/
						yy_state = yyact[ yy_n ];
						goto yy_stack;
					}
					/*
					** current state has no shift on
					** "error", pop stack
					*/
#if YYDEBUG
#	define _POP_ "Error recovery pops state %d, uncovers state %d\n"
					if ( yydebug )
						printf( _POP_, *yy_ps,
							yy_ps[-1] );
#	undef _POP_
#endif
					yy_ps--;
					yy_pv--;
				}
				/*
				** there is no state on stack with "error" as
				** a valid shift.  give up.
				*/
				YYABORT;
			case 3:		/* no shift yet; eat a token */
#if YYDEBUG
				/*
				** if debugging, look up token in list of
				** pairs.  0 and negative shouldn't occur,
				** but since timing doesn't matter when
				** debugging, it doesn't hurt to leave the
				** tests here.
				*/
				if ( yydebug )
				{
					register int yy_i;

					printf( "Error recovery discards " );
					if ( yychar == 0 )
						printf( "token end-of-file\n" );
					else if ( yychar < 0 )
						printf( "token -none-\n" );
					else
					{
						for ( yy_i = 0;
							yytoks[yy_i].t_val >= 0;
							yy_i++ )
						{
							if ( yytoks[yy_i].t_val
								== yychar )
							{
								break;
							}
						}
						printf( "token %s\n",
							yytoks[yy_i].t_name );
					}
				}
#endif /* YYDEBUG */
				if ( yychar == 0 )	/* reached EOF. quit */
					YYABORT;
				yychar = -1;
				goto yy_newstate;
			}
		}/* end if ( yy_n == 0 ) */
		/*
		** reduction by production yy_n
		** put stack tops, etc. so things right after switch
		*/
#if YYDEBUG
		/*
		** if debugging, print the string that is the user's
		** specification of the reduction which is just about
		** to be done.
		*/
		if ( yydebug )
			printf( "Reduce by (%d) \"%s\"\n",
				yy_n, yyreds[ yy_n ] );
#endif
		yytmp = yy_n;			/* value to switch over */
		yypvt = yy_pv;			/* $vars top of value stack */
		/*
		** Look in goto table for next state
		** Sorry about using yy_state here as temporary
		** register variable, but why not, if it works...
		** If yyr2[ yy_n ] doesn't have the low order bit
		** set, then there is no action to be done for
		** this reduction.  So, no saving & unsaving of
		** registers done.  The only difference between the
		** code just after the if and the body of the if is
		** the goto yy_stack in the body.  This way the test
		** can be made before the choice of what to do is needed.
		*/
		{
			/* length of production doubled with extra bit */
			register int yy_len = yyr2[ yy_n ];

			if ( !( yy_len & 01 ) )
			{
				yy_len >>= 1;
				yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
				yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
					*( yy_ps -= yy_len ) + 1;
				if ( yy_state >= YYLAST ||
					yychk[ yy_state =
					yyact[ yy_state ] ] != -yy_n )
				{
					yy_state = yyact[ yypgo[ yy_n ] ];
				}
				goto yy_stack;
			}
			yy_len >>= 1;
			yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
			yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
				*( yy_ps -= yy_len ) + 1;
			if ( yy_state >= YYLAST ||
				yychk[ yy_state = yyact[ yy_state ] ] != -yy_n )
			{
				yy_state = yyact[ yypgo[ yy_n ] ];
			}
		}
					/* save until reenter driver code */
		yystate = yy_state;
		yyps = yy_ps;
		yypv = yy_pv;
	}
	/*
	** code supplied by user is placed in this switch
	*/
	switch( yytmp )
	{
		
case 1:
# line 37 "/home/faculty/uh/cis4930/proj5/cgram.y"
{} break;
case 2:
# line 40 "/home/faculty/uh/cis4930/proj5/cgram.y"
{} break;
case 3:
# line 41 "/home/faculty/uh/cis4930/proj5/cgram.y"
{} break;
case 4:
# line 44 "/home/faculty/uh/cis4930/proj5/cgram.y"
{} break;
case 5:
# line 45 "/home/faculty/uh/cis4930/proj5/cgram.y"
{} break;
case 6:
# line 48 "/home/faculty/uh/cis4930/proj5/cgram.y"
{} break;
case 7:
# line 49 "/home/faculty/uh/cis4930/proj5/cgram.y"
{} break;
case 8:
# line 52 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.id_ptr = dcl(yypvt[-0].id_ptr, yypvt[-1].inttype, 0); } break;
case 9:
# line 53 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.id_ptr = dcl(yypvt[-0].id_ptr, yypvt[-2].id_ptr->i_type&~T_ARRAY, 0); } break;
case 10:
# line 56 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.id_ptr = dclr(yypvt[-0].str_ptr, 0, 1); } break;
case 11:
# line 57 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.id_ptr = dclr(yypvt[-2].str_ptr, T_ARRAY, 1); } break;
case 12:
# line 58 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.id_ptr = dclr(yypvt[-3].str_ptr, T_ARRAY, atoi(yypvt[-1].str_ptr)); } break;
case 13:
# line 61 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.inttype = T_INT; } break;
case 14:
# line 62 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.inttype = T_DOUBLE; } break;
case 15:
# line 65 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ ftail(); } break;
case 16:
# line 68 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ fhead(yypvt[-3].id_ptr); } break;
case 17:
# line 71 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.id_ptr = fname(yypvt[-1].inttype, yypvt[-0].str_ptr); } break;
case 18:
# line 72 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.id_ptr = fname(T_INT, yypvt[-0].str_ptr); } break;
case 19:
# line 75 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ enterblock(); } break;
case 20:
# line 76 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ enterblock(); } break;
case 21:
# line 79 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ dcl(yypvt[-0].id_ptr, yypvt[-1].inttype, PARAM); } break;
case 22:
# line 80 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ dcl(yypvt[-0].id_ptr, yypvt[-1].inttype, PARAM); } break;
case 23:
# line 83 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ startloopscope(); } break;
case 24:
# line 86 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.inttype = m(); } break;
case 25:
# line 89 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = n(); } break;
case 26:
# line 92 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ } break;
case 27:
# line 95 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ } break;
case 28:
# line 96 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ } break;
case 29:
# line 99 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ } break;
case 30:
# line 100 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ } break;
case 31:
# line 103 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ labeldcl(yypvt[-1].str_ptr); } break;
case 32:
# line 104 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ labeldcl(yypvt[-1].str_ptr); } break;
case 33:
# line 107 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ bgnstmt(); } break;
case 34:
# line 111 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ } break;
case 35:
# line 113 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ doif(yypvt[-4].rec_ptr, yypvt[-2].inttype, yypvt[-0].inttype); } break;
case 36:
# line 115 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ doifelse(yypvt[-8].rec_ptr, yypvt[-6].inttype, yypvt[-3].rec_ptr, yypvt[-2].inttype, yypvt[-0].inttype); } break;
case 37:
# line 117 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ dowhile(yypvt[-7].inttype, yypvt[-6].rec_ptr, yypvt[-4].inttype, yypvt[-1].rec_ptr, yypvt[-0].inttype); } break;
case 38:
# line 119 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ dodo(yypvt[-9].inttype, yypvt[-4].inttype, yypvt[-3].rec_ptr, yypvt[-0].inttype); } break;
case 39:
# line 121 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ dofor(yypvt[-11].inttype, yypvt[-10].rec_ptr, yypvt[-8].inttype, yypvt[-6].rec_ptr, yypvt[-4].inttype, yypvt[-1].rec_ptr, yypvt[-0].inttype); } break;
case 40:
# line 123 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ docontinue(); } break;
case 41:
# line 125 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ dobreak(); } break;
case 42:
# line 127 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ dogoto(yypvt[-1].str_ptr); } break;
case 43:
# line 129 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ doret((struct sem_rec *) NULL); } break;
case 44:
# line 131 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ doret(yypvt[-1].rec_ptr); } break;
case 45:
# line 133 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ } break;
case 46:
# line 135 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ } break;
case 47:
# line 138 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = node(0, 0, n(), 0); } break;
case 48:
# line 139 "/home/faculty/uh/cis4930/proj5/cgram.y"
{} break;
case 49:
# line 142 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = rel("==", yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 50:
# line 143 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = rel("!=", yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 51:
# line 144 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = rel("<=", yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 52:
# line 145 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = rel(">=", yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 53:
# line 146 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = rel("<",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 54:
# line 147 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = rel(">",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 55:
# line 148 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = ccand(yypvt[-3].rec_ptr, yypvt[-1].inttype, yypvt[-0].rec_ptr); } break;
case 56:
# line 149 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = ccor(yypvt[-3].rec_ptr, yypvt[-1].inttype, yypvt[-0].rec_ptr); } break;
case 57:
# line 150 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = ccnot(yypvt[-0].rec_ptr); } break;
case 58:
# line 151 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = ccexpr(yypvt[-0].rec_ptr); } break;
case 59:
# line 154 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = yypvt[-0].rec_ptr; } break;
case 60:
# line 155 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = exprs(yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 61:
# line 158 "/home/faculty/uh/cis4930/proj5/cgram.y"
{} break;
case 62:
# line 159 "/home/faculty/uh/cis4930/proj5/cgram.y"
{} break;
case 63:
# line 162 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = set("",   yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 64:
# line 163 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = set("|",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 65:
# line 164 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = set("^",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 66:
# line 165 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = set("&",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 67:
# line 166 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = set("<<", yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 68:
# line 167 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = set(">>", yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 69:
# line 168 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = set("+",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 70:
# line 169 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = set("-",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 71:
# line 170 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = set("*",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 72:
# line 171 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = set("/",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 73:
# line 172 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = set("%",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 74:
# line 173 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = opb("|",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 75:
# line 174 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = opb("^",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 76:
# line 175 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = opb("&",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 77:
# line 176 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = opb("<<", yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 78:
# line 177 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = opb(">>", yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 79:
# line 178 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = op2("+",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 80:
# line 179 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = op2("-",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 81:
# line 180 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = op2("*",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 82:
# line 181 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = op2("/",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 83:
# line 182 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = op2("%",  yypvt[-2].rec_ptr, yypvt[-0].rec_ptr); } break;
case 84:
# line 184 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = yypvt[-0].rec_ptr; } break;
case 85:
# line 185 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = op1("-",      yypvt[-0].rec_ptr); } break;
case 86:
# line 186 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = op1("~",      yypvt[-0].rec_ptr); } break;
case 87:
# line 187 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = op1("@",      yypvt[-0].rec_ptr); } break;
case 88:
# line 188 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = call(yypvt[-2].str_ptr, (struct sem_rec *) NULL); } break;
case 89:
# line 189 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = call(yypvt[-3].str_ptr, yypvt[-1].rec_ptr); } break;
case 90:
# line 190 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = yypvt[-1].rec_ptr; } break;
case 91:
# line 191 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = con(yypvt[-0].str_ptr); } break;
case 92:
# line 192 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = string(yypvt[-0].str_ptr); } break;
case 93:
# line 195 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = id(yypvt[-0].str_ptr); } break;
case 94:
# line 196 "/home/faculty/uh/cis4930/proj5/cgram.y"
{ yyval.rec_ptr = sindex(id(yypvt[-3].str_ptr), yypvt[-1].rec_ptr); } break;
# line	531 "/usr/ccs/bin/yaccpar"
	}
	goto yystack;		/* reset registers in driver code */
}

