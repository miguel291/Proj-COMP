#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef enum {program,decl_list,func_head,func_param,funcbody,func_decl,vardec,varsandstatements,factor,expression,parseargs,statement,statement1,funcinvocation,block,factor1,parsgs,funcinv,Ret,assi,assig} class;

typedef struct token{
    class cl;
    char* symbol;
    char* identificador;
    char *type;
    int line;
    int column;
    int flag;
}token;

typedef struct node{
    token* t;
    struct node* next;
    struct node* first_son;
}node;

typedef struct var_aux{
    char* id;
    struct var_aux* next;
}var_aux;

#endif



