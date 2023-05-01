#pragma once
#include <string>
#include <map>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEngineDebug.h>
#include "GameEngineObject.h"
// �����츦 ���� �����ϴ� ���̺귯��
// ����ڰ� ���� hInstance�� �޾Ƽ� ��¼��... �� �ʿ䰡 ����
// ������ �� �� �����츦 ����ڰ� ���� �����ؾ� �ϴ� ���� ����

// ���� ���忡���� ������ ���� ������ �������� �� ���� ����(�׷��ٰ� �������κ��� �˸� �ȵ�)
// �Լ�������(Virtual�Լ�)�� �ذ��� ����
// Content �κ��� ���� �� CoreProcess�� ��ӹ޾Ƽ� �����
// Content�κп��� ���� �Լ��� �����κ�(Core)���� ��� ȣ�����ٰ�
class CoreProcess : public GameEngineObject
{
	// GameEngineObject��
	// 1. Start, 2. Update, 3.Render, 4.Release �����Լ����� ��������Ƿ�
	// �ڽ�Ŭ�������� �� �Լ����� ������ ����
};

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
	template <typename CoreProcessType>
	static void EngineStart(const std::string& _Title, HINSTANCE _Inst)
	{
		//
		EngineStart(_Title, _Inst, new CoreProcessType());
	}

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
		
		// ���ο� Level(���)�� �����, �ʱ�ȭ���� map�� insert
		GameEngineLevel* NewLevel = new LevelType();
		// NewLevel->Start()�� �ϰ������, Level�� ����� �𸣰��ϱ� ����
		// LevelInit�Լ��� ���� Start()�� ȣ��
		LevelInit(NewLevel);
		AllLevel.insert(std::make_pair(Upper, NewLevel));
	}

	// Level(���)�� ��ȯ�ϱ� ���� �Լ�
	static void ChangeLevel(const std::string& _Name)
	{
		std::string Upper = GameEngineString::ToUpperReturn(_Name);
		std::map<std::string, GameEngineLevel*>::iterator Finditer = AllLevel.find(Upper);

		if (AllLevel.end() == Finditer)
		{
			MsgBoxAssert(Upper + "�� �̸��� ���� GameEngineLevel�� �������� �ʽ��ϴ�.");
			return;
		}

		NextLevel = Finditer->second;
	}
protected:

private:
	// ���ο��� Title���� ������ ��, �ش� Title���� ������ WindowTitle(static ����) ����
	static std::string WindowTitle;
	static CoreProcess* Process;

	// Level�� Start()�� ȣ���ϱ� ���� �Լ�
	static void LevelInit(GameEngineLevel* _Level);
	// CoreProcessŬ������ �����Ͱ��� �־������
	static void EngineStart(const std::string& _Title, HINSTANCE _Inst, CoreProcess* _Ptr);
	// ���α׷��� ����Ǹ� ó�� �ؾ��� �ϵ��� ����
	static void CoreStart(HINSTANCE _Inst);
	// ���α׷��� �ǽð� ������Ʈ�� �Ͼ���� �ϵ��� ����
	static void CoreUpdate();
	// ���α׷��� ������ �������ؾ��� �ϵ��� ����(�޸� ���� ��)
	static void CoreEnd();
	// ��� ������ Level�� ������ map���� �ڷᱸ�� ����
	static std::map<std::string, GameEngineLevel*> AllLevel;
	static GameEngineLevel* CurLevel;
	static GameEngineLevel* NextLevel;
};

