//Nathaniel Clayton
//CIDM-2315 Homework 6
//11/1/2018
using System;

namespace coinflip
{
    class Program
    
    {
        //random generator
        //created as static to prevent instances being created in short amount of time
        //resulting in same number generation
        static Random rnd = new Random();

        static void Main(string[] args)
        {   
            //variable declaration
            int flipsCount;
            int headCount, tailCount;
            headCount = tailCount = 0;

            //Get data from user
            Console.Write("How many times would you like to flip this coin? ");
            flipsCount = Convert.ToInt32(Console.ReadLine());            

            //repeat number of times user indicates
            for(int i = 0; i < flipsCount; i++){
                //Output result for single flip
                if(Flip()){
                    Console.WriteLine("Flip {0} was heads!", i);
                    headCount++;
                } else {
                    Console.WriteLine("Flip {0} was tails!", i);
                    tailCount++;
                }
            }
            //Output result of all flips
            Console.WriteLine("Heads came up {0} times.", headCount);
            Console.WriteLine("Tails came up {0} times.", tailCount);

        }
        
        //Function to simulate coin flip
        static bool Flip(){
            //generate number 1 or 2
            int flipResult = rnd.Next(1, 3);
            //return true for heads, false for tails
            return (flipResult % 2 == 0);
        }
    }
}
