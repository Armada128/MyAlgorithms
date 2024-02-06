#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
        int row = 0, column = 0, rim = 1, temp = 1;
        while (rim <= 0.5 * n) {
            while (column < n - rim) res.at(row).at(column++) = temp++;
            while (row < n - rim) res.at(row++).at(column) = temp++;
            while (column >= rim) res.at(row).at(column--) = temp++;
            while (row >= rim) res.at(row--).at(column) = temp++;
            ++row;
            ++column;
            ++rim;
        }
        if (n % 2) res.at(row).at(column) = temp;
        return res;
    }
};

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    std::cout << "[";
    for (int i = 0; i < matrix.size(); ++i) {
        auto row = matrix.at(i);
        std::cout << "[";
        for (int j = 0; j < row.size(); ++j) {
            std::cout << row.at(j);
            if (j < row.size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (i < matrix.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    Solution s;
    auto matrix_1 = s.generateMatrix(3);
    printMatrix(matrix_1);

    auto matrix_2 = s.generateMatrix(2);
    printMatrix(matrix_2);

    auto matrix_3 = s.generateMatrix(4);
    printMatrix(matrix_3);

    return 0;
}
