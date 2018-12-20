//Nathaniel Clayton
//CIDM-2315 Homework 8
//November 20, 2018
using System;

namespace dupElim
{
    class Program
    {
        static void Main(string[] args)
        {
            int [] myArray = new int[5];
            int [] uniqueArray = new int[5];
            int uniqueCount = 0;

            //loop 5 times getting a new number from the user each time
            for(int i = 0; i < 5; i++){
                bool isValid = false; //check validity of the number given by user
                bool isUnique = true; //check uniqueness of the user defined entry
                //loop until a valid number is given by the user
                while(!isValid){
                    //request number from user and store into our array
                    Console.Write("Enter a number between 10 and 100, inclusive: ");
                    myArray[i] = Convert.ToInt32(Console.ReadLine());
                    //check validity of the number given
                    if(myArray[i] > 9 && myArray[i] < 101){
                        isValid = !isValid;
                    } else {
                        Console.WriteLine("Sorry, your input was invalid.");
                    }
                }
                //make sure the number is unique
                foreach(int element in uniqueArray){
                    if(myArray[i] == element)
                        isUnique = false;
                }
                //store number if it is unique
                if(isUnique){
                    uniqueArray[uniqueCount] = myArray[i];
                    uniqueCount++;
                    Console.WriteLine("\nYou entered {0}, which is a unique value.", myArray[i]);
                }
                //display unique number set
                Console.Write("Unique values up to this point: ");
                for(int k = 0; k < uniqueCount; k++){
                    Console.Write("{0} ", uniqueArray[k]);
                }
                Console.WriteLine("\n");
            }

        }
    }
}
