#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No_Tupla {
    char codigo[15];
    char prateleira[1010];
    struct No_Tupla *prox;
    struct No_Tupla *ant;
}No_Tupla;

typedef struct Lista {
    int tamanho;
    No_Tupla *inicio;
    No_Tupla *fim;
}Lista;

No_Tupla *busca_no(Lista* lista, char codigo[]) {
    No_Tupla *aux = lista->inicio;
    while (aux != NULL && strcmp(codigo, aux->codigo)) {
        aux = aux->prox;
    }
    return aux;
}

void inserir_no (Lista* lista, char codigo[], char prateleira[]) {
    No_Tupla *novo = (No_Tupla*)malloc(sizeof(No_Tupla));
    strcpy(novo->codigo, codigo);
    strcpy(novo->prateleira, prateleira);
    novo->ant = novo->prox = NULL;
    lista->tamanho++;
    if (lista->inicio == NULL) {
        lista->inicio = lista->fim = novo;
    }else {
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
    }
}

void print_lista(Lista *lista) {
    No_Tupla *aux = lista->inicio;
    while (aux != NULL) {
        printf("%s %s\n", aux->codigo, aux->prateleira);
        aux = aux->prox;
    }
    printf("\n");
}


int main() {
    Lista *l1 = (Lista*)malloc(sizeof(Lista));
    l1->inicio = l1->fim = NULL;
    l1->tamanho = 0;

    char codigo[15];
    char acao[15];
    char prateleira[1010];

    do {
        fflush(stdin);
        scanf("%s", codigo);
        if (strcmp(codigo, "0")) {
            fflush(stdin);
            scanf("%s", acao);
            fflush(stdin);
            scanf("%s", prateleira);
            if (strcmp(acao, "adicionar") == 0) {
                No_Tupla *aux = busca_no(l1, codigo);
                if (aux == NULL) {
                    inserir_no(l1, codigo, prateleira);
                }else {
                    strcpy(aux->prateleira, prateleira);
                }
            }else if (strcmp(acao, "remover") == 0) {
                No_Tupla *aux = busca_no(l1, codigo);
                if (aux != NULL && strcmp(aux->prateleira, prateleira) == 0) {
                    strcpy(aux->prateleira, "nao encontrado");
                }
            }
        } 
    }while(strcmp(codigo, "0"));

    print_lista(l1);
    
    return 0;
}