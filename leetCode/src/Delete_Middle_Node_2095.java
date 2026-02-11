public class Delete_Middle_Node_2095 {

    public static ListNode deleteMiddle(ListNode head) {
        if (head.next == null) {
            return null;
        }
        ListNode middle = head;
        ListNode prev = null;
        int m = 0;
        int n = 0;
        ListNode it = head.next;
        while (it != null) {
            n++;
            it = it.next;
            int c = (int) Math.ceil(n / 2.0);
            if (c > m) {
                if (prev == null) {
                    prev = head;
                } else {
                    prev = prev.next;
                }
                middle = middle.next;
                m = c;
            }
        }

        if (prev != null) {
            prev.next = middle.next;
        }
        middle.next = null;
        return head;
    }

    public static void main(String[] args) {
        int[] data = {1,3,4,7,1,2,6};
        ListNode root = new ListNode();
        root.val = data[0];
        ListNode it = root;
        for (int i = 1; i < data.length; i++) {
            ListNode n = new ListNode();
            n.val = data[i];
            it.next = n;
            it = n;
        }
        System.out.println(deleteMiddle(root));
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
