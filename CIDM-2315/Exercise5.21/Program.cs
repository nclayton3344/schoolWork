using System;

namespace Exercise5._21
{
    class Program
    {
        static void Main(string[] args)
        {
            //variable declaration
            int counter, number, largest;
            
            //initialization
            counter = 0;
            largest = Int32.MinValue;

            while(counter < 10){
                //Ask user for input and retrieve input
                Console.Write("Enter a number: ");
                number = Convert.ToInt32(Console.ReadLine());
                
                //Check number against largest
                if(number > largest)
                    largest = number;
                
                //Increment counter
                counter++;
            }
            //Display Largest Number
            Console.WriteLine("The largest number you entered is: {0}", largest);

            
        }
    }
}
