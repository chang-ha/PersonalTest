// 084_DefaultParameter


#include <iostream>
void Function(int _Value = 50)
{
    std::cout << _Value << std::endl;
}
// 디폴트 인자는 무조건 오른쪽에 배치해야함
// 인자를 넣어줬을떄 디폴트 인자에 값을 넣은건지 안넣은건지 구분할 수 없음
//void Function(int _Value = 50, int Test)
//{
//    std::cout << _Value << std::endl;
//}
// 함수의 오버로딩시 주의
// 무슨 함수를 호출해야하는지 모름
void Function(int _Value, int Test = 50)
{
    std::cout << _Value << std::endl;
}
int main()
{
    // 두 함수중 어느 함수를 호출해야 하는가???
    // 그래서 오버로딩시 주의해야함
    // Function(10);
    Function();
    Function();
    Function();
    Function();
    Function();
}