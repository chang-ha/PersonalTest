// GameEngineNode


#include <iostream>
#include <GameEngineConsole/GameEngineArray.h>
#include <conio.h>
// 노드 형태라고 부르는 굉장히 많이 사용되는 방식이 존재한다.
// 어떤 클래스가 자신 내부에 자기 자신의 참조형(보통은 포인터)을 n개 들고 있으면
// 그걸 노드형식이라고 합니다.

// 노드는 2가지 형태가 존재
// 1. 선형
// 2. 트리형


class MapZone
{
public:
	MapZone* SelectNext()
	{
		system("cls");
		printf_s("현재 이곳은 %s 입니다.\n", GetName());
		printf_s("어디로 가시겠습니까?\n");

		for (int i = 0; i < LinkZone.Count(); i++)
		{
			printf_s("%d. %s\n", i + 1, LinkZone[i]->GetName());
		}

		int Select = _getch();
		int SelectIndex = Select - '1';
		if (SelectIndex >= LinkZone.Count())
		{
			return this;
		}
		
		return LinkZone[SelectIndex];
	}

	const char* GetName()
	{
		return Name;
	}

	void SetName(const char* _Name)
	{
		Name = _Name;
	}

	void Link(MapZone* _OtherZone)
	{
		if (nullptr == _OtherZone)
		{
			return;
		}

		LinkZone.ReSize(LinkZone.Count() + 1);
		LinkZone[LinkZone.Count() - 1] = _OtherZone;

		_OtherZone->LinkZone.ReSize(_OtherZone->LinkZone.Count() + 1);
		_OtherZone->LinkZone[_OtherZone->LinkZone.Count() - 1] = this;
	}
protected:

private:
	const char* Name = nullptr;
	GameEngineArray<MapZone*> LinkZone;

};

typedef int DataType;
class Node
{
public:
	Node(const DataType& _Value)
		: Value(_Value)
	{

	}

	DataType GetValue()
	{
		return Value;
	}

	Node* GetNext()
	{
		return Next;
	}

	Node* GetPrev()
	{
		return Prev;
	}

	void NextLinkPointer(Node* _Next)
	{
		Next = _Next;
		_Next->Prev = this;
	}

	void NextLinkRef(Node& _Next)
	{
		Next = &_Next;
		_Next.Prev = this;
	}
protected:

private:
	// 단방향 노드
	Node* Next = nullptr;
	// 쌍방향 노드
	Node* Prev = nullptr;
	DataType Value;
};
int main()
{
	{
		Node Node1 = 0;
		Node Node2 = 1;
		Node Node3 = 2;
		Node Node4 = 3;
		Node Node5 = 4;

		Node1.NextLinkPointer(&Node2);
		Node2.NextLinkPointer(&Node3);
		Node3.NextLinkPointer(&Node4);
		Node4.NextLinkPointer(&Node5);

		Node* CurNode = &Node5;
		while (nullptr != CurNode)
		{
			printf_s("%d\n", CurNode->GetValue());
			CurNode = CurNode->GetPrev();
		}
		return 1;
	}
	{
		// 맵의 한 지역
		// 다크소울2로 예시
		// 하이데의 폐허에서는
		// 1. 청의 성당
		// 2. 하이데의 큰 불탑
		// 3. 매듀라로 갈 수 있음
		// MapZone에서 다른 맵으로 갈 수 있는 참조가 3개 존재

		// 100번지
		MapZone Map1;
		// 200번지
		MapZone Map2;
		// 300번지
		MapZone Map3;
		// 400번지
		MapZone Map4;
		// 500번지
		MapZone Map5;

		// 맵끼리 서로 연결해줌
		Map1.SetName("하이데의 폐허");
		Map2.SetName("청의성당");
		Map3.SetName("매듀라");
		Map4.SetName("하이데의 큰 불탑");
		Map5.SetName("숨겨진 항구");

		Map1.Link(&Map2);
		Map1.Link(&Map4);
		Map1.Link(&Map3);
		Map2.Link(&Map5);

		MapZone* CurMap = &Map1;
		while (nullptr != CurMap)
		{
			CurMap = CurMap->SelectNext();
		}
	}
}