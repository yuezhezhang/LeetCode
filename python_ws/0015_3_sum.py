# exceeds the time limit
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3:
            return []
        else:
            dict_12 = {}
            dict = {}
            result_list = []
            for i in range(len(nums)):
                for j in range(i+1, len(nums)):
                    if nums[i] + nums[j] not in dict_12.keys():
                        dict_12[nums[i]+nums[j]] = [(i, j)]
                    else:
                        dict_12[nums[i]+nums[j]].append((i, j))
            for i in range(len(nums)):
                if nums[i] not in dict.keys():
                    dict[nums[i]] = [i]
                else:
                    dict[nums[i]].append(i)
            for i in dict_12.keys():
                if -i in dict.keys():
                    for pair in dict_12[i]:
                        for idx in dict[-i]:
                            # ensure different idx
                            if idx not in pair:
                                # avoid duplicate
                                result = [nums[idx], nums[pair[0]], nums[pair[1]]]
                                result.sort()
                                if result not in result_list:
                                    result_list.append(result)
            return result_list

# still exceeds the time limit
class Solution2(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3:
            return []
        else:
            result_list = []
            for i in range(len(nums)):
                for j in range(i+1, len(nums)):
                    for k in range(j+1, len(nums)):
                        if nums[i]+nums[j]+nums[k] == 0:
                            # avoid duplicate
                            result = [nums[i], nums[j], nums[k]]
                            result.sort()
                            if result not in result_list:
                                result_list.append(result)
            return result_list

if __name__ == "__main__":
    solution = Solution2()

    nums = [-1,0,1,2,-1,-4]
    print(solution.threeSum(nums)) # [[-1,-1,2],[-1,0,1]]

    nums = []
    print(solution.threeSum(nums)) # []

    nums = [0]
    print(solution.threeSum(nums)) # []

    nums = [1,2,3,4,5,6]
    print(solution.threeSum(nums)) # []

    nums = [1,2,3,4,5,6,-7]
    print(solution.threeSum(nums)) # []

    nums = [1,2,-3]
    print(solution.threeSum(nums)) # []