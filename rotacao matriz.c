#include <stdio.h>

int main()
{
    //variáveis de entrada
    int N = 135;
    int R = 30;

    int contador = 1;
    int voltas = N / 2;

    int aux = 0;
    int aux1 = 0;

    int inicioLinha = 0;
    int fimLinha = N - 1;
    int inicioColuna = 0;
    int fimColuna = N - 1;

    int matriz[N][N];

    //preenche a matriz
    for(int i = 0;i < N; i++)
        for(int j = 0; j < N; j++)
        {
            matriz[i][j] = contador;
            contador++;
        }

    //print da matriz antes das rotações
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("\n");

    while(R > 0)
    {

        for(int k = 0; k < voltas; k++)
        {

            //cima da matriz
            aux = matriz[inicioLinha][fimColuna];

            for(int i = fimColuna;i >=  inicioColuna; i--)
                matriz[inicioLinha][i] = matriz[inicioLinha][i-1];

            if(k == 0)
                matriz[0][0] = matriz[N/2][N/2];
            else
                matriz[inicioLinha][inicioColuna] = aux1;


            //direita da matriz

            aux1 = matriz[fimLinha][fimColuna];

            for(int i = fimLinha; i > inicioLinha; i--)
                matriz[i][fimColuna] = matriz[i - 1][fimColuna];

            matriz[inicioLinha + 1][fimColuna] = aux;


            //baixo da matriz
            aux = matriz[fimLinha][inicioColuna];

            for(int i = inicioColuna;i < fimColuna ; i++)
                matriz[fimLinha][i] = matriz[fimLinha][i + 1];

            matriz[fimLinha][fimColuna - 1] = aux1;


            //esquerda da matriz
            aux1 = matriz[inicioLinha+1][inicioColuna];
            matriz[N/2][N/2] = matriz[fimLinha - 1][inicioColuna];

            for(int i = inicioLinha + 1; i < fimLinha; i++)
                matriz[i][inicioColuna] = matriz[i+1][inicioColuna];

            matriz[fimLinha - 1][inicioColuna] = aux;


            inicioLinha++;
            inicioColuna++;
            fimLinha--;
            fimColuna--;

        }
        inicioLinha = 0;
        inicioColuna = 0;
        fimLinha = N - 1;
        fimColuna = N - 1;
        R--;

    }
    //print da matriz depois das rotações
    for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                    printf("%d ", matriz[i][j]);
                printf("\n");
            }

    return 0;
}


