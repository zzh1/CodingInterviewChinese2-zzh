class CMyString
{
 public:
        CMyString(char* pData = NULL);
        CMyString(const CMyString& str);
        ~CMyString(void);
        
        CMyString& operator = (const CMyString& str);
        void Print();
 private:
         char* m_pData;
};
