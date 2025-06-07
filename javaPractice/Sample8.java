public class Sample8 {
    public static void main(String[] args) {
        ThreadLocal<String> threadLocal = new ThreadLocal<>();
        threadLocal.set("Hello, ThreadLocal!");
        Thread thread = new Thread(() -> {
            threadLocal.set("Hello from new thread!");
            String value = threadLocal.get();
            System.out.println("\nThreadLocal value in new thread: " + value);
        });
        thread.start();
        try {
            Thread.sleep(1000);
        } catch (Exception e) {

        }
        System.out.println("\nMain thread value: " + threadLocal.get());
    }

}
