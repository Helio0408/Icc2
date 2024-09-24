#include <stdio.h>
#include <stdint.h>

int potencia(int n, int k){
	if(k == 0) return 1;
	else if(k % 2 == 0){
		int res = potencia(n, k/2);
		return res * res % 1000;
	}
	else{
		int res = potencia(n, (k - 1)/2);
		return res * res * n % 1000;
	}
}

int main(void){
	int n, k;
	scanf("%d %d", &n, &k);

  	printf("%d\n", potencia(n, k));
	return 0;
}