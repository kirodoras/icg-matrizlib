// compilar: gcc testes.c matriz.c -o testes
// executar: ./testes
#include <stdio.h>
#include "matriz.h"

void imprimirMatriz3x3(Matriz3x3 mat)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("%.3f ", mat.elemento[i][j]);
        }
        printf("\n");
    }
}

void imprimirMatriz3x1(Matriz3x1 mat)
{
    for (int i = 0; i < 3; ++i)
    {
        printf("%.3f\n", mat.elemento[i][0]);
    }
}

int main()
{
    Matriz2x2 matriz2x2_A = {
        {{3, 1},
         {1, 2}}};

    Matriz3x3 matriz3x3_A = {
        {{7, 1, 2},
         {0, 5, 1},
         {3, 1, 6}}};

    Matriz3x3 matriz3x3_B = {
        {{9, 8, 7},
         {6, 5, 4},
         {3, 2, 1}}};

    Matriz3x1 matriz3x1_A = {
        {{3},
         {2},
         {1}}};

    float det2x2A = det2x2(matriz2x2_A);
    printf("\nDeterminante da matriz 2x2: %.2f\n", det2x2A);

    float det3x3A = det3x3(matriz3x3_A);
    printf("\nDeterminante da matriz 3x3: %.2f\n", det3x3A);

    // Testar a função de transposição
    Matriz3x3 transpostaMatriz3x3 = transpor3x3(matriz3x3_A);
    printf("\nMatriz transposta da matriz 3x3 original:\n");
    imprimirMatriz3x3(transpostaMatriz3x3);

    // Testar a função de adjunta
    Matriz3x3 adjuntaMatriz3x3 = adjunta3x3(matriz3x3_A);
    printf("\nMatriz adjunta da matriz 3x3 original:\n");
    imprimirMatriz3x3(adjuntaMatriz3x3);

    // Testar a função de inversa
    Matriz3x3 inversaMatriz3x3 = inversa3x3(matriz3x3_A);
    printf("\nMatriz inversa da matriz 3x3 original:\n");
    imprimirMatriz3x3(inversaMatriz3x3);

    // Testar a multiplicação de matriz 3x3 por escalar
    Matriz3x3 resultadoMatriz3x3PorEscalar = multiplicar3x3PorEscalar(matriz3x3_A, -2);
    printf("\nResultado da multiplicação da matriz 3x3 por escalar:\n");
    imprimirMatriz3x3(resultadoMatriz3x3PorEscalar);

    // Testar a multiplicação de matrizes 3x3
    Matriz3x3 resultadoMatriz3x3 = multiplicar3x3Por3x3(matriz3x3_A, matriz3x3_B);
    printf("\nResultado da multiplicação das matrizes 3x3:\n");
    imprimirMatriz3x3(resultadoMatriz3x3);

    // Testar a multiplicação de matriz 3x3 com matriz 3x1
    Matriz3x1 resultadoMatriz3x1 = multiplicar3x3Por3x1(matriz3x3_A, matriz3x1_A);
    printf("\nResultado da multiplicação da matriz 3x3 com a matriz 3x1:\n");
    imprimirMatriz3x1(resultadoMatriz3x1);

    // Testar a multiplicação de matriz 3x1 por escalar
    Matriz3x1 resultadoMatriz3x1PorEscalar = multiplicar3x1PorEscalar(matriz3x1_A, -3);
    printf("\nResultado da multiplicação da matriz 3x1 por escalar:\n");
    imprimirMatriz3x1(resultadoMatriz3x1PorEscalar);

    // Testar a soma de matrizes 3x1
    Matriz3x1 resultadoSomaMatriz3x1 = somar3x1(matriz3x1_A, matriz3x1_A);
    printf("\nResultado da soma das matrizes 3x1:\n");
    imprimirMatriz3x1(resultadoSomaMatriz3x1);

    // Testar a subtração de matrizes 3x1
    Matriz3x1 resultadoSubtracaoMatriz3x1 = subtrair3x1(matriz3x1_A, matriz3x1_A);
    printf("\nResultado da subtração das matrizes 3x1:\n");
    imprimirMatriz3x1(resultadoSubtracaoMatriz3x1);

    return 0;
}