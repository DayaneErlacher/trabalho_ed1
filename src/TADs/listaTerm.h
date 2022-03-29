#ifndef LISTATERM_H_
#define LISTATERM_H_
#include <stdio.h>
#include "terminal.h"

//Tipo lista Terminal (tipo opaco)
typedef struct listaTerm ListaTerm;
//Tipo celula terminal (tipo opaco)
typedef struct celTerm CelTerm;

/*Inicializa uma lista
 * inputs: nenhum
 * output: lista inicializada
 * pre-condicao: nenhum
 * pos-condicao: lista inicializada pronta para a inserção de terminais
 */
ListaTerm* inicListaTerm (void);

/*Insere terminal na lista
 * inputs: lista e terminal
 * output: um inteiro de valor 1 a função executou corretamente e 0 caso não
 * pre-condicao: lista e terminal inicializados
 * pos-condicao: lista com terminal inserido
 */
int cadastrarTerminal (ListaTerm* lista, Terminal* term);

/*Imprime a lista completa
 * inputs: lista
 * output: nenhum
 * pre-condicao: lista inicializada
 * pos-condicao: nenhuma
 */
void imprimeListaTerm (ListaTerm* lista);

/*Imprime os terminais e seus respectivos roteadores conectados no arquivo saida.dot
 * inputs: lista
 * output: nenhum
 * pre-condicao: lista inicializada
 * pos-condicao: nenhuma
 */
void imprimeConexaoListaTerminal (ListaTerm* lista);

/*Retorna terminal da lista correspondente ao nome chave
 * inputs: lista e ponteiro para chave
 * output: terminal
 * pre-condicao: lista criada
 * pos-condicao: nenhuma
 */
Terminal* retornaTerminal (ListaTerm* lista, char* chave);

/*Procura terminal na lista correspondente ao nome chave
 * inputs: lista e ponteiro para chave
 * output: celula do terminal
 * pre-condicao: lista criada
 * pos-condicao: nenhuma
 */
CelTerm* procuraTerminal (ListaTerm* lista, char* chave);

/*Desconecta os terminais conectados a esse roteador
 * inputs: lista e roteador 
 * output: nenhum
 * pre-condicao: lista e roteador criados
 * pos-condicao: nenhuma
 */
void desconectaRoteadorConectado (ListaTerm* lista, Roteador* rot);

/*Retira terminal da lista
 * inputs: lista e ponteiro para nome do terminal 
 * output: lista com elemento retirado
 * pre-condicao: lista inicializada
 * pos-condicao: lista sem terminal especificado
 */
Terminal* retiraListaTerm(ListaTerm* lista, char* chave);

/*Conta quantas vezes a localização (chave) se repete
 * inputs: lista e ponteiro para chave
 * output: número de vezes
 * pre-condicao: lista criada
 * pos-condicao: nenhuma
 */
int frequenciaLocalizacao (ListaTerm* lista, char* chave);

/*Libera memória alocada para a lista e para os terminais
 * inputs: lista
 * output: nenhum
 * pre-condicao: lista inicializada
 * pos-condicao: toda a memória alocada para a lista e seus terminais liberada
 */
void liberaListaTerm (ListaTerm* lista);

#endif