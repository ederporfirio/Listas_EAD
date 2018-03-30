//Lista de Exercícios
//Professor José Maria
//Eder Jacques Porfirio Farias
// Lista 1 - Questão 1

//Definição de Interface

typedef struct lista Lista;

//Criar Lista Vazia
Lista* lista_cria(void);

//Insere elemelento no início
Lista* lista_insere(Lista* lst, int val);

//Imprime lista
void lista_imprime(Lista* lst);

//Imprime Recursivo
void lista_imprime_rec (Lista* lst);

//Imprime Recursivo - Invertido
void lista_imprime_rec_inv (Lista* lst);

//Verifica Lista Vazia
int lista_vazia(Lista* lst);

//Busca lista
Lista* lista_busca(Lista* lst, int val);

//Retira Item da lista
Lista* lista_retira(Lista* lst, int val);

//Retira Item de maneira recursiva
Lista* lista_retira_rec (Lista* lst, int val);

//Libera lista
void lista_libera(Lista* lst);
