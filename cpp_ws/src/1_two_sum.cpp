#include <iostream>
#include <vector>
#include <exception>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // get the lengthe of the vector
        int length = nums.size();
        if (length <= 1) throw "The input does not meet the requirement";

        // instance the result vector
        std::vector<int> result_index;
        int flag = 0;

        // start iteration
        for (auto i = 0; i < length; ++i)
        {
            for (auto j = i+1; j < length; ++j)
            {
                if (nums[i] + nums[j] == target)
                {   
                    flag = 1;
                    result_index.push_back(i);
                    result_index.push_back(j);
                }
            } 
        }

        // check if the solution found
        if (flag == 0)
            std::cout << "There is no soution" << std::endl; 
        
        return result_index;
    }

    void info(std::vector<int> result_index)
    {   
        int length = result_index.size();
        if (length > 1)
        {
            std::cout << "The vector is: [";
            for (auto i = 0; i < length - 1; ++i)
                std::cout << result_index[i] << ", ";
            std::cout << result_index[length-1] << "]" << std::endl;
        }
    }
};


int main(){
    Solution solution;

    std::vector<int> nums0 = {2};
    int target0 = 7;
    try
    {
        std::vector<int> result_index0 = solution.twoSum(nums0, target0);
    }
    catch (const char* msg)
    {
        std::cerr<< msg << std::endl;
    }

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

    std::vector<int> nums4 = {4, 3};
    int target4 = 6;
    std::vector<int> result_index4 = solution.twoSum(nums4, target4);
    solution.info(result_index4);
}