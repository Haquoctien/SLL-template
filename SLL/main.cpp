#include "SLL.h"
using namespace std;
// implement stack
using intNode = node<int>;
using stack = SLL<int>;
#define push SLL<int>::addHead
#define pop SLL<int>::popHead

int main(void)
{
	stack myStack;
	myStack.push(1);
	myStack.push(6);
	myStack.push(7);
	intNode *p = myStack.head;
	while (p)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
	cout << myStack.pop()->info << endl;
	system("pause");
	return 0;
}