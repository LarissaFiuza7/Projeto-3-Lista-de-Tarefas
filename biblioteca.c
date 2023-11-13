#include "biblioteca.h"
#include <stdio.h>

// Função de atualizar a lista toda vez que ela for usada
void salvarLista(ListaDeTarefas lt, const char *tarefas) {
  FILE *arquivo = fopen(tarefas, "wb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para escrita.\n");
    return;
  }
  fwrite(&lt, sizeof(ListaDeTarefas), 1, arquivo);
  fclose(arquivo);
}
// Carregar a lista quando precisar acessá-la
void carregarLista(ListaDeTarefas *lt, const char *tarefas) {
  FILE *arquivo = fopen(tarefas, "rb");
  if (arquivo == NULL) {
    printf("Arquivo de lista não encontrado. Iniciando com lista vazia.\n");
    return;
  }
  fread(lt, sizeof(ListaDeTarefas), 1, arquivo);
  fclose(arquivo);
}

// Função de criar a tarefa, dando os parâmetros necessaríos
void cadastrarTarefa(ListaDeTarefas *lt) {
  if (lt->qtd < 100) {
    Tarefa novaTarefa;
    printf("Digite a prioridade da tarefa de 0 a 10: ");
    scanf("%d", &novaTarefa.prioridade);
    getchar(); // Limpa o caractere de nova linha pendente
    printf("Digite a categoria da tarefa: ");
    fgets(novaTarefa.categoria, sizeof(novaTarefa.categoria), stdin);
    novaTarefa.categoria[strlen(novaTarefa.categoria) - 1] = '\0';
    // Remove o caractere de nova linha
    printf("Digite a descrição da tarefa: ");
    fgets(novaTarefa.descricao, sizeof(novaTarefa.descricao), stdin);
    novaTarefa.descricao[strlen(novaTarefa.descricao) - 1] = '\0';
    printf("Digite o estado da tarefa: ");
    fgets(novaTarefa.estado, sizeof(novaTarefa.estado), stdin);
    novaTarefa.estado[strlen(novaTarefa.estado) - 1] = '\0';
    // Remove o caractere de nova linha
    lt->tarefas[lt->qtd] = novaTarefa;
    lt->qtd++;
    printf("Tarefa cadastrada com sucesso!\n");
  } else {
    printf("A lista de tarefas está cheia. Não é possível cadastrar mais "
           "tarefas.\n");
  }
}
// Compara as tarefas através da prioridade
int compararTarefas(const void *a, const void *b) {
  return ((Tarefa *)a)->prioridade - ((Tarefa *)b)->prioridade;
}

// Listar as tarefas a partir do nível de prioridade, junto do índice
void listarTarefas(ListaDeTarefas lt) {
  if (lt.qtd == 0) {
    printf("A lista de tarefas está vazia.\n");
    return;
  }
  for (int i = 0; i < lt.qtd; i++) {
    printf("Tarefa %d - Prioridade %d: %s - %s - tarefa %s\n", i, lt.tarefas[i].prioridade,
           lt.tarefas[i].categoria, lt.tarefas[i].descricao, lt.tarefas[i].estado);
  }
}

// Deletar a tarefa através do índice indicado ao listar as tarefas criadas
int deletarTarefa(ListaDeTarefas *lt, int indice) {
  if (indice < 0 || indice >= lt->qtd) {
    printf("Índice inválido. A tarefa não pode ser excluída.\n");
    return 0;
  }
  for (int i = indice; i < lt->qtd - 1; i++) {
    lt->tarefas[i] = lt->tarefas[i + 1];
  }
  lt->qtd--;
  printf("Tarefa excluída com sucesso!\n");
  return 1;
}

void limparBufferEntrada() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void alterarTarefa(ListaDeTarefas *lt, int indice) {
  if (indice >= 0 && indice < lt->qtd) {
    char resposta_1[4];
    char resposta_2[4];
    char resposta_3[4];
    char resposta_4[4];

    printf("Deseja alterar a prioridade? (sim/nao): ");
    fgets(resposta_1, sizeof(resposta_1), stdin);
    resposta_1[strcspn(resposta_1, "\n")] = '\0';
    limparBufferEntrada(); // Limpa o buffer de entrada

    if (strcmp(resposta_1, "sim") == 0) {
      printf("Nova Prioridade: ");
      fgets(resposta_1, sizeof(resposta_1), stdin);
      sscanf(resposta_1, "%d", &lt->tarefas[indice].prioridade);
      limparBufferEntrada();
    }

    printf("Deseja alterar a descrição? (sim/nao): ");
    fgets(resposta_2, sizeof(resposta_2), stdin);
    resposta_2[strcspn(resposta_2, "\n")] = '\0';
    limparBufferEntrada();

    if (strcmp(resposta_2, "sim") == 0) {
      printf("Nova Descrição: ");
      fgets(lt->tarefas[indice].descricao,
            sizeof(lt->tarefas[indice].descricao), stdin);
      lt->tarefas[indice]
          .descricao[strcspn(lt->tarefas[indice].descricao, "\n")] = '\0';
      limparBufferEntrada();
      strcpy(lt->tarefas[indice].descricao, lt->tarefas[indice].descricao);
    }

    printf("Deseja alterar a categoria? (sim/nao): ");
    fgets(resposta_3, sizeof(resposta_3), stdin);
    resposta_3[strcspn(resposta_3, "\n")] = '\0';
    limparBufferEntrada();

    if (strcmp(resposta_3, "sim") == 0) {
      printf("Nova Categoria: ");
      fgets(lt->tarefas[indice].categoria,
            sizeof(lt->tarefas[indice].categoria), stdin);
      lt->tarefas[indice]
          .categoria[strcspn(lt->tarefas[indice].categoria, "\n")] = '\0';
      limparBufferEntrada();
      strcpy(lt->tarefas[indice].categoria, lt->tarefas[indice].categoria);
    }

    printf("Deseja alterar o estado? (sim/nao): ");
    fgets(resposta_4, sizeof(resposta_4), stdin);
    resposta_4[strcspn(resposta_4, "\n")] = '\0';
    limparBufferEntrada();

    if (strcmp(resposta_4, "sim") == 0) {
      printf("Novo Estado: ");
      fgets(lt->tarefas[indice].estado,
            sizeof(lt->tarefas[indice].estado), stdin);
      lt->tarefas[indice]
          .estado[strcspn(lt->tarefas[indice].estado, "\n")] = '\0';
      limparBufferEntrada();
      strcpy(lt->tarefas[indice].estado, lt->tarefas[indice].estado);
    }

    printf("Tarefa alterada com sucesso.\n");
  } else {
    printf("Índice inválido.\n");
  }
}

void filtrar_prioridade(ListaDeTarefas lt, int prioridade){
  if (prioridade < 0 || prioridade > 11) {
    printf("Prioridade invalida.\n");
    return;
  }
  for (int i = 0; i < lt.qtd; i++) {
    if(prioridade == lt.tarefas[i].prioridade){
      printf("Tarefa %d - Prioridade %d: %s - %s - tarefa %s\n", i, lt.tarefas[i].prioridade,
           lt.tarefas[i].categoria, lt.tarefas[i].descricao, lt.tarefas[i].estado);
    }
  }
}
void filtrar_estado(ListaDeTarefas lt, char *status) {
  if (lt.qtd == 0) {
    printf("A lista de tarefas está vazia.\n");
    return;
  }
  for (int i = 0; i < lt.qtd; i++) {
    if (strcmp(status, lt.tarefas[i].estado) == 0) {
      printf("Tarefa %d - Prioridade %d: %s - %s - tarefa %s\n", i, lt.tarefas[i].prioridade,
        lt.tarefas[i].categoria, lt.tarefas[i].descricao, lt.tarefas[i].estado);
    }
  }
}
void filtrar_categoria(ListaDeTarefas lt, char *topicos){
  if (lt.qtd == 0) {
    printf("A lista de tarefas está vazia.\n");
    return;
  }
  for (int i = 0; i < lt.qtd; i++) {
    if (strcmp(topicos, lt.tarefas[i].categoria) == 0) {
      printf("Tarefa %d - Prioridade %d: %s - %s - tarefa %s\n", i, lt.tarefas[i].prioridade,
        lt.tarefas[i].categoria, lt.tarefas[i].descricao, lt.tarefas[i].estado);
    }
  }
}
void filtrar_prioridade_categoria(ListaDeTarefas lt, char *topicos, int prioridade){
  if (lt.qtd == 0) {
    printf("A lista de tarefas está vazia.\n");
    return;
  }
  for (int i = 0; i < lt.qtd; i++) {
    if ((strcmp(topicos, lt.tarefas[i].categoria) == 0) && prioridade == lt.tarefas[i].prioridade) {
      printf("Tarefa %d - Prioridade %d: %s - %s - tarefa %s\n", i, lt.tarefas[i].prioridade,
        lt.tarefas[i].categoria, lt.tarefas[i].descricao, lt.tarefas[i].estado);
    }
  }
}
void exportar_prioridade(ListaDeTarefas lt, int prioridade, const char *priorizando){
    FILE *arquivo = fopen(priorizando, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < lt.qtd; i++) {
      if(prioridade == lt.tarefas[i].prioridade){
       fprintf(arquivo, "Tarefa %d - Prioridade %d: %s - %s - tarefa %s\n", i, lt.tarefas[i].prioridade,
         lt.tarefas[i].categoria, lt.tarefas[i].descricao, lt.tarefas[i].estado);
    }
    }
    fclose(arquivo);
}
void exportar_categoria(ListaDeTarefas lt, char *topicos, const char *categorizando){
    FILE *arquivo = fopen(categorizando, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < lt.qtd; i++) {
      if (strcmp(topicos, lt.tarefas[i].categoria) == 0){
       fprintf(arquivo, "Tarefa %d - Prioridade %d: %s - %s - tarefa %s\n", i, lt.tarefas[i].prioridade,
         lt.tarefas[i].categoria, lt.tarefas[i].descricao, lt.tarefas[i].estado);
    }
    }
    fclose(arquivo);
}
