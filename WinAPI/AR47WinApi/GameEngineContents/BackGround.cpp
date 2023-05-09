#include "BackGround.h"
#include <GameEngineCore/ResourcesManager.h>
#include <GameEnginePlatform/GameEngineWindow.h>

// TransCopy 내부의 " " 함수를 사용하기 위해 lib를 불러와야함
#pragma comment(lib, "msimg32.lib")

BackGround::BackGround()
{

}

BackGround::~BackGround()
{

}

void BackGround::Start()
{
	SetPos({680, 384});
}

void BackGround::Update(float _Delta)
{

}
void BackGround::Render()
{
	// 윈도우창의 DC (캔버스)
	GameEngineWindowTexture* BackBuffer = GameEngineWindow::MainWindow.GetBackBuffer();
	// 윈도우창에 그릴 DC
	GameEngineWindowTexture* FindTexture = ResourcesManager::GetInst().FindTexture(FileName);

	if (nullptr == FindTexture)
	{
		return;
	}
	// { 1360, 768 });
	// 윈도우창의 DC에 Load한 Texture을 복사
	float4 TestScale = GetScale();
	TestScale.X *= 0.71f;
	TestScale.Y *= 0.65f;
	//             BackBuffer에 그리려는 위치        크기  / 이미지의 시작위치, 크기
	BackBuffer->TransCopy(FindTexture, GetPos(), TestScale, {0, 0}, FindTexture->GetScale(), (255, 0, 255));
}

void BackGround::Release()
{

}

void BackGround::Init(const std::string& _FileName)
{
	FileName = _FileName;

	if (false == ResourcesManager::GetInst().IsLoadTexture(FileName))
	{
		GameEnginePath FilePath;
		FilePath.GetCurrentPath();
		FilePath.MoveParentToExistsChild("Resources");
		FilePath.MoveChild("Resources\\Player\\" + FileName);
		GameEngineWindowTexture* Text = ResourcesManager::GetInst().TextureLoad(FilePath.GetStringPath());
		float4 Scale = Text->GetScale();
		// Scale.X *= 5.0f;
		// Scale.Y *= 5.0f;
		SetScale(Scale);
	}
}
