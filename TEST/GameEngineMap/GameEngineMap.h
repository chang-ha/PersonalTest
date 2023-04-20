#pragma once
#include <GameEngineBase/GameEngineDebug.h>
typedef int KeyType;
typedef int ValueType;

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

class GameEngineMap
{
public:
	class MapNode
	{
	public:
		MapNode* Parent = nullptr;
		MapNode* LeftChild = nullptr;
		MapNode* RightChild = nullptr;
		GameEnginepair Pair;

		bool IsLeaf()
		{
			return nullptr == LeftChild && nullptr == RightChild;
		}

		// 내가 지워지기 전에 해야할 일
		void Release()
		{
			if (nullptr == Parent)
			{
				return;
			}

			if (this == Parent->LeftChild)
			{
				Parent->LeftChild = nullptr;
				return;
			}
			if (this == Parent->RightChild)
			{
				Parent->RightChild = nullptr;
				return;
			}
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


		void Detach()
		{
			// 5를 기준 << Detach할 떄 
			// 5의 부모노드인 6에게 LeftNode로 5의 자식노드인 4를 붙여줬어야 했는데
			// 5의 부모노드인 6에게 LeftNode로 5의 RightNode를 붙여주었지만 nullptr이여서 사실상 6의 LeftNode = nullptr이 되어버림

			// 수정
			// 내 의견
			// this == DetachParent->LeftChild란 소리는
			// this가 Parent의 Left->MaxNode()란 뜻
			// == this의 RightNode가 존재하지 않음(내가 가장 오른쪽)
			MapNode* DetachParent = Parent;
			MapNode* DetachLeftChild = LeftChild;
			MapNode* DetachRightChild = RightChild;
			// this == DetachParent->LeftChild << this == Parent->LeftChild->MaxNode() << 오른쪽 자식은 무조건 없음
			if (nullptr != DetachParent && this == DetachParent->LeftChild)
			{
				DetachParent->LeftChild = DetachLeftChild;
				if (nullptr != DetachLeftChild)
				{
					DetachLeftChild->Parent = DetachParent;
				}
			}
			// this == DetachParent->RightChild << this == Parent->RightChild->MinNode() << 왼쪽 자식은 무조건 없음
			else if (nullptr != DetachParent && this == DetachParent->RightChild)
			{
				DetachParent->RightChild = DetachRightChild;
				if (nullptr != DetachRightChild)
				{
					DetachRightChild->Parent = DetachParent;
				}
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

		GameEnginepair* operator->()
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

		if (true == CurNode->IsLeaf())
		{
			CurNode->Release();
			delete CurNode;
			CurNode = nullptr;
			return NextNode;
		}

		if (nullptr != RightChild)
		{
			ChangeNode = RightChild->MinNode();
			ChangeNode->Detach();
			if (nullptr != ParentNode)
			{
				ParentNode->ChangeChild(CurNode, ChangeNode);
				ChangeNode->LeftChild = CurNode->LeftChild;
				if (nullptr != ChangeNode->LeftChild)
				{
					ChangeNode->LeftChild->Parent = ChangeNode;
				}
				ChangeNode->RightChild = CurNode->RightChild;
				if (nullptr != ChangeNode->RightChild)
				{
					ChangeNode->RightChild->Parent = ChangeNode;
				}
			}
			return ChangeNode;
		}
		else if (nullptr != LeftChild)
		{
			ChangeNode = LeftChild->MaxNode();
			ChangeNode->Detach();
			if (nullptr != ParentNode)
			{
				ParentNode->ChangeChild(CurNode, ChangeNode);
				ChangeNode->LeftChild = CurNode->LeftChild;
				if (nullptr != ChangeNode->LeftChild)
				{
					ChangeNode->LeftChild->Parent = ChangeNode;
				}
				ChangeNode->RightChild = CurNode->RightChild;
				if (nullptr != ChangeNode->RightChild)
				{
					ChangeNode->RightChild->Parent = ChangeNode;
				}
			}
			return ChangeNode;
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
	bool insert(const GameEnginepair& _Pair)
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


	MapNode* Root = nullptr;

protected:

private:
};