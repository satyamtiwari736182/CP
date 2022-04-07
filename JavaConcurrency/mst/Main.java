import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the 2 numbers: ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int q = 0;
        sc.close();
        try {
            q = a / b;
        } catch (ArithmeticException e) {
            System.out.println("DivideByZeroException caught");
        } finally {
            System.out.println("Question: " + q);
        }
    }
}

// class Errors extends Exception {
// public Errors() {
// }
// }

// public class Main {
// public static void transpose(int[][] matrix) {
// int n = matrix.length;
// for (int i = 0; i < n; i++) {
// for (int j = 0; j <= i; j++) {
// int temp = matrix[i][j];
// matrix[i][j] = matrix[j][i];
// matrix[j][i] = temp;
// }
// }
// }

// public static void main(String[] args) {
// int n = 2;

// int[][] matrix = new int[n][n];
// int idx = 0;

// try {
// if (args.length < n * n || args.length > n * n)
// throw new Errors();
// for (int i = 0; i < n; i++) {
// for (int j = 0; j < n; j++) {
// matrix[i][j] = Integer.parseInt(args[idx++]);
// }

// }

// transpose(matrix);

// for (int i = 0; i < n; i++) {
// for (int j = 0; j < n; j++) {
// System.out.print(matrix[i][j] + " ");
// }
// System.out.println();
// }
// } catch (Exception e) {
// System.out.println("Please enter Only 4 integers");
// }

// }
// }