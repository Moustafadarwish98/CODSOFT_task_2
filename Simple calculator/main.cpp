#include <iostream>
#include <fstream>
using namespace std;

bool use_result = false;

void printing (string symbol, int number)
{
     for (int i = 0; i<=number; i++)
     {
          cout<< symbol;
     }
}

float calculate ( float num1, char op, float num2)
{

          switch (op) {
          case '+': return num1 + num2;
          break;
          case '-': return num1 - num2;
          break;
          case '*': return num1 * num2;
          break;
          case '/':
               if (num2 == 0)
               {
                    cout<<"-----> MathError cannot divide by 0.\n";
               }
               else
               {
                    return num1/num2;
               }
          break;

}}
int main()
{
     printing("-", 20);
     cout<< "Calculator on. ";
     printing("-", 20);
     cout << endl<<endl;
     bool exit = false;
     while(! exit)
     {
     float first_number, second_number, result;
     char operation;
     cout << "----->Enter first number: "<<endl;
     cin>>first_number;
     cout<<endl;
     label:
     bool invalid = true;
     while(invalid)
     {
          cout<<"----->Enter operation: ('+', '-', '*', '/')"<<endl;
          cin >> operation;
          cout<<endl;
          if (operation == '+' || operation == '-' || operation == '*' || operation == '/' )
          {
               invalid = false;
          }
          else
          {
               printing("-", 20);
               cout<<"Invalid. Please enter one of the available operations.";
               printing("-", 20);
               cout<<endl<<endl;
          }

     }
          if (use_result)
          {
               ifstream file("results.txt");
               file >> first_number;
          }

               result = first_number;

     cout << "----->Enter second number: "<<endl;
     cin>> second_number;
     cout<<endl;
     result = calculate(result, operation, second_number);
     ofstream file("results.txt");
     file<<result;
     printing("-", 10);
     if (operation == '/' && second_number == 0)
     {
          cout<<"Operation ignored.";
          cout<<endl<<endl;
     }
     else
     {
          cout<<"> Calculation: "<<first_number<<" "<<operation<<" "<<second_number<<" = "<<result<<endl<<endl;
     }
     int check ;
     cout<<"Do you to perform another calculation? (Yes(type 1), No (type 0))."<<endl;
     cin>> check;
     if ( !check)
     {
          exit = true;
          system("cls");
          printing("-", 20);
          cout<<"Calculator off.";
          printing("-", 20);
     }
     else
     {
     cout<<"Do you want to use previous result? (Yes(type 1), No (type 0))."<<endl;
     cin>>check;
     if (check)
     {
          use_result = true;
          goto label;
     }
     }
     }
return 0;}
