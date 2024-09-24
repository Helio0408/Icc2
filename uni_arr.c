#include <stdio.h>

void merge(int v1[], int n1, int v2[], int n2, int v3[]){
    if(n1 > 0 && n2 == 0){
        v3[n1+n2-1] = v1[n1-1];
        merge(v1, n1-1, v2, n2, v3);;
    }else if(n2 == 0 && n2 > 0){
        v3[n1+n2-1] = v2[n2-1];
        merge(v1, n1, v2, n2-1, v3);
    }else if(n1 > 0 && n2 > 0){
        if(v1[n1-1] > v2[n2-1]){
            v3[n1+n2-1] = v1[n1-1];
            merge(v1, n1-1, v2, n2, v3);
        }else{
            v3[n1+n2-1] = v2[n2-1];
            merge(v1, n1, v2, n2-1, v3);
        }
    }
}

int main(){
    int n1, n2;

    n1 = 5;
    n2 = 6;

    int v1[5] = {1, 2, 3, 4, 5};
    int v2[6] = {6, 7, 8, 9, 10, 11};
    int v3[n1 + n2];

    merge(v1, n1, v2, n2, v3);

    for(int i = 0; i < n1+n2; i++){
        printf("%d ", v3[i]);
    }

    return 0;
}