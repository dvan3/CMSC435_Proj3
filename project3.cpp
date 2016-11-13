/* -*- c++ -*-
 * project3.cpp
 * CMSC 435/634, Spring 2012
 * Dave Van <dvan3@umbc.edu>
 *
 * Main driver class.
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include "turtle.h"

#define DISTANCE 10
#define RADIUS 2
#define INITIAL 90

using namespace std;

int main(int argc, char *argv[])
{
    float angle;
    int generation;
    ifstream myFile;
    string ruleset[256], line, start, curr, replace;
    stack<turtle> stack;
    turtle currentTurtle, revertTurtle, maxwell(vec(0, 0, 0), INITIAL);

    if(!strcmp(argv[1], "-g"))
    {
        generation = atoi(argv[2]);
        //cout << "Generation: " << generation << endl;
    }
    else if(!strcmp(argv[3], "-g"))
    {
        generation = atoi(argv[4]);
        //cout << "Generation: " << generation << endl;
    }
    else
    {
        generation = 3;
        //cout << "Generation: " << generation << endl;
    }

    if(!strcmp(argv[1], "-a"))
    {
        angle = atof(argv[2]);
        //cout << "Angle: " << angle << endl;
    }
    else if(!strcmp(argv[3], "-a"))
    {
        angle = atof(argv[4]);
        //cout << "Angle: " << angle << endl;
    }
    else
    {
        angle = 25.7;
        //cout << "Angle: " << angle << endl;
    }

    myFile.open("test.txt");

    getline(myFile, line);
    start += line[0];

    while(!myFile.eof())
    {
        getline(myFile, line);
        if(line.length() > 2)
        {
            ruleset[line[0]] = line.substr(2);
        }
    }

    myFile.close();

    curr = start;

    for(int i = 0; i < generation; i++)
    {
        for(unsigned int j = 0; j < curr.length(); j++)
        {
            if(ruleset[curr[j]].length() == 0)
            {
                replace += curr[j];
            }
            else
            {
                replace += ruleset[curr[j]];
            }
        }
        curr = replace;
        replace = "";
    }

    ofstream theFile("plant.txt");
    theFile << "b " << 0.078 << " " << 0.361 << " " << 0.753 << " " << endl;
    theFile << "v" << endl;
    theFile << "from " << 2.1 << " " << 1.3 << " " << 1.7 << endl;
    theFile << "at " << 0 << " " << 0 << " " << 0 << endl;
    theFile << "up " << 0 << " " << 0 << " " << 1 << endl;
    theFile << "angle " << 45 << endl;
    theFile << "hither " << 0.01 << endl;
    theFile << "resolution " << 512 << " " << 512 << endl;
    theFile << "f " << 1 << " " << 0.9 << " " << 0.7 << " " << 0.5 << " " << 3.0827
        << " " << 0 << " " << 1 << endl;

    theFile << "c " << 0 << " " << 0 << " " << 0 << " " << RADIUS << endl;

    for(unsigned int i = 0; i < curr.length(); i++)
    {
        char x = curr[i];
        switch(x)
        {
            case 'F':
                maxwell.forward(DISTANCE);
                theFile << "c " << maxwell.getPosition().x() << " " << maxwell.getPosition().y()
                << " " << maxwell.getPosition().z() << " " << RADIUS << endl;
                break;
            case 'X':
                break;
            case '+':
                maxwell.turnLeft(angle);
                break;
            case '-':
                maxwell.turnRight(angle);
                break;
            case '[':
                currentTurtle = maxwell;
                stack.push(currentTurtle);
                break;
            case ']':
                revertTurtle = stack.top();
                maxwell.setPosition(revertTurtle.getPosition());
                maxwell.setDirection(revertTurtle.getDirection());
                stack.pop();
                break;
        }
    }

    theFile.close();

    return 0;
}
