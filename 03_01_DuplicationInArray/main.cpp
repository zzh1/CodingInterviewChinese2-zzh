#include <cstdlib>
#include <iostream>

using namespace std;


// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:             
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字
bool duplicate(int numbers[],int length,int* duplication)
{
     if(numbers == NULL || length <= 0)
     {
          return false;
     }
     
     for(int i=0; i<length; ++i)
     {
          if(numbers[i]<0 || numbers[i]>length-1)
          return false;
     }
     for(int i=0;i<length; ++i)
     {
          while(numbers[i] != i)
          {
              if(numbers[i] == numbers[numbers[i]])
              {
                   *duplication = numbers[i];
                   return true;
              }
              
              //交换numbers[i] 和 numbers[numbers[i]]
              int temp = numbers[i];
              numbers[i] = numbers[temp];
              numbers[temp] = temp; 
          }
     }
     return false;
} 

bool contains(int array[],int length,int number)
{
     for(int i=0;i<length;++i)
     {
             if(array[i] == number)
             return true;
     } 
     return false;
}

void test(char *testName,int numbers[],int lengthNumber,int expected[],int expectedExpected,bool validArgument)
{
     printf("%s begins: ",testName);
     
     int duplication;
     bool validInput = duplicate(numbers,lengthNumber,&duplication);
     printf("%d",duplication);
     printf("\n");
     if(validArgument == validInput)
     {
          if(validArgument)
          {
                if(contains(expected,expectedExpected,duplication))
                      printf("Passed. \n");
                else
                    printf("FAILED.\n");
          }
          else
              printf("Passed. \n");
     }
     else
         printf("FAILED. \n");
}

//重复的数字是数组中最小的数字
void test1()
{
     int numbers[] = {2,1,3,1,4};
     int duplications[] = {1};
     test("Test1",numbers,sizeof(numbers)/sizeof(int),duplications,sizeof(duplications)/sizeof(int),true);
} 

// 重复的数字是数组中最大的数字
void test2()
{
     int numbers[] = {2,4,3,1,4};
     int duplications[] = {4};
     test("Test2",numbers,sizeof(numbers)/sizeof(int),duplications,sizeof(duplications)/sizeof(int),true);
}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
    int* numbers = NULL;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}


//此种思路只能判断有无重复，第一次出现重复即返回，多个重复数字的情况时无法全部输出 
int main(int argc, char *argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    system("PAUSE");
    return EXIT_SUCCESS;
}
