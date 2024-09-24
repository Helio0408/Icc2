#include <stdio.h>
#include <stdlib.h>

int hash(int k, int esp);
int fat(int num);

int hash(int k, int esp){
	return k%esp;
}

int main(){
	int tam, *arr, num, alvo, *somas, chave, tam_hash, original;

	scanf("%d", &tam);
	tam_hash = (tam*tam*tam);
	arr = (int*)malloc(tam * sizeof(int));
	somas = (int*)calloc(tam_hash, sizeof(int));

	for(int i = 0; i < tam; i++)
		scanf("%d", &arr[i]);

	for(int i = 0; i < tam; i++)
		for(int j = i+1; j < tam; j++){
			chave = hash(arr[i]+arr[j], tam_hash);

			if(somas[chave] == 0)
				somas[chave] = arr[i]+arr[j];
			else if(somas[chave] == arr[i]+arr[j])
				continue;
			else{
				while(somas[chave] != (arr[i]+arr[j]) && somas[chave] != 0){
					chave++;
					if(chave >= tam_hash) chave -= tam_hash; 
				}
				
				somas[chave] = arr[i]+arr[j];
			}
		}

	scanf("%d", &num);

	for(int i = 0; i < num; i++){
		scanf("%d", &alvo);
		
		chave = hash(alvo, tam_hash);

		if(somas[chave] == alvo)
			printf("S\n");
		else if(somas[chave] == 0)
			printf("N\n");
		else{
			original = chave - 1;
			for(int i = 0; i < tam_hash; i++){
				if(somas[chave] == alvo) break;
				if(chave >= tam_hash) chave -= tam_hash;
				chave++;
			}
		
			if(somas[chave] == alvo)
				printf("S\n");
			else
				printf("N\n");
		}
	}

	free(arr);
	free(somas);

	return 0;
}