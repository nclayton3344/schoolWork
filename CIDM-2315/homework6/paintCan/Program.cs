using System;

namespace paintCan
{
    class Program
    {
        static void Main(string[] args)
        {
            int height = 0, width = 0, length = 0;
            int numCans;
            decimal totalCost = 0;

            //Get height, width, and length from user
            height = getSize("height");
            width = getSize("width");
            length = getSize("length");

            //Compute number of paint cans required
            numCans = computeNumberofCans(height, width, length);

            //Compute cost based on number of paint cans required for the job
            totalCost = computeCost(numCans);             


            /* Finally print a summary of the results 
             * You can leave this code in Main
             */
            Console.WriteLine();
            Console.WriteLine("Height of room: {0}", height);
            Console.WriteLine("Width of room: {0}", width);
            Console.WriteLine("Length of room: {0}", length);
            Console.WriteLine("Number of paint cans needed: {0}", numCans);
            Console.WriteLine("Total Cost: {0:C}", totalCost);        
        }

        //Pass which dimension you are getting as a string
        //example getSize("height")
        static int getSize(string dim){
            bool validInput = false;
            int num = 0;
            while (!validInput)
            {
                Console.Write("Enter the {0} of the room: ", dim);
                num = Convert.ToInt32(Console.ReadLine());
                // if entered height is less than or equal to 0, it is invalid and user must re-enter
                // Also if height is greater than or equal to 1000, that is too big and also invalid.
                if (num <= 0 | num >= 1000) 
                {
                    Console.WriteLine("Invalid {0}. Try again.", dim);
                }
                else
                {
                    validInput = true;
                }
            }
            return num;
        }

        //Pass height, width, and length as params
        //returns number of cans 
        static int computeNumberofCans(int height, int width, int length){
            int twoWalls = height * length;
            int otherTwoWalls = height * width;
            int ceiling = length * width;
            double exactCans = (double)(2 * twoWalls + 2 * otherTwoWalls + ceiling) / 365.0;
            return (int)Math.Ceiling(exactCans);
        }

        //Computes cost based on number of cans required for the job
        //returns totalCost as decimal data type
        static decimal computeCost(int numCans){
            const decimal COST_OF_PAINT_CAN = 4.25M;
            decimal totalCost = COST_OF_PAINT_CAN * numCans;
            if (numCans > 10)
            {
                totalCost *= 0.9M; // 10% Discount 1 - 0.10 = 0.90
            }
            else if (numCans > 5)
            {
                totalCost *= 0.94M; // 6% Discount
            }

            return totalCost;
        }

    }
}
