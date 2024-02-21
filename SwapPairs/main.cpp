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
    ListNode *swapPairs(ListNode *head) {
        auto* virtualHead = new ListNode(0, head);
        auto* movingPtr = virtualHead;
        while (movingPtr->next && movingPtr->next->next) {
            ListNode* firstNode = movingPtr->next;
            ListNode* secondNode = movingPtr->next->next;
            ListNode* thirdNode = movingPtr->next->next->next;
            movingPtr->next = secondNode;
            secondNode->next = firstNode;
            firstNode->next = thirdNode;
            movingPtr = firstNode;
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
    std::vector<int> nums_1{1, 2, 3, 4};
    ListNode* head_1 = create(nums_1);
    ListNode* res_1 = s.swapPairs(head_1);
    printList(res_1);

    std::vector<int> nums_2{};
    ListNode* head_2 = create(nums_2);
    ListNode* res_2 = s.swapPairs(head_2);
    printList(res_2);

    std::vector<int> nums_3{1};
    ListNode* head_3 = create(nums_3);
    ListNode* res_3 = s.swapPairs(head_3);
    printList(res_3);

    return 0;
}
