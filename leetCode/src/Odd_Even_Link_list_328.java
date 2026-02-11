public class Odd_Even_Link_list_328 {

    public static ListNode oddEvenList(ListNode head) {
        if (head== null ||head.next == null || head.next.next == null) {
            return head;
        }
        ListNode oddHead = head;
        ListNode evenHead = head.next;
        ListNode oddCounter = head;
        ListNode evenCounter = head.next;
        ListNode it = head.next.next;
        //int count = 2;
        while (it != null) {
            oddCounter.next = it;
            oddCounter = it;
            if (it.next != null) {
                evenCounter.next = it.next;
                evenCounter = it.next;
                it = it.next.next;
            } else {
                it = null;
                evenCounter.next = null;
            }

        }
        oddCounter.next = evenHead;
        return head;

    }

    public static void main(String[] args) {
        int[] data = {2,3,4};
        ListNode root = new ListNode();
        root.val = data[0];
        ListNode it = root;
        for (int i = 1; i < data.length; i++) {
            ListNode n = new ListNode();
            n.val = data[i];
            it.next = n;
            it = n;
        }
        System.out.println(oddEvenList(root));
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
