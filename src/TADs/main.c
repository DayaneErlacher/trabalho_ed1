#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaRot.h"
#include "listaTerm.h"
#include "arquivos.h"

#define ENTRADA_PATH    "./input/entrada.txt"
#define MAXLINELENGTH   300
#define MAXNPARAMETERS  5

void separaLinha(char** tokens, char* line);

int main()
{
    /************************************************************
    *                  LISTA E VARIÁVEIS BÁSICAS
    ************************************************************/ 
    ListaRot* lista_roteadores = inicListaRot();
    ListaTerm* lista_terminais = inicListaTerm();
    Roteador* roteador;
    Terminal* terminal;
    int numRoteadores = 1, numTerminais = 1;

    
    /************************************************************
    *               MANIPULAÇÃO DE ARQUIVO ENTRADA
    ************************************************************/ 
    inicializaArquivos();
    FILE* entrada = fopen(ENTRADA_PATH, "r");
    if (entrada == NULL) {
        escreveArquivoLog(COMMAND_ENTRADANESCONTRADA);
        exit(1);
    }
    
    /************************************************************
    *                  VARIAVEIS PARA LEITURA DO TXT
    ************************************************************/ 
    char* linha = NULL;
    char* nome;
    size_t len = 0;
    ssize_t read = 0;
    // vetor de strings (MAXNUMPARAM é o numero máximo de parametros da entrada)
    char** token_holder = (char**) malloc(sizeof(char*)*(MAXNPARAMETERS));
    int i = 0;
    while(i<MAXNPARAMETERS)
    {
        token_holder[i] = NULL;
        i++;
    }
    
    // pega linha por linha e armazena
    while(getline(&linha, &len, entrada) != -1)
    {
        separaLinha(token_holder, linha); //separa cada string em uma posição
        
        /************************************************************
        *                  CADASTRAROTEADOR
        ************************************************************/ 
        if (strcmp(token_holder[0], "CADASTRAROTEADOR") == 0) {
            if(token_holder[3] != NULL) 
                escreveArquivoLog(COMMAND_NOMECOMPOSTO);
            else {
                roteador = criaRoteador(numRoteadores, token_holder[1], token_holder[2]);
                if(roteador == NULL) {
                     escreveArquivoLog(COMMAND_NOMEACENTUADO);
                } else {
                    if (cadastraRoteador(lista_roteadores, roteador, DEFAULT) == 1)
                        numRoteadores++;
                }
            }
        
        /************************************************************
        *                  CADASTRATERMINAL
        ************************************************************/ 
        } else if (strcmp(token_holder[0], "CADASTRATERMINAL") == 0) {
            if(token_holder[3] != NULL) 
                escreveArquivoLog(COMMAND_NOMECOMPOSTO);
            else {
                terminal = criarTerminal(numTerminais, token_holder[1], token_holder[2]);
                if(terminal == NULL)  {
                     escreveArquivoLog(COMMAND_NOMEACENTUADO);
                } else {
                    if(cadastrarTerminal(lista_terminais, terminal) == 1) 
                        numTerminais++;
                }
            }
        
        /************************************************************
        *                  CONECTAROTEADORES
        ************************************************************/
        } else if (strcmp(token_holder[0], "CONECTAROTEADORES") == 0) {
            conectaRoteadores(retornaRoteador(lista_roteadores, token_holder[1], DEFAULT), retornaRoteador(lista_roteadores, token_holder[2], DEFAULT));
        
        /************************************************************
        *                  CONECTATERMINAL
        ************************************************************/
        } else if (strcmp(token_holder[0], "CONECTATERMINAL") == 0) {
            conectaTerminal(retornaTerminal(lista_terminais, token_holder[1]), retornaRoteador(lista_roteadores, token_holder[2], DEFAULT));
        
        /************************************************************
        *                  DESCONECTAROTEADORES
        ************************************************************/
        } else if (strcmp(token_holder[0], "DESCONECTAROTEADORES") == 0) {
            desconectaRoteadores(retornaRoteador(lista_roteadores, token_holder[1], DEFAULT), retornaRoteador(lista_roteadores, token_holder[2], DEFAULT));
        
        /************************************************************
        *                  ENVIARPACOTESDADOS
        ************************************************************/
        } else if (strcmp(token_holder[0], "ENVIARPACOTESDADOS") == 0) {
            escreveArquivoSaida3variaveis(COMMAND_ENVIAPACOTEDADOS, token_holder[1], token_holder[2], enviaPacotesDados(retornaTerminal(lista_terminais, token_holder[1]), retornaTerminal(lista_terminais, token_holder[2])));
        
        /************************************************************
        *                  REMOVEROTEADOR
        ************************************************************/
        } else if (strcmp(token_holder[0], "REMOVEROTEADOR") == 0) {
            desconectaRoteadorConectado(lista_terminais, retornaRoteador(lista_roteadores, token_holder[1], DEFAULT));
            liberaRoteador(retiraRoteador(lista_roteadores, token_holder[1])); 
        
        /************************************************************
        *                  REMOVETERMINAL
        ************************************************************/
        } else if (strcmp(token_holder[0], "REMOVETERMINAL") == 0) {
            liberaTerminal(retiraListaTerm(lista_terminais, token_holder[1]));
        
        /************************************************************
        *                  DESCONECTATERMINAL
        ************************************************************/
        } else if (strcmp(token_holder[0], "DESCONECTATERMINAL") == 0) {
            desconectaTerminal(retornaTerminal(lista_terminais, token_holder[1]));
        
        /************************************************************
        *                  FREQUENCIAOPERADORA
        ************************************************************/
        } else if (strcmp(token_holder[0], "FREQUENCIAOPERADORA") == 0) {
            escreveArquivoSaida2variaveis(COMMAND_FREQUENCIAOPERADORA, token_holder[1], frequenciaOperadora(lista_roteadores, token_holder[1]));
        
        /************************************************************
        *                  FREQUENCIATERMINAL
        ************************************************************/
        } else if (strcmp(token_holder[0], "FREQUENCIATERMINAL") == 0) {
            escreveArquivoSaida2variaveis(COMMAND_FREQUENCIATERMINAL, token_holder[1],frequenciaLocalizacao(lista_terminais, token_holder[1]));
        
        /************************************************************
        *                   IMPRIMENETMAP
        ************************************************************/
        } else if (strcmp(token_holder[0], "IMPRIMENETMAP") == 0) {
            imprimeNetMap (lista_roteadores, lista_terminais); 
        
        /************************************************************
        *                         FIM
        ************************************************************/
        } else if (strcmp(token_holder[0], "FIM") == 0) {
            break;
        } else {
            escreveArquivoLog1variavel(COMMAND_NIDENT, token_holder[0]);
        }
    }

    /************************************************************
    *      LIBERACAO DE LISTAS E FECHAMENTO DE ARQUIVOS
    ************************************************************/
    fclose(entrada);
    liberaListaTerm(lista_terminais); 
    liberaListaRot(lista_roteadores, LIBERAROT);
    free(token_holder);
    if(linha)
        free(linha);

    // apenas para informar que o programa rodou corretamente
    exit(EXIT_SUCCESS);
}

void separaLinha(char** tokens, char* line)
{
    int i = 0;
    const char delim[2] = " ";
    tokens[i] = strtok(line, delim);
    
    while(tokens[i] != NULL )
    {
        i++;
        tokens[i] = strtok(NULL, delim);
    }

    if(tokens[i-1][strlen(tokens[i-1])-1] == '\n')
    {
        tokens[i-1][strlen(tokens[i-1])-1] = '\0';
    }
    /*
    * Para funcoes com menos parametros, preeche
    * espacos vagos com NULL.
    */
    while(i < MAXNPARAMETERS)
    {        
        tokens[i] = NULL;
        i++;
    }
}
