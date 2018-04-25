# Read Me

### Ví dụ về dùng template node\<type> và SLL\<type>
Đoạn code dưới đây dùng hai template trên để cài đặt stack chứa kiểu int, với hai thao tác là push và pop
```cpp
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
```

Output khi chạy chương trình là:

7 6 1

7

Press any key to continue...
