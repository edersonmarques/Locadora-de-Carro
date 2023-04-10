#include <stdio.h>
#include <stdlib.h>
#define numero_maximo_carros 30

struct carro {
        char marca[20];
        char modelo[20];
        char placa[10];
        float valor;
        int alugado;
        
};

void listarDisponiveis(struct carro lista_carros[], int *numero_carros) {
    int contador;
    for (contador = 0; contador < *numero_carros; contador ++) {
        lista_carros[contador];
    }
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
    printf("Digite a marca do carro: ");
    scanf(" %19s", lista_carros[*numero_carros].marca);
    scanf("%*[^\n]");
    printf("Digite o modelo do carro: ");
    scanf(" %19s", lista_carros[*numero_carros].modelo);
    scanf("%*[^\n]");
    printf("Digite a placa do carro: ");
    scanf(" %9s", lista_carros[*numero_carros].placa);
    scanf("%*[^\n]");
    printf("Digite o valor do carro: ");
    scanf("%f", &lista_carros[*numero_carros].valor);
    lista_carros[*numero_carros].alugado = 0;

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
                    printf("O limite de carros foi atingido. \nPressione enter para continuar. ");
                    scanf("%*[^\n]s");
                }
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