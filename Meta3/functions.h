#include "structures.h"

//clang-format off
node* insert_node(class cl, node* son, node* head, char* symbol,int flag,int linha, int coluna);
node* insert_node2_0(class cl, node* son, node* head,char*identificador, char* symbol,int flag,int linha, int coluna);
void print_node(node* n, int depth,int flag);
void imprime_pontos(int num);
void print_type(char* str,int depth,int flag);
var_aux* insert_var_aux(char* id);
node* insert_vardec_node(var_aux* va, char* type);
