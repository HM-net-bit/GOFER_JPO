#include <iostream>
#include <vector>
#include "Seasoning.hpp"
using std::cin,std::cout,std::endl,std::vector,std::string;

int main(){
    Seasoning s1("Sugar",4.0);
    s1.displayProduct();
    cout<<"Cena: "<<s1.getPriceSeas()<<endl;
    cout<<s1.costSeas()<<endl;
}
