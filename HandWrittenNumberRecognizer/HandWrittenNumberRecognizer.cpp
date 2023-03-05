#include "Global.h"
#include "Definition.h"
int main()
{
	for (unsigned i = 0; i < network.times; i++)
	{
		cout << "第 " << i << " 次学习:" << endl;
		cout << network.cost() << endl;
		while (network.cost() >= flag)
		{
			network.reset();
			network.forward();
			network.backward();
			cout << network.cost() << endl;
		}
	}
	return 0;
}

