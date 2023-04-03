// 025_PointerConst


#include <iostream>
int main()
{
	{
		// const는 무조건 초기화를 해줘야한다
		// 내 의견 : 모르는값(의도하지 않은 값)이 상수화 되버리는걸 막기위해
		// const int Value; << 에러코드
	}
	{
		// int 와 cdonst int는 전혀 다른 자료형임!!!!
		int Value = 10;
		int Value1 = 20;
		int* Ptr = &Value;

		// const int와 int const는 완전히 동일하지만 앞에 붙이는게 좋음
		// const int* Ptr = int const* Ptr (정말 완전히 동일)
		const int* cPtr = &Value;
		// *cPtr = 20; << 불가능 (cPtr이 가리키는것은 const int이기 때문에 상수화 되어있음)
	}

	{
		// 100번지에 있는 'A'
		char Test0 = 'A';
		// 110번지에 있는 'a'
		char Test1 = 'a';

		// 100번지 안에 있는 값을 const한 것 (100번지에 있는 'A'를 바꿀 수 없음)
		// 100번지를 110번지로 바꿀수는 있음
		// 120번지에 있는 100번지수
		const char* Chr = &Test0;
		// 가리키는 대상을 바꿀수 있음
		Chr = &Test1;
		// 가리키는 대상의 값은 바꿀수 없음
		// *Chr = 'B';

		// 100번지(가리키는 대상)을 못바꾸게 하고 싶음
		// *을 기점으로 오른쪽과 왼쪽을 구분해야함
		// * 앞은 내가 가르키고자하는 대상, (const int)* 이라고 생각하면 편함
		// * 뒤는 *에 영향을 미치는 것, (const int)* const 라고 생각하면 편함 
		// char* const = Ref
		// 100번지는 못바꾸지만 100번지에 있는 값은 바꿀 수 있음
		char* const Chr1 = &Test0;

		// (const char) * const << * 앞에 자료형은 묶어서 생각, * 뒤에 const는 *에 영향을 미치는 것
		const char* const Chr2 = &Test0;
	}
	printf_s("aaaaccccdddd");
}