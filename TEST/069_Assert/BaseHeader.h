#pragma once

#include <Windows.h>
#include <assert.h>
//void MsgBoxAssert(const char* _Text)
//{
//	//									MB_OK = Ȯ�ι�ư �Ѱ� ������
//	MessageBoxA(nullptr, _Text, "Error", MB_OK);
//	// assert�� false�� ���α׷��� ������ ����
//	// �ٽýõ� ������ ��� ������ �˷���
//	assert(false);
//}

// ���� �Լ��� �̿��ϸ� ������ ����
// �Լ���ġ�� �͹����� ��� �������� ��
// ȣ�⽺������ �ѹ� �ڷ� �����ؼ� ������
// �׷��� define�� ���
#define MessageBoxAssert(TEXT) 	MessageBoxA(nullptr, TEXT, "Error", MB_OK); assert(false);

// inline���� ������
// inline�� �׷��� �Լ������̱� ������ ���ڰ� �ڷ����� �´��� �� �� �˻�����
// �׸��� �Լ� ȣ�� ���� ������ ������
//inline void MsgBoxAssert(const char* _Text)
//{
//	MessageBoxA(nullptr, _Text, "Error", MB_OK);
//	assert(false);
//}