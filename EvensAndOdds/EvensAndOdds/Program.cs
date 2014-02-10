using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EvensAndOdds
{
    class Program
    {
        static void Main(string[] args)
        {

            Start Run = new Start();
            Restart NewNumber = new Restart();

            Run.Logic();
            NewNumber.restart();

        }
    }
}
