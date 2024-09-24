#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct _pessoa{
	char name[13];
	int idade;
	float altura;
	int entrada;
};

typedef struct _pessoa Pessoa;

// retorna 1 se for maior e 0 se for menor
int cmp(Pessoa* a, Pessoa* b){
	int str_comparison = strcmp(a->name, b->name);
	
	if(str_comparison != 0) 
		return str_comparison > 0;
	if(a->idade != b->idade) 
		return a->idade > b->idade;
	
	return (a->altura > b->altura);
}

void sort(Pessoa *arr, int tam) {
    int k = 1, gaps[20], gap = 0, j = 0;
	Pessoa aux;

	while(gap < tam){
		gap = pow(2, k) - 1;
		gaps[k++] = gap;
	}

	k--;

	while(k > 0){
		gap = gaps[k];

		for(int i = gap; i < tam; i++){
			aux = arr[i];

			for(j = i; (j >= gap) && (cmp(&arr[j-gap], &aux)); j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = aux;
		}

		k--;
	}
}

int main(){
	int tam;
	Pessoa *arr;

	scanf("%d", &tam);

	arr = (Pessoa*) malloc(tam*sizeof(Pessoa));

	for(int i = 0; i < tam; i++){
		scanf("%s %d %f", arr[i].name, &(arr[i].idade), &(arr[i].altura));
		arr[i].entrada = i;
	}

	sort(arr, tam);

	for(int i = 0; i < tam; i++)
		printf("%d;", arr[i].entrada);

	printf("\n");

	free(arr);
	return 0;
}