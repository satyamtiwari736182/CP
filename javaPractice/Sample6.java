import java.util.Optional;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class Sample6 {
    public static void main(String[] args) {
        ScheduledThreadPoolExecutor executor = new ScheduledThreadPoolExecutor(2);
        executor.scheduleAtFixedRate(() -> {
            try {
                System.out.println("Executing task at: " + System.currentTimeMillis());
                // Simulate some work
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.err.println("Task interrupted: " + e.getMessage());
            }
        }, 0, 2, java.util.concurrent.TimeUnit.SECONDS);

        // Optional: Shutdown the executor after some time
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            System.out.println("Shutting down executor...");
            executor.shutdown();
            try {
                if (!executor.awaitTermination(5, java.util.concurrent.TimeUnit.SECONDS)) {
                    System.err.println("Executor did not terminate in the specified time.");
                    executor.shutdownNow();
                }
            } catch (InterruptedException e) {
                System.err.println("Shutdown interrupted: " + e.getMessage());
                executor.shutdownNow();
            }
        }));

        // Keep the main thread alive to see the scheduled task execution
        try {
            Thread.sleep(10000); // Keep the main thread alive for 10 seconds
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            System.err.println("Main thread interrupted: " + e.getMessage());
        }
        System.out.println("Main thread finished execution.");

    }

}
