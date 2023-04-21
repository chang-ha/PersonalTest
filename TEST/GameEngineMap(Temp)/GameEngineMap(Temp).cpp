// GameEngineMap
// 맵이란?
// 노드형 연관 자료구조 (노드형, 넣어주면 Value의 순서가 바뀜)
// 자료를 넣어줄 때 마다 해당 자료(Pair형태)의 Key값을 비교하여
// Key값이 작으면 왼쪽, Key값이 크면 오른쪽으로 자료를 저장
// 그래서 절대 자료의 Key값을 바꾸면 안되기 때문에 내부적으로 막아놨음
// 장점
// 1. 맵은 자료가 많을 떄(자료가 천개이하면 vector가 더 빠름...;;) 탐색을 용이하게 하기 위해서 사용한다.
// 2. 맵은 사용성이 좋다. (vector는 특정 자료를 찾으려면 내가 for문 돌려야함, map은 내부에 함수로 구현되어 있음)


#include <iostream>
#include <map>
#include "GameEngineMap(Temp).h"
#include <list>
int main()
{
	{
		GameEngineDebug::LeckCheck();
		GameEngineMap Test;
		Test.insert(GameEnginepair(10, rand()));
		Test.insert(GameEnginepair(7, rand()));
		Test.insert(GameEnginepair(15, rand()));
		Test.insert(GameEnginepair(25, rand()));
		Test.insert(GameEnginepair(17, rand()));
		Test.insert(GameEnginepair(15, rand()));
		Test.insert(GameEnginepair(18, rand()));
		Test.insert(GameEnginepair(2, rand()));
		Test.insert(GameEnginepair(6, rand()));
		Test.insert(GameEnginepair(5, rand()));
		Test.insert(GameEnginepair(4, rand()));
		Test.insert(GameEnginepair(9, rand()));
		Test.insert(GameEnginepair(8, rand()));
		Test.insert(GameEnginepair(1, rand()));

		{
			GameEngineMap::iterator FindIter = Test.find(7);
			GameEngineMap::iterator NextIter = Test.erase(FindIter);
		}
		{
			GameEngineMap::iterator FindIter = Test.find(9);
			GameEngineMap::iterator NextIter = Test.erase(FindIter);
		}

		{
			GameEngineMap::iterator FindIter = Test.find(6);
			GameEngineMap::iterator NextIter = Test.erase(FindIter);
		}

		GameEngineMap::iterator Start = Test.begin();
		GameEngineMap::iterator End = Test.end();
		for (; Start != End; ++Start)
		{
			std::cout << Start->first << std::endl;
		}
		int a = 0;
	}
	return 1;
	std::list<int> Value;
	Value.push_back(20);
	Value.push_back(30);
	for (int& Test : Value)
	{
		// Ranged For로 순회하면
		// 눈에 보이지는 않지만 
		// Test = 내부의 변수; 해주는 것
		// int Test = 내부의 변수 << 내부의 변수의 int값을 복사해오는 것
		// 그래서 int* Test = 내부의 변수(ex. 노드 내부의 값이 있는 변수) << 불가능 int* Test = A; << int*형식과 int형식은 지원이 안됨 (자료형이 다름)
		// int& Test = 내부의 변수 << 참조로 받는 것 << int& Test = A; << A의 주소를 참조
		Test = 50;
	}

	std::pair<int, int> NewPair;
	NewPair.first = 5;
	NewPair.second = 10;
	NewPair.first = 10;
	// 왼쪽 int는 Key, 오른쪽 int는 Value
	std::map<int, int> Test;
	// 인설트는 pair<int, int>를 달라고 하는 함수입니다.
	// Test.insert(std::pair<int, int> (1,1));
	// == Test.insert(std::make_pair(1, 1));
	// == Test.insert(std::map<int, int>::value_type(1, 1));
	std::pair<std::map<int, int>::iterator, bool> Value1 =
		Test.insert(std::pair<int, int>(5, rand()));
	std::pair<std::map<int, int>::iterator, bool> Value2 =
		Test.insert(std::pair<int, int>(4, rand()));
	std::pair<std::map<int, int>::iterator, bool> Value3 =
		Test.insert(std::pair<int, int>(1, rand()));
	std::pair<std::map<int, int>::iterator, bool> Value4 =
		Test.insert(std::pair<int, int>(7, rand()));
	std::pair<std::map<int, int>::iterator, bool> Value5 =
		Test.insert(std::pair<int, int>(2, rand()));
	std::pair<std::map<int, int>::iterator, bool> Value6 =
		Test.insert(std::pair<int, int>(15, rand()));
	Test.find(5);
	// 같은 키를 넣어주면???? 현재 넣어준 값을 무시하고, 이전에(해당 Key를 가진 노드) 정상적으로 들어간 값을 리턴해줌(false와 함께)
	// std::pair<std::map<int, int>::iterator, bool> 형태로 리턴 first = std::map<int, int>::iterator형태, second = bool 형태
	//std::pair<std::map<int, int>::iterator, bool> Value0 =
	//Test.insert(std::pair<int, int>(5, rand()));

	// 내 의견 : 이렇게 원소가 안들어갔는지도 알수 있겠네???
	if (false == Test.insert(std::pair<int, int>(5, rand())).second)
	{
		int a = 0;
	}

	if (false == Value6.second)
	{
		int a = 0;
		// false면 같은 Key를 넣어줬다.
	}

	Test.find(15); // Key값이 15인 노드의 Value는 얼마일까???
	// 내부의 Key값을 바꾸면 안되기 때문에 참조(&)로 받을때는 const로 넣으면 가능
	// Ranged for
	for (const std::pair<int, int>& Value : Test)
	{
		// Key값
		Value.first;
		// Value값
		Value.second;
	}

	// 내 의견 : Key값만 안바꾸면 되니까 이렇게 해도 될 수 있지 않을까??
	for (std::pair<const int, int>& Value : Test)
	{
		// Key값
		Value.first;
		// Value값
		Value.second = 10;
		int a = 0;
	}

	std::map<int, int>::iterator Start = Test.begin();
	std::map<int, int>::iterator End = Test.end();
	for (; Start != End; ++Start)
	{
		std::cout << Start->first << std::endl;
	}

}