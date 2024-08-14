#include <iostream>
#include <vector>

int max_1d_range_sum(const std::vector<int>& niceness, int& start, int& end) {
    int max_sum = niceness[0];
    int current_sum = niceness[0];
    start = 0;
    end = 0;
    int temp_start = 0;

    for (int i = 1; i < niceness.size(); i++) {
        if (current_sum < 0) {
            current_sum = niceness[i];
            temp_start = i;
        } else {
            current_sum += niceness[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }
    return max_sum;
}

int main() {
    std::vector<int> niceness = {-3, -4, 5, -1, 2, -4, 6, -1};
    int start, end;
    int max_sum = max_1d_range_sum(niceness, start, end);

    if (max_sum > 0) {
        std::cout << "The nicest part of route is between stops " 
                  << start + 1 << " and " << end + 1 << std::endl;
    } else {
        std::cout << "Route has no nice parts" << std::endl;
    }

    return 0;
}
