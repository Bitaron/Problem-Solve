public class Maximum_Average_Subarray_643 {

    public static double findMaxAverage(int[] nums, int k) {
        if (nums.length == 1) {
            return nums[0];
        }

        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double average = sum / k;
        int start = 1;
        int end = k;
        while (end < nums.length) {
            sum = sum - nums[start - 1] + nums[end];
            start++;
            end++;
            if (sum / k > average) {
                average = sum / k;
            }
        }

        return average;
    }

    public static void main(String[] args) {
        int[] nums = {5};
        int k = 1;

        System.out.println(findMaxAverage(nums, k));
    }
}
