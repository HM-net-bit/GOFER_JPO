#include <iostream>
#include <vector>
#include <string>
#include "ProductList.hpp"
using std::cout, std::endl, std::vector,std::string;

int main(){
    HM::ProductList p1;
    p1.addProduct("Mleko");
    p1.addProduct("Woda");
    p1.displayProducts();

    /*
        List of products:
        - Mleko
        - Woda
    */
}