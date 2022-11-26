import java.lang.*;
import java.io.*;
import java.util.*;
class node
{
    public int data;
    public node left,right;
}
class AVLTree
{
    static node LLRotation(node a)
    {
            node b,d;
            b = a.left;
            d = b.right;
            b.right = a;
            a.left = d;
            if(mainroot == a)
            {
                mainroot = b;
            }
            return b;
    }
    static node LRRotation(node a)
    {
            node b,c,d,e;
            b = a.left;
            c = a.right;
            d = c.left;
            e = c.right;
            c.left = b;
            b.right = d;
            a.left = e;
            c.right = a;
            if(mainroot == a)
            {
                mainroot = c;
            }
           return c;
    }
    static node RRRotation(node a)
    {
            node b,d;
            b = a.right;
            d = b.left;
            b.left = a;
            a.right = d;
            if(mainroot == a)
            {
                mainroot =b;
            }
            return b;
        
    }
    static node RLRotation(node a)
    {
    
            node b,c,d,e;
            b = a.right;
            c = b.left;
            d = c.left;
            e = c.right;
            c.left = a;
            a.right = d;
            c.right = b;
            b.right = e;
            if(mainroot == a)
            {
                mainroot = c;
            }
            return c;
        
    }

    static node newNode(int data)
    {
        node temp = new node();
        temp.left = temp.right = null;
        temp.data = data;
        return temp;
    }
    static node removeNode(node root , int key)
    {
        if(root == null)
        {
            return null;
        }
        if(root.data == key)
        {
            if(root.left == null && root.right == null)
            {
                return null;
            }
            else
            {
                int l,r;
                l = height(root.left);
                r = height(root.right);
                if(l > r)
                {
                    node pred =root.left;
                    while(pred != null && pred.right != null)
                    {
                        pred = pred.right;
                    }
                    root.data = pred.data;
                    root.left = removeNode(root.left , pred.data);
                }
                else
                {
                    node succ = root.right;
                    while(succ.left != null)
                    {
                        succ = succ.left;
                    }
                    root.data = succ.data;
                    root.right = removeNode(root.right , succ.data);
                }
            }
        }
        else
        {
            if(key < root.data)
            {
                root.left = removeNode(root.left , key);
            }
            else
            {
                root.right = removeNode(root.right , key);
            }
        }
        int a,b;
        a = balanceFactor(root);
        b = balanceFactor(root.left);
        if(a == 2 && b == 1)
        {
            root = LLRotation(root);
        }
        else if(a==-2 && b==-1)
        {
            root = RRRotation(root);
        }
        else if(a==-2 && b==1)
        {
             root = RLRotation(root);
        }
        else if(a==2 && b==-1)
        {
            root = LRRotation(root);
        }
        return root;
    }
    static int balanceFactor(node root)
    {
        return height(root) - height(root);
    }
    static node insertNode(node root , int data)
    {
        if(root == null)
        {
            return newNode(data);
        }
        else
        {
            if(data < root.data)
            {
                root.left = insertNode(root.left , data);
            }
            else
            {
                root.left = insertNode(root.right , data);
            }
            int a,b;
            a = balanceFactor(root);
            b = balanceFactor(root.left);
            if(a == 2 && b == 1)
            {
                root = LLRotation(root);
            }
            else if(a==-2 && b==-1)
            {
                root = RRRotation(root);
            }
            else if(a==-2 && b==1)
            {
                root = RLRotation(root);
            }
            else if(a==2 && b==-1)
            {
                root = LRRotation(root);
            }
            return root;
        }
    }
    static int height(node root)
    {
        if(root == null)
        {
            return 0;
        }
        else
        {
            int l,r;
            l = height(root.left);
            r = height(root.right);
            return l>r ? l+1 : r+1;
        }
    }
    static void inorder(node root)
    {
        if(root == null)
        {
            return;
        }
        else
        {
            inorder(root.left);
            System.out.print(root.data + " ");
            inorder(root.right);
        }
    }
    public static node mainroot;
    public static void main(String arg[])
    {
        System.out.println("Hello World");
        mainroot = null;
        for(int i=0;i<100;i++)
        {
            mainroot = insertNode(mainroot , i+1);
        }
        //mainroot = removeNode(mainroot , 1);
        System.out.println(height(mainroot));
        inorder(mainroot);
    }
}