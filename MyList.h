#pragma once
#include <iostream>
#include <QGraphicsPixmapItem>

using namespace std;

template <class SA>
class MyList
{
protected:
	struct Node
	{
		SA data;
		Node* next;
	};
	Node* head = NULL;
public:
	bool isEmpty();	
    SA getelement(int);
    void push_tail(SA);
	void DeleteElement(int);		
    Node* FindValueByNum(int);
};

	template<class SA>
	SA MyList<SA>::getelement(int n)
	{
		Node* temp = head;
		int i;
		i = 0;
		while (i < n)
		{
			temp = temp->next;
			i = i + 1;
		}
		return temp->data;
	}



template<class SA>
bool MyList<SA>::isEmpty()
{
	if (head == NULL)
		return true;
	return false;
}
template<class SA>
void MyList<SA>::push_tail(SA data)
{
	Node* temp = new Node;
	if (head == NULL)
	{
		head = new Node();
		head->next = head;
		head->data = data;
	}
	else
	{
		Node* temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = new Node;
		temp->next->next = head;
		temp->next->data = data;
	}
}
template<class SA>
void MyList<SA>::DeleteElement(int n)
{
	Node* temp = FindValueByNum(n);
	Node* save = head;
	if (!isEmpty() and temp != NULL)
	{
		if (temp == head)
		{
			Node* temp = head;
            temp = temp->next;
			Node* pntr = head;
			Node* save = head->next;
			while (pntr->next != head)
				pntr = pntr->next;
			delete head;
			head = temp;
			while (head != pntr)
				head = head->next;
			head->next = save;
		}
		else
		{
			while (save->next != temp)
				save = save->next;
			save->next = temp->next;
			delete temp;
		}
	}
}
	
template<class SA>
typename MyList<SA>::Node* MyList<SA>::FindValueByNum(int n)
{
	Node* temp = head;
	int i;
	i = 0;
	while (i < n)
	{
		temp = temp->next;
		i = i + 1;
	}
	return temp;
}
