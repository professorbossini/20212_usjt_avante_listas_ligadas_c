#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct no {
  int dado;
  struct no * prox;
}no;

typedef struct lista_ligada_simples {
  struct no * primeiro;
  int qtde;
}lista_ligada_simples;

lista_ligada_simples * obter_lista (){
  lista_ligada_simples * lista = malloc(sizeof(lista_ligada_simples));
  lista->qtde = 0;
  lista->primeiro = NULL;
  return lista;
}

void inserir_no_comeco (lista_ligada_simples * lista, int dado){
  no * novo = malloc (sizeof(no));
  novo->dado = dado;
  novo->prox = lista->primeiro;
  lista->primeiro = novo;
  lista->qtde++;
}

void exibir_lista (lista_ligada_simples * lista){
  no * aux = lista->primeiro;
  while (aux != NULL){
    printf ("%d ", aux->dado);
    aux = aux->prox;
  }
}

int obter (lista_ligada_simples * l, int indice) {
  if (indice < 0 || indice >= this.qtde) return -1;
  No * aux = l->primeiro;
  for (int i = 0; i < indice; i++, aux = aux->prox);
  return aux->dado;

}


int main(void) {
  srand(time(NULL));
  lista_ligada_simples * lista = obter_lista();
  for (int i = 0; i < 100; i++){
    int dado = rand() % 20 + 1;
    inserir_no_comeco (lista, dado);
    exibir_lista(lista);
    printf ("\n*************************\n");
  }
  
  return 0;
}