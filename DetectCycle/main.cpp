#include <iostream>
#include <vector>

struct ListNode {
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
    int val;
    ListNode* next;
};
/* 快指针和慢指针相遇时：x = (n - 1) * (y - z) + z
 * 其中，
 * x: 链表头至环入口距离
 * y: 环入口顺时针至相遇点距离
 * z: 相遇点顺时针至环入口距离
 * 对于上式的理解：
 * 假设有两个指针a, b
 * a从链表头出发，最终停于环入口（走过距离x）
 * b从相遇点出发，沿环顺时针移动，经过(n - 1)圈后位于相遇点（走过距离(n - 1) * (y - z)），继续移动z，最终停于快慢指针相遇点（走过(n - 1) * (y - z) + z）
 * 因此，只要a和b相遇，则必定相遇于环入口
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        auto* fast = head;
        auto* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                auto* a = head;
                auto* b = fast;
                while (a != b) {
                    a = a->next;
                    b = b->next;
                }
                return a;
            }
        }
        return nullptr;
    }
};

ListNode* create(const std::vector<int>& v, int entryIndex) {
    if (v.empty()) return nullptr;
    auto* head = new ListNode(v.at(0), nullptr);
    ListNode* tail = head;
    ListNode* entry = nullptr;
    if (entryIndex == 0) entry = tail;
    for (int i = 1; i < v.size(); ++i) {
        auto* temp = new ListNode(v.at(i), nullptr);
        tail->next = temp;
        tail = temp;
        if (entryIndex == i) entry = tail;
    }
    if (entry) tail->next = entry;
    return head;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    Solution s;
    std::vector<int> nums_1{3, 2, 0, -4};
    ListNode* head_1 = create(nums_1, 1);
    ListNode* res_1 = s.detectCycle(head_1);
    if (res_1) std::cout << res_1->val << std::endl;
    else std::cout << "null" << std::endl;

    std::vector<int> nums_2{1, 2};
    ListNode* head_2 = create(nums_2, 0);
    ListNode* res_2 = s.detectCycle(head_2);
    if (res_2) std::cout << res_2->val << std::endl;
    else std::cout << "null" << std::endl;

    std::vector<int> nums_3{3, 2, 0, -4};
    ListNode* head_3 = create(nums_3, -1);
    ListNode* res_3 = s.detectCycle(head_3);
    if (res_3) std::cout << res_3->val << std::endl;
    else std::cout << "null" << std::endl;

    return 0;
}
