#include <cstdlib>
#include <iostream>

using namespace std;

// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。
bool g_InvalidInput = false;

bool equal(double num1,double num2);
double PowerWithUnsignedExponent(double base,unsigned int exponent);

double Power(double base,int exponent)
{
    g_InvalidInput = false;
    
    //cout<<equal(base,0.0)<<endl;
    if(equal(base,0.0) && exponent<0)
    {
        g_InvalidInput = true;
        return 0.0;
    }
    
    unsigned int absExponent = (unsigned int)(exponent);
    if(exponent<0)
        absExponent = (unsigned int)(-exponent);
    //cout<<base<<absExponent<<endl;
    double result = PowerWithUnsignedExponent(base,absExponent);
    
    if(exponent < 0)
        return 1.0/result;
    
    return result;
}

/*
//方法一：最简单的思路， 
double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
    double result = 1.0;
    
    for(int i=1; i<=exponent;++i)
        result*=base;
    return result;
}
*/


//方法二，最完善的，效率较高 
double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;
    
    double result = PowerWithUnsignedExponent(base,exponent >> 1);
    result *= result;
    
    if((exponent & 0x1) == 1)
        result *= base;
    
    return result;
}


bool equal(double num1,double num2)
{
    if((num1-num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

// ====================测试代码====================
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power(base, exponent);
    //cout<<result<<endl;
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char *argv[])
{
    // 底数、指数都为正数
    Test("Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    Test("Test2", -2, 3, -8, false);

    // 指数为负数
    Test("Test3", 2, -3, 0.125, false);

    // 指数为0
    Test("Test4", 2, 0, 1, false);

    // 底数、指数都为0
    Test("Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    Test("Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    Test("Test7", 0, -4, 0, true);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
