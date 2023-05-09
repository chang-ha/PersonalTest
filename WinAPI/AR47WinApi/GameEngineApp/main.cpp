// 윈도우 프로그램을 만들기위한 시작 설정 (exe파일생성 프로젝트만 해당)
// 프로젝트 설정 << 링커 << 시스템 << 하위 시스템(콘솔 -> 창)

// 빌드 결과 위치 바꾸는 설정 << "경로 마지막에 무조건 \ 붙여야함!! 아니면 열 수 없는 파일이라고 에러 발생"
// 프로젝트 설정 << 출력 디렉토리 or 중간 디렉토리 << 아래 화살표 눌러서 편집으로 원하는 경로로 편집

// 종속성 설정
// 솔루션 프로젝트 설정 << 종속성 설정 << 나의 상위 Level은 다 종속성 체크 해줘야함

// 다중 프로세서 컴파일
// 프로젝트 설정 << C/C++ << 일반 << 아래의 다중 프로세서 컴파일
// 멀티코어 사용해서 빌드해주는 옵션

// 왜 터지는지 모르면 해당 단계를 따라가야함(빌드는 되었을 때, 문법적 오류 x)
// 그럴땐 Bin 한번 지우고 다시 빌드해보기 << 100의 99는 내 잘못임 (아주 가끔 vs버그로 인해 그럴 수 있으니 시도는 해보자)


#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineContents/ContentCore.h>


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	GameEngineCore::EngineStart<ContentCore>("MyWindow", hInstance);
	return 0;
}
