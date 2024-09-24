#include "process.h"

int main(void){
	char operacao[7] = "", descricao[MAX_DESCR]= "", opcao[3] = "";
	int prior, hh, mm, ss, prior_n, HH, MM, SS;
	bool sort_by_priority = 0;
	int algo_foi_printado = 0;
	horario tempo, tempo_n;
	lista *l;
	
	l = lista_criar();

	while(1){
		scanf("%s ", operacao); // escolha da operação

		// adiciona um processo à lista
		if(strcmp(operacao, "add") == 0){
			scanf("%d %d:%d:%d %s", &prior, &hh, &mm, &ss, descricao);
			tempo = horario_criar(hh, mm, ss);

			lista_add(l, celula_criar(prior, tempo, descricao));

		// remove o processo de maior prioridade ou de menor tempo
		}else if(strcmp(operacao, "exec") == 0){
			scanf("%s", opcao);

			if(strcmp(opcao, "-p") == 0)
				sort_by_priority = true;
			else
				sort_by_priority = false;
			
			lista_exec(l, sort_by_priority);

		// printa o processo de maior prioridade ou de menor tempo
		}else if(strcmp(operacao, "next") == 0){
			if(!algo_foi_printado) algo_foi_printado = 1;
			else printf("\r\n");

			scanf("%s", opcao);

			if(strcmp(opcao, "-p") == 0)
				sort_by_priority = true;
			else
				sort_by_priority = false;
			
			lista_next(l, sort_by_priority);

		// muda a prioridade ou o tempo de um processo
		}else if(strcmp(operacao, "change") == 0){
			scanf("%s", opcao);

			if(strcmp(opcao, "-p") == 0){
				scanf("%d|%d", &prior, &prior_n);

				lista_modificaPrioridade(l, prior, prior_n);
			}else{
				scanf("%d:%d:%d|%d:%d:%d", &hh, &mm, &ss, &HH, &MM, &SS);
				tempo = horario_criar(hh, mm, ss);
				tempo_n = horario_criar(HH, MM, SS);

				lista_modificaTempo(l, tempo, tempo_n);
			}

		// printa todos os termos em ordem decrescente de acordo com a opção
		}else if(strcmp(operacao, "print") == 0){
			if(!algo_foi_printado) algo_foi_printado = 1;
			else printf("\r\n");

			scanf("%s", opcao);

			if(strcmp(opcao, "-p") == 0)
				sort_by_priority = 1;
			else
				sort_by_priority = 0;
			
			lista_print(l, sort_by_priority);

		// sai do while e termina o programa	
		}else if(strcmp(operacao, "quit") == 0){
			break;
		}

	}
	
	lista_destruir(l);
	return 0;
}
