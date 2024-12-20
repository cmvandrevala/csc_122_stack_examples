#include <iostream>
#include <vector>
#include <string>

#include "my_stack.hpp"

using namespace std;

int postfix_calculator(vector<string> math_expression)
{
  MyStack<int> stack;

  for (auto i = math_expression.begin(); i < math_expression.end(); i++)
  {
    if (*i == "+")
    {
      int sum = stack.pop() + stack.pop();
      stack.push(sum);
    }
    else if (*i == "-")
    {
      int difference = stack.pop() - stack.pop();
      stack.push(difference);
    }
    else if (*i == "*")
    {
      int product = stack.pop() * stack.pop();
      stack.push(product);
    }
    else if (*i == "/")
    {
      int division = stack.pop() / stack.pop();
      stack.push(division);
    }
    else
    {
      stack.push(stoi(*i));
    }
  }

  return stack.pop();
}

int main()
{
  vector<string> math_one = {"3", "4", "+", "2", "3", "+", "+"};
  cout << postfix_calculator(math_one) << endl;

  vector<string> math_two = {"3", "4", "+", "2", "*", "28", "/"};
  cout << postfix_calculator(math_two) << endl;
}
