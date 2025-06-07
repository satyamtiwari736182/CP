import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

public class Sample9 {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newSingleThreadExecutor();
        Callable<Integer> task = () -> {
            TimeUnit.SECONDS.sleep(2);
            return 42; // Return a result
        };
        executor.submit(task);
        // Submit Callable and get Future
        Future<Integer> future = executor.submit(() -> {
            TimeUnit.SECONDS.sleep(5);
            return 123;
        });

        // Do other work while task is executing...

        try {
            System.out.println("Callable task result: " + task.call());

            if (future.isDone()) {
                System.out.println("Task is already done.");
            } else {
                System.out.println("Task is still running...");
                // Integer result = future.get(2, TimeUnit.SECONDS);
                // System.out.println("Result: " + result);
                // future.cancel(false); // Attempt to cancel the task
            }

            // Get the result (blocks if not ready)
            Integer result = future.get();
            System.out.println("Result: " + result);
        } catch (Exception e) {
            System.err.println("Error occurred: " + e.getMessage());
        } finally {
            if (!future.isCancelled()) {
                System.out.println("Task completed successfully.");
            } else {
                System.out.println("Task was cancelled.");
            }
            executor.shutdown();
        }

    }
}
