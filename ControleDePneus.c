/*
Desenvolvido por: Samuel Da Luz Viana Martins
Disciplina: Algoritmos II
Professor: Alessandro
Instituição: Uniavan
(Trabalho de desenvolvimento de sistema de controle de pneus para caminhôes).
Data da última modificação: 09/06/2026
*/

#include <stdio.h>

int main()
{
    //Definindo as váriaveis e vetores
    int qtdFrente = 0, qtdTras = 0, qtdSteps = 0;
    int frotaPneus[3][10];
    int opcao, i, tipoEixo;
    int pneuOrigem, pneuDestino;
    int posOrigem, posDestino, ondeOrigem, ondeDestino, achouOrigem, achouDestino;

    do
    {
        //Menu para o usuário interagir
        printf("\nMENU -----\n");
        printf("1 - Escolher Tipo de Eixo e Preencher Pneus\n");
        printf("2 - Mostrar pneus/steps\n");
        printf("3 - Realizar Rodizio (pneus e steps)\n");
        printf("4 - Mostrar desenho\n");
        printf("5 - Tela de Legenda dos Eixos\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        //Ações a partir das escolhas do usuário
        switch (opcao)
        {
        case 1:
            //Usuário decide qual tipode eixo ela vai utilizar
            printf("\nSelecione o tipo de EIXO:\n");
            printf("1 - Toco (2 eixos)\n");
            printf("2 - Truck (3 eixos)\n");
            printf("3 - Carreta 3 eixos (5 eixos)\n");
            printf("Opcao: ");
            scanf("%d", &tipoEixo);

            //Atribui os valores às variáveis após definir o tipo de eixo
            if (tipoEixo == 1)
            {
                qtdFrente = 2;
                qtdTras = 2;
            }
            else if (tipoEixo == 2)
            {
                qtdFrente = 2;
                qtdTras = 4;
            }
            else if (tipoEixo == 3)
            {
                qtdFrente = 2;
                qtdTras = 6;
            }
            else
            {
                printf("\nOpcao de eixo invalida\n");
                break;
            }

            //Usuário preenche com números no tipo de eixo escolhido
            printf("\nDigite os numeros dos pneus da frente (%d pneus):\n", qtdFrente);
            for (i = 0; i < qtdFrente; i++)
            {
                scanf("%d", &frotaPneus[0][i]);
            }

            printf("Digite os numeros dos pneus de tras (%d pneus):\n", qtdTras);
            for (i = 0; i < qtdTras; i++)
            {
                scanf("%d", &frotaPneus[1][i]);
            }

            printf("Digite a quantidade de STEPS (max 10): ");
            scanf("%d", &qtdSteps);

            printf("Digite os numeros dos STEPS:\n");
            for (i = 0; i < qtdSteps; i++)
            {
                scanf("%d", &frotaPneus[2][i]);
            }
            printf("\nPneus e steps vinculados\n");
            break;

        case 2:
            //Verifica se o usuário já cadastrou os pneus
            if (qtdFrente == 0 && qtdTras == 0)
            {
                printf("\nNenhum pneu cadastrado ainda\n");
                break;
            }

            //Listagem dos pneus na tela
            printf("\nLISTA DE PNEUS:\n");
            printf("FRENTE -----\n");
            for (i = 0; i < qtdFrente; i++)
            {
                printf("Pneu Frente %02d: #%d\n", i + 1, frotaPneus[0][i]);
            }
            printf("TRAS -----\n");
            for (i = 0; i < qtdTras; i++)
            {
                printf("Pneu Tras %02d: #%d\n", i + 1, frotaPneus[1][i]);
            }
            printf("STEPS -----\n");
            for (i = 0; i < qtdSteps; i++)
            {
                printf("STEP %02d: #%d\n", i + 1, frotaPneus[2][i]);
            }
            printf("Pressione qualquer tecla para continuar. . .\n");
            getchar();
            getchar();
            break;

        case 3:
            if (qtdFrente == 0 && qtdTras == 0)
            {
                //Verifica se os pneus já foram cadastrados
                printf("\nNenhum pneu cadastrado ainda\n");
                break;
            }
            printf("Digite o pneu ou step que quer trocar: ");
            scanf("%d", &pneuOrigem);
            printf("Digite o pneu ou step pelo qual quer substituir: ");
            scanf("%d", &pneuDestino);

            //Flags, se encontrarmos os pneus na busca, valerão 1
            achouOrigem = 0;
            achouDestino = 0;

            //Percorremos a matriz pra verificar se o pneu que vai ser trocado existe
            //linha 0 = pneus da frente - linha 1 = pneus de trás
            for (i = 0; i < qtdFrente; i++)
            {
                if (frotaPneus[0][i] == pneuOrigem)
                {
                    achouOrigem = 1; //Sinaliza que o pneu de origem existe no sistema
                    posOrigem = i; //Salva o índice da coluna onde ele foi encontrado
                    ondeOrigem = 1; //Salva um código para a linha
                }

                if (frotaPneus[0][i] == pneuDestino)
                {
                    achouDestino = 1;
                    posDestino = i;
                    ondeDestino = 1;
                }
            }
            for (i = 0; i < qtdTras; i++)
            {
                if (frotaPneus[1][i] == pneuOrigem)
                {
                    achouOrigem = 1;
                    posOrigem = i;
                    ondeOrigem = 2;
                }
                if (frotaPneus[1][i] == pneuDestino)
                {
                    achouDestino = 1;
                    posDestino = i;
                    ondeDestino = 2;
                }
            }
            //Verifica a linha 2 = pneus de trás
            for (i = 0; i < qtdSteps; i++)
            {
                if (frotaPneus[2][i] == pneuOrigem)
                {
                    achouOrigem = 1;
                    posOrigem = i;
                    ondeOrigem = 3;
                }
                if (frotaPneus[2][i] == pneuDestino)
                {
                    achouDestino = 1;
                    posDestino = i;
                    ondeDestino = 3;
                }
            }

            //testa se ambos os pneus foram encontrados
            if (achouOrigem && achouDestino)
            {
                int aux = pneuOrigem; //aux = auxiliar

                //olha a variável ondeOrigem
                //Se for 1 = linha 0
                //Se for 2 = linha 1
                //Se for 3 = linha 2
                if (ondeOrigem == 1) frotaPneus[0][posOrigem] = pneuDestino;
                else if (ondeOrigem == 2) frotaPneus[1][posOrigem] = pneuDestino;
                else if (ondeOrigem == 3) frotaPneus[2][posOrigem] = pneuDestino;

                //Atualiza onde o pneu de destino estava com o valor pneuOrigem que foi passado para a variável aux
                if (ondeDestino == 1) frotaPneus[0][posDestino] = aux;
                else if (ondeDestino == 2) frotaPneus[1][posDestino] = aux;
                else if (ondeDestino == 3) frotaPneus[2][posDestino] = aux;

                printf("\nRodizio realizado com sucesso!\n");
            }
            //Caso os penus não sejam encontrados
            else
            {
                printf("\nErro: Um ou ambos os pneus nao foram encontrados.\n");
            }
            printf("Pressione qualquer tecla para continuar. . .\n");
            getchar();
            getchar();
            break;

        case 4:
            if (qtdFrente == 0 && qtdTras == 0)
            {
                //Verifica se os pneus foram cadastrados
                printf("\nNenhum pneu cadastrado ainda\n");
                break;
            }
            //Desenho dos pneus nos eixos
            printf("\nDESENHO -----\n");
            printf("   Frente\n");
            for (i = 0; i < qtdFrente; i++)
            {
                printf("[ %d ] ", frotaPneus[0][i]);
            }
            printf("\n   Traseira\n");
            for (i = 0; i < qtdTras; i++)
            {
                printf("[ %d ] ", frotaPneus[1][i]);
            }
            printf("\n\nSTEPS:");
            for (i = 0; i < qtdSteps; i++)
            {
                printf(" #%d", frotaPneus[2][i]);
            }
            printf("\nPressione qualquer tecla para continuar. . .\n");
            getchar();
            getchar();
            break;

        case 5:
            //Informações sobre os tipos de eixos
            printf("\nLEGENDA DOS EIXOS\n");
            printf("1. TOCO: Caminhao semipesado com 2 eixos\n");
            printf("   Leva 2 pneus na frente e 2 pneus atras\n\n");
            printf("2. TRUCK: Caminhao pesado com 3 eixos\n");
            printf("   Leva 2 pneus na frente e 4 pneus nos eixos traseiros\n\n");
            printf("3. CARRETA 3 EIXOS: 5 eixos fisicos\n");
            printf("   2 eixos na frente e 3 no reboque\n");
            printf("\n");
            printf("Pressione qualquer tecla para continuar. . .\n");
            getchar();
            getchar();
            break;

        case 0:
            break;

        default:
            printf("\nOpcao invalida\n");
        }
    }
    while (opcao != 0);

    return 0;
}
