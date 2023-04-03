﻿// 금일 강의 내용 : Operator, 초기화 및 대입, 연산자, bit 개념 및 계산법

int main()
{
    // C++는 타입이 존재하는 언어이기 때문에 자료형이 없는것을 허용하지 않고 자료형을 변화시킬수도 없음.
    // 타입기반 언어라는 표현 하셨는데 정확하지 않음 걸러 들어야함.
    // 연산자 : 특정 메모리를 변화시키는 명령을 축약해 놓은 기호
    
   
    // right에 100의 값을 붙여넣는것
    int right = 100;    
    
    // 메모리가 만들어지면서 동시에 특정 값을 받는 것을 초기화라고 합니다. (초기화하는것이 좋음)
    int left = 50;

    // 이걸 카피 혹은 대입이라고 한다.
    left = 10;

    // 선언만 하면 메모리안에 무슨 값이 있는지 알수가 없음 (이전에 사용했던 값이 남아있을 수 있음)
    // 그래서 무조건 초기화하는것이 좋음. 
    int a;

    int x = 7;
    int y = 3;
    int result = 0;

    // F9는 정지점 만드는 것
    result = x + y;
    result = x - y;
    result = x * y;

    // c++에서 정수의 나눗셈은 몫만 나옴
    result = x / y;
    // 나머지 보고싶으면 %
    result = x % y;


    //단항연산자
    result = -left;
    result = +left;
}







