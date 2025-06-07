// import java.util.concurrent.ForkJoinPool;
// import java.util.concurrent.RecursiveAction;

// class SqrtTransform extends RecursiveAction {
//     // The threshold value is arbitrarily set at 1,000 in this example.
//     // In real-world code, its optimal value can be determined by
//     // profiling and experimentation.
//     final int seqThreshold = 3;
//     // Array to be accessed.
//     double[] data;
//     // Determines what part of data to process.
//     int start, end;

//     SqrtTransform(double[] vals, int s, int e) {
//         data = vals;
//         start = s;
//         end = e;
//     }

//     // This is the method in which parallel computation will occur.
//     protected void compute() {
//         // If number of elements is below the sequential threshold,
//         // then process sequentially.
//         if ((end - start) < seqThreshold) {
//             // Transform each element into its square root.
//             for (int i = start; i < end; i++) data[i] = Math.sqrt(data[i]);
//         } 
//         else {
//             // Otherwise, continue to break the data into smaller pieces.
//             int middle = (start + end) / 2; // Find the midpoint.
//             // Invoke new tasks, using the subdivided data.
//             invokeAll(new SqrtTransform(data, start, middle),new SqrtTransform(data, middle, end));
//         }
//     }
// }

// // Demonstrate parallel execution.
// public class Sample5 {
//     public static void main(String args[]) {
//         // Create a task pool.
//         ForkJoinPool fjp = new ForkJoinPool();
//         double[] nums = new double[100000];
//         // Give nums some values.
//         for (int i = 0; i < nums.length; i++) nums[i] = (double) i;
//         System.out.println("A portion of the original sequence:");
//         for (int i = 0; i < 10; i++) System.out.print(nums[i] + " ");
//         System.out.println("\n");

//         SqrtTransform task = new SqrtTransform(nums, 0, nums.length);
//         // Start the main ForkJoinTask.
//         fjp.invoke(task);

//         System.out.println("A portion of the transformed sequence (to four decimal places):");
//         for (int i = 0; i < 10; i++) System.out.format("%.4f ", nums[i]);
//     }
// }

//! =========================================================================
// A simple example that uses RecursiveTask<V>.
import java.util.concurrent.*;

// A RecursiveTask that computes the summation of an array of doubles.
class Sum extends RecursiveTask<Double> {
    final int seqThresHold = 500; // The sequential threshold value.
    double[] data; // Array to be accessed.
    int start, end; // Determines what part of data to process.

    Sum(double[] vals, int s, int e) {
        data = vals;
        start = s;
        end = e;
    }

    // Find the summation of an array of doubles.
    @Override
    protected Double compute() {
        double sum = 0;
        // If number of elements is below the sequential threshold, then process
        // sequentially.
        if ((end - start) < seqThresHold) {
            // Sum the elements.
            for (int i = start; i < end; i++)
                sum += data[i];
        } else {
            // Otherwise, continue to break the data into smaller pieces. Find the midpoint.
            int middle = (start + end) / 2;
            // Invoke new tasks, using the subdivided data.
            Sum subTaskA = new Sum(data, start, middle), subTaskB = new Sum(data, middle, end);

            // Start each subtask by forking.
            subTaskA.fork();
            subTaskB.fork();

            sum = subTaskA.join() + subTaskB.join(); // Wait for the subtasks to return, and aggregate the results.
        }

        return sum; // Return the final sum.
    }
}

// Demonstrate parallel execution.
public class Sample5 {
    public static void main(String args[]) {
        ForkJoinPool fjp = new ForkJoinPool(); // Create a task pool.
        double[] nums = new double[5000];
        // Initialize nums with values that alternate between positive and negative.
        for (int i = 0; i < nums.length; i++)
            nums[i] = (double) (((i % 2) == 0) ? i : -i);
        Sum task = new Sum(nums, 0, nums.length);

        double summation = fjp.invoke(task); // Start the ForkJoinTasks. Notice that, in this case, invoke() returns a
                                             // result.

        System.out.println("Summation " + summation);
    }
}