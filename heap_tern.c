#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int tam);

void sort(int *arr, int tam){
	int temp;

	for(int i = 0; i < tam; i++)
		printf("%d ", arr[i]);

	printf("\n");

	while(1){
		for(int i = tam - 1; i >= 0; i--)
			for(int j = 3; j > 0; j--)
				if(3*i + j < tam && arr[3*i + j] > arr[i]){
					temp = arr[i];
					arr[i] = arr[3*i + j];
					arr[3*i + j] = temp;
				}
		
		for(int i = 0; i < tam; i++)
			printf("%d ", arr[i]);

		printf("\n \n");

		temp = arr[0];
		arr[0] = arr[tam - 1];
		arr[tam - 1] = temp;

		tam--;

		for(int i = 0; i < tam; i++)
			printf("%d ", arr[i]);

		printf("- %d\n", arr[tam]);

		if(tam == 1)
			break;
	}
}

int main(){
	int tam, *arr;

	scanf("%d", &tam);

	arr = (int*)malloc(tam*sizeof(int));

	for(int i = 0; i < tam; i++)
		scanf("%d", &arr[i]);

	sort(arr, tam);

	for(int i = 0; i < tam; i++)
		printf("%d ", arr[i]);

	printf("\n");

	free(arr);
	return 0;
}