/* A Bison parser, made by GNU Bison 3.8.2.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/* AST Node Definition */
typedef struct ASTNode {
    char *type;                /* Type of node (e.g., "BINOP", "PRINT") */
    char *value;               /* Specific value (e.g., "+", "exhibit") */
    struct ASTNode **children; /* Array of child nodes */
    int num_children;          /* Number of child nodes */
} ASTNode;

/* Function Prototypes */
void yyerror(const char *s);
int yylex();
ASTNode *create_ast_node(char *type, char *value, int num_children, ASTNode **children);
void print_ast(ASTNode *node, int indent, FILE *file);
void save_ast_to_yaml(ASTNode *root, const char *filename);

ASTNode *ast_root; // Root of the AST

#line 95 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EXHIBIT = 3,                    /* EXHIBIT  */
  YYSYMBOL_BRANCH = 4,                     /* BRANCH  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_INT_TYPE = 8,                   /* INT_TYPE  */
  YYSYMBOL_LOG_TYPE = 9,                   /* LOG_TYPE  */
  YYSYMBOL_VERUM = 10,                     /* VERUM  */
  YYSYMBOL_FALSUM = 11,                    /* FALSUM  */
  YYSYMBOL_LPAREN = 12,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 13,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 14,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 15,                    /* RBRACE  */
  YYSYMBOL_COLON = 16,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 17,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_LT = 20,                        /* LT  */
  YYSYMBOL_GT = 21,                        /* GT  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 23,                      /* PLUS  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_TIMES = 25,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 26,                    /* DIVIDE  */
  YYSYMBOL_BICONDITIONAL = 27,             /* BICONDITIONAL  */
  YYSYMBOL_IMPLICATION = 28,               /* IMPLICATION  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_NOT = 31,                       /* NOT  */
  YYSYMBOL_IDENTIFIER = 32,                /* IDENTIFIER  */
  YYSYMBOL_STRING = 33,                    /* STRING  */
  YYSYMBOL_NUMBER = 34,                    /* NUMBER  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_statement_list = 37,            /* statement_list  */
  YYSYMBOL_statement = 38,                 /* statement  */
  YYSYMBOL_print_statement = 39,           /* print_statement  */
  YYSYMBOL_print_arguments = 40,           /* print_arguments  */
  YYSYMBOL_print_expr_list_opt = 41,       /* print_expr_list_opt  */
  YYSYMBOL_print_expr_list = 42,           /* print_expr_list  */
  YYSYMBOL_declaration_statement = 43,     /* declaration_statement  */
  YYSYMBOL_identifier_decl = 44,           /* identifier_decl  */
  YYSYMBOL_assign_opt = 45,                /* assign_opt  */
  YYSYMBOL_identifier_list = 46,           /* identifier_list  */
  YYSYMBOL_type = 47,                      /* type  */
  YYSYMBOL_assignment_statement = 48,      /* assignment_statement  */
  YYSYMBOL_if_statement = 49,              /* if_statement  */
  YYSYMBOL_else_opt = 50,                  /* else_opt  */
  YYSYMBOL_while_statement = 51,           /* while_statement  */
  YYSYMBOL_assignment_expression = 52,     /* assignment_expression  */
  YYSYMBOL_for_statement = 53,             /* for_statement  */
  YYSYMBOL_block = 54,                     /* block  */
  YYSYMBOL_biconditional = 55,             /* biconditional  */
  YYSYMBOL_implication = 56,               /* implication  */
  YYSYMBOL_disjunction = 57,               /* disjunction  */
  YYSYMBOL_conjunction = 58,               /* conjunction  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_sum = 60,                       /* sum  */
  YYSYMBOL_term = 61,                      /* term  */
  YYSYMBOL_factor = 62,                    /* factor  */
  YYSYMBOL_atom = 63                       /* atom  */
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
typedef yytype_int8 yy_state_t;

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   101

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    48,    48,    55,    58,    70,    71,    72,    73,    74,
      75,    76,    80,    87,   102,   105,   120,   123,   138,   148,
     167,   168,   172,   175,   194,   195,   199,   205,   219,   220,
     224,   234,   245,   258,   265,   272,   278,   285,   291,   298,
     304,   311,   317,   324,   331,   338,   344,   351,   358,   364,
     371,   378,   384,   390,   396,   402,   408,   411,   416,   419,
     422
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
  "\"end of file\"", "error", "\"invalid token\"", "EXHIBIT", "BRANCH",
  "ELSE", "WHILE", "FOR", "INT_TYPE", "LOG_TYPE", "VERUM", "FALSUM",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "COLON", "SEMICOLON", "COMMA",
  "EQ", "LT", "GT", "ASSIGN", "PLUS", "MINUS", "TIMES", "DIVIDE",
  "BICONDITIONAL", "IMPLICATION", "OR", "AND", "NOT", "IDENTIFIER",
  "STRING", "NUMBER", "$accept", "program", "statement_list", "statement",
  "print_statement", "print_arguments", "print_expr_list_opt",
  "print_expr_list", "declaration_statement", "identifier_decl",
  "assign_opt", "identifier_list", "type", "assignment_statement",
  "if_statement", "else_opt", "while_statement", "assignment_expression",
  "for_statement", "block", "biconditional", "implication", "disjunction",
  "conjunction", "expression", "sum", "term", "factor", "atom", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -73,    27,    11,   -73,    20,    25,    51,    52,   -73,    43,
     -73,   -73,   -73,    50,   -73,   -73,   -73,   -10,   -73,    38,
      36,    36,    37,    36,    54,    16,   -73,    55,    61,   -73,
     -73,    36,    36,    36,    36,   -73,   -73,    -5,    47,    48,
      46,    30,    34,    14,   -73,   -73,     3,    57,    64,     2,
      53,   -73,   -73,   -73,    65,    36,   -73,    67,     7,   -73,
     -73,   -73,    72,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    72,    36,    36,    66,   -73,    15,
     -73,   -73,   -73,    82,    47,    48,    46,    30,    34,    34,
      34,    14,    14,   -73,   -73,   -73,    62,     9,    36,    54,
      36,   -73,     6,    72,   -73,    37,    62,   -73,    15,   -73,
     -73,    77,   -73,    72,   -73
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     0,    11,    20,
       4,     5,     6,     0,     7,     8,     9,     0,    10,     0,
       0,     0,     0,     0,    22,     0,    26,    14,     0,    58,
      59,     0,     0,     0,     0,    60,    57,     0,    35,    37,
      39,    41,    45,    48,    51,    55,     0,     0,     0,    21,
       0,    19,    24,    25,     0,     0,    13,     0,     0,    52,
      53,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    18,    16,
      12,    56,     3,    28,    34,    36,    38,    40,    42,    43,
      44,    46,    47,    49,    50,    30,    31,     0,     0,    22,
       0,    15,     0,     0,    27,     0,    21,    23,    16,    33,
      29,     0,    17,     0,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,    10,   -73,   -73,   -73,   -73,   -17,   -73,   -73,
      17,    -6,   -73,   -73,   -73,   -73,   -73,   -22,   -73,   -72,
     -20,    32,    33,    31,    35,   -15,    -9,   -28,   -73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    10,    11,    28,    56,   101,    12,    13,
      24,    51,    54,    14,    15,   104,    16,    17,    18,    83,
      37,    38,    39,    40,    41,    42,    43,    44,    45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      48,    46,    95,    49,    59,    60,    61,    26,    62,     4,
       5,    58,     6,     7,     4,     5,    74,     6,     7,   -31,
      81,   109,    63,     8,    52,    53,   105,     3,     8,    63,
      63,   110,    19,   100,    63,    79,    63,    20,     9,    72,
      73,   114,    63,     9,    93,    94,    29,    30,    31,    67,
      68,    69,    88,    89,    90,    96,    97,    70,    71,    32,
      33,    91,    92,    21,    22,    23,    25,    34,    35,    47,
      36,    27,    50,    55,    57,    64,    66,    65,   106,    75,
     108,    76,    78,   111,    80,    77,    82,   103,    98,    63,
     113,   112,   102,   107,    99,    84,    86,    85,     0,     0,
       0,    87
};

static const yytype_int8 yycheck[] =
{
      22,    21,    74,    23,    32,    33,    34,    17,    13,     3,
       4,    31,     6,     7,     3,     4,    13,     6,     7,    17,
      13,    15,    27,    17,     8,     9,    17,     0,    17,    27,
      27,   103,    12,    18,    27,    55,    27,    12,    32,    25,
      26,   113,    27,    32,    72,    73,    10,    11,    12,    19,
      20,    21,    67,    68,    69,    75,    76,    23,    24,    23,
      24,    70,    71,    12,    12,    22,    16,    31,    32,    32,
      34,    33,    18,    18,    13,    28,    30,    29,    98,    22,
     100,    17,    17,   105,    17,    32,    14,     5,    22,    27,
      13,   108,    82,    99,    77,    63,    65,    64,    -1,    -1,
      -1,    66
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    37,     0,     3,     4,     6,     7,    17,    32,
      38,    39,    43,    44,    48,    49,    51,    52,    53,    12,
      12,    12,    12,    22,    45,    16,    17,    33,    40,    10,
      11,    12,    23,    24,    31,    32,    34,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    55,    32,    52,    55,
      18,    46,     8,     9,    47,    18,    41,    13,    55,    62,
      62,    62,    13,    27,    28,    29,    30,    19,    20,    21,
      23,    24,    25,    26,    13,    22,    17,    32,    17,    55,
      17,    13,    14,    54,    56,    57,    58,    59,    60,    60,
      60,    61,    61,    62,    62,    54,    55,    55,    22,    45,
      18,    42,    37,     5,    50,    17,    55,    46,    55,    15,
      54,    52,    42,    13,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    38,    38,
      38,    38,    39,    40,    41,    41,    42,    42,    43,    44,
      45,    45,    46,    46,    47,    47,    48,    49,    50,    50,
      51,    52,    53,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    59,    59,    60,    60,    60,    61,
      61,    61,    62,    62,    62,    62,    63,    63,    63,    63,
      63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     5,     2,     0,     3,     0,     3,     4,     3,
       0,     2,     0,     4,     1,     1,     2,     6,     0,     2,
       5,     3,     9,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     2,     2,     2,     1,     3,     1,     1,     1,
       1
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statement_list  */
#line 48 "parser.y"
                   {
        ast_root = create_ast_node("PROGRAM", NULL, (yyvsp[0].node)->num_children, (yyvsp[0].node)->children);
        free((yyvsp[0].node));
    }
#line 1222 "parser.tab.c"
    break;

  case 3: /* statement_list: %empty  */
#line 55 "parser.y"
                {
        (yyval.node) = create_ast_node("STATEMENT_LIST", NULL, 0, NULL);
    }
#line 1230 "parser.tab.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 58 "parser.y"
                               {
        ASTNode *list = (yyvsp[-1].node);
        if ((yyvsp[0].node)) {
            list->num_children += 1;
            list->children = realloc(list->children, sizeof(ASTNode *) * list->num_children);
            list->children[list->num_children - 1] = (yyvsp[0].node);
        }
        (yyval.node) = list;
    }
#line 1244 "parser.tab.c"
    break;

  case 11: /* statement: SEMICOLON  */
#line 76 "parser.y"
                { (yyval.node) = NULL; }
#line 1250 "parser.tab.c"
    break;

  case 12: /* print_statement: EXHIBIT LPAREN print_arguments RPAREN SEMICOLON  */
#line 80 "parser.y"
                                                    {
        (yyval.node) = create_ast_node("EXHIBIT", NULL, (yyvsp[-2].node)->num_children, (yyvsp[-2].node)->children);
        free((yyvsp[-2].node));
    }
#line 1259 "parser.tab.c"
    break;

  case 13: /* print_arguments: STRING print_expr_list_opt  */
#line 87 "parser.y"
                               {
        int num_children = 1 + (yyvsp[0].node)->num_children;
        ASTNode **children = malloc(sizeof(ASTNode *) * num_children);
        children[0] = create_ast_node("STRING", (yyvsp[-1].str), 0, NULL);
        for (int i = 0; i < (yyvsp[0].node)->num_children; i++) {
            children[i + 1] = (yyvsp[0].node)->children[i];
        }
        free((yyvsp[0].node)->children);
        free((yyvsp[0].node));
        (yyval.node) = create_ast_node("PRINT_ARGUMENTS", NULL, num_children, children);
        free(children);
    }
#line 1276 "parser.tab.c"
    break;

  case 14: /* print_expr_list_opt: %empty  */
#line 102 "parser.y"
                {
        (yyval.node) = create_ast_node("EXPR_LIST", NULL, 0, NULL);
    }
#line 1284 "parser.tab.c"
    break;

  case 15: /* print_expr_list_opt: COMMA biconditional print_expr_list  */
#line 105 "parser.y"
                                          {
        int num_children = 1 + (yyvsp[0].node)->num_children;
        ASTNode **children = malloc(sizeof(ASTNode *) * num_children);
        children[0] = (yyvsp[-1].node);
        for (int i = 0; i < (yyvsp[0].node)->num_children; i++) {
            children[i + 1] = (yyvsp[0].node)->children[i];
        }
        free((yyvsp[0].node)->children);
        free((yyvsp[0].node));
        (yyval.node) = create_ast_node("EXPR_LIST", NULL, num_children, children);
        free(children);
    }
#line 1301 "parser.tab.c"
    break;

  case 16: /* print_expr_list: %empty  */
#line 120 "parser.y"
                {
        (yyval.node) = create_ast_node("EXPR_LIST", NULL, 0, NULL);
    }
#line 1309 "parser.tab.c"
    break;

  case 17: /* print_expr_list: COMMA biconditional print_expr_list  */
#line 123 "parser.y"
                                          {
        int num_children = 1 + (yyvsp[0].node)->num_children;
        ASTNode **children = malloc(sizeof(ASTNode *) * num_children);
        children[0] = (yyvsp[-1].node);
        for (int i = 0; i < (yyvsp[0].node)->num_children; i++) {
            children[i + 1] = (yyvsp[0].node)->children[i];
        }
        free((yyvsp[0].node)->children);
        free((yyvsp[0].node));
        (yyval.node) = create_ast_node("EXPR_LIST", NULL, num_children, children);
        free(children);
    }
#line 1326 "parser.tab.c"
    break;

  case 18: /* declaration_statement: identifier_decl COLON type SEMICOLON  */
#line 138 "parser.y"
                                         {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = (yyvsp[-3].node);
        children[1] = (yyvsp[-1].node);
        (yyval.node) = create_ast_node("DECLARATION_STATEMENT", NULL, 2, children);
        free(children);
    }
#line 1338 "parser.tab.c"
    break;

  case 19: /* identifier_decl: IDENTIFIER assign_opt identifier_list  */
#line 148 "parser.y"
                                          {
        int total_children = 1 + ((yyvsp[-1].node) ? 1 : 0) + (yyvsp[0].node)->num_children;
        ASTNode **children = malloc(sizeof(ASTNode *) * total_children);
        int idx = 0;
        children[idx++] = create_ast_node("IDENTIFIER", (yyvsp[-2].str), 0, NULL);
        if ((yyvsp[-1].node)) {
            children[idx++] = (yyvsp[-1].node);
        }
        for (int i = 0; i < (yyvsp[0].node)->num_children; i++) {
            children[idx++] = (yyvsp[0].node)->children[i];
        }
        free((yyvsp[0].node)->children);
        free((yyvsp[0].node));
        (yyval.node) = create_ast_node("IDENTIFIER_DECL", NULL, total_children, children);
        free(children);
    }
#line 1359 "parser.tab.c"
    break;

  case 20: /* assign_opt: %empty  */
#line 167 "parser.y"
                { (yyval.node) = NULL; }
#line 1365 "parser.tab.c"
    break;

  case 21: /* assign_opt: ASSIGN biconditional  */
#line 168 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1371 "parser.tab.c"
    break;

  case 22: /* identifier_list: %empty  */
#line 172 "parser.y"
                {
        (yyval.node) = create_ast_node("IDENTIFIER_LIST", NULL, 0, NULL);
    }
#line 1379 "parser.tab.c"
    break;

  case 23: /* identifier_list: COMMA IDENTIFIER assign_opt identifier_list  */
#line 175 "parser.y"
                                                  {
        int total_children = 1 + ((yyvsp[-1].node) ? 1 : 0) + (yyvsp[0].node)->num_children;
        ASTNode **children = malloc(sizeof(ASTNode *) * total_children);
        int idx = 0;
        children[idx++] = create_ast_node("IDENTIFIER", (yyvsp[-2].str), 0, NULL);
        if ((yyvsp[-1].node)) {
            children[idx++] = (yyvsp[-1].node);
        }
        for (int i = 0; i < (yyvsp[0].node)->num_children; i++) {
            children[idx++] = (yyvsp[0].node)->children[i];
        }
        free((yyvsp[0].node)->children);
        free((yyvsp[0].node));
        (yyval.node) = create_ast_node("IDENTIFIER_LIST", NULL, total_children, children);
        free(children);
    }
#line 1400 "parser.tab.c"
    break;

  case 24: /* type: INT_TYPE  */
#line 194 "parser.y"
             { (yyval.node) = create_ast_node("TYPE", "int", 0, NULL); }
#line 1406 "parser.tab.c"
    break;

  case 25: /* type: LOG_TYPE  */
#line 195 "parser.y"
               { (yyval.node) = create_ast_node("TYPE", "log", 0, NULL); }
#line 1412 "parser.tab.c"
    break;

  case 26: /* assignment_statement: assignment_expression SEMICOLON  */
#line 199 "parser.y"
                                    {
    }
#line 1419 "parser.tab.c"
    break;

  case 27: /* if_statement: BRANCH LPAREN biconditional RPAREN block else_opt  */
#line 205 "parser.y"
                                                      {
        int num_children = 2 + ((yyvsp[0].node) ? 1 : 0);
        ASTNode **children = malloc(sizeof(ASTNode *) * num_children);
        children[0] = (yyvsp[-3].node); // Condition
        children[1] = (yyvsp[-1].node); // If Block
        if ((yyvsp[0].node)) {
            children[2] = (yyvsp[0].node); // Else Block
        }
        (yyval.node) = create_ast_node("IF_STATEMENT", NULL, num_children, children);
        free(children);
    }
#line 1435 "parser.tab.c"
    break;

  case 28: /* else_opt: %empty  */
#line 219 "parser.y"
                { (yyval.node) = NULL; }
#line 1441 "parser.tab.c"
    break;

  case 29: /* else_opt: ELSE block  */
#line 220 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1447 "parser.tab.c"
    break;

  case 30: /* while_statement: WHILE LPAREN biconditional RPAREN block  */
#line 224 "parser.y"
                                            {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = (yyvsp[-2].node); // Condition
        children[1] = (yyvsp[0].node); // Body
        (yyval.node) = create_ast_node("WHILE_STATEMENT", NULL, 2, children);
        free(children);
    }
#line 1459 "parser.tab.c"
    break;

  case 31: /* assignment_expression: IDENTIFIER ASSIGN biconditional  */
#line 234 "parser.y"
                                    {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = create_ast_node("IDENTIFIER", (yyvsp[-2].str), 0, NULL);
        children[1] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("ASSIGNMENT_STATEMENT", NULL, 2, children);
        free(children);
    }
#line 1471 "parser.tab.c"
    break;

  case 32: /* for_statement: FOR LPAREN assignment_expression SEMICOLON biconditional SEMICOLON assignment_expression RPAREN block  */
#line 245 "parser.y"
                                                                                                          {
        ASTNode **children = malloc(sizeof(ASTNode *) * 4);
        children[0] = (yyvsp[-6].node); // Initialization
        children[1] = (yyvsp[-4].node); // Condition
        children[2] = (yyvsp[-2].node); // Update
        children[3] = (yyvsp[0].node); // Body
        (yyval.node) = create_ast_node("FOR_STATEMENT", NULL, 4, children);
        free(children);
    }
#line 1485 "parser.tab.c"
    break;

  case 33: /* block: LBRACE statement_list RBRACE  */
#line 258 "parser.y"
                                 {
        (yyval.node) = create_ast_node("BLOCK", NULL, (yyvsp[-1].node)->num_children, (yyvsp[-1].node)->children);
        free((yyvsp[-1].node));
    }
#line 1494 "parser.tab.c"
    break;

  case 34: /* biconditional: biconditional BICONDITIONAL implication  */
#line 265 "parser.y"
                                            {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = (yyvsp[-2].node);
        children[1] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("BINARY_OP", "biconditional", 2, children);
        free(children);
    }
#line 1506 "parser.tab.c"
    break;

  case 35: /* biconditional: implication  */
#line 272 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1514 "parser.tab.c"
    break;

  case 36: /* implication: implication IMPLICATION disjunction  */
#line 278 "parser.y"
                                        {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = (yyvsp[-2].node);
        children[1] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("BINARY_OP", "implication", 2, children);
        free(children);
    }
#line 1526 "parser.tab.c"
    break;

  case 37: /* implication: disjunction  */
#line 285 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1534 "parser.tab.c"
    break;

  case 38: /* disjunction: disjunction OR conjunction  */
#line 291 "parser.y"
                               {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = (yyvsp[-2].node);
        children[1] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("BINARY_OP", "or", 2, children);
        free(children);
    }
#line 1546 "parser.tab.c"
    break;

  case 39: /* disjunction: conjunction  */
#line 298 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1554 "parser.tab.c"
    break;

  case 40: /* conjunction: conjunction AND expression  */
#line 304 "parser.y"
                               {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = (yyvsp[-2].node);
        children[1] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("BINARY_OP", "and", 2, children);
        free(children);
    }
#line 1566 "parser.tab.c"
    break;

  case 41: /* conjunction: expression  */
#line 311 "parser.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1574 "parser.tab.c"
    break;

  case 42: /* expression: expression EQ sum  */
#line 317 "parser.y"
                      {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = (yyvsp[-2].node);
        children[1] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("BINARY_OP", "equal", 2, children);
        free(children);
    }
#line 1586 "parser.tab.c"
    break;

  case 43: /* expression: expression LT sum  */
#line 324 "parser.y"
                        {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = (yyvsp[-2].node);
        children[1] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("BINARY_OP", "lesser", 2, children);
        free(children);
    }
#line 1598 "parser.tab.c"
    break;

  case 44: /* expression: expression GT sum  */
#line 331 "parser.y"
                        {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = (yyvsp[-2].node);
        children[1] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("BINARY_OP", "greater", 2, children);
        free(children);
    }
#line 1610 "parser.tab.c"
    break;

  case 45: /* expression: sum  */
#line 338 "parser.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1618 "parser.tab.c"
    break;

  case 46: /* sum: sum PLUS term  */
#line 344 "parser.y"
                  {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = (yyvsp[-2].node);
        children[1] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("BINARY_OP", "plus", 2, children);
        free(children);
    }
#line 1630 "parser.tab.c"
    break;

  case 47: /* sum: sum MINUS term  */
#line 351 "parser.y"
                     {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = (yyvsp[-2].node);
        children[1] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("BINARY_OP", "minus", 2, children);
        free(children);
    }
#line 1642 "parser.tab.c"
    break;

  case 48: /* sum: term  */
#line 358 "parser.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1650 "parser.tab.c"
    break;

  case 49: /* term: term TIMES factor  */
#line 364 "parser.y"
                      {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = (yyvsp[-2].node);
        children[1] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("BINARY_OP", "mult", 2, children);
        free(children);
    }
#line 1662 "parser.tab.c"
    break;

  case 50: /* term: term DIVIDE factor  */
#line 371 "parser.y"
                         {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = (yyvsp[-2].node);
        children[1] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("BINARY_OP", "div", 2, children);
        free(children);
    }
#line 1674 "parser.tab.c"
    break;

  case 51: /* term: factor  */
#line 378 "parser.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1682 "parser.tab.c"
    break;

  case 52: /* factor: PLUS factor  */
#line 384 "parser.y"
                {
        ASTNode **children = malloc(sizeof(ASTNode *) * 1);
        children[0] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("UNARY_OP", "plus", 1, children);
        free(children);
    }
#line 1693 "parser.tab.c"
    break;

  case 53: /* factor: MINUS factor  */
#line 390 "parser.y"
                   {
        ASTNode **children = malloc(sizeof(ASTNode *) * 1);
        children[0] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("UNARY_OP", "minus", 1, children);
        free(children);
    }
#line 1704 "parser.tab.c"
    break;

  case 54: /* factor: NOT factor  */
#line 396 "parser.y"
                 {
        ASTNode **children = malloc(sizeof(ASTNode *) * 1);
        children[0] = (yyvsp[0].node);
        (yyval.node) = create_ast_node("UNARY_OP", "not", 1, children);
        free(children);
    }
#line 1715 "parser.tab.c"
    break;

  case 55: /* factor: atom  */
#line 402 "parser.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1723 "parser.tab.c"
    break;

  case 56: /* atom: LPAREN biconditional RPAREN  */
#line 408 "parser.y"
                                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1731 "parser.tab.c"
    break;

  case 57: /* atom: NUMBER  */
#line 411 "parser.y"
             {
        char buffer[20];
        sprintf(buffer, "%d", (yyvsp[0].num));
        (yyval.node) = create_ast_node("NUMBER", buffer, 0, NULL);
    }
#line 1741 "parser.tab.c"
    break;

  case 58: /* atom: VERUM  */
#line 416 "parser.y"
            {
        (yyval.node) = create_ast_node("BOOLEAN", "verum", 0, NULL);
    }
#line 1749 "parser.tab.c"
    break;

  case 59: /* atom: FALSUM  */
#line 419 "parser.y"
             {
        (yyval.node) = create_ast_node("BOOLEAN", "falsum", 0, NULL);
    }
#line 1757 "parser.tab.c"
    break;

  case 60: /* atom: IDENTIFIER  */
#line 422 "parser.y"
                 {
        (yyval.node) = create_ast_node("IDENTIFIER", (yyvsp[0].str), 0, NULL);
    }
#line 1765 "parser.tab.c"
    break;


#line 1769 "parser.tab.c"

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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 427 "parser.y"


/* AST Node Functions */
ASTNode *create_ast_node(char *type, char *value, int num_children, ASTNode **children) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = strdup(type);
    node->value = value ? strdup(value) : NULL;
    node->num_children = num_children;
    if (num_children > 0 && children != NULL) {
        node->children = (ASTNode **)malloc(sizeof(ASTNode *) * num_children);
        for (int i = 0; i < num_children; i++) {
            node->children[i] = children[i];
        }
    } else {
        node->children = NULL;
    }
    return node;
}

void print_ast(ASTNode *node, int indent, FILE *file) {
    for (int i = 0; i < indent; ++i) fprintf(file, "  ");
    fprintf(file, "- type: %s\n", node->type);

    if (node->value) {
        for (int i = 0; i < indent + 1; ++i) fprintf(file, "  ");
        fprintf(file, "value: %s\n", node->value);
    }

    if (node->num_children > 0) {
        for (int i = 0; i < indent + 1; ++i) fprintf(file, "  ");
        fprintf(file, "children:\n");
        for (int i = 0; i < node->num_children; ++i) {
            print_ast(node->children[i], indent + 2, file);
        }
    }
}

void save_ast_to_yaml(ASTNode *root, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    fprintf(file, "AST:\n");
    print_ast(root, 1, file);
    fclose(file);
}

/* Error Handling */
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

/* Main Function */
int main(void) {
    if (yyparse() == 0) {
        save_ast_to_yaml(ast_root, "../ast/output.yaml");
        printf("AST written to output.yaml\n");
    }
    return 0;
}
