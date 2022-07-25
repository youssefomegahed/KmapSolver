//
//  K-map.cpp
//  DD project 1
//
//  Created by Yasmina Halbouny on 27/03/2021.
//

#include "K-map.hpp"

Kmap::Kmap()
{
    variables=0;
    s=true;
}
void Kmap::generate_booleanex_3()
{
    int i=0;
size=8;
minterm=new int[size];
for(int i=0; i<size; i++)
{
  *(minterm+i)=-1;
}
while (s!=false &&i<=8)
{
cout<<"Enter minterm "<<i+1<<": ";
cin>>*(minterm+i);

while((*(minterm+i))>7 || (*(minterm+i))<0)
  {
    cout<<"Invalid input, try again: ";
    cin >> *(minterm+i);
  }
i++;
cout<<"Add another minterm (y/n): ";
cin>>choice;
    cout<<endl;
if (choice=='y'|| choice=='Y')
s=true;
else s=false;
}
    cout<<"Your minterms are: ";
    for(int i=0; i<size; i++)
    {
        if(*(minterm+i)!=-1)
            cout<<*(minterm+i)<<",";
    }
    cout<<endl<<endl;
int kmap[8] = {0,0,0,0,0,0,0,0};

for(int j = 0; j <size; j++)
{
  if(*(minterm+j) == 0)
  {
    kmap[0] = 1;
  }
  if(*(minterm+j) == 1)
    kmap[1] = 1;

  if(*(minterm+j) == 2)
    kmap[3] = 1;

  if(*(minterm+j)==3)
    kmap[2] = 1;

  if(*(minterm+j)==4)
    kmap[4] = 1;
  
  if(*(minterm+j)==5)
    kmap[5] = 1;

  if(*(minterm+j)==6)
    kmap[7] = 1;
  
  if(*(minterm+j)==7)
    kmap[6] = 1;
}
cout<<"K-map:"<<endl;
for(int j = 0; j <size; j++)
{
  cout<<kmap[j]<<" ";
  if (j==3)
  cout<<endl;
}
cout<<endl;
    cout<<endl;
cout<<"Boolean Expression: "<<endl<<"F  =  ";
generateExpression_3v(minterm,size);
    cout<<"0"<<endl;
}
void Kmap::generate_booleanex_2()
{
    int i=0;
    size=4;
    minterm=new int[size];
    for(int i=0; i<size; i++)
    {
      *(minterm+i)=-1;
    }
    while(s != false && i<4)
    {
      cout<<"Enter minterm "<<i+1<<": ";
      cin >> *(minterm+i);

      while(*(minterm+i) > 3 || *(minterm+i) < 0)
      {
        cout<<"Invalid input, try again: ";
        cin >> *(minterm+i);
      }
      cout<<"Add another minterm (y/n): ";
      cin >> choice;
        cout<<endl;
      if (choice=='y'|| choice=='Y')
      s=true;
      else s=false;
      i++;
    }
    
    cout<<"Your minterms are: ";
    for(int i=0; i<size; i++)
    {
        if(*(minterm+i)!=-1)
            cout<<*(minterm+i)<<",";
    }
    cout<<endl<<endl;
    int kmap[4] = {0,0,0,0};
    
    for(int j = 0; j <4; j++)
    {
      if(*(minterm+j) == 0)
        kmap[0] = 1;
      
      if(*(minterm+j) == 1)
        kmap[2] = 1;

      if(*(minterm+j) == 2)
        kmap[1] = 1;

      if(*(minterm+j)==3)
        kmap[3] = 1;
      
    }
    cout<<"K-map:"<<endl;
    
    for(int j = 0; j < 4; j++)
    {
      cout<<kmap[j]<<" ";
      if (j==1)
      cout<<endl;
    }
    cout<<endl;
    cout<<"Boolean expression: "<<endl<<"F = ";
    generateExpression_2v(minterm,2);
    cout<<"0"<<endl;

}
void Kmap::set_variables(int v)
{
    variables=v;
}
bool Kmap::search(int *arr, int n, int key)
{
  for(int i = 0; i < n; i++)
    if(*(arr+i)==key)
      return true;

  return false;
}
void Kmap::generateExpression_3v(int *arr, int n)
{
  if(search(arr, n, 0) && search(arr, n, 1) && search(arr,n,2)&&search(arr,n,3))
    cout<<"A' + ";

  if(search(arr, n, 0) && search(arr, n, 1) && search(arr,n,4)&&search(arr,n,5))
      cout<<"B' + ";

if(search(arr, n, 4) && search(arr, n, 5) && search(arr,n,6)&&search(arr,n,7))
      cout<<"A + ";

if(search(arr, n, 3) && search(arr, n, 2) && search(arr,n,7)&&search(arr,n,6))
    cout<<"B + ";

  if(search(arr, n, 1) && search(arr, n, 3) && search(arr,n,5)&&search(arr,n,7))
      cout<<"C + ";

  if(search(arr, n, 0) && search(arr, n, 4) && search(arr,n,2)&&search(arr,n,6))
      cout<<"C'+ ";

  if(search(arr, n, 0) && search(arr,n,1) && (search(arr,n,2)==false|| search(arr,n,3)==false) && (search(arr,n,4)==false||search(arr,n,5)==false))
      cout<<"A'B' + ";

  if(search(arr, n, 2) && search(arr,n,3) && (search(arr,n,1)==false|| search(arr,n,0)==false) && (search(arr,n,6)==false||search(arr,n,7)==false))
      cout<<"A'B + ";

  if(search(arr, n, 4) && search(arr,n,5) && (search(arr,n,0)==false|| search(arr,n,1)==false) && (search(arr,n,6)==false||search(arr,n,7)==false))
      cout<<"AB' + ";

  if(search(arr, n, 6) && search(arr,n,7) && (search(arr,n,4)==false|| search(arr,n,5)==false) && (search(arr,n,2)==false||search(arr,n,3)==false))
      cout<<"AB + ";

  if(search(arr, n, 1) && search(arr,n,3) && (search(arr,n,0)==false|| search(arr,n,2)==false) && (search(arr,n,5)==false||search(arr,n,7)==false))
      cout<<"A'C + ";
  
  if(search(arr, n, 5) && search(arr,n,7) && (search(arr,n,4)==false|| search(arr,n,6)==false) && (search(arr,n,1)==false||search(arr,n,3)==false))
      cout<<"AC + ";

  if(search(arr, n, 0) && search(arr,n,4) && (search(arr,n,1)==false|| search(arr,n,5)==false) && (search(arr,n,2)==false||search(arr,n,6)==false))
      cout<<"B'C'+ ";

  if(search(arr, n, 1) && search(arr,n,5) && (search(arr,n,0)==false|| search(arr,n,4)==false) && (search(arr,n,3)==false||search(arr,n,7)==false))
      cout<<"B'C + ";

   if(search(arr, n, 3) && search(arr,n,7) && (search(arr,n,1)==false|| search(arr,n,5)==false) && (search(arr,n,2)==false||search(arr,n,6)==false))
       cout<<"BC + ";

  if(search(arr, n, 2) && search(arr,n,6) && (search(arr,n,3)==false|| search(arr,n,7)==false) && (search(arr,n,0)==false||search(arr,n,4)==false))
      cout<<"BC' + ";

  if(search(arr, n, 0) && search(arr,n,2) && (search(arr,n,1)==false|| search(arr,n,3)==false) && (search(arr,n,4)==false||search(arr,n,6)==false))
      cout<<"A'C' + ";

  if(search(arr, n, 4) && search(arr,n,6) && (search(arr,n,5)==false|| search(arr,n,7)==false) && (search(arr,n,0)==false||search(arr,n,2)==false))
      cout<<"AC' + ";

  if(search(arr, n, 0) && search(arr,n,1)==false && (search(arr,n,4)==false && search(arr,n,2)==false))
      cout<<"A'B'C' +";

  if(search(arr, n, 1) && search(arr,n,0)==false && (search(arr,n,5)==false && search(arr,n,3)==false))
      cout<<"A'B'C + ";

  if(search(arr, n, 3) && search(arr,n,1)==false && (search(arr,n,2)==false && search(arr,n,7)==false))
      cout<<"A'BC + ";

  if(search(arr, n, 2) && search(arr,n,0)==false && (search(arr,n,3)==false && search(arr,n,6)==false))
      cout<<"A'BC' + ";

  if(search(arr, n, 4) && search(arr,n,0)==false && (search(arr,n,5)==false && search(arr,n,6)==false))
      cout<<"AB'C' + ";

  if(search(arr, n, 5) && search(arr,n,4)==false && (search(arr,n,7)==false && search(arr,n,1)==false))
      cout<<"AB'C + ";

  if(search(arr, n, 7) && search(arr,n,5)==false && (search(arr,n,6)==false && search(arr,n,3)==false))
      cout<<"ABC + ";

  if(search(arr, n, 6) && search(arr,n,4)==false && (search(arr,n,7)==false && search(arr,n,2)==false))
      cout<<"ABC' + ";

}
void Kmap::generateExpression_2v(int *arr, int n)
{
  if(search(arr, n, 0) && search(arr, n, 1))
      cout<<"A'+ ";
    
  if(search(arr, n, 2) && search(arr, n, 3))
      cout<<"A + ";
    
  if(search(arr, n, 1) && search(arr, n, 3))
      cout<<"B + ";
    
  if(search(arr, n, 0) && search(arr, n, 2))
      cout<<"B' + ";
    
  if(search(arr, n, 0) && search(arr,n,1)==false && (search(arr,n,2)==false))
      cout<<"A'B' + ";
    
  if(search(arr, n, 1) && search(arr,n,3)==false && (search(arr,n,0)==false))
      cout<<"A'B + ";
    
 if(search(arr, n, 2) && search(arr,n,3)==false && (search(arr,n,0)==false))
     cout<<"AB' + ";
    
  if(search(arr, n, 3) && search(arr,n,1)==false && (search(arr,n,2)==false))
      cout<<"AB + ";
}
