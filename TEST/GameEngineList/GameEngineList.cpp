// GameEngineList


// 숙제 1. push_front만들기
#include <iostream>
#include <list>
#include <crtdbg.h>
// 메모리는 연속되어있을떄 가장 빠릅니다 << 컴퓨터 친화적 코딩
// 벡터는 가장 빠른 자료구조 (메모리가 연속적)
// 그래서 할수있다면 최대한 벡터로 짜는게 좋다.
// 그치만 단점은
// 상황에 따른 너무나도 커질수 있는 재할당과 복사 연산의 위험성이 벡터의 문제점입니다.
// 10만개짜리 배열에서 10만 1개가 되는순간 재할당과 복사
// 그래서 사용하는게 리스트

// 리스트의 가장 큰 장점은 편의성
typedef int DataType;
class GameEngineList
{
public:
	class ListNode
	{
	public:
		ListNode* Prev = nullptr;
		ListNode* Next = nullptr;
		DataType Value = 0;

		~ListNode()
		{
			if (nullptr != Next)
			{
				delete Next;
				Next = nullptr;
			}
		}
	protected:

	private:
	};

	class iterator
	{
		friend GameEngineList;
	public:
		iterator()
		{

		}
		iterator(ListNode* _CurNode)
			:CurNode(_CurNode)
		{

		}
		bool operator !=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		iterator& operator ++()
		{
			CurNode = CurNode->Next;
			return *this;
		}

		DataType operator *()
		{
			return CurNode->Value;
		}
	protected:

	private:
		ListNode* CurNode = nullptr;
	};

	iterator begin()
	{
		return iterator(StartNode->Next);
	}
	iterator end()
	{
		return iterator(EndNode);
	}

	void push_back(const DataType& _Data)
	{
		ListNode* NewListNode = new ListNode();
		NewListNode->Value = _Data;

		// push_back이란 End노드의 Prev가 NewListNode
		// PrevNode의 Next가 NewListNode
		ListNode* PrevNode = EndNode->Prev;

		PrevNode->Next = NewListNode;
		EndNode->Prev = NewListNode;
		// NewListNode도 서로 연결해줘야함
		NewListNode->Next = EndNode;
		NewListNode->Prev = PrevNode;
	}

	void push_front(const DataType& _Data)
	{
		// push_back의 반대개념
		ListNode* NewListNode = new ListNode();
		NewListNode->Value = _Data;
		ListNode* NextNode = EndNode->Next;

		NextNode->Prev = NewListNode;
		StartNode->Next = NewListNode;
		NewListNode->Next = NextNode;
		NewListNode->Prev = StartNode;
	}

	iterator erase(iterator& _DeleteNode)
	{
		ListNode* DeleteNode = _DeleteNode.CurNode;

		ListNode* PrevNode = DeleteNode->Prev;
		ListNode* NextNode = DeleteNode->Next;

		DeleteNode->Prev = nullptr;
		DeleteNode->Next = nullptr;

		if (nullptr != DeleteNode)
		{
			delete DeleteNode;
			DeleteNode = nullptr;
		}

		PrevNode->Next = NextNode;
		NextNode->Prev = PrevNode;
		
		return iterator(NextNode);
	}
protected:

public:

	GameEngineList()
	{
		StartNode->Next = EndNode;
		EndNode->Prev = StartNode;
	}

	~GameEngineList()
	{
		if (nullptr != StartNode)
		{
			// 시작노드만 지울것임
			// 왜 시작노드만 지우냐?
			// 연쇄적으로 다른 노드들도 지워지게 기능을 만들것이기 때문에
			// ~ListNode() 참고

			// 재귀 방식.
			delete StartNode;
			StartNode = nullptr;
		}
	}

public:
	// 더미 노드
	// List의 시작과 끝을 알기위한 비어있는 노드를 만들어서
	// 해당 노드가 오면 시작인지 끝인지 알 수 있게 만듦
	// Start노드 - 데이터 - 데이터 - ... - End노드
	ListNode* StartNode = new ListNode();
	ListNode* EndNode = new ListNode();
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	{
		GameEngineList NewList;
		NewList.push_back(999);
		NewList.push_back(888);
		NewList.push_back(777);
		NewList.push_back(123123);

		// NewList[1]; << 바로 몇 번쨰 자료형에 접근하는 것을 제공하지 않음

		{
			// Delete(삭제) 오퍼레이터
			GameEngineList::iterator Delete = NewList.begin(); // 999를 가리킴
			++Delete; // 888를 가리킴

			NewList.erase(Delete); /// 888을 지움
		}
		// 노드는 어느 한 지점을 알아야 앞으로가든 뒤로가든 할 수 있음
		// 그치만 노드를 외부에 공개하면 사용자가 노드간의 연결을 끊고 그럴 수 있기 떄문에 공개하지 않고
		// 이를 외부에 보여주는 클래스가 있음 == iterator
		GameEngineList::iterator Start = NewList.begin();
		GameEngineList::iterator End = NewList.end();

		for (; Start != End; ++Start)
		{
			printf_s("%d\n", *Start);
		}
	}

	return 1;

	{
		std::list<int> NewList;
		NewList.push_back(999);
		NewList.push_back(888);
		NewList.push_back(777);
		NewList.push_back(123123);

		// NewList[1]; << 제공하지 않음

		// 노드는 어느 한 지점을 알아야 앞으로가든 뒤로가든 할 수 있음
		// 그래서 그것을 제공하는 클래스가 또 있음
		// 
		std::list<int>::iterator Start = NewList.begin();
		std::list<int>::iterator End = NewList.end();

		for (; Start != End; ++Start)
		{
			printf_s("%d\n", *Start);
		}
	}
}
