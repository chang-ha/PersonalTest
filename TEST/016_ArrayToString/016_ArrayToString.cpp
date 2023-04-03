// 016_ArrayToString

int main()
{
    // 어떤 자료형을 봤다면 그것은 추가적인 문법으로 모두다 배열이 될 수 있습니다.
    // 배열은 선언했다면 모든 자료들이 딱 붙어있음
    // ex) int 배열이고 첫번째 값이 100번째면
    // 그 다음은 104, 108 ...
    // bool(1Byte)자료값이면 100, 101, 102...

    int Value = 10;

    // 배열은 자동으로 전부다 0으로 초기화 됩니다.
    int ArrValue[5] = {};

    {
        // 아래는 초기화 하지 않은 것 = 무슨 값이 들어갈지 모름
        int ArrValue[5];
        int a;
    }

    {
        // 아래는 배열 크기를 넘어감
        // int ArrValue[5] = { 0, 1, 2, 3, 4, 5 };
    }

    {
        // 넣은것 까지만, 나머지는 0
        int ArrValue[5] = { 2, };
        int a = 0;
    }

    {
        // false, false, false, false, false
        // c++에서는 숫자0을 false로 대신하는게 선호되지 않음
        // 정확하게 false, true로 표현하기 (숫자로 표현할 수 있지만 안하는거 권장)
        bool ArrValue[5] = {};
    }

    {
        bool ArrValue[5] = { false, true, true, true, true };
    }

    {
        int value1 = 10; // 이게 메모리상에서 100번째면 아래는 104번째일까??? X
        int value2 = 20; // 메모리 어디에 위치할 지 모름
    }

    // 문자의 배열은 축약형 표현을 사용할 수 있습니다.
    // 추가적인 규칙 => printf에서 설명
    {
        char ArrValue1[5] = { 'a', 'b', 'c' };
        // 위 선언은 아래로 표현할 수 있음
        char ArrValue2[5] = "abc";
    }
}