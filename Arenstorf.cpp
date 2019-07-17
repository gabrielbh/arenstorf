//
// Created by gabriel on 20/12/2017.
//

#include "Arenstorf.h"

/**
 * Will compute the trajectory points and write it to the output stream.
 * @param init class ArenstorfPoint connector.
 * @param n calculations steps.
 * @param m printing steps.
 * @param dt change in time.
 * @param out write to this output stream.
 * @return 0 on success, -1 for failure.
 */
int Arenstorf::computeArenstorf(const ArenstorfPoint &init, unsigned int n,
                                unsigned int m, long double dt, ostream &out)
{
    if (dt < 0)
    {
        return -1;
    }

    out << scientific;
    out.precision(3);

    long double cycleTime = dt / n;
    long printingTime = n / m;
    long double curXPos = init.getX();
    long double curYPos = init.getY();
    long double curXVelocity = init.getVX();
    long double curYVelocity = init.getVY();

    for (unsigned int i = 0; i < n; ++i)
    {
        long double newD1 = getD1(curXPos, curYPos);
        long double newD2 = getD2(curXPos, curYPos);
        long double newXPos = xPosition(curXPos, cycleTime, curXVelocity);
        long double newYPos = yPosition(curYPos, cycleTime, curYVelocity);
        long double newXVelocity = xVelocity(curXPos, curXVelocity, curYVelocity, newD1, newD2, cycleTime);
        long double newYVelocity = yVelocity(curYPos, curXVelocity, curYVelocity, newD1, newD2, cycleTime);

        if (i % printingTime == 0 || i == 0)
        {
            out << newXPos << ", " << newYPos << ", ";
        }
        curXPos = newXPos;
        curYPos = newYPos;
        curXVelocity = newXVelocity;
        curYVelocity = newYVelocity;
    }
    return 0;
}


/**
 * x Position after d time.
 * @param dt change in time.
 * @return x Position after d time.
 */
long double Arenstorf::xPosition(long double x, long double dt, long double vx)
{
    long double xDt = x + vx * dt;
    return xDt;
}

/**
 * y Position after d time.
 * @param dt change in time.
 * @return y Position after d time.
 */
long double Arenstorf::yPosition(long double y, long double dt, long double vy)
{
    long double yDt = y + vy * dt;
    return yDt;
}

/**
 * x Velocity after d time.
 * @param dt change in time.
 * @return x Velocity after d time.
 */
long double Arenstorf::xVelocity(long double x, long double vx, long double vy,
                                 long double d1, long double d2, long double dt)
{
    long double xVDt = vx + getAccX(x, vy, d1, d2) * dt;
    return xVDt;
}

/**
 * y Velocity after d time.
 * @param dt change in time.
 * @return y Velocity after d time.
 */
long double Arenstorf::yVelocity(long double y, long double vx, long double vy,
                                 long double d1, long double d2, long double dt)
{
    long double yVDt = vy + getAccY(y, vx, d1, d2) * dt;
    return yVDt;
}


/**
 * D1 getter
 */
long double Arenstorf::getD1(long double x, long double y)
{
    long double D1 = powl((powl(x + ALPHA, 2) + powl(y, 2)), 1.5);
    return D1;
}


/**
 * D2 getter.
 */
long double Arenstorf::getD2(long double x, long double y)
{
    long double D2 = powl((powl(x - BETA, 2) + powl(y, 2)), 1.5);
    return D2;
}

/**
 * get x acceleration.
 * @return x acceleration.
 */
long double Arenstorf::getAccX(long double x, long double vy, long double d1, long double d2)
{
    long double AccX = x + 2 * vy - BETA * ((x + ALPHA) / d1) - ALPHA * ((x - BETA) / d2);
    return AccX;
}

/**
 * get y acceleration.
 * @return y acceleration.
 */
long double Arenstorf::getAccY(long double y, long double vx, long double d1, long double d2)
{
    long double AccY = y - 2 * vx - BETA * (y / d1) - ALPHA * (y / d2);
    return AccY;
}