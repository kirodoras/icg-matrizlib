#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct
{
    float elemento[2][2];
} Matriz2x2;

typedef struct
{
    float elemento[3][3];
} Matriz3x3;

typedef struct
{
    float elemento[3][1];
} Matriz3x1;

float det2x2(Matriz2x2 mat);
float det3x3(Matriz3x3 mat);

Matriz3x3 transpor3x3(Matriz3x3 mat);
Matriz3x3 adjunta3x3(Matriz3x3 mat);
Matriz3x3 inversa3x3(Matriz3x3 mat);

Matriz3x3 multiplicar3x3PorEscalar(Matriz3x3 mat, float escalar);
Matriz3x3 multiplicar3x3Por3x3(Matriz3x3 mat1, Matriz3x3 mat2);
Matriz3x1 multiplicar3x3Por3x1(Matriz3x3 mat1, Matriz3x1 mat2);

Matriz3x1 multiplicar3x1PorEscalar(Matriz3x1 mat, float escalar);

Matriz3x1 somar3x1(Matriz3x1 mat1, Matriz3x1 mat2);
Matriz3x1 subtrair3x1(Matriz3x1 mat1, Matriz3x1 mat2);

#endif