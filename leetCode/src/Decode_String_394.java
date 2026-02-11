public class Decode_String_394 {

    public static String decodeString(String s) {
        StringBuilder r = new StringBuilder();
        decode(s, r);
        return r.toString();
    }

    public static void decode(String s, StringBuilder r) {
        if (!s.contains("[")) {
            r.append(s);
        } else {
            int sc = 0;
            int ec = 0;
            while (ec < s.length() && s.charAt(ec) >= 97 && s.charAt(ec) <= 122) {
                ec++;
            }
            if (sc != ec) {
                decode(s.substring(sc, ec), r);
                if (ec < s.length()) {
                    decode(s.substring(ec), r);
                }
            } else {
                int start = -1;
                int end = -1;
                int found = 0;
                for (int i = 0; i < s.length(); i++) {
                    if (s.charAt(i) == '[') {
                        if (start == -1) {
                            start = i;
                        }
                        found++;
                    }
                    if (s.charAt(i) == ']') {
                        found--;
                        if (found == 0) {
                            end = i;
                            break;
                        }
                    }
                }
                int count = Integer.parseInt(s.substring(0, start));
                for (int i = 0; i < count; i++) {
                    String substring = s.substring(start+1, end);
                    decode(substring, r);
                }
                if (end + 1 < s.length()) {
                    decode(s.substring(end + 1), r);
                }
            }
        }

    }


    public static void main(String[] args) {
        String str = "100[leetcode]";
        System.out.println(decodeString(str));
    }
}
