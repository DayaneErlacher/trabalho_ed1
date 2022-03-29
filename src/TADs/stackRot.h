#ifndef STACK_H_
#define STACK_H_

#include "roteador.h"
#include "listaRot.h"

#define START_ID -99

//Tipo stackrot (tipo opaco)
typedef struct stackrot StackRot;
//Tipo idrot (tipo opaco)
typedef struct idrot IdRot;

/*Inicializa uma lista
 * inputs: nenhum
 * output: lista inicializada
 * pre-condicao: nenhum
 * pos-condicao: lista inicializada pronta para a inserção de celulas
 */
StackRot* inicStackRot(void);

/*Insere celula de roteadores na lista
 * inputs: lista e celula de roteadores
 * output: nenhum
 * pre-condicao: lista e celula de roteadores inicializados
 * pos-condicao: lista com celula de roteadores inserido
 */
void push(StackRot* s, CelRot* cel);

/*Retira a última celula de roteadores da lista
 * inputs: lista 
 * output: lista com elemento retirado
 * pre-condicao: lista inicializada
 * pos-condicao: lista sem celula de roteadores especificado
 */
CelRot* pop(StackRot* s);

/*Imprime a lista completa
 * inputs: lista
 * output: nenhum
 * pre-condicao: lista inicializada
 * pos-condicao: nenhuma
 */
void imprimeStack(StackRot* s);

/*Libera memória alocada para a lista e para os roteadores
 * inputs: lista
 * output: nenhum
 * pre-condicao: lista inicializada
 * pos-condicao: toda a memória alocada para a lista e seus roteadores liberada
 */
void liberaStack(StackRot* s);

#endif