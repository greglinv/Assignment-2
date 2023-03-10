#include "single_linked_list.h"

using namespace std;

Single_Linked_List::Single_Linked_List() {
    headPtr = nullptr;
}


//Add an item to the front
void Single_Linked_List::push_front(const string item) {
    Node* newNode = new Node;
    newNode->data = item;
    if (empty()) {
        headPtr = tailPtr = newNode;
        newNode->next = nullptr;
    }
    else {
        newNode->next = headPtr;
        headPtr = newNode;
    }
    ++num_items;
}

//Add an item to the back
void Single_Linked_List::push_back(const string item) {
    Node* newNode = new Node;
    newNode->data = item;
    if (empty()) {
        headPtr = tailPtr = newNode;
        newNode->next = nullptr;
    }
    else {
        tailPtr->next = newNode;
        tailPtr = newNode;
    }
    ++num_items;
}

//Remove the item at the front
void Single_Linked_List::pop_front() {
    if (headPtr == nullptr) {
        return;
    }
    Node* temp = headPtr;
    headPtr = headPtr->next;
    delete temp;
    --num_items;
    if (headPtr == nullptr) {
        tailPtr = nullptr;
    }
}

//Remove the item at the back
void Single_Linked_List::pop_back() {
    if (tailPtr == nullptr) {
        return;
    }
    if (headPtr == tailPtr) {
        delete headPtr;
        headPtr = tailPtr = nullptr;
    }
    else {
        Node* temp = headPtr;
        while (temp->next != tailPtr) {
            temp = temp->next;
        }
        delete tailPtr;
        tailPtr = temp;
        tailPtr->next = nullptr;
    }
    --num_items;
}

//Add an item at a specific index
void Single_Linked_List::insert(size_t index, string item) {
    if (index > num_items) {
        index = num_items;
    }
    if (index == 0) {
        push_front(item);
    }
    else if (index == num_items) {
        push_back(item);
    }
    else {
        Node* temp = headPtr;
        for (size_t i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        Node* newNode = new Node;
        newNode->data = item;
        temp->next = newNode;
        ++num_items;
    }
}

//Remove a specific item then return if it got removed
bool Single_Linked_List::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    }
    else if (index == num_items - 1) {
        pop_back();
    }
    else {
        Node* temp = headPtr;
        for (size_t i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        Node* nodeDelete = temp->next;
        temp->next = nodeDelete->next;
        delete nodeDelete;
        --num_items;
    }
    return true;
}

//Return the index of a specific item
size_t Single_Linked_List::find(const string item) {
    Node* temp = headPtr;
    size_t index = 0;
    while (temp != nullptr && temp->data != item) {
        temp = temp->next;
        ++index;
    }
    return index == num_items ? num_items : index;
}

//return the item at the front
string Single_Linked_List::front() {
    return headPtr->data;
}

//return the item at the back
string Single_Linked_List::back() {
    return tailPtr->data;
}

//check if the list is empty
bool Single_Linked_List::empty() {
    return num_items == 0;
}