#include "Temp.h"
#include <iostream>

// DataType을 알 수 없다고 나옴
// void Function(DataType _Data);

// 그럼 아래처럼 구현하면 되나???
// 아래처럼 구현하면 헤더에서 선언한 DataType과
// cpp에서 선언한 DataType은 같아 보이지만 다른 DataType임
// 아래처럼 구현하면 알 수 없는 외부기호 오류 발생!!!
// 그래서 template는 헤더에 구현해야함
//template<typename DataType>
//void Temp<DataType>::Function(DataType _Data)
//{
//	DataType type = _Data;
//	std::cout << _Data << std::endl;
//}

// 아래처럼 구현하면 쓸 수는 있음
// 템플릿 특수화 느낌
// 그런데 아래처럼 구현할거면 템플릿 함수를 왜 씀...?
// int인 경우에만 사용 가능함
void Temp<int>::Function(int _Data)
{
	int type = _Data;
	std::cout << _Data << std::endl;
}