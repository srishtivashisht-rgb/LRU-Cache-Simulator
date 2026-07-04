#include <iostream>
#include <unordered_map>

using namespace std;

// Node of Doubly Linked List
class Node {
public:
    int key;
    string value;
    Node* prev;
    Node* next;

    Node(int k, string v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {

private:

    int capacity;

    unordered_map<int, Node*> cache;

    Node* head;
    Node* tail;

public:

    LRUCache(int cap) {

        capacity = cap;

        head = nullptr;
        tail = nullptr;
    }
    void addToFront(Node* node) {

    node->next = head;
    node->prev = nullptr;

    if (head != nullptr)
        head->prev = node;

    head = node;

    if (tail == nullptr)
        tail = node;
}

// Remove a node from the list
void removeNode(Node* node) {

    if (node->prev != nullptr)
        node->prev->next = node->next;
    else
        head = node->next;

    if (node->next != nullptr)
        node->next->prev = node->prev;
    else
        tail = node->prev;
}

// Move a node to the front
void moveToFront(Node* node) {

    removeNode(node);
    addToFront(node);
}
string get(int key) {

    if (cache.find(key) == cache.end()) {
        return "Key Not Found!";
    }

    Node* node = cache[key];

    moveToFront(node);

    return node->value;
}
void put(int key, string value) {

    // Key already exists
    if (cache.find(key) != cache.end()) {

        Node* node = cache[key];
        node->value = value;

        moveToFront(node);

        return;
    }

    // Create new node
    Node* newNode = new Node(key, value);

    // Cache Full
    if (cache.size() == capacity) {

        Node* temp = tail;
        cache.erase(temp->key);
        removeNode(temp);
        delete temp;
    }

    addToFront(newNode);

    cache[key] = newNode;
}
void display() {

    if (head == nullptr) {
        cout << "\nCache is Empty!\n";
        return;
    }

    cout << "\nMost Recently Used --> Least Recently Used\n";

    Node* temp = head;

    while (temp != nullptr) {
        cout << "[" << temp->key << " : " << temp->value << "] ";
        temp = temp->next;
    }

    cout << endl;
}

};

int main() {

    int capacity;

    cout << "===== LRU Cache Simulator =====" << endl;
    cout << "Enter Cache Capacity: ";
    cin >> capacity;

    LRUCache cache(capacity);

    int choice;
    int key;
    string value;

    do {

        cout << "\n===== MENU =====" << endl;
        cout << "1. Put" << endl;
        cout << "2. Get" << endl;
        cout << "3. Display Cache" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter Key: ";
                cin >> key;

                cout << "Enter Value: ";
                cin >> value;

                cache.put(key, value);
                break;

            case 2:
                cout << "Enter Key: ";
                cin >> key;

                cout << "Value: " << cache.get(key) << endl;
                break;

            case 3:
                cache.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 4);

    return 0;
}