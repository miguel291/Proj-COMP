#include "structures.h"
#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char buf[50];

void imprime_pontos(int num){
    int i = 0;
    while(i<num){
        printf(".");
        i++;
    }
}

void print_type(char* str,int depth, int flag){
    char delim[] = "\n";
    char* copy = strdup(str);
    char *ptr = strtok(copy, delim);
    if(ptr!=NULL){
        imprime_pontos(depth);
        if (flag == 1){
            printf("%s",ptr);}
        else{
            printf("Id(%s)",ptr);
        }
        ptr = strtok(NULL,delim);
    }
    if(ptr!=NULL){
        printf("\n");
        imprime_pontos(depth);
        if(flag == 1){
            printf("Id(%s)",ptr);
        }
        else{
            printf("%s",ptr);
        }
    }
    free(copy);
    //if(ptr!=NULL)free(ptr);
}

node* insert_node(class cl, node* son, node* head, char* symbol, int flag, int linha, int coluna){
    node* n = (node*)malloc(sizeof(node));
    node* tmp;
    n->next=NULL;
    n->first_son=son;
    token* t = (token*)malloc(sizeof(token));
    if(symbol!=NULL){
        t->symbol=(char*)strdup(symbol);
    }
    else{
        t->symbol=NULL;
    }

    t->cl=cl;
    t->line = linha;
    t->column = coluna;
    t->type = NULL;
    t->identificador = NULL;
    n->t=t;
    
    if(flag==1&&head!=NULL){
        n->next=head;
        return n;
    }
    if(head==NULL)
            return n;
    
    for(tmp=head; tmp->next; tmp=tmp->next);
    tmp->next=n;
    
    
    return head;
}


void print_node(node* n, int depth, int flag){
    if(n->t->cl!=program && n->t->cl!=decl_list && n->t->cl!=varsandstatements)
        printf("\n");
    if(n->t->cl==decl_list || n->t->cl==varsandstatements){
        depth-=2;
    }
    else{
        imprime_pontos(depth);
    }
    //program,decl_list,func_head,func_param,funcbody,func_decl,vardec,varsandstatements,parseargs,statement
    switch(n->t->cl){
        case(program):
            printf("Program");
            break;
        case(decl_list):
            break;
        case(func_decl):
            printf("FuncDecl");
            break;
        case(func_head):
            printf("FuncHeader\n");
            print_type(n->t->symbol,depth+2,0);
            depth+=2;
            printf("\n");
            imprime_pontos(depth);
            printf("FuncParams");
            break;
        case(func_param):
            printf("ParamDecl\n");
            print_type(n->t->symbol,depth+2,1);
            break;
        case(funcbody):
            printf("FuncBody");
            break;
        case(vardec):
            printf("VarDecl\n");
            print_type(n->t->symbol,depth+2,1);
          /*  if(flag == 1){
                printf(" - %s",n->t->type); //if flag == 1 imprime as anotaçoes dos tipos das variaveis
            }*/
            break;
        case(varsandstatements):
            break;
        case(statement): case(Ret):
            printf("%s",n->t->symbol);
            break;
        case(factor): case(factor1): case(assi): case(assig):
            if(n->t->flag == 1){
                printf("%s",n->t->identificador);
                printf("%s",n->t->symbol);
                printf(")");
            }
            else{
                printf("%s",n->t->symbol);
            }
            if(flag == 1){
                printf(" - %s",n->t->type); //if flag == 1 imprime as anotaçoes dos tipos das variaveis
            }
            break;
        case(expression): case(statement1): case(parsgs): case(funcinv):
            if(n->t->flag == 1){
                printf("%s",n->t->identificador);
                printf("%s",n->t->symbol);
                printf(")");
            }
            else{
                printf("%s",n->t->symbol);
            }
           if(flag == 1 && strcmp(n->t->type,"none")!=0 ){
                printf(" - %s",n->t->type); //if flag == 1 imprime as anotaçoes dos tipos das variaveis
            }
            
            break;

        case(block):
            printf("%s",n->t->symbol);
            break;
        case(parseargs): case(funcinvocation):
            if(n->t->flag == 1){
                printf("%s",n->t->identificador);
                printf("%s",n->t->symbol);
                printf(")");
            }
            else{
                printf("%s",n->t->symbol);
            }
            if(flag == 1){
                printf(" - %s",n->t->type); //if flag == 1 imprime as anotaçoes dos tipos das variaveis
            }
            depth-=2;
            break;
    }

    if(n->first_son!=NULL){
        node *aux = n->first_son;
        for (; aux!=NULL; aux=aux->next) {
            print_node(aux, depth+2,flag);
        }
        free(aux);
    }
}

node* insert_vardec_node(var_aux* va, char* type){
    node* n = (node*)malloc(sizeof(node));
    n->next=NULL;
    token* t = (token*)malloc(sizeof(token));
    sprintf(buf,"%s\n%s",type,va->id);
    t->symbol=(char*)strdup(buf);
    t->cl=vardec;
    n->t=t;
    if(va->next!=NULL){
        n->next=insert_vardec_node(va->next,type);
    }
    else{
        n->next=NULL;
    }
    free(va);
    return n;
}

var_aux* insert_var_aux(char* id){
    var_aux* va = (var_aux*)malloc(sizeof(var_aux));
    va->id=id;
    va->next=NULL;
    return va;
}



