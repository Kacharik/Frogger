#include "Rectangle.hpp"

Rectangle::Rectangle(float left, float right, float top, float bottom) : left(left), right(right), top(top), bottom(bottom) {}
// Faut décider où mettre les définitions simples, ici ou dans hpp
float Rectangle::get_left() const {return left;}
float Rectangle::get_right() const {return right;}
float Rectangle::get_top() const {return top;}
float Rectangle::get_bottom() const {return bottom;}

bool Rectangle::intersects(const Rectangle& other) const{

}