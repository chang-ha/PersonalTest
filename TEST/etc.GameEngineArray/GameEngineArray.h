#pragma once

typedef int Datatype;


class GameEngineArray
{
public:
	// constructer destructer
	GameEngineArray(size_t _Value)
		: ArrPtr(new Datatype[_Value])
		, ArrCount(_Value)
	{
		// ArrPtr = new int[_Value];
	}

	~GameEngineArray()
	{
		// 생성자에서 만들어준 배열은 소멸자에서 삭제한다
		// 안전한 삭제 방법으로
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	// delete function
	GameEngineArray(const GameEngineArray& _Ohter) = delete;
	GameEngineArray(GameEngineArray&& _Ohter) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		ArrCount = _Other.ArrCount;
		ArrPtr = _Other.ArrPtr;


		return *this;
	}

	size_t Count()
	{
		return ArrCount;
	}

	Datatype& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	void ReSize(int _Value)
	{
		// 기존의 할당된 배열을 섣불리 지우면 안됨
		// 기존의 있던 값에서 현재의 배열이 복사한 다음 삭제해야 한다.
		// 이전 배열을 지워버림 (Leak방지)
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = new Datatype[_Value];
		ArrCount = _Value;
	}
protected:

private:
	size_t ArrCount;
	Datatype* ArrPtr = nullptr;
};

