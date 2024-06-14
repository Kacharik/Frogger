#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle {
public:
    Rectangle(int x, int y, int width, int height);
    
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    void setPosition(int x, int y);
    void setSize(int width, int height);

    bool intersects(const Rectangle& other) const;

    int getLeft() const;
    int getRight() const;
    int getTop() const;
    int getBottom() const;

private:
    int x, y, width, height;
};

#endif