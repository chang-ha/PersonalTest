﻿// 금일 수업 내용 : 비트연산자, 삼항연산자, sizeof연산자

int main()
{
    // 수업 시작전 질문

    // 하나의 문법 단위
    // 즉 xx한 일을 해라라는 마무리로 쓰이는 문법
    // 이 마무리(;)가 없다면 연결된 코드로 인식 (동시에 실행되어야 한다고 생각하고 읽는다)

    ;

    // 변수명이나 메모리명의 첫번째 글자는 숫자로 사용할 수 없다.
    // int 1value = 10;

    // int value 를 만들고 거기에ㅂ 10을 넣고
    // 이 코드를 마무리 지어라. (그 후에 다음 코드를 실행해라 라는 뜻)
    int value = 10;

    // ;를 남용하면 마무리 지으면 안되는 순간에도 마무리 지어버리니 사용에 주의


    // -------------------------------
    // 비트연산자

    int Left = 0b00000000000000000000000000000010;
    int Right = 0b00000000000000000000000000000001;
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

    //  ^ = 비트 XOR
    // Left   = 0b00000000000000000000000000000010
    // Right  = 0b00000000000000000000000000000001
    // Result = 0b00000000000000000000000000000011 
    // ^는 둘 이 다를때만 True, 둘 이 같으면 False = 0
    Result = Left ^ Right;

    // True와 False, 참과 거짓의 명확한 의미
    // 특정 메모리 영역의 비트가 전부 0이라면 False(거짓)
    // 특정 메모리 영역의 비트중 단 1개라도 1이 있다면 True(참)
    bool bResult = 2;
    bResult = 3 && 12312313123;
    
    // 왼쪽 Shift 연산자
    //    1   = 0b00000000000000000000000000000001
    // 왼쪽으로 3칸가라
    // Result = 0b00000000000000000000000000001000 = 8
    Result = 1 << 3;

    // 보내는 자릿수를 넘어서게 되면 값이 손실될 수 있다 = 0 (Cpu마다 다름)
    Result = 1 << 33;
    Result = 1 >> 1;

    // 오른쪽 Shift 연산자 
    // 오른쪽으로 n칸 가라
    
    //개인적인 의문점 : 가장 앞자리 비트로가면 값이 - 로 바뀌나? 바뀐다.
    int Test = 0b01000000000000000000000000000000;
    Test = Test << 1;

    // 축약연산자
    // 특정 메모리영역의 값을 기반으로 하는 이항 연산에 가깝다.
    // ex) a += b

    int Value1 = 20;

    Value1 += 10; // Value1 = Value1 + 10;
    

    // ----------------------------------
    // 삼항연산자 (메모리 영역이 3개 필요)
    // a ? b : c
    // -> a는 참 혹은 거짓일때 메모리, b는 참일때 메모리, c는 거짓일때 메모리 

    int a = 7;
    int b = 3;
    int c = 0;

    // a != b가 참이면 c에 100을, a != b가 거짓이면 c에 200을 리턴
    c = a != b ? 100 : 200;

    // sizeof 연산자 (단항연산자)
    // sizeof(메모리영역) = 메모리영역이 몇 Byte인지 알아내는 연산자
    c = sizeof(a);
    c = sizeof(int);
    c = sizeof(bool);



}
