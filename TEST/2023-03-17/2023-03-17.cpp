// 금일 강의 내용 : 포인터 연산자, printf_s의 가변인자


#include <iostream>


int main()
{
	{
		// 100번지 Value
		int Value = 0;
		int* Ptr = &Value;
		__int64 Address = 0;
		// Ptr[0]; << 자기 자신의 위치


		Address = (__int64)Ptr;
		// 나의 주소값을 100번지 + sizeof(int) * 1 하겠다
		// 포인터는 자료형과 같게 생각하면 안됨!!!
		// sizeof(자료형) 만큼 이동함
		Ptr = Ptr + 1; // Ptr += 1; (동일문법)

		Address = (__int64)Ptr;
		Ptr = Ptr + 1;
		Address = (__int64)Ptr;
		Ptr = Ptr + 1;
		Address = (__int64)Ptr;
		Ptr = Ptr + 1;
		Address = (__int64)Ptr;
		Ptr = Ptr + 1;
	}
	
	// %를 사용하게 되면 이는 포매팅 문자라고함
	// 숫자나 다양한 다른 변수들을 사용해서 출력을 요쳥하는 것
	printf_s("%d %d %d", 1, 3, 5);

	// 쓰레기값(흔적) 이용하려고 하지 말자!!!
	// %d를 3개 입력했는데 인자는 3개랑 다르면 다른값이 출력될 수도 있음
	// 내 의견 : 내가 입력한 믿을만한 인자 사용하자
	printf_s("%d %d %d", 1); 
}

