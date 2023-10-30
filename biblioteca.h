//aqui temoso arquivo de cabeçalho, na qual é usado para declarar estruturas, funções e variaveis que serão compartilhada.



#ifndef PROJETO_KAWAN_BIBLIOTECA_H
#define PROJETO_BIBLIOTECA_H

//aqui é declarada uma struct (Estrutura) chamada lista que contem tres membros.
struct lista{
    int prioridade; //inteiro que representa a prioridade da tarefa
    char categoria[300]; //  array de caractere com espaço para 300 char que armazena a categoria.
    char descricao[100]; // outro array de caractere com espaço de 100, na qual armazena a descrição da tarefa
    int estado; // array de caractere com espaço de 100, na qual armazena o estado da tarefa
};

//Aqui sao definidas as funções que serão definidas no arquivo .c

void cria_tarefa(struct lista *tarefas);
void lista_tarefas(int tam, struct lista *tarefas);
int tamanho(struct lista *tarefas);
void escreve(int tam, struct lista *tarefas);
void apaga_tarefa(int tam, struct lista *tarefas);
void deleta_tarefa(int *tam, struct lista *tarefas, int numero_tarefa);
void editar_tarefa(int tam, struct lista *tarefas);
void bubbleSort(int tam, struct lista *tarefas);
int compara(char *str1, char *str2);
void exportar_categoria(int tam, struct lista *tarefas, char *categoria);
void exportar_prioridade(int tam, struct lista *tarefas, int prioridade);
void exportarPC(int tam, struct lista *tarefas, int prioridade, char *categoria);
#endif
