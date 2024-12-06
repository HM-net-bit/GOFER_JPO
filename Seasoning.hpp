#include <iostream>
#include <vector>
#include "Product.hpp"
using std::cin,std::cout,std::endl,std::vector,std::string;

class Seasoning:public Product{
private:
    string m_nameSeas;
    double m_priceSeas;
    double m_weightSeas;
public:
    Seasoning(string nameSeas,double weightSeas):m_nameSeas(nameSeas),m_weightSeas(weightSeas){};
    Seasoning(){};

    void setNameSeas(string nameSeas){
        if(nameSeas==""){
            cout<<"You can't set empty name of product"<<endl;
            m_nameSeas="ERROR";
        }else{
            m_nameSeas = nameSeas;
        }
    }
    void setPriceSeas(string m_nameSeas){
        if(m_nameSeas!="")    
            if(m_nameSeas == "Sugar"){
                m_priceSeas = 4.5;
            }else if(m_nameSeas=="Salt"){
                m_priceSeas = 3.0;
            }else if(m_nameSeas=="Pepper"){
                m_priceSeas = 2.0;
            }else{
                m_priceSeas=1.0;
            }
        else{
            m_priceSeas=0;
        }
    }
    void setWeightSeas(double weightSeas){
        if(weightSeas>0.0){
        m_weightSeas = weightSeas;
        }else{
            cout<<"You can't set zero or negative value weight of product"<<endl;
            m_price=0;
        }
    }

    string getNameSeas(){
        return m_nameSeas;
    }
    double getPriceSeas(){
        return m_priceSeas;
    }
    double getWeightSeas(){
        return m_weightSeas;
    }
    
    double costSeas(){
        return m_priceSeas*m_weightSeas;
    }

    void displayProduct() override{
        cout<<"Name: "<<m_nameSeas<<endl;
        cout<<"Weight: "<<m_weightSeas<<" kg"<<endl;
    }
};