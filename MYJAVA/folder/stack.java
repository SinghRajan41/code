package weapons;

class node {
   public int data;
   public node next;

   node(int data) {
      this.data = data;
      next = null;
   }
}

public class stack {
   private node top;
   private int n;

   public stack() {
      n = 0;
      top = null;
   }

   public void push(int data) {
      node temp = new node(data);
      if (top == null) {
         top = temp;
      } else {
         temp.next = top;
         top = temp;
      }
      n += 1;
   }

   public int pop() {
      if (top == null) {
         return -1;
      } else {
         int rvalue = top.data;
         top = top.next;
         n -= 1;
         return rvalue;
      }
   }

   public boolean empty() {
      return n == 0 ? true : false;
   }

   public int top() {
      return top == null ? -1 : top.data;
   }

   public int size() {
      return n;
   }
}