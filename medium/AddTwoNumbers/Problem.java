public class Problem {

    private static void printL(ListNode l) {
        for (;l != null; l = l.next ) {
            System.out.print(l.val);
            if (l.next == null)
                System.out.println();
            else
                System.out.print(" -> ");
        }
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode el = new ListNode(-1);
        ListNode result = null;
        int passOver = 0;
        while (l1 != null || l2 != null || passOver != 0) {
            int val1 = l1 == null ? 0 : l1.val;
            int val2 = l2 == null ? 0 : l2.val;
            int val = val1 + val2 + passOver;
            if (val >= 10)
                passOver = val / 10;
            else
                passOver = 0;

            el.next = new ListNode(val % 10);
            if (result == null) {
                result = el.next;
            }
            el = el.next;
            l1 = l1 == null ? l1 : l1.next;
            l2 = l2 == null ? l2 : l2.next;
        }

        return result;
    }

    public static void main(String[] args){

        ListNode num1 = new ListNode(2);
        num1.next = new ListNode(4);
        num1.next.next = new ListNode(3);

        ListNode num2 = new ListNode(5);
        num2.next = new ListNode(6);
        num2.next.next = new ListNode(4);

        printL(num1);
        printL(num2);
        printL(addTwoNumbers(num1, num2));
    }
}

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}