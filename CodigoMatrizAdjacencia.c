#include<stdio.h>

// GRUPOS: Luis Gabriel Queiroz Carrijo, Ramiro Vieira de Moura, Tiago Carvalho Rodrigues de Oliveira


// DEFINIÇÕES INICIAIS:
#define max 20 // Define o valor máximo de Vértices que podem ser inseridos na Matriz.
#define false 0 // Define valores inteiros para quando se utiliza true ou false no código
#define true 1 // (false = 0, true = 1)

int matrizAdj[max][max]; // Cria um Array matrizAdj de duas Dimensões com uma quantidade de elementos igual a max
int nVertices; // Define a variável nVertices que armazenará o número de vértices atual na matriz
int nArestas = 0; // Define a variavel nArestas que contabilizará a quantidade de arestas na matriz


// FUNÇÃO criaMatriz()
void criarMatriz() { // RESPONSÁVEL PELA CRIAÇÃO DA MATRIZ DE ADJACÊNCIA
    do{ // Laço de repetição "do-while" que garantirá que o número de vértices iniciais inseridos não seja negativo nem maior que max
        printf("Insira o número de Vértices da Matriz: ");
        scanf("%d", &nVertices);
        if (nVertices < 0 || nVertices > max){ // Condiçãp para mensagem de [ERRO] aparecer
            printf("\n[ENTRADA INVÁLIDA]\nO número de Vértices não pode ser menor que zero ou maior que o número máximo de Vértices (%d). Tente Novamente.\n", max);
        }
    }while(nVertices < 0 || nVertices > max); // Condição para que o laço se repita enquanto o valor estiver inválido
    
    for (int i = 0; i < nVertices; i++) { // Laço "for" que preenchera os espaços do Array até o número de vértices inseridos com valor 0
        for (int j = 0; j < nVertices; j++){ // i percorre as Linhas do Array, j percorre suas Colunas
            matrizAdj[i][j] = 0;
        }
    }
    
    printf("\nMatriz criada com sucesso.");

    if (matrizEstaVazia() == false){ // Ao fim da função será automaticamente iniciada a inserção de Arestas caso a matriz não esteja vazia
        printf("\nIniciando a inserção de Arestas.\n");
        inserirArestas(); // Chamada da Função inserirArestas()
    }
}

// FUNÇÃO matrizEstaVazia()
int matrizEstaVazia(){ // CONFERE SE A MATRIZ ESTÁ VAZIA
    if (nVertices == 0){ // Se a quantidade de Vértices for igual a 0, a Matriz está vazia
        return true; // Retorna 1
    }
    else{
        return false; // Retorna 0
    }
}


// FUNÇÃO inserirArestas()
void inserirArestas(){ // RESPONSÁVEL PELA INSERÇÃO DE ARESTAS NA MATRIZ
    // DEFINIÇÃO DE VARIÁVEIS LOCAIS
    int vertice1, vertice2; // Define as variáveis que armazenarão os Vértices inseridos
    int continuar = 1; // Define a variável continuar que manterá o Laço de inserção enquanto o usuário desejar continuar
    
    printf("\n[INSERÇÃO DE ARESTAS]\n");
    if (matrizEstaVazia() == true){ // Confere ao iniciar da Função se a Matriz está vazia o que impede sua execução
        printf("\n[INSERÇÃO NÃO PÔDE SER REALIZADA]\nA Matriz não possui vértices.\n");
    }
    else{ // Caso a Matriz não esteja vazia a função inicia a inserção de Arestas
        do{ // Laço de repetição "do-while" que realiza a inserção das Arestas
            printf("\n%dº Aresta\nInsira os Vértices que se deseja conectar:\n", nArestas+1);
            printf("1º Vértice: ");
            scanf("%d", &vertice1);
            printf("2º Vértice: ");
            scanf("%d", &vertice2); // Inserção dos dois vértices que se ligarão feita pelo usuário
            
            if (vertice1 >= nVertices || vertice2 >= nVertices || vertice1 < 0 || vertice2 < 0) { 
                // Condição que apresenta uma mensagem de [ERRO] caso o valor de algum dos Vértices seja negativo, ou maior ou igual ao número de Vértices dentro da Matriz
                printf("\n[ENTRADA INVÁLIDA]\nOs valores dos Vértices não podem ser menores ou igual a zero ou maiores que o número de Vértices (Lembre-se que os Vértices se iniciam em 0). Tente Novamente.\n");
            }
            else{ // Execução caso os Vértices dados são válidos
                if (vertice1 == vertice2 && matrizAdj[vertice1][vertice2] > 0){
                    // Condição que confere se os Vértices dados são iguais e já foram ligados
                    // Neste caso o acréscimo em sua posição é de 1
                    matrizAdj[vertice1][vertice2] += 1;
                }else{ 
                    // Execução comum aonde os Vértices são diferentes
                    matrizAdj[vertice1][vertice2] += 1;
                    matrizAdj[vertice2][vertice1] += 1; 
                    // O incremento ocorre em ambas as posições por conta de suas Arestas serem Não-Direcionadas (Ambos tem acesso ao outro)
                }
                printf("\n[INSERÇÃO REALIZADA]\n");
                nArestas++; // Assim que a Inserção for realizada, aumentasse o número de Arestas
            }
    
            do{ // Laço "do-while" no qual o usuário insere sua escolha de continuar ou encerrar a inserção de Arestas
                printf("\nDeseja continuar a Inserção de Arestas?\n");
                printf("1.   Sim\n2.   Não\n");
                printf("\nEscolha uma das opções acima: ");
                scanf("%d", &continuar);
                if (continuar != 1 && continuar != 2){ // Condição que apresenta uma mensagem de [ERRO] caso a escolha seja inválida 
                    printf("\n[OPÇÃO INVÁLIDA]\nCertifique-se de inserir uma opção válida (1 ou 2). Tente Novamente.\n");
                }
            }while (continuar != 1 && continuar != 2); // Condição que repete o Laço caso o usuário registre uma escolha inválida
        }while (continuar == 1); // Condição que repete o Laço de inserção de Arestas enqaunto a escolha dada seja a opção 1 ("Sim")
    }
}

// FUNÇÃO apresentar()
void apresentar() { // RESPONSÁVEL POR APRESENTAR A MATRIZ PARA O USUÁRIO
    // A apresentação da Matriz se fará como uma Tabela aonde seus Vértices serã postos como Linhas e Colunas e seus conteúdos serão apresentados
    printf("\n[APRESENTAÇÃO DA MATRIZ]\n");
    printf("   "); // Espaçamento inicial para alinhar a apresentação da Matriz
    for (int h = 0; h < nVertices; h++){ // Laço "for" que imprimirá uma primeira linha de Vértices representado as Colunas na Tabela
        printf("  %4d ", h);
    }
    printf("\n"); // Salto de linha após o fim do Laço

    for (int i = 0; i < nVertices; i++) { // Conjunto de Laços que percorrerão a Matriz e imprimirão o conteúdo de suas Linhas
        // A variável i percorrerá as Linhas da Matriz
        printf("%2d ", i); // Ao início da linha é impresso o Vértice que i está representado a Linha na Tabela
        
        for (int j = 0; j < nVertices; j++) {
            // A variável j percorrerá as Colunas da Matriz
            printf("| %4d ", matrizAdj[i][j]); // É impresso os conteúdos com base na Linha e Coluna na Matriz
        }
        printf("|\n"); // Salto de linha após o fim do Laço

    }// Após j percorrer todas as Colunas de uma Linha seu Laço é encerrado e o Laço anterior repete a execução na Linha seguinte
    
    printf("\nINFORMAÇÕES DO GRAFO:\n>Número de Vértices: %4d | Número de Arestas: %4d\n", nVertices, nArestas); // Além da apresentação da Tabela também são impressas outras informações da Matriz
}
 
// FUNÇÃO inseriVertice()
void inserirVertice() { // RESPONSÁVEL POR CRIAR UM NOVO VÉRTICE AO FINAL DA MATRIZ
    printf("\n[INSERÇÃO DE UM NOVO VÉRTICE]\n");
    
    if(nVertices >= max){  // Caso a Matriz tenha atingido seu número máximo de Vértices não é possivel realizar a inserção
        printf("\nO número máximo de Vértices foi atingido, não é possível inserir mais vértices.\n");
    }
    else{ // Caso o número máximo de Vértices não foi atingido é possivel realizar a inserção de um novo Vértice
        nVertices++; // O número de Vértices é acrescentado representado a inserção de um novo Vértice
        int novoVertice = nVertices - 1; // Recebe o valor da posição do novo Vértice na Matriz (por começar em 0, reduz-se 1)

        for (int i = 0; i < nVertices; i++) { // Laço "for" aonde as posições do novo Vértice serão preenchidas por 0
            // A variável i percorrerá a Matriz auxiliando a preencher as Linhas e Colunas do novo Vértice
            matrizAdj[i][novoVertice] = 0;
            matrizAdj[novoVertice][i] = 0;
        }
        printf("\nO novo Vértice V%d foi inserido ao final da matriz com sucesso.\n", nVertices-1);
    }
}
 
// FUNÇÃO deletarVertice
void deletarVertice(int vertice) { // RESPONSÁVEL POR DELETAR UM VÉRTICE A ESCOLHA DA MATRIZ
    // O Parâmetro dado na Função representará a posição do Vértice que se deseja deletar na Matriz
    printf("\n[REMOÇÃO DE UM VÉRTICE]\n");
    if (matrizEstaVazia() == true) { // Condição que confere se a Matriz está vazia, assim não sendo possível realizar a deleção
        printf("\nA Matriz está vazia, não é possível deletar um Vértice.\n");
        return;
    }
    else if (vertice >= nVertices || vertice < 0) { // Condição que confere se o Vértice inserido é negativo, ou maior ou igual ao número de Vértices atual na Matriz
        printf("\n[VÉRTICE INVÁLIDO]\nO Vértice inserido não é válido ou não está presente na Matriz (Lembre-se que os Vértices se iniciam em 0).\n");
        return;
    }
    else{ // Caso o Vértice do parâmetro esteja válido a deleção é executada
        for (int h = 0; h < nVertices; h++){ // Laço "For" que realiza a deleção das Arestas no Vértice dado
            // h percorre as colunas na Matriz pela posição do valor vertice
            nArestas -= matrizAdj[vertice][h]; // nArestas reduz ao valor que está nas posições, pois representam o número de Arestas entre os Vértices
            // Por conta da Matriz se apresentar simétrica basta que apenas a Linha na posição Vértice seja percorrida
            if (h == vertice && matrizAdj[vertice][h] > 0){ // Condição que confere se um Vértice conectou em si mesmo
                nArestas++; // Devido a primeira vez que um Vértice se liga com ele mesmo seu conteúdo se torna 2, mas ainda tendo 1 Aresta, é necessário adicionar 1 a nArestas para fazer a redução de 1
            }
        }

        for(int j = vertice; j < nVertices; j++) { // Laço "for" que realiza a deleção do Vértice atráves do reposicionamento de seus sucessores
            for (int i = 0; i < nVertices; ++i) { // Laço "for" que faz o conteúdo das Linhas a partir do Vértice dado se tornem o de seus sucessores
                matrizAdj[i][j] = matrizAdj[i][j + 1];
            }
            for (int i = 0; i < nVertices; ++i) { // Laço "for" que faz o conteúdo das Conlunas a partir do Vértice dado se tornem o de seus sucessores
                matrizAdj[j][i] = matrizAdj[j + 1][i];
            }
        }
    }
    printf("Remoção do Vértice %d feita com sucesso.\nSeus sucessores foram reposicionados e o número de Vértices agora é %d.", vertice, nVertices);
    nVertices--; // Ao final, o número de Vértices é reduzido após feita a deleção
}

int main() {
    int opcao, continuar = 1;
    int vertice;

    printf("===[CÓDIGO - GRAFOS: MATRIZ DE ADJACÊNCIA]===\n");
    printf("Este é um código capaz de criar uma Matriz de Adjacência, juntamente a outras funcionalidades com ela.\n");
    printf("Sua estrutura e funcionamento foi baseado no exemplo apresentado em aula, seguindo as seguintes diretrizes:\n");
    printf(">As Arestas do Grafo serão não direcionados, logo a Matriz se apresentará simétrica;\n");
    printf(">Os Vértices do Grafo sempre se iniciaram em 0 ou V0;\n");
    printf(">Um novo Vértice sempre será inserido ao final da Matriz;\n");

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