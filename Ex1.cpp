
#include "ArenstorfPoint.h"
#include "Arenstorf.h"
#include <fstream>
#include <iostream>

#define NUM_OF_PARAM 7
#define WITH_INPUT 3
#define NO_INPUT 2


const string WRONG_NUM_OF_PARAM = "ERROR: wrong number of parameters.\n";
const string WRONG_PARAM = "ERROR: wrong parameters were entered.\n";
const string FILE_ERROR = "Exception opening/reading/closing file\n";

using namespace std;

long double x;
long double y;
long double vx;
long double vy;
long double T;
unsigned int n;
unsigned int m;

/**
 * convert string to long double.
 * @param str to convert
 * @return str converted to long double
 */
long double convertToLDouble(string str)
{
    string::size_type sz;
    long double converted = std::stod(str, &sz);
    return converted;
}


/**
 * opens a file.
 * @param _aFile
 */
void openFile(char *_aFile)
{
    int i = 0;
    string param;
    ifstream aFile;
    aFile.open(_aFile);
    if (aFile.fail())
    {
        cerr << FILE_ERROR;
    }
    auto *parametersList = new long double[NUM_OF_PARAM];

    try
    {
        while (aFile >> param)
        {
            long double converted = convertToLDouble(param);
            parametersList[i] = converted;
            i++;
        }
        aFile.close();
        if (i != NUM_OF_PARAM)
        {
            cerr << WRONG_NUM_OF_PARAM;
        }
    }

    catch (ifstream::failure &f)
    {
        cerr << FILE_ERROR;
        exit(1);
    }

    if (cin.fail())
    {
        cerr << WRONG_PARAM;
        exit(1);
    }

    x = parametersList[0];
    y = parametersList[1];
    vx = parametersList[2];
    vy = parametersList[3];
    T = parametersList[4];
    n = parametersList[5];
    m = parametersList[6];
    delete (parametersList);
}

/**
 * Function we will call in case we got only output without input.
 */
void manualInput()
{
    cout << "Enter initial pos x:\n";
    cin >> x;

    cout << "Enter initial pos y:\n";
    cin >> y;

    cout << "Enter initial vel x:\n";
    cin >> vx;

    cout << "Enter initial vel y:\n";
    cin >> vy;

    cout << "Enter total time T:\n";
    cin >> T;

    cout << "Enter num of steps:\n";
    cin >> n;

    cout << "Enter num of steps to save:\n";
    cin >> m;

    if (cin.fail())
    {
        cerr << WRONG_PARAM;
        exit(1);
    }
}

/**
 * main function of the program.
 * @param argc
 * @param argv
 * @return 0 if the program run well, 1 otherwise.
 */
int main(int argc, char *argv[])
{
    string output;
    if (argc != NO_INPUT && argc != WITH_INPUT)
    {
        cerr << WRONG_NUM_OF_PARAM;
        exit(1);
    }
    else if (argc == NO_INPUT)
    {
        manualInput();
        output = argv[1];
    }
    else
    {
        openFile(argv[1]);
        output = argv[2];
    }
    ofstream out(output);
    const auto *initialPoint = new ArenstorfPoint(x, y, vx, vy);
    int compute = Arenstorf::computeArenstorf(*initialPoint, n, m, T, out);
    if (compute == -1)
    {
        cerr << WRONG_PARAM;
        exit(1);
    }
    delete (initialPoint);
    return 0;
}
