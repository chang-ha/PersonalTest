class int2
{
public:
	int X;
	int Y;

public:
	int2 Half()
	{
		return { X / 2, Y / 2 };
	}

public:
	inline int2()
	{

	}
	int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}
};