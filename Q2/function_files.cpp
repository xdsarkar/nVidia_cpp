#include<stdio.h> /* printf */
#include<string> /* std::string */
#include<string.h> /* const char * strstr ( const char * str1, const char * str2 ); */

using namespace std;

unsigned int FindFunctionDefn(const char* strFunctionName, const char* strSourceCode) /* FindFunctionDefn("func1", "test.c") */
{
	FILE *fp;
	unsigned int line_count=1, find_result=0; /* Line starts from 1, On finding string iterate find_result to 1 */
	char temp[512];

	const char* checkstr = ""; /* Empty string */
	string strapp = strFunctionName; 
	strapp += "();";
	checkstr = strapp.c_str();
	/* 
		Example: if strFunctionName = "func1";
		strapp="func1";
		strapp="func1();";
		checkstr = "func1();"
	*/ 

	if((fp = fopen(strSourceCode, "r")) == NULL) /* If file doesn't exists */
	{
		return -1;
	}

	while(fgets(temp, 512, fp) != NULL) /* Considering each line with a max of 512 characters, fgets reads till encountered "\n" */
	{
		if((strstr(temp, strFunctionName) != NULL)) /* Checks if strFunctionName is substring of temp */
		{
			if(strstr(temp, checkstr) == NULL) /* If strFunctionName exists, check if it's a function call/ function declaration as function call is made like func1(); */
			{
				find_result = 1; /* If found */
				break; /* Breaks if it's a function declaration and not function call */
			}
		}
		line_count++; /* Count line number */
	}

	if(fp) fclose(fp); /* Closes stream if open */
	if(find_result == 0) line_count = 0; /* If not found, return 0 */

	return line_count;
}

int main(int argc, char *argv[]) /*Accepting command line arguments */
{
	unsigned int result = 0;
	const char* str[]={argv[1], argv[2]};
	result = FindFunctionDefn(str[0],str[1]);
	if(result == -1) printf("File can't be opened\n");
	else if(result == 0) printf("Function declaration is not available\n");
	else printf("Function declaration is present on line %d of %s file\n", result, str[1]);
	return 0;
}