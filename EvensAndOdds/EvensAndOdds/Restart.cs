using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EvensAndOdds
{
    class Restart
    {
        public void restart()
        {
            Restart restart = new Restart();

            Console.WriteLine("Would You Like To Run Again ? \n\n");
            Console.WriteLine("Enter 1 For Yes Enter 2 For No ");

            double selection = Convert.ToDouble(Console.ReadLine());

            if (selection == 1)
            {
                restart.restart();
                
            }
            else
            {
                Console.Read();
                Console.Clear();
                Console.Beep(); 
            }
        }
    }
}
