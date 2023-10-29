#include "biblioteca.h"
#include <stdio.h>

// Função para criar uma nova tarefa na qual recebe um ponteiro para nossa estrutura.
//Aqui socilicitamos ao usuario a prioridade da tarefa, validando se esta no intervalo de 1 a 10 para preencher as informações da tarefa.
void cria_tarefa(struct lista *tarefas) {
    int prioridade;

    // Solicita a prioridade da tarefa ao usuário e valida
    do {
        printf("Insira a prioridade da tarefa (de 1 a 10): ");
        scanf("%d", &prioridade);

        if (prioridade < 1 || prioridade > 10) {
            printf("\nATENCAO! Prioridade invalida. Use numeros de 1 a 10.\n");
        }
    } while (prioridade < 1 || prioridade > 10);

    // Preenche informações da tarefa
    tarefas->prioridade = prioridade;
    printf("\nInsira a categoria da tarefa: ");
    scanf(" %299[^\n]", tarefas->categoria);
    printf("\nInsira a descricao da tarefa: ");
    scanf(" %99[^\n]", tarefas->descricao);
}

// Função para listar as tarefas
void lista_tarefas(int tam, struct lista *tarefas){
    for(int i = 0; i < tam; i++){
        printf("Tarefa %d\n", i+1);
        printf("Prioridade: %d\n",tarefas[i].prioridade);
        printf("Categoria: %s\n",tarefas[i].categoria );
        printf("Descricao: %s\n\n",tarefas[i].descricao);
    }
}


// Função para obter o tamanho atual da lista de tarefas
// Aqui recebemos um ponteiro para um array de tarefas como argumento e em seguida abriremos o arquivo para leitura binária.
//Támbem le e conta as tarefas no arquivo, retornando um inteiro de tarefas encontradas.
int tamanho(struct lista *tarefas) {
    FILE *arquivo = fopen("lista_de_tarefas", "rb");
    int cont = 0;
    if (arquivo) {
        // Lê e conta as tarefas no arquivo
        while (fread(&tarefas[cont], sizeof(struct lista), 1, arquivo) == 1) {
            cont++;
        }
        fclose(arquivo);
    }
    return cont;
}


// Função para escrever as tarefas em um arquivo.
// Aqui recebemos o tamanho da lista de tarefas e um array de tarefa como argumentos.
//Aqui faremos a escrita binária e em seguida escrever as tarefas no arquivo.
void escreve(int tam, struct lista *tarefas) {
    FILE *arquivo= fopen("lista_de_tarefas", "wb");;

    if (arquivo) {
        // Escreve as tarefas no arquivo
        fwrite(tarefas, sizeof(struct lista), tam, arquivo);
    }
    fclose(arquivo);
}


// Função para deletar uma tarefa:
//Nesta função recebemos um ponteiro para o tamanho da lista de tarefas, um array de tarefas e o numero de tarefas a ser deletada.
//Aqui excluimos a tarefa pelo numero na qual é dada.
void deleta_tarefa(int *tam, struct lista *tarefas, int numero_tarefa) {
    if (numero_tarefa < 1 || numero_tarefa > *tam) {
        printf("Numero de tarefa invalido. Use um numero de 1 a %d.\n", *tam);
        return;
    }

    // Move as tarefas seguintes uma posição para trás
    for (int i = numero_tarefa - 1; i < *tam - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }

    (*tam)--; // Reduz o tamanho da lista
    printf("Tarefa numero %d foi deletada com sucesso.\n", numero_tarefa);
}
