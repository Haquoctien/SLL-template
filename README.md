# Read Me
#### Tải hai file node.h và SLL.h, copy vào thư mục chứa file cpp của bạn và thêm #include "SLL.h" vào phần header để sử dụng. Thay thế ```type``` trong ```node<type>``` và ```SLL<type>``` bằng kiểu dữ liệu mong muốn, dùng từ khóa ```using``` và ```#define``` để đơn giản hóa cú pháp và đặt tên phù hợp cho cấu trúc dữ liệu và thao tác. Xem thêm ví dụ bên dưới.  
## Template class node
```cpp
template <class type>
class node
{
public:
	type info; // trường thông tin
	node *next; // con trỏ next
	node();
	node(type); // tạo node từ type, cần copy constructor cho type nếu type dùng bộ nhớ động
		// hay chỉnh sửa để method dùng tham biến
	~node();
	void isolate(); // ngắt next của node ra, next = NULL
};
```
## Template class SLL
```cpp
template <class type>
class SLL
{
public:
	node<type> *head, *tail;
	unsigned length;
	SLL();
	~SLL();
	bool isEmpty(); // kiểm tra rỗng
	void addHead(node<type> *);
	void addHead(type); // cần copy constructor cho type nếu type dùng bộ nhớ động
			// hay chỉnh sửa để method dùng tham biến
	void addTail(node<type> *);
	void addTail(type);// cần copy constructor cho type nếu type dùng bộ nhớ động
			// hay chỉnh sửa để method dùng tham biến
	node<type> *popHead();
	node<type> *popTail();
	node<type> *findNode(type); // có thể cần phải nạp chồng toán tử ==
	node<type> *popNode(type);
	node<type> *popNode(node<type> *);
	void deleteHead();
	void deleteTail();
	void deleteNode(type);
	void insertNodeAfter(node<type> *before, node<type> *after);
	void insertNodeAfter(type, type);
	// TODO: cài đặt các hàm nhập, xuất, xóa danh sách phù hợp với dữ liệu cần dùng
	// như là hàm không thành viên
};
```
### Ví dụ về dùng template node\<type> và SLL\<type>
Đoạn code dưới đây dùng hai template trên để cài đặt stack chứa node chứa kiểu int, với hai thao tác là push và pop
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
```
7 6 1
7
Press any key to continue...
```

Một ví dụ phức tạp hơn, dùng template để cài đặt cấu trúc dữ liệu là tokenList chứa node là class Token chứa tokenData (phần info của node) chứa hai string là token và type. Cài đặt hàm tokenize để chia nhỏ biểu thức nhập vào thành những phần tử nguyên vẹn như số, toán tử, hàm,... dùng cho việc tính biểu thức, chuyển biểu thức từ trung tố sang hậu số và ngược lại. 
```cpp
#include <iostream>
#include <string>
#include "SLL.h"
using namespace std;

// data structures
class tokenData
{
public:
	string token;
	string type;
	tokenData() {}
	tokenData(string token, string type)
	{
		this->token = token;
		this->type = type;
	}
	~tokenData() {}
};

using Token = node<tokenData>;
using tokenList = SLL<tokenData>;
#define push SLL<tokenData>::addTail

// function prototypes
void removeSpaces(string&);
tokenList tokenize(string);
#define isDigit isdigit
bool isOperator(char);
bool isLetter(char);
bool isLeftParenthese(char);
bool isRightParenthese(char);
void output(tokenList);


// definitions
tokenList tokenize(string str)
{
	tokenList result;
	removeSpaces(str);
	str[str.length()] = '\0';
	string numberBuffer = "";
	string letterBuffer = "";
	for (int i = 0; str[i];)
	{
		char c = str[i];
		bool flag = isDigit(c);
		while (flag)
		{
			numberBuffer += c;
			c = str[++i];
			if (!isDigit(c))
			{
				result.push(tokenData(numberBuffer, "number"));
				numberBuffer.clear();
				flag = false;
			}
		}
		flag = isLetter(c);
		while (flag)
		{
			letterBuffer += c;
			c = str[++i];
			if (!isLetter(c))
			{
				if (letterBuffer.compare("div") == 0)
					result.push(tokenData(letterBuffer, "operator"));
				result.push(tokenData(letterBuffer, "function"));
				letterBuffer.clear();
				flag = false;
			}
		}
		if (isOperator(c))
		{
			string temp = "";
			temp += c;
			result.push(tokenData(temp, "operator"));
			i++;
		}
		else if (isLeftParenthese(c))
		{
			string temp = "";
			temp += c;
			result.push(tokenData(temp, "rightParenthese"));
			i++;
		}
		else if (isRightParenthese(c))
		{
			string temp = "";
			temp += c;
			result.push(tokenData(temp, "leftParenthese"));
			i++;
		}
	}
	return result;
}

void removeSpaces(string &str)
{
	int count = 0;
	for (int i = 0; str[i]; i++)
		if (str[i] != ' ')
			str[count++] = str[i];
	str[count] = '\0';
}
bool isOperator(char c)
{
	string operators = "+-*/^";
	 if (operators.find(c) != -1)
		 return true;
	 return false;
}
bool isLetter(char c)
{
	return isalpha(c);
}
bool isLeftParenthese(char c)
{
	return (c == '(');
}
bool isRightParenthese(char c)
{
	return (c == ')');
}
```

