#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arquivos.h"

void inicializaArquivos(void) {
    FILE* log = fopen(LOG_PATH, "w");
    FILE* saida = fopen(SAIDA_TXT_PATH, "w");
    FILE* dot = fopen(SAIDA_DOT_PATH, "w");

    if (log == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    fclose(log);

    if (saida == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    fclose(saida);

    if (dot == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    fclose(dot);
}

void escreveArquivoLog(char* mensagem)
{
    FILE* log = fopen(LOG_PATH, "a");
    if(log == NULL) {
        printf("Error ao abrir arquivo. \n");
        exit(1);
    }
    fprintf(log, "%s", mensagem);
    fclose(log); 
}

void escreveArquivoLog1variavel(char* mensagem, char* s)
{
    FILE* log = fopen(LOG_PATH, "a");
    if(log == NULL) {
        printf("Error ao abrir arquivo. \n");
        exit(1);
    }
    fprintf(log, mensagem, s);
    fclose(log); 
}

void imprimeNetMap(ListaRot* lista_roteadores, ListaTerm* lista_terminais) 
{
    imprimeConexaoListaTerminal(lista_terminais); 
    imprimeConexaoListaRoteador(lista_roteadores);
}

void escreveArquivoSaida2variaveis(char* mensagem, char* s, int num)
{
    FILE* log = fopen(SAIDA_TXT_PATH, "a");
    if(log == NULL) {
        printf("Error ao abrir arquivo. \n");
        exit(1);
    }
    fprintf(log, mensagem, s, num);
    fclose(log); 
}

void escreveArquivoSaida3variaveis(char* mensagem, char* s1, char* s2, char* s3)
{
    FILE* log = fopen(SAIDA_TXT_PATH, "a");
    if(log == NULL) {
        printf("Error ao abrir arquivo. \n");
        exit(1);
    }
    fprintf(log, mensagem, s1,s2,s3);
    fclose(log); 
}