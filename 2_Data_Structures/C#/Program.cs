using DataStructures.Stacks; 
using DataStructures.Queues; 
using System; 
using System.Text; 

int result = 0; 
while(result != -1) {
    Console.Clear();
    Console.WriteLine("\nSELECT DATA STRUCTURE TO DEBUG \n"); 
    Console.WriteLine("[s] - for stack \n");
    Console.WriteLine("[q] - for queue \n");
    Console.WriteLine("[l] - for linked list \n");
    Console.WriteLine("[t] - for binary search tree \n");
    Console.WriteLine("[l] - to dequeue the queue\n");
    Console.WriteLine("[h] - to peek\n");
    Console.WriteLine("[e] - exit \n");

    char key = Console.ReadKey().KeyChar;
    Console.WriteLine(key); 

    switch (key)
    {
        case 's' :
            var stackRunner = new StackRunner(); 
            stackRunner.RunStackInInteractiveMode();
            Console.WriteLine("Exiting stack runnner..."); 
            continue;  
        
        case 'q' :
            var queueRunner = new QueueRunner(); 
            queueRunner.RunQueueInInteractiveMode();
            Console.WriteLine("Exiting queue runnner..."); 
            continue;  

        case 'e': 
            result = -1;
            continue;  
        
        default:
            continue; 
    }
}
return 0;   