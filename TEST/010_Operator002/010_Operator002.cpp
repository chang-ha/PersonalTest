﻿// 010_Operator002

int main()
{
    int   Left = 0b00000000000000000000000000000010;
    int  Right = 0b00000000000000000000000000000001;
    int Result = 0b00000000000000000000000000000000;

    // && : 논리형 연산자, & : 비트형 연산자
    // &는 둘 다 True 여야 True
    // Left   = 0b00000000000000000000000000000010
    // Right  = 0b00000000000000000000000000000001
    // Result = 0b00000000000000000000000000000000
    Result = Left & Right;

    // |는 둘 중 하나라도 True면 True
    // Left   = 0b00000000000000000000000000000010
    // Right  = 0b00000000000000000000000000000001
    // Result = 0b00000000000000000000000000000011
    Result = Left | Right;

    // ~ : (단항연산자) 비트를 반전 시켜라
    // Result = 0b00000000000000000000000000000000을 반전시키면
    // Result = 0b11111111111111111111111111111111 = -1
    // ~ = Not
    Result = ~0;

    //  ^ = 비트 XOR 연산자
    // Left   = 0b00000000000000000000000000000010
    // Right  = 0b00000000000000000000000000000001
    // Result = 0b00000000000000000000000000000011 
    // ^는 둘이 다를때만 True, 둘이 같으면 False = 0
    Result = Left ^ Right;

    // True와 False, 참과 거짓의 명확한 의미
    // 특정 메모리 영역의 비트가 전부 0이라면 False(거짓)
    // 특정 메모리 영역의 비트중 단 1개라도 1이 있다면 True(참)
    bool bResult = 2;
    bResult = 3 && 12312313123;
    bResult = 0;

    // 왼쪽 Shift 연산자
    //    1   = 0b00000000000000000000000000000001
    // 왼쪽으로 3칸가라
    // Result = 0b00000000000000000000000000001000 = 8
    Result = 1 << 3;

    // 보내는 자릿수를 넘어서게 되면 값이 손실될 수 있다 = 0?? X (Cpu마다 다름)
    Result = 1 << 33;
    Result = 1 >> 1;

    // 오른쪽 Shift 연산자 
    // 오른쪽으로 n칸 가라

    //개인적인 의문점 : 가장 앞자리 비트로가면 값이 - 로 바뀌나???? "바뀐다."
    int Test = 0b01000000000000000000000000000000;
    Test = Test << 1;

    // 축약연산자
    // 특정 메모리영역의 값을 기반으로 하는 이항 연산에 가깝다.
    // ex) a += b

    int Value1 = 20;

    Value1 += 10; // Value1 = Value1 + 10;

}