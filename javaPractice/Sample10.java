import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.StampedLock;

public class Sample10 {
    public static void main(String[] args) {
        Lock lock1 = new StampedLock().asReadLock();
        Lock lock2 = new ReentrantLock();
        Lock lock3 = new ReadWriteLock() {
            @Override
            public Lock readLock() {
                return new ReentrantLock();
            }

            @Override
            public Lock writeLock() {
                return new ReentrantLock();
            }
        }.readLock();
        Semaphore semaphore = new Semaphore(1);
        Runnable task = () -> {
            try {
                semaphore.acquire();
                System.out.println("Task is running...");
                Thread.sleep(2000); // Simulate work
            } catch (InterruptedException e) {
                System.err.println("Task was interrupted: " + e.getMessage());
            } finally {
                semaphore.release();
                System.out.println("Task completed.");
            }
        };
        Thread thread = new Thread(task);
        thread.start();
        try {
            thread.join(); // Wait for the task to complete
        } catch (InterruptedException e) {
            System.err.println("Main thread was interrupted: " + e.getMessage());
        }
        System.out.println("Main thread finished.");
    }
}
