#include <iostream>
#include <vector>
#include <exception>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int length = nums.size();
        if (length <= 1) throw "The input does not meet the requirement";

        std::vector<int> result_index;
        int flag = 0;

        for (auto i=0; i<length; ++i)
        {
            for (auto j = 0; j<length; ++j)
            {
                if ((i < j) && (nums[i]+nums[j] == target) )
                {   
                    flag = 1;
                    result_index.push_back(i);
                    result_index.push_back(j);
                }
            } 
        }
        if (flag == 0)
            std::cout << "There is no soution" << std::endl; 
        return result_index;
    }

    void info(std::vector<int> result_index)
    {
        for (auto i=0; i<result_index.size(); ++i)
            std::cout << result_index[i] << std::endl;
    }
};


int main(){
    Solution solution;

    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result_index1 = solution.twoSum(nums1, target1);
    solution.info(result_index1);

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result_index2 = solution.twoSum(nums2, target2);
    solution.info(result_index2);

    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result_index3 = solution.twoSum(nums3, target3);
    solution.info(result_index3);



}