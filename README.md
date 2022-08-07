# Proj-COMP

Project to the Compilers subject of the Informatics engineering course @University of Coimbra 


To compile: flex gocompiler.l && yacc -d gocompiler.y && clang lex.yy.c y.tab.c functions.c semantics.c
flex gocompiler.l && yacc -d gocompiler.y && clang lex.yy.c y.tab.c functions.c semantics.c symbol_table.c
