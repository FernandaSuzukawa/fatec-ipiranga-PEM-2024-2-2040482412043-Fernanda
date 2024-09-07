/*--------------------------------------------------------*
 * Disciplina: Programaçao Estruturada e Modular          *
 *               Prof. Carlos Veríssimo                   *
 *--------------------------------------------------------*
 * Objetivo do                                            *
 *   Programa: Montar o tabuleiro utilizando conjunto de  *
 *             vetores unidimensionais                    *
 *       Data: 30/08/2024                                 * 
 *      Autor: Fernanda Yui Bam Suzukawa                  *
 *--------------------------------------------------------*/


#include <stdio.h>
#define WHITE_BG "\x1b[48;2;131;131;131m"
#define BLACK_BG "\x1b[48;2;32;32;32m"
#define SIZE 320
#define RESET_COLOR "\x1b[0m"


int spawnChess(char board[SIZE]) {
    printf("    a    b    c    d    e    f    g    h\n");
    const char *pieces[] = {"T1", "C1", "B1", "D1", "R1", "B2", "C2", "T2"};

    for (int i = 0; i < SIZE; i += 5) {
        snprintf(&board[i], 5, " X ");
    }
    
    for (int i = 0; i < 8; i++) {
        snprintf(&board[i * 5], 5, "B%s", pieces[i]);
        snprintf(&board[(56 + i) * 5], 5, "P%s", pieces[i]);
        
        snprintf(&board[(8 + i) * 5], 5, "BP%i", (i + 1));
        snprintf(&board[(48 + i) * 5], 5, "PP%i", (i + 1));
    }

    for (int i = 0; i < 64; i++) {
        if (i % 8 == 0) {
            printf("%d ", i / 8 + 1);
        }

        if ((i / 8 + i % 8) % 2 == 0) {
            printf("%s",BLACK_BG);
        } else {
            printf("%s",WHITE_BG);
        }
        printf(" %s %s", &board[i * 5], RESET_COLOR);
        
        if ((i + 1) % 8 == 0) {
            printf("\n");
        } 
    }
}


int main()
{
    char board[SIZE];
    spawnChess(board);
    return 0;
}