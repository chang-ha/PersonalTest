
class A
{
	friend B;
	void ValueChange()
	{
		NewB->ValueB = 10;
	}
private:
	int ValueA = 1;
	B* NewB;
};
class B
{
	void ValueChange()
	{
		NewA->ValueA = 10;
	}
private:
	int ValueB = 2;
	A* NewA;
};
int main()
{

}