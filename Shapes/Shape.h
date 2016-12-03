/*
    Base Shape class from which other shape classes can be derived, and
    Color enum and Point struct for descriptive shape object feautures.
    - Jesus Suarez, Oct. 26, 2015
*/

#pragma once
#include <Windows.h>
#include <FL/fl_draw.H>

/*
    Color enum is our simple interface to FLTK's color definitions, which
    use values of type Fl_Color.
*/

enum Color {
    red = FL_RED,
    blue = FL_BLUE,
    green = FL_GREEN,
    yellow = FL_YELLOW,
    white = FL_WHITE,
    black = FL_BLACK,
    magenta = FL_MAGENTA,
    cyan = FL_CYAN,
};

/*
    Point struct, which will allow us to specify the position of our shapes
    on the display.
*/

struct Point {
    int x, y;
    Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) { }
};

/*
    Our simple base Shape class, which allows us to define, position, and draw
    simple shapes on our display using FLTK
*/

class Shape : public Fl_Widget {
protected:
    // The shape constructor is not public because you can't define a generic shape object,
    // but you can define objects of derived classes (i.e. specific types of shapes). The
    // shape constructor is also not private, since it is called by the constructors of our
    // derived classes. So it is protected.
    Shape(Point p = Point(0,0), Color c = black) 
        : Fl_Widget(p.x, p.y, 0, 0), position(p), linecolor(c) {}
   
    Point position; // we define the position of a shape by its top-left corner
    Color linecolor;

public:
    void set_color(Color c) { linecolor = c; }
    Color get_color() const { return linecolor; }
    void set_position(Point p) { position = p; }
    Point get_position() const { return position; }

    virtual void draw() = 0;
    virtual void print_parameters() = 0;
};