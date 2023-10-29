//aqui temoso arquivo de cabeçalho, na qual é usado para declarar estruturas, funções e variaveis que serão compartilhada.



#ifndef PROJETO_KAWAN_HENRIQUE_BIBLIOTECA_H
#define PROJETO_KAWAN_HENRIQUE_BIBLIOTECA_H

//aqui é declarada uma struct (Estrutura) chamada lista que contem tres membros.
struct lista{
    int prioridade; //inteiro que representa a prioridade da tarefa
    char categoria[300]; //  array de caractere com espaço para 300 char que armazena a categoria.
    char descricao[100]; // outro array de caractere com espaço de 100, na qual armazena a descrição da tarefa
};

//Aqui sao definidas as funções que serão definidas no arquivo .c

void cria_tarefa(struct lista *tarefas);
void lista_tarefas(int tam, struct lista *tarefas);
int tamanho(struct lista *tarefas);
void escreve(int tam, struct lista *tarefas);
void apaga_tarefa(int tam, struct lista *tarefas);
void deleta_tarefa(int *tam, struct lista *tarefas, int numero_tarefa);

#endif
