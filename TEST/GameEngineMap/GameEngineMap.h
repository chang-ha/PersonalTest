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
				// ������ �ڽ��� �ִٸ� ������ �ڽ��� MinNode(���� ���� Key)
				return RightChild->MinNode();
			}
			if (nullptr != Parent)
			{
				// ������ �ڽ��� ���ٸ� �θ����
				// �θ���� �� �� ������ Key���� ū �θ��带 ã�� �� ���� ��ȸ
				return OverParentNode();
			}
			// ������ ��嵵 ���� ������ ū Key���� ���� ��尡 ������ �ش� map������ MaxNode��
			// MaxNode�� �������� nullptr(end)
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
			// ���� ���� ����� Key���� Root����� Key������ ������ �����ڽ�����
			if (Pair.first > _NewNode->Pair.first)
			{
				if (nullptr != LeftChild)
				{
					// �����ڽ��� �̹� �ִٸ� insert ���
					return LeftChild->insert(_NewNode);
				}
				LeftChild = _NewNode;
				// ���� ���� Node�� �θ���� ���� �Լ��� ȣ������ ���
				_NewNode->Parent = this;
				return true;
			}
			// ���� ���� ����� Key���� Root����� Key������ ũ�� �������ڽ�����
			else if (Pair.first < _NewNode->Pair.first)
			{
				if (nullptr != RightChild)
				{
					// �������ڽ��� �̹� �ִٸ� insert ���
					return RightChild->insert(_NewNode);
				}
				RightChild = _NewNode;
				// ���� ���� Node�� �θ���� ���� �Լ��� ȣ������ ���
				_NewNode->Parent = this;
				return true;
			}
			// ���� ���� ����� Key���� ������ Key���� ���� ��尡 �̹� �ʿ� ������
			return false;
		}

		MapNode* find(KeyType _Key)
		{
			if (Pair.first > _Key)
			{
				if (nullptr != LeftChild)
				{
					// Key���� ���� ����� Key������ ������ ��������
					return LeftChild->find(_Key);
				}
				// �����ڽ��� nullptr�̸� ��ã�� ���̴� nullptr
				return nullptr;
			}
			else if (Pair.first < _Key)
			{
				if (nullptr != RightChild)
				{
					// Key���� ���� ����� Key������ ũ�� ����������
					return RightChild->find(_Key);
				}
				// �������ڽ��� nullptr�̸� ��ã�� ���̴� nullptr
				return nullptr;
			}
			// ������ �Լ��� ȣ������ ����� iterator�� ����
			return this;
		}

		void FirstOrder()
		{
			// ������ȸ : � �۾��� �� �� ��ȸ�� �� (��Ʈ���� �۾��� �� ����)
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
			// ������ȸ : ��ȸ�� ���� �߰��� � �۾��� �� (����or������ �ڽ��� �۾� �� > ��Ʈ��� �۾� > ������ �ڽ� �۾�)
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
			// ������ȸ : ��ȸ�� ���� �� ���� � �۾��� �� (���������� �۾� > �θ���� �ö󰡸鼭 �������� ��Ʈ��� �۾�)
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
			std::cout << "������ �༮ : " << Pair.first << std::endl;
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
			// ++������ == �� ���� ��带 �����Ѿ���
			// �� ���� ����??? �� RightChild�� MinNode()
			// ���� RightChile == nullptr�̸�??? �θ������� �ö󰡾���
			Node = Node->NextNode();
			return *this;
		}

		iterator& operator--()
		{
			// --������ << �� ���� ��带 �����Ѿ���
			// �� ���� ����??? �� LeftChild�� MaxNode()
			// ���� LeftChild << nullptr�̸�??? �θ������� �ö󰡾���
			Node = Node->PrevNode();
			return *this;
		}
	private:
		// ���漱��
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
		// Node�� nullptr�� �༮�� end == �ƹ��� ����Ű�� �ʴ� �༮
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
			MsgBoxAssert("End��带 ������� �õ��߽��ϴ�.")
		}
		// ������ ���
		MapNode* CurNode = _EraseIter.Node;
		// ������ ����� �θ��� 
		MapNode* ParentNode = CurNode->Parent;
		// ������ ����� ���� ���
		MapNode* NextNode = CurNode->NextNode();
		// ������ ����� �ڸ��� ��ü�� ���
		MapNode* ChangeNode = nullptr;
		// ������ ����� ������ �ڽĳ��
		MapNode* RightChild = CurNode->RightChild;
		// ������ ����� ���� �ڽĳ��
		MapNode* LeftChild = CurNode->LeftChild;

		// ���� �������� ��尡 �ٳ����
		if (true == CurNode->IsLeaf())
		{
			// �ٳ��� �ڽ��� �������� ����
			ParentNode->ChangeChild(CurNode, nullptr);
			if (nullptr != CurNode)
			{
				delete CurNode;
				CurNode = nullptr;
			}
			return NextNode;
		}

		// ���� �ڽ��� �ϳ��� ������
		MapNode* ChangeChild = nullptr;
		MapNode* ChangeParent = nullptr;

		// �����ڽ��� �ִٸ�
		if (nullptr != LeftChild)
		{
			// �����ڽ��� MaxNode�� ��ü
			// MaxNode�̹Ƿ� ChangeNode�� �������ڽ��� ����
			ChangeNode = LeftChild->MaxNode();
			ChangeChild = ChangeNode->LeftChild;
			ChangeParent = ChangeNode->Parent;
		}
		else if (nullptr != RightChild)
		{
			// �����ڽ��� ���� ������ �ڽ��� �ִٸ�
			// �������ڽ��� MinNode�� ��ü
			// MinNode�̹Ƿ� ChangeNode�� �����ڽ��� ����
			ChangeNode = RightChild->MinNode();
			ChangeChild = ChangeNode->RightChild;
			ChangeParent = ChangeNode->Parent;
		}

		// �����߻��� üũ��
		if (nullptr == ChangeNode)
		{
			MsgBoxAssert("��ü�� ��尡 ����???");
			return nullptr;
		}

		// ���� ��ü�Ǿ�� �ؼ� ���������� ����� ChangeNode
		// ChangeNode�� ���������鼭 �ڽ��� �θ�� ����÷���(������ �̾�����)
		if (nullptr != ChangeParent)
		{
			ChangeParent->ChangeChild(ChangeNode, ChangeChild);
		}

		// �������� ��� �ڸ��� ��ü�Ǿ�� �ϴ� ��带 ����
		if (nullptr != ParentNode)
		{
			ParentNode->ChangeChild(CurNode, ChangeNode);
		}
		else 
		{
			// ���� erase�Ǵ°� Root����� ���
			ChangeNode->Parent = nullptr;
			Root = ChangeNode;
		}

		// ��ü�� ����� ���� �ڽĳ�� ����
		ChangeNode->LeftChild = LeftChild;
		if (nullptr != LeftChild)
		{
			// ���� �ڽĳ���� �θ��带 ��ü�� ���� ����
			LeftChild->Parent = ChangeNode;
		}
		// ��ü�� ����� ������ �ڽĳ�� ����
		ChangeNode->RightChild = RightChild;
		if (nullptr != RightChild)
		{
			// ������ �ڽĳ���� �θ��带 ��ü�� ���� ����
			RightChild->Parent = ChangeNode;
		}

		// �׸��� ���������� ���� ����
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

	// �ȵ��� false����
	bool insert(const GameEnginepair<KeyType, ValueType>& _Pair)
	{
		if (nullptr == Root)
		{
			// �Ѹ���尡 �������� ������
			// ������ �Ѹ���尡 ��
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