import java.lang.*;
import java.util.Scanner;
import java.util.*;
class person
{
   public int id;
   public String name;
   public person(int id,String name)
   {
      this.id = id;
      this.name = name;
   }
}
class person_comparator implements Comparator<person>
{
   public int compare(person a, person b)
   {
      if(a.id == b.id)  return 0;
      else if(a.id < b.id) return -1;
      else  return 1;
   }
}
public class integer {
   public static void main(String arg[]) {
         ArrayList<person> arr = new ArrayList<>();
         for(int i = 0;i<10;i++)
         {
            arr.add(new person(i+1 , "Name-" + i+1));
         }
         Collections.sort(arr , new person_comparator());
         for(int i = 0;i<arr.size() ; i++)
         {
            System.out.println(arr.get(i).id + "\t" + arr.get(i).name);
         }
   }

   static void encodeString(String s) {
      int i;
      for (i = 0; i < s.length(); i++) {
         // s[i] = 'a';
      }
   }
}