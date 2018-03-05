# README: Find the function declaration

## function_internal.cpp
1. g++ function_internal.cpp -o function_internal
2. ./function_internal
3. The inputs are hardcoded. You just have to run. As mentioned in example of the question, the pattern is searched and outputs the respective line number. KMP Algorithm is used for the purpose.

## function_files.cpp
1. g++ function_files.cpp -o function_files
2. ./function_files func1 test1.cpp
3. "func1" is argv[1], "test1.cpp" argv[2] i.e., inputs that we require.
4. "func1" declaration is searched in sourcefile "test1.cpp" and returns line number if present.
