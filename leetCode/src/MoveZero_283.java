import java.util.Arrays;

public class MoveZero_283 {

    public static void moveZeroes(int[] nums) {
        int length = nums.length;
        int front = 0;
        int zeroAt = -1;
        for (; front < length; front++) {
            if (nums[front]!= 0) {
                zeroAt++;
                nums[zeroAt] = nums[front];
                if(zeroAt != front) {
                    nums[front] = 0;
                }
            }
        }
        System.out.println(Arrays.toString(nums));
    }

    public static void main(String[] args) {
        int []nums = {1};
        moveZeroes(nums);
    }
}
