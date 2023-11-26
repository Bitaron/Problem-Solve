public class Flower_Bed_605 {
    public static boolean canPlaceFlowers(int[] flowerbed, int n) {
        int length = flowerbed.length;
        int totalPlant = (int) Math.ceil((double) length / 2.0);
        if (n > totalPlant) {
            return false;
        }

        int remainingPlant = 0;
        for (int i = 0; i < length; i++) {
            if (flowerbed[i] == 0) {
                if (i == 0 ) {
                    if(i + 1 < length) {
                        if (flowerbed[i + 1] != 1) {
                            flowerbed[i] = 1;
                            remainingPlant++;
                        }
                    }else {
                        flowerbed[i] = 1;
                        remainingPlant++;
                    }
                } else if (i == length - 1) {
                    if (flowerbed[i - 1] != 1) {
                        flowerbed[i] = 1;
                        remainingPlant++;
                    }
                } else {
                    if (flowerbed[i - 1] != 1 && flowerbed[i + 1] != 1) {
                        flowerbed[i] = 1;
                        remainingPlant++;
                    }
                }
            }
        }

        if (n <= remainingPlant) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        int[] flowerBed = {0};
        int n = 1;
        System.out.println(canPlaceFlowers(flowerBed, n));
    }
}
