import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.atomic.AtomicInteger;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int longestSubString = 0;
        AtomicInteger maxLen = new AtomicInteger(0);
        ArrayList<Character> substring = new ArrayList<Character>();
        s.chars()
            .forEach( c -> {
                if (substring.contains((char)c)) {
                    int index = substring.indexOf(new Character((char)c));
                    substring.removeIf(el -> substring.indexOf(el) <= index);
                }
                substring.add((char)c);
                if (maxLen.get() < substring.size()) {
                    maxLen.set(substring.size());
                }
            });

        return maxLen.get();
    }
}

public class Program {
    public static void main(String[] args) {
        String inputS = new Scanner(System.in).next();
        Solution ss = new Solution();

        System.out.println(inputS);
        System.out.println(ss.lengthOfLongestSubstring(inputS));
    }
}
