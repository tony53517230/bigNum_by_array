#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "bigNum.h"

#define BASE 1000000000
#define BASE_LENGTH 9
using namespace std;
using std::string;


void bigNum::setNumArray()//宣告陣列並全部歸0
{
    this->numArray = new long long int[this->numLength];
    for (int i = 0; i < this->numLength; i++)
        this->numArray[i] = 0;
    return;
}

void bigNum::stringToBigNumFromFile(ifstream *file)//將數自從檔案取出，並轉成數組陣列儲存
{
    *file >> this->strNum;
    int i;
    if (this->strNum[0] == '-')//判斷正負
    {
        this->strNum.erase(0, 1);
        this->sign = false;
    }
    this->numLength = (this->strNum.length() % BASE_LENGTH == 0) ? this->strNum.length() / BASE_LENGTH : this->strNum.length() / BASE_LENGTH + 1;//設定陣列長度
    this->setNumArray();//設定陣列
    for (i = 0; this->strNum.length() >= BASE_LENGTH; i++)
    {
        this->numArray[i] = (long long int)stoi(this->strNum.substr(this->strNum.length() - BASE_LENGTH, BASE_LENGTH));//每BASE_LENGTH位一組抓入數組陣列中
        this->strNum.erase(this->strNum.length() - BASE_LENGTH, BASE_LENGTH);
    }
    numArray[i] = (this->strNum.length() > 0) ? (long long int)stoi(this->strNum) : 0LL;//若最後有剩餘字串則輸入數組陣列，否則補0
    return;
}

void bigNum::multiply(bigNum *num1, bigNum *num2)//令輸入兩數相乘，並將結果存於自身
{
    if (num1->sign ^ num2->sign)
        this->sign = false;
    for (int i = 0; i < num2->numLength; i++)
    {
        for (int j = 0; j < num1->numLength; j++)
        {
            this->numArray[i + j] += num2->numArray[i] * num1->numArray[j];
            this->numArray[i + j + 1] += this->numArray[i + j] / BASE;//carry
            this->numArray[i + j] %= BASE;//去除進位值
        }
    }
    return;
}

void bigNum::print(ofstream *file)//寫入檔案
{
    *file << endl;
    if (this->sign == false)
        *file << '-';
    (this->numArray[this->numLength - 1] == 0) ? *file << this->numArray[(this->numLength--) - 2] : *file << this->numArray[this->numLength - 1];
    for (int i = this->numLength - 2; i >= 0; i--)
        *file << setw(BASE_LENGTH) << setfill('0') << this->numArray[i];
    return;
}

void bigNum::print()//輸出至terminal
{
    cout << endl;
    if (this->sign == false)
        cout << '-';
    (this->numArray[this->numLength - 1] == 0) ? cout << this->numArray[(this->numLength--) - 2] : cout << this->numArray[this->numLength - 1];
    for (int i = this->numLength - 2; i >= 0; i--)
        cout << setw(BASE_LENGTH) << setfill('0') << this->numArray[i];
    return;
}