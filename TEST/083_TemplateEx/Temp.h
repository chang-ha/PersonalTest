#pragma once


// template�Լ��� Ŭ���� ������� ������ ��ȿ�ϴ�
// �ֳ�??? ��Ȯ�� template�Լ��� ���� �����Ǵ��� �˾ƾ���
// template�Լ��� ġȯ�����̶�� �Ͽ���
// "template�Լ��� main���� �Լ��� ������ ����"
// "main�Լ� ���� ��������Ե�"
// �׷��� cpp���� �����ϴ°� ������ �ȵ� (main�Ʒ��� ����)
template<typename DataType>
class Temp
{
public:
	// constructer destructer
	Temp() {}
	~Temp() {}

	// delete function
	Temp(const Temp& _Ohter) = delete;
	Temp(Temp&& _Ohter) noexcept = delete;
	Temp& operator=(const Temp& _Other) = delete;
	Temp& operator=(Temp&& _Other) noexcept = delete;

	void Function(DataType _Data)
	{

	}

protected:

private:

};

