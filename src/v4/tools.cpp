#include<iostream>
#include<sstream>
#include<string>
#include<cctype>
#include<cmath>
using namespace std;

enum {PLUS='+',MINUS='-',MUL='*',DIV='/'};

double Value_Of_Num(const string &Expr)

{
   istringstream is(Expr);
   double value=0.0;
   is >> value;
   return value;
}

double Value_Of_Expr(const string &Expr)

{
  int i=0,p=0,pos_mul=0,pos_div=0;

   if(Expr.at(0)=='('&&Expr.at(Expr.length()-1)==')')
   {
       for(i=0;i < Expr.length();i++)
           {

        if(Expr.at(i)=='(') p++;
           else if(Expr.at(i)==')') p--;
           if(p==0) break;

           }

       if(i==Expr.length()-1)
       return Value_Of_Expr(Expr.substr(1,Expr.length()-2));
   }

   for(i=0;i < Expr.length();i++)
   {
       if(Expr.at(i)=='(') p++;
                else if(Expr.at(i)==')') p--;
                else if(p==0&&ispunct(Expr.at(i)))
                {

                    switch(Expr.at(i))
                        {
                                case PLUS:
                                return Value_Of_Expr(Expr.substr(0,i))+Value_Of_Expr(Expr.substr(i+1,Expr.length()-i-1));
                                case MINUS:
                                return Value_Of_Expr(Expr.substr(0,i))-Value_Of_Expr(Expr.substr(i+1,Expr.length()-i-1));
                                case MUL: pos_mul=i; break;
                                case DIV: pos_div=i; break;

                        }
                }
   }

  if(pos_mul)
  return Value_Of_Expr(Expr.substr(0,pos_mul))*Value_Of_Expr(Expr.substr(pos_mul+1,Expr.length()-pos_mul-1));

  if(pos_div)
  return Value_Of_Expr(Expr.substr(0,pos_div))/Value_Of_Expr(Expr.substr(pos_div+1,Expr.length()-pos_div-1));

  return Value_Of_Num(Expr);
}


// several important validation checks on the input
bool Check(string input_string)
{

   for (int r = 0; r < input_string.length(); r++)
   {
       if((input_string[r]=='+')||(input_string[r]=='-'))
       {
           if((input_string[r+1]=='+')||(input_string[r+1]=='-'))
           {
               return false;
           }
       }
   }
   string array="0123456789+-*/()";
   int count=0;
   for (int s=0; s < input_string.length(); s++)
   {
       for(int z=0; z < array.length(); z++)
       {
           if(input_string[s]==array[z])
           {
              count++;
           }
       }
   }
   if (count == input_string.length())
   {
     return true;
   }
   else
   {
     return false;
   }
}

