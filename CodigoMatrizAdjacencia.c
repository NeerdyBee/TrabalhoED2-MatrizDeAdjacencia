#include<stdio.h>
#define max 20 // Define o valor máximo de Vértices que *podem* ser inseridos na Matriz.
int matrizAdj[max][max]; // Cria uma matriz de duas dimensões, aonde o valor definido contido nelas é igual a max.
int n; // Define a variável n que será responsável por armazenar o o número de Vértices presentes na matriz.
 
void criarMatriz() { // FUNÇÃO RESPONSÁVEL PELA CRIAÇÃO DA MATRIZ DE ADJACÊNCIA
    do{ // Um laço de repetição é iniciado para que seja registrado um valor válido para o número de Vértices iniciais da Matriz.
        printf("Insira o número de Vértices da Matriz: ");
        scanf("%d", &n);
        if (n < 0 || n > max){
            printf("[ENTRADA INVÁLIDA]\nO número de Vértices não pode ser menor que zero ou maior que o número máximo de Vértices (%d). Tente Novamente.\n", max);
        }
    }while(n < 0 || n > max); // O valor de n é válido apenas se ele for um valor inteiro entre 0 e o valor de max.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            matrizAdj[i][j] = 0;
        }
    }
    inserirArestas();
}

void inserirArestas(){ // FUNÇÃO RESPONSAVEL PELA INSERÇÃO DAS ARESTAS NA MATRIZ
    int verticeOrigem, verticeDestino; // Criam as variáveis locais de vértice de origem e vértice de destino
    // verticeOrigem: Vértice da qual a aresta surge; verticeDestino: Vértice da qual a aresta chega
    printf("\n[INSERÇÃO DE ARESTAS]\n");
    do{ // Laço de repetição para realizar a inserção de arestas. Ele não possui limite uma vez que uma vértice pode se ligar a outra mais de uma vez sem limites.
        printf("\nInsira os Vértices de Origem e de Destino da %dº Aresta (Insira \"0\" em ambos para encerrar a inserção)\n", i); // Para encerrar o laço basta que os Vértices de origem e de destino sejam iguais a 0
        printf("Vértice de Origem da Aresta: ");
        scanf("%d", &verticeOrigem);
        printf("Vértice de Destino da Aresta: ");
        scanf("%d", &verticeDestino);
        if ((verticeOrigem == 0) && (verticeDestino == 0)){ // situação aonde o laço é encerrado
            printf("\n[INSERÇÃO ENCERRADA]\n");
            break;
        }
        else if (verticeOrigem > n || verticeDestino > n || verticeOrigem <= 0 || verticeDestino <= 0) { // Situação aonde o valor dos vértices inseridos não válidos
            printf("[ENTRADA INVÁLIDA]\nOs valores dos Vértices não podem ser menores ou igual a zero ou maiores que o número de Vértices. Tente Novamente.\n");
            i--;
        } else{
            matrizAdj[verticeOrigem][verticeDestino] += 1; // Este elemento na matriz recebe adiciona mais 1 representando a quantidade de arestas entre o vértice de origem e de destino
            printf("\n[INSERÇÃO REALIZADA]\n");
        }
    }while (verticeOrigem != 0 && verticeDestino != 0);
}
 
void apresentar() { // FUNCÇÃO RESPONSÁVEL POR IMPRIMIR A MATRIZ
    printf("\n[APRESENTAÇÃO DA MATRIZ]\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) // i e j percorrem pelos indexes da Matriz até chegarem ao último index 
            printf("| %4d ", matrizAdj[i][j]);
        printf("|\n");
    }
}
 
void inserirVertice() {
    printf("\n[INSERÇÃO DE UM NOVO VÉRTICE]\n");
    if(n < max){
        printf("O novo Vértice %d foi inserido com sucesso.\n", n);
        for (int i = 0; i < n; i++) {
            matrizAdj[i][n] = 0;
            matrizAdj[n][i] = 0;
        }
    }
    else{
        printf("O número máximo de Vértices foi atingido, não é possível inserir mais vértices.\n");
    }
}
 
void deletarVertice(int vertice) {
    printf("\n[REMOÇÃO DE UM VÉRTICE]\n");
    if (vertice == 0) {
        printf("A Matriz está vazia, não é possível deletar um Vértice.\n");
        return;
    }
    if (vertice > n || vertice <= 0) {
        printf("O Vértice inserido não está presente na Matriz.\n");
        return;
    }
    for (int i = vertice; i <= n - 1; i++){
        for (int j = 1; j <= n; j++) {
            matrizAdj[j][i] = matrizAdj[j][i + 1];
            matrizAdj[i][j] = matrizAdj[i + 1][j];
        }
    }
    n--;
    printf("Remoção do Vértice %d feita com sucesso.\n", vertice);
}

int main() {
    int opcao, continuar = 1;
    int vertice;

    printf("===[CÓDIGO - GRAFOS: MATRIZ DE ADJACÊNCIA]===\n");
    printf("Este é um código capaz de criar uma Matriz de Adjacência, juntamente a outras funcionalidades com ela.\n");

    criarMatriz();
    while (continuar == 1) {
        printf("\n==============[OPÇÕES]==============\n");
        printf("| 1.  Inserir um novo Vértice;       |\n");
        printf("| 2.  Inserir Arestas;               |\n");
        printf("| 3.  Deletar um Vértice;            |\n");
        printf("| 4.  Apresentar Matriz;             |\n");
        printf("| 5.  Encerrar                       |\n");
        printf("====================================\n");
        printf("\nEscolha uma das opções acima: ");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            inserirVertice();
            break;
        case 2:
            inserirArestas();
            break;
        case 3:
            printf("Determine o Vértice a ser deletado: ");
            fflush(stdin);  // Limpar o conteúdo da entrada dos últimos dados que foram inseridos;
            scanf("%d", &vertice);
            deletarVertice(vertice);
            break;
        case 4:
            apresentar();
            break;
        case 5:
            continuar = 0;
            break;
        default:
            printf("[OPÇÃO INVÁLIDA]\nCertifique-se de inserir uma opção válida (1, 2, 3 ou 4). Tente Novamente.\n");
            break;
        }
    }
    return 0;
}
