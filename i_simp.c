#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *alloc(int tam);
int *inser_s(int tam, int* arr);

int *alloc(int tam){
	int* p = (int*) malloc(tam*sizeof(int));
	assert(p != NULL);

	return p;
}

int *inser_s(int tam, int* arr){
	int temp, cont = 0;

	for(int i = 1; i < tam; i++){
		cont = i;
		if(arr[i] < arr[i-1]){
			while(cont != 0 && arr[cont] < arr[cont-1]){
				temp = arr[cont-1];
				arr[cont-1] = arr[cont];
				arr[cont] = temp;

				cont--;	
			}
		}
			
	}

	return arr;
}
int main(){
	int *arr, tam;

	scanf("%d", &tam);

	arr = alloc(tam);

	for(int i = 0; i < tam; i++)
		scanf("%d", &arr[i]);

	arr = inser_s(tam, arr);

	for(int i = 0; i < tam; i++)
		printf("%d ", arr[i]);

	printf("\n");

	free(arr);

	return 0;
}