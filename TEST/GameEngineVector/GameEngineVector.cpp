// GameEngineVector


#include <iostream>
#include <vector> // 벡터는 stl자료구조입니다.
#include <GameEngineBase/GameEngineDebug.h>
typedef int DataType;
class MyVector
{
public:
	MyVector()
	{

	}

	void push_back(const DataType& _Value)
	{
		if (Size + 1 > Capacity)
		{
			reserve((Capacity + 1) * 1.5);
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
	size_t Capacity = 0;
	size_t Size = 0;
	DataType* ArrData= nullptr;
protected:

private:

};

int main()
{

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