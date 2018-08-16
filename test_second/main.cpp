#include <cstdlib>
#include <iostream>

#include "CMyString.h"

using namespace std;

void Test1()
{
   printf("Test1 begins:\n");
   
   char* text="Hello world";
   
   CMyString str1(text);
   CMyString str2;
   str2 = str1;
   
   printf("The expected result is: %s.\n",text);
   
   printf("The actual result is: ");
   str2.Print();
   printf(".\n");
}


int main(int argc, char *argv[])
{
    Test1();
    system("PAUSE");
    return EXIT_SUCCESS;
}
