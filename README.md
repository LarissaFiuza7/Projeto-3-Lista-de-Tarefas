# Lista de Tarefas Projeto_3
Projeto da disciplina CC2632 - DESENVOLVIMENTO DE ALGORITMOS do Centro Universitário FEI.

# Descrição do Projeto

Neste projeto, a continuação do desenvolvimento da lista de tarefas iniciada no Projeto 1 será abordada. O objetivo é aprimorar o sistema de gerenciamento de tarefas, introduzindo novas funcionalidades. O Projeto 1 tem como objetivo implementar um programa de gerenciamento de uma lista de tarefas em linguagem C. Cada tarefa é caracterizada por uma descrição, uma categoria e uma prioridade, sendo que a prioridade é representada por um valor inteiro (quanto maior o valor, maior a prioridade da tarefa). O programa deve ter a capacidade de armazenar até 100 tarefas e permitir ao usuário cadastrar, deletar e listar as tarefas.

# Requisitos

* O programa deve ser desenvolvido em C.

* Capacidade de armazenar até 100 tarefas.

* Operações obrigatórias: cadastrar, listar e deletar tarefas.

* Os dados das tarefas devem ser armazenados em arquivos binários usando funções para leitura (fread) e escrita (fwrite) desses dados.

* Formato dos dados: um array de struct contendo prioridade (valor inteiro entre 0 e 10), descrição da tarefa (array de char de até 300 letras) e categoria (array de char de até 100 letras).

* Armazenar o estado da tarefa: A estrutura de dados das tarefas deve ser modificada para incluir um campo que armazene o estado da tarefa, que pode ser "completo", "em andamento" ou "não iniciado".

* Alterar tarefas: Implementar a função que permite ao usuário escolher uma tarefa e um campo a ser alterado. O programa deve sobrescrever o dado informado pelo usuário.

* Filtrar tarefas por prioridade: Listar na tela as tarefas que possuem uma prioridade escolhida pelo usuário.

* Filtrar tarefas por estado: Listar na tela as tarefas que possuem um estado escolhido pelo usuário.

* Filtrar tarefas por categoria: Listar na tela as tarefas que pertencem a uma categoria escolhida pelo usuário, com a prioridade ordenada da maior para a menor.

* Filtrar tarefas por prioridade e categoria: Exibir as tarefas que passam pelos filtros de prioridade e categoria escolhidos pelo usuário.

* Exportar tarefas por prioridade: Gerar um arquivo texto listando apenas as tarefas da prioridade escolhida pelo usuário. Cada tarefa deve estar em uma linha do arquivo, na sequência: prioridade, categoria, estado e descrição.

* Exportar tarefas por categoria: Gerar um arquivo texto listando as tarefas da categoria escolhida pelo usuário, ordenadas por prioridade.

* Exportar tarefas por prioridade e categoria: Gerar um arquivo texto listando as tarefas que passam pelos filtros de prioridade e categoria escolhidos pelo usuário.
