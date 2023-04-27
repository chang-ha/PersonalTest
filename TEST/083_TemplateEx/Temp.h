#pragma once


// template함수는 클래스 헤더파일 에서만 유효하다
// 왜냐??? 정확히 template함수가 언제 생성되는지 알아야함
// template함수는 치환문법이라고 하였음
// "template함수는 main에서 함수가 읽히는 순간"
// "main함수 위에 만들어지게됨"
// 그래서 cpp에서 구현하는건 적용이 안됨 (main아래에 구현)
template<typename DataType>
class Temp
{
public:
	// constructer destructer
	Temp() {}
	~Temp() {}

	// delete function
	Temp(const Temp& _Ohter) = delete;
	Temp(Temp&& _Ohter) noexcept = delete;
	Temp& operator=(const Temp& _Other) = delete;
	Temp& operator=(Temp&& _Other) noexcept = delete;

	void Function(DataType _Data)
	{

	}

protected:

private:

};

