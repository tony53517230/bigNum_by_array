#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "bigNum.h"

using namespace std;
using std::string;

int main()
{
    ifstream ifile("num.txt", ios::in);
    bigNum num1, num2, result;
    num1.stringToBigNumFromFile(&ifile);
    num2.stringToBigNumFromFile(&ifile);
    ifile.close();
    ofstream ofile;
    ofile.open("num.txt", ios::app);
    result.numLength = num1.numLength + num2.numLength;
    result.setNumArray();
    result.multiply(&num1, &num2);
    result.print(&ofile);
    return 0;
}