class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(nums)
        if length <= 1:
            print("The input does not meet the requirement")
            return 0

        result_index = []
        flag = 0 
        for i in range(length):
            for j in range(i+1, length):
                if (nums[i] + nums[j] == target):
                    flag = 1
                    result_index.append(i)
                    result_index.append(j)

        if flag == 0:
            print("There is no soution")

        return result_index

if __name__ == "__main__":
    solution = Solution()

    nums0 = [2]
    target0 = 9
    result_index0 = solution.twoSum(nums0, target0)
    # print(result_index0)

    nums1 = [2, 7, 11, 15]
    target1 = 9
    result_index1 = solution.twoSum(nums1, target1)
    print(result_index1)

    nums2 = [3,2,4]
    target2 = 6
    result_index2 = solution.twoSum(nums2, target2)
    print(result_index2)

    nums3 = [3,3]
    target3 = 6
    result_index3 = solution.twoSum(nums3, target3)
    print(result_index3)

    nums4 = [4,3]
    target4 = 6
    result_index4 = solution.twoSum(nums4, target4)
    # print(result_index4)