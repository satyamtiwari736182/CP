import java.util.concurrent.Phaser;

public class Sample11 {
    public static void main(String[] args) {
        Phaser phaser = new Phaser(1); // "1" to register self

        // Create and start 3 worker threads
        for (int i = 0; i < 3; i++) {
            phaser.register(); // Register each worker thread
            new Thread(new Worker(phaser, "Worker-" + i)).start();
        }

        System.out.println("Main thread waiting for workers to complete phase 1");
        phaser.arriveAndAwaitAdvance(); // Main thread waits
        System.out.println("Phase 1 complete");

        System.out.println("Main thread waiting for workers to complete phase 2");
        phaser.arriveAndAwaitAdvance(); // Main thread waits again
        System.out.println("Phase 2 complete");

        phaser.arriveAndDeregister(); // Main thread deregisters
    }

    static class Worker implements Runnable {
        private final Phaser phaser;
        private final String name;

        public Worker(Phaser phaser, String name) {
            this.phaser = phaser;
            this.name = name;
        }

        @Override
        public void run() {
            System.out.println(name + " starting phase 1");
            phaser.arriveAndAwaitAdvance(); // Wait for all workers

            System.out.println(name + " starting phase 2");
            phaser.arriveAndAwaitAdvance(); // Wait for all workers

            System.out.println(name + " finished work");
            phaser.arriveAndDeregister(); // Done with phaser
        }
    }
}