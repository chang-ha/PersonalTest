#include "Player.h"
#include <Windows.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineBase/GameEnginePath.h>


Player::Player()
{

}

Player::~Player()
{

}

void Player::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("Player.Idel.Bmp"))
	{
		// 얘는 무조건 자동으로 현재 실행중인 위치로 설정
		GameEnginePath FilePath;

		FilePath.GetCurrentPath();

		ResourcesManager::GetInst().TextureLoad("Player.Idel.Bmp");
	}
	SetPos({ 200, 200 });
	SetScale({100, 100});
}

void Player::Update(float _Delta)
{
	// 초당 프레임 : 1.0f(1초) / _Delta
	AddPos({100.0f * _Delta, 0.0f});
}

void Player::Render()
{
	HDC WindowDC = GameEngineWindow::MainWindow.GetHDC();
	Rectangle(WindowDC,
		GetPos().iX() - GetScale().ihX(),
		GetPos().iY() - GetScale().ihY(),
		GetPos().iX() + GetScale().ihX(),
		GetPos().iY() + GetScale().ihY()
	);
}

void Player::Release()
{

}