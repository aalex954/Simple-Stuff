using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TempConverter
{
    class Converter
    {
        public void CelciusToFahirheit(double Temp) 
        {
            Temp = Temp * 9 / 5 + 32;
            Console.WriteLine(Temp);
            return;
        }

        public void FahirheitToCelcius(double Temp)
        {
            Temp = (Temp - 32) * 5 / 9;
            Console.WriteLine(Temp);
            return;
        }
    }
}
