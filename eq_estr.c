#include <stdio.h>

long int f(int n, int q, int p);

long int f(int n, int q, int p){
	long int res = 0;

	if(n <= 1){
		res = 1;
		while(p > 1)
			res *= p--;
	}else{
		for(int i = 1; i <= 8; i++)
			res += f(n/2, q, p) + i;

		for(int i = 1; i <= q; i++)
			for(int j = 1; j <= n; j++)
				res += i*j;
	}

	return res;
}

int main(){
	int n = 0, q = 0, p = 0;

	scanf("%d %d %d", &n, &q, &p);

	printf("%ld\n", f(n, q, p));

	return 0;
}