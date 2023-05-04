#pragma once

// ���� : ��� �⺻���� �ൿ�� �����ϴ� Ŭ����
// �����ϴ� Ŭ���� (���� : virtual�� ����ǵ�, �ڽ��� ���� ������ �� �������� ������)
class GameEngineObject
{
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

	// ��ü�� UpdateValue�� true�̰�, DeathValue�� false�� ������Ʈ�� �ض�
	bool IsUpdate()
	{
		return true == IsUpdateValue && false == IsDeathValue;
	}

	bool IsDeath()
	{
		return IsDeathValue;
	}
protected:

private:
	// ��ü�� ������Ʈ�� �Ǿ�� �ϴ��� �Ǻ��ϴ� ��
	bool IsUpdateValue = true;	// ����� ���� ������ false
	// ��ü�� �����ؾ� �ϴ��� �Ǻ��ϴ� ��
	bool IsDeathValue = false;	// �޸𸮿��� ���������� ������ true
};

