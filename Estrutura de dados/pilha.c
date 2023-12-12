#include <stdio.h>
#include <stdlib.h>

typedef struct cache {
  int num;
  struct cache *proxima;
} cache;

void inicializar(cache **pilha) {
  *pilha = NULL;
}

void adicionar(cache **pilha, int num) {
  cache *novacache = (cache *)malloc(sizeof(cache));
  novacache->num = num;
  novacache->proxima = *pilha;
  *pilha = novacache;
}

cache *remover(cache **pilha) {
  if (*pilha == NULL) {
    return NULL;
  }

  cache *cache = *pilha;
  *pilha = cache->proxima;
  cache->proxima = NULL;

  return cache;
}

int main() {
  cache *pilha;

  inicializar(&pilha);

  adicionar(&pilha, 64);
  adicionar(&pilha, 25);
  adicionar(&pilha, 12);
  adicionar(&pilha, 22);
  adicionar(&pilha, 11);
  adicionar(&pilha, 9);

  cache *cache;
  while ((cache = remover(&pilha)) != NULL) {
    if (cache->num > 9) {
      printf("%d\n", cache->num);
    }
    free(cache);
  }

  return 0;
}
