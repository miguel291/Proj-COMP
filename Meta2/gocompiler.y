/*Trabalho realizado Miguel Pedroso 2019218176 e Ricardo Simões 2019231869*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
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
    
%}

%token NUMBER SEMICOLON COMMA BLANKID ASSIGN STAR DIV EQ GE GT LBRACE LE LPAR LSQ LT MOD NE AND OR RBRACE RPAR RSQ PACKAGE RETURN ELSE FOR IF VAR INT FLOAT32 BOOL STRING PRINT PARSEINT FUNC CMDARGS
%token <id>ID
%token<id>INTLIT
%token<id>REALLIT
%token<id>STRLIT
%token <id>MINUS
%token <id>NOT
%token <id>PLUS

%type<n>varspec
%type<n>vardeclaration
%type<id>type
%type<n>declarations
%type<n>program
%type<n>funcdeclaration
%type<n>parameters2
%type<n>parameters
%type<n>funcbody
%type<n>varsandstatements
%type<n>expr
%type<n>statement
%type<n>parseargs
%type<n>funcinvocation
%type<n>funcinvocation1
%type<n>statement1
%type<va>varspec2

%left OR 
%left AND
%left GE GT LT LE EQ NE
%left PLUS MINUS
%left STAR DIV MOD 
%left UNARY
%left ID

%nonassoc LPAR RPAR 

%union{
    char *id;
    node* n;
    var_aux* va;
}

%%

program:            PACKAGE ID SEMICOLON declarations	                                    {$$=myprogram=insert_node(program,$4,NULL,NULL,0);}
    |               PACKAGE ID declarations                                                 {$$=myprogram=insert_node(program,$3,NULL,NULL,0);}//filhos declarations
	;

declarations:       declarations funcdeclaration SEMICOLON                                  {$$=insert_node(decl_list,$2,$1,NULL,0);}
    |               declarations vardeclaration SEMICOLON			                        {$$=insert_node(decl_list,$2,$1,NULL,0);};//inserir $2 na lista ligada de is_program (os structs is_program têm vlist, flist e *next
    |               declarations funcdeclaration                                            {$$=insert_node(decl_list,$2,$1,NULL,0);}
    |               declarations vardeclaration                                             {$$=insert_node(decl_list,$2,$1,NULL,0);}
    |    	/*epsilon*/                                                                     {$$=NULL;}
    ;

vardeclaration:     VAR varspec                                                             {$$=$2;}         //vardecl
    |               VAR LPAR varspec SEMICOLON RPAR                                         {$$=$3;}         //  type
    ;                                                                                                        //  id(argument)

    varspec:	        ID varspec2 type                                                     {if($2!=NULL){no_aux=insert_vardec_node($2,$3);}sprintf(buf,"%s\nId(%s)",$3,$1);ifh=insert_node(vardec,NULL,NULL,buf,0);if($2!=NULL){ifh->next=no_aux;}$$=ifh;}
	;

varspec2:           varspec2 COMMA ID                                                       {if($1!=NULL){var_au=$1;while(var_au->next!=NULL){var_au=var_au->next;}var_au->next=insert_var_aux($3);$$=$1;}else{$$=insert_var_aux($3);}}
    |             /*epsilon*/                                                               {$$=NULL;}
    ;

type:               INT				                                                        {$$="Int";}
    |               FLOAT32			                                                        {$$="Float32";}
    |               STRING			                                                        {$$="String";}
    |               BOOL			                                                        {$$="Bool";}
    ;

funcdeclaration:    FUNC ID LPAR parameters RPAR type funcbody          {sprintf(buf,"Id(%s)\n%s",$2,$6);ifh=insert_node(func_head,$4,NULL,buf,0);ifh->next=$7;$$=insert_node(func_decl,ifh,NULL,NULL,0);}
    |               FUNC ID LPAR  RPAR type funcbody                    {sprintf(buf,"Id(%s)\n%s",$2,$5);ifh=insert_node(func_head,NULL,NULL,buf,0);ifh->next=$6;$$=insert_node(func_decl,ifh,NULL,NULL,0);}
    |               FUNC ID LPAR parameters RPAR  funcbody              {sprintf(buf,"Id(%s)",$2);ifh=insert_node(func_head,$4,NULL,buf,0);ifh->next=$6;$$=insert_node(func_decl,ifh,NULL,NULL,0);}
    |               FUNC ID LPAR  RPAR  funcbody                        {sprintf(buf,"Id(%s)",$2);ifh=insert_node(func_head,NULL,NULL,buf,0);ifh->next=$5;$$=insert_node(func_decl,ifh,NULL,NULL,0);}
    ;
        
parameters:         ID type parameters2                                                     {sprintf(buf,"%s\nId(%s)",$2,$1);$$=insert_node(func_param,NULL,$3,buf,1);};

parameters2:        parameters2 COMMA ID type                                               {sprintf(buf,"%s\nId(%s)",$4,$3);$$=insert_node(func_param,NULL,$1,buf,0);}
    |               /*epsilon*/                                                             {$$=NULL;}
    ;
    //    node* insert_node(class cl, node* son, node* head, char* symbol,int flag);
    
funcbody:           LBRACE varsandstatements RBRACE                                         {$$=insert_node(funcbody,$2,NULL,NULL,0);} // imprime funcbody; tem 0+ filhos

varsandstatements:  varsandstatements vardeclaration SEMICOLON                              {$$=insert_node(varsandstatements,$2,$1,NULL,0);}//$1->next=insert_node(varsandstatements,$2,NULL,NULL,0);$$=$1;}//nós com filhos vardecl ou statement e irmaos varsandstatements/ nao imprime nada
    |               varsandstatements statement SEMICOLON                                   {$$=insert_node(varsandstatements,$2,$1,NULL,0);}//depth nao aumenta
    |               varsandstatements  SEMICOLON                                            {$$=$1;}//nao imprime \n
    |                                                                                       {$$=NULL;}
    ;

    statement:          ID ASSIGN expr                                                      {sprintf(buf,"Id(%s)",$1);no_aux=insert_node(statement,NULL,NULL,buf,0);no_aux->next=$3;$$=insert_node(statement,no_aux,NULL,"Assign",0);}//Assign ..Id(%s)  ..Expr 
    |               LBRACE statement1 RBRACE                                                {if($2==NULL){$$=NULL;}else if($2->next!=NULL){$$=insert_node(block,$2,NULL,"Block",0);}else{$$=$2;}}
    |               IF expr LBRACE statement1 RBRACE ELSE LBRACE statement1 RBRACE          {ifh=$2;ifh->next=insert_node(block,$4,NULL,"Block",0);if($8!=NULL){if(strcmp($8->t->symbol,"Block")==0){ifh->next->next=$8;}else{ifh->next->next= insert_node(block,$8,NULL,"Block",0);}}else{ifh->next->next= insert_node(block,$8,NULL,"Block",0);}$$=insert_node(block,ifh,NULL,"If",0);}//else é um bloco
    |               IF expr LBRACE statement1 RBRACE                                        {ifh=$2;ifh->next=insert_node(block,$4,NULL,"Block",0);ifh->next->next=
        insert_node(block,NULL,NULL,"Block",0);$$=insert_node(block,ifh,NULL,"If",0);}//else é um bloco
    |               FOR expr LBRACE statement1 RBRACE                                       {if($4==NULL){ifh=insert_node(block,NULL,NULL,"Block",0);$2->next=ifh;}else{if(strcmp($4->t->symbol,"Block")==0){$2->next=$4;}else{ifh=insert_node(block,$4,NULL,"Block",0); $2->next=ifh;}}$$=insert_node(block,$2,NULL,"For",0);}
    |               FOR LBRACE statement1 RBRACE                                            {if($3!=NULL){if(strcmp($3->t->symbol,"Block")==0){no_aux=$3;}else {no_aux=insert_node(block,$3,NULL,"Block",0);}}else{no_aux=insert_node(block,NULL,NULL,"Block",0);}$$=insert_node(block,no_aux,NULL,"For",0);}  //errado?
    |               RETURN expr                                                             {$$=insert_node(statement,$2,NULL,"Return",0);}//tem um filho expr e o symbol é Return
    |               RETURN                                                                  {$$=insert_node(statement,NULL,NULL,"Return",0);}// não tem filhos e o symbol é Return
    |               funcinvocation                                                          {$$=insert_node(statement,$1,NULL,"Call",0);}//call é o symbol e filho é nó funcinvocation
    |               parseargs                                                               {$$=insert_node(statement,$1,NULL,"ParseArgs",0);}//symbol parseargs e tem filho parsearg
    |               PRINT LPAR expr RPAR                                                    {$$=insert_node(statement,$3,NULL,"Print",0);}//filho é o nó expr e symbol é print
    |               PRINT LPAR STRLIT RPAR                                                  {sprintf(buf,"StrLit(%s)",$3);ifh=insert_node(expression,NULL,NULL,buf,0);$$=insert_node(statement,ifh,NULL,"Print",0);}// não tem filhos e o symbol é STRLIT
    |               error                                                                   {;}
    ;

statement1:          statement SEMICOLON statement1                                         {if($1==NULL){$$=$3;}else if($3!=NULL){$1->next=$3;$$=$1;}else{$$=$1;}}//{if($1!=NULL){$1->next=$2;$$=$1;}else{$$=$2;}}  //statement null
    |                 /*epsilon*/                                                           {$$=NULL;}
    ;

parseargs:          ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ expr RSQ RPAR         {sprintf(buf,"Id(%s)",$1);$$=insert_node(parseargs,$9,NULL,buf,0);}//só imprime o id e o filho expr, mas depth-=2
    |               ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ error RSQ RPAR        {;}

    
funcinvocation:     ID LPAR expr funcinvocation1 RPAR                                       {sprintf(buf,"Id(%s)",$1);$3->next=$4;$$=insert_node(funcinvocation,$3,NULL,buf,0);}//symbol id e filhos expr; next de expr é funcinvocatoin1; depth-=2
    |               ID LPAR error funcinvocation1 RPAR                                      {;}
    |               ID LPAR RPAR                                                            {sprintf(buf,"Id(%s)",$1);$$=insert_node(funcinvocation,NULL,NULL,buf,0);}//symbol id e nao tem filhos
    ;

funcinvocation1:    funcinvocation1 COMMA expr      {if($1!=NULL){no_aux=$1;while(no_aux->next!=NULL){no_aux=no_aux->next;}no_aux->next=$3;$$=$1;}else{$$=$3;}}
    |               funcinvocation1 COMMA error                                             {;}
    |                                                                                       {$$=NULL;}
    ;

    // if($1!=NULL){var_au=$1;while(var_au->next!=NULL){var_au=var_au->next;}var_au->next=insert_var_aux($3);$$=$1;}else{$$=insert_var_aux($3);}
    //    node* insert_node(class cl, node* son, node* head, char* symbol,int flag);


expr:   INTLIT                                                                  {sprintf(buf,"IntLit(%s)",$1);$$ = insert_node(factor,NULL,NULL,buf,0);}
 |      REALLIT                                                                 {sprintf(buf,"RealLit(%s)",$1);$$ = insert_node(factor,NULL,NULL,buf,0);}
 |      ID                                                                      {sprintf(buf,"Id(%s)",$1);$$ = insert_node(factor,NULL,NULL,buf,0);}
 |      funcinvocation                                                          {$$=insert_node(statement,$1,NULL,"Call",0);}
 |      MINUS expr     %prec UNARY                                              {$$=insert_node(expression,$2,NULL,"Minus",0);}
 |      PLUS expr     %prec UNARY                                               {$$=insert_node(expression,$2,NULL,"Plus",0);}
 |      NOT expr     %prec UNARY                                                {$$=insert_node(expression,$2,NULL,"Not",0);}
 |      expr PLUS expr                                                          {$1->next=$3; $$=insert_node(expression,$1,NULL,"Add",0);}
 |      expr MINUS expr                                                         {$1->next=$3; $$=insert_node(expression,$1,NULL,"Sub",0);}
 |      expr DIV expr                                                           {$1->next=$3; $$=insert_node(expression,$1,NULL,"Div",0);}
 |      expr STAR expr                                                          {$1->next=$3; $$=insert_node(expression,$1,NULL,"Mul",0);}
 |      expr MOD expr                                                           {$1->next=$3; $$=insert_node(expression,$1,NULL,"Mod",0);}
 |      expr LT expr                                                            {$1->next=$3; $$=insert_node(expression,$1,NULL,"Lt",0);}
 |      expr GT expr                                                            {$1->next=$3; $$=insert_node(expression,$1,NULL,"Gt",0);}
 |      expr EQ expr                                                            {$1->next=$3; $$=insert_node(expression,$1,NULL,"Eq",0);}
 |      expr NE expr                                                            {$1->next=$3; $$=insert_node(expression,$1,NULL,"Ne",0);}
 |      expr LE expr                                                            {$1->next=$3; $$=insert_node(expression,$1,NULL,"Le",0);}
 |      expr GE expr                                                            {$1->next=$3; $$=insert_node(expression,$1,NULL,"Ge",0);}
 |      expr AND expr                                                           {$1->next=$3; $$=insert_node(expression,$1,NULL,"And",0);}
 |      expr OR expr                                                            {$1->next=$3; $$=insert_node(expression,$1,NULL,"Or",0);}
 |      LPAR expr RPAR                                                          {$$=$2;}
 |               LPAR error RPAR                                                {;}
 ;
 
%%
   
void yyerror (char *s) {
    if(first!=1){printf("\n");}
    printf("Line %d, column %d: %s: %s", linha,yacc_col, s, yytext);
    error = 1;
    first++;
}

    /*Para compilar: flex gocompiler.l && yacc -d gocompiler.y && clang lex.yy.c y.tab.c functions.c*/

