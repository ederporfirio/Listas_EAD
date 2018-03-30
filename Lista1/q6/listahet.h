//Lista de Exercícios
//Professor José Maria
//Eder Jacques Porfirio Farias

// Lista 1 - Questão 6

//Definição da Interface

#define COR 0
#define POP 1
#define FID 2

#include <stdlib.h>

typedef struct corrente Corrente;

typedef struct poupanca Poupanca;

typedef struct fidelidade Fidelidade;

typedef struct lista_h ListaH;

//Funções de criação e busca
ListaH* lista_cria(void);

ListaH* lista_busca(ListaH* lst, int num);

//Funções para criação de contas
ListaH* cria_corrente (ListaH* lst, float deposito_inicial);

ListaH* cria_poupanca (ListaH* lst, float deposito_inicial);

ListaH* cria_fidelidade (ListaH* lst, float deposito_inicial);

//Funções para Efetuar Crédito
static float efetua_credito (ListaH* lst, int num, float deposito);
static float cred_poupanca (Poupanca* p, float deposito);
static float cred_corrente (Corrente* c, float deposito);
static float cred_fidelidade (Fidelidade* f, float deposito);

//Funções para Efetuar Débito
static float efetua_debido (ListaH* lst, int num, float saque);
static float deb_corrente (Corrente* c, float saque);
static float deb_poupanca (Poupanca* p, float saque);
static float deb_fidelidade (Fidelidade* f, float saque);

//Funções para Efetuar Retirada de bonus
static float efetua_bonus (ListaH* lst, int num);
static float bonus_fid (Fidelidade* f);

//Função de Transferencia
static void ransferencia_contas(ListaH* lst, int cnt_deb, int cnt_cred, float valor);

//Funções para render juros
static float render_juros(ListaH* lst, int num, float taxa);
static float juros_pop (Poupanca* p, float taxa);

//Funções Buscar saldo
static float busca_saldo (ListaH* lst, int num);

//Imprime todos os elementos de uma lista
void lista_imprime(ListaH* lst);

//Libera Lista
void lista_libera (ListaH* lst);
