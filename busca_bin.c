#include <stdio.h>
#include <stdlib.h>

void heap(int *arr, int tam_atual, int raiz);
void sort(int *arr, int tam);
int busca_bin(int *arr, int tam, int alvo);

void heap(int *arr, int tam_atual, int raiz){
	int temp, maior = raiz, esq = 2 * raiz + 1, dir = 2 * raiz + 2;


	if(esq < tam_atual && arr[esq] > arr[maior])
		maior = esq;

	if(dir < tam_atual && arr[dir] > arr[maior])
		maior = dir;

	if(maior != raiz){
		temp = arr[raiz];
		arr[raiz] = arr[maior];
		arr[maior] = temp;

		heap(arr, tam_atual, maior);
	}
}

void sort(int *arr, int tam) {
	int temp;

    for(int i = (tam/2) -1; i >= 0; i--)
		heap(arr, tam, i);

	while(tam > 1){
		temp = arr[0];
		arr[0] = arr[tam - 1];
		arr[tam - 1] = temp;

		heap(arr, tam - 1, 0);

		tam--;
	}
}



// Retorna -2 para erro, -1 se não achar e a posição no arr caso ache
int busca_bin(int *arr, int tam, int alvo){
	int pos = -2, l = 0, r = tam - 1, meio = ((l+r)/2);

	while(1){
		if(l > r){
			pos = -1;
			break;
		}

		meio = ((l+r)/2);

		if(arr[meio] < alvo){
			l = meio + 1;
			continue;
		}else if(arr[meio] > alvo){
			r = meio - 1;
			continue;
		}else{
			pos = meio;
			break;
		}
	}

	return pos;
}

int main(){
	int num, *arr, buscas, alvo;

	scanf("%d", &num);

	arr = (int *)malloc(num * sizeof(int));

	for(int raiz = 0; raiz < num; raiz++)
		scanf("%d", &arr[raiz]);

	sort(arr, num);

	scanf("%d", &buscas);

	for(int raiz = 0; raiz < buscas; raiz++){
		scanf("%d", &alvo);
		if(busca_bin(arr, num, alvo) != -1 && busca_bin(arr, num, alvo) != -2)
			printf("Presente\n");
		else if(busca_bin(arr, num, alvo) == -1)
			printf("Ausente\n");
		else{
			printf("Error busca\n");
		}
	}

	free(arr);
	return 0;
}