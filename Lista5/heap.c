//Estrutura de Dados Avançados
// Professor José Maria
//
//Aluno: Eder Jacques Porfírio Farias
//
// Lista de Exercícios 5
//
//Arquivo heap.c

#include <stdio.h>
#include "heap.h"

struct heap {
	int max; 	/* tamanho maximo do heap */
	int pos;    /* proxima posicao disponivel no vetor */
	float* prioridade; /* vetor das prioridades */
};

Heap* heap_cria(int max){
	Heap* heap=(Heap*)malloc(sizeof(Heap));
	heap->max=max;
	heap->pos=0;
	heap->prioridade=(float*)malloc(max*sizeof(float));
	return heap;
}

void heap_insere(Heap* heap, float prioridade){
	if ( heap->pos <= heap->max-1 ) {

		heap->prioridade[heap->pos]=prioridade;
		corrige_acima(heap,heap->pos);heap->pos++;
	}
	else
		printf("Heap CHEIO!\n");
}

static void troca(int a, int b, float*v) {
	float f= v[a];
	v[a] = v[b];
	v[b] = f;
}

static void corrige_acima(Heap* heap, int pos) {
	while(pos > 0){
	 //Aqui está a recursãoint pai = (pos-1)/2;
	 //É uma Max Heap
		if (heap->prioridade[pai] < heap->prioridade[pos])
			troca(pos,pai,heap->prioridade);
		else
			break;pos=pai;
	}
}

float heap_remove(Heap* heap) {
	if (heap->pos>0) {
		float topo=heap->prioridade[0];
		heap->prioridade[0]=heap->prioridade[heap->pos-1];
		heap->pos--;
		corrige_abaixo(heap);
		return topo;
	}
	else {
		printf("Heap VAZIO!");
		return -1;
	}
}

static void corrige_abaixo(Heap* heap){
	int pai=0;
	while (2*pai+1 < heap->pos){
	//Aqui está a recursão
	int filho_esq=2*pai+1;
	int filho_dir=2*pai+2;
	int filho;
	if (filho_dir >= heap->pos)
		filho_dir=filho_esq;
	if (heap->prioridade[filho_esq]>heap->prioridade[filho_dir])
		filho=filho_esq;
	else
		filho=filho_dir;
	if (heap->prioridade[pai]<heap->prioridade[filho])
	// Max Heap
		troca(pai,filho,heap->prioridade);
	else
		break;
	pai=filho;
	}
}
