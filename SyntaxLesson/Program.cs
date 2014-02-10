using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SyntaxLesson 
{ // <- Begin Namespace scope
    class Program
    { // <- Begin class scope

        // Class level variables are UpperCamelCase <-

        static string HelloWorld = "Hello World!";

        static void Main(string[] args)
        {
            // Method level variables are in lowerCamelCase <-
            int birthYear = 1990;

            for (int i = 0; i < 3; i++)
            { // <- befin for scope
				new Program().SayHello();
            } // <- End for scope

            if (true)
            {// <- Begin if scope
                int number = 5; 
            }// <- End if scope

            // the 'number' variable cannot be called outside of the 'if' scope

            // statements end in a semicolon, loops and if "blocks" or "scopes" do not
            Console.WriteLine("Press any key to exit");
            Console.ReadKey(true);
        } 

        void SayHello()
        {
            // The 'HelloWorld' class level variable can be called because it is in an outerscope relative to 
            // the this Method
            Console.WriteLine(HelloWorld);
        }
    } // <- End class scope
} // <- End namesapce scope

/*
 * Scope - Any code statements between 2 braces
 * Statement - Any single line of code that does not involve scoping.
 * 
 * Scoped variables can always reach from the outer scope to the inner scope
 * An inner scope can call an outer scope's variable.
 * An outer scope cannot call an inner scopes variable.
 * 
 * Method declarations go inside the class scope. 
 */


//////////////////////////////////////////////////////////////////////////////
//                              NOTICE                                      //
//  *   I do not have extra spaces in scopes                            *   //
//  *   This condences the code and makes it much easier to read        *   //
//////////////////////////////////////////////////////////////////////////////