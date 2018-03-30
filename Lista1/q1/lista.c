//Lista de Exercícios
//Professor José Maria
//Eder Jacques Porfirio Farias

// Lista 1 - Questão 1

//Implementação das Funções

#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

//Definição do tipo de dados
struct lista {
  int info;
  Lista* prox;
};

//Criar Lista Vazia
Lista* lista_cria(void){
  return NULL;
}

//Insere um elemento no início
Lista* lista_insere(Lista* lst, int val){
  Lista* novo = (Lista*) malloc(sizeof(Lista));
  novo->info = val;
  novo->prox = lst;
  return novo;
}

//Imprime Lista
void lista_imprime(Lista* lst){
  Lista* p;
  for (p = lst; p != NULL; p = p->prox)
    printf("info = %d\n", p->info);
  printf("fim");
}

//Imprime Recursivo
void lista_imprime_rec (Lista* lst) {
  if (!lista_vazia(lst)) {
    /* imprime primeiro elemento*/
    printf("info: %d\n", lst->info);
    /* imprime sub-lista */
    lista_imprime_rec(lst->prox);
  }
}

//Imprime Recursivo - Invertido
void lista_imprime_rec_inv (Lista* lst){
  if (!lista_vazia(lst)) {
  /* imprime sub-lista */
  lista_imprime_rec_inv (lst->prox);
  /* imprime ultimo elemento*/
  printf("info: %d\n", lst->info);
  }
}

//Verifica Lista Vazia
int lista_vazia(Lista* lst) {
  return(lst == NULL);
}

//Busca lista
Lista* lista_busca(Lista* lst, int val){
   Lista* p;
   for (p=lst; p!=NULL; p = p->prox)
    {
      if (p->info == val)return p;
    }
   return NULL;
}

//Retira Item da lista
Lista* lista_retira(Lista* lst, int val){
  Lista* ant = NULL; /* ponteiro para elemento anterior */
  Lista* p = lst;    /* ponteiro para percorrer a lista */
  /* procura elemento na lista, guardando anterior */

  while (p != NULL && p->info != val) {
      ant = p;p = p->prox;
  }/* verifica se achou elemento */

  if (p == NULL)return lst;/* não achou: retorna lista original */
  /* achou: retira */
  if (ant == NULL) /* retira elemento do inicio */
    lst = p->prox;
  else /* retira elemento do meio da lista */
    ant->prox = p->prox;

  free(p); /* libera espaço ocupado pelo elemento */
  return lst;
}

//Retira um elemento da lista usando recursividade
Lista* lista_retira_rec (Lista* lst, int val) {
   if (!lista_vazia(lst)) {
      /* verifica se elemento a ser retirado é o primeiro */
      if (lst->info == val) {
         Lista* t = lst;
         lst = lst->prox;
         free(t);
       }
       else {
         /* retira de sub-lista */
         lst->prox = lista_retira_rec(lst->prox, val);
      }
    }
    return lst;
}

void lista_libera(Lista* lst){
  Lista* p = lst;
  while (p != NULL) {
    Lista* t = p->prox;   /* guarda referência para opróximo elemento */
    free(p);              /* libera a memória apontada por p */
    p = t;                /* faz p apontar para o próximo */
  }
}
