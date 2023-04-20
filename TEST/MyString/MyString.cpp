// MyString


#include <iostream>
#include <vector>
#include <string>
class MyString
{
public:
	void operator=(const wchar_t* _Other)
	{
		for (int i = 0; _Other[i] != 0; i++)
		{
			String.push_back(_Other[i]);
		}
	}

	char front()
	{
		return String[0];
	}

	char back()
	{
		int Index = String.size() - 1;
		return String[Index];
	}

	int length()
	{
		return String.size();
	}

	int capacity()
	{
		return String.capacity();
	}

	void append(const wchar_t* _Other)
	{
		for (int i = 0; _Other[i] != 0; i++)
		{
			String.push_back(_Other[i]);
		}
	}


protected:

private:
	std::vector<wchar_t> String;
};
int main()
{
	setlocale(LC_ALL, "KOR");
	{
		MyString str;
		str = L"안녕하세요";
		wchar_t Test = str.front();
		Test = str.back();
		int Index = str.length();
		printf_s("%s\n", str);
	}
	return 1;
	{
		std::wstring realstr;
		std::wstring Test;
		realstr = L"안녕하세요";
		// replace
		// 1. 바꾸려는 string의 인덱스를 지정
		// 2. 해당 인덱스에 대체할 string의 크기
		// 3. 대체할 string
		realstr.replace(0, 2, L"오늘");
		// setlocale(LC_ALL, "KOR");
		std::wcout << realstr << std::endl;

		// find
		// 해당 string이 시작하는 인덱스 값을 반환
		int index = realstr.find(L"오늘");
		std::wcout << index << std::endl; // 0
		index = realstr.find(L"녕");
		std::wcout << index << std::endl; // -1
		index = realstr.find(L"요");
		std::wcout << index << std::endl; // 4
		index = realstr.find(L"어");
		std::wcout << index << std::endl; // -1 (없는 문자열은 -1로 반환)

		// rfind
		// rfind는 find를 뒤에서 부터 실행
		realstr.replace(4, 2, L"오늘");
		std::wcout << realstr << std::endl;
		index = realstr.rfind(L"오늘");
		std::wcout << index << std::endl; // 4
		index = realstr.rfind(L"녕");
		std::wcout << index << std::endl; // -1
		index = realstr.rfind(L"요");
		std::wcout << index << std::endl; // -1

		Test = L"오아아오오아";
		std::wcout << Test << std::endl;
		// 1. find_first_if
		// 찾는 문자열이 처음 나타나는 인덱스를 리턴
		index = Test.find_first_of(L"아");
		std::wcout << index << std::endl; // 1
		// 2. find_last_of
		// 찾는 문자열이 마지막으로 나타나는 인덱스를 리턴
		index = Test.find_last_of(L"아");
		std::wcout << index << std::endl; // 5
		// 3. find_first_not_of
		// 찾는 문자열이 아닌 값들의 첫번째 값의 인덱스를 리턴
		index = Test.find_first_not_of(L"아");
		std::wcout << index << std::endl; // 0
		// 4. find_last_not_of
		// 찾는 문자열이 아닌 값들의 마지막 값의 인덱스를 리턴
		index = Test.find_last_not_of(L"아");
		std::wcout << index << std::endl; // 4
		int a = 0;
	}
}

