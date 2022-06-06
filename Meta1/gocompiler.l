/*Trabalho realizado por Ricardo Simões 2019231869 e Miguel Pedroso 2019218176*/

newline			\r\n|\r|\n
ID              ([a-z]|[A-Z]|"_")([0-9]|[a-z]|[A-Z]|"_")*
DECIMAL         0|[1-9][0-9]+?
OCTAL           0[0-7]+
HEXADECIMAL     (0x|0X)([0-9]|[A-F]|[a-f])+



REAL    [0-9]*"."[0-9]+(("e"|"E")("+"|"-")?[0-9]+)?|[0-9]+"."[0-9]*(("e"|"E")("+"|"-")?[0-9]+)?|[0-9]+("e"|"E")("+"|"-")?[0-9]+

    

%X COMMENT ESCAPE STRING

%{
  #include <stdio.h>
  #include <string.h>

  int debug = 0;
  int linha = 1;
  int coluna = 1;
  int last = 0;
  int li = 1;
  int ci = 1;
  
  void printer(char* text, int las){
    if(debug == 1){
      printf("%s\n",text);
    }
    last = las;
    coluna += yyleng;
  }
%}

%%

";"  			{printer("SEMICOLON", 0);}
","  			{printer("COMMA", 0);}
"_"  			{printer("BLANKID", 0);}
"="  			{printer("ASSIGN", 0);}
"*"  			{printer("STAR", 0);}
"/"  			{printer("DIV", 0);}
"-"  			{printer("MINUS", 0);}
"+"  			{printer("PLUS", 0);}
"=="  			{printer("EQ", 0);}
">="  			{printer("GE", 0);}
">"  			{printer("GT", 0);}
"{"  			{printer("LBRACE", 0);}
"<="  			{printer("LE", 0);}
"("  			{printer("LPAR", 0);}
"["  			{printer("LSQ", 0);}
"<"  			{printer("LT", 0);}
"%"  			{printer("MOD", 0);}
"!="  			{printer("NE", 0);}
"!"  			{printer("NOT", 0);}
"&&"  			{printer("AND", 0);}
"||"  			{printer("OR", 0);}
"}"  			{printer("RBRACE", 1);}
")"  			{printer("RPAR", 1);}
"]"  			{printer("RSQ", 1);}
package  		{printer("PACKAGE", 0);}
return  		{printer("RETURN", 1);}
else  			{printer("ELSE", 0);}
for  			{printer("FOR", 0);}
if  			{printer("IF", 0);}
var 			{printer("VAR", 0);}
int  			{printer("INT", 0);}
float32  		{printer("FLOAT32", 0);}
bool  			{printer("BOOL", 0);}
string  		{printer("STRING", 0);}
fmt.Println  	{printer("PRINT", 0);}
strconv.Atoi	{printer("PARSEINT", 0);}
func  			{printer("FUNC", 0);}
os.Args  		{printer("CMDARGS", 0);}


break|default|interface|select|case|defer|go|map|struct|chan|goto|switch|const|fallthrough|range|type|continue|import|"++"|"--"  {if(debug == 1){printf("RESERVED(%s)\n", yytext);} coluna += yyleng; last = 0;}



{DECIMAL}                {if(debug == 1){printf("INTLIT(%s)\n", yytext);}coluna += yyleng; last = 1;}    //INTLIT-->DECIMAL
{HEXADECIMAL}            {if(debug == 1){printf("INTLIT(%s)\n", yytext);}coluna += yyleng; last = 1;}    //INTLIT-->hex
{OCTAL}                  {if(debug == 1){printf("INTLIT(%s)\n", yytext);}coluna += yyleng; last = 1;}    //INTLIT-->octal
{REAL}                   {if(debug == 1){printf("REALLIT(%s)\n", yytext);}coluna += yyleng; last = 1;}    //REALIT
{ID}                     {if(debug == 1){printf("ID(%s)\n", yytext);}coluna += yyleng; last = 1;}    //ID


["]                     {ci = coluna;coluna++;yymore();last=1;BEGIN STRING;}
<STRING>["]             {if(last==1&&debug==1){printf("STRLIT(%s)\n",yytext);}last = 1;coluna++;BEGIN 0;}
<STRING>\n              {printf("Line %d, column %d: unterminated string literal\n",linha,ci);coluna = 1;last = 0;linha+=1;BEGIN 0;}
<STRING><<EOF>>         {if(last==1)printf("Line %d, column %d: unterminated string literal\n",linha,ci);coluna ++;yyterminate();}
<STRING>\\              {BEGIN ESCAPE;yymore();coluna++;}
<ESCAPE>\n              {printf("Line %d, column %d: invalid escape sequence (\\)\n",linha,coluna-1);printf("Line %d, column %d: unterminated string literal\n",linha,ci);coluna = 1;linha++;last = 0;BEGIN 0;}
<ESCAPE>[^nfrt"\\]|" "  {printf("Line %d, column %d: invalid escape sequence (\\%c)\n",linha,coluna-1,yytext[yyleng-1]);coluna ++;BEGIN STRING;last = 0;}
<ESCAPE>.               {coluna++;yymore();BEGIN STRING;}
<ESCAPE><<EOF>>         {printf("Line %d, column %d: invalid escape sequence (\\)\n",linha,coluna-1);printf("Line %d, column %d: unterminated string literal\n",linha,ci);coluna = 1;linha++;last = 0;yyterminate();}
<STRING>.               {coluna++;yymore();}


[ \t]* 				{coluna += yyleng;}
{newline}	  		{linha++; if(last == 1){printer("SEMICOLON", 0);} coluna = 1;}
("//".*) 			;
"/*"            	{BEGIN COMMENT; li = linha; ci = coluna; coluna += yyleng;}
<COMMENT>"*/" 		{BEGIN 0; coluna += 2; last = 0;}
<COMMENT><<EOF>>  	{printf("Line %d, column %d: unterminated comment\n", li, ci); BEGIN 0;}
<COMMENT>{newline}  {linha++; coluna = 1;}
<COMMENT>.    		{coluna += yyleng;}


0[0-7]*(8|9)[0-9]* 	{printf("Line %d, column %d: invalid octal constant (%s)\n", linha, coluna, yytext); coluna += yyleng;}
. 				    {printf("Line %d, column %d: illegal character (%s)\n", linha, coluna, yytext); coluna += yyleng;}


%%
int main(int argc, char *argv[]){
  if(argc > 1){
    if(strcmp(argv[1],"-l") == 0){
      debug = 1;
    } 
  }
  yylex();
  return 0;
}

int yywrap(){
  return 1;
}
    

