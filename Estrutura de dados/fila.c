#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int num;
  struct No *proximo;
} No;

typedef struct Fila {
  No *comeco;
  No *fim;
} Fila;

void inicializarFila(Fila *fila) {
  fila->comeco = NULL;
  fila->fim = NULL;
}

void adicionar(Fila *fila, int numero) {
  No *novoNo = (No *)malloc(sizeof(No));
  novoNo->num = numero;
  novoNo->proximo = NULL;

  if (fila->fim == NULL) {
    fila->comeco = novoNo;
    fila->fim = novoNo;
  } else {
    fila->fim->proximo = novoNo;
    fila->fim = novoNo;
  }
}

int remover(Fila *fila) {
  if (fila->comeco == NULL) {
    return -1;
  }

  int numero = fila->comeco->num;
  No *no = fila->comeco;
  fila->comeco = fila->comeco->proximo;
  free(no);

  if (fila->comeco == NULL) {
    fila->fim = NULL;
  }

  return numero;
}

int retirarNumero(Fila *fila, int numero) {
  No *atual = fila->comeco;
  No *anterior = NULL;

  while (atual != NULL && atual->num != numero) {
    anterior = atual;
    atual = atual->proximo;
  }

  if (atual == NULL) {
    return 0;
  }

  if (anterior == NULL) {
    fila->comeco = atual->proximo;
  } else {
    anterior->proximo = atual->proximo;
  }

  free(atual);

  if (fila->comeco == NULL) {
    fila->fim = NULL;
  }

  return 1;
}

int filaVazia(Fila *fila) {
  return fila->comeco == NULL;
}

void imprimir(Fila *fila) {
  No *no = fila->comeco;
  while (no != NULL) {
    printf("%d\n", no->num);
    no = no->proximo;
  }
}

int main() {
  Fila fila;

  inicializarFila(&fila);

  adicionar(&fila, 64);
  adicionar(&fila, 25);
  adicionar(&fila, 12);
  adicionar(&fila, 22);
  adicionar(&fila, 11);
  adicionar(&fila, 9);

  printf("Fila:\n");
  imprimir(&fila);

  int numeroARetirar = 11;
  if (retirarNumero(&fila, numeroARetirar)) {
    printf("\nNúmero %d retirado da fila:\n", numeroARetirar);
    imprimir(&fila);
  } else {
    printf("\nNúmero %d não encontrado.\n", numeroARetirar);
  }

  return 0;
}