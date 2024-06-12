#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

enum colour {
    Blue = 1,     //I
    Cyan = 2,     //J
    Yellow = 3,   //L
    Green = 4,    //O
    Magenta = 5,  //S
    Red = 6,      //T
    White = 7     //Z                                            
};

class Well {
private:
    sf::RenderWindow* window;
    int cell_size;
    int grid[20][10];
    int rows;
    int cols;
    int colour;

public:
    Well() {
        cell_size = 43;
        rows = 10;
        cols = 20;

        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 10; j++)
                grid[i][j] = 0;
    }
    Well(sf::RenderWindow* window) {
        this->window = window;
        cell_size = 43;
        rows = 10;
        cols = 20;

        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 10; j++)
                grid[i][j] = 0;
    }
    void Draw() {
        sf::RectangleShape cells(sf::Vector2f(cell_size - 1, cell_size - 1));
        cells.setFillColor(sf::Color::Black);

        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++)
            {
                cells.setPosition(cell_size * i, cell_size * j);
                window->draw(cells);
            }
        }
    }
  
};