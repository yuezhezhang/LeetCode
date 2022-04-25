# time: 20ms beat 93.65%%
# RAM: 14MB beat 22.38% 
# Use list to store the visited elements
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left = 0
        right = len(nums)
        i = int((left+right)/2)
        # check if on target before entering the loop
        visited_list = [i]
        while nums[i] != target:
            if nums[i] > target:
                right = i
            elif nums[i] < target:
                left = i
            i = int((left+right)/2)
            if i in visited_list:
                return -1
            else: 
                visited_list.append(i)
        return i


if __name__ == "__main__":
    solution = Solution()

    nums = [-1,0,3,5,9,12]
    target = 9
    print(solution.search(nums, target))  # 4

    nums = [-1,0,3,5,9,12]
    target = 2
    print(solution.search(nums, target)) # -1

    nums = [-5,-4,-3,-2,-1,0,1,2,3,4]
    target = -4
    print(solution.search(nums, target)) # 1

    nums = [2, 5]
    target = 5
    print(solution.search(nums, target)) # 1

    nums = [2, 5]
    target = 2
    print(solution.search(nums, target)) # 0

    nums = [5]
    target = 5
    print(solution.search(nums, target)) # 0

    nums = [2, 3, 5]
    target = 2
    print(solution.search(nums, target)) # 0

    nums = [2, 3, 5]
    target = 5
    print(solution.search(nums, target)) # 2

    nums = [-1,0,3,5,9,12]
    target = 3
    print(solution.search(nums, target)) # 2

