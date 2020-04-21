import java.util.Arrays;

public class Problem {

    public static int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        for (int i = 0; i < nums.length; ++i) {
            for (int j = i + 1; j < nums.length; ++j) {
                if (nums[i] + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        // ? example input
        int[] test = {2, 7, 11, 15};
        System.out.println(Arrays.toString(twoSum(test, 9)));
    }
}