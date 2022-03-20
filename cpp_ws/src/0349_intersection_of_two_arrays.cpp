#include "helper.cpp"
#include <unordered_map>
#include <algorithm>

// time: 4ms, beat 88.56%
// RAM: 10.2MB, beat 57.01%
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        // the map should store the frequencies of every number
        std::unordered_map<int, int> map1;
        std::vector<int> result;
        for (auto i = 0; i < nums1.size(); ++i) {
            ++map1[nums1[i]];
        }
        for (auto i = 0; i < nums2.size(); ++i) {
            auto iter = map1.find(nums2[i]);
            // check if nums[2] in nums1
            if (iter != map1.end()){
                // check if nums2[i] already in the result list to avoid duplicates
                // std::vector has no member find
                auto iter2 = std::find(result.begin(), result.end(), nums2[i]);
                if (iter2 ==  result.end()){
                    result.push_back(nums2[i]);
                }
            }
        }
        return result;
    }
};

// time: 8ms, beat 36.87%
// RAM: 9.7MB, beat 92.36%
class Solution2 {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        // initialize the result vector
        std::vector<int> result;
        for (auto i = 0; i < nums1.size(); ++i) {
            auto iter = std::find(nums2.begin(), nums2.end(), nums1[i]);
            // check if nums1[i] in nums2
            if (iter != nums2.end()){
                // check if nums1[i] already in the result list to avoid duplicates
                // std::vector has no member find
                auto iter2 = std::find(result.begin(), result.end(), nums1[i]);
                if (iter2 ==  result.end()){
                    result.push_back(nums1[i]);
                }
            }
        }
        return result;
    }
};


int main(){
    Solution2 solution;

    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    info(solution.intersection(nums1, nums2));  // [2]

    std::vector<int> nums3 = {4, 9, 5};
    std::vector<int> nums4 = {9, 4, 9, 8, 4};
    info(solution.intersection(nums3, nums4));  // [9, 4]
}