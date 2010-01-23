/*
 *  Parser.h
 *  test
 *
 *  Created by Martin Röbert on 18.01.10.
 *  Copyright 2010 Martin Röbert. All rights reserved.
 *
 */
#include <map>

using namespace std;

class Parser {
public:
	const static int NAN;
	const static int NUMBER;
	const static int OPER;
	const static int FACULTY;
	string validate(string validationForm);
	
private:
	string validForm;
	char step;
	char errorChar;
	
	map<char,int> validChars;
	map<char,int>::iterator validCharsIterator;
	int checkValidChar(char isValid);
}