#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int fat(int num);

int fat(int num){
	int res = 1;
	while(num > 1)
		res *= num--;

	return res;
}

int main(){
	int tam, *arr, repetidos = 0, res;
	bool numeros[1000000] = {0};

	scanf("%d", &tam);

	arr = (int*) malloc(tam*sizeof(int));

	for(int i = 0; i < tam; i++){
		scanf("%d", &arr[i]);

		if(numeros[arr[i]-1] == 0)
			numeros[arr[i]-1]++;
		else
			repetidos++;
	}

	res = ((fat(tam - repetidos)) / (2 * fat(tam - repetidos - 2)));

	printf("%d \n", res);

	free(arr);
	return 0;
}