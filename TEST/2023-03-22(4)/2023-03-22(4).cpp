// 금일 강의 내용 : BytePadding

#include<iostream>

class Player
{
public:
	char Value1;
	char Value2;
	int HP;
	int Att;
	__int64 Value0;
	short Value3; // 2바이트 정수
	short Value4;
	// 1. 8바이트 이하 가장 큰 바이트의 자료형을 기준으로 할당함
	// 2. 거기에 밀어 넣어보고 딱 맞거나 들어갈 수 있으면 그대로 픽스
	// 3. 안되면 새로 할당
	// ex) 
	// short value1; << 8바이트 할당 8{2}
	// int value2;   << 8{2, 4}
	// char value3;  << 8{2, 4, 1}
	// char value4;  << 8{2, 4, 1, 1}
	// char value5;  << 8바이트 새로 할당 8{1} << 빈 공간(7바이트)가 생김 == PaddingByte라고 부름
	// __int64 value6; << 8바이트 새로 할당 8{8}
	// 위의 현상들을 BytePadding현상 이라고 부름
	// 주소값 확인해보기!!
	// int value1;
	// short value2;
	// __int64 value3;
};

int main()
{
	Player NewPlayer = Player();
	char* Value1 = &NewPlayer.Value1;
	char* Value2 = &NewPlayer.Value2;
	int* HP = &NewPlayer.HP;
	int* Att = &NewPlayer.Att;
	__int64* Value0 = &NewPlayer.Value0;
	short* Value3 = &NewPlayer.Value3;
	short* Value4 = &NewPlayer.Value4;
	// 메모리 주소로 보면 변수 순서대로 

	__int64 Address1 = (__int64)Value1; // char 1 byte	8{1}         << 100번지
	__int64 Address6 = (__int64)Value2; // char 1 byte  8{1, 1, 4}   << 104번지
	__int64 Address2 = (__int64)HP;		// int	4 byte  8{1, 1, 4}   << 105번지
	__int64 Address3 = (__int64)Att;	// int  4 byte  8{4}		 << 108번지
	__int64 Address4 = (__int64)Value0; // int64 8 byte 8{8}		 << 116번지
	__int64 Address5 = (__int64)Value3; // short 2byte  8{2}		 << 124번지
	__int64 Address7 = (__int64)Value4; // short 2byte  8{2, 2}	     << 126번지
	int a = 0;
}