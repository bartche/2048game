#include "raylib.h"
#include "funcoes.h"
#include "jogadas.h"
#include "stdio.h"

int main(void)
{

    // Define tamanho da tela
    const int alturaJanela = 615;
    const int larguraJanela = 800;

    // Define tamanho das pecas
    float alturaPeca = 106;
    float larguraPeca = 106;

    // Inicia a tela do jogo
    InitWindow(alturaJanela, larguraJanela, "2048");

    // Carrega imagens e texturas do jogo
    Texture2D background = LoadTexture("../resources/background.png");
    Texture2D numeros = LoadTexture("../resources/numeros.png");
    Image icon = LoadImage("../resources/icon.png");
    SetWindowIcon(icon);

    // Define espaco de jogo
    int jogo[4][4] = { {NULL, NULL, NULL, NULL},
                       {NULL, NULL, NULL, NULL},
                       {NULL, NULL, NULL, NULL},
                       {NULL, NULL, NULL, NULL} };

    // Adiciona duas pecas para comecar
    for (int i = 0; i < 2; i++)
    {
    
        Vector2 posicao = posicaoAleatoria();

        if (i != 0)
        {
            while (jogo[posicao.x][posicao.y] != NULL)
            {
                posicao = posicaoAleatoria();    
            }

            jogo[posicao.x][posicao.y] = numeroAleatorio();
            break;
        }

        jogo[posicao.x][posicao.y] = numeroAleatorio();

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
    printf("---------------\n");

    // Loop principal do jogo
    while (!WindowShouldClose())
    {

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawTexture(background, 0, 0, WHITE);

            if (IsKeyPressed(KEY_RIGHT))
            {

                paraDireita();
                adicionarPeca();

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        printf("%d ", jogo[i][j]);
                    }
                    printf("\n");
                }
                printf("---------------\n");

            }

        EndDrawing();

    }

    UnloadImage(icon);
    UnloadTexture(background);
    UnloadTexture(numeros);
    CloseWindow();

    return 0;
}