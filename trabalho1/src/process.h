#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DESCR 51

/* Armazena um horário de chegada */

typedef struct {
	int hh;
	int mm;
	int ss;
} horario;

/* Armazena informações de um processo */

typedef struct {
	int prior;
	horario chegada;
	char descricao[MAX_DESCR];
} celula;

typedef struct s_lista lista;

horario horario_criar(int hh, int mm, int ss);

int horario_cmp(horario a, horario b);

/* Compara o valor de duas células.
 * Retorna 1 caso a > b
 * Retorna 0 caso a == b
 * Retorna -1 caso a < b
 * Caso cmp_by_priorty == true, a comparação será feita com
 * base na prioridade.
 * Caso contrário, a comparação será feita com base no tempo
 * de chegada */
int celula_cmp(celula *a, celula *b, bool cmp_by_priority);

celula celula_criar(int prior, horario h, const char *descricao);

/* cria um ponteiro para lista */
lista* lista_criar(void);

/* Ordena a lista.
 * Caso sort_by_priority == true, a lista será ordenada
 * com base na prioridade.
 * Caso contrário, ela será ordenada com base no tempo
 * de chegada */
void lista_sort(lista *l, bool sort_by_priority);

/* adiciona uma nova célula a lista */
void lista_add(lista *l, celula nova);

/* executa o primeiro elemento da lista*/
void lista_exec(lista *l, bool sort_by_priority);

/* printa o primeiro elemento da lista */
void lista_next(lista* l, bool sort_by_priority);

/* modifica o elemento com ant_prioridade para ter nova_prioridade */
void lista_modificaPrioridade(lista* l, int ant_prioridade, int nova_prioridade);

/* modifica o elemento de ant_horario com novo_horario */
void lista_modificaTempo(lista* l, horario ant_horario, horario novo_horario);

/* printa a lista */
void lista_print(lista* l, bool sort_by_priority);

void lista_destruir(lista* l);

#endif
