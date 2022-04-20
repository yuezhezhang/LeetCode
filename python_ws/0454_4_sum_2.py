# beyond time limit 
class Solution(object):
    def fourSumCount(self, nums1, nums2, nums3, nums4):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type nums3: List[int]
        :type nums4: List[int]
        :rtype: int
        """
        n = len(nums1)
        # Is there any duplicate in one list! yes!
        num_tuple = 0
        for i in set(nums1):
            for j in set(nums2):
                for k in set(nums3):
                    # count the frequency in nums4
                    # if it does not exist in the list, it returns 0
                    num_tuple += nums1.count(i) * nums2.count(j) * nums3.count(k) * nums4.count(-(i + j + k))
        return num_tuple

# time: 460ms, beat 49.52%
# RAM: 13.3 MB, beat 67.47%
class Solution2(object):
    def fourSumCount(self, nums1, nums2, nums3, nums4):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type nums3: List[int]
        :type nums4: List[int]
        :rtype: int
        """
        n = len(nums1)
        # Is there any duplicate in one list! yes!
        dict_12 = {}
        for i in nums1:
            for j in nums2:
                # get the value correspongding to the ky, if the key does not exist, then 0
                dict_12[i+j] = dict_12.get(i+j, 0) + 1

        num_tuple = 0
        for k in nums3:
            for l in nums4:
                num_tuple += dict_12.get(-k-l, 0)
        return num_tuple


if __name__ == "__main__":
    solution = Solution2()

    nums1 = [1, 2]
    nums2 = [-2, -1, -1]
    nums3 = [-1, 2, 2]
    nums4 = [0, 2]
    print(solution.fourSumCount(nums1, nums2, nums3, nums4))

    nums1 = [0]
    nums2 = [0]
    nums3 = [0, 0]
    nums4 = [0, 0]
    print(solution.fourSumCount(nums1, nums2, nums3, nums4))