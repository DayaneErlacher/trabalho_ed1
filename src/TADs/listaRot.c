#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaRot.h"
#include "roteador.h"
#include "arquivos.h"


struct celRot
{
    Roteador* rot;
    CelRot* prox;
};

struct listaRot
{
    CelRot* prim;
    CelRot* ult;
};

ListaRot* inicListaRot(void)
{
    ListaRot* lista = (ListaRot*) malloc(sizeof(ListaRot));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

int cadastraRoteador(ListaRot* lista, Roteador* rot, int id)
{
    if(procuraRoteador(lista, retornaNomeRot(rot)) != NULL && id != 1) {
        escreveArquivoLog1variavel(COMMAND_NAOCADASTRADO, retornaNomeRot(rot));
        return 0;
    }
    CelRot* nova = (CelRot*)malloc(sizeof(CelRot));
    nova->rot = rot;
    nova->prox = NULL;
    if(lista->prim == NULL && lista->ult == NULL)
    {
        lista->ult = lista->prim = nova;
        return 1;
    }
    lista->ult->prox = nova;
    lista->ult = nova;
    return 1;
}

Roteador* retornaRoteador(ListaRot* lista, char* chave, int id)
{
    CelRot* p = procuraRoteador(lista, chave);

    if(p == NULL)
    {
        if(id == DEFAULT) 
            escreveArquivoLog1variavel(COMMAND_ROTEADORNEXISTE, chave);
        return NULL;
    }

    return p->rot;
}

CelRot* procuraRoteador(ListaRot* lista, char* chave)
{
    CelRot* p = lista->prim;
    CelRot* ant = NULL;

    while((p!=NULL) && strcmp(chave, retornaNomeRot(p->rot)))
    {
        ant = p;
        p = p->prox;
    }
    return p;
}

Roteador* retornaRoteadordeCel(CelRot* cel)
{
    return cel->rot;
}

Roteador* retiraRoteador(ListaRot* lista, char* chave)
{
    CelRot* p = lista->prim;
    Roteador* roteador;
    CelRot* ant = NULL;

    while((p!=NULL) && strcmp(chave, retornaNomeRot(p->rot)))
    {
        ant = p;
        p = p->prox;
    }

    if(p == NULL) 
        return NULL;

    roteador = p->rot;

    // confere se é o unico
    if((p == lista->prim) && (p == lista->ult))
    {
        lista->prim = lista->ult = NULL;
    }
    else if(p == lista->prim)   // se é o primeiro
    {
        lista->prim = p->prox;
    }
    else if(p == lista->ult)     // se é o ultimo de
    {
        lista->ult = ant;
        lista->ult->prox = NULL;
    }
    else
    {
        ant->prox = p->prox;
    }
    
    free(p);

    return roteador;
}

void imprimeListaRot(ListaRot* lista)
{
    CelRot* p;  // ponteiro auxiliar

    printf("\nLista de Roteadores:\n\n");
    for(p = lista->prim; p != NULL; p = p->prox)
    {
        imprimeRoteador(p->rot);
    }  

    if(lista->prim == NULL)
    {
        printf("\tEsta lista esta vazia!\n");
    }
    
}

void imprimeEnlaces(ListaRot* lista)
{
    CelRot* p;  // ponteiro auxiliar

    for(p = lista->prim; p != NULL; p = p->prox)
    {
        printf("\tRoteador id: %d   -   nome: %s   -   operadora: %s\n", retornaIDRot(p->rot), retornaNomeRot(p->rot), retornaOperadora(p->rot));
    }  

    if(lista->prim == NULL)
    {
        printf("Esta lista esta vazia!\n");
    }
    
}

void imprimeConexaoListaRoteador(ListaRot* lista)
{
    CelRot *p, *penlace;
    char* nome;
    char* rotEnlace;
    ListaRot* enlaces;

    FILE* saida = fopen(SAIDA_DOT_PATH, "a");
    if(saida == NULL) {
        printf("Error ao abrir arquivo. \n");
        exit(1);
    }
    p = lista->prim;

    while(p!= NULL)
    {
        
        enlaces = retornaEnlaces(p->rot);
        
        if(enlaces == NULL)
        {
            fprintf(saida,"\t%s;", retornaNomeRot(p->rot));
            p = p->prox;
            break;
        }
        else
        {
            penlace = enlaces->prim;
        }
        
        while(penlace != NULL)
        {
            fprintf(saida,"\t%s", retornaNomeRot(p->rot));
            fprintf(saida," -- ");
            fprintf(saida, "%s", retornaNomeRot(penlace->rot));
            penlace = penlace->prox;
            fprintf(saida,";\n");
        }        
        p = p->prox;
        
    }
    fprintf(saida,"}\n");
    fclose(saida); 
}

CelRot* retornaPrimCelRot(ListaRot* lista)
{
    return lista->prim;
}

CelRot* retornaProxCelRot(CelRot* cel)
{
    return cel->prox;
}

int listado(ListaRot* lista, Roteador* rot)
{
    CelRot* p = lista->prim;
    while(p != NULL)
    {
        if(p->rot == rot)
        {
            return 1;
        }
        p = p->prox;
    }
    return 0;
}
int frequenciaOperadora(ListaRot* lista, char* operadora)
{
    CelRot* p = lista->prim;
    int freq = 0;

    while(p != NULL)
    {
        if(!strcmp(operadora, retornaOperadora(p->rot)))
        {
            freq++;
        }
        p = p->prox;
    }

    return freq;
}


void liberaListaRot(ListaRot* lista, int liberacao)
{
    CelRot* p = lista->prim;
    CelRot* t;
    
    while(p != NULL)
    {
        t = p->prox;
        if(liberacao == LIBERAROT)
            liberaRoteador(p->rot);
        free(p);        
        p = t;
    }
    
    free(lista);
}