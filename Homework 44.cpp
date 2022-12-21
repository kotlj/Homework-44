
#include <iostream>

using namespace std;

class MyString
{
private:
    char* str;
    int length;

    static int numOfStr;
public:
    MyString()
    {
        length = 80;
        str = new char[length + 1];
        numOfStr++;
    }
    MyString(int _length)
    {
        length = _length;
        str = new char[length + 1];
        numOfStr++;
    }
    MyString(char* _str)
    {
        length = 1;
        for (int phase = 0; phase < 2; phase++)
        {
            for (int i = 0; _str[i] != '\0'; i++)
            {
                if (phase == 0)
                {
                    length++;
                }
                else
                {
                    str[i] = _str[i];
                }
            }
            if (phase == 0)
            {
                str = new char[length + 1];
            }
        }
        str[length - 1] = '\0';
        numOfStr++;
    }
    MyString(const char _str[])
    {
        length = 1;
        for (int phase = 0; phase < 2; phase++)
        {
            for (int i = 0; _str[i] != '\0'; i++)
            {
                if (phase == 0)
                {
                    length++;
                }
                else
                {
                    str[i] = _str[i];
                }
            }
            if (phase == 0)
            {
                str = new char[length + 1];
            }
        }
        str[length] = '\0';
        numOfStr++;
    }

    void inputStr()
    {
        gets_s(str, length);
    }

    void showStr()
    {
        cout << str << '\n';
    }

    void static showCount()
    {
        cout << numOfStr << '\n';
    }

    ~MyString()
    {
        delete[] str;
    }
};

int MyString::numOfStr = 0;


int main()
{
    MyString a(100);
    a.inputStr();
    a.showStr();
    MyString::showCount();
}