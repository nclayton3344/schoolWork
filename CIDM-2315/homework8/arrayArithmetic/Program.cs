//Nathaniel Clayton
//CIDM-2315 Homework 8
//November, 20, 2018
using System;
namespace arrayArithmetic
{
    class Program
    {
        static void Main(string[] args)
        {
            double [] dubArray = new double[10];

            //cycle ten times to fill values
            for(int i = 0; i < 10; i++){
                //try-catch to validate user input
                try{
                    Console.Write("Enter a number value: ");
                    dubArray[i] = Convert.ToDouble(Console.ReadLine());

                } catch {
                    Console.Write("Invalid input, try again! Enter a new number value: ");
                    dubArray[i] = Convert.ToDouble(Console.ReadLine());
                }
            }
            //output sum
            Console.WriteLine("The sum of the values is {0}", Sum(dubArray));
        }

        //function to calculate sum of the entries in a double array
        static double Sum(double [] array){
            double sum = 0;
            //cycle through the array adding values to sum
            foreach(double element in array){
                sum += element;
            }
            //return the sum to the calling function
            return sum;
        }
    }
}
