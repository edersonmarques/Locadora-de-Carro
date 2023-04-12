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
    int contador;
    for (contador = 0; contador < numero_carros; contador ++) {
        if ((strcmp(modelo, lista_carros[contador].modelo) == 0) && (lista_carros[contador].alugado == 0)) {
            lista_carros[contador].alugado = 1;
            return;
        } else {
            printf("Não existe um carro deste modelo disponível, presione ENTER para continuar.   ");
            scanf("%*c");
            getchar();
            return;
        }
    }
}

void devolverCarro(struct carro lista_carros[], int *numero_carros, char modelo[20]) {

}

void listarDisponiveis(struct carro lista_carros[], int *numero_carros) {
    int contador;
    system("clear");
    printf("Carros disponíveis: \n\n");
    for (contador = 0; contador < *numero_carros; contador ++) {
        if (lista_carros[contador].alugado == 0) {
            printf("Carro %d - [marca: %s, modelo: %s, placa: %s, cor: %s, valor: %f]\n\n" , contador + 1, lista_carros[contador].marca, lista_carros[contador].modelo, lista_carros[contador].placa, lista_carros[contador].cor, lista_carros[contador].valor);
        }
    }

    printf("Digite enter para continuar: ");
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

void remocaoCarro() {

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
                listarDisponiveis(lista_carros, &numero_carros);
                break;

            case 4:
                if (numero_carros < numero_maximo_carros) {
                    aquisicaoCarro(lista_carros, &numero_carros);
                } else {
                    system("clear");
                    printf("O limite de carros foi atingido. \nPressione enter para continuar. ");
                    scanf("%*c");
                    getchar();
                }
                break;
            case 6:
                system("clear");
                char modelo[20];
                printf("Digite o modelo do carro que deseja alugar: ");
                scanf(" %19[^\n]s", modelo);
                scanf("%*[^\n]s");
                alugarCarro(lista_carros, numero_carros, modelo);
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