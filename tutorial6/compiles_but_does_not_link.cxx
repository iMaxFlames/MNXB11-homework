#include <iostream>
// Promising the compiler that void never_defined() will be defined either in
// another file or in a library
void never_defined();
int main()
{
    // Trying to use the function without a definition
    never_defined();
    return 0;
}
