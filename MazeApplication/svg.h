
#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

	/* Initialize the SVG file after opening */
	void svg_header(ofstream * f, unsigned int width, unsigned int height);

	/* Finalize the SVG file before closing */
	void svg_footer(ofstream * f);

	/* Change the current color (default: red) */
	void set_svg_color(char *color);

	/* Draw a line using current color between two points */
	void svg_line(ofstream * f, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);


	/* Draw a rectangle */
	void svg_rect(ofstream * f, unsigned int x1, unsigned int y1, unsigned int width, unsigned int heigth);




