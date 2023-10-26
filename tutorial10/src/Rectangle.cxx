#include "Rectangle.h"
namespace Geometry
{
    double Rectangle::area() const { return _width * _height; }

    Rectangle::Rectangle(double width, double height)
        : _width{width}, _height{height}
    {
        if (_width < 0 || _height < 0)
        {
            std::cout << "Are you sure that you want a Rectangle with negative sides?\n";
        }
    }
    Rectangle::Rectangle(double side_length)
        : _width{side_length}, _height{side_length} {}

    void Rectangle::print() const
    {
        double a{_width * _height};
        std::cout << "Width = " << _width << std::endl;
        std::cout << "Height = " << _height << std::endl;
        std::cout << "Area = " << a << std::endl;
    }

} // namespace Geometry
