// 060_FunctionPointer


#include <iostream>
// 함수도 프로세스로 메모리에 올라갈 것이기 때문에
// 위치가 있을수밖에 없다.
// 이 위치는 정해져 있다.
void Test()
{
}

void PlayerAttack()
{
    printf_s("플레어이가 공격합니다.\n");
}

void PlayerMove()
{
    printf_s("플레어이가 이동합니다.\n");
}

// 문법적으로 가장 어려워하는 부분임
// 행동을 변수로 만드는 것입니다.

class UIButton
{
public:

    void (*Ptr)() = nullptr;
    void Click()
    {
        if (nullptr == Ptr)
        {
            return;
        }
        Ptr();
    }
};


// 개인적인 테스트 
void Test1()
{
    printf_s("Test\n");
}

int Test2(int _Value1, int _Value2)
{
    return _Value1 + _Value2;
}

int Test3()
{
    return 10;
}

int Test4(int _Value1)
{
    return _Value1;
}

int main()
{
    {
        // void(*)(); 형 << function pointer
        void(*Ptr)();

        // void PlayerAttack();
        // 둘의 자료형은 완전히 동일하다
        // void(*)() == void PlayerAttack();
        // int == 10; << 아래와 동일 10의 자료형은 int

        // 모든 자료형은 배열로 사용할 수 있다.
        // int[] => int Arr << 자료형에 이름이 붙어있어야 사용할 수 있다
        // void(*[])() => void(*Arr[10]()

        // Ptr << 특정한 함수의 이름을 넣어줌으로 이 변수가 그 함수를 호출할 수 있게 된다
        
        // int Arr[10] = int* Ptr = Arr
        // int* Arr[10] = int** Ptr = Arr << 별을 하나 더 붙여주면 된다 (암시적 형변환) / 안되면 강제로 형변환 해줘야함
        {
            int* Arr[10];
            int** Ptr = Arr;
        }
        // void(*[])() => void(*Arr[10]() 을 똑같이 적용해보면
        {
            // *을 하나 더 붙여주면 된다. (주소값은 모두 8바이트)
            // 함수의 변수(Function Pointer)도 결국 8바이트 주소값이 될 수 있다.
            void(*Arr[10])();
            void(**ArrPtr)() = Arr;
        }
    }
    // 리턴값 (* 함수포인터명)(인자)
    {
        void(*Ptr1)() = PlayerAttack;
        void(*Ptr2)() = PlayerMove;

        Ptr1();
        Ptr2();
    }

    {
        UIButton PlayerAttackButton;
        UIButton PlayerMoveButton;

        PlayerAttackButton.Ptr = PlayerAttack;
        PlayerMoveButton.Ptr = PlayerMove;

        PlayerMoveButton.Click();
        PlayerMoveButton.Click();
    }

    {
        void(*ArrFunction[20])();

        void(**Ptr)() = ArrFunction;

        ArrFunction[0] = PlayerAttack;

        Ptr[0]();

    }
    // 개인적인 테스트
    {
        void (*Ptr1)() = Test1;
        Ptr1();

        // 인자가 있는 함수의 Function Pointer를 초기화 할때에는
        // 인자 자리에 자료형만 작성해주면 된다. (값 넣으면 오류 발생)
        // 혹은 그냥 함수에 인자작성하듯이 하면됨
        int (*Ptr2)(int, int) = Test2;
        int (*Ptr22)(int _Value1, int _Value2) = Test2;

        Ptr2(10, 20);
        printf_s("%d\n", Ptr2(10, 20));

        int (*Ptr3)() = Test3;
        Ptr3();
        printf_s("%d\n", Ptr3());

        int (*Ptr4)(int) = Test4;
        Ptr4(100);
        printf_s("%d\n", Ptr4(100));
    }
}
