#pragma once

// ���� : ��� �⺻���� �ൿ�� �����ϴ� Ŭ����
// �����ϴ� Ŭ���� (���� : virtual�� ����ǵ�, �ڽ��� ���� ������ �� �������� ������)
class GameEngineLevel;
class GameEngineObject
{
	friend GameEngineLevel;
public:
	// constructer destructer
	GameEngineObject();
	~GameEngineObject();

	// delete function
	GameEngineObject(const GameEngineObject& _Ohter) = delete;
	GameEngineObject(GameEngineObject&& _Ohter) noexcept = delete;
	GameEngineObject& operator=(const GameEngineObject& _Other) = delete;
	GameEngineObject& operator=(GameEngineObject&& _Other) noexcept = delete;

	// �����ϰ�
	virtual void Start() {}

	// �ൿ�ϰ�
	virtual void Update(float _Delta) {}

	// �׷�����
	virtual void Render() {}

	// �����ȴ�
	virtual void Release() {}

	// UpdateValue�� true�� ����(������Ʈ�� �Ǵ� ��ü�� ����)
	void On()
	{
		IsUpdateValue = true;
	}

	// UpdateValue�� false�� ����(��ü�� ���̻� ������Ʈ ���� �ʵ���)
	void Off()
	{
		IsUpdateValue = false;
	}

	void Death()
	{
		IsDeathValue = true;
	}

	// ��ü�� UpdateValue�� true�̰�, DeathValue�� false�� ������Ʈ�� �ض�
	bool IsUpdate()
	{
		return true == IsUpdateValue && false == IsDeathValue;
	}

	virtual bool IsDeath()
	{
		return IsDeathValue;
	}

	void SetOrder(int _Order)
	{
		Order = _Order;
	}

	float GetLiveTime()
	{
		return LiveTime;
	}

	void ResetLiveTime()
	{
		LiveTime = 0.0f;
	}
protected:

private:
	int Order = 0;
	// ��ü�� ������Ʈ�� �Ǿ�� �ϴ��� �Ǻ��ϴ� ��
	bool IsUpdateValue = true;	// ����� ���� ������ false
	// ��ü�� �����ؾ� �ϴ��� �Ǻ��ϴ� ��
	bool IsDeathValue = false;	// �޸𸮿��� ���������� ������ true
	// �ش� ������Ʈ�� ����ִ� �ð��� üũ
	float LiveTime = 0.0f;

	void AddLiveTime(float _DeltaTime)
	{
		LiveTime += _DeltaTime;
	}
};

