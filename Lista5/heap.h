//Estrutura de Dados Avançados
// Professor José Maria
//
//Aluno: Eder Jacques Porfírio Farias
//
// Lista de Exercícios 5
//
//Arquivo heap.h

typedef struct _heap Heap;

Heap* heap_cria(int max);

void  heap_insere(Heap* heap, float prioridade);

static void troca(int a, int b, float*v);

static void corrige_acima(Heap* heap, int pos);

float heap_remove(Heap* heap);

static void corrige_abaixo(Heap* heap);

 float busca_heap(Heap* heap);
