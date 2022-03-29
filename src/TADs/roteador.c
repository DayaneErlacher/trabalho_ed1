#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "roteador.h"
#include "arquivos.h"

struct roteador{
    int identificador;
    char* nome;
    char* operadora;
    ListaRot* enlaces; 
};

Roteador* criaRoteador(int identificador, char* nome, char* operadora) {
    Roteador* rot = (Roteador*) malloc (sizeof(Roteador));
    rot->identificador = identificador;
    rot->nome = ajustaNome(nome);
    if(rot->nome == NULL)
        return NULL;
    rot->operadora = ajustaNome(operadora);
    if(rot->operadora == NULL)
        return NULL;
    rot->enlaces = inicListaRot();
    return rot;
}

void conectaRoteadores(Roteador* rot1, Roteador* rot2)
{
    if (rot1 == NULL || rot2 == NULL) {
        escreveArquivoLog(COMMAND_NCONECTAROTEADORES);
        return;
    }
    //Se eles já estão conectados
    if(retornaRoteador(rot1->enlaces, rot2->nome, CONECTAROT) != NULL)
    {
        escreveArquivoLog(COMMAND_ROTEADORESCONECTADOS);
        return;
    }
    cadastraRoteador(rot1->enlaces, rot2, DEFAULT);
    cadastraRoteador(rot2->enlaces, rot1, DEFAULT);
}

void desconectaRoteadores(Roteador* rot1, Roteador* rot2)
{
    if (rot1 == NULL || rot2 == NULL) {
        escreveArquivoLog(COMMAND_NDESCONECTAROTEADORES);
        return;
    }
    retiraRoteador(rot1->enlaces, rot2->nome);
    retiraRoteador(rot2->enlaces, rot1->nome);
}

void imprimeRoteador(Roteador* rot)
{
    if(rot != NULL)
    {
        printf("\nRoteador id: %d   -   nome: %s   -   operadora: %s\n",
                rot->identificador,
                rot->nome,
                rot->operadora);
        printf("Lista de conexoes:\n");
        imprimeEnlaces(rot->enlaces);
    }
}

char* retornaNomeRot(Roteador* rot){
    return rot->nome;
}

char* retornaOperadora(Roteador* rot)
{
    return rot->operadora;
}

ListaRot* retornaEnlaces(Roteador* rot)
{
    return rot->enlaces;
}

int retornaIDRot(Roteador* rot)
{
    return rot->identificador;
}


void liberaRoteador(Roteador* rot)
{
    if (rot == NULL) {
        escreveArquivoLog(COMMAND_NREMOVEROTEADOR);
        return;
    }
    CelRot* atual = retornaPrimCelRot(retornaEnlaces(rot));
    CelRot* prox;
    while(atual != NULL)
    {
        prox = retornaProxCelRot(atual);
        desconectaRoteadores(rot, retornaRoteadordeCel(atual));
        atual = prox;
    }

    free(rot->nome);
    free(rot->operadora);
    liberaListaRot(rot->enlaces, NAO_LIBERAROT);
    free(rot);
}

char* ajustaNome(char* nome) {
    int len = strlen(nome);
    char* nomeAux = (char*) malloc((len+1)*sizeof(char));
    int j = 0;
    for(int i=0; i < len; i++) {
        if(( nome[i]>=32 && nome[i]<128))
        {
            nomeAux[j] = nome[i]; 
            j++;
        }        
    }
    nomeAux[j] = '\0';
    char* nomePronto = strdup(nomeAux);
    free(nomeAux);
    //TODO: testar
    if(strlen(nomePronto) == 0) //caso toda a palavra seja acentuada
        return NULL;
    return nomePronto;
} 
