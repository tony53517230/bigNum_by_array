#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "bigNum.h"

using namespace std;

int main()
{
    string input_file;
    cout << "Input file: ";
    cin >> input_file;
    string output_file;
    cout << "Output file: ";
    cin >> output_file;
    ifstream ifile(input_file, ios::in);
    bigNum num1, num2, result;
    num1.stringToBigNumFromFile(&ifile);
    num2.stringToBigNumFromFile(&ifile);
    ifile.close();
    ofstream ofile;
    ofile.open(output_file, ios::app);
    result.numLength = num1.numLength + num2.numLength;
    result.setNumArray();
    result.multiply(&num1, &num2);
    result.print(&ofile);
    return 0;
}