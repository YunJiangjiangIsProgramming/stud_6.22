#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
using namespace std;
typedef struct ListNode ListNode;
struct ListNode
{
	int _val;
	ListNode* next;
	ListNode* prev;
};

ListNode* BuyListNode()
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	int _val = 1;
	ListNode* next = NULL;
	ListNode* prev = NULL;

	return newNode;
}

struct ListNode_cpp
{
public:
	int _val;
	ListNode* next;
	ListNode* prev;

	ListNode_cpp(int val = 0)
		:_val(val)
		, next(nullptr)
		, prev(nullptr)
	{
		cout << "ListNodecpp" << endl;
	}

	
};
int main()
{
	
	/*ListNode* node1 = BuyListNode();
	ListNode_cpp* node2 = new ListNode_cpp;

	delete node2;*/
	ListNode_cpp a[10];

	return 0;
}



class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}

	~A()
	{
		cout << "~A():" << this << endl;
	}

private:
	int _a;
};

int main()
{
	A* p1 = new A;
	//A* p2 = new A[10];

	A* p3 = (A*)malloc(sizeof(A));
	if (p3 == nullptr)
	{
		perror("malloc fail");
		exit(-1);
	}

	// 定位new -- 对p3指向空间，显示调用构造函数初始化
	new(p3)A(1);

	//p3->~A();
	//free(p3);
	delete p3;

	delete p1;


	return 0;
}

int main()
{
	char* p = new char[1024 * 1024 * 1024];

	return 0;
}


//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}

//template<class T>
//template<class Tp>
//template<class K>

 //函数模板
template<typename T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

//int main()
//{
//	int a = 1, b = 2;
//	Swap(a, b);
//
//	int x = 1, y = 2;
//	Swap(x, y);
//
//	double c = 1.1, d = 2.2;
//	Swap(c, d);
//
//	char e = 'a', f = 'b';
//	Swap(e, f);
//
//	//Swap(x, c);
//
//	return 0;
//}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}

//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	// 自动推演实例化
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//
//	cout << Add((double)a1, d2) << endl;
//	/*cout << Add(a1, (int)d2) << endl;*/
//
//	// 显示实例化
//	cout << Add<double>(a1, d2) << endl;
//	cout << Add<int>(a1, d2) << endl;
//
//	return 0;
//}


template<class T1, class T2>
T1 Add(const T1& left, const T2& right)
{
	return left + right;
}


int main()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.1, d2 = 20.2;
	// 自动推演实例化
	cout << Add(a1, a2) << endl;
	cout << Add(d1, d2) << endl;

	cout << Add(a1, d2) << endl;
	cout << Add(d1, a2) << endl;

	return 0;
}



int Add(int left, int right) // _Z3Addii
{
	return left + right;
}

// 通用加法函数
template<class T>
T Add(T left, T right) // _Z3TAddii
{
	return left + right;
}

int main()
{
	int a = 1, b = 2;
	Add(a, b);

	Add<int>(a, b);

	return 0;
}

typedef int STDataType;
//typedef double STDataType;

template<typename T>
class Stack
{
public:
	Stack(int capacity = 4)
	{
		cout << "Stack(int capacity = )" <<capacity<<endl;

		_a = (T*)malloc(sizeof(T)*capacity);
		if (_a == nullptr)
		{
			perror("malloc fail");
			exit(-1);
		}

		_top = 0;
		_capacity = capacity;
	}
	
	~Stack()
	{
		cout << "~Stack()" << endl;

		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}

	void Push(const T& x)
	{
		// ....
		// 扩容
		_a[_top++] = x;
	}

private:
	T* _a;
	int _top;
	int _capacity;
};


int main()
{
	// 类模板一般没有推演时机，函数模板实参传递形参，推演模板参数
	// 显示实例化
	// 他们是同一个类模板实例化出来的
	// 但是模板参数不同，他们就是不同类型
	Stack<double> st1; // double
	st1.Push(1.1);

	Stack<int> st2; // int
	st2.Push(1);

	return 0;
}

//#define N  10
//
//namespace bit
//{
//	template<class T>
//	class array
//	{
//	public:
//		T& operator[](size_t i)
//		{
//			assert(i < N);
//			return _a[i];
//		}
//	private:
//		T _a[N];
//	};
//}
//
//int main()
//{
//	int a2[10];
//	a2[20] = 0;
//	a2[10];
//
//	bit::array<int> a1;
//	for (size_t i = 0; i < N; ++i)
//	{
//		 a1.operator[](i)= i;
//
//		a1[i] = i;
//	}
//
//	for (size_t i = 0; i < N; ++i)
//	{
//		a1.operator[](i);
//		/*cout << a1[i] << " ";*/
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < N; ++i)
//	{
//		a1[i]++;
//	}
//
//	for (size_t i = 0; i < N; ++i)
//	{
//		cout << a1[i] << " ";
//	}
//	cout << endl;
//
//	a1[20];
//	a1[10];
//
//
//	return 0;
//}

