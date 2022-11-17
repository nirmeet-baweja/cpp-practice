#include<iostream>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<limits.h>

using namespace std;

int main(int argc, char *argv[])
{
  // the argument is emtpy
  if(argc < 2 || strlen(argv[1]) == 0) {
    cout << "\nEnter atleast one argument." << endl;
    return 1;
  }

  cout << "\nThe argument entered is : (" << argv[1] << ")"<< endl;

  // not 'int errno', because the '#include<errno.h>' already defined it
  errno = 0;
  // the pointer to check where the strtol stopped.
  char *p;
  // function to convert string to long
  long arg = strtol(argv[1], &p, 10);
  // if *p != '\0' that means non-digits were present in argv[1]
  if(*p != '\0' || errno != 0) {
    cout << "\nError occurred while converting argument to type int." << endl;
    return 1;
  }

  if(arg < INT_MIN || arg > INT_MAX) {
    cout << "\nOut of bounds error." << endl;
    return 1;
  }

  int arg_int = arg;

  cout << "\n The argument entered was: " << arg_int << endl;
  return 0;
}