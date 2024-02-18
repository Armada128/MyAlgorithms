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
    ListNode* removeElements_raw(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        ListNode* movingPtr = head;
        while (movingPtr != nullptr && movingPtr->next != nullptr) {
            if (movingPtr->next->val == val) {
                ListNode* temp = movingPtr->next;
                movingPtr->next = movingPtr->next->next;
                delete temp;
            } else movingPtr = movingPtr->next;
        }
        return head;
    }

    ListNode* removeElements_virtualHead(ListNode* head, int val) {
        auto* virtualHead = new ListNode(0, head);
        ListNode* movingPtr = virtualHead;
        while (movingPtr->next != nullptr) {
            if (movingPtr->next->val == val) {
                ListNode* temp = movingPtr->next;
                movingPtr->next = movingPtr->next->next;
                delete temp;
            } else movingPtr = movingPtr->next;
        }
        return virtualHead->next;
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
    std::vector<int> nums_1{1, 2, 6, 3, 4, 5, 6};
    ListNode* head_1 = create(nums_1);
    ListNode* res_1 = s.removeElements_raw(head_1, 6);
    printList(res_1);
    ListNode* head_1_virtualHead = create(nums_1);
    ListNode* res_1_virtualHead = s.removeElements_virtualHead(head_1_virtualHead, 6);
    printList(res_1_virtualHead);
    std::cout << std::endl;

    std::vector<int> nums_2{};
    ListNode* head_2 = create(nums_2);
    ListNode* res_2 = s.removeElements_raw(head_2, 1);
    printList(res_2);
    ListNode* head_2_virtualHead = create(nums_2);
    ListNode* res_2_virtualHead = s.removeElements_raw(head_2_virtualHead, 1);
    printList(res_2_virtualHead);
    std::cout << std::endl;

    std::vector<int> nums_3{7, 7, 7, 7};
    ListNode* head_3 = create(nums_3);
    ListNode* res_3 = s.removeElements_raw(head_3, 7);
    printList(res_3);
    ListNode* head_3_virtualHead = create(nums_3);
    ListNode* res_3_virtualHead = s.removeElements_raw(head_3_virtualHead, 7);
    printList(res_3_virtualHead);

    return 0;
}
