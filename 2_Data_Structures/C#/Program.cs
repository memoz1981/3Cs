using DataStructures.Stacks; 
using DataStructures.Queues; 
using DataStructures.LinkedLists; 
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
    Console.WriteLine("[e] - exit \n");

    char key = Console.ReadKey().KeyChar;
    Console.WriteLine(key); 

    switch (key)
    {
        case 's' :
            var stackRunner = new StackRunner(); 
            stackRunner.RunStackInInteractiveMode();
            continue;  
        
        case 'q' :
            var queueRunner = new QueueRunner(); 
            queueRunner.RunQueueInInteractiveMode();
            continue;  
        
        case 'l' :
            var listRunner = new LinkedListRunner(); 
            listRunner.RunLinkedListInInteractiveMode(); 
            continue;  

        case 'e': 
            result = -1;
            continue;  
        
        default:
            continue; 
    }
}
return 0;   