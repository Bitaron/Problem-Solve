public class Twin_Sum_Linked_List_2130 {

    public static int pairSum(ListNode head) {
        if (head == null) {
            return 0;
        }
        if (head.next.next == null) {
            return head.val + head.next.val;
        }
        ListNode it = head.next.next;
        ListNode mid = head;
        while (it != null) {
            mid = mid.next;
            it = it.next.next;
        }
        it = mid.next;
        ListNode rev = it;
        mid.next = null;

        while (it != null) {
            ListNode temp = it;
            it = it.next;
            if (rev == temp) {
                temp.next = null;
            } else {
                temp.next = rev;
                rev = temp;
            }
        }
        it = head;
        int sum = 0;
        while (rev != null) {
            int t = it.val + rev.val;
            if (t > sum) {
                sum = t;
            }
            it = it.next;
            rev = rev.next;
        }
        return sum;
    }

    public static void main(String[] args) {
        int[] data = {4,2};
        ListNode root = new ListNode();
        root.val = data[0];
        ListNode it = root;
        for (int i = 1; i < data.length; i++) {
            ListNode n = new ListNode();
            n.val = data[i];
            it.next = n;
            it = n;
        }
        System.out.println(pairSum(root));
    }

    public static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }

        @Override
        public String toString() {
            return "" + val + ", " + (next != null ? next.toString() : "");
        }
    }
}
