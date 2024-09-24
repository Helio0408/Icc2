#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *alloc(int num);
void orden3(int *arr, int tam); 

int *alloc(int num) {
	int *p = (int*)malloc(num*sizeof(int));
	assert(p != NULL);

	return p;
}
/*
	Usamos bubble sort pois para esse caso só precisamos ordenar os 3 maiores
termos, fazendo com que ele seja mais eficiente que os demais algoritmos.
*/
void orden3(int *arr, int tam) {
	int aux = 0;

	for(int i = 0; i < 3; i++)
		for(int j = 1; j < tam; j++)
			if(arr[j-1] > arr[j]){
				aux = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = aux;
			}
}

int main(){
	int tam = 0, *arr = NULL;

	scanf("%d", &tam);

	arr = alloc(tam);

	for(int i = 0; i < tam; i++){
		scanf("%d", &arr[i]);

		if(i < 2)
			printf("-1\n");
		else{
			orden3(arr, i+1);
			printf("%d %d %d\n", arr[i], arr[i-1], arr[i-2]);
		}
	}

	free(arr);

	return 0;
}