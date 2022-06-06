#include "structures.h"

node* insert_node(class cl, node* son, node* head, char* symbol,int flag);
void print_node(node* n, int depth);
void imprime_pontos(int num);
void print_type(char* str,int depth);
var_aux* insert_var_aux(char* id);
node* insert_vardec_node(var_aux* va, char* type);
