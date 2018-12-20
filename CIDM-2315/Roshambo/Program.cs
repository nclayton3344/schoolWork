//Nathaniel Clayton
//CIDM-2315 
//September 24, 2018
using System;

namespace Roshambo
{
    class Program
    {
        static void Main(string[] args)
        {
            //declare & initialize variables
            string[] option = new string[] {"Rock!", "Paper!", "Scissors!"};
            int playerThrow, cpuThrow, cpuWinCount, playerWinCount;
            char sentinel = 'y';
            Random r = new Random();

            //Game Introduction to be displayed to console
            Console.WriteLine("\nWelcome to the Rock, Paper, Scissors Game! You will be facing our AI in a battle of luck and phsychology. Good Luck.");
            Console.WriteLine("To make your selection, you will input a number to represent either rock, paper, or scissors. Let's Begin\n");
            
            //Do-while which repeats game until user wants to stop
            do{
                //intialize win count to 0
                cpuWinCount = playerWinCount = 0;

                //Loop until either player or cpu wins twice
                while(playerWinCount < 2 && cpuWinCount < 2){
                    
                    //asks user for input and stores into playerThrow
                    Console.Write("\nTo throw Rock, input 1. To throw Paper, input 2. To throw Scissors, input 3: ");
                    playerThrow = Convert.ToInt32(Console.ReadLine());
                    
                    //generates cpu choice
                    cpuThrow = r.Next(1,4);
                    
                    //Check for tie first
                    if(playerThrow == cpuThrow){
                        Console.WriteLine("Tie! Try Again!\n");
                    }else{
                        //Compares playerThrow to cpuThrow to determine winner
                        //This could have been cleaner with a switch statement
                        if(playerThrow == 1){
                            if(cpuThrow == 2){
                                //cpu wins this round
                                Console.WriteLine("You threw " + option[playerThrow - 1] + " The AI threw " + option[cpuThrow - 1]);
                                Console.WriteLine("The AI won this round.\n");
                                cpuWinCount++; 
                            }else{
                                //player wins round
                                Console.WriteLine("You threw " + option[playerThrow - 1] + " The AI threw " + option[cpuThrow - 1]);
                                Console.WriteLine("You won this round.\n");
                                playerWinCount++;
                            }
                            
                        }else if(playerThrow == 2){
                            if(cpuThrow == 1){
                                //player wins round
                                Console.WriteLine("You threw " + option[playerThrow - 1] + " The AI threw " + option[cpuThrow - 1]);
                                Console.WriteLine("You won this round.\n");
                                playerWinCount++; 
                            }else{
                                //cpu wins round
                                Console.WriteLine("You threw " + option[playerThrow - 1] + " The AI threw " + option[cpuThrow - 1]);
                                Console.WriteLine("The AI won this round.\n");
                                cpuWinCount++;
                            }
                        }else {
                            if(cpuThrow == 1){
                                //cpu wins round
                                Console.WriteLine("You threw " + option[playerThrow - 1] + " The AI threw " + option[cpuThrow - 1]);
                                Console.WriteLine("The AI won this round.\n");
                                cpuWinCount++; 
                            }else{
                                //player wins round
                                Console.WriteLine("You threw " + option[playerThrow - 1] + " The AI threw " + option[cpuThrow - 1]);
                                Console.WriteLine("You won this round.\n");
                                playerWinCount++;
                            }
                        }
                    }
                }
                //Display winner based on winCount for player and cpu
                if(playerWinCount > cpuWinCount){
                    //player wins game
                    Console.Write("Congratulations! You beat the AI two out of three times!\n");
                }else{
                    //cpu wins game
                    Console.Write("Sorry! The AI beat you two out of three times. :(\n");
                }
                //ask user to play again and store their response in sentinel
                Console.Write("\nWould you like to play again? Enter y for yes and n for no. (y/n)");
                sentinel = Console.ReadKey().KeyChar;

            }while(sentinel == 'y');

            //program termination indication
            Console.WriteLine("\nThanks for playing! Enjoy your day.");
            
        }
    }
}
