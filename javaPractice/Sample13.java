import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.util.concurrent.ConcurrentHashMap;

@Retention(RetentionPolicy.RUNTIME)
@interface Sample14 {
    String value() default "default value";

    int number() default 0;

    Class<?> type() default Object.class;

    String[] tags() default {};

    boolean enabled() default true;

}

public class Sample13 {
    public static void main(String[] args) {
        // Using the Sample14 annotation
        @Sample14(value = "Sample Annotation", number = 42, type = String.class, tags = { "tag1",
                "tag2" }, enabled = true)
        class AnnotatedClass {
            // This class is annotated with Sample14
        }

        // Accessing the annotation
        Sample14 annotation = AnnotatedClass.class.getAnnotation(Sample14.class);
        if (annotation != null) {
            System.out.println("Value: " + annotation.value());
            System.out.println("Number: " + annotation.number());
            System.out.println("Type: " + annotation.type().getName());
            System.out.println("Tags: " + String.join(", ", annotation.tags()));
            System.out.println("Enabled: " + annotation.enabled());
        } else {
            System.out.println("No Sample14 annotation found.");
        }


    }
}
