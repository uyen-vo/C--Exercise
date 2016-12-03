#include <Windows.h>
#include <FL/Fl.h>
#include <FL/Fl_Window.h>
#include <vector>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

int main(int argc, char **argv) {
	Fl_Window *window = new Fl_Window(800, 600);
    
  //  Rect r1(400, 165, Point(50, 245), blue);
 //   Circle c1(200, Point(300, 180), red);
	Triangle t1(Point(100, 100), Point(20, 20), Point(120, 150), black);

    vector<Shape*> shapes;
  //  shapes.push_back(&r1);
  //  shapes.push_back(&c1);
    for (int i = 0; i < shapes.size(); i++)
        shapes[i]->print_parameters();

	window->end();
	window->show(argc, argv);
	return Fl::run();
}
