class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # list.sort() returns the list in place, it does not return a new list
        # answer = sorted(list) will return a new list
        list_s = list(s)
        list_s.sort()
        list_t = list(t)  
        list_t.sort()
        return list_s == list_t 


if __name__ == "__main__":
    solution = Solution()

    s1 = "anagram"
    t1 = "nagaram"
    print(solution.isAnagram(s1, t1))

    s2 = "rat"
    t2 = "car"
    print(solution.isAnagram(s2, t2))