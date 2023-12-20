#include <iostream>
#include <set>

using namespace std;

class Circle
{
public:
    int radius;

    Circle(int r) : radius(r) {}
};

class Square
{
public:
    int side;

    Square(int s) : side(s) {}
};

class Shapes
{
public:
    set<int> circles_radius;
    set<int> squares_side;

    Shapes() {}

    Shapes operator+(const Circle &circle)
    {
        Shapes newShapes = *this;
        newShapes.circles_radius.insert(circle.radius);
        return newShapes;
    }

    Shapes operator+(const Square &square)
    {
        Shapes newShapes = *this;
        newShapes.squares_side.insert(square.side);
        return newShapes;
    }
};

int main()
{
    Circle circle1(5);
    Square square1(4);

    Shapes shapes;
    shapes = shapes + circle1;
    shapes = shapes + square1;

    cout << "Circles' Radii:";
    for (int radius : shapes.circles_radius)
    {
        cout << " " << radius;
    }
    cout << endl;

    cout << "Squares' Sides:";
    for (int side : shapes.squares_side)
    {
        cout << " " << side;
    }
    cout << endl;

    return 0;
}