#include <iostream>
#include <vector>

struct ListNode {
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* reverseList_doublePointer(ListNode* head) {
        ListNode* movingPtr = head;
        ListNode* reverseHead = nullptr;
        while (movingPtr) {
            ListNode* temp = movingPtr->next;
            movingPtr->next = reverseHead;
            reverseHead = movingPtr;
            movingPtr = temp;
        }
        return reverseHead;
    }

    ListNode* reverse(ListNode* movingPtr, ListNode* reverseHead) {
        if (!movingPtr) return reverseHead;
        ListNode* temp = movingPtr->next;
        movingPtr->next = reverseHead;
        return reverse(temp, movingPtr);
    }

    ListNode* reverseList_recursion(ListNode* head) {
        return reverse(head, nullptr);
    }
};

ListNode* create(const std::vector<int>& v) {
    if (v.empty()) return nullptr;
    auto* head = new ListNode(v.at(0), nullptr);
    ListNode* tail = head;
    for (int i = 1; i < v.size(); ++i) {
        auto* temp = new ListNode(v.at(i), nullptr);
        tail->next = temp;
        tail = temp;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* ptr = head;
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

    Solution s;
    std::vector<int> nums_1{1, 2, 3, 4, 5};
    ListNode* head_1 = create(nums_1);
    ListNode* res_1 = s.reverseList_doublePointer(head_1);
    printList(res_1);
    ListNode* head_1_recursion = create(nums_1);
    ListNode* res_1_recursion = s.reverseList_recursion(head_1_recursion);
    printList(res_1_recursion);
    std::cout << std::endl;

    std::vector<int> nums_2{1, 2};
    ListNode* head_2 = create(nums_2);
    ListNode* res_2 = s.reverseList_doublePointer(head_2);
    printList(res_2);
    ListNode* head_2_recursion = create(nums_2);
    ListNode* res_2_recursion = s.reverseList_recursion(head_2_recursion);
    printList(res_2_recursion);
    std::cout << std::endl;

    std::vector<int> nums_3{};
    ListNode* head_3 = create(nums_3);
    ListNode* res_3 = s.reverseList_doublePointer(head_3);
    printList(res_3);
    ListNode* head_3_recursion = create(nums_3);
    ListNode* res_3_recursion = s.reverseList_recursion(head_3_recursion);
    printList(res_3_recursion);
    std::cout << std::endl;

    return 0;
}
