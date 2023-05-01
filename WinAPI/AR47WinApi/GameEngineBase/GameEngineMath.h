#pragma once

class GameEngineMath
{
};

class float4
{
public:
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
