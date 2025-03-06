#include <stdio.h>

int main() {

    char letras[11] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int linha, coluna, tabuleiro[10][10];
    int linhaCone, colunaCone, cone[3][5];
    int linhaCruz, colunaCruz, cruz[3][5];
    int linhaOctaedro, colunaOctaedro, octaedro[3][5];

    //calculo dos navios
    for(linha = 0; linha < 10; linha++)
    {
        for(coluna = 0; coluna < 10; coluna++)
        {
            tabuleiro[linha][coluna] = 0;

            //navios
            if(linha == 3 && coluna == 4 || linha == 3 && coluna == 5 || linha == 3 && coluna == 6)
            {
                tabuleiro[linha][coluna] = 3; //navio na horizontal
            }
            if(linha == 3 && coluna == 0 || linha == 4 && coluna == 0 || linha == 5 && coluna == 0)
            {
                tabuleiro[linha][coluna] = 3; //navio na vertical
            }
            if(linha == 0 && coluna == 9 || linha == 1 && coluna == 8 || linha == 2 && coluna == 7)
            {
                tabuleiro[linha][coluna] = 3; //navio na diagonal 1
            }

            if(linha == 6 && coluna == 1 || linha == 7 && coluna == 2 || linha == 8 && coluna == 3)
            {
                tabuleiro[linha][coluna] = 3; //navio na diagonal 2
            }
        }
    }

    //matriz para a habilidade cone
    for(linhaCone = 0; linhaCone < 3; linhaCone++)
    {
        for(colunaCone = 0; colunaCone < 5; colunaCone++)
        {
            cone[linhaCone][colunaCone] = 0;

            // formação da matriz para o cone
            if(linhaCone == 0 && colunaCone == 2)
            {
                cone[linhaCone][colunaCone] = 1; // condicional para posição {0,2}, atribui 1 na posição
            }
            if(linhaCone == 1 && colunaCone == 1 || linhaCone == 1 && colunaCone == 2 || linhaCone == 1 && colunaCone == 3)
            {
                cone[linhaCone][colunaCone] = 1; // condicional para posição {1, 1} {1,2} {1,3}, atribui 1 nas posições
            }
            if(linhaCone == 2)
            {
                cone[linhaCone][colunaCone] = 1; // condicional para todas as colunas na linha 2, atribui 1 nas posições
            }
        }
    }

    //matriz para a habilidade cruz
    for(linhaCruz = 0; linhaCruz < 3; linhaCruz++)
    {
        for(colunaCruz = 0; colunaCruz < 5; colunaCruz++)
        {
            cruz[linhaCruz][colunaCruz] = 0;

            // formação da matriz para a cruz
            if(linhaCruz == 0 && colunaCruz == 2)
            {
                cruz[linhaCruz][colunaCruz] = 1; // condicional para a posição {0,2}, atribui 1 na posição
            }
            if(linhaCruz == 1)
            {
                cruz[linhaCruz][colunaCruz] = 1; // condicional para todas as colunas na linha 1, atribui 1 nas posições
            }
            if(linhaCruz == 2 && colunaCruz == 2)
            {
                cruz[linhaCruz][colunaCruz] = 1; // condicional para a posição (2,2), atribui 1 na posição
            }
        }
    }

    // matriz para a habilidade octaedro
    for(linhaOctaedro = 0; linhaOctaedro < 3; linhaOctaedro++)
    {
        for(colunaOctaedro = 0; colunaOctaedro < 5; colunaOctaedro++)
        {
            octaedro[linhaOctaedro][colunaOctaedro] = 0;
            
            // formação da matriz do octaedro
            if(linhaOctaedro == 0 && colunaOctaedro == 2)
            {
                octaedro[linhaOctaedro][colunaOctaedro] = 1; // condicional para a posição {0,2}, atribui 1 na posição
            }
            if(linhaOctaedro == 1 && colunaOctaedro == 1 || linhaOctaedro == 1 && colunaOctaedro == 2 || linhaOctaedro == 1 && colunaOctaedro == 3)
            {
                octaedro[linhaOctaedro][colunaOctaedro] = 1; // condicional para as colunas 1,2 e 3 na linha 1, atribui 1 nas posições
            }
            if(linhaOctaedro == 2 && colunaOctaedro == 2)
            {
                octaedro[linhaOctaedro][colunaOctaedro] = 1; // condicional para a posição {2,2}, atribui 1 na posição
            }
        }
    }

    //substituindo a matriz habilidade na matriz original
    for(int i = 0; i < linhaCone; i++)
    {
        for(int j = 0; j < colunaCone; j++)
        {
            int pontoOrigemLinha = 0; // ponto de origem da linha
            int pontoOrigemColuna = 0; // ponto de origem da coluna
            tabuleiro[pontoOrigemLinha + i][pontoOrigemColuna + j] = cone[i][j]; // ponto de origem + i para o cone crescente
        }
    }

    for(int i = 0; i < linhaCruz; i++)
    {
        for(int j = 0; j < colunaCruz; j++)
        {
            int pontoOrigemLinha = 5;
            int pontoOrigemColuna = 5;
            tabuleiro[pontoOrigemLinha + (i - 1)][pontoOrigemColuna + (j - 2)] = cruz[i][j]; // (i - 1) e (j - 2) movem para o centro
        }
    }

    for(int i = 0; i < linhaOctaedro; i++)
    {
        for(int j = 0; j < colunaOctaedro; j++)
        {
            int pontoOrigemLinha = 8;
            int pontoOrigemColuna = 7;
            tabuleiro[pontoOrigemLinha + (i - 1)][pontoOrigemColuna + (j - 2)] = octaedro[i][j]; // (i - 1) e (j - 2) movem para o centro
        }
    }


    //imprimindo o tabuleiro
    for(int i = 0; i <= 10; i++)
    {
        printf(" %c", letras[i]); //imprime as letras representando as colunas
    }
    printf("\n");

    for(linha = 0; linha < 10; linha++)
    {
        if(numeros[linha] < 10)
        {
            printf(" ");
        }
        printf("%d ", numeros[linha]);

        for(coluna = 0; coluna < 10; coluna++)
        {
            printf("%d ", tabuleiro[linha][coluna]); // impressao da matriz 10x10
        }
        printf("\n");
    }

    return 0;
}
