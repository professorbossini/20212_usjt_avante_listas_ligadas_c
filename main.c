#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct no {
  int dado;
  struct no * prox;
}no;

typedef struct lista_ligada_simples {
  struct no * primeiro;
  struct no * ultimo;
  int qtde;
}lista_ligada_simples;

lista_ligada_simples * obter_lista (){
  lista_ligada_simples * lista = malloc(sizeof(lista_ligada_simples));
  lista->qtde = 0;
  lista->primeiro = NULL;
  lista->ultimo = NULL;
  return lista;
}

int esta_vazia ( lista_ligada_simples * l){
  return l->qtde <= 0;
}

void inserir_no_comeco (lista_ligada_simples * lista, int dado){
  no * novo = malloc (sizeof(no));
  novo->dado = dado;
  novo->prox = lista->primeiro;
  lista->primeiro = novo;
  if (esta_vazia(lista))
   lista->ultimo = lista->primeiro;
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
  if (indice < 0 || indice >= l->qtde) return -1;
  no * aux = l->primeiro;
  for (int i = 0; i < indice; i++, aux = aux->prox);
  return aux->dado;
}




void inserir_no_final (lista_ligada_simples * l, int dado){
  if (esta_vazia(l))
    inserir_no_comeco(l, dado);
  else{
    no * novo = malloc(sizeof(no));
    novo->dado = dado;
    novo->prox = NULL;
    no * aux = l->primeiro;
    while (aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = novo;
    l->ultimo = novo;
    l->qtde++;
  }
}

int main (void){
  srand(time (NULL));
  lista_ligada_simples * lista = obter_lista();
  for (int i = 0; i < 10; i++){
    //sortear o que fazer
    int inicio_ou_fim = rand() % 2;
    int dado = rand() % 20 + 1;
    if (inicio_ou_fim == 0){
      inserir_no_comeco(lista, dado);
    }
    else{
      inserir_no_final(lista, dado);
    }
    exibir_lista(lista);
    printf ("\n");
    printf ("lista[%d]=%d\n", lista->qtde - 1, lista->ultimo->dado);
    
  }
  printf ("\n");

}


// int main (void){
//   srand(time (NULL));
//   lista_ligada_simples * lista = obter_lista();
//   for (int i = 0; i < 10; i++){
//     int dado = rand() % 20 + 1;
//     inserir_no_comeco (lista, dado);
//     exibir_lista(lista);
//     printf("\n");
//     int posicao = rand() % lista->qtde;
//     printf ("lista[%d]=%d\n", posicao, obter(lista, posicao));
//     printf ("\n*************************\n");
//   }

// }



// int main(void) {
//   srand(time(NULL));
//   lista_ligada_simples * lista = obter_lista();
//   for (int i = 0; i < 100; i++){
//     int dado = rand() % 20 + 1;
//     inserir_no_comeco (lista, dado);
//     exibir_lista(lista);
//     printf ("\n*************************\n");
//   }
  
//   return 0;
// }