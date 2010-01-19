
#include <bacalc_processor.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <tools.cpp>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int factorial (int num) {
    int result = 1;
    for (int i = 1; i <= num; ++i) {
        result=result*=i;
    }
    return result;
}


bool isNumber(const char &input) {
    int ascii = (int) input;
    // ASCII Mapping of numbers (0-9)
    // 0 -> 48
    // 9 -> 57
    bool result;
    if ((ascii <= 57) && (ascii >= 48)) {
        result = true;
    } else {
        result = false;
    }

    return result;
}

string calc_multiplikation_term(string term) {
    char current_char;
    double result;

    string current_number;
    double current_numberd;

    char current_operator;

    bool isinit = true;

    ostringstream result_stream;

    for (int i=0; i <= term.length(); i++) {
        current_char = term[i];

        if (isNumber(current_char)) {
            current_number += current_char;
        } else {
            current_numberd = strtod(current_number.c_str(), 0);
            current_number = "";
            switch (current_operator) {
            case '*':
                result = result * current_numberd;
                break;
            case '/':
                result = result / current_numberd;
                break;
            default:
                if (isinit) {
                    result = current_numberd;
                    isinit = false;
                } else {
                    result_stream << result;
                    return result_stream.str();
                }
                break;
            }
            current_operator = current_char;
        }
    }
}

Processor::Processor() {

}

Processor::~Processor() {

}

char* Processor::process(const char* input) {

    double bla = Value_Of_Expr(input);
    cout << "BLA: " << bla << endl;

    //char first_number[1024];
    //int  first_number_pointer = 0;

    string first_number;

    string current_multiplikation_term;
    string current_addition_term;

    string transformed_task;
//    char transformed_task[1024];
//    int  transformed_task_pointer = 0;

    char current_char;
    char current_operator;
    char last_operator;

    bool char_is_number;

    bool is_adition = false;
    bool is_multiplikation = false;

    bool last_adition = false;
    bool last_mutliplikation = false;

    // this var will be true if a multiplikation sign is detected ('*' or '/')
    // the second number after the term a*b will be calculated with the first one
    // and the result will be inserted into the transformed_task
    bool multiplikation_mode = false;

    for (int i = 0; i <= sizeof input; i++) {
        current_char = input[i];

        char_is_number = isNumber(current_char);
        cout << "[" << current_char << "] isNumber: " << char_is_number << endl;

        if (char_is_number) {
            first_number += current_char;
            //first_number[first_number_pointer] = current_char;
            //first_number_pointer++;
        } else {
            // current char must be an operator

            ostringstream o;

            current_operator = current_char;

            // check which base operation is currently requested
            switch (current_operator) {
            case '+':
                is_adition = true;
                break;
            case '-':
                is_adition = true;
                break;
            case '*':
                is_multiplikation = true;
                break;
            case '/':
                is_multiplikation = true;
                break;
            case '!':
                // This transforms only the current number. The factorial will
                // be calculated.
                int result = factorial(atoi(first_number.c_str()));
                cout << result << endl;
                o << result;
                first_number = o.str();
                break;
            }

            // if it is an addition add the current number + the current operator
            // to the adition buffer
            if (is_adition) {
                // write the currend number into the transformed buffer
                current_addition_term += first_number + current_operator;
            }

            if (is_multiplikation) {

            }

//
//
//            if (is_adition) {
//                // write the currend number into the transformed buffer
//                current_addition_term += first_number;
//                current_addition_term += current_char;
//            } else if (is_multiplikation) {
//                current_multiplikation_term += first_number;
//                current_multiplikation_term += current_char;
//            }


//            switch (last_operator) {
//            case '*':
//                current_multiplikation_term += first_number + current_char;
//            }
//
//            if (multiplikation_mode) {
//                current_addition_term += current_char;
//                transformed_task += calc_multiplikation_term(current_multiplikation_term);
//            } else {

            is_adition = false;
            is_multiplikation = false;
            first_number = "";

            // this expression must be executed after the switch-case block
            // if a operator is detected the last one is the point of interrest.
            current_operator = current_char;
        }

        cout << "[" << current_char << "] current_multiplikation_term: '" << current_multiplikation_term << "'" << endl;
        cout << "[" << current_char << "] current_addition_term: '" << current_addition_term << "'" << endl;
        cout << "[" << current_char << "] first_number: '" << first_number << "'" << endl;

        //printf("first_number: %s", first_number);
    }

    //printf(transformed_task);
}
