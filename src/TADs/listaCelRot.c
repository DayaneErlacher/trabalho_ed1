#include "listaCelRot.h"

struct celcelrot
{
    CelRot* celrot;
    CelCelRot* prox;
};

struct listacelrot
{
    CelCelRot* prim;
    CelCelRot* ult;
};

ListaCelRot* inicListaCelRot(void)
{
    ListaCelRot* lista = (ListaCelRot*) malloc(sizeof(ListaCelRot));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereCelRot(ListaCelRot* lista, CelRot* cel)
{
    CelCelRot* nova = (CelCelRot*)malloc(sizeof(CelCelRot));
    nova->celrot = cel;
    nova->prox = NULL;
    if(lista->prim == NULL && lista->ult == NULL)
    {
        lista->ult = lista->prim = nova;
        return;
    }
    lista->ult->prox = nova;
    lista->ult = nova;
}

CelRot* retiraCelRot(ListaCelRot* lista)
{
    CelCelRot *cel, *aux;
    CelRot *celrot;

    if(lista->prim == NULL)
    {
        return NULL;
    }
    if(lista->prim == lista->ult)
    {
        cel = lista->prim;
        lista->prim = lista->ult = NULL;
        celrot = cel->celrot;
        free(cel);
        return celrot;
    }
    cel = lista->prim;
    while(cel->prox != lista->ult)
    {
        cel = cel->prox; //pegando a penultima posição
    }
    aux = lista->ult;
    lista->ult = cel;

    celrot = aux->celrot;

    free(aux);
    return celrot;
} 

/* void liberaListaCelRot(ListaCelRot* lista)
{
    CelCelRot* p = lista->prim;
    CelCelRot* t;
    
    while(p != NULL)
    {
        t = p->prox;
        free(p);
        p = t;
    }
    
    free(lista);
} */

void liberaListaCelRot(ListaCelRot* lista)
{
    CelCelRot* p = lista->prim;
    CelCelRot* t;
    CelRot* teste = retiraCelRot(lista);

    while(teste != NULL)
        teste = retiraCelRot(lista);
    
    free(lista);
}