
#ifndef EX1_ARENSTORFPOINT_H
#define EX1_ARENSTORFPOINT_H

#include <string>
#include <math.h>
#include <iostream>

using namespace std;

// moon mass / earth mass.
const long double ALPHA = 0.012299;

// BETA = 1 - ALPHA.
const long double BETA = 0.987701;


/**
 * class that represent an arenstorf point.
 */
class ArenstorfPoint
{
public:

/**
 * constructor.
 */
    ArenstorfPoint(long double x, long double y, long double vx, long double vy);

    /**
     * x getter
     * @return x position.
     */
    long double getX() const;

    /**
     * y getter
     * @return y position.
     */
    long double getY() const;

    /**
     * vx getter
     * @return x veloc.
     */
    long double getVX() const;

    /**
     * vx getter
     * @return x veloc.
     */
    long double getVY() const;

    /**
 * Writes to the os a string representation of the point in the format x, y, vx, vy
 */
    friend ostream &operator<<(ostream &os, const ArenstorfPoint &a);

private:
    long double _x, _vx;
    long double _y, _vy;
};


#endif //EX1_ARENSTORFPOINT_H
