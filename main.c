#include "raylib.h"
#include "funcoes.h"
#include "stdio.h"

int main(void)
{

    // Define tamanho da tela
    const int alturaJanela = 615;
    const int larguraJanela = 800;

    // Inicia a tela do jogo
    InitWindow(alturaJanela, larguraJanela, "2048");

    // Carrega imagens e texturas do jogo
    Texture2D background = LoadTexture("../resources/background.png");
    Texture2D numeros = LoadTexture("../resources/numeros.png");
    Image icon = LoadImage("../resources/icon.png");
    SetWindowIcon(icon);

    // Define espaco de jogo
    int jogo[4][4] = { {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0} };

    // Define duas posicoes aleatorias para comecar
    for (int i = 0; i < 2; i++)
    {
        Vector2 posicao = posicaoAleatoria();
        jogo[posicao.x][posicao.y] = numeroAleatorio();

        // TODO: nao deixar aparecer no mesmo lugar

    }

    // Mostrar jogo no console para debug
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", jogo[i][j]);
        }
        printf("\n");
    }

    // Loop principal do jogo
    while (!WindowShouldClose())
    {

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawTexture(background, 0, 0, WHITE);

        EndDrawing();

    }

    UnloadImage(icon);
    UnloadTexture(background);
    UnloadTexture(numeros);
    CloseWindow();

    return 0;
}