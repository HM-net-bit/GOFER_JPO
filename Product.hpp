#include <iostream>
#include <vector>
using std::cin,std::cout,std::endl,std::vector,std::string;

class Product{
protected:
    string m_name;
    double m_price;
public:
    Product(){};
    Product(string name, double price):m_name(name),m_price(price){};
    virtual void displayProduct()=0;
    ~Product(){};
};