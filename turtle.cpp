#include "turtle.h"
#include "vec.h"
#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI 3.14
#define HALFCIRC 180

using namespace std;

turtle::turtle()
{

}

turtle::turtle(vec position, double direction)
{
   mPosition = position;
   mDirection = direction;
}

vec turtle::getPosition()
{
   return mPosition;
}

double turtle::getDirection()
{
   return mDirection;
}

void turtle::setPosition(vec position)
{
    mPosition = position;
}

void turtle::setDirection(double direction)
{
    mDirection = direction;
}

void turtle::forward(int distance)
{
   double currentX, currentY, currentZ, dx, dy, newX, newY;
   vec newPoint;

   currentX = mPosition.x();
   currentY = mPosition.y();
   currentZ = mPosition.z();

   dx = distance * cos(mDirection * (PI / HALFCIRC));
   dy = distance * sin(mDirection * (PI / HALFCIRC));

   newX = currentX + dx;
   newY = currentY + dy;

   newPoint = vec(newX, newY, currentZ);

   mPosition = newPoint;
}

void turtle::turnRight(double direction)
{
   mDirection -= direction;
}

void turtle::turnLeft(double direction)
{
   mDirection += direction;
}

/*
int main(int argc, char *argv[])
{
    turtle maxwell = turtle(vec(0, 0, 0), 90);
    cout << maxwell.getPosition() << endl;

    maxwell.forward(10);
    cout << maxwell.getPosition() << endl;
    cout << maxwell.getDirection() << endl;

    maxwell.turnRight(25);
    cout << maxwell.getPosition() << endl;
    cout << maxwell.getDirection() << endl;

    maxwell.turnLeft(25);

    maxwell.forward(10);
    cout << maxwell.getPosition() << endl;
    cout << maxwell.getDirection() << endl;

    return 0;
}
*/

