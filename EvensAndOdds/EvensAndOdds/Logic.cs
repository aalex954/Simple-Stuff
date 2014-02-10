using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EvensAndOdds
{
    class Start
    {


        public void Logic()
        {

            Console.WriteLine("This Program Determines If A Number Is Even Or Odd \n");

            Console.WriteLine("Enter The Number You Want To Test :");

            Double input = Convert.ToDouble(Console.Read());

            if (input % 2 == 0)
            {
                Console.WriteLine("");
                Console.WriteLine("The Number You Entered Is Even! \n\n\n\n");
            }

            else
            {
                Console.WriteLine("");
                Console.WriteLine("The Number You Entered Is Odd \n\n\n\n");
            }

        }

    }
}
