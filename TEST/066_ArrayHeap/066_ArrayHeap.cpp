// 066_ArrayHeap

#include <iostream>
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// "정적 바인딩"
	// 갯수가 정해져있고, 코드가 실행되면 바뀌지 않는 메모리 영역들을 말한다
	{
		int Arr[10];
		int* Ptr = Arr;
		Ptr[0];
	}

	// 힙을 사용하는 행위 == "동적 바인딩" (배열이라서가 아님, 그냥 힙을 쓴다면...)
	{
		// 2가지 new를 사용해서 배열을 만들수도 있습니다.
		int* Ptr = new int[100];
		// 지울때 이 방식을 통해서 지우는게 힙배열 삭제의 정식 문법
		// 배열은 무조건 이방식으로 지워야한다.
		// delete[] Ptr;
		// 안전한 방식으로 삭제
		if (nullptr != Ptr)
		{
			delete[] Ptr;
			Ptr = nullptr;
		}
		// 그냥 delete로도 지워는 진다.
		// 그런데 상황에 따라 안지워질때가 있다...;; << 그래서 delete[] 로 지워줘야함
		// delete Ptr
	}
}
