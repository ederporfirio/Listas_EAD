//Lista de Exercícios
//Professor José Maria
//Eder Jacques Porfirio Farias

// Lista 1 - Questão 6

//Implementação das Funções

#include <stdlib.h>
#include <stdio.h>
#include "listahet.h"

//Cria as estruturas das contas
struct corrente {
  float saldo;
};

struct poupanca {
  float saldo;
};

struct fidelidade {
  float saldo;
  float bonus;
};

/* Definição do nó da estrutura */
struct lista_h {
  int tipo;
  int numero;
  void *info;
  ListaH* prox;
};

//Criar Lista Vazia
ListaH* lista_cria(void){
  return NULL;
}

//Cria um conta corrente e insere na lista
ListaH* cria_corrente (ListaH* lst, float deposito_inicial) {
  Corrente* nova_conta;
  printf ("\nCriando CONTA CORRENTE \n");
  ListaH* p;

  /* aloca conta corrente */
  nova_conta = (Corrente*) malloc(sizeof(Corrente));
  nova_conta->saldo = deposito_inicial;

  /* aloca nó */
  p = (ListaH*) malloc(sizeof(ListaH));
  p->tipo = COR;
  p->info =  nova_conta;
  p->prox = lst;
  printf("SALDO INICIAL: R$ %.2f\n", nova_conta->saldo);
  //Cria número sequencial para conta
  if (lst == NULL){
    p->numero = 1;
    printf ("Número: %04d\n", p->numero);
  }
  else{
    p->numero = lst->numero + 1;
    printf ("Número: %04d\n", p->numero);
  }


  return p;
}

//Cria um conta poupança e insere na lista
ListaH* cria_poupanca (ListaH* lst, float deposito_inicial) {
  Poupanca* nova_conta;
  printf ("\nCriando CONTA POUPANÇA \n");
  ListaH* p;

  /* aloca conta poupanca */
  nova_conta = (Poupanca*) malloc(sizeof(Poupanca));
  nova_conta->saldo = deposito_inicial;

  /* aloca nó */
  p = (ListaH*) malloc(sizeof(ListaH));
  p->tipo = POP;
  p->info = nova_conta;
  p->prox = lst;
  printf("SALDO INICIAL: R$ %.2f\n", nova_conta->saldo);
  //Cria número sequencial para conta
  if (lst == NULL){
    p->numero = 1;
    printf ("Número: %04d\n", p->numero);
  }
  else{
    p->numero = lst->numero + 1;
    printf ("Número: %04d\n", p->numero);
  }
  return p;
}

//Cria um conta fidelidade e insere na lista
ListaH* cria_fidelidade (ListaH* lst, float deposito_inicial) {
  Fidelidade* nova_conta;
  printf ("\nCriando CONTA FIDELIDADE \n");
  ListaH* p;

  /* aloca conta corrente */
  nova_conta = (Fidelidade*) malloc(sizeof(Fidelidade));
  nova_conta->saldo = deposito_inicial;
  nova_conta->bonus = deposito_inicial * 0.01;

  /* aloca nó */
  p = (ListaH*) malloc(sizeof(ListaH));
  p->tipo = FID;
  p->info =  nova_conta;
  p->prox = lst;
  printf("SALDO INICIAL: R$ %.2f\n", nova_conta->saldo);
  printf("BONUS: R$ %.2f\n", nova_conta->bonus);
  //Cria número sequencial para conta
  if (lst == NULL){
    p->numero = 1;
    printf ("Número: %04d\n", p->numero);
  }
  else{
    p->numero = lst->numero + 1;
    printf ("Número: %04d\n", p->numero);
  }
  return p;
}

//Busca lista
ListaH* lista_busca (ListaH* lst, int num){
   ListaH* p;
   for (p=lst; p!=NULL; p = p->prox)
    {
      if (p->numero == num)return p;
    }
   return NULL;
}



//Implementação de funções de crédito
float cred_corrente (Corrente* c, float deposito){
  printf ("\nINICIANDO PROCESSO DE CRÉDITO\n");
  printf("SALDO ANTERIOR: R$ %.2f\n", c->saldo);
  c->saldo = c->saldo + deposito;
  return c->saldo;
}

float cred_poupanca (Poupanca* p, float deposito){
  printf ("\nINICIANDO PROCESSO DE CRÉDITO\n");
  printf("SALDO ANTERIOR: R$ %.2f\n", p->saldo);
  p->saldo = p->saldo + deposito;
  return p->saldo;
}

float cred_fidelidade (Fidelidade* f, float deposito){
  printf ("\nINICIANDO PROCESSO DE CRÉDITO\n");
  printf("SALDO ANTERIOR: R$ %.2f\n", f->saldo);
  f->saldo = f->saldo + deposito;
  f->bonus = f->bonus + (deposito * 0.01);
  return f->saldo;
}


float efetua_credito (ListaH* lst, int num, float deposito){
  ListaH* q = lista_busca(lst, num);

  float a;
  switch (q->tipo) {
      case COR:
      a = cred_corrente((Corrente*)q->info, deposito);
      break;
      case POP:
      a = cred_poupanca((Poupanca*)q->info, deposito);
      break;
      case FID:
      a = cred_fidelidade((Fidelidade*)q->info, deposito);
      break;
  }
  printf ("CRÉDITO EFETUADO COM SUCESSO\n");
  printf("NOVO SALDO: R$ %.2f\n", a);
  return a;
}




//Implementação das funções de debito
float deb_corrente (Corrente* c, float saque){
  printf ("\nINICIANDO PROCESSO DE DÉBITO\n");
  printf("SALDO ANTERIOR: R$ %.2f\n", c->saldo);
  c->saldo = c->saldo - saque;
  return c->saldo;
}

float deb_poupanca (Poupanca* p, float saque){
  printf ("\nINICIANDO PROCESSO DE DÉBITO\n");
  printf("SALDO ANTERIOR: R$ %.2f\n", p->saldo);
  p->saldo = p->saldo - saque;
  return p->saldo;
}

float deb_fidelidade (Fidelidade* f, float saque){
  printf ("\nINICIANDO PROCESSO DE DÉBITO\n");
  printf("SALDO ANTERIOR: R$ %.2f\n", f->saldo);
  f->saldo = f->saldo - saque;
  return f->saldo;
}


float efetua_debido (ListaH* lst, int num, float saque){
  ListaH* q = lista_busca(lst, num);

  float a;
  switch (q->tipo) {
      case COR:
      a = deb_corrente((Corrente*)q->info, saque);
      break;
      case POP:
      a = deb_poupanca((Poupanca*)q->info, saque);
      break;
      case FID:
      a = deb_fidelidade((Fidelidade*)q->info, saque);
      break;
  }
  printf ("DÉBITO EFETUADO COM SUCESSO\n");
  printf("NOVO SALDO: R$ %.2f\n", a);
  return a;
}

//Implementação da função efetua bonus
float bonus_fid (Fidelidade* f) {
  printf ("\nINICIANDO PROCESSO DE TRANSFERÊNCIA DE BÔNUS\n");
  printf("SALDO ANTERIOR: R$ %.2f\n", f->saldo);
  printf("BÔNUS ANTERIOR: R$ %.2f\n", f->bonus);
  f->saldo = f->saldo + f->bonus;
  f->bonus = 0;
  printf("SALDO ATUAL: R$ %.2f\n", f->saldo);
  printf("BÔNUS ATUAL: R$ %.2f\n", f->bonus);
  return f->saldo;
}

float efetua_bonus (ListaH* lst, int num){
  ListaH* q = lista_busca(lst, num);
  float a;
  if (q->tipo == FID){
    a = bonus_fid((Fidelidade*)q->info);
  }
  else{
    printf("A CONTA BUSCADA NÃO É UMA CONTA FIDELIDADE\n");
  }
  return a;
}

//Implamentação de Função Transferencia
void transferencia_contas(ListaH* lst, int cnt_deb, int cnt_cred, float valor){
  printf ("\nINICIANDO PROCESSO DE TRANSFERÊNCIA\n");
  float a;
  ListaH* q = lista_busca(lst, cnt_deb);
  switch (q->tipo) {
      case COR:
      a = deb_corrente((Corrente*)q->info, valor);
      break;
      case POP:
      a = deb_poupanca((Poupanca*)q->info, valor);
      break;
      case FID:
      a = deb_fidelidade((Fidelidade*)q->info, valor);
      break;
  }

  q = lista_busca(lst, cnt_cred);
  switch (q->tipo) {
      case COR:
      a = cred_corrente((Corrente*)q->info, valor);
      break;
      case POP:
      a = cred_poupanca((Poupanca*)q->info, valor);
      break;
      case FID:
      a = cred_fidelidade((Fidelidade*)q->info, valor);
      break;
  }
  printf("TRANSFERÊNCIA ENTRE CONTAS REALIZADA COM SUCESSO\n");
}

//Implementação da função Render Juros
float juros_pop (Poupanca* p, float taxa){
  printf("\nA CONTA ESTÁ REDENDO JUROS\n");
  p->saldo = p->saldo + (p->saldo * taxa);
  return p->saldo;
}

float render_juros(ListaH* lst, int num, float taxa){
  ListaH* q = lista_busca(lst, num);
  float a;
  if (q->tipo == POP){
    a = juros_pop((Poupanca*)q->info, taxa);
    printf("TAXA ADICIONADA AO SALDO - COM SUCESSO\n");
  }
  else{
    printf("A CONTA BUSCADA NÃO É UMA CONTA POUPANÇA\n");
  }
  return a;
}

//Implementação de busca saldo
float saldo_corente(Corrente* c){
  return c->saldo;
}

float saldo_poupanca(Poupanca* c){
  return c->saldo;
}

float saldo_fidelidade(Fidelidade* c){
  return c->saldo;
}

float busca_saldo (ListaH* lst, int num){
  ListaH* q = lista_busca(lst, num);
  float a;
  switch (q->tipo) {
      case COR:
      a = saldo_corente((Corrente*)q->info);
      break;
      case POP:
      a = saldo_poupanca((Poupanca*)q->info);
      break;
      case FID:
      a = saldo_fidelidade((Fidelidade*)q->info);
      break;
  }
  return a;
}

void lista_imprime(ListaH* lst){
  ListaH* p;
  for (p = lst; p != NULL; p = p->prox){
    float a;
    switch (p->tipo) {
        case COR:
        a = saldo_corente((Corrente*)p->info);
        printf("\nNUMERO = %d\n", p->numero);
        printf("SALDO = R$ %.2f\n", a);
        break;
        case POP:
        a = saldo_poupanca((Poupanca*)p->info);
        printf("\nNUMERO = %d\n", p->numero);
        printf("SALDO = R$ %.2f\n", a);
        break;
        case FID:
        a = saldo_fidelidade((Fidelidade*)p->info);
        printf("\nNUMERO = %d\n", p->numero);
        printf("SALDO = R$ %.2f\n", a);
        break;
    }
  }
  printf("\nFim\n");
}

void lista_libera (ListaH* lst){
  ListaH* p = lst;
  while (p != NULL) {
    ListaH* t = p->prox;   /* guarda referência para opróximo elemento */
    free(p);              /* libera a memória apontada por p */
    p = t;                /* faz p apontar para o próximo */
  }
}
