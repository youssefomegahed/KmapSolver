
#ifndef K_map_hpp
#define K_map_hpp
#include<iostream>
using namespace std;

class Kmap
{
private:
    bool search(int *arr, int n, int key);
    int variables, size;
    bool s;
    int *minterm;
    char choice;
    void generateExpression_3v(int *arr, int n);
    void generateExpression_2v(int *arr, int n);
public:
    Kmap();
    void generate_booleanex_2();
    void generate_booleanex_3();
    void set_variables(int v);
    
};

#endif /* K_map_hpp */
