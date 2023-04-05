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
		// �����ڿ��� ������� �迭�� �Ҹ��ڿ��� �����Ѵ�
		// ������ ���� �������
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
		// ������ �Ҵ�� �迭�� ���Ҹ� ����� �ȵ�
		// ������ �ִ� ������ ������ �迭�� ������ ���� �����ؾ� �Ѵ�.
		// ���� �迭�� �������� (Leak����)
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

