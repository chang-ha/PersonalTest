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
	GameEnginePath(const std::string& _Path);
	~GameEnginePath();	

	// delete function
	GameEnginePath(const GameEnginePath& _Ohter) = delete;
	GameEnginePath(GameEnginePath&& _Ohter) noexcept = delete;
	GameEnginePath& operator=(const GameEnginePath& _Other) = delete;
	GameEnginePath& operator=(GameEnginePath&& _Other) noexcept = delete;

	// ���� �������� ������ ��θ� return���ִ� ����Լ�
	void GetCurrentPath();

	// ���� ��ο��� ���� ������ �̵��ϴ� ����Լ�
	void MoveParent();

	// ���ϴ� ������ ���� ������ ���� �� ���� ���� ������ �̵��ϴ� ����Լ�
	void MoveParentToExistsChild(const std::string& _ChildPath);

	// ���� ��ο� �ִ� ���ϴ� ���� �Ǵ� ���Ϸ� ��θ� �������ִ� ����Լ�
	void MoveChild(const std::string& _ChildPath);

	std::string PlusFilePath(const std::string& _ChildPath);

	// path Ŭ���� ���ο� �ִ� ��ΰ��� string���� return���ִ� ����Լ�
	std::string GetStringPath()
	{
		return Path.string();
	}

	// ��θ� ������ ���� �̸��� �޴� ����Լ�
	std::string GetFileName();
protected:

private:
	// ��θ� �����ϴ� �������
	std::filesystem::path Path;
};

