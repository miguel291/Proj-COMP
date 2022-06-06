/* A Bison parser, made by GNU Bison 3.8.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    SEMICOLON = 259,               /* SEMICOLON  */
    COMMA = 260,                   /* COMMA  */
    BLANKID = 261,                 /* BLANKID  */
    ASSIGN = 262,                  /* ASSIGN  */
    STAR = 263,                    /* STAR  */
    DIV = 264,                     /* DIV  */
    EQ = 265,                      /* EQ  */
    GE = 266,                      /* GE  */
    GT = 267,                      /* GT  */
    LBRACE = 268,                  /* LBRACE  */
    LE = 269,                      /* LE  */
    LPAR = 270,                    /* LPAR  */
    LSQ = 271,                     /* LSQ  */
    LT = 272,                      /* LT  */
    MOD = 273,                     /* MOD  */
    NE = 274,                      /* NE  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    RBRACE = 277,                  /* RBRACE  */
    RPAR = 278,                    /* RPAR  */
    RSQ = 279,                     /* RSQ  */
    PACKAGE = 280,                 /* PACKAGE  */
    RETURN = 281,                  /* RETURN  */
    ELSE = 282,                    /* ELSE  */
    FOR = 283,                     /* FOR  */
    IF = 284,                      /* IF  */
    VAR = 285,                     /* VAR  */
    INT = 286,                     /* INT  */
    FLOAT32 = 287,                 /* FLOAT32  */
    BOOL = 288,                    /* BOOL  */
    STRING = 289,                  /* STRING  */
    PRINT = 290,                   /* PRINT  */
    PARSEINT = 291,                /* PARSEINT  */
    FUNC = 292,                    /* FUNC  */
    CMDARGS = 293,                 /* CMDARGS  */
    ID = 294,                      /* ID  */
    INTLIT = 295,                  /* INTLIT  */
    REALLIT = 296,                 /* REALLIT  */
    STRLIT = 297,                  /* STRLIT  */
    MINUS = 298,                   /* MINUS  */
    NOT = 299,                     /* NOT  */
    PLUS = 300,                    /* PLUS  */
    UNARY = 301                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUMBER 258
#define SEMICOLON 259
#define COMMA 260
#define BLANKID 261
#define ASSIGN 262
#define STAR 263
#define DIV 264
#define EQ 265
#define GE 266
#define GT 267
#define LBRACE 268
#define LE 269
#define LPAR 270
#define LSQ 271
#define LT 272
#define MOD 273
#define NE 274
#define AND 275
#define OR 276
#define RBRACE 277
#define RPAR 278
#define RSQ 279
#define PACKAGE 280
#define RETURN 281
#define ELSE 282
#define FOR 283
#define IF 284
#define VAR 285
#define INT 286
#define FLOAT32 287
#define BOOL 288
#define STRING 289
#define PRINT 290
#define PARSEINT 291
#define FUNC 292
#define CMDARGS 293
#define ID 294
#define INTLIT 295
#define REALLIT 296
#define STRLIT 297
#define MINUS 298
#define NOT 299
#define PLUS 300
#define UNARY 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 65 "gocompiler.y"

    char *id;
    node* n;
    var_aux* va;

#line 165 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
