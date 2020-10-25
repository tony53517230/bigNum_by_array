#include <iostream>
#include <string>

using namespace std;

class bigNum
{
public:
    string strNum = "";
    long long int *numArray;
    int numLength;
    bool sign = true;
    void setNumArray();//設定陣列長度與歸0
    void stringToBigNumFromFile(ifstream *file);//自檔案中取出數字存入陣列
    void multiply(bigNum *num1, bigNum *num2);//將兩輸入大數相乘並存結果於自身
    void print(ofstream *file);//輸出至檔案
    void print();//輸出至terminal
};