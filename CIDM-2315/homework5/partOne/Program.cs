//Nathaniel Clayton
//Homework 5 - Part One
//CIDM-2315 10-14-2018
using System;

namespace partOne
{
    class Program
    {
        static void Main(string[] args)
        {
            //variable declaration
            int numTerms;
            int twoDig, threeDig, fourDig, fiveDig;
            twoDig = threeDig = fourDig = fiveDig = 0;
            bool firstTwoDig, firstThreeDig, firstFourDig, firstFiveDig;
            firstTwoDig = firstThreeDig = firstFourDig = firstFiveDig = false;
            //Intro and get number of terms to calculate from user
            Console.WriteLine("Welcome to the PI Calculator.");
            Console.Write("How many terms would you like to use to calculate pi? ");
            numTerms = Convert.ToInt32(Console.ReadLine());

            //Output Header
            Console.WriteLine("# of Terms          PI Approximation");
            Console.WriteLine("----------          ----------------");

            //Loop for number of user defined terms
            int i = 0;
            int j = 1;
            double approx = 0;
            while(i < numTerms){
                //Calculate pi approximation
                if(i % 2 == 0){
                    approx += (double) 4/j;
                } 
                else {
                    approx -= (double) 4/j;
                }
                //Output Term # and PI approximation 
                Console.Write(Convert.ToString(i+1).PadRight(20));
                Console.Write(Convert.ToString(approx).PadRight(16) + '\n');

                //Determine if we hit given approximations
                if(!firstTwoDig && approx >= 3.14 && approx < 3.15){
                    twoDig = i+1;
                    firstTwoDig = true;
                }
                if(!firstThreeDig && approx >= 3.141 && approx < 3.142){
                    threeDig = i+1;
                    firstThreeDig = true;
                }
                if(!firstFourDig && approx >= 3.1415 && approx < 3.1416){
                    fourDig = i+1;
                    firstFourDig = true;;                    
                }
                if(!firstFiveDig && approx >= 3.14159 && approx < 3.1416){
                    fiveDig = i+1;
                    firstFiveDig = true;
                }

                //Increment term counter and denominator for pi approximation formula
                i++;
                j += 2;
            }   

            //Output term determinations
            Console.WriteLine("First got to 3.14 at term {0}", twoDig);
            Console.WriteLine("First got to 3.141 at term {0}", threeDig);
            Console.WriteLine("First got to 3.1415 at term {0}", fourDig);
            Console.WriteLine("First got to 3.14159 at term {0}", fiveDig);

        }
    }
}
