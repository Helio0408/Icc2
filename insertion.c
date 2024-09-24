#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _pessoa{
	char name[13];
	int idade;
	float altura;
	int entrada;
};

typedef struct _pessoa Pessoa;

int cmp(Pessoa* a, Pessoa* b);
Pessoa *inser_s(int tam, Pessoa arr[]);


// retorna 1 se for maior e 0 se for menor
int cmp(Pessoa* a, Pessoa* b) {
	int str_comparison = strcmp(a->name, b->name);
	
	if(str_comparison != 0) 
		return str_comparison > 0;
	if(a->idade != b->idade) 
		return a->idade > b->idade;
	
	return (a->altura >= b->altura);
}


Pessoa *inser_s(int tam, Pessoa arr[]){
	Pessoa temp;
	int cont = 0;

	for(int i = 1; i < tam; i++){
		cont = i;
		if(cmp(&arr[i-1], &arr[i])){
			while(cont != 0 && cmp(&arr[cont-1], &arr[cont])){
				temp = arr[cont-1];
				arr[cont-1] = arr[cont];
				arr[cont] = temp;

				cont--;	
			}
		}
			
	}

	return arr;
}

int main() {
	int tam = 0;
	Pessoa *arr;

	scanf("%d", &tam);

	arr = (Pessoa*)malloc(tam*sizeof(Pessoa));

	for(int i = 0; i < tam; i++){
		scanf("%s %d %f", arr[i].name, &(arr[i].idade), &(arr[i].altura));
		arr[i].entrada = i;
	}

	arr = inser_s(tam, arr);

	for(int i = 0; i < tam; i++)
		printf("%d;", arr[i].entrada);

	printf("\n");

	free(arr);
	return 0;
}