#include <stdlib.h>
#include <stdio.h>
#define MAX 5

typedef struct elementos {
    char nome[50];
} t_elemento;

typedef struct fila {
    t_elemento vetor[MAX];
    int inicio; 
    int fim;    
    int quant_element;    
} t_fila;

t_fila criar()
{
    t_fila fila;


    fila.inicio = 0;
    fila.fim = -1;
    fila.quant_element = 0;

    return fila;
}

int isVazia (t_fila * fila)
{
    return (fila->quant_element == 0);
}

int isCheia(t_fila * fila)
{
    return (fila->quant_element == MAX);
}

int inserir (t_fila * fila, t_elemento valor)
{
    if (isCheia(fila))
        return 0;

    (fila->quant_element)++;
    fila->fim = (fila->fim + 1) % MAX;
    fila->vetor[fila->fim] = valor;
    return 1;
}

t_elemento remover(t_fila * fila)
{
    t_elemento valor = { "" } ;
    if (isVazia(fila))
        return valor; 

    valor = fila->vetor[fila->inicio];
    fila->vetor[fila->inicio].nome[0] = '\0'; 
    (fila->quant_element)--;
    fila->inicio = (fila->inicio + 1) % MAX;
    return valor;
}

void exibir(t_fila * fila) {
    int i;
    if (isVazia(fila)) {
        printf("Fila vazia\n");
        return;
    }

    printf("\nExibindo fila:\n");
    printf("inicio: %d\n", fila->inicio);
    printf("fim:    %d\n", fila->fim);
    
    if(fila->inicio == fila->fim + 1){
    	for(i = fila->inicio; i != (fila->fim) % MAX; i = (i+1) % MAX)
        	printf("%d: %s\n", i+1, fila->vetor[i].nome);
    	printf("ultima: %s\n", fila->vetor[fila->fim].nome);
    	return;
	}
    for(i = fila->inicio; i != (fila->fim + 1) % MAX; i = (i+1) % MAX){
        printf("%d: %s\n", i+1, fila->vetor[i].nome);
    }
     
}

void EntrarPessoas(t_fila * fila){
	int i = 0;
	t_elemento elemento;


	for(i = 0; i < MAX-1; i++){
		printf("informe o nome da pessoa %d: ", (i+1));
		scanf("%s", &elemento.nome);
		inserir(fila, elemento);
		exibir(fila);

	}


}

void removerPessoa(t_fila * fila){
	int i = 0;

	for(i = 0; i < 3; i++){
			
			printf("A %d pessoa a ser removida e %s\n",(i+1), fila->vetor[i].nome);
			remover(fila);

	}



}

int main(){
	t_fila fila;

	t_elemento elemento;    
	int i = 0;

	fila = criar();

	EntrarPessoas(&fila);	

	removerPessoa(&fila); 
	for(i = 0; i < MAX-1; i++){ 
		printf("Informe o nome da %d pessoa a entrar na fila: ", (i+1) );
		scanf("%s", &elemento.nome);

		inserir(&fila, elemento);
		exibir(&fila);
	}


}