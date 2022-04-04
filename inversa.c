#include <stdio.h>
#include <stdlib.h>

void trocar (float **matriz,int ordem, int linha_1, int linha_2);

void multiplicar_linha (float **matriz, int ordem, int linha, float fator);

void aritmetica_linhas (float **matriz, int ordem, int linha_1, int linha_2, float fator);

void printar_matriz (float **matriz, int ordem);

int main () {
    int r, l1, l2 , l3, l4, l5, opcao;
    float x,y;
    printf ("Escolha a quantidade de linhas e colunas para a matriz: \n");
    scanf("%d", &r);
    float **mtx;
    
    mtx = (int **)malloc(r*sizeof(int));
    for (int i = 0; i < r; i++) {
        mtx = (int *)malloc(r*sizeof(int));
    }

    printf ("Agora de os valores para os elementos da matriz: \n");
    for (int i = 0; i<r; i++) {
        for (int j = 0; j<r; j++) {
            scanf("%f", &mtx[i][j]);
        }
    }
    
    float **inv;
    inv = (int **)malloc(r*sizeof(int));
    for (int i = 0; i < r; i++) {
        inv = (int *)malloc(r*sizeof(int));
    }

    for (int i = 0; i < 0; i++) {
        for (int j = 0; j < 0; j++) {
            if (i == j) {
                inv[i][j] = 1;
            }
            else {
                inv[i][j] = 0;
            }
        }
    }

    printf ("Escolha uma das quatro opcoes: \n");
    printf ("\n1 - Trocar linha");
    printf ("\n2 - Multiplicar linha");
    printf ("\n3 - Aritmetica entre linhas");
    printf ("\n4 - Mostrar a matriz inversa");
    printf ("\n5 - Sair\n");
    scanf ("%d", &opcao);
    if (opcao == 5) {
        printf ("\nObrigado!!!");
        return 0;
    }
    
    else {
        do {
            switch (opcao) {
                case 1: 
                    printf ("\nSeleciona as linhas a serem trocadas: \n");
                    scanf("%d", &l1);
                    scanf ("%d", &l2);
                    trocar (mtx,r, l1-1, l2-1);
                    trocar (inv,r, l1-1, l2-1);
                    printf ("\n");
                    printar_matriz (mtx,r);
                    l1 = 0;
                    l2 = 0;
                break;

                case 2: 
                    printf ("\nEscolha a linha para ser multiplicada: ");
                    scanf ("%d", &l3);
                    printf ("\nEscolha o fator que ira multiplicar: ");
                    scanf ("%f", &x);
                    multiplicar_linha (mtx,r, l3, x);
                    multiplicar_linha (inv,r, l3, x);
                    printf ("\n\n");
                    printar_matriz (mtx,r);
                    x = 0;
                    l3 = 0;
                break;

                case 3:
                    printf ("\nEscolha a linha a ser multiplicada: ");
                    scanf ("%d", &l4);
                    printf ("\nEscolha o fator que ira multiplicar: ");
                    scanf ("%f", &y);
                    printf ("\nEscolha a linha que sera adicionado e substituida: ");
                    scanf ("%d", &l5);
                    aritmetica_linhas (mtx,r, l4, l5, y);
                    aritmetica_linhas (inv,r, l4, l5, y);
                    printf ("\n\n");
                    printar_matriz (mtx,r);
                break;

                case 4: 
                    printf ("\n\n");
                    printar_matriz (inv,r);
                break;
                
            }

            printf ("\n\nEscolha novamente outra opcao");
            scanf ("%d", &opcao);
            if (opcao == 5) {
               printf ("\n\nObrigado!!!");
            }
        }
        while (opcao != 5);
    }
}

void printar_matriz (float **matriz, int ordem) {
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            printf ("%.2f ", matriz[i][j]);
        }
        printf ("\n");
    }
}

void trocar (float **matriz,int ordem, int linha_1, int linha_2) {
    int temp = 0;
    for (int i = 0; i < ordem; i++) {
        temp = matriz[linha_1][i];
        matriz[linha_1][i] = matriz[linha_2][i];
        matriz[linha_2][i] = temp;
    }
}

void multiplicar_linha (float **matriz, int ordem, int linha, float fator) {
    
    for (int i = 0; i < ordem; i++) {
        matriz[linha][i] = fator*matriz[linha][i];
    }

    
}

void aritmetica_linhas (float **matriz, int ordem, int linha_1, int linha_2, float fator) {
    
    for (int i = 0; i < ordem; i++) {
        matriz[linha_2][i] = matriz[linha_2][i] + (fator*matriz[linha_1][i]);
    }
}