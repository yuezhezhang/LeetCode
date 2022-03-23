#include "helper.cpp"
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

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
        // declare the result vector
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

// time: 4ms, beat 88.58%
// RAM: 9.6MB, beat 95.61%
// use std::set_intersection, efficient in memory
class Solution3 {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        // sort and get the unique values 
        // ref: https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector
        std::sort(nums1.begin(), nums1.end());
        nums1.erase(std::unique(nums1.begin(), nums1.end()), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        nums2.erase(std::unique(nums2.begin(), nums2.end()), nums2.end());
        // declare the result vector
        std::vector<int> result;
        // use the library ref: https://en.cppreference.com/w/cpp/algorithm/set_intersection
        std::set_intersection(nums1.begin(), nums1.end(),
                              nums2.begin(), nums2.end(),
                              std::back_inserter(result));
        return result;
    }
};


// time: 0ms, beat 100%
// RAM: 10.3MB, beat 32.38%
// use unordered_set, which is space demanding and sometimes slower than array
class Solution4 {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> result_set; 
        std::unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // find element in nums2 which also appears in nums1_set
            if (nums1_set.find(num) != nums1_set.end()) {
                result_set.insert(num);
            }
        }
        return std::vector<int>(result_set.begin(), result_set.end());
    }
};


int main(){
    Solution4 solution;

    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    info(solution.intersection(nums1, nums2));  // [2]

    std::vector<int> nums3 = {4, 9, 5};
    std::vector<int> nums4 = {9, 4, 9, 8, 4};
    info(solution.intersection(nums3, nums4));  // [9, 4]
}