public interface ISample {

    // static final int name=12;
    public static void show(){
        System.out.println("i am Isample static in nature");
    }
    

    default public void show2(){
        System.out.println("i am Isample default in nature");
    }
    
} 