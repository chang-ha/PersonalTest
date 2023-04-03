// 011_Operator003 (삼항연산자, sizeof)

int main()
{
    // 삼항연산자 (메모리 영역이 3개 필요)
    // a ? b : c
    // -> a는 참 혹은 거짓일때 메모리, b는 참일때 메모리, c는 거짓일때 메모리 

    int a = 7;
    int b = 3;
    int c = 0;

    // a != b가 참이면 c에 100을, a != b가 거짓이면 c에 200을 리턴
    c = a != b ? 100 : 200;

    // sizeof 연산자 (단항연산자)
    // sizeof(메모리영역) = 메모리영역이 몇 Byte인지 알아내는 연산자
    // ()안에 있는 메모리영역의 바이트 크기를 리턴합니다.
    c = sizeof(a);
    c = sizeof(int);
    c = sizeof(bool);
}
