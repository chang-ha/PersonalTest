#pragma once

class GameEngineMath
{
};

class float4
{
public:
	static const float4 ZERO;

	// �Ǽ��� �⺻������ ������ �߻��� �� �ۿ� ���� (�ε��Ҽ��������)
	// �׷��� 1.0f == 1.0f�� false�� �� �������� ( == �� ���� �Ұ����ϴ�)
	// Player->GetPos() == Monster->GetPos() �ϸ� �ȵ� ���ɼ��� �ſ�ſ� ����
	float X = 0.0f;
	float Y = 0.0f;

	// Direct�� ����ؼ� �̸� ���� ������
	float Z = 0.0f;
	float W = 1.0f;

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

	inline float hX() const
	{
		return X * 0.5f;
	}

	inline float hY() const
	{
		return Y * 0.5f;
	}

	// float X�� int X/2�� casting�ؼ� �������ִ� �Լ�
	inline int ihX() const
	{
		return static_cast<int>(hX());
	}

	// float Y�� int Y/2�� casting�ؼ� �������ִ� �Լ�
	inline int ihY() const
	{
		return static_cast<int>(hY());
	}

	inline float4 Half() const
	{
		return {hX(), hY(), Z, W};
	}

	float4 operator+(const float4& _Other)
	{
		float4 ReturnValue;
		ReturnValue.X = X + _Other.X;
		ReturnValue.X = Y + _Other.Y;
		ReturnValue.X = Z + _Other.Z;
		return ReturnValue;
	}

	float4 operator-(const float4& _Other)
	{
		float4 ReturnValue;
		ReturnValue.X = X - _Other.X;
		ReturnValue.X = Y - _Other.Y;
		ReturnValue.X = Z - _Other.Z;
		return ReturnValue;
	}

	float4 operator*(const float4& _Other)
	{
		float4 ReturnValue;
		ReturnValue.X = X * _Other.X;
		ReturnValue.X = Y * _Other.Y;
		ReturnValue.X = Z * _Other.Z;
		return ReturnValue;
	}

	float4 operator*(const float _Value)
	{
		float4 ReturnValue;
		ReturnValue.X = X * _Value;
		ReturnValue.X = Y * _Value;
		ReturnValue.X = Z * _Value;
		return ReturnValue;
	}

	float4& operator+=(const float4& _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
		Z += _Other.Z;
		return *this;
	}

	float4& operator-=(const float4& _Other)
	{
		X -= _Other.X;
		Y -= _Other.Y;
		Z -= _Other.Z;
		return *this;
	}

	float4& operator*=(const float4& _Other)
	{
		X *= _Other.X;
		Y *= _Other.Y;
		Z *= _Other.Z;
		return *this;
	}

	float4& operator*=(const float _Value)
	{
		X *= _Value;
		Y *= _Value;
		Z *= _Value;
		return *this;
	}



protected:

private:

};
