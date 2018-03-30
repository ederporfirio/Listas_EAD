//Lista de Exercícios
//Professor José Maria
//Eder Jacques Porfirio Farias

// Lista 1 - Questão 4

//Definição de Interface

#include <stdlib.h>

typedef struct lista Lista;

//Criar Lista Vazia
Lista* lista_cria(void);

//Insere elemelento na lista
Lista* lista_insere(Lista* lst, int val);

//Imprime lista
void lista_imprime (Lista* lst);

//Imprime Recursivo
void lista_imprime_rec (Lista* lst);

//Verifica Lista Vazia
int lista_vazia(Lista* lst);

//Busca lista
Lista* lista_busca(Lista* lst, int val);

//Retira Item da lista
Lista* lista_retira(Lista* lst, int val);

//Retira Item da lista
Lista* lista_retira_rec (Lista* lst, int val);

//Libera Lista Circuclar
void lista_libera(Lista* lst);
