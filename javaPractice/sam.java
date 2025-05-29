public class sam{
    private static String show(){
        char str[]="Hellow world".toCharArray();
        // return new StringBuilder().append(str).append('#').toString();
        return new String(str);
    }
    public static void main(String []args){
        
        System.out.println(show());
    }
}