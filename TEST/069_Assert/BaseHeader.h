#pragma once

#include <Windows.h>
#include <assert.h>
//void MsgBoxAssert(const char* _Text)
//{
//	//									MB_OK = 확인버튼 한개 나오게
//	MessageBoxA(nullptr, _Text, "Error", MB_OK);
//	// assert가 false면 프로그램이 터지게 만듬
//	// 다시시도 누르면 어디가 터진지 알려줌
//	assert(false);
//}

// 위의 함수를 이용하면 에러가 나면
// 함수위치로 와버려서 어디서 터졌는지 모름
// 호출스택으로 한번 뒤로 가야해서 귀찮음
// 그래서 define을 사용
#define MessageBoxAssert(TEXT) 	MessageBoxA(nullptr, TEXT, "Error", MB_OK); assert(false);

// inline과의 차이점
// inline은 그래도 함수형식이기 때문에 인자가 자료형이 맞는지 한 번 검사해줌
// 그리고 함수 호출 스택 전까지 가야함
//inline void MsgBoxAssert(const char* _Text)
//{
//	MessageBoxA(nullptr, _Text, "Error", MB_OK);
//	assert(false);
//}