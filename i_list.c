#include <stdio.h>
#include <stdlib.h>

struct cel{
    int conteudo;
    struct cel *prox;
};

typedef struct cel celula;

void inserir(celula** ini, int x){
    // considera-se que a lista está ordenada em ordem crescente

    celula* p = NULL;

    if(x < (*ini)->conteudo){
        celula* nova = (celula*) malloc(sizeof(celula));
        nova->conteudo = x;
        nova->prox = (*ini);
        (*ini) = nova;
        return;
    }

    for(p = *ini; p != NULL; p = p->prox){
        if((x > p->conteudo)){
            int menor = 0;

            if(p->prox == NULL) menor = 1;
            else if(p->prox->conteudo > x) menor = 1;

            if(menor){
                celula* nova = (celula*) malloc(sizeof(celula));
                nova->conteudo = x;
                nova->prox = p->prox;
                p->prox = nova;
                break;
            }
            
        }
    }
}

int main(){
    celula *ini = malloc(sizeof(celula));
    ini->conteudo = 1;
    ini->prox = NULL;
    inserir(&ini, 0);
    inserir(&ini, 3);
    inserir(&ini, 2);
    inserir(&ini, 87);
    inserir(&ini, -1);




    for(celula* p = ini; p != NULL; p = p->prox) 
        printf("%d\n", p->conteudo);
    return 0;
}