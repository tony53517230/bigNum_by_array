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
    void setNumArray();//�]�w�}�C���׻P�k0
    void stringToBigNumFromFile(ifstream *file);//���ɮפ����X�Ʀr�s�J�}�C
    void multiply(bigNum *num1, bigNum *num2);//�N���J�j�Ƭۭ��æs���G��ۨ�
    void print(ofstream *file);//��X���ɮ�
    void print();//��X��terminal
};