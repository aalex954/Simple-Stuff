using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Program_Test
{
    class Program
    {
        static void Main(string[] args)
        {
            double a = 0;
            double b = 0;
            double c = 0;

            Console.WriteLine("This Program Adds 3 Numbers Together");


            Console.Write("Would You Like To Run The Program?" + " \n " + " \n " + "Enter 0 for Yes or 1 for  No :");

            double YorN = Convert.ToDouble (Console.ReadLine());
                    

                if ( YorN == 0)
	            { 
		 	                                     
                    Console.Write("Enter The 1st Number :");
                    double Num1 = double.Parse(Console.ReadLine());

                    Console.Write("Enter The 2nd Number :");
                    double Num2 = double.Parse(Console.ReadLine());

                    Console.Write("Enter The 3rd Number :");
                    double Num3 = double.Parse(Console.ReadLine());

                    a = Num1;

                    Console.WriteLine("Value of variable 'a' is" + " " + (a) );
                    Console.WriteLine("Value of variable 'b' is" + " " + (b) );
                    Console.WriteLine("Value of variable 'c' is" + " " + (c) );

                    Console.WriteLine("Enter input for variable 'g'");
                   
                    string g = (Console.ReadLine());
                    Console.WriteLine("The value of Variable g which is a Double is " + g);
                    
                }

            else
            {
                Console.WriteLine ("GoodBye");
            }

        }
    }
}
