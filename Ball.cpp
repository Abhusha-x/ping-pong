//
//  Ball.cpp
//  Lab 2 Pong Game
//
//  Created by Abhusha Ghimire, 2024-09-23
#include "Ball.h"

#include <cmath>
#include <iostream>
using namespace std;

Ball::Ball() {}

Ball::Ball(double a, double b, double c, double d, int e) {
  x = a;
  y = b;
  velocity_x = c;
  velocity_y = d;
  id = e;
  height = 1;
  width = 1;
}

void Ball::update() {
  velocity_y = velocity_y - 0.02 * timeStep;
  y = y + velocity_y * timeStep;
  x = x + velocity_x * timeStep;
}

void Ball::draw(Screen& screen_to_draw_to) {
  screen_to_draw_to.addPixel(x, y, 'o');
}

void Ball::bounce(Ball arr[], int ballCount, Player player) {
  for (int i = 0; i < ballCount; i++) {
    if (arr[i].getID() != id) {
      int overlap_ball = overlap(arr[i]);
      if (overlap_ball == HORIZONTAL_OVERLAP) {
        arr[i].velocity_x = -arr[i].velocity_x;
        velocity_x = -velocity_x;
      }
      if (overlap_ball == VERTICAL_OVERLAP) {
        arr[i].velocity_y = -arr[i].velocity_y;
        velocity_y = -velocity_y;
      }
    }
  }
  int p_overlap = overlap(player);
  if (p_overlap == HORIZONTAL_OVERLAP) {
    velocity_x = -velocity_x;
  }

  if (x >= WIDTH - 1) {
    velocity_x = -velocity_x;
  }
  if (y <= 0 || y > HEIGHT) {
    velocity_y = -velocity_y;
  }
}

int Ball::getID() { return (id); }

double Ball::getX() { return (x); }

int Ball::overlap(Ball& b) {
  double b_x = b.x;
  double b_y = b.y;
  double b_height = b.height;
  double b_width = b.width;
  double h_overlap = -1;
  double v_overlap = -1;

  if (b_x >= x) {
    h_overlap = (x + width) - b_x;
  } else {
    h_overlap = (b_x + b_width) - x;
  }
  if (b_y >= y) {
    v_overlap = (y + height) - b_y;
  } else {
    v_overlap = (b_y + b_height) - y;
  }
  if (h_overlap > 0 && v_overlap > 0) {
    if (h_overlap >= v_overlap) {
      return (HORIZONTAL_OVERLAP);
    } else {
      return (VERTICAL_OVERLAP);
    }
  } else {
    return (NO_OVERLAP);
  }
}

int Ball::overlap(Player& p) {
  double p_x = p.getX();
  double p_y = p.getY();
  int p_height = p.getHeight();
  double p_width = 1.1;
  double h_overlap = -1;
  double v_overlap = -1;

  if (p_x >= x) {
    h_overlap = (x + width) - p_x;
  } else {
    h_overlap = (p_x + p_width) - x;
  }
  if (p_y >= y) {
    v_overlap = (y + height) - p_y;
  } else {
    v_overlap = (p_y + p_height) - y;
  }
  if (h_overlap > 0 && v_overlap > 0) {
    return (HORIZONTAL_OVERLAP);
  } else {
    return (NO_OVERLAP);
  }
}
