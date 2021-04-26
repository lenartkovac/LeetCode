"""
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
- 0 <= a, b, c, d < n
- a, b, c, and d are distinct.
- nums[a] + nums[b] + nums[c] + nums[d] == target
"""

import numpy as np

class Solution:
    #def __init__(self):
    #    self.arrays = []

    def makeQuadruplets(self, nums: [int], target: int, arr=[], index=0):

        if len(arr) == 4:
            if np.sum(arr) == target:
                #print(arr)
                arr = np.sort(arr).tolist()
                if not arr in self.arrays:
                    self.arrays.append(np.copy(arr).tolist())
                #newArr = np.copy(arr)
                #self.arrays.append(np.sort(newArr).tolist())
                #arrayList.append(newArr.tolist())
                return

        if index >= len(nums):
            return

        sum = np.sum(arr)

        arr.append(nums[index])
        self.makeQuadruplets(nums, target, arr, index + 1)
        arr.pop()
        self.makeQuadruplets(nums, target, arr, index + 1)

    #def filterUnique(self):
    #    temp = []
    #    for array in self.arrays:
    #        if not array in temp:
    #            temp.append(array)
    #    self.arrays = temp


    def fourSum(self, nums: [int], target: int) -> [[int]]:
        self.arrays = []
        self.makeQuadruplets(nums, target)
        #print(self.arrays)
        return self.arrays

s = Solution()

#print(s.makeQuadruplets([1, 0, -1, 0, -2, 2], 0, arrayList=[]))
#print(s.arrays)
#print(s.fourSum([1, 0, -1, 0, -2, 2], 0))
#print(s.fourSum([2, 2, 2, 2, 2], 8))
print(s.fourSum([6,-7,-8,-8,-9,-5,5,1,-4,9,-4,-3,0,0,0,-6,6,7], 29))
#result = s.fourSum([2, 2, 2, 2, 2], 8)
#print(result[0] == result[1])

#print(s.makeQuadruplets([2, 2, 2, 2, 2], 8, arrayList=[]))
#print(s.arrays)