using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grade_Calculator
{
    class Program
    {
        
        static void Main(string[] args)
        {
            Calculator GradeCalc = new Calculator();

            Console.WriteLine("This Program Takes Three Grades And Computes The Average \n");

            GradeCalc.GradeAverage();       

        }
    }
}
