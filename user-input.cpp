#include <iostream>
#include <string>

class TextInput
{
private:
  std::string input_variable;

public:
  TextInput()
  {
    // std::cout << "text const\n";
    input_variable = "";
  }

  virtual void add(char c)
  {
    // std::cout << "text add\n";
    this->input_variable.push_back(c);
  }

  std::string getValue()
  {
    // std::cout << "input variable : " << input_variable << '\n';
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
  // std::cout << "num add\n";
  if (c >= '0' && c <= '9')
  {
    // std::cout << "c: " << c << '\n';
    TextInput::add(c);
  }
}

#ifndef RunTests
int main()
{
  // std::cout << "main\n";
  TextInput *input = new NumericInput();
  input->add('1');
  input->add('a');
  input->add('0');
  std::cout << input->getValue();
}
#endif