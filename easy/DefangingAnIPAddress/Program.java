import java.util.Scanner;
import java.util.stream.Collectors;

class Solution {
    public String defangIPaddr(String address) {
        return address.replace(".", "[.]");
    }
}

public class Program {
    public static void main(String[] args) {
        String input = new Scanner(System.in).next();
        Solution sol = new Solution();

        System.out.println(input);
        System.out.println(sol.defangIPaddr(input));
    }
}