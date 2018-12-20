//NATHANIEL CLAYTON 
//CIDM-2315 - HOMEWORK 4
//OCTOBER 2, 2018
using System;

namespace creditCalc
{
    class Program
    {
        static void Main(string[] args)
        {
            //variable declarations
            int accountNum;
            char sentinel = 'y';
            decimal beginningMonthlyBalance, currentMonthCharges, creditAllowed, currentMonthCredits, newBalance;            

            do{

                //asks user for account number
                Console.Write("\nEnter the customer's account number: ");
                accountNum = Convert.ToInt32(Console.ReadLine());

                //asks user for account number
                Console.Write("\nEnter the customer's balance at the beginning of the month: ");
                beginningMonthlyBalance = Convert.ToDecimal(Console.ReadLine());

                //asks user for credits applied to account
                Console.Write("\nEnter the customer's total credits applied for this month: ");
                currentMonthCredits = Convert.ToDecimal(Console.ReadLine());

                //asks user for current month charges
                Console.Write("\nEnter the customer's total charges applied for this month: ");
                currentMonthCharges = Convert.ToDecimal(Console.ReadLine());

                //asks user for credit limit
                Console.Write("\nEnter the customer's credit limit: ");
                creditAllowed = Convert.ToDecimal(Console.ReadLine());
                
                //calculate new balance and display to console
                newBalance = beginningMonthlyBalance + currentMonthCharges - currentMonthCredits;
                Console.WriteLine("\nThe new balance for Customer #{0}: ${1}", accountNum, newBalance);

                //determine if credit limit has been reached
                if(newBalance > creditAllowed)
                    Console.WriteLine("ALERT! CREDIT LIMIT EXCEEDED!");

                //ask user if there is more data
                Console.Write("\nWould you like to calculate for another account? Enter y for yes and n for no. (y/n)");
                sentinel = Console.ReadKey().KeyChar;

            }while(sentinel == 'y'); 

            Console.WriteLine("\nPROGRAM TERMINATED.");
        }
    }
}
