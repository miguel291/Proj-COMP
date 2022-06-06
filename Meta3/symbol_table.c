#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

extern table_element *symtab;

// Insere um novo identificador na cauda de uma lista ligada de simbolo
table_element *insert_el(table_element **symtab, char *str, basic_type t, arg *param, int gen) {
  table_element *newSymbol = (table_element *)malloc(sizeof(table_element));
  table_element *aux;
  table_element *previous;

  strcpy(newSymbol->name, str);                                    //gen indica se é uma variavel ou uma função
  newSymbol->type = t;                                             //variavel: {nome} {tipo} (1)
                                                                   //variavel: {nome} {tipo} param(2)
  //printf("Type new table element: %d\n",newSymbol->type);        //função:   {nome} {parametros} {tipo de retorno}(0)

    newSymbol->next = NULL;
    newSymbol->first_son = param;
    newSymbol->genero = gen;
    

  if (*symtab != NULL) {
    for (aux = *symtab; aux; previous = aux, aux = aux->next){
        if (strcmp(aux->name, str) == 0){
            return NULL;
        }
    }
    previous->next = newSymbol; // adiciona ao final da lista
  } else {
    *symtab = newSymbol;
      
  }
  return newSymbol;
}

// {Int,Float32,Bool,String}

void show_table(table_element *symtab) {
  table_element *aux;
  arg* param;
  char *t;
  for (aux = symtab; aux; aux = aux->next){      //por cada simbolo na tabela
        switch(aux->type){
            case(0):
                t = "int";
                break;
            case(1):
                t = "float32";
                break;
            case(2):
                t = "bool";
                break;
            case(3):
                t = "string";
                break;
            case(4):
                t = "none";
        }
      printf("%s\t", aux->name);                                            //imprime o nome do simbolo
      
      if(aux->genero == 2){                                                 // n    int     param
          printf("\t%s\tparam\n",t);
      }
      
      else if(aux->genero == 1){                                                 //se for uma função
          printf("(");
          for(param = aux->first_son; param!=NULL; param = param->next){    //imprime todos os parametros da função
              printf("%s",param->nome);
              if(param->next !=NULL)printf(",");
          }
         printf(")\t%s\n",t);                                            //imprime tipo de retorno da função
        }
      
      else{printf("\t%s\n",t);}                                            //se for uma variavel
    }
}


// Procura um identificador, devolve 0 caso nao exista
table_element *search_el(table_element *symtab, node *n) {
  table_element *aux;

  for (aux = symtab; aux; aux = aux->next)
      if (strcmp(aux->name, n->t->symbol) == 0){
          return aux;
      }
    aux = globaltab->first_child;
 for (; aux; aux = aux->next)
     if (strcmp(aux->name, n->t->symbol) == 0){
         return aux;
        }
      

  return NULL;
}

int check_return(node* ret, table_element* elemento){
  printf("entrei na função de check_return\n");
  if(ret->first_son!=NULL){
    printf("ret->first_son->t->type----->%s, elemento->type---->%d\n",ret->first_son->t->type,elemento->type);

  }

  if(ret->first_son==NULL){
    printf("ret->t->type:::%s, elemento->name:::%d\n",ret->t->type,elemento->type);
  }


    /*
     if(ret->first_son!=NULL){

       if(strcmp(ret->first_son->t->type,elemento->type)==0){

         printf("caso 1\n");
       return 0;
     }

     else if (strcmp(ret->first_son->t->type,elemento->type)!=0){
       printf("caso 2\n");
       return 1;
     }

     }

    if(ret->first_son ==NULL){
       if(strcmp("none",elemento->name)==0){
         printf("caso 3\n");
         return 0;
       }
       else if(strcmp("none",elemento->name)!=0){
         printf("caso 4\n");
         return 1;
       }

    }

    */

     return 1;


}

