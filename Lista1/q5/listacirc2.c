//Lista de Exercícios
//Professor José Maria
//Eder Jacques Porfirio Farias

// Lista 1 - Questão 5

//Implementação das Funções

#include <stdlib.h>
#include <stdio.h>
#include "listacirc2.h"

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

//Verifica Lista Vazia
int lista_vazia(Lista* lst){
  return(lst == NULL);
}

//Insere elemento na lista
Lista* lista_insere (Lista* lst, int val){
	Lista* novo;
	novo = (Lista*) malloc(sizeof(Lista));
	novo->info = val;

  if(lista_vazia(lst)){/*caso a lista esteja vazia*/
    lst = novo;
    lst->prox = lst;/*ligando a ele mesmo*/
		lst->ant = lst;/*ligando a ele mesmo*/
    printf ("Inserindo primeiro \n");

	}
  else
  {/*caso a lista não esteja vazia*/
		Lista* p = lst; /* ponteiro para percorrer a lista */
	  //Lista* fim = NULL;/* ponteiro para guardar o último nó */

    // /* procura posição para inserção */
		while (p->prox != lst) {
		// 	if(p->prox == lst){
		// 		fim = p;
		// 	}
		p = p->prox;
		}
		if(p == lst){/*caso apenas um item na list*/
			novo->ant = lst;
			novo->prox = lst;
			lst->ant = novo;
      lst->prox = novo;
      printf ("Inserindo segundo \n");

		}
    else
    {
      p->prox = novo;
      novo->prox = lst;
      lst->ant = novo;
			novo->ant = p;
      printf ("Inserindo outros \n");
		}
	}
  return lst; /* retorna ponteiro para o primeiro elemento */

}

//Imprime Lista
void lista_imprime(Lista* lst) {
  Lista* p = lst;
  do {
    printf("info = %d\n", p->info);
    p = p->prox;
  } while (p->prox != lst);
  printf("\n fim");
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
  Lista* p = lista_busca (lst, val);
  if (p == NULL)
    return lst; /* não achou: retorna lista inalterada */

  if (lst == p) {
    lst = p->prox;
    lst->ant = p->ant;
    p->ant->prox = lst;
    free(p);
  }
  else {
    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    free (p);
  }
  return lst;
}

//Retira um elemento da lista usando recursividade
Lista* lista_retira_rec (Lista* lst, int val) {
 if (!lista_vazia(lst)) {
    /* verifica se elemento a ser retirado é o primeiro */
    if (lst->info == val) {
       Lista* t = lst;
       lst = lst->prox;
       lst->ant = t->ant;
       t->ant->prox = lst;
       free(t);
     }
     else {
       /* retira de sub-lista */
      lst->prox = lista_retira_rec(lst->prox, val);
    }
  }
  return lst;
}

//Libera Lista Circuclar
void lista_libera(Lista* lst){
  Lista* p = lst;
  while (p->prox != lst) {
    Lista* t = p->prox;   /* guarda referência para opróximo elemento */
    free(p);              /* libera a memória apontada por p */
    p = t;                /* faz p apontar para o próximo */
  }
}
