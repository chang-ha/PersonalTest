#include "GameEngineCamera.h"
#include <GameEngineBase/GameEngineDebug.h>

GameEngineCamera::GameEngineCamera()
{

}

GameEngineCamera::~GameEngineCamera()
{

}

void GameEngineCamera::PushRenderer(GameEngineRenderer* _Renderer, int _Order)
{
	if (nullptr == _Renderer)
	{
		MsgBoxAssert("nullptr인 Renderer를 카메라에 넣을 순 없습니다.");
	}
	Renderers[_Order].push_back(_Renderer);
}

// Camera가 가지고 있는 Renderer 중 상태가 Update인 애들을 Render돌려주는 함수
void GameEngineCamera::Render()
{
	std::map<int, std::list<GameEngineRenderer*>>::iterator GroupStartIter = Renderers.begin();
	std::map<int, std::list<GameEngineRenderer*>>::iterator GroupEndIter = Renderers.end();

	for (; GroupStartIter != GroupEndIter; ++GroupStartIter)
	{
		std::list<GameEngineRenderer*>& List = GroupStartIter->second;

		std::list<GameEngineRenderer*>::iterator RenderStartIter = List.begin();
		std::list<GameEngineRenderer*>::iterator RenderEndIter = List.end();
		for (; RenderStartIter != RenderEndIter; ++RenderStartIter)
		{
			GameEngineRenderer* Render = *RenderStartIter;
			if (false == Render->IsUpdate())
			{
				continue;
			}
			Render->Render(this);
		}
	}
}