//NATHANIEL CLAYTON
//HOMEWORK 5 PART TWO
//CIDM-2315 10*14*2018
using System;

namespace partTwo
{
    class Program
    {
        static void Main(string[] args)
        {   
            //Display msg to user
            Console.WriteLine("DISPLAY PYTHAGOREAN TRIPLES!");

            //calculate all possible pythagorean triples
            for(int i = 1; i <= 500; i++){
                for(int j = 1; j <= 500; j++){
                    for(int k = 1; k <= 500; k++){
                        if((i*i) + (j*j) == (k*k))
                            Console.WriteLine("{0}, {1}, {2}", i, j, k);
                    }
                }
            }
        }
    }
}
