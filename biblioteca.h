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
void filtrar_prioridade(ListaDeTarefas lt, int prioridade);
void filtrar_estado(ListaDeTarefas lt, char *status);
void filtrar_categoria(ListaDeTarefas lt, char *topicos);
void filtrar_prioridade_categoria(ListaDeTarefas lt, char *topicos, int prioridade);
void exportar_prioridade(ListaDeTarefas lt, int prioridade, const char *priorizando);
void exportar_categoria(ListaDeTarefas lt, char *topicos, const char *categorizando);
void exportar_prioridade_categoria(ListaDeTarefas lt, int prioridade, char *topicos, const char *classificando);


#endif // PROJET_1_BIBLIOTECA_H
