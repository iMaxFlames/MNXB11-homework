#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>
// Everything in one file to make things easier to browse with the debugger,
// don't get into the habit of writing code this way!
class Shape
{
public:
    virtual double area() const = 0;
    // A new member function that can be used to identify what kind of shape it
    // is.
    virtual std::string type() const = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(const double width, const double height)
        : _width{width}, _height{height}
    {
        if (_width < 0 || _height < 0)
        {
            throw std::runtime_error("Negative sides aren't allowed for a rectangle");
        }
    }
    double area() const override { return _width * _height; }
    std::string type() const override { return "Rectangle"; }

private:
    double _width;
    double _height;
};

class Circle : public Shape
{
public:
    explicit Circle(const double radius) : _radius{radius} {}
    double area() const override { return M_PI * _radius * _radius; }
    std::string type() const override { return "Circle"; }

private:
    double _radius;
};

class ColorRectangle : public Rectangle
{
public:
    ColorRectangle(const double width, const double height, std::string color)
        : Rectangle{width, height}, _color{color} {}

    std::string type() const override { return "Rectangle with color " + _color; }

private:
    std::string _color;
};

double area_summed(std::vector<const Shape *> shapes)
{
    double result{0};
    for (auto shape : shapes)
    {
        result += shape->area();
    }
    return result;
}

int main()
{

    int x{3};
    // Reference to 'x', type is reference to int
    // Initialize with the 'x' object
    // 'x_ref' can change 'x'
    // 'x_ref' cannot be changed to refer to another object
    int &x_ref{x};

    // Reference to 'x' as if it was constant, type is reference to const int
    // Initialize with the 'x' object
    // 'x_const_ref' can't change 'x'
    // 'x_const_ref' can't be changed to refer to another object
    const int &x_const_ref{x};

    // Pointer to the location of the 'x' object
    // Initialized by the address of the 'x' object given by '&x'
    // 'x_ptr' can change 'x'
    // 'x_ptr' can be changed to point to the location of another object
    int *x_ptr{&x};

    // Pointer to the location of the 'x' object as if it was const
    // Type is pointer to const int
    // Initialize by the address of the 'x' object given by '&x'
    // 'x_const_ptr' cannot change 'x'
    // 'x_const_ptr can be changed to point to the location of another object
    const int *x_const_ptr{&x};

    // Constant pointer to the location of the 'x' object
    // Initialized by the address of the 'x' object given by '&x'
    // 'const_x_ptr' can change 'x'
    // 'const_x_ptr' can't be changed to point to the location of another object
    int *const const_x_ptr{&x};

    // Change 'x'
    x_ref = 4;

    // Error, 'x_const_ref' is a reference to const, can't change the object
    // x_const_ref = 5;

    // Change 'x', need to dereference
    *x_ptr = 6;
    // Error 'x_const_ptr' is a pointer to const, can't change the object
    // *x_const_ptr = 7;

    // Change 'x', need to dereference
    // The pointer is const, not what it points to
    *const_x_ptr = 8;

    int y{4};

    // Error: x_ref is a reference, can't be changed
    // x_ref = y;

    // Error x_const_ref is a reference, can't be changed
    // x_const_ref = y;

    // Change 'x_ptr' to point to the location of the 'y' object
    x_ptr = &y;

    // Change 'x_const_ptr' to point to the location of the 'y' object
    x_const_ptr = &y;

    // Error 'x_const_ptr' is a const pointer, can't change what it points to
    // const_x_ptr = &y;

    // Pointer to nothing, has to be changed before you can dereference it
    int *pointer_to_nothing{nullptr};
    // *pointer_to_nothing or pointer_to_nothing-> would be a bug!

    const Circle unit_circle{1};
    const Rectangle rectangle{3, 4};
    const ColorRectangle colored_rectangle{12, 24, "Green"};

    const Shape &reference_to_circle{unit_circle};
    const Shape &reference_to_rectangle{rectangle};
    const Shape &reference_to_colored_rectangle{colored_rectangle};
    // Can't change what these refer to, but can call member functions directly.
    // Try using the step-into feature to see that you end up in the right place!

    std::cout << "The first reference is a " << reference_to_circle.type()
              << std::endl;
    std::cout << "The second reference is a " << reference_to_rectangle.type()
              << std::endl;
    std::cout << "The third reference is a "
              << reference_to_colored_rectangle.type() << std::endl;

    // Using pointers for indirection will do the same thing, but now we can
    // change what we are pointing to.

    // Note that const here means that the object pointer to is treated as const,
    // not that the pointer itself is const!
    const Shape *shape_pointer{&unit_circle};
    // We are more than welcome to print the value of the pointer, it is just an
    // address somewhere. It will be different every time you run the program.
    std::cout << "The pointer " << shape_pointer << " currently points to a "
              << shape_pointer->type() << std::endl;
    // Change what the pointer is pointing to by assigning a new value
    shape_pointer = &rectangle;
    std::cout << "The pointer " << shape_pointer << " currently points to a "
              << shape_pointer->type() << std::endl;
    // It also works for types that aren't the direct descendents of the Shape
    // base class
    shape_pointer = &colored_rectangle;

    std::cout << "The pointer " << shape_pointer << " currently points to a "
              << shape_pointer->type() << std::endl;

    // A typical use-case for needing pointers rather than references is when you
    // want to have a container where you want to work with the elements in a
    // polymorphic manner. Since a vector is a container of objects, we can't put
    // references into it (references don't have a region of memory in the
    // language, so there's nothing to store)
    // std::vector<Shape&> vector_of_ref; // Not allowed
    const Rectangle another_rectangle{17, 33};
    const Circle another_circle{3};
    std::vector<const Shape *> vector_of_shapes{
        &unit_circle, &rectangle, &another_rectangle, &another_circle};
    for (auto shape : vector_of_shapes)
    {
        std::cout << "The pointer " << shape << " currently points to a "
                  << shape->type() << " which has area " << shape->area()
                  << std::endl;
    }

    double total_area{area_summed(vector_of_shapes)};
    std::cout << "Total area is " << total_area << std::endl;
    return 0;
}