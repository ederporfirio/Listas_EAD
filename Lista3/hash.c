//Estrutura de Dados Avançados
//Prof. José Maria
//Aluno Eder Porfírio
//
//Lista de Exercícios - Lista 3

//hash.c

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "hash.h"

//struct Cliente
struct cliente {
	int cod;
	char nome[50];
	Cliente* prox; /* encadeamento na lista de colisão*/
};

//Algorítimos de Hash
int hashDivisao (int cod, int tam) {
	return (cod & 0x7FFFFFFF) % tam;
}

int hashMultiplicacao(int cod, int tam){
  float A = 0.6180339887; //constante 0 < A < 1
  float val = cod * A;
  val = val - (int) val;
  return (int) (tam * val);
}

int hashDobra (int cod, int tam){
  int num_bits = 10;
  int parte1 = cod >> num_bits;
  int parte2 = cod & (tam -1);
  return (parte1 ^ parte2);
}


//Struct Hash
struct hash {
	Cliente** v;
	int tam;
};

//Função de Criaçao da Tabela Hash
Hash* criaHash (int tam) {
	Hash* ha = (Hash*) malloc(sizeof(Hash));
	ha->tam = tam;
	ha->v = (Cliente**) calloc(tam, sizeof(Cliente*));
	return ha;
}

Hash* liberaHash (Hash* ha) {
	int i;
	for (i = 0; i < ha->tam; i++){
		Cliente* p;

		while (ha->v[i] != NULL){
			p = ha->v[i];
			ha->v[i] = p->prox;
			free (p);
		}

		free(ha->v[i]);
	}
	free(ha->v);
	free(ha);
	return NULL;
}


Cliente* buscaHash (Hash* ha , int cod) {
	if(ha == NULL)
  	return 0;

	int pos = hashDivisao(cod, ha->tam);
	Cliente* a = ha->v[pos];
	while (a != NULL) {
		if (a->cod == cod)
			return a;
		a = a->prox;
	}
	return NULL;
}


Hash* insereHash (Hash* ha , int cod, char* nome) {
	int pos = hashDivisao(cod, ha->tam);
	Cliente* a = (Cliente*) malloc(sizeof(Cliente ));
	a->prox = ha->v[pos];
	a->cod = cod;
	strcpy(a->nome ,nome);
	ha->v[pos] = a;
	printf("Cliente Inserido\n");
	return ha;
}


void retiraHash (Hash* ha , int cod) {
	int pos = hashDivisao(cod, ha->tam);
	Cliente* a = ha->v[pos];
	Cliente* ant = NULL;

	while (a != NULL && a->cod != cod){
		ant = a;
		a = a->prox;
	}

    if (a == NULL)
        return;
    if (ant == NULL)
        ha->v[pos] = a->prox;
    else
        ant->prox = a->prox;

    free(a);
}
