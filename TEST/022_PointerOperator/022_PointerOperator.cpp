﻿// 022_PointerOperator


// 포인터의 기본
void ValueChange(int Ptr)
{
	// 함수에 들어오는 변수는 밖에 영향을 미칠 수 없음(지역변수)
	// 여기서는 아무리 Ptr값을 바꿔도 main에 있는 Ptr에는 영향 X
	// ValueChange_Ptr = 0 / main_Ptr = &Value
	Ptr = 0;
}

void ValueChangePtr(int* Ptr)
{
	// 함수에 들어오는 변수는 밖에 영향을 미칠 수 없음(지역변수)
	// 그치만 이 함수는 변수가 주소값(100번지)가 넘어간것임
	// *Ptr은 *붙이는 순간 해당 주소에 있는 값을 건드리겠다는 것
	// *Ptr = 0을 했으므로 main에 있는 Value = 20 이 0으로 바뀜
	*Ptr = 0;
}
int main()
{
	{
		int Value = 10;

		int* Ptr = &Value;

		// 그럼 Ptr은 주소가 없나??? X 있다.
		// Value(10)이라는 변수의 위치를 가지고있는 Ptr (100번지 주소값을 가지고 있는 120번지)
		// 이중포인터는 꼬리물기
		// ... 계속 이어갈 수 있음 (100번지 주소값을 가지고 있는 120번지의 주소값을 가지고 있는 150번지...)


		// 이중포인터
		int** PtrPtr = &Ptr;

		// 그 위치의 메모리를 사용하겠다.
		// 그 포인터 변수의 앞에 *을 붙이는 연산자는
		// *Ptr 100번지의 값을 사용하겠다.

		*Ptr = 20;
		ValueChangePtr(Ptr);
		ValueChange(Value);
	}
}
