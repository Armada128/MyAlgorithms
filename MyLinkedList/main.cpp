#include <iostream>

class MyLinkedList {
public:
    struct MyNode {
        MyNode(int val, MyNode* next) : val(val), next(next) {}
        int val;
        MyNode* next;
    };

    MyLinkedList() : virtualHead(new MyNode(0, nullptr)), size(0) {}

    int get(int index) {
        if (index < 0 || index >= size) throw std::out_of_range("out of list range!");
        MyNode* movingPtr = virtualHead->next;
        while (index) {
            if (movingPtr) {
                movingPtr = movingPtr->next;
                index--;
            }
            else throw std::invalid_argument("null pointer!");
        }
        return movingPtr->val;
    }

    void addAtHead(int val) {
        auto* head = new MyNode(val, nullptr);
        if (virtualHead->next) head->next = virtualHead->next;
        virtualHead->next = head;
        ++size;
    }

    void addAtTail(int val) {
        auto movingPtr = virtualHead->next;
        while (movingPtr->next) movingPtr = movingPtr->next;
        auto* tail = new MyNode(val, nullptr);
        movingPtr->next = tail;
        ++size;
    }

    void addAtIndex(int index, int val) {
        auto movingPtr = virtualHead->next;
        while (--index) movingPtr = movingPtr->next;
        auto* newNode = new MyNode(val, movingPtr->next);
        movingPtr->next = newNode;
        ++size;
    }

    void deletAtIndex(int index) {
        auto movingPtr = virtualHead->next;
        while (--index) movingPtr = movingPtr->next;
        MyNode* temp = movingPtr->next;
        movingPtr->next = movingPtr->next->next;
        delete temp;
        --size;
    }

    MyNode* getHead() { return virtualHead->next; }

private:
    MyNode* virtualHead;
    unsigned long size;
};

void printList(MyLinkedList::MyNode* head) {
    if (!head) return;
    MyLinkedList::MyNode* ptr = head;
    std::cout << "[";
    while (ptr) {
        int val = ptr->val;
        std::cout << val;
        if (ptr->next) std::cout << ", ";
        ptr = ptr->next;
    }
    std::cout << "]" << std::endl;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    auto* myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    printList(myLinkedList->getHead());
    myLinkedList->addAtTail(3);
    printList(myLinkedList->getHead());
    myLinkedList->addAtIndex(1, 2);
    printList(myLinkedList->getHead());
    try {
        std::cout << "element at index 1: " <<  myLinkedList->get(1) << std::endl;
    } catch (std::out_of_range& e) {

    } catch (std::invalid_argument& e) {

    }
    myLinkedList->deletAtIndex(1);
    printList(myLinkedList->getHead());
    try {
        std::cout << "element at index 1: " << myLinkedList->get(1) << std::endl;
    } catch (std::out_of_range& e) {

    } catch (std::invalid_argument& e) {

    }
    return 0;
}
