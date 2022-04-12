# cpp-practice

Collection of small programs written to practice C++ programming skills

## Command to compile a programName.cpp file
Make sure you are in the same directory as the __programName.cpp__ file and in the terminal type:

```g++ -std=c++11 -O2 -Wall programName.cpp -o programName.out```

### Understanding different terms in above command:

- ```g++```: tells the computer the given command is for g++ compiler.
- ```-std=c++11```: the compiler follows C++11 standard, you can set it to -std = c++14 or -std=c++17 based on what you want to use.
- ```-O2```: Optimizes the code
- ```-Wall```: shows warnings about possible errors
- ```programName.cpp```: refers to the c++ file to be compiled
- ```-o programName.out```: creates a executable file of the suggested name( here programName.exe).

__Note:__ The name of cpp file and executable file need not be same.
