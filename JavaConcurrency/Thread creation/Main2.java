
// public class Main2 {

//     public void maing(String[] args) {
//         System.out.println("Hello world!");
//         System.out.println(Thread.currentThread().getName() + " is Running");

//         Runnable runnable = () -> {
//             try {

//                 Thread.sleep(1000 * Thread.currentThread().getPriority());
//             } catch (Exception e) {
//                 e.printStackTrace();
//             }
//             System.out.println(Thread.currentThread().getName() + " is Running");
//         };
//         Thread thred1 = new Thread(runnable, "Thread_1");
//         Thread thred2 = new Thread(runnable, "Thread_2");
//         thred2.setPriority(7);
//         thred1.start();
//         thred2.start();

//     }
// }