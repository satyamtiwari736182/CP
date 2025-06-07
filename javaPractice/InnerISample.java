interface ISample {

    final String name = "ISample Interface";
    public String str = "Satyam";

    public static void show() {
        System.out.println("i am Isample static in nature");
    }

    public default void show23() {
        System.out.println("i am Isample default in nature");
    }

    public String show2(String str);

}

class Sample {
    public String show3(String str) {
        return "I am Sample Class show2 method" + " with str: " + str;
    }

    public static String show4(String str) {
        return "I am Sample Class show4 static method" + " with str: " + str;
    }
}

public class InnerISample implements ISample {

    public String show2(String str) {
        // ISample.str = str; // This will not compile, as 'str' is final in the
        // interface
        return "I am InnerISample show2 method" + " with str: " + str;
    }

    public static void main(String[] args) {
        InnerISample obj = new InnerISample();
        System.out.println(obj.show2("Hello, World!"));
        ISample.show();
        obj.show23();
        System.out.println("Name: " + ISample.name);

        Sample sampleObj = new Sample();
        ISample iSample = sampleObj::show3; // Method reference to Sample's show2 method
        ISample iSample2 = Sample::show4; // Method reference to Sample's show2 method
        System.out.println(iSample.show2("Hello from ISample!"));
        System.out.println(iSample2.show2("Hello from ISample!"));
    }

}