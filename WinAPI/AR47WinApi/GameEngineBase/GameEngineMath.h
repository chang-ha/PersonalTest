#pragma once

class GameEngineMath
{
};

class float4
{
public:
	// 실수는 기본적으로 오차가 발생할 수 밖에 없음 (부동소수점계산방식)
	// 그래서 1.0f == 1.0f가 false가 될 수도있음 ( == 이 거의 불가능하다)
	// Player->GetPos() == Monster->GetPos() 하면 안될 가능성이 매우매우 높음
	float X;
	float Y;

	// Direct를 대비해서 미리 만든 변수임
	float Z;
	float W;

	// float X를 int X로 casting해서 리턴해주는 함수
	inline int iX() const
	{
		return static_cast<int>(X);
	}
	// float Y 를 int Y로 casting해서 리턴해주는 함수
	inline int iY() const
	{
		return static_cast<int>(Y);
	}

	// float X를 int X/2로 casting해서 리턴해주는 함수
	inline int ihX() const
	{
		return static_cast<int>(X * 0.5f);
	}

	// float Y를 int Y/2로 casting해서 리턴해주는 함수
	inline int ihY() const
	{
		return static_cast<int>(Y * 0.5f);
	}

	float4& operator+=(const float4& _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
		Z += _Other.Z;
		return *this;
	}

protected:

private:

};
