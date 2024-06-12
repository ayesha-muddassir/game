#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include"well.h"
#include "tetrimino.h"
using namespace std;
class L :public Tetrimino
{
	int angle;
	int temp_x, temp_y, temp_angle;
public:
	L()
	{
		x = 4;
		y = 0;
		angle = 0;
	}
	L(int(*grid)[10], sf::RenderWindow* window) : Tetrimino(window)
	{
		x = 4;
		y = 0;
		colour = Yellow;
		this->grid = grid;
		temp_x = 0;
		temp_y = 0;
		temp_angle = 0;
	}
	void draw()
	{
		if (angle == 0)
		{
			colorCell(x, y, 3);
			colorCell(x, y + 1, 3);
			colorCell(x, y + 2, 3);
			colorCell(x + 1, y + 2, 3);
		}
		if (angle == 90)
		{
			colorCell(x, y, 3);
			colorCell(x+1, y, 3);
			colorCell(x+2, y, 3);
			colorCell(x, y + 1, 3);
		}
		if (angle == 180)
		{
			colorCell(x, y, 3);
			colorCell(x+1, y, 3);
			colorCell(x+1 ,y + 1, 3);
			colorCell(x + 1, y + 2, 3);
		}
		if (angle == 270)
		{
			colorCell(x, y, 3);
			colorCell(x, y + 1, 3);
			colorCell(x-1, y + 1, 3);
			colorCell(x-2, y+1 , 3);
		}
	}

	void move_left(int(*grid)[10])
	{
		if (angle == 0)
		{
			if (x - 1 >= 0 && grid[y][x - 1] == 0 && grid[y + 1][x - 1] == 0 && grid[y + 2][x - 1] == 0)
			{
				x--;
			}
		}
		if (angle == 90)
		{
			if (x - 1 >= 0 && grid[y][x - 1] == 0 && grid[y + 1][x - 1] == 0)
			{
				x--;
			}
		}
		if (angle == 180)
		{
			if (x - 1 >= 0 && grid[y][x - 1] == 0 && grid[y + 1][x] == 0 && grid[y + 2][x] == 0)
			{
				x--;
			}
		}
		if (angle == 270)
		{
			if (x - 3 >= 0 && grid[y][x - 1] == 0 && grid[y][x - 2] == 0 && grid[y][x - 3] == 0 && grid[y+1][x - 3] == 0)
			{
				x--;
			}
		}
	}
	void move_right(int(*grid)[10])
	{
		if (angle == 0)
		{
			if (x + 2 < 10 && grid[y + 2][x + 2] == 0)
			{
				x++;
			}
		}
		if (angle == 90)
		{
			if (x + 3 < 10 && grid[y][x + 3] == 0 && grid[y+1][x + 1] == 0 && grid[y][x + 2] == 0)
			{
				x++;
			}
		}
		if (angle == 180)
		{
			if (x + 2 < 10 && grid[y][x +1] == 0 && grid[y+1][x + 1] == 0 && grid[y+2][x + 1] == 0)
			{
				x++;
			}
		}
		if (angle == 270)
		{
			if (x + 1 < 10 && grid[y][x + 1] == 0 && grid[y+1][x + 1] == 0)
			{
				x++;
			}
		}
	}
	bool move_down(int(*grid)[10])
	{
		if (angle == 0)
		{
			if (y + 3 < 20 && grid[y + 3][x] == 0 && grid[y + 3][x + 1] == 0)
			{
				y += 1;
				return true;
			}
			else {
				grid[y][x] = 3;
				grid[y + 1][x] = 3;
				grid[y + 2][x] = 3;
				grid[y + 2][x + 1] = 3;
				return false;
			}
		}
		if (angle == 90)
		{
			if (y + 2 < 20 && grid[y + 2][x] == 0 && grid[y + 1][x + 1] == 0 && grid[y + 1][x +2] == 0)
			{
				y += 1;
				return true;
			}
			else {
				grid[y][x] = 3;
				grid[y][x+1] = 3;
				grid[y][x+2] = 3;
				grid[y + 1][x] = 3;
				return false;
			}
		}
		if (angle == 180)
		{
			if (y + 3 < 20 && grid[y + 3][x+1] == 0)
			{
				y += 1;
				return true;
			}
			else {
				grid[y][x] = 3;
				grid[y][x+1] = 3;
				grid[y + 1][x+1] = 3;
				grid[y + 2][x + 1] = 3;
				return false;
			}
		}
		if (angle == 270)
		{
			if (y + 2 < 20 && grid[y + 2][x] == 0 && grid[y + 2][x - 1] == 0 && grid[y + 2][x - 2] == 0)
			{
				y += 1;
				return true;
			}
			else {
				grid[y][x] = 3;
				grid[y + 1][x] = 3;
				grid[y + 1][x-1] = 3;
				grid[y + 1][x -2] = 3;
				return false;
			}
		}
	}

	void rotate(int(*grid)[10])
	{
		temp_x = x;
		temp_y = y;
		temp_angle = angle;

		if (angle >= 270)
		{
			angle = 0;
		}
		else {
			angle += 90;
		}

		if (x + 1 > 10 || x + 2 > 10 || x+3>10)
			angle = temp_angle;
	}
};
