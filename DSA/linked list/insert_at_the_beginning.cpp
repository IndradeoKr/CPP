//Inserting data at the beginning using liked list.
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *next;
};

node* insert(int x, node *head)
{
	node* temp = new node();
	temp->data = x;//inserting value.
	temp->next = head;//inserting address.
	head = temp;//copy temporery address to the head.
	return head;
}

void print(node *head)
{
	cout << "List is: ";
	while(head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	node *head = NULL;
	int n,x;
	
	cout << "How many numbers you want?" << endl;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cout << "Enter the number" << endl;
		cin >> x;
		head = insert(x, head);
		print(head);
	}
	free(head);
	return 0;
}