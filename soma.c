#include <stdio.h>
#include <limits.h>

int dif(int x, int y){
	int res;

	if((x > 0 && y > 0) || (x < 0 && y < 0)){
		res = x - y;
		if(res > 0)
			return res;
		else
			return -res;
	}else{
		res = x + y;
		if(res > 0)
			return res;
		else
			return -res;
	}
}

int main(){
	int num, alvo, prim = 0, ult = 0, dif_min = INT_MAX, soma = 0;
	int arr[100];

	scanf("%d", &num);

	for(int i = 0; i < num; i++){
		scanf("%d", &arr[i]);
	}

	scanf("%d", &alvo);

	for(int i = 0; i < num; i++){
		soma = 0;

		for(int j = i; j < num; j++){
			soma += arr[j];
			
			if(dif(soma, alvo) < dif_min){
				dif_min = dif(soma, alvo);
				prim = i;
				ult = j;
			}
		}
	}

	printf("%d %d\n", prim + 1, ult + 1);

	return 0;
}