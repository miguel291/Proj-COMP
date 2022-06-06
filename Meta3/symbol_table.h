#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "structures.h"

typedef enum {Int,Float32,Bool,String,none} basic_type;

typedef struct _t0 {
    char* nome;
    struct _t0 *next;
} arg;

typedef struct _t1 {
  char name[32];   //nome da variavel ou funcao
  basic_type type; //tipo da variavel ou retorno da funcao (pode ser none)
  struct _t0 *first_son;  //tem os tipos dos parametros da funçao
  struct _t1 *next;
  int genero;
} table_element;

typedef struct _t2 {
  char name[50];
  struct _t0 *first_param;  //tem os tipos dos parametros da funçao
  struct _t2 *next;
  table_element *first_child;
} table;

table_element *insert_el(table_element **symtab, char *str, basic_type t, arg *param, int genero);
void show_table(table_element *symtab);
table_element *search_el(table_element *symtab, node *n);
int check_return(node* ret, table_element* elemento);
table *globaltab;
#endif
