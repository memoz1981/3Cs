using System;
using System.Text; 

namespace DataStructures.Queues; 

public class Queue<T> where T : struct
{
    public Queue(T value)
    {
        Value = value;
        Next = null; 
    }

    public T Value { get; set; }

    public Queue<T> Next { get; set; }

    public override string ToString() => $"{Value}";
}

public class QueueWrapper<T> where T : struct
{
    private uint _count = 0; 
    public Queue<T> Head { get; set; }

    public Queue<T> Tail { get; set; }

    public void Enqueue(T value)
    {
        var queue = new Queue<T>(value); 
        
        if(IsEmpty)
        {
            Head = queue; 
            Tail = queue; 
            return; 
        }

        Tail.Next = queue; 
        Tail = queue; 
    }

    public T? Dequeue()
    {
        if(IsEmpty)
            return null; 

        var value = Head.Value; 
        Head = Head.Next; 

        return value; 
    }

    public T? Peek() => Head?.Value; 

    public uint Size { get => _count; }

    public bool IsEmpty { get => _count == 0; }

    public override string ToString()
    {
        var builder = new StringBuilder(); 
        builder.AppendLine("Queue: "); 
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

public class QueueRunner
{
    public void RunQueueInInteractiveMode()
    {
        var wrapper = new QueueWrapper<int>(); 
        int result;
        Console.Clear(); 
        do {
             
            result = RunQueueCycle(wrapper); 
        }
        while(result != -1); 
    }

    private int RunQueueCycle(QueueWrapper<int> wrapper)
    {
        Console.WriteLine("\n\n\nINTERACTIVE QUEUE COMMANDS:\n"); 
        Console.WriteLine("[c] - for clearing the screen\n");
        Console.WriteLine("[r] - to print the queue\n");
        Console.WriteLine("[e] - to exit\n");
        Console.WriteLine("[+] - to enqueue an integer to the queue\n");
        Console.WriteLine("[-] - to dequeue the queue\n");
        Console.WriteLine("[p] - to peek\n");
        Console.WriteLine("[s] - to print the queue count\n");
        char ch = Console.ReadKey().KeyChar;
        Console.WriteLine(); 

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
            Console.WriteLine("Enter an integer to add to the queue: ");
            var resultStr = Console.ReadLine().ToString(); 
            int result = Int32.Parse(resultStr); 

            wrapper.Enqueue(result); 

            return 0; 
        }

        if(ch == '-')
        {
            var popped = wrapper.Dequeue(); 

            if(popped != null)
                Console.WriteLine($"Dequeued value is {popped}"); 
            else
                Console.WriteLine("Queue is empty"); 
            return 0; 
        }

        if(ch == 'p')
        {
            var peeked = wrapper.Peek();
            
            if(peeked != null)
                Console.WriteLine($"Peeked value is {peeked}"); 
            else
                Console.WriteLine("Queue is empty");  
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