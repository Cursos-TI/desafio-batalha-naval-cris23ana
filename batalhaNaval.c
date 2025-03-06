#include <stdio.h>

int main() {

    char letras[11] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int linha, coluna, tabuleiro[10][10];

    //calculo dos navios
    for(linha = 0; linha < 10; linha++)
    {
        for(coluna = 0; coluna < 10; coluna++)
        {
            tabuleiro[linha][coluna] = 0;

            //navios
                if(linha == 5 && coluna == 4 || linha == 5 && coluna == 5 || linha == 5 && coluna == 6)
                {
                    tabuleiro[linha][coluna] = 3; //navio na horizontal
                }
                if(linha == 2 && coluna == 2 || linha == 3 && coluna == 2 || linha == 4 && coluna == 2)
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
