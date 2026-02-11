public class Longest_Subarray_1493 {

    public static int longestSubarray(int[] nums) {
        int currentMax = 0;
        int i = 0;
        int start = 0;
        int end = -1;

        for (int c = 0; c < nums.length; c++) {
            i = start;
            end = start-1;

//            System.out.println("c=="+ c);
//            System.out.println("i=="+ i);
            for (; i < nums.length; i++) {
                if (i != c) {
                    if (nums[i] == 1) {
                        end++;
                    } else {
                        if(nums[c]==1&&i>0 && i<=nums.length) {
                            c = i-1;
                        }
                        break;
                    }
                    int temp = end - start + 1;
                    if (temp > currentMax) {
                        currentMax = temp;
                    }
                }
            }
            if (nums[c] == 0 ) {
                start=c+1;
            }
        }


        return currentMax;
    }

    public static void main(String[] args) {
       // int[] nums = {0,1,1,1,0,0,0,1,1,0,1};
       int[] nums = {0,1,1,1,0,1,1,0,1};

        System.out.println(longestSubarray(nums));
    }
}
