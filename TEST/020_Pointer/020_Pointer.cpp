﻿// 020_Pointer

// 주소값은 Byte로 샘(Bit로 새지 않음)
// 모든 포인터는 64비트 운영체제 일때 8바이트 크기를 가진다.
// 32비트 운영체제 일때 4바이트 크기를 가진다.

#include <iostream>
int main()
{
	// 포인터란 c++의 자료형의 한 형태며
	// 자료형 뒤에 *을 붙이는 문법을 통해서 선언한다.

	// int는 4Byte 정수
	// __int64는 8Byte 정수
	// 8바이트 주소표현 << 64bit운영체제 램의 최대 주소값을 다 표현하고도 남음
	// 4바이트 주소표현 << 32bit운영체제 (과거의 잔재) 이제는 몰라도 되지만 왜 몰라야 하는지는 알고있자
	// 9223372036854775807 << 8바이트 최대값
	//          4294967295 << 4바이트 최대값
	//         17179869184 << 램의 최대 주소값 (16GB)
	// 위에서 볼 수 있다싶이 64비트 운영체제로 주소표현시 램의 최대 주소값을 다 표현하고도 남음 (32비트 운영체제는 램의 주소값을 다 표현 불가능)
	// 하지만 실제 주소값을 보면 램의 최대 주소값을 넘어서는데 이는 가상주소(Virtual주소)값이기 때문
	// Virtual주소 : 운영체제에서 임의대로 주소를 부여해주는 것
	// 가상주소는 대신 어느정도 규칙은 있음 (딱 붙어있진 않지만 비슷한 위치에 존재)
	int Value = 0;


	// 예시
	int Value1 = 0;
	int* ValuePtr = &Value1;
	__int64 Address = 0;
	Address = (__int64)ValuePtr;
	// 포인터란 c++의 자료형의 한 형태이며
	// 자료형 뒤에 *을 붙이는 문법을 통해서 선언한다.

	//일반적인 자료형에 가능
	// 램에서의 위치를 의미하게 됩니다.
	int* ptr;


	// 100번지에 있는 값 10
	// 100번지 그 자체를 쓰고싶을때 포인터 사용
	int Value = 10;

	Value < 9;
	// value가 표현하는 값이 2가지
	// 내부의 자신의 진짜 값인 10
	// 그 이름을 통해서 램에 존재하게 되는 자신의 위치인 100번지
	// 100번지 주소값(램에서의 위치의 정수값)을 끌어내서 그것을 담아내는 전문 자료형을 만든 것
	// 그냥 int와 같이 사용하면 주소값인 100인지 정수값인 100인지 구별할 수 없음
	int* valuePtr = &Value;

	int Value2 = 0b00000000000000000000000000000001; // 2진수
	int Value16 = 0xffffffff; // 16진수 (16진수로 표현한 4바이트)
	// 0b 0000 0000 0000 0000 0000 0000 0000 0001
	// 0x  f    f    f    f    f    f    f    f  << f하나가 4개의 비트를 담당 f(16) = 15, 1111(2) = 15

	// unsigned 존재 이유 << 램에서는 -번지가 존재하지 않으니 탄생
	// 주소값은 -값이 없기 때문에 주소값은 unsigned

	// 형변환(맛보기)
	// 어떤 자료형 앞에 (자료형)이 자료형으로 바꿀 수 있으면 바꿔달라.
	__int64 Address = 0;
	Address = (__int64)valuePtr;

	// 코드로 쳐졌다면 램의 어딘가에는 존재해야 한다.
	// 모든건 위치가 있고 크기가 있어야 한다.
	// 주소값이라는것은 램의 위치를 표현하는 정수인데
	// bool* 와 int*가 크기가 다를까???? X 포인터는 그저 주소를 가리키는 값 (8바이트)
}
