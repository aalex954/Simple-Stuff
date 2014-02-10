using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grade_Calculator
{
    class Calculator
    {
        public void GradeAverage()
        {

            Console.Write("Please Input The First Grade  : ");
            double Grade1 = Convert.ToDouble(Console.ReadLine());
            Console.Write("Please Input The Second Grade : ");
            double Grade2 = Convert.ToDouble(Console.ReadLine());
            Console.Write("Please Input The Third Grade  : ");
            double Grade3 = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("");
            Console.Write("If You Have Any Bonus Points Input Them Here : ");
            double BonusPoints = Convert.ToDouble(Console.ReadLine());


            double gradeTotal = Grade1 + Grade2 + Grade3;
            double FinalGrade = gradeTotal / 3 + BonusPoints;
            Console.WriteLine("");
            string Final = string.Format("Your Final Grade Is : {0} \n", FinalGrade);
            Console.WriteLine(Final);


            if (FinalGrade <= 50)
            {
                Console.WriteLine("You Failed The Class");
            }

            else if (FinalGrade <= 60)
            {
                Console.WriteLine("You Have A 'D' In The Class ");
            }

            else if (FinalGrade <= 70)
            {
                Console.WriteLine("You Have A 'C' In The Class");
            }

            else if (FinalGrade <= 80)
            {
                Console.WriteLine("You Have A 'B' In The Class");
            }

            else if (FinalGrade <= 90)
            {
                Console.WriteLine("You Have A 'A' In The Class");
            }

            else if (FinalGrade >= 100)
            {
                Console.WriteLine("You Have A Perfect Score In The Class");
            }

            return;

        }


    }
}
