// Your code goes in this file.
// This is the ONLY file you submit.

#include <stdio.h>
#include <string.h>
#include "ppm.h"

typedef struct position {
	int x;
	int y;
} pos;

void make2(char [] , char [] , char []);
void make3(char [] , char [] , char []);

int main() {
	char suit[2];
	char number[2];
	char ext [] = ".ppm";

	char small[60];
	char large[60];
	char numberStr[60];

	printf("Enter a suit: ");
	scanf("%s" , &suit);

	printf("Enter a number: ");
	scanf("%s" , &number);

	strcpy(small , "images\\small-");
	strcat(small , suit);
	strcat(small , ext);

	strcpy(large , "images\\large-");
	strcat(large , suit);
	strcat(large , ext);

	strcpy(numberStr , "images\\");

	if(number[0] == 'j' || number[0] == 'q' || number[0] == 'k' || number[0] == 'a') {
		strcat(numberStr , "face-");
		strcat(numberStr , number);
		strcat(numberStr , suit);
	}
	else {
		if(suit[0] == 'd' || suit[0] == 'h') {
			strcat(numberStr , "red-");
			strcat(numberStr , number);
		}
		else {
			strcat(numberStr , "black-");
			strcat(numberStr , number);
		}
	}
	strcat(numberStr , ext);

	puts(small);
	puts(large);
	puts(numberStr);

	switch(number[0]) {
	case '2':
		make2(small , large , numberStr);
		break;
	case '3':
		make3(small , large , numberStr);
		break;
	default:
		break;
	}

	system("pause");
}

//. Currently makes the number 2
void make2(char small [] , char large [] , char number []) {
	pos numPos = {
		3 ,
		4
	};

	pos smallShapePos = {
		3 ,
		19
	};

	pos largeShapePos;

	pos botNumPos;
	pos botLargestShapePos;
	pos botSmallShapePos;

	ppm_t smallPPM = NULL_PPM;
	ppm_t largePPM = NULL_PPM;
	ppm_t newCard = NULL_PPM;
	ppm_t numberPPM = NULL_PPM;
	int r = 0;
	int c = 0;

	int x = 0;
	int y = 0;

	smallPPM = loadPpm(small);
	largePPM = loadPpm(large);
	numberPPM = loadPpm(number);
	newCard = loadPpm("images\\border.ppm");

	largeShapePos.x = newCard.cols / 2 - 7;
	largeShapePos.y = 19 - 7;

	botLargestShapePos.x = newCard.cols / 2 - 6;
	botLargestShapePos.y = newCard.rows - 19 - 7;

	botSmallShapePos.x = newCard.cols - smallShapePos.x - 11;
	botSmallShapePos.y = newCard.rows - smallShapePos.y - 12;

	botNumPos.x = newCard.cols - 3 - 11;
	botNumPos.y = newCard.rows - 4 - 14;

	//. Places a number in the upper left corner
	for(r = 0 , x = 0 , y = 0; r < numberPPM.rows; r++ , y++) {
		for(c = 0 , y = 0; c < numberPPM.cols; c++ , x++) {
			newCard.data[r + numPos.y][c + numPos.x].red = numberPPM.data[r][c].red;
			newCard.data[r + numPos.y][c + numPos.x].green = numberPPM.data[r][c].green;
			newCard.data[r + numPos.y][c + numPos.x].blue = numberPPM.data[r][c].blue;
		}
		x = 0;
	}

	//. Places a small icon on under the number in the top right corner.
	for(r = 0; r < smallPPM.rows; r++) {
		for(c = 0; c < smallPPM.cols; c++) {
			newCard.data[r + smallShapePos.y][c + smallShapePos.x].red = smallPPM.data[r][c].red;
			newCard.data[r + smallShapePos.y][c + smallShapePos.x].green = smallPPM.data[r][c].green;
			newCard.data[r + smallShapePos.y][c + smallShapePos.x].blue = smallPPM.data[r][c].blue;
		}
	}

	//. Places the large icon into the center of the card.
	for(r = 0; r < largePPM.rows; r++) {
		for(c = 0; c < largePPM.cols; c++) {
			newCard.data[r + largeShapePos.y][c + largeShapePos.x].red = largePPM.data[r][c].red;
			newCard.data[r + largeShapePos.y][c + largeShapePos.x].green = largePPM.data[r][c].green;
			newCard.data[r + largeShapePos.y][c + largeShapePos.x].blue = largePPM.data[r][c].blue;
		}
	}

	//. For placing a number upsidown on the card
	//  used for the bottom right hand corner.
	for(r = numberPPM.rows - 1 , x = 0 , y = 0; r > -1; r-- , y++) {
		for(c = numberPPM.cols - 1; c > -1; c-- , x++) {
			newCard.data[y + botNumPos.y][x + botNumPos.x].red = numberPPM.data[r][c].red;
			newCard.data[y + botNumPos.y][x + botNumPos.x].green = numberPPM.data[r][c].green;
			newCard.data[y + botNumPos.y][x + botNumPos.x].blue = numberPPM.data[r][c].blue;
		}
		x = 0;
	}

	//. For placing small PPM icon above bottom right number
	for(r = smallPPM.rows - 1 , x = 0 , y = 0; r > -1; r-- , y++) {
		for(c = 0; c < smallPPM.cols; c++ , x++) {
			newCard.data[y + botSmallShapePos.y][x + botSmallShapePos.x].red = smallPPM.data[r][c].red;
			newCard.data[y + botSmallShapePos.y][x + botSmallShapePos.x].green = smallPPM.data[r][c].green;
			newCard.data[y + botSmallShapePos.y][x + botSmallShapePos.x].blue = smallPPM.data[r][c].blue;
		}
		x = 0;
	}

	//. For placing large PPM icon
	for(r = largePPM.rows - 1 , x = 0 , y = 0; r > -1; r-- , y++) {
		for(c = 0; c < largePPM.cols; c++ , x++) {
			newCard.data[y + botLargestShapePos.y][x + botLargestShapePos.x].red = largePPM.data[r][c].red;
			newCard.data[y + botLargestShapePos.y][x + botLargestShapePos.x].green = largePPM.data[r][c].green;
			newCard.data[y + botLargestShapePos.y][x + botLargestShapePos.x].blue = largePPM.data[r][c].blue;
		}
		x = 0;
	}

	savePpm("test.ppm" , newCard);

	freePpm(newCard);
	freePpm(smallPPM);
	freePpm(largePPM);
	freePpm(numberPPM);
}

//. Currently makes the number 2
void make3(char small [] , char large [] , char number []) {
	pos numPos = {
		3 ,
		4
	};

	pos smallShapePos = {
		3 ,
		19
	};

	pos largeShapePos;

	pos botNumPos;
	pos botLargestShapePos;
	pos botSmallShapePos;
	pos midLargeShapePos;

	ppm_t smallPPM = NULL_PPM;
	ppm_t largePPM = NULL_PPM;
	ppm_t newCard = NULL_PPM;
	ppm_t numberPPM = NULL_PPM;
	int r = 0;
	int c = 0;

	int x = 0;
	int y = 0;

	smallPPM = loadPpm(small);
	largePPM = loadPpm(large);
	numberPPM = loadPpm(number);
	newCard = loadPpm("images\\border.ppm");

	largeShapePos.x = newCard.cols / 2 - 7;
	largeShapePos.y = 19 - 7;

	botLargestShapePos.x = newCard.cols / 2 - 6;
	botLargestShapePos.y = newCard.rows - 19 - 7;

	botSmallShapePos.x = newCard.cols - smallShapePos.x - 11;
	botSmallShapePos.y = newCard.rows - smallShapePos.y - 12;

	midLargeShapePos.x = newCard.cols / 2 - 7;
	midLargeShapePos.y = newCard.rows / 2 - 7;

	botNumPos.x = newCard.cols - 3 - 11;
	botNumPos.y = newCard.rows - 4 - 14;

	//. Places a number in the upper left corner
	for(r = 0 , x = 0 , y = 0; r < numberPPM.rows; r++ , y++) {
		for(c = 0 , y = 0; c < numberPPM.cols; c++ , x++) {
			newCard.data[r + numPos.y][c + numPos.x].red = numberPPM.data[r][c].red;
			newCard.data[r + numPos.y][c + numPos.x].green = numberPPM.data[r][c].green;
			newCard.data[r + numPos.y][c + numPos.x].blue = numberPPM.data[r][c].blue;
		}
		x = 0;
	}

	//. Places a small icon on under the number in the top right corner.
	for(r = 0; r < smallPPM.rows; r++) {
		for(c = 0; c < smallPPM.cols; c++) {
			newCard.data[r + smallShapePos.y][c + smallShapePos.x].red = smallPPM.data[r][c].red;
			newCard.data[r + smallShapePos.y][c + smallShapePos.x].green = smallPPM.data[r][c].green;
			newCard.data[r + smallShapePos.y][c + smallShapePos.x].blue = smallPPM.data[r][c].blue;
		}
	}

	//. Places the large icon into the center of the card top.
	for(r = 0; r < largePPM.rows; r++) {
		for(c = 0; c < largePPM.cols; c++) {
			newCard.data[r + largeShapePos.y][c + largeShapePos.x].red = largePPM.data[r][c].red;
			newCard.data[r + largeShapePos.y][c + largeShapePos.x].green = largePPM.data[r][c].green;
			newCard.data[r + largeShapePos.y][c + largeShapePos.x].blue = largePPM.data[r][c].blue;
		}
	}

	//. Places the large icon into the center of the card MIDDLE.
	for(r = 0; r < largePPM.rows; r++) {
		for(c = 0; c < largePPM.cols; c++) {
			newCard.data[r + midLargeShapePos.y][c + midLargeShapePos.x].red = largePPM.data[r][c].red;
			newCard.data[r + midLargeShapePos.y][c + midLargeShapePos.x].green = largePPM.data[r][c].green;
			newCard.data[r + midLargeShapePos.y][c + midLargeShapePos.x].blue = largePPM.data[r][c].blue;
		}
	}

	//. For placing a number upsidown on the card
	//  used for the bottom right hand corner.
	for(r = numberPPM.rows - 1 , x = 0 , y = 0; r > -1; r-- , y++) {
		for(c = numberPPM.cols - 1; c > -1; c-- , x++) {
			newCard.data[y + botNumPos.y][x + botNumPos.x].red = numberPPM.data[r][c].red;
			newCard.data[y + botNumPos.y][x + botNumPos.x].green = numberPPM.data[r][c].green;
			newCard.data[y + botNumPos.y][x + botNumPos.x].blue = numberPPM.data[r][c].blue;
		}
		x = 0;
	}

	//. For placing small PPM icon above bottom right number
	for(r = smallPPM.rows - 1 , x = 0 , y = 0; r > -1; r-- , y++) {
		for(c = 0; c < smallPPM.cols; c++ , x++) {
			newCard.data[y + botSmallShapePos.y][x + botSmallShapePos.x].red = smallPPM.data[r][c].red;
			newCard.data[y + botSmallShapePos.y][x + botSmallShapePos.x].green = smallPPM.data[r][c].green;
			newCard.data[y + botSmallShapePos.y][x + botSmallShapePos.x].blue = smallPPM.data[r][c].blue;
		}
		x = 0;
	}

	//. For placing large PPM icon
	for(r = largePPM.rows - 1 , x = 0 , y = 0; r > -1; r-- , y++) {
		for(c = 0; c < largePPM.cols; c++ , x++) {
			newCard.data[y + botLargestShapePos.y][x + botLargestShapePos.x].red = largePPM.data[r][c].red;
			newCard.data[y + botLargestShapePos.y][x + botLargestShapePos.x].green = largePPM.data[r][c].green;
			newCard.data[y + botLargestShapePos.y][x + botLargestShapePos.x].blue = largePPM.data[r][c].blue;
		}
		x = 0;
	}

	savePpm("test.ppm" , newCard);

	freePpm(newCard);
	freePpm(smallPPM);
	freePpm(largePPM);
	freePpm(numberPPM);
}