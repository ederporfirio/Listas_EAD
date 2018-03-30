//Lista de Exercícios
//Professor José Maria
//Eder Jacques Porfirio Farias

// Lista 1 - Questão 1

//Implementação das Funções

#include <stdlib.h>
#include <stdio.h>
#include "lista2.h"

//Definição do tipo de dados
struct lista {
  int info;
  Lista* ant;
  Lista* prox;
};

//Criar Lista Vazia
Lista* lista_cria(void){
  return NULL;
}

//Insere elemento na lista
Lista* lista_insere (Lista* lst, int val){
	Lista* novo;
	novo = (Lista*) malloc(sizeof(Lista));
	novo->info = val;
	if(lista_vazia(lst)){/*caso a lista esteja vazia*/
		novo->prox = NULL;/*ligando o prox a null*/
		novo->ant = NULL;/*ligando o ant a null*/
		lst = novo;
	}else {/*caso a lista não esteja vazia*/
		Lista* p = lst; /* ponteiro para percorrer a lista */
		Lista* fim = NULL;/* ponteiro para guardar o último nó */
		/* procura posição para inserção */
		while (p != NULL && p->info < val) {
			if(p->prox == NULL){
				fim = p;
			}
			p = p->prox;
		}
		if(p == lst){/*caso o local seja a primeira posição*/
			novo->prox = lst;
			novo->ant = NULL;
			lst->ant = novo;
			lst = novo;
		}else if(fim != NULL){/*caso o local seja a última posição*/
			novo->prox = NULL;
			novo->ant = fim;
			fim->prox = novo;
			fim = NULL;
		}else{/*caso o local seja no meio*/
			novo->prox = p;/*ligando o prox do novo ao p*/
			novo->ant = p->ant;/*ligando o ant do novo ao ant do p*/
			p->ant->prox = novo;/*ligando o prox do do ant de p ao novo*/
			p->ant = novo;/*ligando o ant do p ao novo*/
		}
	}
	return lst; /* retorna ponteiro para o primeiro elemento */
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
    lista_imprime_rec(lst->prox);}
}

//Imprime Recursivo - Invertido
void lista_imprime_rec_inv (Lista* lst){
  if (!lista_vazia(lst)) {
  /* imprime sub-lista */
  lista_imprime_rec_inv (lst->prox);}
  /* imprime ultimo elemento*/
  printf("info: %d\n", lst->info);
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
Lista* lista_retira (Lista* lst, int val){
	Lista* p = lst; /* ponteiro para percorrer a lista */
	/* procura elemento na lista, guardando anterior */
	while (p != NULL && p->info != val) {
		p = p->prox;
	}
	/* verifica se achou elemento */
	if (p == NULL)
		return lst; /* não achou: retorna lista original */
	/* achou: retira */
	if (p->ant == NULL){ /* retira elemento do inicio */
		lst = p->prox;
		lst->ant = NULL;
	}else {/* retira elemento do meio da lista */
		p->ant->prox = p->prox;
		p->prox->ant = p->ant;
	}
	free(p); /* libera espaço ocupado pelo elemento */
	return lst;
}

Lista* lista_retira_rec (Lista* lst, int val) {
   if (!lista_vazia(lst)) {
      /* verifica se elemento a ser retirado é o primeiro */
      if (lst->info == val) {
	        Lista* t = lst;
	        lst = lst->prox;
	        if(lst != NULL){/* só liga se não for o último*/
	        	lst->ant = lst->ant->ant;
			}
	        free(t);
       } else {
            lst->prox = lista_retira_rec(lst->prox, val); /* retira de sub-lista */
       }
    }
    return lst;
}

/*
Lista* lista_retira (Lista* lst, int val) {
   Lista* p = lista_busca(lst, val);
   if (p == NULL)
     return lst;


   if (lst == p)
      lst = p->prox;

   else
      p->ant->prox = p->prox;
   if (p->prox != NULL)
      p->prox->ant = p->ant;
  free(p);
  return lst;
}


//Retira um elemento da lista usando recursividade
Lista* lista_retira_rec (Lista* lst, int val) {
 if (!lista_vazia(lst)) {

    if (lst->info == val) {
       Lista* t = lst;
       lst = lst->prox;
       list->ant = NULL;
       free(t);
     }
     else {

      lst->prox = lista_retira_rec(lst->prox, val);
    }
  }
  return lst;
}

*/

//Libera Lista
void lista_libera(Lista* lst){
  Lista* p = lst;
  while (p != NULL) {
    Lista* t = p->prox;   /* guarda referência para opróximo elemento */
    free(p);              /* libera a memória apontada por p */
    p = t;                /* faz p apontar para o próximo */
  }
}
