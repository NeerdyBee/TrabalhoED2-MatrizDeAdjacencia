#include<stdio.h>

// GRUPOS: Luis Gabriel Queiroz Carrijo, Ramiro Vieira de Moura, Tiago Carvalho Rodrigues de Oliveira

#define max 20 // Define o valor máximo de Vértices que podem ser inseridos na Matriz.
#define false 0;
#define true 1;
int matrizAdj[max][max]; // Cria uma matriz de duas dimensões, aonde o valor definido contido nelas é igual a max.
int nVertices; // Define a variável n que será responsável por armazenar o o número de Vértices presentes na matriz.
int nArestas = 0; // Inicia a variavel nArestas que contabilizará a quantidade de arestas
 
void criarMatriz() { // FUNÇÃO RESPONSÁVEL PELA CRIAÇÃO DA MATRIZ DE ADJACÊNCIA
    do{ // Um laço de repetição é iniciado para que seja registrado um valor válido para o número de Vértices iniciais da Matriz.
        printf("Insira o número de Vértices da Matriz: ");
        scanf("%d", &nVertices);
        if (nVertices < 0 || nVertices > max){
            printf("\n[ENTRADA INVÁLIDA]\nO número de Vértices não pode ser menor que zero ou maior que o número máximo de Vértices (%d). Tente Novamente.\n", max);
        }
    }while(nVertices < 0 || nVertices > max); // O valor de n é válido apenas se ele for um valor inteiro entre 0 e o valor de max.
    
    for (int i = 0; i < nVertices; i++) { // for responsável por preencher a matriz até o número de vértices inseridos
        for (int j = 0; j < nVertices; j++){
            matrizAdj[i][j] = 0;
        }
    }
    
    if (matrizEstaVazia() == 0){
        inserirArestas();
    }
}

int matrizEstaVazia(){ // FUNÇÃO QUE CONFERE SE A MATRIZ ESTÁ SEM VÉRTICES
    if (nVertices == 0){
        return true; // 1
    }
    else{
        return false; // 0
    }
}

void inserirArestas(){ // FUNÇÃO RESPONSAVEL PELA INSERÇÃO DAS ARESTAS NA MATRIZ
    int vertice1, vertice2, continuar = 1; // Criam as variáveis locais para  inserção de dois vértice os quais serão ligados
    // Para este exemplo de grafo com matriz de adjcência os vérticies são conectados por arestas não direcionadas, assim um vértice tem acesso com o vértice ele se concetar e vice versa
    printf("\n[INSERÇÃO DE ARESTAS]\n");
    if (matrizEstaVazia() == 0){ // Caso a matriz não esteja vazia; 0 = "Falso"
        do{ // Laço de repetição para realizar a inserção de arestas.
            printf("\n%dº Aresta\nInsira os Vértices que se deseja conectar:\n", nArestas+1); // Para encerrar o laço basta que ambos os vértices tenham o valor igual a 0
            printf("1º Vértice: ");
            scanf("%d", &vertice1);
            printf("2º Vértice: ");
            scanf("%d", &vertice2);
            
            if (vertice1 >= nVertices || vertice2 >= nVertices || vertice1 < 0 || vertice2 < 0) { // Situação aonde o valor dos vértices inseridos não válidos
                printf("\n[ENTRADA INVÁLIDA]\nOs valores dos Vértices não podem ser menores ou igual a zero ou maiores que o número de Vértices (Lembre-se que os Vértices se iniciam em 0). Tente Novamente.\n");
            }
            else{
                if (vertice1 == vertice2 && matrizAdj[vertice1][vertice2] > 0){
                    matrizAdj[vertice1][vertice2] += 1;
                }else{
                    matrizAdj[vertice1][vertice2] += 1; // Esta posição matriz recebe mais 1 ao seu valor representando a quantidade de ligações entre os
                    matrizAdj[vertice2][vertice1] += 1; // O incremento ocorre em ambas as posições para garantir a simetria na matriz, assim representando que um vértice possui acesso a outro
                }
                printf("\n[INSERÇÃO REALIZADA]\n");
                nArestas++;
            }
    
            do{
                printf("\nDeseja continuar a Inserção de Arestas?\n");
                printf("1.   Sim\n2.   Não\n");
                printf("\nEscolha uma das opções acima: ");
                scanf("%d", &continuar);
                if (continuar != 1 && continuar != 2){
                    printf("\n[OPÇÃO INVÁLIDA]\nCertifique-se de inserir uma opção válida (1 ou 2). Tente Novamente.\n");
                }
            }while (continuar != 1 && continuar != 2);
        }while (continuar == 1);
    }else{
        printf("\n[INSERÇÃO NÃO PÔDE SER REALIZADA]\nA Matriz não possui vértices.\n");
    }
}
 
void apresentar() { // FUNÇÃO RESPONSÁVEL POR IMPRIMIR A MATRIZ
    printf("\n[APRESENTAÇÃO DA MATRIZ]\n");
    printf("   ");
    for (int h = 0; h < nVertices; h++){
        printf("  %4d ", h);
    }
    printf("\n");
    for (int i = 0; i < nVertices; i++) { // i percorre os indexes pela matriz representando suas linhas
        printf("%2d ", i);
        for (int j = 0; j < nVertices; j++) // j percorre os indexes pela matriz representando suas colunas
            printf("| %4d ", matrizAdj[i][j]); // i e j percorrem pelos indexes da Matriz até chegarem ao último index e imprimindo as linhas de ligações entres os vértices
        printf("|\n");
    }
    printf("\nINFORMAÇÕES DO GRAFO:\n>Número de Vértices: %4d | Número de Arestas: %4d\n", nVertices, nArestas);
}
 
void inserirVertice() { // FUNÇÃO RESPONSÁVEL POR CRIAR UM NOVO VÉRTICE NO FINAL DA MATRIZ
    printf("\n[INSERÇÃO DE UM NOVO VÉRTICE]\n");
    if(nVertices < max){  // Condição para que seja possível inserir um novo vértice, aonde nVertices ainda seja menor que o valor máximo da matriz
        nVertices++;
        for (int i = 0; i < nVertices; i++) { // i percorrerá as linhas e colunas do novo vértice e definirá seus valores contidos como 0
            matrizAdj[i][nVertices-1] = 0;
            matrizAdj[nVertices-1][i] = 0;
        }
        printf("\nO novo Vértice V%d foi inserido ao final da matriz com sucesso.\n", nVertices-1);
    }
    else{
        printf("\nO número máximo de Vértices foi atingido, não é possível inserir mais vértices.\n");
    }
}
 
void deletarVertice(int vertice) { // FUNÇÃO RESPONSÁVEL POR DELETAR UM VÉRTICE DA MATRIZ
    printf("\n[REMOÇÃO DE UM VÉRTICE]\n");
    if (matrizEstaVazia() != 0) { // Situação aonde não elementos para serem removidos da matriz
        printf("A Matriz está vazia, não é possível deletar um Vértice.\n");
        return;
    }
    else if (vertice >= nVertices || vertice < 0) { // Situação aonde o vértice é inválido
        printf("O Vértice inserido não é válido ou não está presente na Matriz (Lembre-se que os Vértices se iniciam em 0).\n");
        return;
    }
    else{
        for (int i = vertice; i < nVertices; i++){  // Este laço fará com que i e j percorram os elementos da matriz a partir do vértice dado e farão com que eles recebam o valor de seus sucessores
            for (int j = 0; j < nVertices; j++) {
                matrizAdj[j][i] = matrizAdj[j][i + 1];
                matrizAdj[i][j] = matrizAdj[i + 1][j];
            }
         }
    }
    nVertices--; // Por fim, assim que seus novos valores são colocados n é reduzido para excluir o último valor do alcance da matriz
    printf("Remoção do Vértice %d feita com sucesso.\nSeus sucessores foram reposicionados e o número de Vértices agora é %d.", vertice, nVertices);
}

int main() {
    int opcao, continuar = 1;
    int vertice;

    printf("===[CÓDIGO - GRAFOS: MATRIZ DE ADJACÊNCIA]===\n");
    printf("Este é um código capaz de criar uma Matriz de Adjacência, juntamente a outras funcionalidades com ela.\n");
    printf("Sua estrutura e funcionamento foi baseado no exemplo apresentado em aula, seguindo as seguintes diretrizes:\n");
    printf(">As Arestas do Grafo serão não direcionados, logo a Matriz se apresentará simétrica;\n");
    printf(">Os Vértices do Grafo sempre se iniciaram em 0 ou V0;\n\n");

    criarMatriz(); 
    while (continuar == 1) {
        printf("\n==============[OPÇÕES]==============\n");
        printf("| 1.  Inserir um novo Vértice;      |\n");
        printf("| 2.  Inserir Arestas;               |\n");
        printf("| 3.  Deletar um Vértice;           |\n");
        printf("| 4.  Apresentar Matriz;             |\n");
        printf("| 5.  Encerrar                       |\n");
        printf("======================================\n");
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
            printf("\n[OPÇÃO INVÁLIDA]\nCertifique-se de inserir uma opção válida (1, 2, 3, 4 ou 5). Tente Novamente.\n");
            break;
        }
    }
    return 0;
}