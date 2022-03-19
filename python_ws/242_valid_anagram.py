class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # list.sort() returns the list in place, it does not return a new list
        # answer = sorted(list) will return a new list

        # The sorted() function returns a sorted list of the specified iterable object.

        # Iterable object, can iterate via for loop, including sequential and non-sequential
        # sequential: lists, tuples, and strings
        # non-sequential: dicts, sets
        # non-iterable: such as int object

        # Functions that act on iterables: sorted, max, min, any, all
        return sorted(s) == sorted(t) 


if __name__ == "__main__":
    solution = Solution()

    s1 = "anagram"
    t1 = "nagaram"
    print(solution.isAnagram(s1, t1))

    s2 = "rat"
    t2 = "car"
    print(solution.isAnagram(s2, t2))