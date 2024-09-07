/*--------------------------------------------------------*
 * Disciplina: Programação Estruturada e Modular          *
 *               Prof. Carlos Veríssimo                   *
 *--------------------------------------------------------*
 * Objetivo do                                            *
 *   Programa: Desenvolva um código (linguagem C) que, a  *
 *             partir do tabuleiro montado (Atividade     *
 *             N1-3), seja simulado os 3 lances do "Xeque *
 *             Pastor".                                   *
 *       Data: 06/09/2024                                 * 
 *      Autor: Fernanda Yui Bam Suzukawa                  *
 *--------------------------------------------------------*/


#include <stdio.h>
#define WHITE_BG "\x1b[48;2;131;131;131m"
#define BLACK_BG "\x1b[48;2;32;32;32m"
#define SIZE 8
#define RESET_COLOR "\x1b[0m"
#include <string.h>
#include <ctype.h>
#define EMPTY "   "
#define PREVIOUS "..."


int spawnChess(char board[SIZE][SIZE][4]) {
	const char *pieces[] = {"T1", "C1", "B1", "D1", "R1", "B2", "C2", "T2"};

	for (int row = 0; row < SIZE; row ++) {
		for (int col = 0; col < SIZE; col++) {
			snprintf(board[row][col], 4, EMPTY);
		}
	}

	for (int col = 0; col < SIZE; col++) {
		snprintf(board[0][col], 4, "B%s", pieces[col]);
		snprintf(board[7][col], 4, "P%s", pieces[col]);

		snprintf(board[1][col], 4, "BP%i", col + 1);
		snprintf(board[6][col], 4, "PP%i", col + 1);
	}
}


int printChess(char board[SIZE][SIZE][4]) {
	printf("    a    b    c    d    e    f    g    h\n");

	for (int row = 0; row < SIZE; row++) {
		printf("%d ", SIZE - row);
		
		for (int col = 0; col < SIZE; col++) {
			if ((row + col) % 2 == 0) {
				printf("%s",BLACK_BG);
			} else {
				printf("%s",WHITE_BG);
			}
			printf(" %s %s", board[row][col], RESET_COLOR);
		}
		printf("\n");
	}
}


int convertToIndex(char file, int rank, int *row, int *col) {
    *col = tolower(file) - 'a';
    *row = SIZE - rank;
    
    return (*col >= 0 && *col < SIZE && *row >= 0 && *row < SIZE);
}


void movePiece(char board[SIZE][SIZE][4], char startFile, int startRank, char endFile, int endRank, int *prevRow, int *prevCol) {
    int startRow, startCol, endRow, endCol;

    if (convertToIndex(startFile, startRank, &startRow, &startCol) &&
        convertToIndex(endFile, endRank, &endRow, &endCol)) {

        if (*prevRow != -1 && *prevCol != -1) {
            snprintf(board[*prevRow][*prevCol], 4, "%s", EMPTY);
        }

        snprintf(board[endRow][endCol], 4, "%s", board[startRow][startCol]);

        snprintf(board[startRow][startCol], 4, "%s", PREVIOUS);

        *prevRow = startRow;
        *prevCol = startCol;
        
    } else {
        printf("Invalid move notation.\n");
    }
}


int main() {
	char board[SIZE][SIZE][4];
	int prevRow = -1, prevCol = -1; 
	
	spawnChess(board);
	printChess(board);
	
	printf("\n===========================================");
	printf("\n\nTURN #1:\n");
	printf("White: e4\n");
	movePiece(board,'e',2,'e',4,&prevRow, &prevCol);
	printChess(board);

	printf("\nBlack: e5\n");
	movePiece(board,'e',7,'e',5,&prevRow, &prevCol);
	printChess(board);
	
	printf("\n===========================================");
	printf("\n\nTURN #2:\n");
	printf("White: Bc4\n");
	movePiece(board,'f',1,'c',4,&prevRow, &prevCol);
	printChess(board);
	
	printf("\nBlack: Cc6\n");
	movePiece(board,'b',8,'c',6,&prevRow, &prevCol);
	printChess(board);
	
	printf("\n===========================================");
	printf("\n\nTURN #3:\n");
	printf("White: Dh5\n");
	movePiece(board,'d',1,'h',5,&prevRow, &prevCol);
	printChess(board);
	
	printf("\nBlack: Cf6\n");
	movePiece(board,'g',8,'f',6,&prevRow, &prevCol);
	printChess(board);

	printf("\n===========================================");
	printf("\n\nTURN #4: CHECK MATE\n");
	printf("White wins: Dxf7\n");
	movePiece(board,'h',5,'f',7,&prevRow, &prevCol);
	printChess(board);

	
	return 0;
}