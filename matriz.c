#include <stdio.h>
#include "matriz.h"

float det2x2(Matriz2x2 mat)
{
    return mat.elemento[0][0] * mat.elemento[1][1] - mat.elemento[0][1] * mat.elemento[1][0];
}

float det3x3(Matriz3x3 mat)
{
    float determinante;

    determinante = mat.elemento[0][0] * (mat.elemento[1][1] * mat.elemento[2][2] - mat.elemento[2][1] * mat.elemento[1][2]) -
                   mat.elemento[0][1] * (mat.elemento[1][0] * mat.elemento[2][2] - mat.elemento[2][0] * mat.elemento[1][2]) +
                   mat.elemento[0][2] * (mat.elemento[1][0] * mat.elemento[2][1] - mat.elemento[2][0] * mat.elemento[1][1]);

    return determinante;
}

Matriz3x3 transpor3x3(Matriz3x3 mat)
{
    Matriz3x3 resultado = {};

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            resultado.elemento[i][j] = mat.elemento[j][i];
        }
    }

    return resultado;
}

Matriz3x3 adjunta3x3(Matriz3x3 mat)
{
    Matriz3x3 resultado = {};

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            Matriz2x2 subMat = {
                {{mat.elemento[(i + 1) % 3][(j + 1) % 3], mat.elemento[(i + 1) % 3][(j + 2) % 3]},
                 {mat.elemento[(i + 2) % 3][(j + 1) % 3], mat.elemento[(i + 2) % 3][(j + 2) % 3]}}};

            float det2x2_result = det2x2(subMat);

            resultado.elemento[i][j] = det2x2_result;
        }
    }

    resultado = transpor3x3(resultado);

    return resultado;
}

Matriz3x3 inversa3x3(Matriz3x3 mat)
{
    Matriz3x3 resultado = {};
    float determinante = det3x3(mat);

    if (determinante == 0)
    {
        printf("A matriz não é invertível.\n");
        return resultado;
    }

    float invDet = 1.0 / determinante;

    Matriz3x3 adjunta = adjunta3x3(mat);

    resultado = multiplicar3x3PorEscalar(adjunta, invDet);

    return resultado;
}

Matriz3x3 multiplicar3x3PorEscalar(Matriz3x3 mat, float escalar)
{
    Matriz3x3 resultado = {0};

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            resultado.elemento[i][j] = mat.elemento[i][j] * escalar;
        }
    }

    return resultado;
}

Matriz3x3 multiplicar3x3Por3x3(Matriz3x3 mat1, Matriz3x3 mat2)
{
    Matriz3x3 resultado = {};

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                resultado.elemento[i][j] += mat1.elemento[i][k] * mat2.elemento[k][j];
            }
        }
    }

    return resultado;
}

Matriz3x1 multiplicar3x3Por3x1(Matriz3x3 mat1, Matriz3x1 mat2)
{
    Matriz3x1 resultado = {};

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            resultado.elemento[i][0] += mat1.elemento[i][j] * mat2.elemento[j][0];
        }
    }

    return resultado;
}

Matriz3x1 multiplicar3x1PorEscalar(Matriz3x1 mat, float escalar)
{
    Matriz3x1 resultado = {};

    for (int i = 0; i < 3; ++i)
    {
        resultado.elemento[i][0] = mat.elemento[i][0] * escalar;
    }

    return resultado;
}

Matriz3x1 somar3x1(Matriz3x1 mat1, Matriz3x1 mat2)
{
    Matriz3x1 resultado = {};

    for (int i = 0; i < 3; ++i)
    {
        resultado.elemento[i][0] = mat1.elemento[i][0] + mat2.elemento[i][0];
    }

    return resultado;
}

Matriz3x1 subtrair3x1(Matriz3x1 mat1, Matriz3x1 mat2)
{
    Matriz3x1 resultado = {};

    for (int i = 0; i < 3; ++i)
    {
        resultado.elemento[i][0] = mat1.elemento[i][0] - mat2.elemento[i][0];
    }

    return resultado;
}
