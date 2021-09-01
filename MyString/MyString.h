/*****************************************************************//**
 * \file   String.h
 * \brief
 *
 * \author ipewz
 * \date   September 2021
 *********************************************************************/
#pragma once
#include <stdio.h>
#include <string.h>
typedef struct String_t
{
	char* str;
} String;

typedef _Bool BOOL;

/**
 * @brief Print the last error.
 */
void getLastLinkedListError(void);


/**
 * @brief Createing String for the source.
 *
 * @param source
 * @return String
 */
String* CreateString(const char* source);

/**
 * @brief free string memory.
 *
 * @param str
 * @return _Bool
 */
BOOL DeleteString(String* str);

/**
 * @brief return *char.
 *
 * @param *String str.
 *
 * @return *char.
 */
const char* GetString(const String* str);

/**
 * @brief Give the string length.
 * @param String* str.
 * @return unsigned long.
 */
size_t GetStringLength(const String* str);

/**
 * @brief testing if the String empty.
 * @param String* str.
 * @return _Bool.
 */
BOOL IsEmpty(const String* str);

/**
 * @brief Compare string.
 *
 * @param
 * @param
 *
 * @return int
 * 0	if strings are equal
 * >0	if the first non-matching character in str1 is greater (in ASCII) than that of str2.
 * <0	if the first non-matching character in str1 is lower (in ASCII) than that of str2.
 */
int CompareString(const String* str1, const String* str2); // see strcmp()

/**
 * @brief Copy String to String.
 *
 * @param String* dst.
 * @param String* src.
 *
 * @return int.
 */
int CopyString(String* dst, const String* src);

/**
 * @brief Copy *char to String.
 *
 * @param String* dst.
 * @param String* src.
 *
 * @return int.
 */
int CopyCString(String* dst, const char* src);



/*
//Bonus:
AppendString(String* dst, const String* src); // see strcat()
AppendCString(String* dst, const char* src);
		 */