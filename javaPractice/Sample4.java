import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.RejectedExecutionHandler;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

class CustomThreadFactory implements ThreadFactory {

    @Override
    public Thread newThread(Runnable r) {
        return new Thread(r);
    }
}

class CustomRejectedHandler implements RejectedExecutionHandler {

    @Override
    public void rejectedExecution(Runnable r, ThreadPoolExecutor executor) {
        System.out.println("Task denied: " + r.toString());
    }

}

public class Sample4 {
    public static void main(String[] args) {
        ThreadPoolExecutor poolExecutor = new ThreadPoolExecutor(2, 5, 1, TimeUnit.HOURS, new ArrayBlockingQueue<>(10),
                new CustomThreadFactory(), new CustomRejectedHandler());
        poolExecutor.allowCoreThreadTimeOut(true);
        // submit task
        for (int i = 0; i < 25; i++)
            poolExecutor.submit(() -> {
                try {
                    Thread.sleep(5000);
                    System.out.println("Thread Name: " + Thread.currentThread().getName());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            });
        poolExecutor.shutdown();

        ExecutorService executor = Executors.newScheduledThreadPool(2);

        for (int i = 1; i <= 10; i++) {
            final int taskNumber = i;
            executor.submit(() -> {
                System.out.println("Hello World!..: " + taskNumber + " ->" + Thread.currentThread().getName());
                try {
                    Thread.sleep(5000); // Simulate some work
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    System.err.println("Task interrupted: " + e.getMessage());
                }
            });
        }

        try {
            if (!executor.awaitTermination(20, TimeUnit.SECONDS)) {
                executor.shutdownNow(); // Force shutdown if timeout reached
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Main Thread Finished Execution");
    }
}
