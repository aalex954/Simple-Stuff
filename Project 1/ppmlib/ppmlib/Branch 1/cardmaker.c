// Your code goes in this file.
// This is the ONLY file you submit.

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "ppm.h"


//Prototype-----------------------------------------
void chooseNumber(char [] , char []);

void copyInto(const ppm_t m , ppm_t , int , int);
void copyIntoFlipped(const ppm_t , ppm_t , int , int);

void placeNumber(const ppm_t , ppm_t);
void placeSmallIcon(const ppm_t , const ppm_t , ppm_t);

void cardChooser(const ppm_t , ppm_t , char []);


/////////////////////////////////////////////////////
//-------------->ICON POSITIONS<---------------------
/////////////////////////////////////////////////////

void placeIconTopCenter(const ppm_t , ppm_t);
void placeIconDeadCenter(const ppm_t , ppm_t);
void placeIconBotCenter(const ppm_t , ppm_t);
void placeIconTopLeft(const ppm_t, ppm_t);

char numberPath[60];
const char ext [] = ".ppm";

// Main---------------------------------------------
int main() {
	ppm_t newPPM = loadPpm("images\\border.ppm");

	char smallPath[60];
	char largePath[60];

	char suit[2];
	char number[2];

	printf("Enter in a suit :");
	scanf("%s" , &suit);

	printf("Enter in a number :");
	scanf("%s" , &number);

	strcpy(smallPath , "images\\small-");
	strcpy(largePath , "images\\large-");

	chooseNumber(number , suit);

	strcat(smallPath , suit);
	strcat(smallPath , ext);

	strcat(largePath , suit);
	strcat(largePath , ext);

	placeNumber(loadPpm(numberPath) , newPPM);
	placeSmallIcon(loadPpm(numberPath) , loadPpm(smallPath) , newPPM);

	cardChooser(loadPpm(smallPath) , newPPM , number);

	savePpm("card.ppm" , newPPM);

	system("pause");
}

//Method for copying the constant ppm into the changeable ppm
void copyInto(const ppm_t unchange , ppm_t changeable , int row , int col) {

	int r = 0;
	int c = 0;

	for(r = 0; r < unchange.rows; r++) {
		assert(row > -1 && row < 97);
		for(c = 0; c < unchange.cols; c++) {
			assert(col > -1 && col < 73);
			changeable.data[r + row][c + col].red = unchange.data[r][c].red;
			changeable.data[r + row][c + col].green = unchange.data[r][c].green;
			changeable.data[r + row][c + col].blue = unchange.data[r][c].blue;
		}
	}
}

//Method for copying the constant ppm into the changeable ppm FLIPPED
void copyIntoFlipped(const ppm_t unchange , ppm_t changeable , int row , int col) {

	int x = 0;
	int y = 0;

	int r = 0;
	int c = 0;

	//. For placing a ppm upsidown on the changeable ppm
	//  used for the bottom right hand corner or other flipped ppms
	for(r = unchange.rows - 1 , x = 0 , y = 0; r > -1; r-- , y++) {
		assert(row > -1 && row < 97);
		for(c = unchange.cols - 1; c > -1; c-- , x++) {
			assert(col > -1 && col < 73);
			changeable.data[y + row][x + col].red = unchange.data[r][c].red;
			changeable.data[y + row][x + col].green = unchange.data[r][c].green;
			changeable.data[y + row][x + col].blue = unchange.data[r][c].blue;
		}
		x = 0;
	}
}
//. POSITION OF THE ICONS
///////////////////////////////////////////////////////////////////////////

void placeIconTopCenter(const ppm_t icon , ppm_t changeable) {
	int y = 18 - icon.rows / 2;
	int x = 36 - icon.cols / 2;
	copyInto(icon , changeable , y , x);
}

void placeIconDeadCenter(const ppm_t icon , ppm_t changeable) {
	int y = changeable.rows / 2 - icon.rows / 2;
	int x = changeable.cols / 2 - icon.cols / 2;

	copyInto(icon , changeable , y , x);
}

void placeIconBotCenter(const ppm_t icon , ppm_t changeable) {
	int y = changeable.rows - 18 - icon.rows / 2;
	int x = changeable.cols - 38 - icon.cols / 2;

	copyIntoFlipped(icon , changeable , y , x);
}

void placeIconTopLeft(const ppm_t icon, ppm_t changeable) {
	int y = 45;
	int x = changeable.cols 15 - icon.cols / 2;

	copyIntoFlipped(icon, changeable, y, x);
}

//////////////////////////////////////////////////////////////////////////

//. Places the number onto the card
void placeNumber(const ppm_t constPPM , ppm_t changeablePPM) {
	copyInto(constPPM , changeablePPM , 4 , 3);
	copyIntoFlipped(constPPM , changeablePPM , changeablePPM.rows - constPPM.rows - 4 , changeablePPM.cols - constPPM.cols - 3);
}

//. places the small icon below the number
void placeSmallIcon(const ppm_t number , const ppm_t smallIcon , ppm_t changeablePPM) {
	copyInto(smallIcon , changeablePPM , number.rows + 6 , 3);
	copyIntoFlipped(smallIcon , changeablePPM , changeablePPM.rows - number.rows - smallIcon.rows - 6 , changeablePPM.cols - number.cols - 3);
}

//. chooses which number to print on the card
void chooseNumber(char number [] , char suit []) {
	strcpy(numberPath , "images\\");

	if(suit[0] == 'h' || suit[0] == 'd') {
		strcat(numberPath , "red-");
	}
	else {
		strcat(numberPath , "black-");
	}

	strcat(numberPath , number);
	strcat(numberPath , ext);
}

void cardChooser(const ppm_t iconPPM , ppm_t changeablePPM , char number []) {
	int sY = 0;
	int sX = 0;
	int fY = 0;
	int fX = 0;

	switch(number[0]) {
	case '2':
		placeIconTopCenter(iconPPM , changeablePPM);
		placeIconBotCenter(iconPPM , changeablePPM);
		break;

	case '3':
		placeIconTopCenter(iconPPM , changeablePPM);
		placeIconDeadCenter(iconPPM , changeablePPM);
		placeIconBotCenter(iconPPM , changeablePPM);
		placeIconTopLeft(iconPPM, changeablePPM);
		break;
	default:
		break;
	}
}