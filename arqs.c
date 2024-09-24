#include <stdio.h>

void procurar_registro(char filename[], int id){
    FILE *fp;
    int id_o, idade;
    char nome[12];

    fp = fopen(filename, "rb");

    if(fp = NULL){
        printf("Arquivo não encontrado.\n");
        return;
    }

    while(feof(fp) == 0){
        fread(&id_o, sizeof(int), 1, fp);
        fread(nome, sizeof(char), 12, fp);
        fread(&idade, sizeof(int), 1, fp);

        if(id_o == id)
            break;
    }

    if(id_o == id){
        printf("ID: %d | NOME: %s | IDADE: %d \n", id_o, nome, idade);
        return;
    }else{
        printf("Registro não encontrado.\n");
        return;
    }
}

int main(){
    return 0;
}