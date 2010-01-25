/*
 * Parser.cpp
 * test
 *
 * Created by Martin Roebert on 18.01.10.
 * Copyright 2010 Martin Roebert. All rights reserved.
 *
 */

#include <iostream>
#include <map>

#define CSI 0x1b

using namespace std;

class Parser {

public:
	const static int NAN = 0;
	const static int NUMBER = 1;
	const static int OPER = 2;
	const static int FACULTY = 3;

	string validate(string validationForm) {

		printf("Parser->validate('%s')\n", validationForm.c_str());

		// loop var
		int i;
		for (i = 0; i < validationForm.length(); i++) {
			// stores .at(i) - if the .append- function is called with &validationForm.at(i)
			// the complete validationForm is appended
			step = validationForm.at(i);

			if (i == 0) {
				// only numbers are allowed at the first position of the formula
				if (checkValidChar(step) == NUMBER) {
					printf("\033[22;32mConstruct formula: %s", &step);
					validForm += step;
				} else {
					printf(
							"\033[22;31m First sign has to be a number but is %s- deleting this sign;\n",
							&step);
				}

			} else {
				// numbers are allowed at every position
				if (checkValidChar(step) == NUMBER) {
					printf("\033[22;32m%s", &step);
					validForm += step;
				} else if (checkValidChar(step) == OPER) {
					// if oper is not at the end of the formula
					if (i != validationForm.length() - 1) {
						// allow numbers
						if (checkValidChar(validationForm.at(i - 1)) == NUMBER) {
							printf("\033[22;32m%s", &step);
							validForm += step;
							//validForm.append(&step);
						}
						// current position is operator and not the last sign in formula;
						// and now previous is a faculty or NAN
						else if (checkValidChar(validationForm.at(i - 1))
								== FACULTY || checkValidChar(validationForm.at(
								i - 1)) == NAN) {
							// set new loop var to parent loop var
							int j = i;
							while (j != 0) {
								// same procedure as last year... numbers are allowed and
								if (checkValidChar(validationForm.at(j))
										== NUMBER) {
									printf("\033[22;32m%s", &step);
									validForm += step;
									// break lop
									j = 0;
								}
								// check if child-loop-position is an operator
								else if (checkValidChar(validationForm.at(j))
										== OPER) {
									// if previous is a non valid sign next loop
									if (checkValidChar(validationForm.at(j - 1))
											== NAN || checkValidChar(
											validationForm.at(j - 1))
											== FACULTY) {
										j--;
									}
									// if not we are finished and can break the loop
									else {
										j = 0;
									}
								}
								// if it is not a number or a operator: decrement counter
								else {
									j--;
								}
							}
						}
					}
				}
			}
		}

		// clean up last opererator if possible.
		// this must happen due to the fact, that the above algorithm cant recognize
		// more than 1 operator at the end of the formula
		if (checkValidChar(validForm.at(validForm.length() - 1)) == OPER) {
			errorChar = validForm.at(validForm.length() - 1);
			printf("\033[22;31m \nRemove last operator %s \n", &errorChar);
			validForm.erase(validForm.length() - 1);
		}

		// append faculty
		if (checkValidChar(validationForm.at(validationForm.length() - 1))
				== FACULTY) {
			printf(
					"\033[22;34m \nYou wanted to faculty the formula - Have to add !\n");
			validForm += "!";
			//validForm.append("!");
		}
		return validForm;
	}

	string validForm;
	char step;
	char errorChar;

	map<char, int> validChars;
	map<char, int>::iterator validCharsIterator;

	/*
	 * return 1 numbers
	 * return 2 operators
	 * return 3 faculty
	 * return 0 non valid
	 */
	int checkValidChar(char isValid) {
		//int Parser::checkValidChar(char isValid){

		validChars['1'] = NUMBER;
		validChars['2'] = NUMBER;
		validChars['3'] = NUMBER;
		validChars['4'] = NUMBER;
		validChars['5'] = NUMBER;
		validChars['6'] = NUMBER;
		validChars['7'] = NUMBER;
		validChars['8'] = NUMBER;
		validChars['9'] = NUMBER;
		validChars['0'] = NUMBER;
		validChars['+'] = OPER;
		validChars['-'] = OPER;
		validChars['/'] = OPER;
		validChars['*'] = OPER;
		validChars['!'] = FACULTY;

		// the iterator returned by .find()
		validCharsIterator = validChars.find(isValid);
		// if element wasnt found, the end of the map is returned
		if (validCharsIterator != validChars.end()) {
			// return the number -> constant
			return validCharsIterator->second;
		} else {
			// nothing valid found
			return NAN;
		}
	}
};
