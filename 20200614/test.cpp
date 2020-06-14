#include <queue>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//template<class T>
//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//		stack<int> st;
//		int pushIdx = 0;
//		int popIdx = 0;
//		while (pushIdx < pushV.size()) {
//			st.push(pushV[pushIdx++]);
//			while (!st.empty() && st.top() == popV[popIdx]) {
//				st.pop();
//				popIdx++;
//			}
//		}
//		return st.empty();
//	}
//};

//template <class T>
void test() {
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
void test2() {
	//通过堆实现,默认为大堆
	priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	pq.push(6);
	pq.push(7);
	pq.push(8);
	//遍历大堆
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}
void test3() {
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
struct C{
	C(int a,int b,int c)
		:_a(a)
		,_b(b)
		,_c(c)
	{}
	bool operator>(const C& c)const {
		return _a > c._a;
	}
	bool operator<(const C& c)const {
		return _a < c._a;
	}
	int _a;
	int _b;
	int _c;
};

//仿函数类模板
template<class T>
struct Less {
	//重载括号运算符
	bool operator()(const T& c1, const T& c2) {
		return c1 < c2;
	}
};

template<class T>
struct Greater {

	bool operator()(const T& c1, const T& c2) {
		return c1 > c2; 
	}
};
//输出运算符重载
ostream& operator<<(ostream& cout, const C& c) {
	cout << c._a << "-" << c._b << "-" << c._c << endl;
	return cout;
}
void test4() {
	//优先队列存放自定义类型,自定义类型需要支持大小比较运算
	//建大堆,需要提供小于的比较
	priority_queue<C> pq;
	pq.push(C(1, 2, 3));
	pq.push(C(2, 2, 3));
	pq.push(C(3, 2, 3));
	pq.push(C(4, 2, 3));
	pq.push(C(5, 2, 3));
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}	
}

void test5{
	//优先队列存放自定义类型,自定义类型需要支持大小比较运算
	//建小堆,需要提供大于的比较
	priority_queue<C, vector<C>, Greater<C>> pq;
	pq.push(C(1, 2, 3));
	pq.push(C(2, 2, 3));
	pq.push(C(3, 2, 3));
	pq.push(C(4, 2, 3));
	pq.push(C(5, 2, 3));
	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
}

int main() {
	test4();
	return 0;
}