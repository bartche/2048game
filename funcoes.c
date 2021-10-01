#include "raylib.h"
#include "stdlib.h"
#include "time.h"

//extern jogo;

/*Vector2 posicaoAleatoria()
{

    srand(time(NULL));

    for (int i = 0; i < 2; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;

        Vector2 posicao = {x, y};
        return posicao;
    }
}*/

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

/*void adicionarPeca()
{

    Vector2 posicao = posicaoAleatoria();

    while (jogo[posicao.x][posicao.y] != NULL)
    {
        posicao = posicaoAleatoria();    
    }

    jogo[posicao.x][posicao.y] = numeroAleatorio();

}*/