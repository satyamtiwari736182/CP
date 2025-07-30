import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

class MyClass {
    public int id;
    public String name, address;

    public MyClass() {
        System.out.println("MyClass constructor called");
    }

    public MyClass(int val) {
        System.out.println("MyClass constructor with int called: " + val);
    }

    public String show(int val) {
        return "MyClass" + val;
    }

    public String show2(int val) {
        return "MyClass" + val;
    }

}

public class Sample12 {

    public static void run(Class<?> class1) throws Exception {

        // Class<?> class1 = Class.forName("MyClass");
        // Class<?> class1 = cls.getClass();
        System.out.println(class1);
        System.out.println(class1.getName());
        Constructor<?>[] constructors = class1.getDeclaredConstructors();
        for (Constructor<?> constructor : constructors) {
            System.out.println(constructor);
        }
        MyClass ob = (MyClass) constructors[0].newInstance(12);
        ob.show(90210);

        Method[] methods = class1.getDeclaredMethods();
        for (Method method : methods) {
            System.out.println(method);
        }
        Field field[] = class1.getFields();
        for (Field field1 : field) {
            System.out.println(field1.getName());
        }
        class1.
    }

    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        run(MyClass.class);

    }
}