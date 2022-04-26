#include "helper.cpp"

// time: 44ms, beat 7.74%
// RAM: 26.9MB, beat 54.15%
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int i = (left + right)/2;
        while (nums[i] != target){
            if (right == left + 1)
                return -1;
            if (nums[i] > target)
                right = i;
            else if (nums[i] < target)
                left = i;
            i = (left + right)/2;
        }
        return i;
    }
};

// time: 20ms, beat 93.89%
// RAM: 27MB, beat 6.1%
// target belongs to [left, right]
class Solution2 {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right){
            int i = left + (right - left)/2;
            if (nums[i] < target)
                left = i + 1;
            else if (nums[i] > target)
                right = i - 1;
            else
                return i;
        }
        return -1;
    }
};


int main(){
    Solution2 solution;

    std::vector<int> nums1 = {-1,0,3,5,9,12};
    int target1 = 9;
    std::cout << solution.search(nums1, target1) << std::endl; // 4

    std::vector<int> nums2 = {-1,0,3,5,9,12};
    int target2 = 2;
    std::cout << solution.search(nums2, target2) << std::endl; // -1

    std::vector<int> nums3 = {-5,-4,-3,-2,-1,0,1,2,3,4};
    int target3 = -4;
    std::cout << solution.search(nums3, target3) << std::endl; // 1

    std::vector<int> nums4 = {2, 5};
    int target4 = 5;
    std::cout << solution.search(nums4, target4) << std::endl; // 1

    std::vector<int> nums5 = {2, 5};
    int target5 = 2;
    std::cout << solution.search(nums5, target5) << std::endl; // 0

    std::vector<int> nums6 = {5};
    int target6 = 5;
    std::cout << solution.search(nums6, target6) << std::endl; // 0

    std::vector<int> nums7 = {2, 3, 5};
    int target7 = 2;
    std::cout << solution.search(nums7, target7) << std::endl; // 0

    std::vector<int> nums8 = {2, 3, 5};
    int target8 = 5;
    std::cout << solution.search(nums8, target8) << std::endl; // 2

    std::vector<int> nums9 = {-1,0,3,5,9,12};
    int target9 = 3;
    std::cout << solution.search(nums9, target9) << std::endl; // 2
}