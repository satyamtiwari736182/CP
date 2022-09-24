
public class Main {
    // Example 1
    // public static class MyThread extends Thread {
    // public void run() {
    // System.out.println("MyThread running");
    // System.out.println("MyThread finished");
    // }
    // }

    // Example 2
    // public static class MyThread implements Runnable {
    // public void run() {
    // System.out.println("MyThread running");
    // System.out.println("MyThread finished");
    // }
    // }

    // public void maint(String[] args) {
    //     System.out.println("Hello world!");

    //     // ------------------------
    //     // Example 4
    //     // using lambda Expression
    //     Runnable runnable = () -> {
    //         System.out.println("MyThread running");
    //         System.out.println("MyThread finished");

    //     };
    //     Thread thred = new Thread(runnable);
    //     thred.start();

        // ------------------------

        // Example 3
        // Using anonymous class
        // Runnable runnable = new Runnable() {
        // public void run() {
        // System.out.println("MyThread running");
        // System.out.println("MyThread finished");

        // }
        // };
        // Thread thred = new Thread(runnable);
        // thred.start();

        // ------------------------
        // Example 2
        // Thread thred = new Thread(new MyThread());
        // thred.start();
        // ------------------------

        // Example 1
        // MyThread thred = new MyThread();
        // thred.start();
        // ------------------------
    // }
}