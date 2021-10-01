#include "raylib.h"

Vector2 posicaoAleatoria()
{
    for (int i = 0; i < 2; i++)
    {
        int x = GetRandomValue(0, 3);
        int y = GetRandomValue(0, 3);

        Vector2 posicao = {x, y};
        return posicao;
    }
}

int numeroAleatorio()
{
    int numero = GetRandomValue(2, 4);
    
    while (numero == 3)
    {
        numero = GetRandomValue(2, 4);
    }

    return numero;
}