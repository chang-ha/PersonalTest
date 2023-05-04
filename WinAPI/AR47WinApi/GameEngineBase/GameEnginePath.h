#pragma once
#include <string>
#include <filesystem> // C++ 17���� �̻󿡼��� ��밡��

// �����δ� ���� ���� ����
// ��ġ�ϴ� ȯ���� ������� �ٸ��� ������ 
class GameEnginePath
{
public:
	// constructer destructer
	GameEnginePath();
	~GameEnginePath();

	// delete function
	GameEnginePath(const GameEnginePath& _Ohter) = delete;
	GameEnginePath(GameEnginePath&& _Ohter) noexcept = delete;
	GameEnginePath& operator=(const GameEnginePath& _Other) = delete;
	GameEnginePath& operator=(GameEnginePath&& _Other) noexcept = delete;

	// ���� �������� ������ ��θ� return���ִ� �Լ�
	void GetCurrentPath();
protected:

private:
	std::filesystem::path Path;
};

