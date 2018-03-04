/* KMP Algorithm - Function Declaration */
/* Time Complexity = O(len1 + len2), where len1 is length of pattern i.e., "func2" and len2 is length of sourceFilecode to be searched for the pattern "func2(){" */
/* Space Complexity = O(len2) */

#include<stdio.h> /* printf */

typedef unsigned int ui;

using namespace std;

void failFunction(const char* strFunctionName, ui F[], ui len2) /* Prefix Table for strFunctionName */
{
    ui i=1, j=0;
    F[0]=0;
    while(i<len2)
    {
        if(strFunctionName[i] == strFunctionName[j])
        {
            F[i]=j+1;
            i++;
            j++;
        }
        else if(j>0) j=F[j-1];
        else 
        {
            F[i]=0;
            i++;
        }
    }
} /* Prefix Table */

ui KMPalgo(const char* strSourceCode, ui len1, const char* strFunctionName, ui len2)
{
    ui i=0, j=0, k=0, lines=0;
    ui find_result=0;
    ui F[len2];
    failFunction(strFunctionName, F, len2);
    while(i<len1)
    {
        if((strSourceCode[i]=='\\') && (strSourceCode[i+1]=='n')) lines++; /* if \\n encounters, iterate lines */
        if(strFunctionName[j] == strSourceCode[i])
        {
            if(j==len2-1)
            {
                if(strSourceCode[i+1]=='(') /* func2( */
                {   
                    k=i+1;
                    while(strSourceCode[k]!=')') k++; /* func2() */
                    if(strSourceCode[k+1]=='{') /* func2(){ */
                    {
                        find_result=1; /* changes flag to 1 i.e, found function declaration */
                        break; /* break from while loop, return line number */
                    }
                }
                j=0;
            }
            else 
            {
                i++; j++;
            }
        }
        else if(j>0) j=F[j-1];
        else i++;
    }
    if(find_result==1) return lines+1;
    else return find_result;   
}

ui FindFunctionDefn(const char* strSourceCode, const char* strFunctionName)
{   
    ui len1=0, len2=0;
    for(int i=0; strSourceCode[i] != '\0'; i++) len1++; /* length of string strSourceCode, required for KMP */
    for(int i=0; strFunctionName[i] != '\0'; i++) len2++; /* length of string strFunctionName, required for KMP */
    ui line_num = KMPalgo(strSourceCode, len1, strFunctionName, len2); /* calling KMP algorithm */
    return line_num; /* return line number of function declared */
}

int main()
{
    char strFunctionName[] = "func2";
    char strSourceCode[] = "int func1(){ return 0; }\\n int func2(){ return 1; }\\n" "int main(int argc, char*argv[]){ return func2(); }\\n"; 
    ui result = FindFunctionDefn((const char*)strSourceCode, (const char*)strFunctionName);
    if(result == 0) printf("Function declaration is not available\n");
    else printf("Function declaration is present on line %d of source code string\n", result);
    return 0;
}



