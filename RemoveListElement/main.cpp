#include <iostream>
#include <vector>

struct ListNode {
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(nullptr) {};
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

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
    printList(head_1);

    std::vector<int> nums_2{};
    ListNode* head_2 = create(nums_2);
    printList(head_2);

    std::vector<int> nums_3{7, 7, 7, 7};
    ListNode* head_3 = create(nums_3);
    printList(head_3);

    return 0;
}
