//Estrutura de Dados Avançados
//Prof. José Maria
//Aluno Eder Porfírio
//
//Lista de Exercícios - Lista 3

//Testa Hash

#include <stdio.h>
#include "hash.c"

int main(){
	Hash* ha;
	Cliente* cliente;

	int n;
	printf("Digite o número máximo de Chaves: \n");
	scanf("%d", &n);
	ha = criaHash(n/2);

	ha = insereHash (ha , 225, "Eder");
	ha = insereHash (ha , 725, "Emanuel");

	cliente = buscaHash (ha , 225);
	if (!cliente)
		printf("Cliente Inexistente\n");
	else
		printf("Cliente Encontrado: %s\n", cliente->nome);

	retiraHash (ha, 123);

	cliente = buscaHash (ha , 123);
	if (!cliente)
	 	printf("Cliente Inexistente\n");
	else
	 	printf("Cliente Encontrado: %s\n", cliente->nome);

	ha = liberaHash(ha);
	if (ha == NULL)
		printf("Hash foi libedado com Sucesso\n");
	else
		printf ("Erro na Liberação\n");
}
