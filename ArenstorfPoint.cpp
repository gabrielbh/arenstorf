#include "ArenstorfPoint.h"

/**
 * constructor.
 */
ArenstorfPoint::ArenstorfPoint(long double x, long double y, long double vx, long double vy)
{
    _x = x;
    _y = y;
    _vx = vx;
    _vy = vy;

}


/**
 * x getter.
 * @return x
 */
long double ArenstorfPoint::getX() const
{
    return _x;
}


/**
 * y getter.
 * @return y
 */
long double ArenstorfPoint::getY() const
{
    return _y;
}


/**
 * vx getter.
 * @return vx
 */
long double ArenstorfPoint::getVX() const
{
    return _vx;
}


/**
 * vy getter.
 * @return vy
 */
long double ArenstorfPoint::getVY() const
{
    return _vy;
}


/**
 * Writes to the os a string representation of the point in the format x, y, vx, vy
 */
ostream &operator<<(ostream &os, const ArenstorfPoint &a)
{
    string x = to_string(a.getX());
    string y = to_string(a.getY());
    string vx = to_string(a.getVX());
    string vy = to_string(a.getVY());
    return os << x << ", " << y << ", " << vx << ", " << vy;
}
