//Estrutura de Dados Avançados
//Prof. José Maria
//Aluno Eder Porfírio
//
//Lista de Exercícios - Lista 5

//Testa Heap

#include <stdio.h>
#include "heap.c"

int main(){
	Heap* hp;
	hp = heap_cria(3);

	heap_insere (hp, 12);
	heap_insere (hp, 32);
	heap_insere (hp, 22);
	heap_insere (hp, 10);
	//
	heap_remove (hp);
	heap_insere (hp, 10);

	int a = busca_heap(hp);
	if (a = 0)
		printf("Valor Não encotrado\n");
	else
		printf("Valor Encotrado: %f\n", a);

	system("pause");
  return 0;
}
