#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "bigNum.h"

#define BASE 1000000000
#define BASE_LENGTH 9
using namespace std;
using std::string;


void bigNum::setNumArray()//�ŧi�}�C�å����k0
{
    this->numArray = new long long int[this->numLength];
    for (int i = 0; i < this->numLength; i++)
        this->numArray[i] = 0;
    return;
}

void bigNum::stringToBigNumFromFile(ifstream *file)//�N�Ʀ۱q�ɮר��X�A���ন�Ʋհ}�C�x�s
{
    *file >> this->strNum;
    int i;
    if (this->strNum[0] == '-')//�P�_���t
    {
        this->strNum.erase(0, 1);
        this->sign = false;
    }
    this->numLength = (this->strNum.length() % BASE_LENGTH == 0) ? this->strNum.length() / BASE_LENGTH : this->strNum.length() / BASE_LENGTH + 1;//�]�w�}�C����
    this->setNumArray();//�]�w�}�C
    for (i = 0; this->strNum.length() >= BASE_LENGTH; i++)
    {
        this->numArray[i] = (long long int)stoi(this->strNum.substr(this->strNum.length() - BASE_LENGTH, BASE_LENGTH));//�CBASE_LENGTH��@�է�J�Ʋհ}�C��
        this->strNum.erase(this->strNum.length() - BASE_LENGTH, BASE_LENGTH);
    }
    numArray[i] = (this->strNum.length() > 0) ? (long long int)stoi(this->strNum) : 0LL;//�Y�̫ᦳ�Ѿl�r��h��J�Ʋհ}�C�A�_�h��0
    return;
}

void bigNum::multiply(bigNum *num1, bigNum *num2)//�O��J��Ƭۭ��A�ñN���G�s��ۨ�
{
    if (num1->sign ^ num2->sign)
        this->sign = false;
    for (int i = 0; i < num2->numLength; i++)
    {
        for (int j = 0; j < num1->numLength; j++)
        {
            this->numArray[i + j] += num2->numArray[i] * num1->numArray[j];
            this->numArray[i + j + 1] += this->numArray[i + j] / BASE;//carry
            this->numArray[i + j] %= BASE;//�h���i���
        }
    }
    return;
}

void bigNum::print(ofstream *file)//�g�J�ɮ�
{
    *file << "408411071 �i���x"<< endl;
    if (this->sign == false)
        *file << '-';
    (this->numArray[this->numLength - 1] == 0) ? *file << this->numArray[(this->numLength--) - 2] : *file << this->numArray[this->numLength - 1];
    for (int i = this->numLength - 2; i >= 0; i--)
        *file << setw(BASE_LENGTH) << setfill('0') << this->numArray[i];
    return;
}

void bigNum::print()//��X��terminal
{
    cout << endl;
    if (this->sign == false)
        cout << '-';
    (this->numArray[this->numLength - 1] == 0) ? cout << this->numArray[(this->numLength--) - 2] : cout << this->numArray[this->numLength - 1];
    for (int i = this->numLength - 2; i >= 0; i--)
        cout << setw(BASE_LENGTH) << setfill('0') << this->numArray[i];
    return;
}