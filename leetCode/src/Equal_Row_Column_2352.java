public class Equal_Row_Column_2352 {

    public static int equalPairs(int[][] grid) {
        int count = 0;
        for (int row = 0; row < grid.length; row++) {
            for (int column = 0; column < grid.length; column++) {
                int c = 0;
                int r = 0;
                boolean match = true;
                while (c < grid.length) {
                    int rData = grid[row][c];
                    int cData = grid[r][column];
                    if (rData != cData) {
                        match = false;
                        break;
                    }
                    c++;
                    r++;
                }
                if (match) {
                    count++;
                }
            }

        }
        return count;
    }

    public static void main(String[] args) {
       // int[][] grid = new int[][]{{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
        int[][] grid = new int[][]{{3,2,1},{1,7,6},{2,7,7}};

        System.out.println(equalPairs(grid));
    }
}


