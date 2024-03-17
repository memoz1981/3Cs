using System; 
using System.Text; 

namespace DataStructures.Stacks; 

public class Stack<T>
{
    public Stack(T value, Stack next = null)
    {
        Value = value; 
        next = next; 
    }

    public T Value { get; set; }
    public Stack next { get; set; }

    public override ToString() => $"{ value }";
}

public class StackWrapper<T>
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
        var stack = new Stack(value, Top); 
        Top = stack; 
        _count++; 
    } 

    public T Pop()
    {
        var top = Top; 

        Top = top?.next; 
        _count--;
        return top; 
    }

    public T Peek() => Top; 

    public int Size { get => _count; }

    public bool IsEmpty { get => _count == 0; }

    
    public override ToString()
    {
        var builder = new StringBuilder(); 
        builder.AppendLine("Stack: "); 
        var temp = Top; 
        while(temp != null)
        {
            builder.Append($"{temp.ToString()} -> ");
        }
        builder.Append("NULL"); 
    }

    public void RunStackInInteractiveMode()
    {
        Console.Clear(); 
        printf("\n\n\nINTERACTIVE STACK COMMANDS:\n"); 
        Console.WriteLine("[c] - for clearing the screen\n");
        Console.WriteLine("[r] - to print the stack\n");
        Console.WriteLine("[e] - to exit\n");
        Console.WriteLine("[+] - to push integer to the stack\n");
        Console.WriteLine("[-] - to pop\n");
        Console.WriteLine("[p] - to peek\n");
        Console.WriteLine("[s] - to print stack count\n");

        char ch = Console.ReadKey().KeyChar; 

        var stackWrapper = new StackWrapper<int>(); 
        int result;
        do {
            result = RunStackCycle(stackWrapper, ch); 
        }
        while(result != -1)
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
            int result = Int32.Parse(Console.Readline()); 

            wrapper.Push(value); 

            return 0; 
        }

        if(ch == '-')
        {
            int popped = wrapper.Pop(); 

            Console.WriteLine($"Popped value is {popped}"); 
            return 0; 
        }

        if(ch == 'p')
        {
            int popped = wrapper.Peek(); 

            Console.WriteLine($"Peeked value is {popped}"); 
            return 0; 
        }

        if(ch == 's')
            Console.WriteLine($"Stack size is {wrapper.Size}");
    }
}