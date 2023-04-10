// 071_ClassNew



#include <iostream>
class Test
{
    char* ArrChar;

public:
    void Resize(size_t Size)
    {
        ArrChar = new char[Size];
    }
};

int main()
{
    char* Arrint = new char();

    delete Arrint;

    // 이녀석을 만든다는것 자체가 
    // char의 배열을 만든것과 같다는것.
    Test* ArrTest = new Test[10];

    delete[] ArrTest;

    // Test ArrTest = Test();

}