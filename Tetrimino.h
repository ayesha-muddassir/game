#pragma once
#include <SFML/Graphics.hpp>

class Tetrimino {
public:
    int cell_size;
    sf::RenderWindow* window;
    int colour;
    int x;
    int y;
    int(*grid)[10];
    virtual bool move_down(int(*grid)[10]) = 0;
    virtual void move_left(int(*grid)[10]) = 0;
    virtual void move_right(int(*grid)[10]) = 0;
    virtual void rotate(int(*grid)[10]) = 0;
    virtual void draw() = 0;
    Tetrimino() {
    }
    Tetrimino(sf::RenderWindow* window) {
        this->window = window;
        cell_size = 43;
       
    }
    Tetrimino(const Tetrimino &copy)
    {
        cell_size = copy.cell_size;
        window = copy.window;
        colour = copy.colour;
        x = copy.x;
        y = copy.y;
        grid = copy.grid;
    }
    Tetrimino &operator =(const Tetrimino& copy)
    {
        if (this == &copy)
            return *this;
        cell_size = copy.cell_size;
        window = copy.window;
        colour = copy.colour;
        x = copy.x;
        y = copy.y;
        grid = copy.grid;
    }
    void colorCell(int i, int j, int c) {
        sf::Color colour;

        if (c == 1)
            colour = sf::Color::Blue;
        else if (c == 2)
            colour = sf::Color::Cyan;
        else if (c == 3)
            colour = sf::Color::Yellow;
        else if (c == 4)
            colour = sf::Color::Green;
        else if (c == 5)
            colour = sf::Color::Magenta;
        else if (c == 6)
            colour = sf::Color::Red;
        else if (c == 7)
            colour = sf::Color::White;

        sf::RectangleShape cell(sf::Vector2f(cell_size, cell_size));
        cell.setFillColor(colour);
        cell.setPosition(cell_size * i, cell_size * j);
        window->draw(cell);
    }
};