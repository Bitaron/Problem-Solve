public class Reverse_Word_151 {
    public static String reverseWords(String s) {
        String[] split = s.trim().split("\\s+");
        StringBuilder strb = new StringBuilder();
        for (int i = split.length - 1; i >= 0; i--) {
            strb.append(split[i]);
            strb.append(" ");
        }
        return strb.toString().trim();
    }

    public static void main(String[] args) {
        String str = "a ";
        System.out.println(reverseWords(str));
    }
}
