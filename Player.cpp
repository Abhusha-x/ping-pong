//
//  Player.cpp
//  Lab 2 Pong Game
//
//  Created by Abhusha Ghimire, 2024-09-23

#include "Player.h"

#include <iostream>
using namespace std;

Player::Player() {}

Player::Player(double a, double b, int c) {
  x = a;
  y = b;
  height = c;
}

double Player::getX() { return (x); }
double Player::getY() { return (y); }
int Player::getHeight() { return (height); }
int Player::getWidth() { return (width); }
void Player::update(char c) {
  if (c == 'A' && y + height < HEIGHT) {
    y = y + 2;
  } else if (c == 'B' && y > 0) {
    y = y - 2;
  }
}
void Player::draw(Screen& screen_to_draw_to) {
  for (int j = 0; j < height; j++) {
    screen_to_draw_to.addPixel(x, y + j, '#');
  }
}
void Player::decreaseHeight(int delta_to_decrease_by) {
  if (height > 3) {
    height = height - delta_to_decrease_by;
  }
}
