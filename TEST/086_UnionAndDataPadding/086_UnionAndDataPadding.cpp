// 086_UnionAndDataPadding

#include <iostream>

// GameEngineTime을 만드는 도중 union개념이 나와서 설명
// class, struct, union의 다른 의미는 내부 메모리 구조를 어떻게 할 것인지도 내포하고 있다
// class, struct : 내부 변수들의 메모리 구조를 차례대로 나열하라 (BytePadding을 사용해서)
// union : 내부 변수들의 메모리 구조를 union형식으로 해라 << 변수들의 시작 메모리 주소를 같게 해라



//typedef union _LARGE_INTEGER {
//    struct {
//        int LowPart;
//        int HighPart;
//    };
//    struct {
//        DWORD LowPart;
//        LONG HighPart;
//    } u;
//    LONGLONG QuadPart;
//} LARGE_INTEGER;

// struct와 class의 차이
// default 접근 제한 지정자가 struct는 public, class는 private

union LARGE_INTEGER
{
    // struct(구조체)에 구조체 이름없이 맨 뒤에 u라고 붙임
    // 이는 해당 구조체를 바로 변수화시키는 문법임
    // u << struct인 멤버변수
    struct
    {
        int LowPart;
        int HighPart;
    } u;
    __int64 QuadPart;
};

// 위와 아래는 동일한 형식 (구조체를 바로 멤버변수로 사용하지 않음)
class Player
{
public:
    struct MyClass
    {
        int LowPart;
        int HighPart;
    };
    MyClass u;
    __int64 QuadPart;
};

class tPlayer
{
public:
    // Player가 300번지에 만들어 졌다고 가정하면
    // LowPart는 300번지 ~ 304번지
    int LowPart;
    // HighPart는 304번지 ~ 308번지
    int HighPart;
    // QuadPart는 308번지 ~ 316번지
    __int64 QuadPart;
};

union UPlayer
{
public:
    // 유니온은 어떤 클래스인가??
    // 내부에 의미있는 변수가 있다면
    // 그 중 가장 큰 변수를 중심으로 같은 위치에 다른 이름을 준다.
    
    // 모든 멤버가 동일한 메모리 위치를 공유하는 사용자 정의 형식(공동체 == union)
    // "메모리가 제한된 경우 메모리를 절약하는 데 유용"

    // 300번지 ~ 308번지
    __int64 C = 0b0000000000000000000000000000000100000000000000000000000000000001;
    // 300번지 ~ 304번지
    int A;
    // 300번지 ~ 304번지
    int B;
};

class MyUniClass // 12바이트
{
public:
    union // 4바이트
    {
        int a; // 4바이트
        int b; // 4바이트
    };

    struct // 8바이트
    {
        int A; // 4바이트
        int B; // 4바이트
    };
};

union LastUnion // 8바이트
{
    // 300번지 8바이트
    struct
    {
        int a;
        int b;
    } ValueAB; // struct가 만들어지고 바로 ValueAB이름을 가진 멤버변수를 선언

    // 300번지 8바이트
    __int64 Test;
};

int main()
{
    {
        MyUniClass New;
        New.a;
        New.b;
        int Size = sizeof(MyUniClass);
    }
    // class사용시
    {
        // 200번지에 만들어 졌다고 가정
        Player NewPlayer;

        // 200번지 ~ 204번지 까지 사용하겠다 
        NewPlayer.u.LowPart;

        // 204번지 ~ 208번지 까지 사용하겠다 
        NewPlayer.u.HighPart;

        // 208번지 ~ 216번지 까지 사용하겠다 
        NewPlayer.QuadPart;

        // Player의 크기는 16바이트
        int Value = sizeof(Player);

        int a = 0;
    }

    // union사용시
    {
        // union은 같은 위치에 다른 이름을 준다
        // 사실 컴파일러 입장에서는 이름(변수명)은 아무런 의미가 없음
        // 그저 사용자가 사용하기 좋게 해주는 기능일 뿐
        // 컴파일러 입장에선 그저 메모리 주소를 의미하고 있음

        
        // 300번지에 만들어 졌다고 가정
        UPlayer NewPlayer;

        // 00000001 00000000 00000000 00000000 00000001 00000000 00000000 00000000 << 리틀에디안

        // 300번지 ~ 304번지 까지 사용하겠다 
        // 00000001 00000000 00000000 00000000
        NewPlayer.A;
        

        // 300번지 ~ 304번지 까지 사용하겠다 
        // 00000001 00000000 00000000 00000000
        NewPlayer.B;

        // 300번지 ~ 308번지 까지 사용하겠다 
        // 00000001 00000000 00000000 00000000 00000001 00000000 00000000 00000000
        NewPlayer.C;

        // UPlayer의 크기는 8바이트
        int Value = sizeof(UPlayer);

        int a = 0;
    }

}

