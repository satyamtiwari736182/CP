// import java.util.*;

// import java.io.*;

// class Cmpr implements Comparator<Pair> {

//     public int compare(Pair p1, Pair p2) {
//         return p1.b - p2.b;
//     }

// }

// class Pair {
//     int a, b;
//     public final int name;

//     public Pair(int a, int b) {
//         this.a = a;
//         this.b = b;
//         name = a;
//     }

//     @Override
//     public String toString() {
//         return "Pair [a=" + a + ", b=" + b + "]";
//     }

//     static class InnerSample {
//         private int sh() {
//             return 123;
//         }
//     }

//     public void disp() {

//         InnerSample obj = new InnerSample();
//         System.out.println(obj.sh());
//     }

//     // public void show(ISample iSample) {
//     // System.out.println("I am Pair class ");
//     // iSample.show2();
//     // }

//     public void show2() {
//         System.out.println("showing the interface from Pair....");
//     }
// }

// public class Sample {

//     public static void main(String[] args) {

//         Pair arr[] = { new Pair(10, 23), new Pair(4, 89), new Pair(12, 38) };
//         Arrays.sort(arr, new Cmpr());
//         for (Pair pr : arr)
//             System.out.println(pr);

//         Pair pr = new Pair(13, 42);

//         ISample iSample = pr::show2;
//         iSample.show23();
//         ISample.show();

//     }
// }

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.TreeSet;

class Pair implements ISample, Comparable<Pair> {
    public final int val;
    public final String name;

    public int getVal() {
        return val;
    }

    public Pair(int val, String name) {
        this.val = val;
        this.name = name;
    }

    public static void show() {
        System.out.println("i am Sample static in nature");
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + val;
        result = prime * result + ((name == null) ? 0
                : (name +
                        String.valueOf(Math.random())).hashCode());
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Pair other = (Pair) obj;
        if (val != other.val)
            return false;
        if (name == null) {
            if (other.name != null)
                return false;
        } else if (!name.equals(other.name))
            return false;
        return true;
    }

    @Override
    public String toString() {
        return "Pair [val=" + val + ", name=" + name + "]";
    }

    @Override
    public int compareTo(Pair o) {
        return this.hashCode() - o.hashCode();
    }

    @Override
    public void show2() {
        System.out.println("i am Pair default overridden in nature");
    }

    @Override
    public String show2(String str) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'show2'");
    }

}

public class Sample {
    static String show() {
        String sam = "dsf";
        char[] str = sam.toCharArray();
        str[0] = 'A';
        String sa = str.toString();
        return sa;
    }

    static int getv(int a) {
        return a;
    }

    public static void main(String[] args) {
        List<Integer> lst = List.of(getv(12), 34, getv(67), 21, 35);

        System.out.println(Collections.max(lst));

        // int arr[][]=new int[3][4];
        // for(int i=0;i<arr.length;i++) Arrays.fill(arr[i],10);
        // for(int i=0;i<arr.length;i++){
        // for(int j=0;j<arr[0].length;j++){
        // System.out.print(arr[i][j]+" ");
        // }
        // System.out.println();
        // }

        // ISample obj=new Pair(12, "satyam");
        // obj.show2();

        TreeSet<Pair> set = new TreeSet<Pair>();
        // set.add(new Pair(10,"satyam"));
        // set.add(new Pair(20,"rahul"));
        // set.add(new Pair(30,"kajal"));
        // set.add(new Pair(10,"satyam"));
        // set.add(new Pair(20,"rahul"));
        // set.add(new Pair(30,"kajal"));
        // set.add(new Pair(10,"satyam"));
        // set.add(new Pair(20,"rahul"));
        // set.add(new Pair(30,"kajal"));
        // set.add(new Pair(10,"satyam"));
        // set.add(new Pair(20,"rahul"));
        // set.add(new Pair(30,"kajal"));

        // for(Pair p : set) {
        // System.out.println(p);
        // }

        // System.out.println(show());
        // // sam[0]='h';
        // HashMap<Integer,Integer>map = new HashMap<>();
        // map.remove(1);
        // List<Pair>arr=new ArrayList<>();
        // arr.add(new Pair(12));
        // arr.add(new Pair(23));

        // arr.stream().forEach((Pair a)->System.out.println(a.val));
        // ISample pr=new Pair(050);
        // ISample.show();

    }
}