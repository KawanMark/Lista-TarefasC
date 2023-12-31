#include "biblioteca.h"
#include <stdio.h>

// Função para criar uma nova tarefa na qual recebe um ponteiro para nossa estrutura.
// Aqui socilicitamos ao usuario a prioridade da tarefa, validando se esta no intervalo de 1 a 10 para preencher as informações da tarefa.
// 1 para mais importante e 10 para menos importante, aqui tambem soclicito o estado, 1 para concluida, 2 para em andamento e 0 para não concluida.
void cria_tarefa(struct lista *tarefas)
{
    int prioridade;
    int estado;

    // Solicita a prioridade da tarefa ao usuário e valida por um loop.
    do
    {
        printf("Insira a prioridade da tarefa (de 1 para mais importante a 10 menos importante): \n");
        scanf("%d", &prioridade);

        if (prioridade < 1 || prioridade > 10)
        {
            printf("\nATENCAO! Prioridade invalida. Use numeros de 1 a 10.\n");
        }
    } while (prioridade < 1 || prioridade > 10);
    
    //mesma coisa que a prioridade porem agora faz um loop pedindo o estado da tarefa.
    do
    {
        printf("Insira o estado da tarefa: \n");
        printf("0 para nao concluida\n");
        printf("1 para concluida\n");
        printf("2 para andamento\n");
        scanf("%d", &estado);
        
        if (estado !=0 && estado != 1 && estado != 2) // se o estado digitado nao satisfazer a minha condição, printa o invalido.
        {
            printf("\nATENCAO! Estado invalido. Use numeros de 0 a 1.\n");
        };

            
    }
    while (estado !=0 && estado != 1 && estado != 2);
    

    // Preenche informações da tarefa
    tarefas->prioridade = prioridade;
    tarefas->estado = estado;
    printf("\nInsira a categoria da tarefa: ");
    scanf(" %299[^\n]", tarefas->categoria);
    printf("\nInsira a descricao da tarefa: ");
    scanf(" %99[^\n]", tarefas->descricao);
}


// esta função compara foi criada para comparar duas strings, na qual retorna 0 se forem iguais, 1 se a primeira for maior e -1 se a segunda for maior.
//esta função olha os caracteres para retornar sempre a menor lexicograficamente .
int compara(char *str1, char *str2){ 
    while (*str1 && *str2){
        if(*str1 < *str2){
            return -1;
        }
        else if(*str1 > *str2){
            return 1;
        }

        str1++;
        str2++;
    }

    if(*str1){
        return 1;
    }
    else if(*str2){
        return -1;
    }

    return 0;
}

//ordenar tarefas por prioridade.
// esta função classifica um array de estrutura, com base nos criterios de prioridade e tambem categoria.
// esta função recebe dois parametros, comparando os elementos e trocando se estiverem fora de ordem, serve para listar na ordem certa.
void bubbleSort(int tam, struct lista *tarefas){
    struct lista temp;

    for(int i = 0; i < tam - 1; i++){ //controla o número de passagens através da lista
        for(int j = 0; j < tam - i - 1; j++){ //percorre os elementos e compara adjacentes.
            if(tarefas[j].prioridade > tarefas[j+1].prioridade){
                //aqui kawan mark troca as tarefas ne 
                temp = tarefas[j];
                tarefas[j] = tarefas[j+1];
                tarefas[j+1] = temp;
            }

            else if(tarefas[j].prioridade == tarefas[j + 1].prioridade && compara(tarefas[j].categoria, tarefas[j + 1].categoria) > 0){
                temp = tarefas[j];
                tarefas[j] = tarefas[j+1];
                tarefas[j+1] = temp;
            }
        }
    }
}

// Função para listar as tarefas, na qual pedimos o estado da tarefa ou todas as tarefas.
void lista_tarefas(int tam, struct lista *tarefas)
{
    printf("Insira o estado ou categoria da tarefa: \n");
    printf("0 para nao concluida\n");
    printf("1 para concluida\n");
    printf("2 para andamento\n");
    printf("3 para todas as tarefas\n");
    printf("4 para categorias\n ");
    int estado;
    scanf("%d", &estado);

    bubbleSort(tam, tarefas); // chamando a função acima para ordenar.



    if(estado == 1){ // se o estado for 1, percorra a lista de tarefas e printe as tarefas concluidas.
        for (int i = 0; i < tam; i++)
        {
            if(tarefas[i].estado == 1){
                printf("---------------------------\n");
                printf("Tarefa %d\n", i + 1);
                printf("Prioridade: %d\n", tarefas[i].prioridade);
                printf("Categoria: %s\n", tarefas[i].categoria);
                printf("Descricao: %s\n\n", tarefas[i].descricao);
                printf("Estado: Concluida\n\n");
                printf("---------------------------\n");

            }
        }
    }

    else if(estado == 2){ // se o estado for 2, perccorra a lista de tarefas e printe as tarefas em andamento.
        for(int i = 0; i < tam; i++){
            if(tarefas[i].estado == 2){
                printf("---------------------------\n");
                printf("Tarefa %d\n", i + 1);
                printf("Prioridade: %d\n", tarefas[i].prioridade);
                printf("Categoria: %s\n", tarefas[i].categoria);
                printf("Descricao: %s\n\n", tarefas[i].descricao);
                printf("Estado: Em andamento...\n\n");
                printf("---------------------------\n");
            }
        }
    }

    else if(estado == 3){ // se o estado for 3, percorrera a lista de tarefas e printe todas as tarefas.
        for(int i = 0; i < tam; i++){
            printf("---------------------------\n");
            printf("Tarefa %d\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Descricao: %s\n\n", tarefas[i].descricao);
            printf("Estado: %d\n\n", tarefas[i].estado);
            printf("---------------------------\n");
        }
    }

    else if(estado == 0){ // se a tarefa for 0, percorra a lista de tarefas e printe as tarefas não concluidas.
        for(int i = 0; i < tam; i++){
            if(tarefas[i].estado == 0 ){
                printf("---------------------------\n");
                printf("Tarefa %d\n", i + 1);
                printf("Prioridade: %d\n", tarefas[i].prioridade);
                printf("Categoria: %s\n", tarefas[i].categoria);
                printf("Descricao: %s\n\n", tarefas[i].descricao);
                printf("Estado: Nao Concluida\n\n");
                printf("---------------------------\n");

            }
        }
    }

    else if(estado == 4){
        char categoria[50];
        printf("Digite a categoria que deseja listar: \n");
        scanf(" %50[^\n]", categoria);
        for(int i = 0; i < tam; i++){
            if(compara(tarefas[i].categoria, categoria) == 0){
                printf("---------------------------\n");
                printf("Tarefa %d\n", i + 1);
                printf("Prioridade: %d\n", tarefas[i].prioridade);
                printf("Categoria: %s\n", tarefas[i].categoria);
                printf("Descricao: %s\n\n", tarefas[i].descricao);
                printf("Estado: %d\n\n", tarefas[i].estado);
                printf("---------------------------\n");
            }
        }
    }
    else{
        printf("Estado invalido !!!\n");
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

//aqui temos a função de editar tarefa, na qual recebe o tamanho da lista de tarefas e um array de tarefas.
//aqui editamos a tarefa pelo numero da tarefa, na qual é dada.
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
    printf("1 para mais importante e 10 para menos importante: ");
    scanf("%d", &tarefas[numero_tarefa - 1].prioridade);

    int novo_estado;
    do {
        printf("Insira o novo estado da tarefa (0 para não concluída, 1 para concluída e 2 para em andamento): ");
        scanf("%d", &novo_estado);
        if (novo_estado != 0 && novo_estado != 1 && novo_estado != 2) {
            printf("ATENCAO! Estado inválido. Use 0, 1 ou 2.\n");
        }
    } while (novo_estado != 0 && novo_estado != 1 && novo_estado != 2);
    
    tarefas[numero_tarefa - 1].estado = novo_estado;

    //apos a verifcação e adicionar a nova prioridade e estado, agora editamos a categoria e a descrição da tarefa.
    printf("Insira a nova categoria da tarefa: ");
    scanf(" %299[^\n]", tarefas[numero_tarefa - 1].categoria);
    printf("Insira a nova descricao da tarefa: ");
    scanf(" %99[^\n]", tarefas[numero_tarefa - 1].descricao);
    printf("Tarefa numero %d foi editada com sucesso.\n", numero_tarefa);
    //aqui reescrevemos a tarefa.
    escreve(tam, tarefas);
}

//aqui tem a função que exporta por prioridade, na qual recebemos tres parametros, o tamanho, a struct lista e a prioridade.
void exportar_prioridade(int tam, struct lista *tarefas, int prioridade){
     FILE *arquivo = fopen("tarefas_por_prioridade.txt", "w"); //aqui cria um arquivo chamado tarefas_por_prioridade.txt para escrever as tarefas.
    
    if (arquivo) {
        for (int i = 0; i < tam; i++) {
            if (tarefas[i].prioridade == prioridade) { // aqui verifica a prioridade da tarefa e escreve no arquivo.
                fprintf(arquivo, "Prioridade: %d\n", tarefas[i].prioridade);
                fprintf(arquivo, "Categoria: %s\n", tarefas[i].categoria);
                fprintf(arquivo, "Estado: %d\n", tarefas[i].estado);
                fprintf(arquivo, "Descricao: %s\n\n", tarefas[i].descricao);
            }
        }
        //Após concluir a iteração e escrever todas as tarefas com a prioridade desejada no arquivo, a função fecha o arquivo usando fclose.
        fclose(arquivo);
        printf("Tarefas de prioridade %d exportadas com sucesso para 'tarefas_por_prioridade.txt'\n", prioridade);
    } else {
        printf("Erro ao abrir o arquivo para exportação.\n");
    }
}


//outra função de exportar porem agora exporta por categoria, na qual recebe tres parametros, o tamanho, a struct lista e a categoria.
void exportar_categoria(int tam, struct lista *tarefas, char *categoria){
    FILE *arquivo = fopen("tarefas_por_categoria.txt", "w");

    if(arquivo){
        for(int i = 0; i < tam; i++){
            if(compara(tarefas[i].categoria, categoria) == 0){ // aqui verifica a categoria da tarefa e escreve no arquivo.
                fprintf(arquivo, "Prioridade: %d\n", tarefas[i].prioridade);
                fprintf(arquivo, "Categoria: %s\n", tarefas[i].categoria);
                fprintf(arquivo, "Estado: %d\n", tarefas[i].estado);
                fprintf(arquivo, "Descricao: %s\n\n", tarefas[i].descricao);

            }
        }
        fclose(arquivo);
        printf("Tarefas de categoria %s exportadas com sucesso para 'tarefas_por_categoria.txt'\n", categoria);
    }
    else{
        printf("Erro ao abrir o arquivo para exportação.\n\n");
    }
}

//aqui chamei a função de exportar por categoria e prioridade, na qual recebe quatro parametros, o tamanho, a struct lista, a prioridade e a categoria.
//o nome PC pois exporta PrioridadeCategoria.
void exportarPC(int tam, struct lista *tarefas, int prioridade, char *categoria) {
    FILE *arquivo = fopen("tarefas.txt", "w");
    
    if (arquivo) {
        for (int i = 0; i < tam; i++) { //aqui percorre verificando a prioridade e a categoria da tarefa e escreve no arquivo.
            if (tarefas[i].prioridade == prioridade && compara(tarefas[i].categoria, categoria) == 0) { // aqui verifica a prioridade e a categoria da tarefa e escreve no arquivo, utilizando a função compara string criada anteriomente para verificar a existencia.
                fprintf(arquivo, "Prioridade: %d\n", tarefas[i].prioridade);
                fprintf(arquivo, "Categoria: %s\n", tarefas[i].categoria);
                fprintf(arquivo, "Estado: %d\n", tarefas[i].estado);
                fprintf(arquivo, "Descricao: %s\n\n", tarefas[i].descricao);
            }
        }
        fclose(arquivo);
        printf("Tarefas de prioridade %d e categoria '%s' exportadas com sucesso para 'tarefas.txt'\n", prioridade, categoria);
    } else {
        printf("Erro ao abrir o arquivo para exportação.\n");
    }
}