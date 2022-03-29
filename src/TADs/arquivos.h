#ifndef ARQUIVOS_H_
#define ARQUIVOS_H_

#include "listaRot.h"
#include "listaTerm.h"


// #define LOG_PATH "../../output/log.txt"
// #define SAIDA_TXT_PATH  "../../output/saida.txt"
// #define SAIDA_DOT_PATH  "../../output/saida.dot"
#define LOG_PATH "./output/log.txt"
#define SAIDA_TXT_PATH  "./output/saida.txt"
#define SAIDA_DOT_PATH  "./output/saida.dot"

/*
* COMANDOS PARA O ARQUIVO LOG.TXT
*/
#define COMMAND_ENTRADANESCONTRADA "Erro: Arquivo de entrada não encontrado na pasta input\n"
#define COMMAND_NIDENT "Erro: Comando não identificado - %s\n"
#define COMMAND_NAOCADASTRADO "Erro: Roteador %s não cadastrado pois já existe no NetMap\n"
#define COMMAND_ROTEADORNEXISTE "Erro: Roteador %s inexistente no NetMap\n"
#define COMMAND_TERMINALNAOCADASTRADO "Erro: Terminal %s não cadastrado pois já existe no NetMap\n"
#define COMMAND_TERMINALNEXISTE "Erro: Terminal %s inexistente no NetMap\n"
#define COMMAND_NCONECTAROTEADORES "Erro: Não foi possível executar CONECTAROTEADORES\n"
#define COMMAND_NDESCONECTAROTEADORES "Erro: Não foi possível executar DESCONECTAROTEADORES\n"
#define COMMAND_NREMOVEROTEADOR "Erro: Não foi possível executar REMOVEROTEADOR\n"
#define COMMAND_NCONECTATERMINAL "Erro: Não foi possível executar CONECTATERMINAL\n"
#define COMMAND_NDESCONECTATERMINAL "Erro: Não foi possível executar DESCONECTATERMINAL\n"
#define COMMAND_NENVIARPACOTESDADOS "Erro: Não foi possível executar ENVIARPACOTESDADOS\n"
#define COMMAND_NOMECOMPOSTO "Erro: Não são aceitos nomes compostos\n"
#define COMMAND_NOMEACENTUADO "Erro: Entrada textual composta apenas por letras acentuadas\n"
#define COMMAND_ROTEADORESCONECTADOS "Erro: Os dois roteadores escolhidos já estão conectados\n"

/*
* COMANDOS PARA O ARQUIVO SAIDA.TXT
*/
#define COMMAND_FREQUENCIAOPERADORA "FREQUENCIAOPERADORA %s: %d\n"
#define COMMAND_FREQUENCIATERMINAL "FREQUENCIATERMINAL %s: %d\n"
#define COMMAND_ENVIAPACOTEDADOS "ENVIAPACOTEDADOS %s %s: %s\n"

/*Exclue arquivos existentes e cria novos 
 * inputs: nenhum
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: nenhum
 */
void inicializaArquivos(void);

/* Escreve no arquivo log.txt a mensagem
 * inputs: ponteiro para mensagem
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: nenhum
 */
void escreveArquivoLog(char* mensagem);

/* Escreve no arquivo log.txt a mensagem utilizando 1 variavel
 * inputs: ponteiro para mensagem e ponteiro para variavel
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: nenhum
 */
void escreveArquivoLog1variavel(char* mensagem, char* s);

/* Escreve no arquivo saida.txt a mensagem utilizando 2 variaveis
 * inputs: ponteiro para mensagem e ponteiro para variaveis
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: nenhum
 */
void escreveArquivoSaida2variaveis(char* mensagem, char* s, int num);

/* Escreve no arquivo saida.txt a mensagem utilizando 3 variaveis
 * inputs: ponteiro para mensagem e ponteiro para variaveis
 * output: nenhum
 * pre-condicao: nenhum
 * pos-condicao: nenhum
 */
void escreveArquivoSaida3variaveis(char* mensagem, char* s1, char* s2, char* s3);

/* Imprime conexão do netMap no arquivo saida.dot
 * inputs: lista de roteadores e terminais cadastrados
 * output: saida.dot preenchido
 * pre-condicao: nenhum
 * pos-condicao: nenhum
 */
void imprimeNetMap(ListaRot* lista_roteadores, ListaTerm* lista_terminais);

#endif