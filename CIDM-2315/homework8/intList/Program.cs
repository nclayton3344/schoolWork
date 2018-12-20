//Nathaniel Clayton
//CIDM-2315 Homework 8
//November 20, 2018
using System;
using System.Collections.Generic;

namespace intList
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> list = new List<int>();
            int sentinel = 0; //sentinel controller
            int temp;

            while(sentinel != -1){
                //ask for user input and store in temp variable
                Console.Write("\nEnter a non-negative number to add to the list: ");
                temp = Convert.ToInt32(Console.ReadLine());

                //check if user input value is in the list already
                if(list.Contains(temp)){
                    Console.WriteLine("\nHey, the number you input is already in the list. I'm not adding it.");
                } else {
                    list.Add(temp);
                }

                //check if user wants to continue or quit
                Console.Write("\nEnter -1 to quit or 0 to continue: ");
                sentinel = Convert.ToInt32(Console.ReadLine());
            }
            //display the list as given by the user
            Console.WriteLine("\nHere is your list in the order it was created: ");
            foreach(int item in list){
                Console.Write("{0} ", item);
            }
        }
    }
}
