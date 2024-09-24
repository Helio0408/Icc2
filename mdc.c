/* 
 * Trabalho feitos pelos alunos do grupo 20:
 * Hélio Márcio Cabral Santos - 14577862
 * Gabriel Martins Monteiro   - 14572099
*/

#include <stdio.h>

long mdc(long m, long n);

long mdc(long m, long n){
	if(n == 0)
		return m;
	else
		return mdc(n, m%n);
}

long main(){
	long m, n;

	scanf("%ld %ld", &m, &n);

	printf("%ld\n", mdc(m,n));

	return 0;
}