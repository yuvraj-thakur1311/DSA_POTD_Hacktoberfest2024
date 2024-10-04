// link : https://www.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
    if (head == nullptr || head->next == head) {
        return head; 
        // No reversal needed for an empty or single-node list
    }

    Node* prv = nullptr;
    Node* tmp = head;
    Node* nxt = head->next;
    
    // Traverse the circular list and reverse the links
    while (tmp->next != head) {
        tmp->next = prv;
        prv = tmp;
        tmp = nxt;
        nxt = nxt->next;
    }
    
    // Reverse the last node
    tmp->next = prv;

    // Adjust the last node to point to the new head (which is the last node processed)
    head->next = tmp;

    // Update the head to the last node
    head = tmp;

    return head;
}


    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
    // If the list is empty, return nullptr
    if (head == nullptr) {
        return nullptr;
    }

    Node* tmp = head;
    Node* nxt = head->next;
    
    // If the node to be deleted is the head node
    if (head->data == key) {
        // Case where there is only one node in the list
        if (head->next == head) {
            delete head;
            return nullptr;
        }
        
        // Find the last node
        while (nxt != head) {
            tmp = nxt;
            nxt = nxt->next;
        }
        
        // Point the last node to the new head (head->next)
        tmp->next = head->next;
        delete head;
        head = tmp->next;
        return head;
    }

    // Traverse the list to find the node with the key
    while (nxt != head) {
        if (nxt->data == key) {
            tmp->next = nxt->next;
            delete nxt;
            return head;
        }
        tmp = nxt;
        nxt = nxt->next;
    }
    
    // Return the original head if the key is not found
    return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends