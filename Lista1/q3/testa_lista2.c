//Lista de Exercícios
//Professor José Maria
//Eder Jacques Porfirio Farias

// Lista 1 - Questão 1

//Programa Principal

#include <stdio.h>
#include "lista2.c"

int main (void){

  Lista* lst;
  lst = lista_cria();

  //Insere Elementos
  lst = lista_insere (lst, 23);
  lst = lista_insere (lst, 45);
  lst = lista_insere (lst, 115);
  lst = lista_insere (lst, 78);

  //Impime Lista
  lista_imprime(lst);

  //Retira elemento
  lst = lista_retira(lst,78);

  //Imprime Lista
  lista_imprime(lst);

  lista_libera(lst);
  return 0;
}
