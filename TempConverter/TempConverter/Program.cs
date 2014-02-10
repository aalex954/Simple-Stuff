using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TempConverter
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("This Program Converts Celsius To Fahrenheit");
            Console.WriteLine("Please Enter The Temperature");  //.........Add Try Catch .........//
            double Temp = Convert.ToDouble (Console.ReadLine());
            {  
                  //............. Add A Try Catch To The Switch To Prevent UnAuthorized Input ..........//
                Console.WriteLine("Press 1 To Convert To F \t Press 2 To Convert To Celsius");
                int choice = Convert.ToInt32(Console.ReadLine());

                switch (choice)
                {
                    case 1:
                        Converter CtoF = new Converter();
                        CtoF.CelciusToFahirheit(Temp);
                        break;

                    case 2:
                        Converter FtoC = new Converter();
                        FtoC.FahirheitToCelcius(Temp);
                        break;

                    default:
                        Console.WriteLine("Invalid Input (Choose Only 1 or 2)");

                        break;
                }
            }   
              

        }
    }
}
