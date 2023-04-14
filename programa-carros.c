#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define numero_maximo_carros 30

struct carro {
        char marca[20];
        char modelo[20];
        char placa[10];
        char cor[10];
        float valor;
        int alugado;
        
};

void alugarCarro(struct carro lista_carros[], int numero_carros, char modelo[20]) {
    int posicao;
    for (posicao = 0; posicao < numero_carros; posicao ++) {
        if ((strcmp(modelo, lista_carros[posicao].modelo) == 0) && (lista_carros[posicao].alugado == 0)) {
            lista_carros[posicao].alugado = 1;
            return;
        } else if (posicao == numero_carros) {
            printf("Não existe um carro deste modelo disponível, presione ENTER para continuar.   ");
            scanf("%*c");
            getchar();
            return;
        }
        
    }
}

void devolverCarro(struct carro lista_carros[], int numero_carros, char placa[10]) {
    int posicao;
    for (posicao = 0; posicao < numero_carros; posicao ++) {
        if (strcmp(lista_carros[posicao].placa, placa) == 0) {
            lista_carros[posicao].alugado = 0;
            return;
        }
    }
}

void listarDisponiveis(struct carro lista_carros[], int numero_carros) {
    int posicao;
    system("clear");
    printf("Carros disponíveis: \n\n");
    for (posicao = 0; posicao < numero_carros; posicao ++) {
        if (lista_carros[posicao].alugado == 0) {
            printf("Carro %d - [marca: %s, modelo: %s, placa: %s, cor: %s, valor: %f]\n\n" , posicao + 1, lista_carros[posicao].marca, lista_carros[posicao].modelo, lista_carros[posicao].placa, lista_carros[posicao].cor, lista_carros[posicao].valor);
        }
    }

    printf("Pressione ENTER para continuar: ");
    scanf("%*c");
    getchar();
}

void listarPorModelo(struct carro lista_carros[], int numero_carros, char modelo[20]) {
    system("clear");
    int posicao;
    printf("Os carros do modelo %s são: \n\n", modelo);
    for (posicao = 0; posicao < numero_carros; posicao ++) {
        if (strcmp(lista_carros[posicao].modelo, modelo) == 0) {
            printf("Carro %d - [marca: %s, modelo: %s, placa: %s, cor: %s, valor: %f]\n\n" , posicao + 1, lista_carros[posicao].marca, lista_carros[posicao].modelo, lista_carros[posicao].placa, lista_carros[posicao].cor, lista_carros[posicao].valor);
        }
    }
    printf("Pressione ENTER para continuar: ");
    scanf("%*c");
    getchar();
}

void exibirStatus(struct carro lista_carros[], int numero_carros, char placa[10]) {
    int posicao;
    system("clear");
    for (posicao = 0; posicao < numero_carros; posicao ++) {
        if (strcmp(lista_carros[posicao].placa, placa) == 0) {
            if (lista_carros[posicao].alugado) {
                printf("O carro de placa %s não está disponível para alugar.", placa);   
            } else {
                printf("O carro de placa %s está disponível para alugar.", placa);
            }
        } else if (posicao == numero_carros) {
            printf("Não existe um carro de placa %s no sistema.", placa);
        }
        
    }
        printf("\n\nPressione ENTER para continuar.");
        scanf("%*c");
        getchar();
}

void gerarMenu() {
    printf("------------MENU------------\n\nPor favor, digite uma das opções abaixo: \n\n");
    printf("[1] - Listar carros disponíveis\n");
    printf("[2] - Listar carros por modelo\n");
    printf("[3] - Exibir status de um carro\n");
    printf("[4] - Aquisição de um carro\n");
    printf("[5] - Remoção de carro\n");
    printf("[6] - Aluguel de um carro\n");
    printf("[7] - Devolução de um carro\n");
    printf("[8] - SAIR\n\n\n");
}

void aquisicaoCarro(struct carro lista_carros[], int *numero_carros) {
    system("clear");
    printf("Digite a marca do carro: ");
    scanf(" %19s", lista_carros[*numero_carros].marca);
    scanf("%*[^\n]");
    printf("Digite o modelo do carro: ");
    scanf(" %19s", lista_carros[*numero_carros].modelo);
    scanf("%*[^\n]");
    printf("Digite a placa do carro: ");
    scanf(" %9s", lista_carros[*numero_carros].placa);
    scanf("%*[^\n]");
    printf("Digite a cor do carro: ");
    scanf(" %9s", lista_carros[*numero_carros].cor);
    scanf("%*[^\n]");
    printf("Digite o valor do carro: ");
    scanf("%f", &lista_carros[*numero_carros].valor);
    lista_carros[*numero_carros].alugado = 0;
    *numero_carros = *numero_carros + 1;

}

void remocaoCarro(struct carro lista_carros[], char placa[10], int *numero_carros) {
    int posicao;

    for (posicao = 0; posicao < *numero_carros; posicao ++) {
        if ((strcmp(lista_carros[posicao].placa, placa) == 0)) {
            lista_carros[posicao].alugado = lista_carros[*numero_carros - 1].alugado;
            strcpy(lista_carros[posicao].cor, lista_carros[*numero_carros - 1].cor);
            strcpy(lista_carros[posicao].marca, lista_carros[*numero_carros - 1].marca);
            strcpy(lista_carros[posicao].modelo, lista_carros[*numero_carros - 1].modelo);
            strcpy(lista_carros[posicao].placa, lista_carros[*numero_carros - 1].placa);
            lista_carros[posicao].valor = lista_carros[*numero_carros - 1].valor;
            *numero_carros = *numero_carros - 1;
            return;
        }
    }
    return;
}

int main() {
    struct carro lista_carros[30];
    int entrada_usuario;
    int numero_carros = 0;
    do {
        system("clear");
        gerarMenu();
        scanf("%d", &entrada_usuario);
        switch (entrada_usuario) {
            case 1:
                listarDisponiveis(lista_carros, numero_carros);
                break;
            case 2:
                system("clear");
                char modelo_listar[20];
                printf("Digite o modelo dos carros a serem listados: ");
                scanf(" %19s", modelo_listar);
                listarPorModelo(lista_carros, numero_carros, modelo_listar);
                break;
            case 3:
                system("clear");
                char placa_exibir[10];
                printf("Digite a placa do carro que você deseja consultar o status: ");
                scanf(" %9s", placa_exibir);
                scanf("%*[^\n]s");
                exibirStatus(lista_carros, numero_carros, placa_exibir);
                break;

            case 4:
                if (numero_carros < numero_maximo_carros) {
                    aquisicaoCarro(lista_carros, &numero_carros);
                } else {
                    system("clear");
                    printf("O limite de carros foi atingido. \nPressione ENTER para continuar. ");
                    scanf("%*c");
                    getchar();
                }
                break;
            case 5:
                system("clear");
                char placa_remover[10];
                printf("Digite a placa do carro a ser removido: ");
                scanf(" %9s", placa_remover);
                scanf("%*[^\n]");
                remocaoCarro(lista_carros, placa_remover, &numero_carros);
                break;
            case 6:
                system("clear");
                char modelo_alugar[20];
                printf("Digite o modelo do carro que deseja alugar: ");
                scanf(" %19s", modelo_alugar);
                scanf("%*[^\n]s");
                alugarCarro(lista_carros, numero_carros, modelo_alugar);
                break;

            case 7:
                system("clear");
                char placa_devolver[10];
                printf("Digite a placa do carro a ser devolvido: ");
                scanf(" %9s", placa_devolver);
                scanf("%*[^\n]s");
                devolverCarro(lista_carros, numero_carros, placa_devolver);
                break;
            default:
                break;
        }
    } while (entrada_usuario != 8);
    return 0;
}


/*- Aquisição de um carro. A locadora, devido a seu espaço físico, se limita a ter no máximo 30 carros. Faça uma implementação de inclusão que atenda a este limite. Sugestão: Utilize uma variável para controlar o número de carros existentes na locadora, a cada novo carro adquirido some um a esta variável.
O registro de carros deve conter os seguintes campos:
Marca
Modelo
Cor
Placa
Valor
Alugado

-Remoção de Carro. Implemente um procedimento que após a entrada da placa do carro diminua um daquela variável de controle utilizada no procedimento de inclusão e logo após elimine o registro (como se trata de um vetor, a posição em que o registro se encontra não será realmente excluída, mas terão que entrar aí dados válidos de outros carros).
-Aluguel de Carro. O usuário deverá perguntar o modelo do carro, se for encontrado um carro deste modelo disponível , marcá-lo como alugado.
-Devolução de um carro. O usuário deverá perguntar a placa do carro e então se este estiver alugado , marcá-lo como disponível.
-Listagem de Carros por Modelo. Pedir o modelo do carro e listar os dados de todos os carros deste modelo.
-Listagem de todos os carros disponíveis naquele momento.
- Informação do status de um carro. Entrar com a placa do carro, o programa deverá informar se este está alugado ou não.

Obs: Utilizar pelo menos uma função para implementar cada requisito do programa;
Utilizar um vetor de struct para o armazenar os dados.*/