using System; 
using System.Text; 

namespace DataStructures.Stacks; 

public class Stack<T> where T: struct
{
    public Stack(T value, Stack<T> next = null)
    {
        Value = value; 
        this.next = next; 
    }

    public T Value { get; set; }
    public Stack<T> next { get; set; }

    public override string ToString() => $"{Value}";
}

public class StackWrapper<T> where T: struct
{
    public StackWrapper()
    {
        Top = null; 
        _count = 0; 
    }

    public Stack<T> Top { get; set; }
    private int _count; 

    public void Push(T value)
    {
        var stack = new Stack<T>(value, Top); 
        Top = stack; 
        _count++; 
    } 

    public T? Pop()
    {
        var top = Top; 

        Top = top?.next; 
        _count--;
        return top?.Value; 
    }

    public T? Peek() => Top?.Value; 

    public int Size { get => _count; }

    public bool IsEmpty { get => _count == 0; }

    
    public override string ToString()
    {
        var builder = new StringBuilder(); 
        builder.AppendLine("Stack: "); 
        var temp = Top; 
        while(temp != null)
        {
            builder.Append($"{temp.ToString()} -> ");
        }
        builder.Append("NULL"); 

        return builder.ToString(); 
    }
}

public class StackRunner
{
    public void RunStackInInteractiveMode()
    {
        Console.Clear(); 
        Console.WriteLine("\n\n\nINTERACTIVE STACK COMMANDS:\n"); 
        Console.WriteLine("[c] - for clearing the screen\n");
        Console.WriteLine("[r] - to print the stack\n");
        Console.WriteLine("[e] - to exit\n");
        Console.WriteLine("[+] - to push integer to the stack\n");
        Console.WriteLine("[-] - to pop\n");
        Console.WriteLine("[p] - to peek\n");
        Console.WriteLine("[s] - to print stack count\n");
        var stackWrapper = new StackWrapper<int>(); 
        int result;
        do {
            char ch = Console.ReadKey().KeyChar; 
            result = RunStackCycle(stackWrapper, ch); 
        }
        while(result != -1); 
    }

    private int RunStackCycle(StackWrapper<int> wrapper, char ch)
    {
        if(ch == 'c')
        {
            Console.Clear(); 
            return 0; 
        }

        if(ch == 'r')
        {
            Console.WriteLine(wrapper.ToString());
            return 0; 
        }

        if(ch == 'e')
            return -1; 

        if(ch == '+')
        {
            Console.WriteLine("Enter an integer to add to the stack: ");
            var resultStr = Console.ReadLine(); 
            int result = Int32.Parse(resultStr); 

            wrapper.Push(result); 

            return 0; 
        }

        if(ch == '-')
        {
            var popped = wrapper.Pop(); 

            Console.WriteLine($"Popped value is {popped?.ToString() ?? "N/A"}"); 
            return 0; 
        }

        if(ch == 'p')
        {
            var peeked = wrapper.Peek(); 

            Console.WriteLine($"Peeked value is {peeked?.ToString() ?? "N/A"}"); 
            return 0; 
        }

        if(ch == 's')
        {
            Console.WriteLine($"Stack size is {wrapper.Size}");
            return 0; 
        }
        return 0;    
    }
}