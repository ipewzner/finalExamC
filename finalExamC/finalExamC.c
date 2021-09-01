// finalExamC.c : This file contains the 'main' function. Program execution begins and ends there.
//


#include "../MyString/MyString.h"

int main(void)
{
	String *myString , *youString;
	myString = CreateString("aaa");
	youString= CreateString("aaa");
	printf("\nMy string: %s", GetString(myString));
	printf("\nMy string length is: %d",(int)GetStringLength(myString));
	IsEmpty(myString) ? printf("\nMy string empty.") : printf("\nMy string isn't empty.");
	
	printf("\nCompare String: %d",CompareString(myString, youString));

	DeleteString(myString);
    DeleteString(youString);
	IsEmpty(myString) ? printf("\nMy string empty.") : printf("\nMy string isn't empty.");

	



	return 0;
}
