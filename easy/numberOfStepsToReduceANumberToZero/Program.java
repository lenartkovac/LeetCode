import java.util.Scanner;

class Solution {
    public int numOfSteps(int num) {
        int steps = 0;
        while (num != 0) {
            if (num % 2 == 0) 
                num = num / 2;
            else 
                num = num - 1;
            steps++;
        }

        return steps;
    }
}

public class Program {
    public static void main(String[] args) {
        int num = new Scanner(System.in).nextInt();
        Solution solution = new Solution();
        System.out.println(num);
        System.out.println(solution.numOfSteps(num));
    }
}