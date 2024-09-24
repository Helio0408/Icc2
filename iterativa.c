/* 
 * Trabalho feitos pelos alunos do grupo 20:
 * Hélio Márcio Cabral Santos - 14577862
 * Gabriel Martins Monteiro   - 14572099
*/

#include <stdio.h>

#define mmin(m, n) (m < n ? m : n)

long mdc(long m, long n);

long mdc(long m, long n){
	for(long i = mmin(m, n); i > 0; i--){
		if(m % i == 0 && n % i == 0) return i;
	}

	return 1;
}

int main(void){
	long m, n;
	scanf("%ld %ld", &m, &n);
	printf("%ld\n", mdc(m, n));
}