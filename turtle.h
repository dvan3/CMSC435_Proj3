
/* -*- c++ -*-
 * turtle.h
 * CMSC 435/634, Spring 2012
 * Dave Van <dvan3@umbc.edu>
 *
 * Turtle header class.
 */
#ifndef TURTLE_H
#define TURTLE_H

#include "vec.h"

class turtle
{
  public:
   turtle();

   turtle(vec position, double direction);

   vec getPosition();
   double getDirection();
   void setPosition(vec position);
   void setDirection(double direction);
   void forward(int distance);
   void turnRight(double direction);
   void turnLeft(double direction);

  private:
   vec mPosition;
   double mDirection;
};

#endif // TURTLE_H


