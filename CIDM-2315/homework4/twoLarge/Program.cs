//Nathaniel Clayton
//CIDM-2315 Homework 4
//October 2, 2018
using System;

namespace twoLarge
{
    class Program
    {
        static void Main(string[] args)
        {
            //variable declaration
            int largest = -Int32.MaxValue, twoLarge = -Int32.MaxValue;//Set largest to smallest possible value
            int num, num1, num2, num3, num4, num5, num6, num7, num8, num9, num10; //When can we start using arrays?
            num = num1 = num2 = num3 = num4 = num5 = num6 = num7 = num8 = num9 = num10 = -Int32.MaxValue; // setting at this insane value to prevent erros when user enters 0 since default value is 0

            //Information heading
            Console.WriteLine("Input 10 numbers and I'll tell you which are the largest two numbers that you input.");

            //Asks user for 5 integer inputs, adds each input to sum, multiplies by product, and compares for small/largest number
            for(int i = 0; i < 10; i++){

                //Asks user for integer input and checks for validity                
                bool valid = false;
                while(!valid){
                    Console.Write("#" + (i + 1) + " Enter your number: ");
                    num = Convert.ToInt32(Console.ReadLine());  

                    //Checks if this number has already been entered
                    if((num == num1 || num == num2 || num == num3 || num == num4 || num == num5 || num == num6 || num == num7 || num == num8 || num == num9 || num == num10 )){
                        Console.WriteLine("You input an already existing number, please try again!");
                    } else {
                        valid = true;
                    }   

                }            

                //Largest/Second largest comparison
                if(num > largest){
                    twoLarge = largest;
                    largest = num;
                }
                else if(num > twoLarge){
                    twoLarge = num;
                }

                //assign num to one of our placeholder variables based on index number
                switch(i){
                    case 0:
                        num1 = num;
                        break;
                    case 1:
                        num2 = num;
                        break;
                    case 2:
                        num3 = num;
                        break;
                    case 3:
                        num4 = num;
                        break;
                    case 4:
                        num5 = num;
                        break;
                    case 5:
                        num6 = num;
                        break;
                    case 6:
                        num7 = num;
                        break;
                    case 7:
                        num8 = num;
                        break;
                    case 8:
                        num9 = num;
                        break;
                    case 9:
                        num10 = num;
                        break;
                    
                }

            }
            //Displays two largest numbers to user            
            Console.WriteLine("The largest number entered was {0}, and the second largest was {1}.", largest, twoLarge);
        }
    }
}
