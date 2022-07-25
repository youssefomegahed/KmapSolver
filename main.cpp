#include "K-map.hpp"

int main()
{
    int n;
    Kmap K;
    cout<<"Boolean expression generator"<<endl<<endl<<"*Note:this program only supports functions with two or three input variables."<<endl<<endl<<"Please enter the number of inputs in your function: ";
    cin>>n;
    while(n<2 || n>3)
    {
      cout<<"Invalid number of variables, please try again"<<endl;
      cin>> n;
      cout<<endl;
    }
    K.set_variables(n);
    cout<<endl;
    if(n==2)
        K.generate_booleanex_2();
    if  (n==3)
        K.generate_booleanex_3();




return 0;
}
