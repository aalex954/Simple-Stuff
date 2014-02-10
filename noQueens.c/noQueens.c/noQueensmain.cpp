#include<stdio.h>
#include <stdlib.h>

#define SIZE 4

typedef char board_t[SIZE][SIZE];

const char EMPTY = '.';
const char QUEEN = 'Q';

void initBoard(board_t);
void printBoard(const board_t);
int isSafe(int, int, board_t);

int main() {
	int i = 0;
	board_t b1;
	board_t b2;
	board_t b3;
	board_t b4;

	initBoard(b1);
	initBoard(b2);
	initBoard(b3);
	initBoard(b4);

	//b1[0][0] = 'Q';
	//b2[0][0] = 'Q';
	//b3[0][0] = 'Q';
	//b4[0][0] = 'Q';
	
	b1[0][1] = 'Q';
	b2[1][0] = 'Q';
	b3[1][1] = 'Q';
	b4[3][1] = 'Q';

	printBoard(b1);
	printBoard(b2);
	printBoard(b3);
	printBoard(b4);

	printf("%d" , isSafe(0 , 1 , b1));
	printf("%d" , isSafe(1 , 0 , b2));
	printf("%d" , isSafe(1 , 1 , b3));
	printf("%d" , isSafe(3 , 1 , b4));

	system("pause");
}

void initBoard(board_t board) {
	int r = 0;
	int c = 0;

	for(r = 0; r < SIZE; r++) {
		for(c = 0; c < SIZE; c++) {
			board[r][c] = EMPTY;
		} 
	}
}

void printBoard(const board_t board) {
	int r = 0;
	int c = 0;

	for(r = 0; r < SIZE; r++) {
		for(c = 0; c < SIZE; c++) {
			printf("%c" , board[r][c]);
		}
		puts("");
	}
	puts("");
}

int isSafe(int row , int col , board_t board) {
	int countInRow = 0;
	int countInCol = 0;
	int countDiagnal = 0;

	int c = 0;
	int r = 0;

	//. Counts the queen in the row
	for(c = 0; c < SIZE; c++) {
		if(board[row][c] == 'Q') {
			countInRow++;
		}
	}

	//. Count in Col
	for(r = 0; r < SIZE; r++) {
		if(board[r][col] == 'Q') {
			countInRow++;
		}
	}

	//. check diagnal down left
	for(r = row; r < SIZE; r++) {
		for(c = col; c >= 0; c--) {
			if(board[r][c] == 'Q') {
				countDiagnal++;
			}
		}
	}

	for(r = row; r >= 0; r--) {
		for(c = col; c >= 0; c--) {
			if(board[r][c] == 'Q') {
				countDiagnal++;
			}
		}
	}

	if(countInRow > 1) { 
		return 0;
	}
	else if(countInCol > 1) {
		return 0;
	}
	else if(countDiagnal > 0) {
		return 0;
	}
	else {
	 return 0;
	}

}