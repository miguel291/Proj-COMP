#include "semantics.h"
#include "structures.h"
#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

void lower(char *str){
    *str = tolower(*str);
}

char* getSignal(char *str){
    if(strcmp(str,"Add") == 0)
        return "+";
    else if(strcmp(str,"Sub") == 0)
        return "-";
    else if(strcmp(str,"Div") == 0)
        return "/";
    else if(strcmp(str,"Mul") == 0)
        return "*";
    else if(strcmp(str,"Mod") == 0)
        return "%";
    else if(strcmp(str,"Lt") == 0)
        return "<";
    else if(strcmp(str,"Gt") == 0)
        return ">";
    else if(strcmp(str,"Eq") == 0)
        return "==";
    else if(strcmp(str,"Ne") == 0)
        return "!=";
    else if(strcmp(str,"Le") == 0)
        return "<=";
    else if(strcmp(str,"Ge") == 0)
        return ">=";
    else if(strcmp(str,"And") == 0)
        return "&&";
    else if(strcmp(str,"Or") == 0)
        return "||";
    else if(strcmp(str,"Not") == 0)
        return "!";
    else if(strcmp(str,"Plus") == 0)
        return "+";
    else if(strcmp(str,"Minus") == 0)
            return "-";
    else
        return "";
}

int comparaTipo(node *type, char*str1, char *str2, int flag){
    //printf("Sinal: %s ----> Tipo: operador1 %s  operador2 %s\n",type->t->symbol,str1,str2);
    type->t->type = (char*)malloc(sizeof(char)*5);
    int operando1 = 0; //---->verificador 1
    int operando2 = 0; //---->verificador 2
    if(strcmp(type->t->symbol,"Sub") == 0 ){
        if(strcmp(str1,str2) == 0 || flag == 1){                          //Se os tipos dos operandos forem iguais
            if(strcmp(str1,"int") != 0 && strcmp(str1,"float32") != 0){
                //Se forem iguais, mas não forem do tipo certo
                operando1 = 1;
                operando2 = 1;
            }
        }
        else{
            //Se não forem iguais
            operando1 = 1;
            operando2 = 1;
        }
    }
    else if(strcmp(type->t->symbol,"Minus") == 0 || strcmp(type->t->symbol,"Plus") == 0 ){
            if(strcmp(str1,"int") != 0 && strcmp(str1,"float32") != 0 && strcmp(str1,"string") != 0){
                operando1 = 1;
            }
    }
            
    else if(strcmp(type->t->symbol,"Add") == 0){
        if(strcmp(str1,str2) == 0 || flag == 1){
            if(strcmp(str1,"int") != 0 && strcmp(str1,"float32") != 0 && strcmp(str1,"string") != 0){
                operando1 = 1;
                operando2 = 1;
            }
        }
         else{
            //Se não forem iguais
            operando1 = 1;
            operando2 = 1;
        }

    }
    else if(strcmp(type->t->symbol,"Not") == 0){
        strcpy(type->t->type,"bool");
        if(strcmp(str1,"bool") != 0){
                 operando1 = 1;
            }
    }
            
    else if(strcmp(type->t->symbol,"And") == 0){
        strcpy(type->t->type,"bool");
        if(strcmp(str1,str2) == 0 || flag == 1){
            if(strcmp(str1,"bool") != 0 ){
            }
        }

        else{
            operando1 = 1;
            operando2 = 1;

        }
    }
    else if(strcmp(type->t->symbol,"Or") == 0){
        strcpy(type->t->type,"bool");
        if(strcmp(str1,str2) == 0 || flag == 1){
            if(strcmp(str1,"bool") != 0 ){
                operando1 = 1;
                operando2 = 1;
            }
        }
        else{
            operando1 = 1;
            operando2 = 1;
        }
    }
    else if(strcmp(type->t->symbol,"Ge") == 0 || strcmp(type->t->symbol,"Le") == 0  || strcmp(type->t->symbol,"Gt") == 0 || strcmp(type->t->symbol,"Lt") == 0){
        strcpy(type->t->type,"bool");
        if(strcmp(str1,str2) == 0 || flag == 1){
            if(strcmp(str1,"int") != 0 && strcmp(str1,"float32") != 0 && strcmp(str1,"string") != 0){
                operando1 = 1;
                operando2 = 1;
            }
        }
        else{
            operando1 = 1;
            operando2 = 1;
        }
    }
    else if(strcmp(type->t->symbol,"Mul") == 0 || strcmp(type->t->symbol,"Mod") == 0 || strcmp(type->t->symbol,"Div") == 0 ){
        if(strcmp(str1,str2) == 0 || flag == 1){
            if(strcmp(str1,"int") != 0 && strcmp(str1,"float32") != 0){
                operando1 = 1;
                operando2  = 1;
            }
        }
        else{
            operando1 = 1;
            operando2 = 1;
        }
    }
    else if(strcmp(type->t->symbol,"Eq") == 0 || strcmp(type->t->symbol,"Ne") == 0){
        strcpy(type->t->type,"bool");
        if(strcmp(str1,str2) == 0 || flag == 1){
            if(strcmp(str1,"int") != 0 && strcmp(str1,"float32") != 0 && strcmp(str1,"bool") != 0 && strcmp(str1,"string") != 0){
                operando1 = 1;
                operando2 = 1;
            }
        }
        else{
            operando1 = 1;
            operando2 = 1;
        }
    }
    else if(strcmp(type->t->symbol,"ParseArgs") == 0 ){
        if(strcmp(str1,str2) == 0 || flag == 1){
            if(strcmp(str1,"int") != 0 ){
                printf("Line %d, column %d: Operator strconv.Atoi cannot be applied to types %s, %s\n",type->t->line,type->t->column,str1,str2);
                return 1;
            }
        }
        else{
            printf("Line %d, column %d: Operator strconv.Atoi cannot be applied to types %s, %s\n",type->t->line,type->t->column,str1,str2);
            return 1;
        }
    }
    
    if(operando1 == 1 && operando2 == 1){
        printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",type->t->line,type->t->column,getSignal(type->t->symbol),str1,str2);
        //printf("%s\n",type->t->type);
        if(strcmp(type->t->type,"bool") != 0)
            strcpy(type->t->type,"undef");
        return 1 ;
    }

    else if(operando1 ==1){
        printf("Line %d, column %d: Operator %s cannot be applied to type %s\n",type->t->line,type->t->column,getSignal(type->t->symbol),str1);
        if(strcmp(type->t->type,"bool") != 0)
            strcpy(type->t->type,"undef");
        return 1 ;
    }

    else if(operando2 ==1){
        printf("Line %d, column %d: Operator %s cannot be applied to type %s\n",type->t->line,type->t->column,getSignal(type->t->symbol),str2);
        if(strcmp(type->t->type,"bool") != 0)
            strcpy(type->t->type,"undef");
        return 1 ;
    }
    else{
        type->t->type = (char*)malloc(sizeof(char)*10);
        if(strcmp(type->t->symbol,"Ge") == 0 || strcmp(type->t->symbol,"Le") == 0 || strcmp(type->t->symbol,"Ne") == 0 || strcmp(type->t->symbol,"Gt") == 0 || strcmp(type->t->symbol,"Lt") == 0 || strcmp(type->t->symbol,"Eq") == 0 || strcmp(type->t->symbol,"Not") == 0 || strcmp(type->t->symbol,"And") == 0 || strcmp(type->t->symbol,"Or") == 0){
            strcpy(type->t->type,"bool");
        }
        else{
            strcpy(type->t->type,str1);
        }
        return 0;
        //operador type = type dos operandos
    }
}

table_element* creator(table_element **symtab, char *type, char *name, arg* param,int flag){
    table_element *newel;
    if(type == NULL){
        newel = insert_el(symtab, name, none, param,flag);                  //flag 0 se for uma variavel ou 1 se for função
    }
    else if(strcmp(type,"Int") == 0 || strcmp(type,"int") == 0){
            newel = insert_el(symtab, name, Int, param,flag);
    }
    else if(strcmp(type,"Float32") == 0 || strcmp(type,"float32") == 0){
            newel = insert_el(symtab, name, Float32, param,flag);
    }
    else if(strcmp(type,"Bool") == 0 || strcmp(type,"bool") == 0){
            newel = insert_el(symtab, name, Bool, param,flag);
    }
    else if(strcmp(type,"String") == 0 || strcmp(type,"string") == 0){
            newel = insert_el(symtab, name, String, param,flag);
    }
    else if(strcmp(type,"undef") == 0){
            newel = insert_el(symtab, name, String, param,flag);
    }
    return newel;
}

int check_type(node* n, table *symtab){
    int processado = 0;
    table* auxT = symtab;
    arg *father;
    table_element **ele = &(auxT->first_child);
    int errorcount = 0;
    char delim[] = "\n";
    char buffer[100];
    table_element *newel;
    char *copy;
    node *naux;
    node *naux2;
    arg *arg1;
    if(n->t->symbol!=NULL){
        copy = strdup(n->t->symbol);
    }
    char *ptr1;
    char *ptr2;
    char *ptr3;
    char *ptr4;
    table *newtab;
    switch(n->t->cl){

        case(vardec):
            ptr1 = strtok(copy, delim);                        //type
            ptr2 = strtok(NULL,delim);                         //symbol
            //printf("Type: %s\nSymbol: %s\n",ptr1,ptr2);
            newel = creator(ele, ptr1, ptr2,NULL,0);
            if (newel == NULL) {
                printf("Line %d, column %d: Symbol %s already defined!\n",n->t->line,n->t->column, ptr2);
              return 1;
            }
            lower(ptr1);
            n->t->type = ptr1;                                  //insere o tipo na árvore é criada anotação na tabela de simbolos
            //printf("OLA OLA: %s\n",n->t->type);
            //printf("Tipo:   %s\n",n->t->type);
            return 0;
            break;

        case(func_head):
            ptr1 = strtok(copy, delim);                          //id
            ptr2 = strtok(NULL,delim);                           //tipo de return
            //printf("Type: %s\nSymbol: %s\n",ptr1,ptr2);
            newel = creator(ele, ptr2, "return",NULL,0);        // adicionar à tabela da função: return   type

            father = (arg *)malloc(sizeof(arg));
            father->next=NULL;
                                                        
            if(n->first_son!=NULL){                             //se a função tiver parametros
                node *paramNode = n->first_son;
                copy = strdup(paramNode->t->symbol);
                ptr3 = strtok(copy,delim);                     //tipo do primeiro parametro
                lower(ptr3);
                paramNode->t->type = ptr3;
               // printf("OLA OLA: %s\n",paramNode->t->type);
                father->nome = ptr3;
                ptr4 = strtok(NULL,delim);
                newel = creator(ele, ptr3, ptr4,NULL,2);                //adicionar à tabela da função: id  type    param
                if (newel == NULL) {
                 printf("Line %d, column %d: Symbol %s already defined!\n",n->t->line,n->t->column ,ptr4);
                  return 1;
                }
                for (paramNode = paramNode->next; paramNode!=NULL; paramNode=paramNode->next) {
                    copy = strdup(paramNode->t->symbol);
                    ptr3 = strtok(copy,delim);                                      //tipo \n id
                    ptr4 = strtok(NULL,delim);
                    lower(ptr3);
                    paramNode->t->type = ptr3;
                   // printf("OLA OLA: %s\n",paramNode->t->type);
                    creator(ele, ptr3, ptr4,NULL,2);
                    arg *ar = (arg *)malloc(sizeof(arg));

                    ar->nome=ptr3;
                    
                    arg *aux = father;
                    while(aux->next!=NULL){                                        //acrescentar arg ao fim da fila de argumentos
                        aux = aux->next;
                    }
                    aux->next = ar;
                }
            }
            else{
                father = NULL;                                                    //função nao tem argumentos
            }
            
            ele = &(globaltab->first_child);
            newel = creator(ele, ptr2, ptr1,father,1);   //adicionar à tabela global: nome da função\t (parametros)\t return type
            if (newel == NULL) {
              printf("Line %d, column %d: Symbol %s already defined!\n",n->t->line,n->t->column ,ptr1);
              return 1;
            }
            break;                                       //ptr2 = return type //ptr1 = nome da funçao //father = nó pai com argumento
        
            
            
        case(func_decl):
            newtab = (table*)malloc(sizeof(table));              //criar nova tabela
            while(auxT->next!=NULL){
                auxT = auxT->next;
            }
            auxT->next = newtab;                                  // colocar no fim da lista de tabs
            auxT = auxT->next;

            node* funcHead = n->first_son;                        //Nó do tipo funchead
            copy = strdup(funcHead->t->symbol);

            ptr1 = strtok(copy, delim);
            sprintf(auxT->name,"Function %s",ptr1);               //Nome da função a que pertence a tabela
            father = (arg *)malloc(sizeof(arg));
            father->next=NULL;
            
            if(funcHead->first_son!=NULL){                      //por cada filho parâmetro
                node *paramNode = funcHead->first_son;
                int i = 1;
                for (; paramNode!=NULL; paramNode=paramNode->next,i++) {
                    copy = strdup(paramNode->t->symbol);
                    ptr3 = strtok(copy,delim);                    //ptr3 = tipo do parametro
                    lower(ptr3);
                    
                    if(i == 1){
                        father->nome = ptr3;
                       // printf("Ptr3: %s\n",ptr3);
                    }
                    else{
                        arg *ar = (arg *)malloc(sizeof(arg));
                        ar->nome=ptr3;
                        arg *aux = father;
                        while(aux->next!=NULL){                   //acrescentar arg ao fim da fila
                            aux = aux->next;
                        }
                        aux->next = ar;
                    }
                }
            }
            else{                                               //caso a função nao tenha parametros
                father = NULL;
            }
            auxT->first_param = father;
            break;
        
        case(program): case(decl_list): case(func_param): case(funcbody): case(block):
            break;
            
        case(varsandstatements):
                                                   //create new table
            break;
        case(factor):
            break;
            
        case(expression):
           // printf("Symbol operador: %s\n",n->t->symbol);           //simbolo do operador
            naux = n->first_son;                                 //primeiro operando
           // printf("First operador: %s\n",naux->t->symbol);
            if (naux->t->cl != 8 && naux->t->cl != funcinv && naux->t->cl != expression){                              //se não for um id      && naux->t->cl != 13
                newel = search_el(*ele,naux);        //procurar na tabela
                if (newel != 0){
                    switch(newel->type){                        // apontar na árvore o tipo do simbolo de acordo com o encontrado na tabela
                        case(0):
                            naux->t->type = "int";
                            break;
                        case(1):
                            naux->t->type = "float32";
                            break;
                        case(2):
                            naux->t->type = "bool";
                            break;
                        case(3):
                            naux->t->type = "string";
                            break;
                        case(4):
                            naux->t->type = "none";
                    }
                }
                else{                                                           //simbolo nao encontrado na tabela
                    printf("Cannot find symbol %s\n",naux->t->symbol);          //dá erro
                    naux->t->type = "undef";
                    errorcount++;
                }
            }
            else if (naux->t->cl == 17 || naux->t->cl == expression){
             //   printf("dion1\n");
                check_type(naux,auxT);
             //   printf("find symbol :::: %s %d %d\n",naux->t->symbol,naux->t->line,naux->t->column);          //dá erro
             //   printf("dion11\n");

            }
            
            
             //  printf("Operando1: %s\n",naux->t->symbol);                       //simbolo do primeiro operando
           // printf("Tipo de nó operando2: %d  %s\n",naux->next->t->cl,naux->next->t->symbol);                //classe do primeiro operando

            //   printf("Tipo de nó operando1: %d\n",naux->t->cl);                //classe do primeiro operando

                if(naux->next !=NULL){                          // se o segundo operando existir
                    naux2 =  naux->next;
                    if (naux2->t->cl != 8 && naux2->t->cl != 17 && naux2->t->cl != expression){                      //se nao for um id
                        newel = search_el(*ele,naux2);        //procurar na tabela
                        if (newel != 0){
                            switch(newel->type){
                                case(0):
                                    naux2->t->type = "int";
                                    break;
                                case(1):
                                    naux2->t->type = "float32";
                                    break;
                                case(2):
                                    naux2->t->type = "bool";
                                    break;
                                case(3):
                                    naux2->t->type = "string";
                                    break;
                                case(4):
                                    naux2->t->type = "none";
                            }
                        }
                        else{
                            printf("Cannot find symbol %s\n",naux2->t->symbol);          // segundo operando nao encontrado nas tabelas
                            naux2->t->type = "undef";
                            errorcount++;
                        }
                    
                }
                else if (naux2->t->cl == 17 || naux2->t->cl == expression){
                   //printf("olá sou uma function call %s\n", naux->t->symbol);  //se for function call ??????
                    //printf("dion2\n");
                    check_type(naux2,auxT);
                   // printf("dion23456\n");
                }
                   // printf("Operando2: %s\n",naux2->t->symbol);                       //simbolo do segundo operando
                   // printf("Tipo de nó operando2: %d\n",naux2->t->cl);                //classe do segundo operando
                    errorcount+= comparaTipo(n,naux->t->type,naux2->t->type,0);
                    //printf("MACACO %s\n",n->t->type);
                    
            }
            else{
                //printf("String %s %s\n",n->t->type,naux->t->type);
                errorcount+= comparaTipo(n,naux->t->type,NULL,1);           // expression = -7
            }
            //printf("smooth operator :   %s\n",naux2->t->symbol);
                
            
            
            
            
            
          /*  for(int i = 0; i < 2; i++){                         //NO pai --- first_son -- first_son -> next
                if(naux->first_son !=NULL){
                    naux = naux->first_son;
                    newel = search_el(*ele,n->first_son);
                    
                    if (naux->t->cl != 8){
                        newel = search_el(*ele,naux);        //procurar tabela
                        if (newel != 0){
                            switch(newel->type){
                                case(0):
                                    naux->t->type = "int";
                                    break;
                                case(1):
                                    naux->t->type = "float32";
                                    break;
                                case(2):
                                    naux->t->type = "bool";
                                    break;
                                case(3):
                                    naux->t->type = "string";
                                    break;
                                case(4):
                                    naux->t->type = "none";
                            }
                        }
                        else{
                            printf("Cannot find symbol %s\n",naux->t->symbol);
                            errorcount++;
                        }
                }
                
                }
                printf("Tipo de nó operando: %d\n",naux->t->cl);
                printf("Operando: %s\n",naux->t->symbol);
            }
            errorcount += comparaTipo(n,n->first_son->t->type,n->first_son->first_son->t->type,0);

           
           
           
          // printf("Operador: %s\n",n->t->symbol);
           //     printf("OHOHOHOH %d\n",n->first_son->t->cl);
                newel = search_el(*ele,n->first_son);
                switch(newel->type){
                    case(0):
                        n->first_son->t->type = "int";
                        break;
                    case(1):
                        n->first_son->t->type = "float32";
                        break;
                    case(2):
                        n->first_son->t->type = "bool";
                        break;
                    case(3):
                        n->first_son->t->type = "string";
                        break;
                    case(4):
                        n->first_son->t->type = "none";
                }
             //   printf("Operando1: %s\n",n->first_son->t->symbol);
              //  printf("Boas %d\n",newel->type);
                if (newel != 0){
                    printf("ola %s\n",n->first_son->t->type);
                    printf("pls\n");
                    if(n->first_son->next != NULL){
                 //       printf("Operando2: %s\n",n->first_son->next->t->symbol);
                //        printf("AHHAHAHAHOHOHOH %d\n",n->first_son->next->t->cl);
                        newel = search_el(*ele,n->first_son->next);
                        if (newel != 0){
                            strcpy(ptr2,n->first_son->t->type);
                            comparaTipo(n,ptr1,ptr2,0);
                        }
                        else{
                            printf("Cannot find symbol %s\n",n->first_son->next->t->symbol);
                        }
                        comparaTipo(n,n->first_son->t->type,"int",0);

                    }
                    else{
                        comparaTipo(n,ptr1,NULL,1);
                    }
                }
                else{printf("Cannot find symbol %s\n",n->first_son->t->symbol);}
            
            */
            break;
            
/*
            
            nó (operador):
            ver se existe o filho da esquerda (ir á tabela):

            se existe ver o tipo{
                ver se existe o filho da direita (ir á tabela):
                    se existir :
                        verficar se é compativel
            }
            se nao existir{
                mensagem de erro : " a variavel x nao existe linha coluna"
                anotar tipo undef na arvore
                mensagem de erro : " a operação nao pode ser feita"
            }
            
            int+int         float+float
            
            
            
            
            */
            
            
        case(statement1):
           /* n->t->type = "int";
            printf("blablbalbalblba operador: %s\n",n->t->symbol);      //parseargs
            printf("blablbalbalblba operador type: %d\n",n->t->cl);      //parseargs
            printf("Linha %d Coluna %d\n",n->t->line,n->t->column);
            naux = n;
            for(int i = 0; i < 2; i++){
                naux = naux->first_son;
                newel = search_el(*ele,n->first_son);
                
                if (naux->t->cl != 8){
                    newel = search_el(*ele,naux);        //procurar tabela
                    if (newel != 0){
                        switch(newel->type){
                            case(0):
                                naux->t->type = "int";
                                break;
                            case(1):
                                naux->t->type = "float32";
                                break;
                            case(2):
                                naux->t->type = "bool";
                                break;
                            case(3):
                                naux->t->type = "string";
                                break;
                            case(4):
                                naux->t->type = "none";
                        }
                    }
                    else{
                        printf("Cannot find symbol %s\n",naux->t->symbol);
                        errorcount++;
                    }
                }
                printf("Tipo de nó operando: %d\n",naux->t->cl);
                printf("Operando: %s\n",naux->t->symbol);
            }
            errorcount += comparaTipo(n,n->first_son->t->type,n->first_son->first_son->t->type,0);

      */
      
      /*
          newel = search_el(*ele,n->first_son);
            printf("Symbol operando: %s\n",n->t->symbol);
            if (newel != 0){
                switch(newel->type){
                    case(0):
                        n->first_son->t->type = "int";
                        break;
                    case(1):
                        n->first_son->t->type = "float32";
                        break;
                    case(2):
                        n->first_son->t->type = "bool";
                        break;
                    case(3):
                        n->first_son->t->type = "string";
                        break;
                    case(4):
                        n->first_son->t->type = "none";
                }
                printf("Type operando 1 %s\n",n->first_son->t->type);
                printf("Operando 1: %s\n",n->first_son->t->symbol);
                if(n->first_son->first_son != NULL){
                  printf("Operando 2: %s\n",n->first_son->first_son->t->symbol);
                    if (n->first_son->first_son->t->cl == 15){
                        newel = search_el(*ele,n->first_son->first_son);
                        if (newel != 0){
                            switch(newel->type){
                                case(0):
                                    n->first_son->first_son->t->type = "int";
                                    break;
                                case(1):
                                    n->first_son->first_son->t->type = "float32";
                                    break;
                                case(2):
                                    n->first_son->first_son->t->type = "bool";
                                    break;
                                case(3):
                                    n->first_son->first_son->t->type = "string";
                                    break;
                                case(4):
                                    n->first_son->first_son->t->type = "none";
                            }
                        }
                    }
                  printf("Tipo de nó operando 2: %d\n",n->first_son->first_son->t->cl);
                  comparaTipo(n,n->first_son->t->type,n->first_son->first_son->t->type,0);
                 newel = search_el(*ele,n->first_son->next);
                    if (newel != 0){
                        strcpy(ptr2,n->first_son->t->type);
                        
                    }
                    else{
                        printf("Cannot find symbol %s\n",n->first_son->next->t->symbol);
                    }
                    comparaTipo(n,n->first_son->t->type,"int",0);

                }
                else{
                    printf("axagxasx\n");
                    comparaTipo(n,ptr1,NULL,1);
                }
            }
            else{printf("Cannot find symbol %s\n",n->first_son->t->symbol); errorcount++;}*/
            break;
            
        case(funcinv):
            //printf("Funcinv %s\n", n->first_son->t->symbol);
            naux = n->first_son;   //no funcinvocation
            newel = search_el(*ele, naux);
            if (newel!= 0){
                switch(newel->type){
                    case(0):
                        n->t->type = "int";
                        break;
                    case(1):
                        n->t->type = "float32";
                        break;
                    case(2):
                        n->t->type = "bool";
                        break;
                    case(3):
                        n->t->type = "string";
                        break;
                    case(4):
                        n->t->type = "none";
                }
            }
            else{
                n->t->type = "undef";
            }
           // printf("Sou o params %s\n",params);
            buffer[0]='\0';
            strcat(buffer,"(");
           // printf("Sou o params %s\n",params);

            int i = 0;
            if(naux->first_son != NULL){
                naux = naux->first_son; //naux passa a no argumento // MUDOU!!!!!!!!!
                check_type(naux,auxT);
                for(arg1 = newel->first_son; arg1!=NULL; arg1 = arg1->next, i++, naux = naux->next){ //naux passa a ser irmão do nó funcinv(nó que está a ser passado como argumento) //naux2 é o argumento da função
                    if(i!=0){
                        strcat(buffer,",");
                        //printf("BUFFER   : %s\n",buffer);

                    }
                    //printf("Sou um número %d\n",naux->t->cl);
                   // printf("Argumento  %d !!!\n",i+1);

                    if(naux->t->cl != factor){           //se nao for intlit ou realit
                        newel = search_el(*ele, naux); //pesquisar se nó passado como argumento existe na tabela
                        if (newel!= 0){
                            switch(newel->type){
                                case(0):
                                    naux->t->type = "int";
                                    break;
                                case(1):
                                    naux->t->type = "float32";
                                    break;
                                case(2):
                                    naux->t->type = "bool";
                                    break;
                                case(3):
                                    naux->t->type = "string";
                                    break;
                                case(4):
                                    naux->t->type = "none";
                            }
                        }
                        else{
                            naux->t->type = "undef";   //não existe na tabela
                        }
                    }
                    //strcat(params,",");  ----->Segmentation fault

                   // printf("buffer: %s\n", buffer);

                   
                    

                    strcat(buffer,arg1->nome);
                    //printf("buffer2.0: %s\n",buffer);

                   // strcat(buffer,params);
                   // strcat(buffer,arg1->nome);
                    //printf("Sou o params %s\n",params);
                   
                    
                }

            }
            
            strcat(buffer,")");
           // printf("BUFFER final  : %s\n",buffer);

           // strcat(buffer,params);
           // strcat(buffer,")");

          // printf("buffer3.0: %s\n",buffer);
                
           // printf("só falta o último\n");

            n->first_son->t->type = strdup(buffer);
           
            break;
            
            
        case(parsgs):
             //n->t->type = "int";
             //printf("blablbalbalblba operador: %s\n",n->t->symbol);      //parseargs
             //printf("blablbalbalblba operador type: %d\n",n->t->cl);      //parseargs
            // printf("Linha %d Coluna %d\n",n->t->line,n->t->column);
             naux = n;
             for(int i = 0; i < 2; i++){
                 naux = naux->first_son;
                 newel = search_el(*ele,n->first_son);
                 
                 if (naux->t->cl != 8){
                     newel = search_el(*ele,naux);        //procurar tabela
                     if (newel != 0){
                         switch(newel->type){
                             case(0):
                                 naux->t->type = "int";
                                 break;
                             case(1):
                                 naux->t->type = "float32";
                                 break;
                             case(2):
                                 naux->t->type = "bool";
                                 break;
                             case(3):
                                 naux->t->type = "string";
                                 break;
                             case(4):
                                 naux->t->type = "none";
                         }
                     }
                     else{
                         printf("Cannot find symbol %s\n",naux->t->symbol);
                         errorcount++;
                     }
                 }
                // printf("Tipo de nó operando: %d\n",naux->t->cl);
                // printf("Operando: %s\n",naux->t->symbol);
             }
             errorcount += comparaTipo(n,n->first_son->t->type,n->first_son->first_son->t->type,0);

       
            break;

        case(statement): case(parseargs): case(assi):
            break;
        case(funcinvocation):
            break;
            
        case(factor1):


                    newel = search_el(*ele,n);        //procurar na tabela
                        if (newel != 0){
                            switch(newel->type){                        // apontar na árvore o tipo do simbolo de acordo com o encontrado na tabela
                                case(0):
                                    n->t->type = "int";

                                    break;
                                case(1):
                                    n->t->type = "float32";
                                    break;
                                case(2):
                                    n->t->type = "bool";
                                    break;
                                case(3):
                                    n->t->type = "string";
                                    break;
                                case(4):
                                    n->t->type = "none";
                            }
                        }
                        else{                                                           //simbolo nao encontrado na tabela
                            printf("Cannot find symbol %s\n",n->t->symbol);          //dá erro
                            n->t->type = "undef";
                            errorcount++;
                        }



                    break;
            
        case(Ret):
            //printf("Aloha  %s\n",n->first_son->t->symbol);
                    check_type(n->first_son,auxT);


                   /* if(check_return(n,ele)==1){
                        printf("mensagem erro 123\n");
                    }
                    else if(check_return(n,ele)==0){
                        printf("supostamente deu certo\n");

                    }
*/

                    break;
            
        case(assig):
            //printf("Filhinho %s %d\n",n->first_son->next->t->symbol,n->first_son->next->t->cl);
            newel = search_el(*ele,n->first_son);        //procurar tabela
            if (newel != 0){
                switch(newel->type){                //falta verificar se tipo da expressao e do id sao iguais
                    case(0):
                        n->t->type = "int";         //id = expr
                        n->first_son->t->type = "int";         //id = expr
                        break;
                    case(1):
                        n->t->type = "float32";
                        n->first_son->t->type = "float32";         //id = expr
                        break;
                    case(2):
                        n->t->type = "bool";
                        n->first_son->t->type = "bool";         //id = expr
                        break;
                    case(3):
                        n->t->type = "string";
                        n->first_son->t->type = "string";         //id = expr
                        break;
                    case(4):
                        n->t->type = "none";
                        n->first_son->t->type = "none";         //id = expr
                }
            }
            else{
                printf("Cannot find symbol %s\n",n->t->symbol);
                n->t->type = "undef";
                n->first_son->t->type = "undef";
                errorcount++;
            }
            for(naux=n->first_son; naux!=NULL; naux = naux->next){
                errorcount += check_type(naux,auxT);
                processado = 1;
            }
            
            if(strcmp(n->t->type,n->first_son->next->t->type)!=0){
                printf("Line %d, column %d: Operator = cannot be applied to types %s, %s\n",n->t->line,n->t->column,n->t->type,n->first_son->next->t->type);
            }
            
            break;
        
    }
    //varsandstatements,factor,expression,parseargs,statement,funcinvocation
    if(n->first_son!=NULL){                             //função check_type recursiva
        node *aux = n->first_son;
        for (; aux!=NULL; aux=aux->next) {
            if(processado == 0)
                errorcount += check_type(aux, auxT);
        }
        free(aux);
    }
    return errorcount;
}



/*

Symbol < token > already defined
Cannot find symbol < token >  ---->Check: expression
Operator < token > cannot be applied to type < type > 
Operator < token > cannot be applied to types < type > , <type >
Incompatible type < type > in < token > statement
Symbol < token > declared but never used


*/


    /*
    void check_type(node* n){
        int value;
        //pos order(first father)
        
        //pre order (first children)
        
        for vardecl:
            get name and see if it exists in previous tables
            if it does, print error
            else add it to current table
        
        for expression:
            operations:
                operands:
                    see if exists in table
                see if operands are compatible
                    
        
        ...
       
        }


    */
//int float32 string bool


    
