#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle {
private:
    float left, right, top, bottom;
public:
    Rectangle(float left, float right, float top, float bottom);
    // A CHANGER Pour l'instant j'ai mis les definitions ici aussi
    float Rectangle::get_left() const {return left;}
    float Rectangle::get_right() const {return right;}
    float Rectangle::get_top() const {return top;}
    float Rectangle::get_bottom() const {return bottom;}

    bool intersects(const Rectangle& other) const;


};

#endif