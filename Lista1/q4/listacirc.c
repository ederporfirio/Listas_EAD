//Lista de Exercícios
//Professor José Maria
//Eder Jacques Porfirio Farias

// Lista 1 - Questão 4

//Implementação das Funções

#include <stdlib.h>
#include <stdio.h>
#include "listacirc.h"

//Definição do tipo de dados
struct lista {
  int info;
  Lista* prox;
};

//Criar Lista Vazia
Lista* lista_cria(void){
  return NULL;
}

//Insere elemelento na lista
Lista* lista_insere (Lista* lst, int val){
  Lista* novo;
  novo = (Lista*) malloc(sizeof(Lista));
  novo->info = val;

  if (lst == NULL)
      novo->prox = novo;
  else {
      Lista* p = lst; /* faz p apontar para o nó inicial */
      while(p->prox != lst) {
          p = p->prox; /* avança para o próximo nó */
      }
      p->prox = novo;
      novo->prox = lst;
  }
  return novo;
}

//Imprime Lista
void lista_imprime(Lista* lst){
  Lista* p = lst;
    if (p) do {
      printf("%d\n", p->info);
      p = p->prox;
  } while (p != lst);
}

//Imprime Recursivo
void lista_imprime_rec (Lista* lst, Lista* p){
  if (p) {
    /* imprime primeiro elemento*/
    printf("info: %d\n",lst->info);
    if (p->prox != lst)
      lista_imprime_rec(lst, p->prox);
    }
}

//Verifica Lista Vazia
int lista_vazia(Lista* lst){
  return(lst==NULL);
}


//Busca lista
Lista* lista_busca(Lista* lst, int val){
   Lista* p;
   do {
     if (p && p->info == val)
      return p;
     p = p->prox;
   } while(p!=lst);

   return NULL;
}

//Retira Item da lista
Lista* lista_retira(Lista* lst, int val){
  Lista* ant = NULL;
  Lista* p = lst;

  do {
    if (p && p->info == val)
     break;
    ant = p;
    p= p->prox;
  } while(p!=lst);

  if (p == NULL  || p->info != val)
    return lst;

  if (ant == NULL)
    if(p->prox == lst)
      lst = NULL;
    else {
      Lista* q;
      for (p = p->prox; q->prox != lst; q = q->prox);
      q->prox = p->prox;
      lst = p->prox;
    }
  else {
    ant->prox = p->prox;
  }

  free (p);
  return (lst);
}

//Libera Lista Circuclar
void lista_libera(Lista* lst){
  Lista *p, *s, *t;
  p = s = lst;

  if (p)
    do {
      t = p;
      p = p->prox;
      free(t);
    } while (p != s);
}
