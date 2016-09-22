#include "svg.h"
#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;


char *svg_color = "red";

void set_svg_color(char *color)
{
	svg_color = color;
}

void svg_header(ofstream * f, unsigned int width, unsigned int height)
{
	*f << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\" " << width << "\" height=\"" << height <<"\">"<<endl;
}

void svg_footer(ofstream * f) {
	*f<< "</svg>\n"<<endl;
}

void svg_line(ofstream * f, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
	if ((x1 == x2) && (y1 == y2)) return;
	*f << "<line x1=\"" << x1 *10 << "\" y1=\"" << y1 *10 << "\" x2=\"" << x2 *10 << "\" y2=\"" << y2 *10 << "\" style=\"stroke:rgb(150,100,75);stroke-width:0.2\"/>"<<endl;
		 
}



void svg_rect(ofstream * f, unsigned int x1, unsigned int y1, unsigned int width, unsigned int heigth)
{
	*f << "<rect x=\"" << x1 *10 << "\" y=\"" << y1 *10 << "\" width=\""<< width *10<< "\" height=\"" << heigth *10 << "\"  stroke=\"green\" stroke-width=\"1\" fill=\"none\" />" << endl;
}

