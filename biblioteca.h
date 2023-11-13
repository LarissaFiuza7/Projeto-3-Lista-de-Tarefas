#ifndef PROJET_1_BIBLIOTECA_H
#define PROJET_1_BIBLIOTECA_H
#include <string.h>
// Cria a estrutura de tarefa, dando 3 parâmetros, priroidade, categoria e descrição
typedef struct {
  int prioridade;
  char categoria[100];
  char descricao[300];
  char estado[20];
} Tarefa;

// Cria a lista de tarefas
typedef struct {
  Tarefa tarefas[100];
  int qtd;
} ListaDeTarefas;

// Variaveis
void cadastrarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt, int indice);
void listarTarefas(ListaDeTarefas lt);
void salvarLista(ListaDeTarefas lt, const char *tarefas);
void carregarLista(ListaDeTarefas *lt, const char *tarefas);
void alterar_Tarefa(ListaDeTarefas*lt, int indice);

#endif // PROJET_1_BIBLIOTECA_H
