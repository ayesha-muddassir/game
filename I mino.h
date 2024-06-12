#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include"well.h"
#include "tetrimino.h"
using namespace std;
class I : public Tetrimino 
{
	int temp_x, temp_y, temp_angle;
public:
	int(*grid)[10];
	int angle;

	I() {
		x = 4;
		y = 0;
		angle = 0;
		temp_x = 0;
		temp_y = 0;
		temp_angle = 0;
	}
	I(int(*grid)[10], sf::RenderWindow* window) : Tetrimino(window) {
		x = 4;
		y = 0;
		colour = Blue;
		this->grid = grid;
	}
	void move_left(int(*grid)[10])
	{
		if (angle == 0)
		{
			if (x - 1 >= 0 && grid[y][x - 1] == 0 && grid[y + 1][x - 1] == 0 && grid[y + 2][x - 1] == 0 && grid[y + 3][x - 1] == 0)
			{
				x--;
			}
		}
		if (angle == 90)
		{
			if (x - 1 >= 0 && grid[y][x - 1] == 0)
				x--;
		}
		if (angle == 180)
		{
			if (x - 1 >= 0 && grid[y][x - 1] == 0 && grid[y + 1][x - 1] == 0 && grid[y + 2][x - 1] == 0 && grid[y + 3][x - 1] == 0)
			{
				x--;
			}
		}
		if (angle == 270)
		{
			if (x - 1 >= 0 && grid[y][x - 1] == 0)
				x--;
		}
	}
	void move_right(int(*grid)[10])
	{
		if (angle == 0)
		{
			if (x + 1 < 10 && grid[y][x + 1] == 0 && grid[y + 1][x + 1] == 0 && grid[y + 2][x + 1] == 0 && grid[y+3][x + 1] == 0)
			{
				x++;
			}
		}
		if (angle == 180)
		{
			if (x + 1 < 10 && grid[y][x + 1] == 0 && grid[y + 1][x + 1] == 0 && grid[y + 2][x + 1] == 0 && grid[x + 1] == 0)
			{
				x++;
			}
		}
		if (angle == 90 || angle==270)
		{
			if (x + 4 < 10 && grid[y][x + 4] == 0)
				x++;
		}
		
	}
	void draw()
	{
		if (angle == 0) {
			colorCell(x, y, 1);
			colorCell(x, y + 1, 1);
			colorCell(x, y + 2, 1);
			colorCell(x, y + 3, 1);
		}
		if (angle == 90)
		{
			colorCell(x, y, 1);
			colorCell(x + 1, y, 1);
			colorCell(x + 2, y, 1);
			colorCell(x + 3, y, 1);
		}
		if (angle == 270)
		{
			colorCell(x, y, 1);
			colorCell(x + 1, y, 1);
			colorCell(x + 2, y, 1);
			colorCell(x + 3, y, 1);
		}
		if (angle == 180) {
			colorCell(x, y, 1);
			colorCell(x, y + 1, 1);
			colorCell(x, y + 2, 1);
			colorCell(x, y + 3, 1);
		}
	}
	bool move_down(int(*grid)[10]) {

		if (angle==0) {
			if (y + 4 < 20 && grid[y + 4][x] == 0) {
				y += 1;
				return true;
			}
			else {
				grid[y][x] = 1;
				grid[y + 1][x] = 1;
				grid[y + 2][x] = 1;
				grid[y + 3][x] = 1;
				return false;
			}
		}
		if (angle == 90)
		{
			if (y + 1 < 20 && grid[y + 1][x] == 0 && grid[y + 1][x+1] == 0 && grid[y + 1][x+2] == 0 && grid[y + 1][x+3] == 0) {
				y += 1;
				return true;
			}
			else
			{
				grid[y][x] = 1;
				grid[y][x+1] = 1;
				grid[y][x+2] = 1;
				grid[y][x+3] = 1;
				return false;

			}
		}
		if (angle == 180) {
			if (y + 4 < 20 && grid[y + 4][x] == 0) {
				y += 1;
				return true;
			}
			else {
				grid[y][x] = 1;
				grid[y + 1][x] = 1;
				grid[y + 2][x] = 1;
				grid[y + 3][x] = 1;
				return false;
			}
		}
		if (angle == 270)
		{
			if (y + 1 < 20 && grid[y + 1][x] == 0 && grid[y + 1][x + 1] == 0 && grid[y + 1][x + 2] == 0 && grid[y + 1][x + 3] == 0) {
				y += 1;
				return true;
			}
			else
			{
				grid[y][x] = 1;
				grid[y][x + 1] = 1;
				grid[y][x + 2] = 1;
				grid[y][x + 3] = 1;
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
		
		if (x + 3 > 10 || x+4 >10)
			angle = temp_angle;
	}
};