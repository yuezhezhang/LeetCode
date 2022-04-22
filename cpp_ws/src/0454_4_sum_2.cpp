#include "helper.cpp" 
#include "map"

// time: 372ms, beat 5.07%
// RAM: 24.2MB, beat 9.98%
class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
        int n = nums1.size();
        std::map<int, int>  map_12;   
        // assign the sum of the two vectors to frequencies 
        for (int i : nums1){
            for (int j : nums2){  
                map_12[i+j] ++;
            }
        }

        // show the contents of the map 
        for(const auto& elem : map_12){
            std::cout << elem.first << " => " << elem.second << "\n";
        }

        int num_tuple = 0;
        for (int k : nums3){
            for (int l : nums4){
                num_tuple += map_12[-k-l];
            }
        }
        
        return num_tuple;
    }
};

int main(){
    Solution solution;

    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {-2, -1};
    std::vector<int> nums3 = {-1, 2};
    std::vector<int> nums4 = {0, 2};
    std::cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << std::endl;

    std::vector<int> nums5 = {0};
    std::vector<int> nums6 = {0, 0};
    std::vector<int> nums7 = {0};
    std::vector<int> nums8 = {0};
    std::cout << solution.fourSumCount(nums5, nums6, nums7, nums8) << std::endl;
}