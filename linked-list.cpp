#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *next;
};
node *head = NULL;
// insert value in back
void inserNode(int value);
// console the list to the log
void displayNode();
// delete certain value
void deletenode(int value);
// insert to the beginning
void insertBegin(int value);
// delete from the beginning
void delete_beg();
// delete node at the end
void delete_end();

int main()
{
    // testing
    inserNode(5);   // 5
    inserNode(15);  // 5 15
    inserNode(10);  // 5 15 10
    inserNode(1);   // 5 15 10 1
    deletenode(15); // 5 -  10 1
    insertBegin(9); // 9 5 -  10 1
    delete_beg();   //- 5 -  10 1
    displayNode();  // the result should be 5 10 1
}
void inserNode(int value)
{

    node *newNode, *last;
    newNode = new node;
    // adding the value to the newnode
    newNode->val = value;

    // adding the address
    // if it's the first item in the linked list
    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
    }
    // if it's not the first
    else
    {
        // finding the last node that has been added using new pointer named last
        last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        // then changing the adresses
        last->next = newNode;
        newNode->next = NULL;
    }
}

void displayNode()
{
    node *current_node;
    if (head == NULL)
        cout << "!There is no items yet..";
    else
    {
        current_node = head;
        while (true)
        {
            cout << current_node->val << ' ';
            current_node = current_node->next;
            if (current_node->next == NULL)
            {
                cout << current_node->val << ' ';
                break;
            }
        }
    }
}
void deletenode(int value)
{
    node *current, *prev;
    current = head;
    prev = head;
    // if the node that we want to delete is the first
    if (current->val == value)
    {
        head = current->next;
        free(current);
        return;
    }
    // make the current pointing to the target value and the prev to the one before current
    while (current->val != value)
    {
        prev = current;
        current = current->next;
    }
    // then make the prev point to the one after current and ignore current
    prev->next = current->next;
    delete (current);
}
void insertBegin(int value)
{
    node *new_node = new node;
    new_node->val = value;
    new_node->next = head;
    head = new_node;
}
void delete_beg()
{
    if (head == NULL)
        cout << "this list is empty already. \n";
    else
    {
        node *firstNode = head;
        head = firstNode->next;
        delete (firstNode); // or free (first node)
    }
}
void delete_end()
{
    if (head == NULL)
        cout << "this list is empty already. \n";
    else if (head->next == NULL)
    {
        delete (head);
        head = NULL;
    }
    else
    {
        node *ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        delete (ptr->next);
        ptr->next = NULL;
    }
}
