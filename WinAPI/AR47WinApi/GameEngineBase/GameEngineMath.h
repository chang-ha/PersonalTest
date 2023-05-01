#pragma once

class GameEngineMath
{
};

class float4
{
public:
	float X;
	float Y;

	// Direct�� ����ؼ� �̸� ���� ������
	float Z;
	float W;

	// float X�� int X�� casting�ؼ� �������ִ� �Լ�
	inline int iX() const
	{
		return static_cast<int>(X);
	}
	// float Y �� int Y�� casting�ؼ� �������ִ� �Լ�
	inline int iY() const
	{
		return static_cast<int>(Y);
	}

	// float X�� int X/2�� casting�ؼ� �������ִ� �Լ�
	inline int ihX() const
	{
		return static_cast<int>(X * 0.5f);
	}

	// float Y�� int Y/2�� casting�ؼ� �������ִ� �Լ�
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
