﻿// 015_Charactor


int main()
{	// Char
	// 한글자만 처리가능
	// 램은 비트의 집합 => 글자도 비트로 바뀌어야함.
	// 1Byte = 8Bit = 정수로 표현한다면 255가지 가능 (-128 ~ 127)
	// 이를 "아스키 코드" 라고 부름
	char Ch = 'A';



	// 문자를 표현하는 방식은 1가지
	// 특정 글자를 정수 1개와 매칭
	// ex) A = 숫자 95야, 0은 숫자 78이야 (숫자는 예시 = 외울필요 X)


	// 위의 아스키 코드로 한글을 표현 가능? 불가능 그래서 나온게 2Byte문자형
	// 2Byte문자형
	// 앞쪽에 L을 붙여서 표현하는 것
	// L을 안붙이면 1Byte문자형이라 인식
	// 이를 유니코드라 부름
	wchar_t wch = L'A';

	// 아랍어는? 중국어는? 일본어는??? 이러면 끝이 없음
	// 그래서 나온게 국가 코드가 생김
	// UTF-8이라고 부름 = 글자를 1 2 3 4 바이트로 표현합니다.
	// 어떤 글자는 1Byte 어떤 글자는 2Byte... 이렇게 매칭
	// U8표현은 설정의 ISO C++ 14이상만 가능
	char Arr = u8'a';

	// 위 개념들을 인코딩이라고 부름.

	// 아스키 : 255개만 표현
	// 멀티바이트 : 어떤건 1바이트, 어떤건 2바이트로 표현
	// 유니코드(와이드 바이트) : 모두다 2바이트
	// 그 후 UTF-8, UTF-16, UTF-32 ... <<< 이제는 이것들만 사용
	// 그러면 왜 아스키 등은 왜 안없애고 남아있는가? 이제껏 만든 프로그램(코드)를 사용할 수 없게 되기 때문


}