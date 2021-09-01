// MyString.c : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "MyString.h"
#include <malloc.h>

static int g_lastError = 0;
void getLastLinkedListError(void)
{
	printf("\n------------------");
	switch (g_lastError)
	{		
	case(1):
		printf("\nError: no *char!");
		break;

	case(2):
		printf("\nError: no *String!");
		break;

	case(3):
		printf("\nError: no *char in *String!");
		break;
		
	default:
		printf("\nNo errors!");
		break;
	}
	printf("\n------------------");

}

String* CreateString(const char* source)
{
	if (!source)
	{
		g_lastError = 1;
		return;
	}
	String* result = (String*)malloc(sizeof(String));
	result->str = (char*)malloc(strlen(source) * sizeof(char));
	strcpy_s((result->str), strlen(source) + 1, source);
	return result;
}

BOOL DeleteString(String* toDelete)
{
	if (!toDelete)
	{
		g_lastError = 2;
		return;
	}					
	char* temp = toDelete->str;
	if (!toDelete->str)
	{
		g_lastError = 3;
	}
	free(toDelete);	  
	//free(temp);
	return 0;
}

const char* GetString(const String* str)
{
	/*
	char* result = (char*)malloc(strlen(str->str) * sizeof(char));
	return result;
	*/
	if (!str)
	{
		g_lastError = 2;
		return;
	}
	if (!(str->str))
	{
		g_lastError = 3;
		return;
	}
	return str->str;
}

size_t GetStringLength(const String* str)
{
	if (!str)
	{
		g_lastError = 2;
		return;
	}
	if (!(str->str))
	{
		g_lastError = 3;
		return;
	}
	return strlen(str->str);
}

BOOL IsEmpty(const String* str)
{
	if (!str)
	{
		g_lastError = 2;
		return;
	}
	if (!(str->str))
	{
		g_lastError = 3;
		return;
	}
	return 1 - (str->str && GetStringLength(str) != 0);
}

int CompareString(const String* str1, const String* str2)
{
	if (!str1|| !str2)
	{
		g_lastError = 2;
		return;
	}
	if (!(str1->str)|| !(str2->str))
	{
		g_lastError = 3;
		return;
	}
	return strcmp(str1->str, str2->str);
}

int CopyString(String* dst, const String* src)
{
	/*
	free(dst->str);
	dst->str = (char*)malloc(strlen(src->str) * sizeof(char));
	strcpy_s((dst->str), strlen(src->str) + 1, src->str);
	*/
	int result = CopyCString(dst, src->str);
	return result;
}

int CopyCString(String* dst, const char* src)
{
	free(dst->str);
	dst->str = (char*)malloc(strlen(src) * sizeof(char));
	strcpy_s((dst->str), strlen(src) + 1, src);
	return 0;
}

