#include"list.h"
#include<iostream>
using namespace std;
QGList::QGList()
{
	head = new Node;
	tail = new Node;
	head->data = 0;
	tail->data = 0;
	head->next = tail;
	head->prior = NULL;
	tail->prior = head;
	tail->next = NULL;
	length = 0;
}
QGList::~QGList()
{
	Node* p1 = head->next;
	Node* p2 = NULL;
	while(p1!=tail)
	{
		p2 = p1->next;
		delete p1;
		p1 = NULL;
		p1 = p2;
	}
	delete head;
	head = NULL;
	delete tail;
	tail = NULL;
}
bool QGList::push_front(ElemType& e)
{
	Node* p1 = head->next;
	Node* pe = new Node;
	if(pe==NULL)
	{
		return false;
	}
	pe->next = p1;
	pe->prior = p1->prior;
	p1->prior->next = pe;
	p1->prior = pe;
	pe->data = e;
	length++;
	return true;
}
bool QGList::pop_front()
{
	Node* p1 = head->next;
	if (p1 != tail)
	{
		p1->prior->next = p1->next;
		p1->next->prior = p1->prior;
		delete p1;
		p1 = NULL;
		length--;
		return true;
	}
	return false;
}
bool QGList::push_back(ElemType& e)
{
	Node* p1 = head->next;
	if (p1 = tail)
	{
		Node* pe = new Node;
		if (pe == NULL)
		{
			return false;
		}
		pe->next = p1;
		pe->prior = p1->prior;
		p1->prior->next = pe;
		p1->prior = pe;
		pe->data = e;
		length++;
		return true;
	}
	while(p1->next!=tail)
	{
		p1 = p1->next;
	}
	Node* pe = new Node;
	if (pe == NULL)
	{
		return false;
	}
	pe->next = p1;
	pe->prior = p1->prior;
	p1->prior->next = pe;
	p1->prior = pe;
	pe->data = e;
	length++;
	return true;
}
bool QGList::pop_back()
{
	Node* p1 = head->next;
	if(p1==tail)
	{
		return false;
	}
	while (p1->next!=tail)
	{
		p1 = p1->next;
	}
	p1->prior->next = p1->next;
	p1->next->prior = p1->prior;
	delete p1;
	p1 = NULL;
	length--;
	return true;
}
bool QGList::insert(unsigned int index, ElemType& e)
{
	if(index<0||index>length)
	{
		return false;
	}
	Node* p1 = head;
	for(unsigned int k=0;k<index;k++)
	{
		p1 = p1->next;
	}
	Node* pe = new Node;
	if (pe == NULL)
	{
		return false;
	}
	pe->next = p1;
	pe->prior = p1->prior;
	p1->prior->next = pe;
	p1->prior = pe;
	pe->data = e;
	length++;
	return true;
}
bool QGList::erase(unsigned int index)
{
	if (index<0 || index>=length)
	{
		return false;
	}
	Node* p1 = head;
	Node* pb = NULL;
	for (unsigned int k = 0; k <= index; k++)
	{
		pb = p1;
		p1 = p1->next;
	}
	p1->prior->next = p1->next;
	p1->next->prior = p1->prior;
	delete p1;
	p1 = NULL;
	length--;
	return false;
}
bool QGList::clear()
{
	Node* p1 = head->next;
	Node* p2 = NULL;
	head->next = tail;
	tail->prior = head;
	while (p1 != tail)
	{
		p2 = p1->next;
		delete p1;
		p1 = NULL;
		p1 = p2;
	}
	length = 0;
	return true;
}


QGList::ElemType& QGList::front()
{
	Node* p = head->next;
	if(p==tail)
	{
		cout << "链表当前没有数据";
		return p->data;
	}
	return p->data;
}
QGList::ElemType& QGList::back()
{
	Node* p1 = head->next;
	if (p1 == tail)
	{
		cout << "链表当前没有数据";
		return p1->data;
	}
	while (p1->next!=tail)
	{
		p1 = p1->next;
	}
	return p1->data;
}
bool QGList::contain(ElemType& e)
{
	Node* p = head -> next;
	for (unsigned int k = 1; k <= length; k++)
	{	
		if (p->data == e)
		{
			return true;
		}
		p = p->next;
	}
	return false;
}
void QGList::Traverse()
{
	Node* p = head;
	while (p->next!=tail)
	{
		p = p->next;
		cout << p->data << endl;
	}
}
unsigned int QGList::size()
{
	return length;
}
int main()
{
	cout << "1.查询首结点数据   " << "2.查询末结点数据 " << "3.查询链表长度          丨" << endl;
	cout << "                                                            丨" << endl;
	cout << "4.插入结点数据     " << "5.删除结点数据   " << "6.清空链表              丨" << endl;
	cout << "                                                            丨" << endl;
	cout << "7.首元素前插入     " << "8.末结点后处插入 " << "9.查找数据是否存在      丨" << endl;
	cout << "                                                            丨" << endl;
	cout << "10.删除首结点数据  " << "11.删除末结点数据" << "12.查看链表当前数据     丨" << endl;
	cout << "                                                            丨" << endl;
	cout << "13.退出操作        " << "14.      (空)    " << "15.      （空）         丨" << endl;
	cout << "============================================================丨" << endl;

	QGList* p = new QGList();
	int i, n;
	cout << "请选择你的操作：";
	cin >> i;
	while (i != 13)
	{
		if (i == 1)
		{
			cout << "当前首结点数据为：" << endl;
			cout << p->front() << endl;
		}
		if (i == 2)
		{
			cout << "当前尾结点数据为：" << endl;
			cout << p->back() << endl;
		}
		if (i == 3)
		{
			cout << "当前链表长度：" << p->size() << endl;
		}
		if (i == 4)
		{
			int j;
			cout << "请输入插入位置：";
			cin >> j;
			cout << "请输入插入数字：";
			cin >> n;
			p->insert(j - 1, n);
		}
		if (i == 5)
		{
			int d;
			cout << "请输入删除位置：";
			cin >> d;
			p->erase(d - 1);
		}
		if (i == 6)
		{
			if (p->clear())
			{
				cout << "已清空链表" << endl;
			}
			else
			{
				cout << "操作失败" << endl;
			}
		}
		if (i == 7)
		{
			cout << "请输入插入数字：";
			cin >> n;
			p->push_front(n);
		}
		if (i == 8)
		{
			cout << "请输入插入数字：";
			cin >> n;
			p->push_back(n);
		}
		if (i == 9)
		{
			cout << "请输入想要查找数据：";
			int k;
			cin >> k;
			if (p->contain(k))
			{
				cout << "有此数据" << endl;
			}
			else
			{
				cout << "此数据不存在" << endl;
			}
		}
		if (i == 10)
		{
			p->pop_front();
		}
		if (i == 11)
		{
			p->pop_back();
		}
		if (i == 12)
		{
			cout << "链表当前数据：" << endl;
			p->Traverse();
		}
		cout << "请选择你的操作：";
		cin >> i;
	}
	return 0;
}