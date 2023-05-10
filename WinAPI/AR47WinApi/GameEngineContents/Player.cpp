#include "Player.h"
#include "ContentsEnum.h"
#include <Windows.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineWindowTexture.h>
#include <GameEngineCore/ResourcesManager.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>

Player::Player()
{

}

Player::~Player()
{
}

void Player::Start()
{
	if (false == ResourcesManager::GetInst().IsLoadTexture("Player.Bmp"))
	{
		// 얘는 무조건 자동으로 현재 실행중인 위치로 설정 (Debug모드면 app폴더, Release모드면 bin폴더 안의 exe파일이 있는 곳)
		GameEnginePath FilePath;
		// 현재 파일이 실행되고 있는 경로를 return해주는 함수
		FilePath.GetCurrentPath();
		// Resources 폴더가 있는 경로까지 이동 << Resources폴더 안으로 이동한게 아님 XXX
		FilePath.MoveParentToExistsChild("Resources");
		// 해당 경로에서 원하는 파일까지 이동
		FilePath.MoveChild("Resources\\Player\\");
		
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Player.Bmp"));
		ResourcesManager::GetInst().TextureLoad(FilePath.PlusFilePath("Player_arm.Bmp"));
	}	


	{
		GameEngineRenderer* Ptr = CreateRenderer("Player.Bmp", RenderOrder::Play);
		Ptr->SetRenderScale({ 200, 200 });
		Ptr->SetTexture("Player.Bmp");
	}

	{
		GameEngineRenderer* Ptr = CreateRenderer("Player_arm.Bmp", RenderOrder::Play);
		Ptr->SetRenderPos({ 0, -100 });
		Ptr->SetRenderScale({ 200, 40 });
		Ptr->SetTexture("Player_arm.Bmp");
	}

	float4 WinScale = GameEngineWindow::MainWindow.GetScale();
	// GetLevel()->GetMainCamera()->SetPos({ -WinScale.hX(), -WinScale.hY() });
	SetPos(WinScale.Half());
}

void Player::Update(float _Delta)
{
	float Speed = 200.0f;
	float4 MovePos = float4::ZERO;
	if (0 != GetAsyncKeyState('A')) // 0이 아니라면 키가 눌린 것
	{
		MovePos = { - Speed * _Delta, 0.0f};
	}

	if (0 != GetAsyncKeyState('D'))
	{
		MovePos = {Speed * _Delta, 0.0f };
	}

	if (0 != GetAsyncKeyState('W'))
	{
		MovePos = { 0.0f, -Speed * _Delta};
	}

	if (0 != GetAsyncKeyState('S'))
	{
		MovePos = { 0.0f, Speed * _Delta};
	}
	AddPos(MovePos);
	GetLevel()->GetMainCamera()->AddPos(MovePos);
}

void Player::Render()
{
	// 내가 띄운 윈도우창에 그림을 그릴 권한
	// HDC WindowDC = GameEngineWindow::MainWindow.GetHDC();

	// HDC를 숨기기 위해 (인터페이스의 통일을 위해) Window의 HDC를 받는 BackBuffer를 GameEngineWindowTexture형식으로 저장
	// GameEngineWindowTexture* BackBuffer = GameEngineWindow::MainWindow.GetBackBuffer();

	// AllTexture에 "Title_background.bmp"가 저장되어있는지 확인 
	// GameEngineWindowTexture* FindTexture = ResourcesManager::GetInst().FindTexture("Player.Bmp");

	// 
	// BackBuffer->TransCopy(FindTexture, GetPos(), GetScale(), { 0, 0 }, FindTexture->GetScale());
	// 위에서 찾아온 "Title_background.bmp"의 HDC핸들을 return
	// HDC ImageDC = FindTexutre->GetImageDC();

	// BitBlt
	// 특정 DC(ImageDC)에 연결된 색상을
	// 특정 DC(WindowDC)에 고속복사하는 함수
	// BitBlt(WindowDC, 0, 0, 1920, 1200, ImageDC, 0, 0, SRCCOPY);
}

void Player::Release()
{

}