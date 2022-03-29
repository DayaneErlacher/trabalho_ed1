#include "terminal.h"
#include "roteador.h"
#include "arquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct terminal {
    int identificador;
    char* nome;
    char* localizacao;
    Roteador* roteador;
};

Terminal* criarTerminal (int identificador, char* nome, char* localizacao) {
    Terminal* term = (Terminal*) malloc (sizeof(Terminal));
    term->identificador = identificador;
    term->nome = ajustaNome(nome);
    if(term->nome == NULL)
        return NULL;
    term->localizacao = ajustaNome(localizacao);
    if(term->nome == NULL)
        return NULL;
    term->roteador = NULL;
    return term;
}

void conectaTerminal (Terminal* term, Roteador* rot) {
    if (term == NULL || rot == NULL) {
        escreveArquivoLog(COMMAND_NCONECTATERMINAL);
        return;
    }
    term->roteador = rot;
}

void desconectaTerminal (Terminal* term) {
    if (term == NULL) {
        escreveArquivoLog(COMMAND_NDESCONECTATERMINAL);
        return;
    }
    term->roteador = NULL;
}

void imprimeTerminal (Terminal* term) {
    if(term->roteador != NULL)
        printf("Terminal: %s, identificador: %d, localizacao: %s, conectado ao roteador: %s.\n", term->nome, term->identificador, term->localizacao, retornaNomeRot(term->roteador));
    else
        printf("Terminal: %s, identificador: %d, localizacao: %s, conectado ao roteador: nenhum.\n", term->nome, term->identificador, term->localizacao);
}

char* retornaNomeTerm (Terminal* term) {
    return term->nome;
}

char* retornaLocalizacaoTerm (Terminal* term) {
    return term->localizacao;
}

Roteador* retornaRoteadorTerm (Terminal* term) {
    return term->roteador;
}

char* enviaPacotesDados(Terminal* term1, Terminal* term2)
{
    if (term1 == NULL || term2 == NULL) {
        escreveArquivoLog(COMMAND_NENVIARPACOTESDADOS);
        return "NAO";
    }

    if (term1->roteador == NULL || term2->roteador == NULL) 
        return "NÃO";

    ListaRot* conferidos = inicListaRot();
    StackRot* proxs = inicStackRot();
    CelRot* c;      // celula para andar no netmap
    CelRot* temp;

    // roteador "variavel"
    Roteador* rot_v = term1->roteador;
    // roteador para comparacao;
    Roteador* rot_df = term2->roteador;

    if(rot_v == rot_df)
    {
        liberaListaRot(conferidos, NAO_LIBERAROT);
        liberaStack(proxs);
        return "SIM";  
    }

    if(retornaPrimCelRot(retornaEnlaces(rot_v)) == NULL) 
    {
        liberaListaRot(conferidos, NAO_LIBERAROT);
        liberaStack(proxs);
        return "NAO";
    }    
    c = retornaPrimCelRot(retornaEnlaces(rot_v));
    cadastraRoteador(conferidos, rot_v, ENVIA_PACOTES);
    while(c != NULL)
    {
        rot_v = retornaRoteadordeCel(c);
        if(rot_v == rot_df)
        {
            liberaListaRot(conferidos, NAO_LIBERAROT);
            liberaStack(proxs);
            return "SIM";  
        }
        if(retornaProxCelRot(c) != NULL)
        {
            temp = retornaProxCelRot(c);
            while((temp != NULL) && listado(conferidos,retornaRoteadordeCel(temp)) && (retornaRoteadordeCel(temp) != NULL) ) {
                temp = retornaProxCelRot(temp);
            }
            if(temp != NULL) {
                push(proxs, temp);
            }

        }

        cadastraRoteador(conferidos, rot_v, ENVIA_PACOTES);

        if((retornaPrimCelRot(retornaEnlaces(rot_v)) == NULL))
        { 
            c = pop(proxs);
            break;
        }

        c = retornaPrimCelRot(retornaEnlaces(rot_v));

        while(listado(conferidos, retornaRoteadordeCel(c)))
        {
            c = retornaProxCelRot(c);
            if(c == NULL)
            {          
                c = pop(proxs);                
                break;                
            }
        }        
    }
    liberaListaRot(conferidos, NAO_LIBERAROT);
    liberaStack(proxs);
    return "NAO";
}

void liberaTerminal (Terminal* term) {
    if (term == NULL) {
        escreveArquivoLog(COMMAND_NREMOVEROTEADOR);
        return;
    }
    free(term->nome);
    free(term->localizacao);
    free(term);
}