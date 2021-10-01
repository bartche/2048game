#include "stdio.h"

extern jogo;

void paraDireita()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (jogo[i][j] != NULL)
            {
                int temp = jogo[i][j];
                jogo[i][j] = NULL;
                switch (i) {
                    case 0: {
                        if (jogo[0][(j+(3-j))] == NULL)
                        {
                            jogo[0][(j+(3-j))] = temp;
                        } else if (temp == jogo[0][(j+(3-j))])
                        {
                            jogo[0][(j+(3-j))] * 2;
                        } else {
                            for (int k = 3; k >= 0; k--) // Nao ta somando quando igual
                            {                           // Substituindo quando eh diferente
                               jogo[0][(j+(k-j))] = temp; 
                            }
                        }
                        break;
                    }
                    case 1: {
                        jogo[1][(j+(3-j))] = temp;
                        break;
                    }
                    case 2: {
                        jogo[2][(j+(3-j))] = temp;
                        break;
                    }
                    case 3: {
                        jogo[3][(j+(3-j))] = temp;
                        break;
                    }
                }

            }
        }
    }
}

void paraEsquerda()
{

}

void paraCima()
{

}

void paraBaixo()
{

}