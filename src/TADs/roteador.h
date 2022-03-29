#ifndef ROTEADOR_H_
#define ROTEADOR_H_

//Tipo roteador (tipo opaco)
typedef struct roteador Roteador;

#include "listaRot.h"

/*Cria um roteador 
 * inputs: identificador, ponteiro para nome e ponteiro para operadora 
 * output: ponteiro para a roteador criado
 * pre-condicao: nenhum
 * pos-condicao: roteador criado
 */
Roteador* criaRoteador(int identificador, char* nome, char* operadora);

/*Conecta roteadores um ao outro 
 * inputs: 2 roteadores 
 * output: nenhum
 * pre-condicao: roteadores criados
 * pos-condicao: cada roteador com o outro adicionado a sua lista de enlaces
 */
void conectaRoteadores(Roteador* rot1, Roteador* rot2);

/*Desconecta roteadores
 * inputs: 2 roteadores 
 * output: nenhum
 * pre-condicao: roteadores criados
 * pos-condicao: cada roteador sem o outro na sua lista de enlaces
 */
void desconectaRoteadores(Roteador* rot1, Roteador* rot2);

/*Imprime valores do roteador
 * inputs: roteador 
 * output: nenhum
 * pre-condicao: roteador criado
 * pos-condicao: nenhuma
 */
void imprimeRoteador(Roteador* rot);

/*Retorna ponteiro para nome do roteador
 * inputs: roteador 
 * output: ponteiro para nome
 * pre-condicao: roteador criado
 * pos-condicao: nenhuma
 */
char* retornaNomeRot (Roteador* rot);

/*Retorna identificador do roteador
 * inputs: roteador 
 * output: identificador
 * pre-condicao: roteador criado
 * pos-condicao: nenhuma
 */
int retornaIDRot (Roteador* rot);

/*Retorna ponteiro para operadora do roteador
 * inputs: roteador 
 * output: ponteiro para operadora
 * pre-condicao: roteador criado
 * pos-condicao: nenhuma
 */
char* retornaOperadora(Roteador* rot);

/*Retorna lista de enlaces do roteador
 * inputs: roteador 
 * output: lista de enlaces
 * pre-condicao: roteador criado
 * pos-condicao: nenhuma
 */
ListaRot* retornaEnlaces(Roteador* rot);

/*Libera memória alocada para o roteador
 * inputs: roteador
 * output: nenhum
 * pre-condicao: roteador criado
 * pos-condicao: toda a memória alocada para roteador foi liberada
 */
void liberaRoteador (Roteador* rot);

/*Retira acentos da string
 * inputs: ponteiro para nome
 * output: sring sem acentos
 * pre-condicao: nenhum
 * pos-condicao: nova string criada utilizando entrada mas sem acentos
 */
char* ajustaNome(char* nome);

#endif