#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int tam);
void bub_up(int *arr, int tam, int j);
void bub_down(int *arr, int tam, int j);
void imprimir(int *arr, int tam);

void sort(int *arr, int tam){
	int cont = 0, j = 0;

	while(cont < tam){
		bub_up(arr, tam, j);
		cont++;
		imprimir(arr, tam);

		if(cont == tam)
			break;

		bub_down(arr, tam, j);
		cont++;
		imprimir(arr, tam);

		j++;
	}
}

void bub_up(int *arr, int tam, int j){
	int temp;

	for(int i = j; i < tam - 1; i++)
		if(arr[i] > arr[i+1]){
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
}

void bub_down(int *arr, int tam, int j){
	int temp;

	for(int i = tam - j - 1; i > 0; i--)
		if(arr[i - 1] > arr[i]){
				temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
			}
}

void imprimir(int *arr, int tam){
	for(int i = 0; i < tam; i++)
		printf("%d ", arr[i]);

	printf("\n");
}

int main(){
	int tam, *arr;

	scanf("%d", &tam);

	arr = (int*)malloc(tam*sizeof(int));

	for(int i = 0; i < tam; i++)
		scanf("%d", &arr[i]);

	sort(arr, tam);

	free(arr);
	return 0;
}