#include <cstdlib>
#include <iostream>

#include "CMyString.h"

using namespace std;


// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

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

void Test2()
{
   printf("Test2 begins: \n");
   char* text = "Hello world";
   
   CMyString str1(text);
   str1 = str1; 
   
   printf("The expeckted result is: %s. \n",text);
   
   printf("The actual result is: ");
   str1.Print();
   printf(".\n");
    
}

void Test3()
{
     printf("Test2 begins: \n");
     char* text = "Hello world";
     
     CMyString str1(text);
     CMyString str2,str3;
     str3=str2=str1;
     
     printf("The expeckted result is: %s. \n",text);
   
     printf("The actual result is: ");
     str2.Print();
     printf(".\n");
     
     printf("The expected result is: %s. \n",text);
     
     printf("The actual result is: ");
     str3.Print();
     printf(".\n");
     
}


int main(int argc, char *argv[])
{   
    //Test1();
    //Test2();
    Test3();
    system("PAUSE");
    return EXIT_SUCCESS;
}


