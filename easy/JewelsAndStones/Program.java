import java.util.Scanner;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.Collectors;
import java.util.HashSet;

class Solution {
    public int numJewelsInStones(String J, String S) {
        HashSet<Character> jewels = 
            new HashSet<Character>(
                J.chars()
                    .mapToObj(c -> (Character)(char)c)
                    .collect(Collectors.toList())
            );

        AtomicInteger numJewels = new AtomicInteger(0);
        S.chars()
            .forEach(c -> {
                if (jewels.contains((char) c))
                numJewels.set(numJewels.get() + 1);
            });
        return numJewels.get();
    }
}

public class Program {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String J = in.nextLine();
        String S = in.nextLine();
        Solution solution = new Solution();

        System.out.println(J);
        System.out.println(S);
        System.out.println(solution.numJewelsInStones(J, S));
    }
}