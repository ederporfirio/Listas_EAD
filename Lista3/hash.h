//Estrutura de Dados Avançados
//Prof. José Maria
//Aluno Eder Porfírio
//
//Lista de Exercícios - Lista 3

//hash.h

//Definiçao dos Tipos
typedef struct cliente Cliente;
typedef struct hash Hash;

//Declaração das funções Hash
static int hashDivisao (int cod, int tam);
static int hashMultiplicacao(int cod, int tam);
static int hashDobra (int cod, int tam);


Hash* criaHash (int tam);

Hash* liberaHash (Hash* ha);

Cliente* buscaHash (Hash* ha , int cod);

Hash* insereHash (Hash* ha , int cod, char* nome);

void retiraHash (Hash* ha , int cod);
