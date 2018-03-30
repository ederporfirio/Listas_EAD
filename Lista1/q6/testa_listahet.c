//Lista de Exercícios
//Professor José Maria
//Eder Jacques Porfirio Farias

// Lista 1 - Questão 6

//Programa Principal

#include <stdio.h>
#include "listahet.c"


int main (void){

  ListaH* lst;
  lst = lista_cria();

  //Insere Elementos
  lst = cria_corrente (lst, 93.00);
  lst = cria_poupanca (lst, 45.00);
  lst = cria_fidelidade (lst, 560.00);

  //lst = lista_busca (lst, 1);
  //printf("ENCONTRA CONTA NÚMERO: %d\n", lst->numero);
  //printf("TIPO: %d\n", lst->tipo);
  //float saldo_atual = efetua_credito(lst, 1, 50.00);
  //printf("%f\n", saldo_atual);
  float s1;
  s1 = efetua_credito(lst, 2, 50.00);
  s1 = efetua_debido (lst, 1, 20.00);

  s1 = efetua_bonus(lst, 3);
  transferencia_contas(lst, 1, 3, 10.00);

  float s2 = render_juros(lst, 2, 0.01);

  //Retornar saldo
  float s3;
  s3 = busca_saldo(lst, 3);
  printf("\nSALDO: R$ %.2f\n", s3);

  lista_imprime (lst);
  lista_libera(lst);
  return 0;
}
