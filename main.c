//Nome: Kawan Mark Geronimo da Silva
//Ra: 22222010-5


#include <stdio.h>
#include "biblioteca.h" // Inclui um arquivo de cabeçalho personalizado
struct lista tarefas[100]; // Declara um array de tarefas com espaço para 100 elementos

int main() {
    int  chek = 0, escolha, tam; //Tres variaveis que serão usadas posteriomente para controle

    tam = tamanho(tarefas); // Obtém o tamanho atual da lista de tarefas

    printf("Bem vindo ao controle de tarefas!!!\n-----------------------\n");

    //While True para que o usuario tenha controle aos acessos com agilidade e eficiencia
    while (1) {
        // Apresenta um menu de opções ao usuário
        printf("\n1. Criar tarefas \n2. Deletar tarefas\n3. Listar suas tarefas\n4. Editar tarefas \n5. Exportar tarefas \n6. Sair do controle de tarefas\n---------------------------\nInsira o numero da operacao desejada:  ");
        scanf("%d", &escolha);

        //Switch case é usado para menu de opções na qual o programa le a escolha do usuario.
        switch (escolha) {
            //Caso o usuario escolha 1, verifica se o tamanho atual da lista de tarefas é igual a 100 e exibe uma mensagem de erro.
            case(1):
                if(tam == 100){
                    printf("Tamanho máximo de tarefas cadastradas, exclua algumas para cadastrar mais.\n");
                }
                //Aqui chama a função criar tarefa passando o endereço da posição do array para criar uma nova tarefa
                printf("\nBem vindo a criacao de tarefas\n");
                cria_tarefa(&tarefas[tam]); // Chama a função para criar uma nova tarefa
                tam++; // Incrementa o tamanho da lista de tarefas
                break;
            case(2):
            //Caso o usuario escolha 2, irá chamar a função de deletar tarefa, passando o tamanho atual da lista, o array e o numero da tarefa.
                printf("\nBem vindo a remocao de tarefas\n");
                int numero_tarefa;
                printf("Insira o numero da tarefa que deseja deletar: ");
                scanf("%d", &numero_tarefa);
                deleta_tarefa(&tam, tarefas, numero_tarefa); // Chama a função para deletar uma tarefa
                break;
            
            //Cao seja 3, exibe uma mensagem de boas vindas e chama a função de listar tarefa, passando o tamanho atual da lista de terefas e o array de tarefas
            case(3):
                printf("\nBem vindo a lista de tarefas\n");
                lista_tarefas(tam, tarefas); // Chama a função para listar as tarefas
                break;
            
            case(4):
                printf("\nBem vindo a edicao de tarefas\n");
                editar_tarefa(tam, tarefas); // Chama a função para editar uma tarefa
                break;

            case(5):
                if(tam == 0){
                    printf("Nenhuma tarefa para exportar !!!\n");
                }
                else{
                    printf("\nBem vindo a exportacao de tarefas\n");
                    int export;
                    printf("\n1. Exportar por prioridade\n2. Exportar por categoria\n3. Exportar tudo\n");
                    scanf("%d", &export);

                    if(export == 1){
                        int prioridade;
                        printf("Digite a prioridade que deseja exportar: \n");
                        scanf("%d", &prioridade);
                        exportar_prioridade(tam, tarefas, prioridade);
                        break;
                    }
                    
                    else if(export == 2){
                        char categoria[50];
                        printf("Digite a categoria que deseja exportar: \n");
                        scanf(" %50[^\n]", categoria);
                        exportar_categoria(tam, tarefas, categoria);
                        break;
                    }

                    else if(export == 3){
                        
                    }

                }
                

                break;

            case(6):
                printf("\nTchau :)\n");
                escreve(tam, tarefas); // Chama a função para escrever as tarefas em um arquivo e encerra o programa
                chek = 1; // Define a variável 'chek' como 1 para sair do loop
                break;
                
            default:
                printf("\nNumero invalido, escolha um numero valido\n"); // Mensagem de erro para escolha inválida
                break;
        }
        if(chek) // Sai do loop se 'chek' for igual a 1
            break;
    }
    printf("Controle de tarefas encerrado.\n\n");
}
