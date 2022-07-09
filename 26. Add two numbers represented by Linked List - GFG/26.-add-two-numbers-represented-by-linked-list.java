// { Driver Code Starts
//Initial Template for Java


import java.util.*;
import java.io.*;

class Node {
    int data;
    Node next;
    Node(){}
    Node(int d) {
        data = d;
        next = null;
    }
}


class LinkedList {
    Node head;
    void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }
	
	
    public void push(int new_data) {
        Node new_node = new Node(new_data);
        new_node.next = head;
        head = new_node;
    }
    
    static int getsize(Node head) { 
        int count = 0; 
        while (head != null) { 
            count++; 
            head = head.next; 
        } 
        return count; 
    } 
    
    static void addTwoLists(LinkedList first, LinkedList second, LinkedList res, GfG g) {
	    if (first.head == null) { 
            res.head = second.head; 
            return; 
        }  
        if (second.head == null) { 
            res.head = first.head; 
            return; 
        } 
        int size1 = getsize(first.head); 
        int size2 = getsize(second.head); 
        g.carry = 0;
        if (size1 == size2) { 
            g.addSameSize(first.head, second.head, res); 
        } else { 
            if (size1 < size2) { 
                Node temp = first.head; 
                first.head = second.head; 
                second.head = temp; 
            } 
            int diff = Math.abs(size1 - size2); 
            Node temp = first.head; 
            while (diff-- >= 0) { 
                g.cur = temp; 
                temp = temp.next; 
            } 
            g.addSameSize(g.cur, second.head, res);
            g.addCarryToRemaining(first.head, res); 
        }
        if(g.carry > 0) 
            res.push(g.carry); 
	}
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim());
		while(t-->0){
		    String[] inputline = br.readLine().trim().split(" ");
            int n1 = Integer.parseInt(inputline[0]);
            int n2 = Integer.parseInt(inputline[1]);
            
            inputline = br.readLine().trim().split(" ");
            LinkedList list1 = new LinkedList();
            for (int i = n1 -1; i >=0 ; i--) {
                int a = Integer.parseInt(inputline[i]);
                list1.push(a);
            }
            
		    inputline = br.readLine().trim().split(" ");
		    LinkedList list2 = new LinkedList();
		    for(int i = n2-1; i >= 0; i--) {
			    int b = Integer.parseInt(inputline[i]);
			    list2.push(b);
		    }
		    LinkedList res = new LinkedList();
            GfG g = new GfG();
            addTwoLists(list1, list2, res, g);
		    res.printList(res.head);
        }
    }
}   
                               // } Driver Code Ends


//User function Template for Java

 
/*class Node 
{
    int data;
    Node next;
    
    Node(int data)
    {
        this.data = data;
        next = null;
    }
}*/
class GfG {

    Node cur; // Dont change the variable name, its used in main function
    int carry; // Dont change the variable name, its used in main function
    
    //This function is called after the smaller list is added to the sublist of 
    //bigger list of same size. Once the right sublist is added, the carry
    //must be added to left side of larger list to get the final result.    
void addCarryToRemaining(Node head, LinkedList res)  { 
        // Write code here
        if(head != cur){
            addCarryToRemaining(head.next, res);
            
            int d = head.data + carry;
            res.push(d%10);
            carry = d/10;
        }
    }
    void addSameSize(Node head1, Node head2, LinkedList res) { 
	    // Write code here
	    if(head1 == null){
	        return;
	    }
	    
	    addSameSize(head1.next, head2.next, res);
	    
	    int d = head1.data + head2.data + carry;
	    carry = d/10;
	    res.push(d%10);
    }
} 