#include <cstdlib>
#include <iostream>

using namespace std;

// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����

void ReplaceBlank(char str[],int length)
{
    if(str == NULL && length <=0)
        return ;
    
    /*originalLength Ϊ�ַ���str��ʵ�ʳ���*/
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        ++ originalLength;
        
        if(str[i] == ' ')
        {
            ++ numberOfBlank;
        } 
        ++i;
    }
    
    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length)
        return;
    
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(str[indexOfOriginal] == ' ')
        {
            str[indexOfNew --] = '0';
            str[indexOfNew --] = '2';
            str[indexOfNew --] = '%';
        }
        else
        {
            str[indexOfNew--] = str[indexOfOriginal];
        }
        -- indexOfOriginal;
    }
} 

//=============���Դ���=====================
void Test(char* testName,char str[],int length,char expected[]) 
{
    if(testName != NULL)
        printf("%s begins: ", testName);
    
    ReplaceBlank(str,length);
    
    if(expected == NULL && str == NULL)
        printf("passed.\n");
    else if(expected == NULL && str != NULL)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n"); 
}

// �ո��ھ����м�
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// ����nullptr
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// ������ַ���û�пո�
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char *argv[])
{ 
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    system("PAUSE");
    return EXIT_SUCCESS;
}