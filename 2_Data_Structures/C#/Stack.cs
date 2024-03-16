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
        Console.WriteLine("Running stack in interactive mode..."); 
    }
}