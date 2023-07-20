// Inserting data at the beginning using liked list.
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *insert(int x, node *head)
{
    node *temp = new node();
    temp->data = x;    // inserting value.
    temp->next = head; // inserting address.
    head = temp;       // copy temporery address to the head.
    return head;
}

void print(node *head)
{
    cout << "List is: ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *middle(node *start, node *last)
{
    if (start == NULL)
        return NULL;

    node *slow = start, *fast = start;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *bianary(node *head, int value)
{
    node *start = head;
    node *last = NULL;
    do
    {
        node *mid = middle(start, last);
        if (mid == NULL)
            return NULL;

        if (mid->data == value)
            return mid;
        // to move rightward direction.
        else if (mid->data < value)
            start = mid->next;
        // to move leftward direction.
        else
            last = mid;

    } while (last == NULL || last != start);
    return NULL; // if value not found.
}

int main()
{
    node *head = NULL;
    int n, x;

    cout << "How many numbers you want?" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number" << endl;
        cin >> x;
        head = insert(x, head);
        print(head);
    }
    int value;
    cout << "Enter a value\n";
    cin >> value;
    if(bianary(head,value) == NULL)
    {
        cout << "Not found\n";
    }
    else
    {
        cout << "present\n";
    }
    return 0;
}