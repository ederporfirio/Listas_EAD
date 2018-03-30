//Lista de Exercícios
//Professor José Maria
//Eder Jacques Porfirio Farias

// Lista 1 - Questão 4

//Função Main

#include <stdio.h>
#include "listacirc.c"

int main() {

	// 1. Criar uma lista vazia;
	Lista* lst; 		/* declara lista não iniciada */
	lst = lista_cria(); 	/* inicia lista vazia */
  
	//2. Inserir elemento;
	lst = lista_insere(lst, 23);
	lst = lista_insere(lst, 32);
	lst = lista_insere(lst, 10);
	lst = lista_insere(lst, 98);

	lista_imprime(lst);


	lista_imprime_rec(lst, lst);

  printf ("%d\n", lista_vazia(lst));

  Lista* p = lista_busca(lst, 132);
  if (p)
    printf("%d\n", p->info);
  else
    printf("não existe\n");

  lst = lista_retira(lst, 23);

  lista_imprime(lst);

	lista_libera(lst);

	return 0;
}
