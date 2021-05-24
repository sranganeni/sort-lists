// MergeSortedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;



typedef struct _Node {
    int val;
    struct _Node* next;
}Node;

struct CustomCompare {
    bool operator() (const Node& lhs, const Node& rhs) { 
        return lhs.val >= rhs.val;
    }
};

void print_list(Node* node) {
    while (node) {
        cout << node->val << " " ;
        node = node->next;

    }
    cout << endl;
}

void make_lists(vector<Node*> &ls, int count) {
    int val = 1;
    for (int i = 0; i < count; i++) {
        Node* current = NULL;
        Node* head = NULL;
        for (int j = 0; j < 5 - i; j++) {
            Node* node = new Node;
            node->val = val++;
            node->next = NULL;
            if (current == NULL) {
                current = node;
                head = node;
            }
            else {
                current->next = node;
                current = current->next;
            }
        }
        ls.push_back(head);
        print_list(head);
    }
}

Node* merge_lists(vector<Node*>& lists) {
  
    priority_queue < Node, vector<Node>, CustomCompare> pq;
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != NULL) {
            pq.push(*lists[i]);
            lists[i] = lists[i]->next;
        }
    }

    Node* current = NULL;
    Node* head = NULL;
    while (pq.size()) {
        Node top = pq.top();
        Node *newNode = new Node;        
        newNode->val = top.val;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            current = newNode;
        }
        else {
            current->next = newNode;
            current = current->next;
        }
        pq.pop();
        if (top.next)
            pq.push(static_cast<Node>(*top.next));
    }
    return head;
    //print_list();
}

int main()
{
    //priority_queue <Node*, vector<Node*>, CustomCompare> pq;
    std::cout << "Hello World!\n";

    vector<Node*> sortedLists;
    make_lists(sortedLists, 5);
    Node* sortedList = NULL;
    sortedList = merge_lists(sortedLists);
    print_list(sortedList);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
