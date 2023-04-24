// etc.StdString


#include <iostream>
#include <vector>
class MyString
{
public:
	void operator+(const MyString& _Other)
	{
		std::vector<char> NewBuffer;

		NewBuffer.reserve(Buffer.size() + _Other.Buffer.size());

		for (size_t i = 0; i < Buffer.size(); i++)
		{
			NewBuffer.push_back(Buffer[i]);
		}
		for (size_t i = 0; i < _Other.Buffer.size(); i++)
		{
			NewBuffer.push_back(_Other.Buffer[i]);
		}
		this->Buffer = NewBuffer;
	}
	MyString(const char* _Text)
	{
		int i = 0;
		while (0 != _Text[i])
		{
			Buffer.push_back(_Text[i]);
			i++;
		}
	}
protected:

private:
	std::vector<char> Buffer;
};
int main()
{
	// 문자라고 하는건 굉장히 많이 사용된다
	// 특히 파일입출력이나 경로를 표현할 떄 문자를 잘 편집할 수 있어야 하기 때문
	// "C:\Program Files"
	// >> "C:\Program Files\Steam" 으로 바꿔야할 때
	// 문자열을 편집하는 기술이나 알고리즘 함수들에 대해서 많이 알면 알수록 편해집니다

	// 앞쪽 255(영어 등)은 어느 인코딩 방식이든 고정(2~4바이트에서도 동일하게 적용)
	// 인코딩 << 숫자 == 어떤 글자나 의미를 매칭하는 것을 의미한다.
	// 1바이트 인코딩 아스키(ANSI)

	// 1~2바이트 멀티바이트 인코딩 << 65536 특정 한 국가의 문자 정도는 표현할 수 있게 되었다
	// 2바이트 인코딩까지는 국가별로 달라지는 매칭형식입니다.
	// 50000번째가 한국에서는 '가'이고 일본에서는 다른 글자로 매칭되어있음(국가마다 다름)
	// 문제점 << 국가마다 매칭된 숫자랑 글자가 다르기 때문에 국가마다 파일이 다른 글자로 나옴

	// 그래서 나온게 3바이트 문자형 및 4바이트 문자형 "UTF시리즈"
 	// 우리가 지금 코딩하는 (VisualStudio) 글자들은 국가코드에 따른 문자열로 해석된다

	// 멀티바이트(어떤건 1바이트 어떤건 2바이트)
	"하하하 호호호";
	// 하 = 2바이트, ' ' = 1바이트, "호" = 2바이트
	char Arr[6] = "하 호";

	// wchar_t 는 모두 2바이트
	wchar_t Arr[4] = L"하 호";

	// std::string << vector형태의 자료구조
	{
		// 멀티바이트
		std::string Text0 = "안녕하세요";
		std::string Text1 = "반갑습니다";
		std::string Result = Text0 + Text1;
		std::cout << Result << std::endl;
	}
	{
		// 와이드바이트
		std::wstring Text0 = L"안녕하세요";
		std::wstring Text1 = L"반갑습니다";
		std::wstring Result = Text0 + Text1;
		// 와이드 바이트는 국가 코드에 영향을 받기 때문에 처음에는 출력이 안됨
		std::wcout << Result << std::endl;

		// 기본적으로 비주얼 스튜디오의 출력 국가 코드는 미국임
		// 그래서 출력 국가 코드를 한국으로 변경하고 출력하면 나옴
		setlocale(LC_ALL, "KOR");
		std::wcout << Result << std::endl;
	}

	// std::string 함수사용법 공부하기
	// "안녕" >> "오늘" 로 바꿔주는 함수
	// 1. replace()

	// 특정 문자나 글자가 몇 번 인덱스에 있는지 알려주는 함수
	// 2-1. find()
	// 2-2. rfind()
	// 2-3. find_last_not_of
	// 2-4. find_first_of

	// +는 내부에서 append() 하고 있는 것임
	// 3. append()

	{
		char Arr0[256] = "안녕하세요";
		char Arr1[256] = "안녕하세요";

		// 아래 비교문은 내부로 들어갈까?? XXXXX
		// 아래는 주소값을 비교한 것임 
		// 절대 값이 같다고 생각하면 안됨
		// 원래는 Arr0와 Arr1은 char[]형이었는데 비교를 위해 char*로 암시적형변환한것임 (주소값끼리 비교한 연산)
		if (Arr0 == Arr1) // if(reinterpret_cast<char*>(Arr0) == reinterpret_cast<char*>(Arr1))
		{
			int a = 0;
		}

		// 아래도 Arr0의 주소값과 코드영역에 있는 const char[11] 의 주소값을 비교한 것
		if (Arr0 == "안녕하세요")
		{
			int a = 0;
		}
		int a = 0;
	}
}

// "!!!!!!!!주의사항!!!!!!!!"
// 위에 함수는 내가 만약 200글자를 인자로 넣으면
// 200글자가 새로 동적할당 되는것임
void Function(std::string _Value)
{

}

// 아래 함수는 200글자의 주소값을 넣어주는 것이기 때문에
// 새로 할당하진 않음
void Function(const std::string& _Value)
{

}
