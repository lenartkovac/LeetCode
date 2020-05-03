import java.util.Arrays;

// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// The number of elements initialized in nums1 and nums2 are m and n respectively.
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

// Example:
//
// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3
//
// Output: [1,2,2,3,5,6]

class Solution {
    public void merge (int[] nums1, int m, int[] nums2, int n) {
        assert nums1.length >= m + n;
        n--; m--;
        int index = nums1.length - 1;

        while (n >= 0 || m >= 0) {
            int n1 = m >= 0 ? nums1[m] : Integer.MIN_VALUE;
            int n2 = n >= 0 ? nums2[n] : Integer.MIN_VALUE;
            if (n1 > n2) {
                nums1[index--] = nums1[m--];
            }
            else {
                nums1[index--] = nums2[n--];
            }
        }
    }
}

public class Program {

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 0, 0, 0};
        int[] nums2 = {2, 5, 6};
        Solution s = new Solution();

        s.merge(nums1, 3, nums2, 3);

        System.out.println(Arrays.toString(nums1));
    }
}