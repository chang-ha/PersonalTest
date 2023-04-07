#pragma once

//typedef int DataType;
#include <GameEngineBase/GameEngineDebug.h>

template <typename DataType>
class GameEngineArray
{
public:
	// delete function
	GameEngineArray(const GameEngineArray& _Ohter) = delete;
	GameEngineArray(GameEngineArray&& _Ohter) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;

	// constructer destructer
	GameEngineArray(size_t _Value)
		: ArrPtr(new DataType[_Value])
		, ArrCount(_Value)
	{
		if (0 >= _Value)
		{
			MsgBoxAssert("크기가 0인 배열은 만들수 없습니다");
		}
	}

	~GameEngineArray()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	size_t Count()
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index) const
	{
		return ArrPtr[_Index];
	}

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		ReSize(_Other.ArrCount);
		for (size_t i = 0; i < _Other.ArrCount; i++)
		{
			ArrPtr[i] = _Other[i];
		}
		return *this;
	}


	void ReSize(int _Count)
	{
		DataType* NewPtr = new DataType[_Count];
		int CopySize = _Count < ArrCount ? _Count : ArrCount;

		for (size_t i = 0; i < CopySize; i++)
		{
			NewPtr[i] = ArrPtr[i];
		}

		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
		ArrPtr = NewPtr;
		ArrCount = _Count;
	}


protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;
};