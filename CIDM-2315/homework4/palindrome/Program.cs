//Nathaniel Clayton
//CIDM-2315 Homework 4
//October 3, 2018
using System;

namespace palindrome
{
    class Program
    {
        static void Main(string[] args)
        {
            //variable declaration
            int num;

            //Info display
            Console.WriteLine("Let's enter 5 digit numbers and check it they are palindromes. ");
            //Get number from user
            Console.Write("Enter a 5 digit number: ");
            num = Convert.ToInt32(Console.ReadLine());
            //Check user input for 5 digits
            while((num / 10000) == 0 || (num / 10000) > 9){
                Console.WriteLine("Your number was not 5 digits long, try again!");
                Console.Write("Enter a 5 digit number: ");
                num = Convert.ToInt32(Console.ReadLine());
            }
            //Check equality between 1st and last digit and second with second to last digit
            if ((num / 10000) == (num % 10) && (((num - ((num / 10000) * 10000))) / 1000) == (((num - (num % 10)) % 100) / 10)){
                Console.WriteLine("The number you entered, {0}, is a palindrome.", num);
            }
            else{
               Console.WriteLine("The number you entered, {0}, is NOT a palindrome.", num); 
            }
        }
    }
}
