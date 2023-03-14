﻿// 금일 강의 내용 : #include, MainFunction(진입점)

// #include <파일명> 은 다른 프로그래머들이 미리 만들어놓은 라이브러리(코드를) 불러와서 내가 사용하겠다는 것
#include <iostream> // Ctrl+Shift+G : 해당 파일 코드 확인 단축키


// 코드란 내가 컴퓨터에게 어떤 일을 시키는 것
// 먼저 프로그램을 실행할거야
// 실행하면 가장 먼저 진입점에서 부터 코드를 읽어감

// 진입점에서부터 실행흐름이 생긴다.
// 이 실행흐름을 함수라고 부르기로 했다.

int main() // int main() 을 진입점으로 하기로 모두가 합의함 (바꿀수는 있지만 바꿀필요가 없음)
{ // 함수의 시작
    // cout은 어려우니 나중에 설명 우선은 printf부터 설명함
    std::cout << "Hello World!\n";


} // 함수의 끝