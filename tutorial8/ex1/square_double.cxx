#include <iostream>
#include <vector>

void square(double& number_ref) {
    number_ref = number_ref * number_ref;
}

void square(double* number_ptr) {
    const double content {*number_ptr};
    *number_ptr = content * content;
}

int main() {
    double number {2.};
    double& number_ref {number};
    double* number_ptr {&number};
    square(number_ref);
    square(number_ptr);
}