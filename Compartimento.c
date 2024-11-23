#include "Compartimento.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LTamanhoC(TListaRocha *pLista)
{
    int cont = 0;
    TCelulaRocha *pAux;
    pAux = pLista->pPrimeiro->pProx;
    while (pAux != NULL)
    {
        cont++;
        pAux = pAux->pProx;
    }
    return cont;
}

void FLVaziaC(TListaRocha *pLista)
{
    pLista->pPrimeiro = (ApontadorRocha)malloc(sizeof(TCelulaRocha));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
}

int LEhVaziaC(TListaRocha *pLista)
{
    return(pLista->pPrimeiro == pLista->pUltimo);
}
int lista_rocha_vazia(TListaRocha *pLista) {
    if (pLista->pPrimeiro->pProx == NULL) {
        return 1;
    }
    else{
        return 0;
    }
}

int LInsereC(TListaRocha *pLista, TRocha *pItem)
{
    //ApontadorRocha pAux = pLista->pPrimeiro->pProx;

    // while (pAux != NULL)
    // {
    //     if (strcmp(pAux->Item.Chave->categoria, pItem->categoria) == 0)
    //     {
    //         TrocarRocha(pLista, pItem);
    //         return 1;
    //     }
    //     pAux = pAux->pProx;
    // }

    pLista->pUltimo->pProx = (ApontadorRocha)malloc(sizeof(TCelulaRocha));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->Item.Chave = pItem;
    pLista->pUltimo->pProx = NULL;
    return 0;
}

int LRetiraC(TListaRocha *pLista, TRocha* rocha)
{
    if (LEhVaziaC(pLista))
    {
        return 0;
    }
    TCelulaRocha *aux1 = pLista->pPrimeiro;
    TCelulaRocha *aux2 = NULL;

    while (aux1 != NULL && strcmp(aux1->Item.Chave->categoria, rocha->categoria) != 0)
    {
        aux2 = aux1;
        aux1 = aux1->pProx;
    }
    if (aux2 == NULL)
    {
        pLista->pPrimeiro = aux1->pProx;
    }
    aux2 = aux1->pProx;

    free(aux1);
    return 1;
}

void LImprimeC(TListaRocha pLista)
{
    ApontadorRocha pAux;
    pAux = pLista.pPrimeiro->pProx;
    while (pAux != NULL)
    {
        printf("Categoria: %s\nPeso: %f\n", pAux->Item.Chave->categoria, pAux->Item.Chave->peso);
        pAux = pAux->pProx; // próxima célula
    }
    if (pAux == pLista.pPrimeiro->pProx)
    {
        printf("A lista é vazia\n");
    }
}

void TrocarRocha(TListaRocha *pLista, TRocha *Item)
{
    ApontadorRocha att = pLista->pPrimeiro->pProx;
    while (att != NULL)
    {
        if (strcmp(att->Item.Chave->categoria, Item->categoria) == 0 && att->Item.Chave->peso < Item->peso)
        {
            att->Item.Chave = Item;
        }
        att = att->pProx;
    }
}

double PesoCompartimento(TListaRocha *pLista)
{
    double PesoT = 0.0;
    ApontadorRocha att = pLista->pPrimeiro->pProx;
    while (att != NULL)
    {
        PesoT += att->Item.Chave->peso;
        att = att->pProx;
    }
    return PesoT;
}