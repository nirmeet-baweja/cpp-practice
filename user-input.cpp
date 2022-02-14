/**
 * @file user-input.cpp
 * @author nirmeet baweja
 * @brief User interface contains two types of user input controls: TextInput,
 * which accepts all characters and NumericInput, which accepts only digits
 *
 * Implement the following methods:
 * add on class TextInput - adds the given character to the current value
 * getValue on class TextInput - returns the current value add on class
 * NumericInput - overrides the base class method so that each non-numeric
 * character is ignored
 *
 * For example, the following code should output "10":
 * TextInput* input = new NumericInput();
 * input->add('1');
 * input->add('a');
 * input->add('0');
 * std::cout << input->getValue();
 *
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

class TextInput
{
private:
  std::string input_variable;

public:
  TextInput()
  {
    input_variable = "";
  }

  virtual void add(char c)
  {
    this->input_variable.push_back(c);
  }

  std::string getValue()
  {
    return input_variable;
  }
};

class NumericInput : public TextInput
{
public:
  void add(char) override;
};

void NumericInput::add(char c)
{
  if (c >= '0' && c <= '9')
  {
    TextInput::add(c);
  }
}

#ifndef RunTests
int main()
{
  TextInput *input = new NumericInput();
  input->add('1');
  input->add('a');
  input->add('0');
  std::cout << input->getValue();
}
#endif