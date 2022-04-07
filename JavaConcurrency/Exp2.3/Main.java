
import java.io.*;

import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        System.out.println("Satyam Tiwari ");

        System.out.println("19BCS1157 ");

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Scanner sc = new Scanner(System.in);

        ArrayList<String> al = new ArrayList<String>();

        boolean flag = true;

        while (flag) {

            System.out.println("1. Insert");

            System.out.println("2. Search");

            System.out.println("3. Delete");

            System.out.println("4. Display");

            System.out.println("5. Exit");

            int option = sc.nextInt();

            if (option >= 1 && option <= 5) {

                switch (option) {

                    case 1:

                        System.out.println("Enter item to be inserted: ");

                        al.add(br.readLine());

                        System.out.println("Inserted successfully");

                        break;

                    case 2:

                        System.out.println("Enter item to search: ");

                        String se = br.readLine();

                        if (al.contains(se)) {

                            System.out.println("Item is at Index: " + al.indexOf(se));

                        }

                        else {

                            System.out.println("Item not found in the list");

                        }

                        break;

                    case 3:

                        System.out.println("Enter which Item to delete: ");

                        String re = br.readLine();

                        if (al.contains(re)) {

                            al.remove(re);

                            System.out.println("Deleted Successfully !");

                        }

                        else {

                            System.out.println("No such Item in the List !");

                        }

                        break;

                    case 4:

                        if (al.size() == 0) {

                            System.out.println("Empty List !");

                        }

                        else {

                            System.out.println(al);

                        }

                        break;

                    default:

                        flag = false;

                }

            }

            else {

                System.out.println("Invalid option");

            }

        }

        sc.close();

    }

}
