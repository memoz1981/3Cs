namespace DataStructures.LinkedLists; 

public class Node<T> where T : struct   
{
    public LinkedList(T value) => Value = value; 
    public T Value { get; private set; }
    public Node<T> Next { get; private set; }
    public void SetNext(Node<T> next) => Next = next; 
    public override ToString() => $"{Value}"
}

//For simplicity assuming linked list will contain unique elements only... 
public class LinkedList<T> where T : struct
{
    public Node<T> Head { get; private set;}
    
    public bool Contains(T value, out Node<T> last)
    {
        last = Head; 
        while(last != null)
        {
            if(last.Value == value)
                return true; 
            
            last = last.Next; 
        }
        return false;
    }
    
    public bool Add(T value)
    {
        if(Contains(value, out var last))
            return false; 
        
        last.SetNext(new Node(value));  
    }

    public bool Remove(T value)
    {
        if(Head.Value == value)
        {
            Head = null; 
            return true; 
        }

        var temp = Head; 
        while(temp.Next != null)
        {
            if(temp.Next.Value == value)
            {
                temp.SetNext(temp.Next.Next); 
                return true; 
            }
            temp = temp.Next; 
        }
        return false;
    }

    public bool IsEmpty() => Head != null; 

    public override string ToString()
    {
        var builder = new StringBuilder(); 
        builder.AppendLine("Linked List: "); 
        var temp = Head; 
        while(temp != null)
        {
            builder.Append($"{temp.ToString()} -> ");
            temp = temp.Next; 
        }
        builder.Append("NULL"); 

        return builder.ToString(); 
    } 
}

public class LinkedListRunner
{
    public void RunLinkedListInInteractiveMode()
    {
        var list = new LinkedList<int>(); 
        int result;
        Console.Clear(); 
        do {
             
            result = RunLinkedListCycle(list); 
        }
        while(result != -1); 
    }

    private int RunLinkedListCycle(LinkedList<int> list)
    {
        Console.WriteLine("\n\n\nINTERACTIVE LINKED LIST COMMANDS:\n"); 
        Console.WriteLine("[c] - for clearing the screen\n");
        Console.WriteLine("[r] - to print the linked list\n");
        Console.WriteLine("[e] - to exit\n");
        Console.WriteLine("[+] - to add an integer to the linked list\n");
        Console.WriteLine("[-] - to remove an integer from the linked list\n");
        Console.WriteLine("[?] - to check if the linked list contains an integer\n");
        char ch = Console.ReadKey().KeyChar;
        Console.WriteLine(); 

        if(ch == 'c')
        {
            Console.Clear(); 
            return 0; 
        }

        if(ch == 'r')
        {
            Console.WriteLine(list.ToString());
            return 0; 
        }

        if(ch == 'e')
            return -1; 

        if(ch == '+')
        {
            Console.WriteLine("\nEnter an integer to add to the linked list: ");
            var resultStr = Console.ReadLine().ToString(); 
            int result = Int32.Parse(resultStr); 

            var addResult = list.Add(result); 

            if(!addResult)
                Console.WriteLine("\nAdd failed, list already contains the element\n"); 

            return 0; 
        }

        if(ch == '-')
        {
            Console.WriteLine("\nEnter an integer to remove from the linked list: ");
            var resultStr = Console.ReadLine().ToString(); 
            int result = Int32.Parse(resultStr); 

            var removeResult = list.Remove(result); 

            if(!removeResult)
                Console.WriteLine("\nRemove failed, list doesn't contain the element\n"); 

            return 0; 
        }

        if(ch == '?')
        {
            Console.WriteLine("\nEnter an integer to check if linked list contains it: ");
            var resultStr = Console.ReadLine().ToString(); 
            int result = Int32.Parse(resultStr); 

            var checkResult = list.Contains(result); 

            if(checkResult)
                Console.WriteLine($"\nList contains {result}.\n"); 
            else
                Console.WriteLine($"\nList doesn't contain {result}.\n"); 

            return 0; 
        }
        
        return 0;    
    }
}