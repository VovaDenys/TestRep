
#include <iostream>
using namespace std;
 
int main()
{
    int var = 123; // инициализация переменной var числом 123
    int *ptrvar = &var; // указатель на переменную var
    int **ptr_ptrvar = &ptrvar; // указатель на указатель на переменную var
    int ***ptr_ptr_ptrvar = &ptr_ptrvar;
    
    int var1 = 123; // ????????????? ?????????? var1 ?????? 123
    int var2 = 99; // ????????????? ?????????? var2 ?????? 99
    int *ptrvar1 = &var1; // ????????? ?? ?????????? var1    
    int *ptrvar2 = &var2;; // ????????? ?? ?????????? var2
 
    cout << "var1    = " << var1 << endl;
    cout << "var2    = " << var2 << endl;
    cout << "&var1 = " << &var1  << " ptrvar1 = " << ptrvar1 << " ptrvar1 = " << &ptrvar1 << endl;
    cout << "&var2 = " << &var2  << " ptrvar2 = " << ptrvar2 << " ptrvar2 = " << &ptrvar2 <<endl;
    
    
    
    cout << " var\t\t= " << var << endl;
    cout << " *ptrvar\t= " << *ptrvar << endl;
    cout << " **ptr_ptrvar   = " << **ptr_ptrvar << endl; // два раза разименовываем указатель, так как он второго порядка
    cout << " ***ptr_ptrvar  = " << ***ptr_ptr_ptrvar << endl; // указатель третьего порядка
    cout << "\n ***ptr_ptr_ptrvar -> **ptr_ptrvar -> *ptrvar ->      var -> "<< var << endl;
    cout << "\t  " << &ptr_ptr_ptrvar<< " -> " << "    " << &ptr_ptrvar << " ->" << &ptrvar << " -> " << &var << " -> " << var << endl;
    system("pause");
    return 0;
}
