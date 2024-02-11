// compilar: gcc testes.c matriz.c -o testes
// executar: ./testes
#include <stdio.h>
#include "matriz.h"

void imprimirMatriz4x4(Matriz4x4 mat)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            printf("%.3f ", mat.elemento[i][j]);
        }
        printf("\n");
    }
}

void imprimirMatriz4x1(Matriz4x1 mat)
{
    for (int i = 0; i < 4; ++i)
    {
        printf("%.3f\n", mat.elemento[i][0]);
    }
}

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

    Matriz4x4 matriz4x4_A = {
        {{1, 2, 0, 0},
         {5, 6, 0, 0},
         {3, 0, 1, 2},
         {1, 1, 1, 1}}};

    Matriz4x4 matriz4x4_B = {
        {{1, 2, 0, 0},
         {2, 2, 6, 6},
         {3, 0, 1, 7},
         {1, 1, 1, 1}}};

    Matriz4x1 matriz4x1_A = {
        {{3},
         {2},
         {1},
         {0}}};

    float det2x2A = det2x2(matriz2x2_A);
    printf("\nDeterminante da matriz 2x2: %.2f\n", det2x2A);

    float det3x3A = det3x3(matriz3x3_A);
    printf("\nDeterminante da matriz 3x3: %.2f\n", det3x3A);

    float det4x4A = det4x4(matriz4x4_A);
    printf("\nDeterminante da matriz 4x4: %.2f\n", det4x4A);

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

    // Testar a função de transposição
    Matriz4x4 transpostaMatriz4x4 = transpor4x4(matriz4x4_A);
    printf("\nMatriz transposta da matriz 4x4 original:\n");
    imprimirMatriz4x4(transpostaMatriz4x4);

    // Testar a função de adjunta
    Matriz4x4 adjuntaMatriz4x4 = adjunta4x4(matriz4x4_A);
    printf("\nMatriz adjunta da matriz 4x4 original:\n");
    imprimirMatriz4x4(adjuntaMatriz4x4);

    // Testar a função de inversa
    Matriz4x4 inversaMatriz4x4 = inversa4x4(matriz4x4_A);
    printf("\nMatriz inversa da matriz 4x4 original:\n");
    imprimirMatriz4x4(inversaMatriz4x4);

    // Testar a multiplicação de matriz 4x4 por escalar
    Matriz4x4 resultadoMatriz4x4PorEscalar = multiplicar4x4PorEscalar(matriz4x4_A, -2);
    printf("\nResultado da multiplicação da matriz 4x4 por escalar:\n");
    imprimirMatriz4x4(resultadoMatriz4x4PorEscalar);

    // Testar a multiplicação de matrizes 4x4
    Matriz4x4 resultadoMatriz4x4 = multiplicar4x4Por4x4(matriz4x4_A, matriz4x4_B);
    printf("\nResultado da multiplicação das matrizes 4x4:\n");
    imprimirMatriz4x4(resultadoMatriz4x4);

    // Testar a multiplicação de matriz 4x4 com matriz 4x1
    Matriz4x1 resultadoMatriz4x1 = multiplicar4x4Por4x1(matriz4x4_A, matriz4x1_A);
    printf("\nResultado da multiplicação da matriz 4x4 com a matriz 4x1:\n");
    imprimirMatriz4x1(resultadoMatriz4x1);

    return 0;
}