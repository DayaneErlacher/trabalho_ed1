
#include "stackRot.h"
#include "roteador.h"
#include "listaCelRot.h"
#include "stdlib.h"


struct stackrot
{
    ListaCelRot* lista;
};


StackRot* inicStackRot()
{
    StackRot* s = (StackRot*) malloc(sizeof(StackRot));
    s->lista = inicListaCelRot();
    return s;
}

void push(StackRot* s, CelRot* cel)
{
    insereCelRot(s->lista, cel);
}

CelRot* pop(StackRot* s)
{
    return(retiraCelRot(s->lista));
}


void liberaStack(StackRot* s)
{
    liberaListaCelRot(s->lista);
    free(s);
}