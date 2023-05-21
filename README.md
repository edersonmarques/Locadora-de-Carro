# Locadora-de-Carro 

### Obs: este é um exercício feito para minha faculdade, este readme possui o enunciado.


Requisitos: 

- Aquisição de um carro. A locadora, devido a seu espaço físico, se limita a ter no máximo 30 carros. Faça uma implementação de inclusão que atenda a este limite. Sugestão: Utilize uma variável para controlar o número de carros existentes na locadora, a cada novo carro adquirido some um a esta variável.
O registro de carros deve conter os seguintes campos:
Marca
Modelo
Cor
Placa
Valor
Alugado

- Remoção de Carro. Implemente um procedimento que após a entrada da placa do carro diminua um daquela variável de controle utilizada no procedimento de inclusão e logo após elimine o registro (como se trata de um vetor, a posição em que o registro se encontra não será realmente excluída, mas terão que entrar aí dados válidos de outros carros).
-Aluguel de Carro. O usuário deverá perguntar o modelo do carro, se for encontrado um carro deste modelo disponível , marcá-lo como alugado.

- Devolução de um carro. O usuário deverá perguntar a placa do carro e então se este estiver alugado , marcá-lo como disponível.
- Listagem de Carros por Modelo. Pedir o modelo do carro e listar os dados de todos os carros deste modelo.
- Listagem de todos os carros disponíveis naquele momento.
- Informação do status de um carro. Entrar com a placa do carro, o programa deverá informar se este está alugado ou não.

- Obs: Utilizar pelo menos uma função para implementar cada requisito do programa;
Utilizar um vetor de struct para o armazenar os dados.
