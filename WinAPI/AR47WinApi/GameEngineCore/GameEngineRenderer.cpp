#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineWindowTexture.h>

#include "GameEngineRenderer.h"
#include "ResourcesManager.h"
#include "GameEngineActor.h"
#include "GameEngineCamera.h"

GameEngineRenderer::GameEngineRenderer()
{

}

GameEngineRenderer::~GameEngineRenderer()
{

}

void GameEngineRenderer::SetTexture(const std::string& _Name)
{
	Texture = ResourcesManager::GetInst().FindTexture(_Name);
	if (nullptr == Texture)
	{
		MsgBoxAssert(_Name + "존재하지 않는 텍스쳐를 로드하려고 했습니다.");
	}

	// 복사하려는 이미지의 복사를 시작할 위치를 0,0 으로 설정
	SetCopyPos(float4::ZERO);
	// 복사하려는 이미지의 복사크기를 기본 Texture크기로 설정
	SetCopyScale(Texture->GetScale());

	if (false == ScaleCheck)
	{
		// Scale이 바뀐적이 없으면 Render하는 Scale값을 기본 Texture크기로 설정
		SetRenderScaleToTexture();
	}
}

void GameEngineRenderer::SetRenderScaleToTexture()
{
	RenderScale = Texture->GetScale();
	ScaleCheck = false;
}

void GameEngineRenderer::Render(GameEngineCamera* _Camera)
{
	if (nullptr == Texture)
	{
		MsgBoxAssert("이미지를 세팅하지 않는 Renderer를 Render할 수 없습니다.");
	}

	GameEngineWindowTexture* BackBuffer = GameEngineWindow::MainWindow.GetBackBuffer();
	// 그리려는 Texture
	// 해당 Rednerer의 주인의 Pos + 거기서 얼마나 떨어져 있나(RenderPos)
	// Render하려는 크기는 얼마나인가?
	// 그리려는 Texture의 어느 Pos부터 얼마나 Scale만큼 그릴것인가
	BackBuffer->TransCopy(Texture, Master->GetPos() + RenderPos - _Camera->GetPos(), RenderScale, CopyPos, CopyScale);
}