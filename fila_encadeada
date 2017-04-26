#include	<stdio.h>
#include	<stdlib.h>

typedef struct elementos {
	char nome[50];
}t_elemento;

typedef struct no {
	t_elemento dado;
	struct no *prox;
}t_no;

typedef struct fila {
	t_no *inicio;
	int quant_element;
	t_no *final;
}t_fila;
 
t_fila * criaCabeca();

t_no * criaNo();

int isVazia (t_fila * fila);

int inserir (t_fila *fila, t_elemento valor);

void exibir (t_fila *fila);

int main() {
		
	t_fila * mFila = criaCabeca();
	
	int i;
	
	t_elemento dado;
	
	for (i = 0; i < 4; i++) {
		printf("\nDigite um nome: ");
		scanf("%s", dado.nome);
		inserir(mFila, dado); 
		exibir(mFila);
	}
	
	return 0;
}

t_fila * criaCabeca() {
    t_fila * fila = (t_fila*) malloc(sizeof(t_fila));

    if (fila) {
        fila->inicio = fila->final = NULL;
        fila->quant_element=0;
    }
    return fila;
}

t_no * criaNo() {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    if (no)
        no->prox = NULL;

    return no;
}

int isVazia (t_fila * fila) {
    return (fila->quant_element == 0);
}

int inserir (t_fila * fila, t_elemento valor) {
    t_no *novo;
    novo = criaNo();
    if (novo == NULL)
        return 0; 
    novo->dado = valor;
    if (isVazia(fila))
        fila->inicio = novo;
    else
        (fila->final)->prox = novo;
    fila->final = novo;
    fila->quant_element++;
    return 1;
}

void exibir (t_fila *fila){       
  t_no * mfila;       
  int i;       
  mfila = fila->inicio;       

  for(i=0; i < fila->quant_element; ++i){       
    printf("%s ", mfila->dado.nome);       
    mfila = mfila->prox;       
  }       
}