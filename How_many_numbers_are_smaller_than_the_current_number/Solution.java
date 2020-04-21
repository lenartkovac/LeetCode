import java.util.Arrays;

public class Solution {
    public static int[] smallerNumbersThanCurrent(int[] nums) {
        return Arrays.stream(nums)
            .map(num -> 
                (int)Arrays.stream(nums)
                .filter(i -> i < num)
                .count()
            )
            .toArray();
    }

    public static void main(String[] args) {
        int[] nums = {8, 1, 2, 2, 3};
        int[] result = smallerNumbersThanCurrent(nums);
        System.out.println(Arrays.toString(result));
    }
}