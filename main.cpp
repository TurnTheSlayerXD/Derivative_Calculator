#include "Functions.h"
void foo(int argc, char* argv[]){
    string expr;
    while(getline(cin,expr)) {
        Derivative A(expr);
        cout << A.get_result() << "\n";
    }
}
int main(int argc, char*argv[]) {
    foo(argc, argv);
    return 0;
}
