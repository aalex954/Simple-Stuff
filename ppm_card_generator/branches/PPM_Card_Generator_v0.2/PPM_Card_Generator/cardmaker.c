#include "ppm.h"
#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	ppm_t ppm = NULL_PPM;
	int r = 0;
	int c = 0;
	ppm_t newCard = NULL_PPM;
	
	ppm = loadPpm("images\\small-d.ppm");
	newCard = loadPpm("images\\border.ppm");

	for(c = 0; c < newCard.cols; c++) {
		newCard.data[20][c].red = 15;
		newCard.data[20][c].green = 0;
		newCard.data[20][c].blue = 0;
	}

	savePpm("test.ppm" , newCard);

	freePpm(newCard);
	freePpm(ppm);

	return 0;
}