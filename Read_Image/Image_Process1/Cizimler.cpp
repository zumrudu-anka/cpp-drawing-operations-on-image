#include "stdafx.h"
#include "Cizimler.h"

BYTE* DrawLine(BYTE* Buffer, int width, int height, int xx1, int yy1, int xx2, int yy2) {

	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// find the number of padding bytes

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;

	// create new buffer
	BYTE* newbuf = new BYTE[width*height];

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	for (int row = 0; row < height; row++)
		for (int column = 0; column < width; column++) {
			bufpos = (height - row - 1) * psw + column * 3;
			newbuf[row * width + column] = BYTE(0.11*Buffer[bufpos + 2] + 0.59*Buffer[bufpos + 1] + 0.3*Buffer[bufpos]);
		}

	double egim = ((height / 2 - yy2) - (height / 2 - yy1)) / ((width / 2 + xx2) - (width / 2 + xx1));

	if ((height / 2 - yy1) < (height / 2 - yy2)) {
		if ((width / 2 + xx1) < (width / 2 + xx2)) {
			for (int row = (height/2 - yy1); row < (height / 2 - yy2); row++) {
				for (int column = (width/2 + xx1); column <(width / 2 + xx2); column++) {
					if ( fabs((row - (height / 2 - yy1)) - (egim * (column - (width / 2 + xx1)))) < 1.5f ) {
						newbuf[row * width + column] = BYTE(0);
					}

				}
			}
		}
		else {
			for (int row = (height / 2 - yy1); row < (height / 2 - yy2); row++) {
				for (int column = (width / 2 + xx1); column > (width / 2 + xx2); column--) {
					if (fabs((row - (height / 2 - yy1)) - (egim * (column - (width / 2 + xx1)))) < 1.5f ) {
						newbuf[row * width + column] = BYTE(0);
					}
				}
			}
		}
	}
	else {
		if ((width / 2 + xx1) < (width / 2 + xx2)) {
			for (int row = (height / 2 - yy1); row > (height / 2 - yy2); row--) {
				for (int column = (width / 2 + xx1); column < (width / 2 + xx2); column++) {
					if (fabs((row - (height / 2 - yy1)) - (egim * (column - (width / 2 + xx1)))) < 1.5f ) {
						newbuf[row * width + column] = BYTE(0);
					}
				}
			}
		}
		else {
			for (int row = (height / 2 - yy1); row > (height / 2 - yy2); row--) {
				for (int column = (width / 2 + xx1); column > (width / 2 + xx2); column--) {
					if (fabs((row - (height / 2 - yy1)) - (egim * (column - (width / 2 + xx1)))) < 1.5f) {
						newbuf[row * width + column] = BYTE(0);
					}
				}
			}
		}
	}
	return newbuf;
}

BYTE* DrawCircle(BYTE* Buffer, int width, int height, int centerx, int centery, float radius) {

	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// find the number of padding bytes

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;

	// create new buffer
	BYTE* newbuf = new BYTE[width*height];

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	long newpos = 0;
	for (int row = 0; row < height; row++)
		for (int column = 0; column < width; column++) {
			newpos = row * width + column;
			bufpos = (height - row - 1) * psw + column * 3;
			newbuf[newpos] = BYTE(0.11*Buffer[bufpos + 2] + 0.59*Buffer[bufpos + 1] + 0.3*Buffer[bufpos]);
		}


	for (int row = 0; row < height; row++) {
		for (int column = 0; column < width ; column++) {
			if (sqrt(pow((height / 2 - row - centery),2) + pow((column - width / 2 - centerx),2)) <= (radius + 0.5f) && sqrt(pow((height / 2 - row - centery), 2) + pow((column - width / 2 - centerx), 2)) >= (radius - 0.5f)) {
				newpos = row * width + column;
				newbuf[newpos] = BYTE(0);
			}
		}
	}

	return newbuf;

}

BYTE* DrawEllipse(BYTE* Buffer, int width, int height, int centerx, int centery, int xrad, int yrad) {
	
	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// find the number of padding bytes

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;

	// create new buffer
	BYTE* newbuf = new BYTE[width*height];

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	long newpos = 0;
	for (int row = 0; row < height; row++)
		for (int column = 0; column < width; column++) {
			newpos = row * width + column;
			bufpos = (height - row - 1) * psw + column * 3;
			newbuf[newpos] = BYTE(0.11*Buffer[bufpos + 2] + 0.59*Buffer[bufpos + 1] + 0.3*Buffer[bufpos]);
		}

	for (int row = 0; row < height; row++) {
		for (int column = 0; column < width; column++) {
			if ((pow((column - width / 2 - centerx), 2)/pow(xrad,2)) + (pow((height / 2 - row - centery), 2)/pow(yrad,2)) <= 1.05f && (pow((column - width / 2 - centerx), 2) / pow(xrad, 2)) + (pow((height / 2 - row - centery), 2) / pow(yrad, 2)) >= 0.95f) {
				newpos = row * width + column;
				newbuf[newpos] = BYTE(0);
			}
		}
	}

	return newbuf;
}
