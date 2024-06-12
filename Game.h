#pragma once
// #include<Windows.h>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "I mino.h"
#include "J mino.h"
#include "L mino.h"
#include "O mino.h"
#include "S minoh.h"
#include "T mino.h"
#include "Z mino.h"
#include "well.h"

using namespace std;
class Game {
private:
    sf::RenderWindow* window;
    Well well;
    sf::Clock clock;
    sf::Time elapsed;
    float dropDownTime;
    Tetrimino* tetrimino;
    int randnum;
    int grid[20][10];
    int score;
    int lines;
    int screen;
    int level;
    string playerName;
    string highScoreNames[5];
    int highScores[5];
    sf::Texture imgtxt;
    sf::Sprite img;

    sf::Texture cattoTexture[12];
    sf::Sprite cattoSprite[12];
public:
    Game() {
        window = new sf::RenderWindow(sf::VideoMode(1000, 861), "Tetris");
        well = Well(window);
        clock.restart();
        elapsed = clock.restart();
        dropDownTime = 1.0;
        score = 0;
        lines = 0;
        screen = 0;
        imgtxt.loadFromFile("tetris title.jpeg");
        img = sf::Sprite(imgtxt);
        img.setPosition(220, 70);
        img.setScale(1.5, 1.5);

        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 10; j++)
                grid[i][j] = 0;

        for (int i = 0; i < 10; i++) {
            string name = "frame_0" + to_string(i) + ".png";
            cattoTexture[i].loadFromFile(name);
            cattoSprite[i] = sf::Sprite(cattoTexture[i]);
            cattoSprite[i].setPosition(250, 450);
        }
        cattoTexture[10].loadFromFile("frame_10.png");
        cattoSprite[10] = sf::Sprite(cattoTexture[10]);
        cattoSprite[10].setPosition(250, 450);

        cattoTexture[11].loadFromFile("frame_11.png");
        cattoSprite[11] = sf::Sprite(cattoTexture[11]);
        cattoSprite[11].setPosition(250, 450);


        loadHighScores();
    }

    void dropNewMino() {
        randnum = rand() % 7;

        switch (randnum) {
        case 0:
            tetrimino = new Z(grid, window);
            break;
        case 1:
            tetrimino = new I(grid, window);
            break;
        case 2:
            tetrimino = new J(grid, window);
            break;
        case 3:
            tetrimino = new O(grid, window);
            break;
        case 4:
            tetrimino = new S(grid, window);
            break;
        case 5:
            tetrimino = new T(grid, window);
            break;
        case 6:
            tetrimino = new L(grid, window);
            break;
        }
    }


    // line clearing
    bool isLineComplete(int row) {
        for (int j = 0; j < 10; j++) {
            if (grid[row][j] == 0)
                return false;
        }

        return true;
    }

    void loadHighScores() {
        ifstream file;
        file.open("highscores.txt");

        if (file.is_open()) {
            for (int i = 0; i < 5; i++) {
                file >> highScoreNames[i];
                file >> highScores[i];
            }
        }
    }

    void saveHighScores() {
        ofstream file;
        file.open("highscores.txt");

        if (file.is_open()) {
            for (int i = 0; i < 5; i++) {
                file << highScoreNames[i] << endl
                    << highScores[i] << endl;
            }
        }
    }

    void clearLine(int row) {
        for (int j = 0; j < 10; j++) {
            grid[row][j] = 0;
        }

        for (int i = row - 1; i >= 0; i--) {
            for (int j = 0; j < 10; j++) {
                grid[i + 1][j] = grid[i][j];
                grid[i][j] = 0;
            }
        }
    }
    void clear() {
        for (int i = 20 - 1; i >= 0; i--) {
            if (isLineComplete(i)) {
                cout << "Line " << i << " is complete " << endl;
                clearLine(i);
                score += 100;
                lines++;
                if (lines %10==0 && level < 8 && lines !=0)
                {
                    level++;
                    dropDownTime -= 0.1;
                }
                if (level == 8)
                {
                    level = 1;
                    dropDownTime = 1.0;
                }

                cout << "score = " << score;
                cout << "lines = " << lines;

            }
        }
    }
    // reset game
    void gameReset() {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 10; j++) {
                grid[i][j] = 0;
            }
        }
        score = 0;
        lines = 0;
        level = 0;
    }

    void colorCell(int i, int j, int c) {
        sf::Color colour;
        int cell_size = 43;

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
    void renderGame() {
        sf::RectangleShape bg = sf::RectangleShape(sf::Vector2f(1000, 861));
        bg.setFillColor(sf::Color(0x1E0A3DFF));
        tetrimino = new I(grid, window);
        // setting text

        sf::Font font;
        sf::Text text;
        sf::Text linestext;
        sf::Text name;
        sf::Text scoretext;
        sf::Text no_lines;
        sf::Text inputname;
        sf::Text levels;
        sf::Text levelNo;

        font.loadFromFile("sigmar.ttf");
        text.setFont(font);
        text.setString("SCORE : ");
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(50);
        text.setPosition(460, 350);

        linestext.setFont(font);
        linestext.setString("LINES : ");
        linestext.setFillColor(sf::Color::White);
        linestext.setCharacterSize(50);
        linestext.setPosition(460, 500);

        name.setFont(font);
        name.setString("NAME : ");
        name.setFillColor(sf::Color::White);
        name.setCharacterSize(50);
        name.setPosition(460, 200);

        levels.setFont(font);
        levels.setString("LEVELS : ");
        levels.setFillColor(sf::Color::White);
        levels.setCharacterSize(50);
        levels.setPosition(460, 650);

        scoretext.setFont(font);

        scoretext.setFillColor(sf::Color::White);
        scoretext.setCharacterSize(50);
        scoretext.setPosition(700, 350);

        no_lines.setFont(font);
        no_lines.setFillColor(sf::Color::White);
        no_lines.setCharacterSize(50);
        no_lines.setPosition(700, 500);

        levelNo.setFont(font);
        levelNo.setFillColor(sf::Color::White);
        levelNo.setCharacterSize(50);
        levelNo.setPosition(720, 650);

        inputname.setFont(font);
        inputname.setFillColor(sf::Color::White);
        inputname.setCharacterSize(50);
        inputname.setPosition(700, 200);

        string inputstring;
        bool istyping = true;

        sf::Clock cattoClock;
        int catto = 0;

        

        sf::Event event;
        while (window->isOpen()) {
            elapsed += clock.restart();
            while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window->close();
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Left) {
                        tetrimino->move_left(grid);
                    }
                    if (event.key.code == sf::Keyboard::Down) {
                        if (!tetrimino->move_down(grid)) {
                            clear();
                            dropNewMino();
                        }

                    }
                    if (event.key.code == sf::Keyboard::Right) {
                        tetrimino->move_right(grid);
                    }
                    if (event.key.code == sf::Keyboard::Up) {
                        tetrimino->rotate(grid);
                    }

                    if (event.key.code == sf::Keyboard::Enter) {
                        screen++;
                    }
                }
                if (event.type == sf::Event::TextEntered && istyping) {
                    if (event.text.unicode < 128) {
                        inputname.setString(inputstring);
                        // Append the input character to the string
                        inputstring += static_cast<char>(event.text.unicode);
                        playerName = inputstring;
                    }
                }
            }

            if (screen == 0) {
                // Catto

                window->clear();
                window->draw(bg);
                window->draw(img);
                if (cattoClock.getElapsedTime().asSeconds() >= 0.05) {
                    catto++;
                    cattoClock.restart();

                }
                sf::Text text10;
                text10.setFont(font);
                text10.setString("Press Enter To Play ");
                text10.setFillColor(sf::Color::White);
                text10.setCharacterSize(50);
                text10.setPosition(240, 700);

                catto %= 12;
                window->draw(cattoSprite[catto]);
                window->draw(text10);
                window->display();
            }

            else if (screen == 1) {
                // incrementing the score and lines variable
                scoretext.setString(to_string(score));
                no_lines.setString(to_string(lines));
                levelNo.setString(to_string(level));

                if (elapsed.asSeconds() >= 1.0) {
                    if (tetrimino->move_down(grid) == true) {
                        // Check if line is complete

                        // Do nothing
                    }
                    else {
                        dropNewMino();
                    }
                    clear();

                    elapsed = sf::Time::Zero;
                }
                window->clear();
                window->draw(bg);
                window->draw(text);
                window->draw(linestext);
                window->draw(name);
                window->draw(scoretext);
                window->draw(no_lines);
                window->draw(inputname);
                window->draw(levels);
                window->draw(levelNo);
                well.Draw();

                for (int i = 0; i < 20; i++) {
                    for (int j = 0; j < 10; j++) {
                        if (grid[i][j] != 0) {
                            colorCell(j, i, grid[i][j]);
                        }
                    }
                }
                tetrimino->draw();
                window->display();
                for (int j = 0; j < 10; j++) {
                    if (grid[0][j] != 0) {
                       
                        // Check if high score is achieved
                        // Save high score
                        for (int i = 0; i < 5; i++) {
                            if (score > highScores[i]) {
                                for (int j = 4; j > i; j--) {
                                    highScores[j] = highScores[j - 1];
                                    highScoreNames[j] = highScoreNames[j - 1];
                                }
                                highScores[i] = score;
                                highScoreNames[i] = playerName;
                                saveHighScores();
                                break;
                            }
                        }

                        gameReset();
                        break;
                    }
                }
            } else if (screen == 2) {
                sf::Text highscoreTitle;
                sf::Text highscore[5];
                window->clear();
                window->draw(bg);

                highscoreTitle.setFont(font);
                highscoreTitle.setString(" HIGHSCORES ");
                highscoreTitle.setFillColor(sf::Color::White);
                highscoreTitle.setCharacterSize(50);
                highscoreTitle.setPosition(300, 100);
                window->draw(highscoreTitle);

                for (int i = 0; i < 5; i++)
                {
                    highscore[i].setString(highScoreNames[i] + " : " + to_string(highScores[i]));
                    highscore[i].setFont(font);
                    highscore[i].setPosition(300, 200 + i * 100);
                    highscore[i].setFillColor(sf::Color::White);
                    highscore[i].setCharacterSize(50);

                    window->draw(highscore[i]);
                }
                
                window->display();
            }
            
        }
    }

    ~Game() {
        delete[] window;
    }
};