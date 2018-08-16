#include <cstdlib>
#include <iostream>

using namespace std;


// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��

// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        duplication: (���) �����е�һ���ظ�������
// ����ֵ:             
//        true  - ������Ч�����������д����ظ�������
//        false - ������Ч������������û���ظ�������
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
              
              //����numbers[i] �� numbers[numbers[i]]
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

//�ظ�����������������С������
void test1()
{
     int numbers[] = {2,1,3,1,4};
     int duplications[] = {1};
     test("Test1",numbers,sizeof(numbers)/sizeof(int),duplications,sizeof(duplications)/sizeof(int),true);
} 

// �ظ�����������������������
void test2()
{
     int numbers[] = {2,4,3,1,4};
     int duplications[] = {4};
     test("Test2",numbers,sizeof(numbers)/sizeof(int),duplications,sizeof(duplications)/sizeof(int),true);
}

// �����д��ڶ���ظ�������
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// û���ظ�������
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// û���ظ�������
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// ��Ч������
void test6()
{
    int* numbers = NULL;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}


//����˼·ֻ���ж������ظ�����һ�γ����ظ������أ�����ظ����ֵ����ʱ�޷�ȫ����� 
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