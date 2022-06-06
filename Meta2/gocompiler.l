/*Trabalho realizado Miguel Pedroso 2019218176 e Ricardo Simões 2019231869*/

expoente		(e|E)("+"|"-")?[0-9]+
escape			\\[^nrtf"\\\n\r]
newline			\r\n|\r|\n
ID              ([a-z]|[A-Z]|"_")([0-9]|[a-z]|[A-Z]|"_")*
DECIMAL         0|[1-9][0-9]+?
OCTAL           0[0-7]+
HEXADECIMAL    (0x|0X)([0-9]|[A-F]|[a-f])+
REAL            [0-9]*"."[0-9]+(("e"|"E")("+"|"-")?[0-9]+)?|[0-9]+"."[0-9]*(("e"|"E")("+"|"-")?[0-9]+)?|[0-9]+("e"|"E")("+"|"-")?[0-9]+

%X COMMENT ESCAPE STRING1

%{
#include "structures.h"
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
#include "header.h"
#include "functions.h"
//#define yyterminate() return (last!=0)?SEMICOLON : YY_NULL

  int debug = 0;
  int tree = 0;
  int linha = 1;
  int coluna = 1;
  int last = 0;
  int li = 1;
  int ci = 1;
  extern node* myprogram;
  int error = 0;
  int adder = 0;
  int yacc_col = 1;
  extern node* ifh;
  extern node* no_aux;
  extern var_aux* var_au;
  extern char* yytext;
  int line_comment=0;
  
  void printer(char* text, int las){
    if(debug == 1){
      printf("%s\n",text);
    }
   // printf("%s Yacc col: %d Adder: %d\n",text,yacc_col,adder);
    
    coluna += yyleng;
    yacc_col += adder;                                        //  palavra0 palavra1
    adder = yyleng;
    last = las;
    
  }
%}

%%
";"  			{printer("SEMICOLON", 0);return SEMICOLON;}
","  			{printer("COMMA", 0);return COMMA;}
"_"  			{printer("BLANKID", 0);return BLANKID;}
"="  			{printer("ASSIGN", 0);return ASSIGN;}
"*"  			{printer("STAR", 0);return STAR;}
"/"  			{printer("DIV", 0);return DIV;}
"-"  			{printer("MINUS", 0);return MINUS;}
"+"  			{printer("PLUS", 0);return PLUS;}
"=="  			{printer("EQ", 0);return EQ;}
">="  			{printer("GE", 0);return GE;}
">"  			{printer("GT", 0);return GT;}
"{"  			{printer("LBRACE", 0);return LBRACE;}
"<="  			{printer("LE", 0);return LE;}
"("  			{printer("LPAR", 0);return LPAR;}
"["  			{printer("LSQ", 0);return LSQ;}
"<"  			{printer("LT", 0);return LT;}
"%"  			{printer("MOD", 0);return MOD;}
"!="  			{printer("NE", 0);return NE;}
"!"  			{printer("NOT", 0);return NOT;}
"&&"  			{printer("AND", 0);return AND;}
"||"  			{printer("OR", 0);return OR;}
"}"  			{printer("RBRACE", 1); return RBRACE;}
")"  			{printer("RPAR", 1); return RPAR;}
"]"  			{printer("RSQ", 1);return RSQ;}
package  		{printer("PACKAGE", 0);return PACKAGE;}
return  		{printer("RETURN", 1);return RETURN;}
else  			{printer("ELSE", 0);return ELSE;}
for  			{printer("FOR", 0);return FOR;}
if  			{printer("IF", 0);return IF;}
var 			{printer("VAR", 0);return VAR;}
int  			{printer("INT", 0);return INT;}
float32  		{printer("FLOAT32", 0);return FLOAT32;}
bool  			{printer("BOOL", 0); return BOOL;}
string  		{printer("STRING", 0);return STRING;}
fmt.Println  	{printer("PRINT", 0);return PRINT;}
strconv.Atoi	{printer("PARSEINT", 0);return PARSEINT;}
func  			{printer("FUNC", 0);return FUNC;}
os.Args  		{printer("CMDARGS", 0);return CMDARGS;}


break|default|interface|select|case|defer|go|map|struct|chan|goto|switch|const|fallthrough|range|type|continue|import|"++"|"--"  {if(debug == 1){printf("RESERVED(%s)\n", yytext);} yacc_col+=adder; adder=yyleng; coluna += yyleng; last = 0;return STRLIT;}


{DECIMAL}                {if(debug == 1){printf("INTLIT(%s)\n", yytext);}yacc_col+=adder; adder=yyleng;coluna += yyleng; last = 1;yylval.id = strdup(yytext);return INTLIT;}    //INTLIT-->DECIMAL
{HEXADECIMAL}            {if(debug == 1){printf("INTLIT(%s)\n", yytext);}yacc_col+=adder; adder=yyleng;coluna += yyleng; last = 1;yylval.id = strdup(yytext);return INTLIT;}    //INTLIT-->hex
{OCTAL}                  {if(debug == 1){printf("INTLIT(%s)\n", yytext);}yacc_col+=adder; adder=yyleng;coluna += yyleng; last = 1;yylval.id = strdup(yytext);return INTLIT;}    //INTLIT-->octal
{REAL}                   {if(debug == 1){printf("REALLIT(%s)\n", yytext);}yacc_col+=adder; adder=yyleng; coluna += yyleng; last = 1;yylval.id = strdup(yytext);return REALLIT;}    //REALIT
{ID}                     {if(debug == 1){printf("ID(%s)\n", yytext);}yacc_col+=adder; adder=yyleng; coluna += yyleng; last = 1;yylval.id = strdup(yytext);return ID;}    //ID




["]                         {ci = coluna;coluna++;yymore();last=1;BEGIN STRING1;}
<STRING1>["]                {if(last==1&&debug==1){printf("STRLIT(%s)\n",yytext);}yacc_col+=adder; adder=yyleng; coluna += yyleng; last = 1;yylval.id = strdup(yytext);BEGIN 0;return STRLIT;}
<STRING1>\n                 {printf("Line %d, column %d: unterminated string literal\n",linha,ci);coluna = 1;linha+=1;BEGIN 0;}
<STRING1><<EOF>>            {if(last==1)printf("Line %d, column %d: unterminated string literal\n",linha,ci);coluna ++;yyterminate();}
<STRING1>\\                 {BEGIN ESCAPE;yymore();coluna++;}
<ESCAPE>\n                  {printf("Line %d, column %d: invalid escape sequence (\\)\n",linha,coluna-1);printf("Line %d, column %d: unterminated string literal\n",linha,ci);coluna = 1;linha++;last = 0;BEGIN 0;}
<ESCAPE>[^nfrt"\\]|" "      {printf("Line %d, column %d: invalid escape sequence (\\%c)\n",linha,coluna-1,yytext[yyleng-1]);coluna ++;BEGIN STRING1;last = 0;}
<ESCAPE>.                   {coluna++;yymore();BEGIN STRING1;}
<ESCAPE><<EOF>>             {printf("Line %d, column %d: invalid escape sequence (\\)\n",linha,coluna-1);printf("Line %d, column %d: unterminated string literal\n",linha,ci);coluna = 1;linha++;last = 0;yyterminate();}
<STRING1>.                  {coluna++;yymore();}


[ \t]* 				{coluna += yyleng;yacc_col += yyleng;}
{newline}	  		{linha++; if(last == 1){yacc_col-=1; printer("SEMICOLON", 0); yacc_col = 1; coluna = 1; last = 0;return SEMICOLON;} yacc_col = 1; adder = 0; last = 0;coluna = 1;}
("//".*) 			;
"/*"            	{line_comment=linha;BEGIN COMMENT; li = linha; ci = coluna; coluna += yyleng;}
<COMMENT>"*/" 		{BEGIN 0; coluna += 2; if(line_comment!=linha){last = 0;}}
<COMMENT><<EOF>>  	{printf("Line %d, column %d: unterminated comment\n", li, ci); BEGIN 0;}
<COMMENT>{newline}  {linha++;coluna = 1;}
<COMMENT>.    		{coluna += yyleng;}

0[0-7]*(8|9)[0-9]* 	{printf("Line %d, column %d: invalid octal constant (%s)\n", linha, coluna, yytext); coluna += yyleng;}
. 				    {printf("Line %d, column %d: illegal character (%s)\n", linha, coluna, yytext); coluna += yyleng;}


%%

int main(int argc, char *argv[]) {
    //int errors;
    if(argc > 2){
      if(strcmp(argv[1],"-l") == 0 || strcmp(argv[2],"-l") == 0){
        debug = 1;
      }
      if(strcmp(argv[1],"-t") == 0 || strcmp(argv[2],"-t") == 0){
        tree = 1;
      }
    }
    if(argc == 2){
      if(strcmp(argv[1],"-l") == 0){
        debug = 1;
      }
      if(strcmp(argv[1],"-t")  == 0){
        tree = 1;
      }
    }
    yyparse();
    if(tree == 1 && error == 0){print_node(myprogram,0);}printf("\n");
    
    free(myprogram);
    free(no_aux);
    free(ifh);
    free(var_au);
    //printf("FIM!!!!\n");
    return 0;
}
    
int yywrap(){
  return 1;
}
    
