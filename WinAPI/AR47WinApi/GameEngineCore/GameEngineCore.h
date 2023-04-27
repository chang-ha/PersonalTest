#pragma once
#include <string>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <map>

// ���漱��
class GameEngineLevel;
class GameEngineCore
{
public:
	// constructer destructer
	GameEngineCore();
	~GameEngineCore();

	// delete function
	GameEngineCore(const GameEngineCore& _Ohter) = delete;
	GameEngineCore(GameEngineCore&& _Ohter) noexcept = delete;
	GameEngineCore& operator=(const GameEngineCore& _Other) = delete;
	GameEngineCore& operator=(GameEngineCore&& _Other) noexcept = delete;

	// ���α׷��� �����ϴ� �Լ�
	static void EngineStart(const std::string& _Title, HINSTANCE _Inst);

	// ���������� Level�� ��������� �Լ�
	template<typename LevelType>
	static void CreateLevel(const std::string& _Name)
	{
		// ��� ���ڿ��� �빮�ڷ� �Ͽ� ������ ���� (�ҹ���, �빮�� ǥ�� ������ ����)
		std::string Upper = GameEngineString::ToUpperReturn(_Name);

		// �̹� �ش� Level�� �����ϹǷ� ���� Create�Ұ���
		if (AllLevel.end() != AllLevel.find(Upper))
		{
			MsgBoxAssert(Upper + "�� �̸��� ���� GameEngineLevel�� �̹� �����մϴ�.");
			return;
		}

		GameEngineLevel* NewLevel = new LevelType();
		AllLevel.insert(std::make_pair(Upper, NewLevel));
	}
protected:

private:
	// ���ο��� Title���� ������ ��, �ش� Title���� ������ WindowTitle(static ����) ����
	static std::string WindowTitle;

	// ���α׷��� ����Ǹ� ó�� �ؾ��� �ϵ��� ����
	static void CoreStart(HINSTANCE _Inst);
	// ���α׷��� �ǽð� ������Ʈ�� �Ͼ���� �ϵ��� ����
	static void CoreUpdate();
	// ���α׷��� ������ �������ؾ��� �ϵ��� ����(�޸� ���� ��)
	static void CoreEnd();
	// ��� ������ Level�� ������ map���� �ڷᱸ�� ����
	static std::map<std::string, GameEngineLevel*> AllLevel;
};

