#ifndef TERMINAL_H_
#define TERMINAL_H_
#include "roteador.h"
#include "stackRot.h"

//Tipo terminal (tipo opaco)
typedef struct terminal Terminal;

/*Cria um terminal 
 * inputs: identificador, ponteiro para nome e ponteiro para localização 
 * output: ponteiro para a terminal criado
 * pre-condicao: nenhum
 * pos-condicao: terminal criado
 */
Terminal* criarTerminal (int identificador, char* nome, char* localizacao);

/*Conecta terminal ao roteador 
 * inputs: terminal e roteador
 * output: nenhum
 * pre-condicao: terminal e roteador criados
 * pos-condicao: terminal com ponteiro para roteador 
 */
void conectaTerminal (Terminal* term, Roteador* rot);

/*Desconecta terminal do roteador 
 * inputs: terminal 
 * output: nenhum
 * pre-condicao: terminal criado
 * pos-condicao: terminal com ponteiro para NULL 
 */
void desconectaTerminal (Terminal* term);

/*Imprime valores do terminal
 * inputs: terminal 
 * output: nenhum
 * pre-condicao: terminal criado
 * pos-condicao: nenhuma
 */
void imprimeTerminal (Terminal* term);

/*Retorna ponteiro para nome do terminal
 * inputs: terminal 
 * output: ponteiro para nome
 * pre-condicao: terminal criado
 * pos-condicao: nenhuma
 */
char* retornaNomeTerm (Terminal* term);

/*Retorna ponteiro para localização do terminal
 * inputs: terminal 
 * output: ponteiro para localização
 * pre-condicao: terminal criado
 * pos-condicao: nenhuma
 */
char* retornaLocalizacaoTerm (Terminal* term);

/*Retorna roteador conectado ao terminal
 * inputs: terminal 
 * output: roteador
 * pre-condicao: terminal criado
 * pos-condicao: nenhuma
 */
Roteador* retornaRoteadorTerm (Terminal* term);

/*Verifica se existe alguma conexão entre term1 e term2
 * inputs: terminal de origem e terminal de destino 
 * output: char contendo "SIM" se existe conexão e "NÃO" se não existe
 * pre-condicao: terminais criados
 * pos-condicao: nenhuma
 */
char* enviaPacotesDados(Terminal* term1, Terminal* term2);

/*Libera memória alocada para o terminal
 * inputs: terminal
 * output: nenhum
 * pre-condicao: terminal criado
 * pos-condicao: toda a memória alocada para terminal foi liberada
 */
void liberaTerminal (Terminal* term);

#endif