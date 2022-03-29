#ifndef LISTAROT_H_
#define LISTAROT_H_

#include <stdio.h>

#define LIBERAROT       0
#define NAO_LIBERAROT   1

#define ENVIA_PACOTES 1
#define CONECTAROT 1
#define DEFAULT 0

//Tipo celula roteador (tipo opaco)
typedef struct celRot CelRot;
//Tipo lista Roteador (tipo opaco)
typedef struct listaRot ListaRot;

#include "roteador.h"

/*Inicializa uma lista
 * inputs: nenhum
 * output: lista inicializada
 * pre-condicao: nenhum
 * pos-condicao: lista inicializada pronta para a inserção de roteadores
 */
ListaRot* inicListaRot(void);

/*Insere roteador na lista
 * inputs: lista e roteador
 * output: um inteiro de valor 1 a função executou corretamente e 0 caso não
 * pre-condicao: lista e roteador inicializados
 * pos-condicao: lista com roteador inserido
 */
int cadastraRoteador(ListaRot* lista, Roteador* rot, int id);

/*Imprime a lista completa
 * inputs: lista
 * output: nenhum
 * pre-condicao: lista inicializada
 * pos-condicao: nenhuma
 */
void imprimeListaRot(ListaRot* lista);

/*Imprime enlace
 * inputs: lista
 * output: nenhum
 * pre-condicao: lista inicializada
 * pos-condicao: nenhuma
 */
void imprimeEnlaces(ListaRot* lista);

/*Imprime os enlaces dos roteadores no arquivo saida.dot
 * inputs: lista
 * output: nenhum
 * pre-condicao: lista inicializada
 * pos-condicao: nenhuma
 */
void imprimeConexaoListaRoteador(ListaRot* lista);

/*Procura roteador na lista correspondente ao nome chave
 * inputs: lista e ponteiro para chave
 * output: celula do roteador
 * pre-condicao: lista criada
 * pos-condicao: nenhuma
 */
CelRot* procuraRoteador(ListaRot* lista, char* chave);

/*Retorna roteador da lista correspondente ao nome chave
 * inputs: lista, ponteiro para chave e id (DEFAULT = imprime log de erro, caso ocorra)
 * output: roteador
 * pre-condicao: lista criada
 * pos-condicao: nenhuma
 */
Roteador* retornaRoteador(ListaRot* lista, char* chave, int id);

/*Retorna roteador da celula
 * inputs: terminal 
 * output: roteador
 * pre-condicao: terminal criado
 * pos-condicao: nenhuma
 */
Roteador* retornaRoteadordeCel(CelRot* cel);

/*Retira roteador da lista por chave
 * inputs: lista e ponteiro para nome do roteador 
 * output: lista com elemento retirado
 * pre-condicao: lista inicializada
 * pos-condicao: lista sem roteador especificado
 */
Roteador* retiraRoteador(ListaRot* lista, char* chave);

/*Retorna primeira celula da lista
 * inputs: lista 
 * output: primeira celula da lista
 * pre-condicao: lista criada
 * pos-condicao: nenhuma
 */
CelRot* retornaPrimCelRot(ListaRot* lista);

/*Retorna a celula do próximo roteador
 * inputs: celula  
 * output: celula
 * pre-condicao: celula criada
 * pos-condicao: nenhuma
 */
CelRot* retornaProxCelRot(CelRot* cel);

/*Busca se o roteador esta na lista
 * inputs: lista e roteador  
 * output: inteiro (1 = pertece, 0 = não pertece)
 * pre-condicao: lista e roteador criados
 * pos-condicao: nenhuma
 */
int listado(ListaRot* lista, Roteador* rot);

/*Conta quantas vezes a operadora se repete
 * inputs: lista e ponteiro para operadora
 * output: número de vezes
 * pre-condicao: lista criada
 * pos-condicao: nenhuma
 */
int frequenciaOperadora(ListaRot* lista, char* operadora);

/*Libera memória alocada para a lista e para os roteadores
 * inputs: lista
 * output: nenhum
 * pre-condicao: lista inicializada
 * pos-condicao: toda a memória alocada para a lista e seus roteadores liberados
 */
void liberaListaRot(ListaRot* lista, int liberacao);

#endif