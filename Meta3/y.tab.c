/* A Bison parser, made by GNU Bison 3.8.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30801

/* Bison version string.  */
#define YYBISON_VERSION "3.8.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "gocompiler.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "y.tab.h"
#include "structures.h"


    int yylex (void);
    void yyerror (char *s);
    char buf[256];
    int linha;
    int coluna;
    node* myprogram;
    extern char* yytext;
    int error;
    int first = 1;
    node* ifh;
    node* no_aux;
    var_aux* var_au;
    extern int yacc_col;
    

#line 96 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 247 "y.tab.c"

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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_SEMICOLON = 4,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 5,                      /* COMMA  */
  YYSYMBOL_BLANKID = 6,                    /* BLANKID  */
  YYSYMBOL_ASSIGN = 7,                     /* ASSIGN  */
  YYSYMBOL_STAR = 8,                       /* STAR  */
  YYSYMBOL_DIV = 9,                        /* DIV  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_GE = 11,                        /* GE  */
  YYSYMBOL_GT = 12,                        /* GT  */
  YYSYMBOL_LBRACE = 13,                    /* LBRACE  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_LPAR = 15,                      /* LPAR  */
  YYSYMBOL_LSQ = 16,                       /* LSQ  */
  YYSYMBOL_LT = 17,                        /* LT  */
  YYSYMBOL_MOD = 18,                       /* MOD  */
  YYSYMBOL_NE = 19,                        /* NE  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_RBRACE = 22,                    /* RBRACE  */
  YYSYMBOL_RPAR = 23,                      /* RPAR  */
  YYSYMBOL_RSQ = 24,                       /* RSQ  */
  YYSYMBOL_PACKAGE = 25,                   /* PACKAGE  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_ELSE = 27,                      /* ELSE  */
  YYSYMBOL_FOR = 28,                       /* FOR  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_VAR = 30,                       /* VAR  */
  YYSYMBOL_INT = 31,                       /* INT  */
  YYSYMBOL_FLOAT32 = 32,                   /* FLOAT32  */
  YYSYMBOL_BOOL = 33,                      /* BOOL  */
  YYSYMBOL_STRING = 34,                    /* STRING  */
  YYSYMBOL_PRINT = 35,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 36,                  /* PARSEINT  */
  YYSYMBOL_FUNC = 37,                      /* FUNC  */
  YYSYMBOL_CMDARGS = 38,                   /* CMDARGS  */
  YYSYMBOL_ID = 39,                        /* ID  */
  YYSYMBOL_INTLIT = 40,                    /* INTLIT  */
  YYSYMBOL_REALLIT = 41,                   /* REALLIT  */
  YYSYMBOL_STRLIT = 42,                    /* STRLIT  */
  YYSYMBOL_MINUS = 43,                     /* MINUS  */
  YYSYMBOL_NOT = 44,                       /* NOT  */
  YYSYMBOL_PLUS = 45,                      /* PLUS  */
  YYSYMBOL_UNARY = 46,                     /* UNARY  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_declarations = 49,              /* declarations  */
  YYSYMBOL_vardeclaration = 50,            /* vardeclaration  */
  YYSYMBOL_varspec = 51,                   /* varspec  */
  YYSYMBOL_varspec2 = 52,                  /* varspec2  */
  YYSYMBOL_type = 53,                      /* type  */
  YYSYMBOL_funcdeclaration = 54,           /* funcdeclaration  */
  YYSYMBOL_parameters = 55,                /* parameters  */
  YYSYMBOL_parameters2 = 56,               /* parameters2  */
  YYSYMBOL_funcbody = 57,                  /* funcbody  */
  YYSYMBOL_varsandstatements = 58,         /* varsandstatements  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_statement1 = 60,                /* statement1  */
  YYSYMBOL_parseargs = 61,                 /* parseargs  */
  YYSYMBOL_funcinvocation = 62,            /* funcinvocation  */
  YYSYMBOL_funcinvocation1 = 63,           /* funcinvocation1  */
  YYSYMBOL_expr = 64                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   335

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    73,    73,    74,    77,    78,    79,    80,    81,    84,
      85,    88,    91,    92,    95,    96,    97,    98,   101,   102,
     103,   104,   107,   109,   110,   114,   116,   117,   118,   119,
     122,   123,   124,   125,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   138,   139,   142,   143,   146,   147,   148,
     151,   152,   153,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "SEMICOLON",
  "COMMA", "BLANKID", "ASSIGN", "STAR", "DIV", "EQ", "GE", "GT", "LBRACE",
  "LE", "LPAR", "LSQ", "LT", "MOD", "NE", "AND", "OR", "RBRACE", "RPAR",
  "RSQ", "PACKAGE", "RETURN", "ELSE", "FOR", "IF", "VAR", "INT", "FLOAT32",
  "BOOL", "STRING", "PRINT", "PARSEINT", "FUNC", "CMDARGS", "ID", "INTLIT",
  "REALLIT", "STRLIT", "MINUS", "NOT", "PLUS", "UNARY", "$accept",
  "program", "declarations", "vardeclaration", "varspec", "varspec2",
  "type", "funcdeclaration", "parameters", "parameters2", "funcbody",
  "varsandstatements", "statement", "statement1", "parseargs",
  "funcinvocation", "funcinvocation1", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,   -33,    27,    24,   -65,   -65,   -14,   -14,     3,   -10,
      39,    67,    -6,   -65,   -65,    50,   -65,   -65,    73,    61,
     -22,    55,    40,   -65,   -65,   -65,   -65,   -65,    95,   121,
      58,   -65,   -65,   -65,    78,   -65,   -65,    95,   108,   -65,
      81,    78,   -65,   -65,   -65,   122,   -65,   221,   282,   221,
      83,     7,    92,    98,   -65,   -65,    72,   -65,   118,   102,
      29,   110,   -65,   -65,   221,   221,   221,   -65,   260,   122,
     154,   168,   175,   127,   221,    44,   -65,   -65,   121,   122,
     -65,   116,   184,   -65,   -65,   -65,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   120,
     122,   122,   117,   214,   138,   260,   -65,   -65,   260,   -65,
     -65,   -65,   -65,   -65,   -65,    -5,    -5,    -5,    -5,    -5,
     -65,    -5,   290,   274,   123,   123,   -65,   124,   134,   -65,
     -65,   113,    16,    59,   -65,   131,   144,    60,   -65,   -65,
     147,   132,   -65,   260,   122,   153,   161,    75,   -65,   160,
     230,   177,   183,   -65,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     8,     1,     8,     3,     2,     0,     0,
       7,     6,     0,    13,     9,     0,     5,     4,     0,     0,
       0,     0,     0,    14,    15,    17,    16,    11,     0,     0,
       0,    10,    12,    29,     0,    21,    24,     0,     0,    19,
      22,     0,    20,    42,    28,     0,    25,    37,     0,     0,
       0,     0,     0,     0,    39,    38,     0,    18,     0,     0,
       0,    55,    53,    54,     0,     0,     0,    56,    36,     0,
       0,     0,     0,     0,     0,     0,    26,    27,     0,     0,
      31,     0,     0,    57,    59,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,    52,    49,    52,    23,
      43,    74,    73,    63,    62,    67,    70,    66,    69,    65,
      64,    68,    71,    72,    61,    60,    35,     0,     0,    41,
      40,     0,     0,     0,    34,    33,     0,     0,    48,    47,
       0,     0,    51,    50,     0,     0,     0,     0,    32,     0,
       0,     0,     0,    46,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   186,   170,   197,   -65,   -18,   -65,   -65,   -65,
      76,   -65,   172,   -64,   -65,   -38,   104,   -40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     6,    10,    14,    19,    27,    11,    30,    40,
      35,    38,    58,    59,    54,    67,   132,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    28,     1,    86,    87,    99,     3,    55,    70,    71,
      34,    36,    73,    93,    74,   110,     8,    29,    12,    41,
      82,   137,    75,     9,    83,    84,    85,     4,     5,    15,
      81,    55,   103,    13,   105,   108,   127,   128,    97,   138,
      98,    55,    13,    16,    60,   106,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    60,
     109,   142,    55,    55,   137,    20,    22,   107,    61,    62,
      63,    17,    64,    65,    66,    60,   149,    21,    31,    32,
     146,    37,   139,    61,    62,    63,    56,    64,    65,    66,
      60,    33,    23,    24,    25,    26,    76,   143,    72,    61,
      62,    63,    77,    64,    65,    66,    55,   150,    33,    43,
      39,    78,    44,    42,    61,    62,    63,    57,    64,    65,
      66,    45,    79,    43,    80,    75,    23,    24,    25,    26,
      46,    86,    87,   104,    47,    45,    48,    49,     8,   111,
     129,    93,   126,    50,   -44,   131,   134,    51,    47,   136,
      48,    49,    23,    24,    25,    26,   135,    50,   140,   141,
     144,    51,    86,    87,    88,    89,    90,   100,    91,   147,
     145,    92,    93,    94,    95,    96,    86,    87,    88,    89,
      90,   101,    91,   148,   151,    92,    93,    94,    95,    96,
      60,     7,    86,    87,    88,    89,    90,    97,    91,    98,
     153,    92,    93,    94,    95,    96,   154,   112,    52,    18,
      53,    97,   133,    98,    61,    62,    63,   102,    64,    65,
      66,     0,    86,    87,    88,    89,    90,    97,    91,    98,
       0,    92,    93,    94,    95,    96,    60,   130,    86,    87,
      88,    89,    90,     0,    91,     0,     0,    92,    93,    94,
      95,    96,     0,     0,   152,     0,     0,    97,     0,    98,
      61,    62,    63,     0,    64,    65,    66,     0,    86,    87,
      88,    89,    90,    97,    91,    98,     0,    92,    93,    94,
      95,    96,    86,    87,    88,    89,    90,     0,    91,     0,
       0,    92,    93,    94,    95,    69,     0,    60,    86,    87,
      88,    89,    90,    97,    91,    98,     0,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    97,     0,    98,
       0,    61,    62,    63,     0,    64,    65,    66,     0,     0,
       0,     0,     0,    97,     0,    98
};

static const yytype_int16 yycheck[] =
{
      38,    23,    25,     8,     9,    69,    39,    45,    48,    49,
      28,    29,     5,    18,     7,    79,    30,    39,    15,    37,
      60,     5,    15,    37,    64,    65,    66,     0,     4,    39,
       1,    69,    72,    39,    74,    75,   100,   101,    43,    23,
      45,    79,    39,     4,    15,     1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    15,
      78,     1,   100,   101,     5,    15,     5,    23,    39,    40,
      41,     4,    43,    44,    45,    15,     1,     4,    23,    39,
     144,    23,    23,    39,    40,    41,     5,    43,    44,    45,
      15,    13,    31,    32,    33,    34,     4,   137,    15,    39,
      40,    41,     4,    43,    44,    45,   144,   147,    13,     1,
      34,    39,     4,    37,    39,    40,    41,    41,    43,    44,
      45,    13,     4,     1,    22,    15,    31,    32,    33,    34,
      22,     8,     9,     6,    26,    13,    28,    29,    30,    23,
      23,    18,    22,    35,    22,     7,    22,    39,    26,    36,
      28,    29,    31,    32,    33,    34,    22,    35,    27,    15,
      13,    39,     8,     9,    10,    11,    12,    13,    14,    16,
      38,    17,    18,    19,    20,    21,     8,     9,    10,    11,
      12,    13,    14,    22,    24,    17,    18,    19,    20,    21,
      15,     5,     8,     9,    10,    11,    12,    43,    14,    45,
      23,    17,    18,    19,    20,    21,    23,    23,    38,    12,
      38,    43,   108,    45,    39,    40,    41,    42,    43,    44,
      45,    -1,     8,     9,    10,    11,    12,    43,    14,    45,
      -1,    17,    18,    19,    20,    21,    15,    23,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    17,    18,    19,
      20,    21,    -1,    -1,    24,    -1,    -1,    43,    -1,    45,
      39,    40,    41,    -1,    43,    44,    45,    -1,     8,     9,
      10,    11,    12,    43,    14,    45,    -1,    17,    18,    19,
      20,    21,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    17,    18,    19,    20,    13,    -1,    15,     8,     9,
      10,    11,    12,    43,    14,    45,    -1,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,
      -1,    39,    40,    41,    -1,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    48,    39,     0,     4,    49,    49,    30,    37,
      50,    54,    15,    39,    51,    39,     4,     4,    51,    52,
      15,     4,     5,    31,    32,    33,    34,    53,    23,    39,
      55,    23,    39,    13,    53,    57,    53,    23,    58,    57,
      56,    53,    57,     1,     4,    13,    22,    26,    28,    29,
      35,    39,    50,    59,    61,    62,     5,    57,    59,    60,
      15,    39,    40,    41,    43,    44,    45,    62,    64,    13,
      64,    64,    15,     5,     7,    15,     4,     4,    39,     4,
      22,     1,    64,    64,    64,    64,     8,     9,    10,    11,
      12,    14,    17,    18,    19,    20,    21,    43,    45,    60,
      13,    13,    42,    64,     6,    64,     1,    23,    64,    53,
      60,    23,    23,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    22,    60,    60,    23,
      23,     7,    63,    63,    22,    22,    36,     5,    23,    23,
      27,    15,     1,    64,    13,    38,    60,    16,    22,     1,
      64,    24,    24,    23,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    49,    49,    49,    50,
      50,    51,    52,    52,    53,    53,    53,    53,    54,    54,
      54,    54,    55,    56,    56,    57,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    62,    62,    62,
      63,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     3,     2,     2,     0,     2,
       5,     3,     3,     0,     1,     1,     1,     1,     7,     6,
       6,     5,     3,     4,     0,     3,     3,     3,     2,     0,
       3,     3,     9,     5,     5,     4,     2,     1,     1,     1,
       4,     4,     1,     3,     0,    11,    11,     5,     5,     3,
       3,     3,     0,     1,     1,     1,     1,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: PACKAGE ID SEMICOLON declarations  */
#line 73 "gocompiler.y"
                                                                                            {(yyval.n)=myprogram=insert_node(program,(yyvsp[0].n),NULL,NULL,0,linha,yacc_col);}
#line 1553 "y.tab.c"
    break;

  case 3: /* program: PACKAGE ID declarations  */
#line 74 "gocompiler.y"
                                                                                            {(yyval.n)=myprogram=insert_node(program,(yyvsp[0].n),NULL,NULL,0,linha,yacc_col);}
#line 1559 "y.tab.c"
    break;

  case 4: /* declarations: declarations funcdeclaration SEMICOLON  */
#line 77 "gocompiler.y"
                                                                                            {(yyval.n)=insert_node(decl_list,(yyvsp[-1].n),(yyvsp[-2].n),NULL,0,linha,yacc_col);}
#line 1565 "y.tab.c"
    break;

  case 5: /* declarations: declarations vardeclaration SEMICOLON  */
#line 78 "gocompiler.y"
                                                                                                        {(yyval.n)=insert_node(decl_list,(yyvsp[-1].n),(yyvsp[-2].n),NULL,0,linha,yacc_col);}
#line 1571 "y.tab.c"
    break;

  case 6: /* declarations: declarations funcdeclaration  */
#line 79 "gocompiler.y"
                                                                                            {(yyval.n)=insert_node(decl_list,(yyvsp[0].n),(yyvsp[-1].n),NULL,0,linha,yacc_col);}
#line 1577 "y.tab.c"
    break;

  case 7: /* declarations: declarations vardeclaration  */
#line 80 "gocompiler.y"
                                                                                            {(yyval.n)=insert_node(decl_list,(yyvsp[0].n),(yyvsp[-1].n),NULL,0,linha,yacc_col);}
#line 1583 "y.tab.c"
    break;

  case 8: /* declarations: %empty  */
#line 81 "gocompiler.y"
                                                                                                {(yyval.n)=NULL;}
#line 1589 "y.tab.c"
    break;

  case 9: /* vardeclaration: VAR varspec  */
#line 84 "gocompiler.y"
                                                                                            {(yyval.n)=(yyvsp[0].n);}
#line 1595 "y.tab.c"
    break;

  case 10: /* vardeclaration: VAR LPAR varspec SEMICOLON RPAR  */
#line 85 "gocompiler.y"
                                                                                            {(yyval.n)=(yyvsp[-2].n);}
#line 1601 "y.tab.c"
    break;

  case 11: /* varspec: ID varspec2 type  */
#line 88 "gocompiler.y"
                                                                                                {if((yyvsp[-1].va)!=NULL){no_aux=insert_vardec_node((yyvsp[-1].va),(yyvsp[0].id));}sprintf(buf,"%s\n%s",(yyvsp[0].id),(yyvsp[-2].id));ifh=insert_node(vardec,NULL,NULL,buf,0,linha,yacc_col);if((yyvsp[-1].va)!=NULL){ifh->next=no_aux;}(yyval.n)=ifh;}
#line 1607 "y.tab.c"
    break;

  case 12: /* varspec2: varspec2 COMMA ID  */
#line 91 "gocompiler.y"
                                                                                            {if((yyvsp[-2].va)!=NULL){var_au=(yyvsp[-2].va);while(var_au->next!=NULL){var_au=var_au->next;}var_au->next=insert_var_aux((yyvsp[0].id));(yyval.va)=(yyvsp[-2].va);}else{(yyval.va)=insert_var_aux((yyvsp[0].id));}}
#line 1613 "y.tab.c"
    break;

  case 13: /* varspec2: %empty  */
#line 92 "gocompiler.y"
                                                                                            {(yyval.va)=NULL;}
#line 1619 "y.tab.c"
    break;

  case 14: /* type: INT  */
#line 95 "gocompiler.y"
                                                                                                        {(yyval.id)="Int";}
#line 1625 "y.tab.c"
    break;

  case 15: /* type: FLOAT32  */
#line 96 "gocompiler.y"
                                                                                                        {(yyval.id)="Float32";}
#line 1631 "y.tab.c"
    break;

  case 16: /* type: STRING  */
#line 97 "gocompiler.y"
                                                                                                        {(yyval.id)="String";}
#line 1637 "y.tab.c"
    break;

  case 17: /* type: BOOL  */
#line 98 "gocompiler.y"
                                                                                                        {(yyval.id)="Bool";}
#line 1643 "y.tab.c"
    break;

  case 18: /* funcdeclaration: FUNC ID LPAR parameters RPAR type funcbody  */
#line 101 "gocompiler.y"
                                                                        {sprintf(buf,"%s\n%s",(yyvsp[-5].id),(yyvsp[-1].id));ifh=insert_node(func_head,(yyvsp[-3].n),NULL,buf,0,linha,yacc_col);ifh->next=(yyvsp[0].n);(yyval.n)=insert_node(func_decl,ifh,NULL,NULL,0,linha,yacc_col);}
#line 1649 "y.tab.c"
    break;

  case 19: /* funcdeclaration: FUNC ID LPAR RPAR type funcbody  */
#line 102 "gocompiler.y"
                                                                        {sprintf(buf,"%s\n%s",(yyvsp[-4].id),(yyvsp[-1].id));ifh=insert_node(func_head,NULL,NULL,buf,0,linha,yacc_col);ifh->next=(yyvsp[0].n);(yyval.n)=insert_node(func_decl,ifh,NULL,NULL,0,linha,yacc_col);}
#line 1655 "y.tab.c"
    break;

  case 20: /* funcdeclaration: FUNC ID LPAR parameters RPAR funcbody  */
#line 103 "gocompiler.y"
                                                                        {sprintf(buf,"%s",(yyvsp[-4].id));ifh=insert_node(func_head,(yyvsp[-2].n),NULL,buf,0,linha,yacc_col);ifh->next=(yyvsp[0].n);(yyval.n)=insert_node(func_decl,ifh,NULL,NULL,0,linha,yacc_col);}
#line 1661 "y.tab.c"
    break;

  case 21: /* funcdeclaration: FUNC ID LPAR RPAR funcbody  */
#line 104 "gocompiler.y"
                                                                        {sprintf(buf,"%s",(yyvsp[-3].id));ifh=insert_node(func_head,NULL,NULL,buf,0,linha,yacc_col);ifh->next=(yyvsp[0].n);(yyval.n)=insert_node(func_decl,ifh,NULL,NULL,0,linha,yacc_col);}
#line 1667 "y.tab.c"
    break;

  case 22: /* parameters: ID type parameters2  */
#line 107 "gocompiler.y"
                                                                                            {sprintf(buf,"%s\n%s",(yyvsp[-1].id),(yyvsp[-2].id));(yyval.n)=insert_node(func_param,NULL,(yyvsp[0].n),buf,1,linha,yacc_col);}
#line 1673 "y.tab.c"
    break;

  case 23: /* parameters2: parameters2 COMMA ID type  */
#line 109 "gocompiler.y"
                                                                                            {sprintf(buf,"%s\n%s",(yyvsp[0].id),(yyvsp[-1].id));(yyval.n)=insert_node(func_param,NULL,(yyvsp[-3].n),buf,0,linha,yacc_col);}
#line 1679 "y.tab.c"
    break;

  case 24: /* parameters2: %empty  */
#line 110 "gocompiler.y"
                                                                                            {(yyval.n)=NULL;}
#line 1685 "y.tab.c"
    break;

  case 25: /* funcbody: LBRACE varsandstatements RBRACE  */
#line 114 "gocompiler.y"
                                                                                            {(yyval.n)=insert_node(funcbody,(yyvsp[-1].n),NULL,NULL,0,linha,yacc_col);}
#line 1691 "y.tab.c"
    break;

  case 26: /* varsandstatements: varsandstatements vardeclaration SEMICOLON  */
#line 116 "gocompiler.y"
                                                                                            {(yyval.n)=insert_node(varsandstatements,(yyvsp[-1].n),(yyvsp[-2].n),NULL,0,linha,yacc_col);}
#line 1697 "y.tab.c"
    break;

  case 27: /* varsandstatements: varsandstatements statement SEMICOLON  */
#line 117 "gocompiler.y"
                                                                                            {(yyval.n)=insert_node(varsandstatements,(yyvsp[-1].n),(yyvsp[-2].n),NULL,0,linha,yacc_col);}
#line 1703 "y.tab.c"
    break;

  case 28: /* varsandstatements: varsandstatements SEMICOLON  */
#line 118 "gocompiler.y"
                                                                                            {(yyval.n)=(yyvsp[-1].n);}
#line 1709 "y.tab.c"
    break;

  case 29: /* varsandstatements: %empty  */
#line 119 "gocompiler.y"
                                                                                            {(yyval.n)=NULL;}
#line 1715 "y.tab.c"
    break;

  case 30: /* statement: ID ASSIGN expr  */
#line 122 "gocompiler.y"
                                                                                            {no_aux=insert_node(assi,NULL,NULL,(yyvsp[-2].id),0,linha,yacc_col);no_aux->t->identificador=(char *)malloc(10*sizeof(char));strcpy(no_aux->t->identificador,"Id(");no_aux->t->flag = 1;no_aux->next=(yyvsp[0].n);(yyval.n)=insert_node(assig,no_aux,NULL,"Assign",0,linha,(yylsp[-1]).first_column+1);}
#line 1721 "y.tab.c"
    break;

  case 31: /* statement: LBRACE statement1 RBRACE  */
#line 123 "gocompiler.y"
                                                                                            {if((yyvsp[-1].n)==NULL){(yyval.n)=NULL;}else if((yyvsp[-1].n)->next!=NULL){(yyval.n)=insert_node(block,(yyvsp[-1].n),NULL,"Block",0,linha,yacc_col);}else{(yyval.n)=(yyvsp[-1].n);}}
#line 1727 "y.tab.c"
    break;

  case 32: /* statement: IF expr LBRACE statement1 RBRACE ELSE LBRACE statement1 RBRACE  */
#line 124 "gocompiler.y"
                                                                                            {ifh=(yyvsp[-7].n);ifh->next=insert_node(block,(yyvsp[-5].n),NULL,"Block",0,linha,yacc_col);if((yyvsp[-1].n)!=NULL){if(strcmp((yyvsp[-1].n)->t->symbol,"Block")==0){ifh->next->next=(yyvsp[-1].n);}else{ifh->next->next= insert_node(block,(yyvsp[-1].n),NULL,"Block",0,linha,yacc_col);}}else{ifh->next->next= insert_node(block,(yyvsp[-1].n),NULL,"Block",0,linha,yacc_col);}(yyval.n)=insert_node(block,ifh,NULL,"If",0,linha,yacc_col);}
#line 1733 "y.tab.c"
    break;

  case 33: /* statement: IF expr LBRACE statement1 RBRACE  */
#line 125 "gocompiler.y"
                                                                                            {ifh=(yyvsp[-3].n);ifh->next=insert_node(block,(yyvsp[-1].n),NULL,"Block",0,linha,yacc_col);ifh->next->next=
        insert_node(block,NULL,NULL,"Block",0,linha,yacc_col);(yyval.n)=insert_node(block,ifh,NULL,"If",0,linha,yacc_col);}
#line 1740 "y.tab.c"
    break;

  case 34: /* statement: FOR expr LBRACE statement1 RBRACE  */
#line 127 "gocompiler.y"
                                                                                            {if((yyvsp[-1].n)==NULL){ifh=insert_node(block,NULL,NULL,"Block",0,linha,yacc_col);(yyvsp[-3].n)->next=ifh;}else{if(strcmp((yyvsp[-1].n)->t->symbol,"Block")==0){(yyvsp[-3].n)->next=(yyvsp[-1].n);}else{ifh=insert_node(block,(yyvsp[-1].n),NULL,"Block",0,linha,yacc_col); (yyvsp[-3].n)->next=ifh;}}(yyval.n)=insert_node(block,(yyvsp[-3].n),NULL,"For",0,linha,yacc_col);}
#line 1746 "y.tab.c"
    break;

  case 35: /* statement: FOR LBRACE statement1 RBRACE  */
#line 128 "gocompiler.y"
                                                                                            {if((yyvsp[-1].n)!=NULL){if(strcmp((yyvsp[-1].n)->t->symbol,"Block")==0){no_aux=(yyvsp[-1].n);}else {no_aux=insert_node(block,(yyvsp[-1].n),NULL,"Block",0,linha,yacc_col);}}else{no_aux=insert_node(block,NULL,NULL,"Block",0,linha,yacc_col);}(yyval.n)=insert_node(block,no_aux,NULL,"For",0,linha,yacc_col);}
#line 1752 "y.tab.c"
    break;

  case 36: /* statement: RETURN expr  */
#line 129 "gocompiler.y"
                                                                                            {(yyval.n)=insert_node(Ret,(yyvsp[0].n),NULL,"Return",0,linha,yacc_col);}
#line 1758 "y.tab.c"
    break;

  case 37: /* statement: RETURN  */
#line 130 "gocompiler.y"
                                                                                            {(yyval.n)=insert_node(Ret,NULL,NULL,"Return",0,linha,yacc_col);}
#line 1764 "y.tab.c"
    break;

  case 38: /* statement: funcinvocation  */
#line 131 "gocompiler.y"
                                                                                            {(yyval.n)=insert_node(funcinv,(yyvsp[0].n),NULL,"Call",0,linha,yacc_col);}
#line 1770 "y.tab.c"
    break;

  case 39: /* statement: parseargs  */
#line 132 "gocompiler.y"
                                                                                            {(yyval.n)=insert_node(parsgs,(yyvsp[0].n),NULL,"ParseArgs",0,(yylsp[0]).first_line,(yyvsp[0].n)->t->column);}
#line 1776 "y.tab.c"
    break;

  case 40: /* statement: PRINT LPAR expr RPAR  */
#line 133 "gocompiler.y"
                                                                                            {(yyval.n)=insert_node(statement,(yyvsp[-1].n),NULL,"Print",0,linha,yacc_col);}
#line 1782 "y.tab.c"
    break;

  case 41: /* statement: PRINT LPAR STRLIT RPAR  */
#line 134 "gocompiler.y"
                                                                                            {sprintf(buf,"StrLit(%s)",(yyvsp[-1].id));ifh=insert_node(expression,NULL,NULL,buf,0,linha,yacc_col);(yyval.n)=insert_node(statement,ifh,NULL,"Print",0,linha,yacc_col);}
#line 1788 "y.tab.c"
    break;

  case 42: /* statement: error  */
#line 135 "gocompiler.y"
                                                                                            {;}
#line 1794 "y.tab.c"
    break;

  case 43: /* statement1: statement SEMICOLON statement1  */
#line 138 "gocompiler.y"
                                                                                            {if((yyvsp[-2].n)==NULL){(yyval.n)=(yyvsp[0].n);}else if((yyvsp[0].n)!=NULL){(yyvsp[-2].n)->next=(yyvsp[0].n);(yyval.n)=(yyvsp[-2].n);}else{(yyval.n)=(yyvsp[-2].n);}}
#line 1800 "y.tab.c"
    break;

  case 44: /* statement1: %empty  */
#line 139 "gocompiler.y"
                                                                                            {(yyval.n)=NULL;}
#line 1806 "y.tab.c"
    break;

  case 45: /* parseargs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ expr RSQ RPAR  */
#line 142 "gocompiler.y"
                                                                                            {no_aux = insert_node(parseargs,(yyvsp[-2].n),NULL,(yyvsp[-10].id),0,linha,(yylsp[-6]).first_column+1);no_aux->t->identificador=(char *)malloc(10*sizeof(char));strcpy(no_aux->t->identificador,"Id(");no_aux->t->flag = 1;(yyval.n) = no_aux;}
#line 1812 "y.tab.c"
    break;

  case 46: /* parseargs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ error RSQ RPAR  */
#line 143 "gocompiler.y"
                                                                                            {;}
#line 1818 "y.tab.c"
    break;

  case 47: /* funcinvocation: ID LPAR expr funcinvocation1 RPAR  */
#line 146 "gocompiler.y"
                                                                                            {(yyvsp[-2].n)->next=(yyvsp[-1].n);no_aux =  insert_node(funcinvocation,(yyvsp[-2].n),NULL,(yyvsp[-4].id),0,linha,yacc_col);no_aux->t->identificador=(char *)malloc(3*sizeof(char));strcpy(no_aux->t->identificador,"Id(");no_aux->t->flag = 1; (yyval.n) = no_aux;}
#line 1824 "y.tab.c"
    break;

  case 48: /* funcinvocation: ID LPAR error funcinvocation1 RPAR  */
#line 147 "gocompiler.y"
                                                                                            {;}
#line 1830 "y.tab.c"
    break;

  case 49: /* funcinvocation: ID LPAR RPAR  */
#line 148 "gocompiler.y"
                                                                                            {no_aux = insert_node(funcinvocation,NULL,NULL,(yyvsp[-2].id),0,linha,yacc_col);no_aux->t->identificador=(char *)malloc(10*sizeof(char));strcpy(no_aux->t->identificador,"Id(");no_aux->t->flag = 1; (yyval.n) = no_aux;}
#line 1836 "y.tab.c"
    break;

  case 50: /* funcinvocation1: funcinvocation1 COMMA expr  */
#line 151 "gocompiler.y"
                                                    {if((yyvsp[-2].n)!=NULL){no_aux=(yyvsp[-2].n);while(no_aux->next!=NULL){no_aux=no_aux->next;}no_aux->next=(yyvsp[0].n);(yyval.n)=(yyvsp[-2].n);}else{(yyval.n)=(yyvsp[0].n);}}
#line 1842 "y.tab.c"
    break;

  case 51: /* funcinvocation1: funcinvocation1 COMMA error  */
#line 152 "gocompiler.y"
                                                                                            {;}
#line 1848 "y.tab.c"
    break;

  case 52: /* funcinvocation1: %empty  */
#line 153 "gocompiler.y"
                                                                                            {(yyval.n)=NULL;}
#line 1854 "y.tab.c"
    break;

  case 53: /* expr: INTLIT  */
#line 156 "gocompiler.y"
                                                                                {no_aux = insert_node(factor,NULL,NULL,(yyvsp[0].id),0,(yylsp[0]).first_line,(yylsp[0]).first_column+1);no_aux->t->identificador=(char *)malloc(10*sizeof(char));strcpy(no_aux->t->identificador,"IntLit(");no_aux->t->type=(char *)malloc(10*sizeof(char));strcpy(no_aux->t->type,"int");no_aux->t->flag = 1;(yyval.n) = no_aux;}
#line 1860 "y.tab.c"
    break;

  case 54: /* expr: REALLIT  */
#line 157 "gocompiler.y"
                                                                                {no_aux = insert_node(factor,NULL,NULL,(yyvsp[0].id),0,(yylsp[0]).first_line,(yylsp[0]).first_column+1);no_aux->t->identificador=(char *)malloc(10*sizeof(char));strcpy(no_aux->t->identificador,"RealLit(");no_aux->t->type=(char *)malloc(10*sizeof(char));strcpy(no_aux->t->type,"float32");no_aux->t->flag = 1;no_aux->t->flag = 1;(yyval.n) = no_aux;}
#line 1866 "y.tab.c"
    break;

  case 55: /* expr: ID  */
#line 158 "gocompiler.y"
                                                                                {no_aux = insert_node(factor1,NULL,NULL,(yyvsp[0].id),0,(yylsp[0]).first_line,(yylsp[0]).first_column+1);no_aux->t->identificador=(char *)malloc(10*sizeof(char));strcpy(no_aux->t->identificador,"Id(");no_aux->t->flag = 1;(yyval.n) = no_aux;}
#line 1872 "y.tab.c"
    break;

  case 56: /* expr: funcinvocation  */
#line 159 "gocompiler.y"
                                                                                {(yyval.n)=insert_node(funcinv,(yyvsp[0].n),NULL,"Call",0,linha,yacc_col);}
#line 1878 "y.tab.c"
    break;

  case 57: /* expr: MINUS expr  */
#line 160 "gocompiler.y"
                                                                                {(yyval.n)=insert_node(expression,(yyvsp[0].n),NULL,"Minus",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1884 "y.tab.c"
    break;

  case 58: /* expr: PLUS expr  */
#line 161 "gocompiler.y"
                                                                                {(yyval.n)=insert_node(expression,(yyvsp[0].n),NULL,"Plus",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1890 "y.tab.c"
    break;

  case 59: /* expr: NOT expr  */
#line 162 "gocompiler.y"
                                                                                {(yyval.n)=insert_node(expression,(yyvsp[0].n),NULL,"Not",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1896 "y.tab.c"
    break;

  case 60: /* expr: expr PLUS expr  */
#line 163 "gocompiler.y"
                                                                                {(yyvsp[-2].n)->next=(yyvsp[0].n); (yyval.n)=insert_node(expression,(yyvsp[-2].n),NULL,"Add",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1902 "y.tab.c"
    break;

  case 61: /* expr: expr MINUS expr  */
#line 164 "gocompiler.y"
                                                                                {(yyvsp[-2].n)->next=(yyvsp[0].n); (yyval.n)=insert_node(expression,(yyvsp[-2].n),NULL,"Sub",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1908 "y.tab.c"
    break;

  case 62: /* expr: expr DIV expr  */
#line 165 "gocompiler.y"
                                                                                {(yyvsp[-2].n)->next=(yyvsp[0].n); (yyval.n)=insert_node(expression,(yyvsp[-2].n),NULL,"Div",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1914 "y.tab.c"
    break;

  case 63: /* expr: expr STAR expr  */
#line 166 "gocompiler.y"
                                                                                {(yyvsp[-2].n)->next=(yyvsp[0].n); (yyval.n)=insert_node(expression,(yyvsp[-2].n),NULL,"Mul",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1920 "y.tab.c"
    break;

  case 64: /* expr: expr MOD expr  */
#line 167 "gocompiler.y"
                                                                                {(yyvsp[-2].n)->next=(yyvsp[0].n); (yyval.n)=insert_node(expression,(yyvsp[-2].n),NULL,"Mod",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1926 "y.tab.c"
    break;

  case 65: /* expr: expr LT expr  */
#line 168 "gocompiler.y"
                                                                                {(yyvsp[-2].n)->next=(yyvsp[0].n); (yyval.n)=insert_node(expression,(yyvsp[-2].n),NULL,"Lt",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1932 "y.tab.c"
    break;

  case 66: /* expr: expr GT expr  */
#line 169 "gocompiler.y"
                                                                                {(yyvsp[-2].n)->next=(yyvsp[0].n); (yyval.n)=insert_node(expression,(yyvsp[-2].n),NULL,"Gt",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1938 "y.tab.c"
    break;

  case 67: /* expr: expr EQ expr  */
#line 170 "gocompiler.y"
                                                                                {(yyvsp[-2].n)->next=(yyvsp[0].n); (yyval.n)=insert_node(expression,(yyvsp[-2].n),NULL,"Eq",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1944 "y.tab.c"
    break;

  case 68: /* expr: expr NE expr  */
#line 171 "gocompiler.y"
                                                                                {(yyvsp[-2].n)->next=(yyvsp[0].n); (yyval.n)=insert_node(expression,(yyvsp[-2].n),NULL,"Ne",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1950 "y.tab.c"
    break;

  case 69: /* expr: expr LE expr  */
#line 172 "gocompiler.y"
                                                                                {(yyvsp[-2].n)->next=(yyvsp[0].n); (yyval.n)=insert_node(expression,(yyvsp[-2].n),NULL,"Le",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1956 "y.tab.c"
    break;

  case 70: /* expr: expr GE expr  */
#line 173 "gocompiler.y"
                                                                                {(yyvsp[-2].n)->next=(yyvsp[0].n); (yyval.n)=insert_node(expression,(yyvsp[-2].n),NULL,"Ge",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1962 "y.tab.c"
    break;

  case 71: /* expr: expr AND expr  */
#line 174 "gocompiler.y"
                                                                                {(yyvsp[-2].n)->next=(yyvsp[0].n); (yyval.n)=insert_node(expression,(yyvsp[-2].n),NULL,"And",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1968 "y.tab.c"
    break;

  case 72: /* expr: expr OR expr  */
#line 175 "gocompiler.y"
                                                                                {(yyvsp[-2].n)->next=(yyvsp[0].n); (yyval.n)=insert_node(expression,(yyvsp[-2].n),NULL,"Or",0,(yylsp[-1]).first_line,(yylsp[-1]).first_column+1);}
#line 1974 "y.tab.c"
    break;

  case 73: /* expr: LPAR expr RPAR  */
#line 176 "gocompiler.y"
                                                                                {(yyval.n)=(yyvsp[-1].n);}
#line 1980 "y.tab.c"
    break;

  case 74: /* expr: LPAR error RPAR  */
#line 177 "gocompiler.y"
                                                                                {;}
#line 1986 "y.tab.c"
    break;


#line 1990 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 180 "gocompiler.y"

   
void yyerror (char *s) {
    if(first!=1){printf("\n");}
    printf("Line %d, column %d: %s: %s", linha,yacc_col, s, yytext);
    error = 1;
    first++;
}

    /*Para compilar: flex gocompiler.l && yacc -d gocompiler.y && clang lex.yy.c y.tab.c functions.c*/


//( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)( ͡° ͜ʖ ͡°)
