// BitTest(endian개념)


#include <iostream>
int main()
{
	int Value = 0b00000000000000000000000000000001;

	int* Ptr = &Value;

	char* ChPtr = reinterpret_cast<char*>(Ptr);

	// 예상되는 값
	//  Test0    Test1    Test2    Test3
	// 00000000 00000000 00000000 00000001
	// 주소값을 읽어 시작하는 위치부터 순서대로 읽을것이라 예상됨

	// 확인되는 값
	char Test0 = ChPtr[0]; // 00000001
	char Test1 = ChPtr[1]; // 00000000
	char Test2 = ChPtr[2]; // 00000000
	char Test3 = ChPtr[3]; // 00000000
	// 예상과 반대로 읽어서 저장함

	// 이 현상의 이름은???
	// 리틀 엔디안 (little - endian)
	// 반대는 빅 엔디안 (big - endian) << 최초 예상한 순서
	int a = 0;
}

