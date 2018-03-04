#README: Find the function declaration#

##function_internal.cpp##
> g++ function_internal.cpp -o function_internal
> ./function_internal
> The inputs are hardcoded. You just have to run. As mentioned in example of the question, the pattern is searched and outputs the respective line number. KMP Algorithm is used for the purpose.

##function_files.cpp##
> g++ function_files.cpp -o function_files
> ./function_files func1 test1.cpp
> "func1" is argv[1], "test1.cpp" argv[2] i.e., inputs that we require.
> "func1" declaration is searched in sourcefile "test1.cpp" and returns line number if present.
