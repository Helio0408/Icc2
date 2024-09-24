#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int dia;
	int mes;
	int ano;
}arq;

unsigned long merge_sort(arq arr[], int p, int r);
unsigned long sort(arq arr[], int p, int q, int r);
int comp(arq x, arq y);

unsigned long merge_sort(arq arr[], int p, int r){
	int q;
	unsigned long cont = 0;
	
	if(p < r){
		q = (p + r)/2;

		cont += merge_sort(arr, p, q);
		cont += merge_sort(arr, q + 1, r);
		cont += sort(arr, p, q, r);
	}

	return cont;
}

unsigned long sort(arq arr[], int p, int q, int r){
	int i, j;
	unsigned long cont = 0;
	arq *aux;

	aux = (arq*) malloc((r + 1) * sizeof(arq));

	for(i = p; i <= q; i++)
		aux[i] = arr[i];
	
	for(j = q + 1; j <= r; j++)
		aux[j] = arr[j];

	i = p;
	j = q + 1;
		
	for(int k = p; k <= r; k++){
		if(i > q){
			arr[k] = aux[j];
			j++;
		}else if(j > r){
			arr[k] = aux[i];
			i++;
		}else if(comp(aux[i], aux[j]) != -1){
			arr[k] = aux[i];
			i++;
		}else{
			arr[k] = aux[j];
			j++;
			cont += q - i + 1;
		}
	}

	free(aux);
	return cont;
}

int comp(arq x, arq y){
	if(x.ano > y.ano)
		return -1;
	else if(x.ano < y.ano)
		return 1;
	
	if(x.mes > y.mes)
		return -1;
	else if(x.mes < y.mes)
		return 1;

	if(x.dia > y.dia)
		return -1;
	else if(x.dia < y.dia)
		return 1;
	else
		return 0;
}

int main(){
	int num;
	unsigned long cont = 0;
	arq *arr;

	scanf("%d", &num);

	arr = (arq*) malloc(num * sizeof(arq));

	for(int i = 0; i < num; i++)
		scanf("%d %d %d", &arr[i].dia, &arr[i].mes, &arr[i].ano);

	cont = merge_sort(arr, 0, num-1);

	printf("%lu \n", cont);

	free(arr);
	return 0;
}