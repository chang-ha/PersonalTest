// etc.Vector


#include <iostream>
#include <vector>
#include <GameEngineBase/GameEngineDebug.h>
// vector는 배열을 대체합니다.
// 조금 특징이 다릅니다.

// 배열
// 10개짜리 배열을 만들면 즉시 [9]에 접근가능

// vector
// 10개를 만들어도 차례대로 넣어야 함

typedef int DataType;
class MyVector
{
public:
	MyVector()
	{

	}

	void push_back(const DataType& _Value)
	{
		// 배열크기 : 벡터가 할당한 배열의 크기
		// 원소크기 : 벡터가 할당한 배열 중 원소가 들어간 크기
		// 배열크기가 감당할수 있나?
		// 원소를 넣으려고 하는데 배열크기가 되는가??? (배열크기 > 원소크기 여야함)
		if (Size + 1 > Capacity)
		{
			// 더 크게 할당하자. (우리가 만든 GameEngineArray에서 Resize와 동일)
			reserve((Capacity + 1) * 1.5);
			// 확장해야 합니다.
		}

		ArrData[Size] = _Value;
		++Size;
	}

	void reserve(size_t _Value)
	{
		DataType* NewPtr = new DataType[_Value];
		size_t CopySize = _Value < Capacity ? _Value : Capacity;

		for (size_t i = 0; i < CopySize; i++)
		{
			NewPtr[i] = ArrData[i];
		}

		if (nullptr != ArrData)
		{
			delete[] ArrData;
			ArrData = nullptr;
		}

		ArrData = NewPtr;
		Capacity = _Value;
	}

	size_t size()
	{
		return Size;
	}

	size_t capacity()
	{
		return Capacity;
	}

	DataType& operator[](size_t _Index) const
	{
		if (Size <= _Index)
		{
			MsgBoxAssert("인덱스를 오버하여 벡터를 사용하려고 했습니다.");
		}
		return ArrData[_Index];
	}
public:
	// 벡터가 할당한 배열의 크기
	size_t Capacity = 0;
	// 벡터의 배열에 넣어준 원소의 크기(갯수)
	size_t Size = 0;
	// 배열을 가리키는 포인터(주소값)
	DataType* ArrData = nullptr;
protected:

private:

};


int main()
{
	{
		std::vector<int> Test;
		// Test.resize(10); // == push_back 10번 한것과 똑같은 크기로 만들어준다.
		//					// == resize(10)하면 배열의 크기 = 10, 원소의 크기 = 10 (전부 0이 들어가 있음)

		// 벡터는 넣는다는 개념임
		// 최초에는 아무것도 없다
		// 0~4 총 4개의 원소를 넣은것
		Test.push_back(0); // Test에 [0]
		Test.push_back(1); // [0][1]
		Test.push_back(2); // [0][1][2]
		Test.push_back(3); // [0][1][2][3]
		// 위와 같은 사용법은 최악의 사용법으로 불린다.
		// 이유 : 할당, 재할당이 일어나면 안좋게본다 (우리가 만든 Array랑 비슷하게 작동함)
		// 10000개짜리 배열이 10001개로 될 떄 안에서 Resize(10001)하고 delete하고 for문 만번돌아서 값을 다 복사하고 등...

		printf_s("%d\n", Test.size());
		for (size_t i = 0; i < Test.size(); i++)
		{
			printf_s("%d\n", Test[i]);
		}

		// 둘의 차이는??
		// Test.resize(10); // push_back 10번하는것 (원소는 전부 0이 들어가 있음)
		// Test.reserve(10); // 배열의 크기만 미리 10개로 키워놓음 (Capacity = 10), 원소의 크기는 0 (배열에 원소가 들어가 있지 않음)
		// reserve(10)하고 push_back하면 크기 10인 배열에 원소 1개가 들어가 있는 것

		// 그래서 "벡터를 쓸 때는 reserve를 미리 해놓는게 중요!!!!!"
	}


	{
		MyVector Test;

		Test.reserve(10);

		for (size_t i = 0; i < 10; i++)
		{
			Test.push_back(i);
			printf("Capacity %d\n", Test.capacity());
			printf("Size %d\n", Test.size());
		}

		for (size_t i = 0; i < Test.size(); i++)
		{
			printf("Value %d\n", Test[i]);
		}

		printf_s("size : %d", (int)Test.size());
	}

	return 1;

	{
		std::vector<int> Test;

		Test.reserve(10);

		for (size_t i = 0; i < 10; i++)
		{
			Test.push_back(i);
			printf("Capacity %d\n", Test.capacity());
			printf("Size %d\n", Test.size());
		}
		return 1;
	}
}