#include "listaTerm.h"
#include "arquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celTerm
{
    Terminal* term;
    CelTerm* prox;
};

struct listaTerm {
    CelTerm* prim;
    CelTerm* ult;
};

ListaTerm* inicListaTerm (void){
    ListaTerm* lista = (ListaTerm*) malloc (sizeof(ListaTerm));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

int cadastrarTerminal (ListaTerm* lista, Terminal* term){
    if(procuraTerminal(lista, retornaNomeTerm(term)) != NULL) {
        escreveArquivoLog1variavel(COMMAND_TERMINALNAOCADASTRADO, retornaNomeTerm(term));
        liberaTerminal(term);
        return 0;
    }
    CelTerm* nova = (CelTerm*) malloc (sizeof(CelTerm));
    nova->term = term;
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

void imprimeListaTerm (ListaTerm* lista){
    CelTerm* p;

    for (p = lista->prim; p != NULL; p = p->prox)
    {
        imprimeTerminal(p->term);
    }
    printf("\n");
}

void imprimeConexaoListaTerminal (ListaTerm* lista) {
    CelTerm* p;
    char* nome;
    char* rot;

    FILE* saida = fopen(SAIDA_DOT_PATH, "a");
    if(saida == NULL) {
        printf("Error ao abrir arquivo. \n");
        exit(1);
    }

    fprintf(saida, "strict graph {\n"); //começo do arquivo

    for (p = lista->prim; p != NULL; p = p->prox) {
        fprintf(saida,"\t%s", retornaNomeTerm(p->term)); //nome do terminal
        if(retornaRoteadorTerm(p->term) != NULL) { //caso tenha roteador ligado a ele
            fprintf(saida," -- ");
            fprintf(saida, "%s", retornaNomeRot(retornaRoteadorTerm(p->term)));
        }
            fprintf(saida,";\n");
    }

    fclose(saida); 
}

Terminal* retornaTerminal (ListaTerm* lista, char* chave) {
    CelTerm* p = procuraTerminal(lista, chave);
    
    if(p == NULL)
    {
        escreveArquivoLog1variavel(COMMAND_TERMINALNEXISTE, chave);
        return NULL;
    }
   
    return p->term;
}

CelTerm* procuraTerminal (ListaTerm* lista, char* chave) {
    CelTerm* p = lista->prim;
    CelTerm* ant = NULL;
    
    while((p!=NULL) && strcmp(chave, retornaNomeTerm(p->term)))
    {
        ant = p;
        p = p->prox;
    }
    return p;
}

void desconectaRoteadorConectado (ListaTerm* lista, Roteador* rot) {
    if(rot == NULL)
        return;
        
    CelTerm* p = lista->prim;
    
    while(p!=NULL) {
        if(retornaRoteadorTerm(p->term) != NULL) {
            if(strcmp(retornaNomeRot(retornaRoteadorTerm(p->term)), retornaNomeRot(rot)) == 0)
                desconectaTerminal(p->term);
        }
        p = p->prox;
    }
}

Terminal* retiraListaTerm(ListaTerm* lista, char* chave){
    CelTerm* p = lista->prim;
    CelTerm* ant = NULL;
    Terminal* term;

    //Faz busca
    while (p!=NULL && (strcmp(retornaNomeTerm(p->term), chave))) 
    {
        ant = p;
        p = p->prox;
    }
    
    // lista vazia ou não encontrou o aluno
    if (p==NULL) {
        escreveArquivoLog1variavel(COMMAND_TERMINALNEXISTE, chave);
        return NULL;
    }
    
    //atribui o aluno de retorno
    term = p->term;

    //se for único
    if (p == lista->prim && p == lista->ult)
        lista->prim = lista->ult = NULL;
    else if(p == lista->prim)
        lista->prim = p->prox;
    else if (p == lista->ult) {
        lista->ult = ant;
        lista->ult->prox = NULL;
    } else
        ant->prox = p->prox;
    
    free(p);

    return term;
}

int frequenciaLocalizacao (ListaTerm* lista, char* chave) {
    CelTerm* p = lista->prim;
    Terminal* term;
    int cont = 0;

    //Faz busca
    while (p!=NULL) 
    {
        if(strcmp(retornaLocalizacaoTerm(p->term), chave) == 0)
            cont++;
        p = p->prox;
    }
    return cont;
}

void liberaListaTerm (ListaTerm* lista){
    CelTerm* p = lista -> prim;
    CelTerm* t;

    while (p != NULL)
    {
        t = p->prox;
        liberaTerminal(p->term);
        free(p);
        p = t;
    }

    free(lista);
}