#pragma once
#include <GameEngineBase/GameEngineDebug.h>

template <typename KeyType, typename ValueType>
class GameEnginepair
{
public:
	KeyType first;
	ValueType second;
	GameEnginepair()
	{

	}
	GameEnginepair(const KeyType& _Key, const ValueType& _Value)
		:first(_Key), second(_Value)
	{

	}
};

template<typename KeyType, typename ValueType>
class GameEngineMap
{
public:
	class MapNode
	{
	public:
		MapNode* Parent = nullptr;
		MapNode* LeftChild = nullptr;
		MapNode* RightChild = nullptr;
		GameEnginepair<KeyType, ValueType> Pair;

		bool IsLeaf()
		{
			return nullptr == LeftChild && nullptr == RightChild;
		}

		void ChangeChild(MapNode* _OldChild, MapNode* _NewChild)
		{
			if (_OldChild == LeftChild)
			{
				LeftChild = _NewChild;
				if (nullptr != _NewChild)
				{
					_NewChild->Parent = this;
				}
				return;
			}

			if (_OldChild == RightChild)
			{
				RightChild = _NewChild;
				if (nullptr != _NewChild)
				{
					_NewChild->Parent = this;
				}
				return;
			}
		}

		MapNode* OverParentNode()
		{
			MapNode* ParentNode = Parent;

			while (Pair.first > ParentNode->Pair.first)
			{
				ParentNode = ParentNode->Parent;
				if (nullptr == ParentNode)
				{
					return nullptr;
				}
			}
			return ParentNode;
		}

		MapNode* rOverParentNode()
		{
			MapNode* ParentNode = Parent;

			while (Pair.first < ParentNode->Pair.first)
			{
				ParentNode = ParentNode->Parent;
				if (nullptr == ParentNode)
				{
					return nullptr;
				}
			}
			return ParentNode;
		}

		MapNode* MinNode()
		{
			if (nullptr == LeftChild)
			{
				return this;
			}
			return LeftChild->MinNode();
		}

		MapNode* MaxNode()
		{
			if (nullptr == RightChild)
			{
				return this;
			}
			return RightChild->MaxNode();
		}

		MapNode* NextNode()
		{
			if (nullptr != RightChild)
			{
				// 오른쪽 자식이 있다면 오른쪽 자식의 MinNode(가장 작은 Key)
				return RightChild->MinNode();
			}
			if (nullptr != Parent)
			{
				// 오른쪽 자식이 없다면 부모노드로
				// 부모노드로 갈 떄 나보다 Key값이 큰 부모노드를 찾을 떄 까지 순회
				return OverParentNode();
			}
			// 오른쪽 노드도 없고 나보다 큰 Key값을 가진 노드가 없으면 해당 map구조의 MaxNode임
			// MaxNode의 다음노드는 nullptr(end)
			return nullptr;
		}

		MapNode* PrevNode()
		{
			if (nullptr != LeftChild)
			{
				return LeftChild->MaxNode();
			}
			if (nullptr != Parent)
			{
				return rOverParentNode();
			}
			return nullptr;
		}

		bool insert(MapNode* _NewNode)
		{
			// 새로 들어온 노드의 Key값이 Root노드의 Key값보다 작으면 왼쪽자식으로
			if (Pair.first > _NewNode->Pair.first)
			{
				if (nullptr != LeftChild)
				{
					// 왼쪽자식이 이미 있다면 insert 재귀
					return LeftChild->insert(_NewNode);
				}
				LeftChild = _NewNode;
				// 새로 들어온 Node의 부모노드는 현재 함수를 호출중인 노드
				_NewNode->Parent = this;
				return true;
			}
			// 새로 들어온 노드의 Key값이 Root노드의 Key값보다 크면 오른쪽자식으로
			else if (Pair.first < _NewNode->Pair.first)
			{
				if (nullptr != RightChild)
				{
					// 오른쪽자식이 이미 있다면 insert 재귀
					return RightChild->insert(_NewNode);
				}
				RightChild = _NewNode;
				// 새로 들어온 Node의 부모노드는 현재 함수를 호출중인 노드
				_NewNode->Parent = this;
				return true;
			}
			// 새로 들어온 노드의 Key값와 동일한 Key값을 가진 노드가 이미 맵에 존재함
			return false;
		}

		MapNode* find(KeyType _Key)
		{
			if (Pair.first > _Key)
			{
				if (nullptr != LeftChild)
				{
					// Key값이 현재 노드의 Key값보다 작으면 왼쪽으로
					return LeftChild->find(_Key);
				}
				// 왼쪽자식이 nullptr이면 못찾은 것이니 nullptr
				return nullptr;
			}
			else if (Pair.first < _Key)
			{
				if (nullptr != RightChild)
				{
					// Key값이 현재 노드의 Key값보다 크면 오른쪽으로
					return RightChild->find(_Key);
				}
				// 오른쪽자식이 nullptr이면 못찾은 것이니 nullptr
				return nullptr;
			}
			// 같으면 함수를 호출중인 노드의 iterator를 리턴
			return this;
		}

		void FirstOrder()
		{
			// 전위순회 : 어떤 작업을 한 뒤 순회를 돔 (루트부터 작업을 해 나감)
			std::cout << Pair.first << std::endl;
			if (nullptr != LeftChild)
			{
				LeftChild->FirstOrder();
			}
			if (nullptr != RightChild)
			{
				RightChild->FirstOrder();
			}
		}

		void MidOrder()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->MidOrder();
			}
			// 중위순회 : 순회를 도는 중간에 어떤 작업을 함 (왼쪽or오른쪽 자식을 작업 함 > 루트노드 작업 > 나머지 자식 작업)
			std::cout << Pair.first << std::endl;
			if (nullptr != RightChild)
			{
				RightChild->MidOrder();
			}
		}

		void LastOrder()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->LastOrder();
			}
			if (nullptr != RightChild)
			{
				RightChild->LastOrder();
			}
			// 후위순회 : 순회를 전부 돈 다음 어떤 작업을 함 (리프노드부터 작업 > 부모노드로 올라가면서 마지막엔 루트노드 작업)
			std::cout << Pair.first << std::endl;
		}

		~MapNode()
		{
			if (nullptr != LeftChild)
			{
				delete LeftChild;
				LeftChild = nullptr;
			}
			if (nullptr != RightChild)
			{
				delete RightChild;
				RightChild = nullptr;
			}
			std::cout << "지워진 녀석 : " << Pair.first << std::endl;
		}
	};

	class iterator
	{
		friend GameEngineMap;
	public:
		iterator()
		{

		}

		iterator(class MapNode* _Node)
			: Node(_Node)
		{

		}

		GameEnginepair<KeyType, ValueType>* operator->()
		{
			return &Node->Pair;
		}

		bool operator==(const iterator& _Other) const
		{
			return Node == _Other.Node;
		}

		bool operator!=(const iterator& _Other) const
		{
			return Node != _Other.Node;
		}

		iterator& operator++()
		{
			// ++연산자 == 내 다음 노드를 가리켜야함
			// 내 다음 노드는??? 내 RightChild의 MinNode()
			// 만약 RightChile == nullptr이면??? 부모쪽으로 올라가야함
			Node = Node->NextNode();
			return *this;
		}

		iterator& operator--()
		{
			// --연산자 << 내 이전 노드를 가리켜야함
			// 내 이전 노드는??? 내 LeftChild의 MaxNode()
			// 만약 LeftChild << nullptr이면??? 부모쪽으로 올라가야함
			Node = Node->PrevNode();
			return *this;
		}
	private:
		// 전방선언
		class MapNode* Node = nullptr;
	};

	iterator begin()
	{
		if (nullptr == Root)
		{
			return end();
		}
		return iterator(Root->MinNode());
	}

	iterator end()
	{
		// Node가 nullptr인 녀석이 end == 아무도 가리키지 않는 녀석
		return iterator();
	}

	iterator rbegin()
	{
		if (nullptr == Root)
		{
			return end();
		}
		return iterator(Root->MaxNode());
	}

	iterator rend()
	{
		return iterator();
	}

	iterator erase(const iterator& _EraseIter)
	{
		if (_EraseIter == end())
		{
			MsgBoxAssert("End노드를 지우려고 시도했습니다.")
		}
		// 지워질 노드
		MapNode* CurNode = _EraseIter.Node;
		// 지워질 노드의 부모노드 
		MapNode* ParentNode = CurNode->Parent;
		// 지워질 노드의 다음 노드
		MapNode* NextNode = CurNode->NextNode();
		// 지워진 노드의 자리를 대체할 노드
		MapNode* ChangeNode = nullptr;
		// 지워질 노드의 오른쪽 자식노드
		MapNode* RightChild = CurNode->RightChild;
		// 지워질 노드의 왼쪽 자식노드
		MapNode* LeftChild = CurNode->LeftChild;

		// 만약 지워지는 노드가 잎노드라면
		if (true == CurNode->IsLeaf())
		{
			// 잎노드는 자식이 존재하지 않음
			ParentNode->ChangeChild(CurNode, nullptr);
			if (nullptr != CurNode)
			{
				delete CurNode;
				CurNode = nullptr;
			}
			return NextNode;
		}

		// 만약 자식이 하나라도 있으면
		MapNode* ChangeChild = nullptr;
		MapNode* ChangeParent = nullptr;

		// 왼쪽자식이 있다면
		if (nullptr != LeftChild)
		{
			// 왼쪽자식의 MaxNode로 대체
			// MaxNode이므로 ChangeNode는 오른쪽자식이 없음
			ChangeNode = LeftChild->MaxNode();
			ChangeChild = ChangeNode->LeftChild;
			ChangeParent = ChangeNode->Parent;
		}
		else if (nullptr != RightChild)
		{
			// 왼쪽자식이 없고 오른쪽 자식이 있다면
			// 오른쪽자식의 MinNode로 대체
			// MinNode이므로 ChangeNode는 왼쪽자식이 없음
			ChangeNode = RightChild->MinNode();
			ChangeChild = ChangeNode->RightChild;
			ChangeParent = ChangeNode->Parent;
		}

		// 오류발생시 체크용
		if (nullptr == ChangeNode)
		{
			MsgBoxAssert("대체할 노드가 없다???");
			return nullptr;
		}

		// 현재 대체되어야 해서 빠져나가는 노드인 ChangeNode
		// ChangeNode가 빠져나가면서 자식을 부모로 끌어올려줌(연결이 이어지게)
		if (nullptr != ChangeParent)
		{
			ChangeParent->ChangeChild(ChangeNode, ChangeChild);
		}

		// 지워지는 노드 자리에 대체되어야 하는 노드를 삽입
		if (nullptr != ParentNode)
		{
			ParentNode->ChangeChild(CurNode, ChangeNode);
		}
		else 
		{
			// 만약 erase되는게 Root노드일 경우
			ChangeNode->Parent = nullptr;
			Root = ChangeNode;
		}

		// 대체된 노드의 왼쪽 자식노드 세팅
		ChangeNode->LeftChild = LeftChild;
		if (nullptr != LeftChild)
		{
			// 왼쪽 자식노드의 부모노드를 대체된 노드로 세팅
			LeftChild->Parent = ChangeNode;
		}
		// 대체된 노드의 오른쪽 자식노드 세팅
		ChangeNode->RightChild = RightChild;
		if (nullptr != RightChild)
		{
			// 오른쪽 자식노드의 부모노드를 대체된 노드로 세팅
			RightChild->Parent = ChangeNode;
		}

		// 그리고 지워져야할 노드는 삭제
		if (nullptr != CurNode)
		{
			delete CurNode;
			CurNode = nullptr;
		}
		return NextNode;
	}

	iterator find(const KeyType _Key)
	{
		if (nullptr == Root)
		{
			return end();
		}
		MapNode* FindNode = Root->find(_Key);
		return iterator(FindNode);
	}

	// 안들어가면 false리턴
	bool insert(const GameEnginepair<KeyType, ValueType>& _Pair)
	{
		if (nullptr == Root)
		{
			// 뿌리노드가 존재하지 않으면
			// 본인이 뿌리노드가 됨
			Root = new MapNode();
			Root->Pair = _Pair;
			return true;
		}
		MapNode* NewNode = new MapNode();
		NewNode->Pair = _Pair;
		if (false == Root->insert(NewNode))
		{
			delete NewNode;
			NewNode = nullptr;
			return false;
		}
		return true;
	}

	void FirstOrder()
	{
		Root->FirstOrder();
	}

	void MidOrder()
	{
		Root->MidOrder();
	}

	void LastOrder()
	{
		Root->LastOrder();
	}


	~GameEngineMap()
	{
		delete Root;
		Root = nullptr;
	}
protected:

private:
	MapNode* Root = nullptr;
};