//Lista de Exercícios
//Professor José Maria
//Eder Jacques Porfirio Farias

// Lista 1 - Questão 1

//Programa Principal

#include <stdio.h>
#include "lista.c"

int main (void){

  Lista* lst;
  lst = lista_cria();

  //Insere Elementos
  lst = lista_insere (lst, 23);
  lst = lista_insere (lst, 45);
  lst = lista_insere (lst, 56);
  lst = lista_insere (lst, 78);

  //Impime Lista
  lista_imprime(lst);

  //Retira elemento
  lst = lista_retira(lst,78);

  //Imprime Lista
  lista_imprime(lst);

  lst = lista_retira(lst,45);

  lista_imprime_rec(lst);
  lista_imprime_rec_inv(lst);
  lista_libera(lst);
  system("pause");
  return 0;
}
