#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
    string data; 
    struct Node* prev; 
    struct Node* next; 
}; 

void rotate(struct Node** head_ref, int N) { 
    if (N == 0) 
        return; 
  
    struct Node* current = *head_ref; 
  
    int count = 1; 
    while (count < N && current != NULL) { 
        current = current->next; 
        count++; 
    } 
  
    if (current == NULL) 
        return; 

    struct Node* NthNode = current; 
  
    while (current->next != NULL) 
        current = current->next; 
  
    current->next = *head_ref; 
  
    (*head_ref)->prev = current; 
  
    *head_ref = NthNode->next; 
  
    (*head_ref)->prev = NULL; 
  
    NthNode->next = NULL; 
} 
 
void push(struct Node** head_ref, string new_data) { 
    struct Node* new_node =  new Node; 
    new_node->data = new_data; 
    new_node->prev = NULL; 
    new_node->next = (*head_ref); 
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
   *head_ref = new_node; 
} 
  
void printList(struct Node* node) { 
    while (node->next != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
    cout << node->data; 
} 
  
int main(void) { 
    struct Node* head = NULL; 
    int n, k;
    cin >> n >> k;
    string s;
    for (int i = 0; i < n; i++){
        // string s;
        cin >> s;
        push(&head, s); 
    }

    rotate(&head, n); 
    printList(head); 
  
    return 0; 
} 