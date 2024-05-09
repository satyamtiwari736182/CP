import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Sample3 {
    public static void main(String[] args) {

        // int arr[]={1,34,56,6,7};
        // int myArr[][]=new int[][]{{12,34,2,34},{54,3,2,5}};
        // Arrays.sort(myArr, (a, b) -> a[0] - b[0]);  //? It works
        // Arrays.sort(arr, (a, b) -> a - b); //! does not Works



        // Integer arr[]={1,34,56,6,7};
        // List<Integer> lst=new ArrayList<>(Arrays.asList(arr));
        // // for(int v:arr)lst.add(v);
        // Integer[] arr2 = lst.toArray(new Integer[lst.size()]);
        
        // int arr2[]=new int[lst.size()];
        // for(int i=0;i<lst.size();i++)arr2[i]=lst.get(i);
        //=========================== Immutable 
        // List<Integer> lst=Arrays.stream(arr).boxed().toList();
        // int arr2[]=lst.stream().mapToInt(Integer::intValue).toArray();
        // int arr2[]=lst.stream().mapToInt(Integer::intValue).toArray();
        // for(int i:arr2)System.out.print(i+", ");
        //===========================
        
        // int arr[][]={{1,34,56,6,7},{1,34,56,6,7}};

        // List<int[]> lst=new ArrayList<>(Arrays.asList(arr));
        // // lst.add(new int[]{12,45,67});
        // // lst.get(0)[0]=945;
        // int arr2[][]=lst.toArray(new int[lst.size()][]);

        // for(int a[]:lst){
        //     for(int v:a)System.out.print(v+" ");
        //     System.out.println();
        // }
    }
}
