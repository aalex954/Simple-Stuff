/**-------------------------------------------------------------------
   You may NOT edit this file. 
-------------------------------------------------------------------*/

#ifndef __ppm_h__
#define __ppm_h__

/**
 * Struct used to represent a pixel.  
 * Each pixel is made up of a red, green, and blue component.
 */
typedef struct pixel_t {
	int red;
	int green;
	int blue;
} pixel_t;

/**
 * The (struct) type used for ppm.
 * A ppm knows its number of rows and columns, and
 * contains a 2D array of pixels.
 */
typedef struct ppm_t {
  int rows;
  int cols;
  pixel_t **data;
} ppm_t;


/**
 * Represents an empty (NULL) ppm.
 * Returned by makePpm and loadPpm when there is an error.
 */
extern const ppm_t NULL_PPM;

/**
 * Allocates space for an empty ppm of the given size.
 * <b>NOTE: Remember to call freePpm when you are done.</b>
 * @param nrows the number of rows
 * @param ncolumns the number of columns (this is multiplied by 3 inside the function)
 * @return the ppm or NULL_PPM if error.
 */
ppm_t makePpm(int nrows, int ncolumns);

/**
 * Frees the memory allocated by makePpm and loadPpm.
 * @param ppm the ppm (created/allocated by makePpm or loadPpm).
 */
void freePpm(ppm_t ppm);

/**
 * Allocates necessary space for and 
 * loads a ppm from the given file.
 * <b>NOTE: Remember to call freePpm when you are done.</b>
 * @param filename the name of the ppm file.
 * @return the ppm or NULL_PPM if error.
 */
ppm_t loadPpm(char filename[]);

/**
 * Saves the ppm to the specified file.
 * @param filename the name of the file to save.
 * @param ppm the ppm being saved.
 */
void savePpm(char filename[], ppm_t ppm);

#endif