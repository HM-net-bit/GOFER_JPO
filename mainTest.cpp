#include <iostream>
#include "ProductList.hpp"
using std::string,std::cin,std::cout,std::endl;

int main() {
    HM::ProductList productList;
    productList.displayProducts();
    productList.addOrUpdateProduct("Mleko",10);
    productList.addOrUpdateProduct("Kawa",1);
    productList.addOrUpdateProduct("",1);
    productList.addOrUpdateProduct("Czekolada",0);
    productList.addOrUpdateProduct("Mleko",30);
    productList.displayProducts();
    productList.saveToFile("");
    productList.saveToFile("Lista Zakupów");
    /*
        The product list is empty.
        Error: Product name cannot be empty.
        Error: Quantity cannot be less than 0.
        Product List:
        Product: Mleko, Quantity: 40
        Product: Kawa, Quantity: 1
        Error: Filename cannot be empty.
        Data saved to Lista Zakupów.txt
    */
}