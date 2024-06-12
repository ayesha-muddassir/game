#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include"well.h"
#include "tetrimino.h"
using namespace std;
class O :public Tetrimino
{
public:
	O()
	{
		x = 4;
		y = 0;
	}
	O(int(*grid)[10], sf::RenderWindow* window) : Tetrimino(window)
	{
		x = 4;
		y = 0;
		colour = Green;
		this->grid = grid;
	}
	void draw()
	{
			colorCell(x, y, 4);
			colorCell(x + 1, y, 4);
			colorCell(x, y + 1, 4);
			colorCell(x + 1, y + 1, 4);
	}
	void move_left(int(*grid)[10])
	{
		if (x - 1 >= 0 && grid[y][x - 1] == 0 && grid[y + 1][x - 1] == 0)
		{
			x--;
		}
	}
	void move_right(int(*grid)[10])
	{
		if (x + 2 < 10 && grid[y][x + 2] == 0 && grid[y + 1][x + 2] == 0)
		{
			x++;
		}
	}
	bool move_down(int(*grid)[10])
	{
		if (y + 2 < 20 && grid[y + 2][x] == 0 && grid[y + 2][x + 1] == 0)
		{
			y += 1;
			return true;
		}
		else {
			grid[y][x] = 4;
			grid[y][x + 1] = 4;
			grid[y + 1][x] = 4;
			grid[y + 1][x + 1] = 4;
			return false;
		}

	}
	void rotate(int(*grid)[10])
	{
		// no rotation 
	}
};
