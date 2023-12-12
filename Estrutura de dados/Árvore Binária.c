#include <stdio.h>
#include <stdlib.h>

struct NoArvore {
    int info;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
};

struct NoArvore* criarNo(int info) {
    struct NoArvore* novoNo = (struct NoArvore*)malloc(sizeof(struct NoArvore));
    novoNo->info = info;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

struct NoArvore* inserirNo(struct NoArvore* raiz, int info) {
    if (raiz == NULL) {
        return criarNo(info);
    }

    if (info < raiz->info) {
        raiz->esquerda = inserirNo(raiz->esquerda, info);
    } else if (info > raiz->info) {
        raiz->direita = inserirNo(raiz->direita, info);
    }

    return raiz;
}

void imprimir(struct NoArvore* raiz) {
    if (raiz != NULL) {
        imprimir(raiz->esquerda);
        printf("%d\n", raiz->info);
        imprimir(raiz->direita);
    }
}

int main() {
    int infos[] = {200, 450, 123, 52, 133, 321, 422, 523, 36, 64};
    int n = sizeof(infos) / sizeof(infos[0]);

    struct NoArvore* raiz = NULL;

    for (int i = 0; i < n; i++) {
        raiz = inserirNo(raiz, infos[i]);
    }

    printf("Árvore Binária:\n");
    imprimir(raiz);

    return 0;
}
