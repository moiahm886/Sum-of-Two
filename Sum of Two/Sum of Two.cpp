#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
struct Node
{
	int data;
	Node* Next;
};
Node* SumNode = NULL;
Node* NewNode(Node* Head, int val)
{
	Node* newnode = new Node();
	newnode->data = val;
	newnode->Next = NULL;
	return newnode;
}
Node* Insertion(Node* Head, int val)
{
	if (Head == NULL)return NewNode(Head,val);
	Head->Next = Insertion(Head->Next, val);
	return Head;
}
Node* Sum(Node* Head, Node* head)
{
	int x = 0;
	int y = 0;
	int sum = 0;
	vector<int>vect1, vect2;
	for (Head; Head != NULL; Head = Head->Next)
	{
		vect1.push_back(Head->data);
	}
	reverse(vect1.begin(), vect1.end());
	stringstream ss, sx;
	for (head; head != NULL; head = head->Next)
	{
		vect2.push_back(head->data);
	}
	reverse(vect1.begin(), vect1.end());
	for (auto z : vect1)
	{
		ss << z;
	}
	ss >> x;
	for (auto z : vect2)
	{
		sx << z;
	}
	sx >> y;
	sum = x + y;
	vector<int>hello;
	while (1)
	{
		hello.insert(hello.begin(), sum % 10);
		sum /= 10;
		if (sum == 0)
		{
			break;
		}
	}
	reverse(hello.begin(), hello.end());
	for (auto sfk : hello)
	{
		SumNode = Insertion(SumNode, sfk);
	}
	return SumNode;
}
void display(Node* head)
{
	if (head == NULL)return;
	cout << head->data << "\t";
	display(head->Next);
}
int main()
{
	Node* Head = NULL;
	Node* head = NULL;
	Head = Insertion(Head, 2);
	Head = Insertion(Head, 4);
	Head = Insertion(Head, 3);
	head = Insertion(head, 5);
	head = Insertion(head, 6);
	head = Insertion(head, 4);
	display(head);
	cout << endl;
	display(Head);
	cout << endl;
	Sum(Head, head);
	display(SumNode);
	return 0;
}
