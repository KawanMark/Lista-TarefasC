#include "biblioteca.h"
#include <stdio.h>

// Função para criar uma nova tarefa na qual recebe um ponteiro para nossa estrutura.
// Aqui socilicitamos ao usuario a prioridade da tarefa, validando se esta no intervalo de 1 a 10 para preencher as informações da tarefa.
void cria_tarefa(struct lista *tarefas)
{
    int prioridade;
    int estado;

    // Solicita a prioridade da tarefa ao usuário e valida
    do
    {
        printf("Insira a prioridade da tarefa (de 1 a 10): ");
        scanf("%d", &prioridade);

        if (prioridade < 1 || prioridade > 10)
        {
            printf("\nATENCAO! Prioridade invalida. Use numeros de 1 a 10.\n");
        }
    } while (prioridade < 1 || prioridade > 10);
    
    do
    {
        printf("Insira o estado da tarefa (0 para nao concluica, 1 para concluida: ) ");
        scanf("%d", &estado);

        if (estado !=0 && estado != 1)
        {
            printf("\nATENCAO! Estado invalido. Use numeros de 0 a 1.\n");
        };

            
    }
    while (estado !=0 && estado != 1);
    

    // Preenche informações da tarefa
    tarefas->prioridade = prioridade;
    tarefas->estado = estado;
    printf("\nInsira a categoria da tarefa: ");
    scanf(" %299[^\n]", tarefas->categoria);
    printf("\nInsira a descricao da tarefa: ");
    scanf(" %99[^\n]", tarefas->descricao);
}

// Função para listar as tarefas
void lista_tarefas(int tam, struct lista *tarefas)
{
    printf("Digite o estado da tarefa que deseja listar (0 para nao concluida, 1 para concluida): \n");
    int estado;
    scanf("%d", &estado);

    if(estado == 1){
        for (int i = 0; i < tam; i++)
        {
            if(tarefas[i].estado == 1){
                printf("Tarefa %d\n", i + 1);
                printf("Prioridade: %d\n", tarefas[i].prioridade);
                printf("Categoria: %s\n", tarefas[i].categoria);
                printf("Descricao: %s\n\n", tarefas[i].descricao);
                printf("Estado: Concluida\n\n");

            }
        }
    }

    else if(estado == 0){
        for(int i = 0; i < tam; i++){
            if(tarefas[i].estado == 0 ){
                printf("Tarefa %d\n", i + 1);
                printf("Prioridade: %d\n", tarefas[i].prioridade);
                printf("Categoria: %s\n", tarefas[i].categoria);
                printf("Descricao: %s\n\n", tarefas[i].descricao);
                printf("Estado: Concluida\n\n");

            }
        }
    }
}

// Função para obter o tamanho atual da lista de tarefas
// Aqui recebemos um ponteiro para um array de tarefas como argumento e em seguida abriremos o arquivo para leitura binária.
// Támbem le e conta as tarefas no arquivo, retornando um inteiro de tarefas encontradas.
int tamanho(struct lista *tarefas)
{
    FILE *arquivo = fopen("lista_de_tarefas", "rb");
    int cont = 0;
    if (arquivo)
    {
        // Lê e conta as tarefas no arquivo
        while (fread(&tarefas[cont], sizeof(struct lista), 1, arquivo) == 1)
        {
            cont++;
        }
        fclose(arquivo);
    }
    return cont;
}

// Função para escrever as tarefas em um arquivo.
// Aqui recebemos o tamanho da lista de tarefas e um array de tarefa como argumentos.
// Aqui faremos a escrita binária e em seguida escrever as tarefas no arquivo.
void escreve(int tam, struct lista *tarefas)
{
    FILE *arquivo = fopen("lista_de_tarefas", "wb");
    ;

    if (arquivo)
    {
        // Escreve as tarefas no arquivo
        fwrite(tarefas, sizeof(struct lista), tam, arquivo);
    }
    fclose(arquivo);
}

// Função para deletar uma tarefa:
// Nesta função recebemos um ponteiro para o tamanho da lista de tarefas, um array de tarefas e o numero de tarefas a ser deletada.
// Aqui excluimos a tarefa pelo numero na qual é dada.
void deleta_tarefa(int *tam, struct lista *tarefas, int numero_tarefa)
{
    if (numero_tarefa < 1 || numero_tarefa > *tam)
    {
        printf("Numero de tarefa invalido. Use um numero de 1 a %d.\n", *tam);
        return;
    }

    // Move as tarefas seguintes uma posição para trás
    for (int i = numero_tarefa - 1; i < *tam - 1; i++)
    {
        tarefas[i] = tarefas[i + 1];
    }

    (*tam)--; // Reduz o tamanho da lista
    printf("Tarefa numero %d foi deletada com sucesso.\n", numero_tarefa);
}

void editar_tarefa(int tam, struct lista *tarefas){
    int numero_tarefa;
    printf("Insira o numero da tarefa que deseja editar: ");
    scanf("%d", &numero_tarefa);
    if (numero_tarefa < 1 || numero_tarefa > tam)
    {
        printf("Numero de tarefa invalido. Use um numero de 1 a %d.\n", tam);
        return;
    }
    printf("Insira a nova prioridade da tarefa: ");
    scanf("%d", &tarefas[numero_tarefa - 1].prioridade);

    int novo_estado;
    do {
        printf("Insira o novo estado da tarefa (0 para não concluída, 1 para concluída): ");
        scanf("%d", &novo_estado);
        if (novo_estado != 0 && novo_estado != 1) {
            printf("ATENCAO! Estado inválido. Use 0 ou 1.\n");
        }
    } while (novo_estado != 0 && novo_estado != 1);
    
    tarefas[numero_tarefa - 1].estado = novo_estado;


    printf("Insira a nova categoria da tarefa: ");
    scanf(" %299[^\n]", tarefas[numero_tarefa - 1].categoria);
    printf("Insira a nova descricao da tarefa: ");
    scanf(" %99[^\n]", tarefas[numero_tarefa - 1].descricao);
    printf("Tarefa numero %d foi editada com sucesso.\n", numero_tarefa);

    escreve(tam, tarefas);
}
