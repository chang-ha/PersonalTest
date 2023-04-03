// 030_PointerOperator001


int main()
{
	// 100번지 Value
	int Value = 0;
	int* Ptr = &Value;
	__int64 Address = 0;
	// Ptr[0]; << 자기 자신의 위치


	Address = (__int64)Ptr;
	// 나의 주소값을 100번지 + sizeof(int) * 1 하겠다
	// 포인터는 자료형과 같게 생각하면 안됨!!!
	// sizeof(자료형) 만큼 이동함
	Ptr = Ptr + 1; // Ptr += 1; (동일문법)

	Address = (__int64)Ptr;
	Ptr = Ptr + 1;
	Address = (__int64)Ptr;
	Ptr = Ptr + 1;
	Address = (__int64)Ptr;
	Ptr = Ptr + 1;
	Address = (__int64)Ptr;
	Ptr = Ptr + 1;
}