#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	new int();
	int* Ptr = new int();
	*Ptr = 10;
	
	delete Ptr;
}