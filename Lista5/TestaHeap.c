//Estrutura de Dados Avançados
//Prof. José Maria
//Aluno Eder Porfírio
//
//Lista de Exercícios - Lista 5

//Testa Heap

#include <stdio.h>
#include "haep.c"

int main(){
	Heap* hp;
	hp = heap_cria (20);

	heap_insere (hp, 12);
	heap_insere (hp, 32);
	heap_insere (hp, 22);
	heap_insere (hp, 10);

	heap_remove (hp);

	system ("pause");
	return 0;
}
