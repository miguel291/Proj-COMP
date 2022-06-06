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

void print_type(char* str,int depth){
    char delim[] = "\n";
    char *ptr = strtok(str, delim);
    if(ptr!=NULL){
        imprime_pontos(depth);
        printf("%s",ptr);
        ptr = strtok(NULL,delim);
    }
    if(ptr!=NULL){
        printf("\n");
        imprime_pontos(depth);
        printf("%s",ptr);
    }
}

node* insert_node(class cl, node* son, node* head, char* symbol, int flag){
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

void print_node(node* n, int depth){
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
            print_type(n->t->symbol,depth+2);
            depth+=2;
            printf("\n");
            imprime_pontos(depth);
            printf("FuncParams");
            break;
        case(func_param):
            printf("ParamDecl\n");
            print_type(n->t->symbol,depth+2);
            /*imprime_pontos(depth+2);
            printf("%s",n->t->symbol);*/
            break;
        case(funcbody):
            printf("FuncBody");
            /*if(n->first_son==NULL){
                printf("Nao ha filho\n");
            }*/
            //printf("\nEste é o meu filho: %s ..",n->first_son->t->symbol);
            break;
        case(vardec):
            printf("VarDecl\n");
            print_type(n->t->symbol,depth+2);
            break;
        case(varsandstatements):
            break;
        case(statement):
            printf("%s",n->t->symbol);
            break;
        case(expression): case(block): case(blocky):
            printf("%s",n->t->symbol);
            break;
        case(parseargs):
            printf("%s",n->t->symbol);
            depth-=2;
            break;
        case(funcinvocation):
            printf("%s",n->t->symbol);
            depth-=2;
            break;
        case(factor):
            printf("%s",n->t->symbol);
            break;
        
    }
    if(n->first_son!=NULL){
        node *aux = n->first_son;
        for (; aux!=NULL; aux=aux->next) {
            print_node(aux, depth+2);
        }
        free(aux);
    }
}

node* insert_vardec_node(var_aux* va, char* type){
    node* n = (node*)malloc(sizeof(node));
    n->next=NULL;
    token* t = (token*)malloc(sizeof(token));
    sprintf(buf,"%s\nId(%s)",type,va->id);
    t->symbol=(char*)strdup(buf);
    t->cl=vardec;
    n->t=t;
    if(va->next!=NULL){
        //printf("");
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



