// 060_FunctionPointer


#include <iostream>
// 이 함수도 프로세스로 메모리에 올라갈 것이기 때문에
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

int main()
{
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
}
