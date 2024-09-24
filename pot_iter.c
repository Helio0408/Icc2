#include <stdio.h>

int pot(int num, int ind){
	int res = 1;

	if(ind == 0)
		return 1;

	for(int i = 0; i < ind; i++){
		res *= num;
		res %= 1000;
	}

	return res;
}

int main(){
	int num, ind;

	scanf("%d %d", &num, &ind);

	printf("%d\n", pot(num, ind));

	return 0;
}