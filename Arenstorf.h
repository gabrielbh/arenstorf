
#ifndef EX1_ARENSTORF_H
#define EX1_ARENSTORF_H

#include <ostream>
#include "ArenstorfPoint.h"

using namespace std;

/**
 * class that computes trajectory points.
 */
class Arenstorf
{
public:

    /**
 * Will compute the trajectory points and write it to the output stream.
 * @param init class ArenstorfPoint connector.
 * @param n calculations steps.
 * @param m printing steps.
 * @param dt change in time.
 * @param out write to this output stream.
 * @return 0 on success, -1 for failure.
 */
    static int computeArenstorf(const ArenstorfPoint &init, unsigned int n,
                                unsigned int m, long double dt, std::ostream &out);


/**
* x Position after d time.
* @param dt change in time.
* @return x Position after d time.
*/
static long double xPosition(long double x, long double dt, long double vx);

 /**
 * y Position after d time.
 * @param dt change in time.
 * @return y Position after d time.
 */
static long double yPosition(long double y, long double dt, long double vy);

    /**
 * x Velocity after d time.
 * @param dt change in time.
 * @return x Velocity after d time.
 */
static long double xVelocity(long double x, long double vx, long double vy, long double d1, long double d2, long double dt);

    /**
 * y Velocity after d time.
 * @param dt change in time.
 * @return y Velocity after d time.
 */
static long double yVelocity(long double y, long double vx, long double vy, long double d1, long double d2, long double dt);

    /**
 * D1 getter
 */
static long double getD1(long double x, long double y);

    /**
 * D2 getter
 */
static long double getD2(long double x, long double y);

    /**
 * get x acceleration.
 * @return x acceleration.
 */
static long double getAccX(long double x, long double vy, long double d1, long double d2);

    /**
 * get y acceleration.
 * @return y acceleration.
 */
static long double getAccY(long double y, long double vx, long double d1, long double d2);


private:

};


#endif //EX1_ARENSTORF_H
