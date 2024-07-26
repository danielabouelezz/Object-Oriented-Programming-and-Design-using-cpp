#include <bits/stdc++.h>

class Invoice{
public:
    Invoice(const std::string &name, const int &itemNumber,
            const double &price, const int &quantity = 1);
    std::string getName() const;
    int getItemNumber() const;
    double getPrice() const;
    int getQuantity() const;
    void setName(std::string& name);
    void setItemNumber(int itemNumber);
    void setPrice(double price);
    void setQuantity(int quantity);
    double getTotalPrice();
    std::string toString();
private:
    std::string name;
    int itemNumber;
    double price;
    int quantity;
};

Invoice::Invoice(const std::string &name, const int &itemNumber,
                 const double &price, const int &quantity):
        name(name), itemNumber(itemNumber), price(price), quantity(quantity){
        }

std::string Invoice::getName() const
{
    return name;
}
int Invoice::getItemNumber() const
{
    return itemNumber;
}
double Invoice::getPrice() const
{
    return price;
}
int Invoice::getQuantity() const
{
    return quantity;
}

void Invoice::setName(std::string& name)
{
    this->name = name;
}
void Invoice::setItemNumber(int itemNumber)
{
    this->itemNumber = itemNumber;
}
void Invoice::setPrice(double price)
{
    this->price = price;
}
void Invoice::setQuantity(int quantity)
{
    this->quantity = quantity;
}
double Invoice::getTotalPrice()
{
    return getQuantity()*getPrice();
}
std::string Invoice::toString()
{
    std::ostringstream oss;
    oss<<getName()<<","<<getItemNumber()<<","<<getPrice()<<","
    <<getQuantity();

    /*std::string container = getName() + " " + std::to_string(getItemNumber())
     + " " + std::to_string(getPrice())+" " +std::to_string(getQuantity());
    std::cout<<container<<"\n";*/

    return oss.str();
}

int main()
{
    Invoice i1("dany", 1212121, 1199.99, 3);

    std::cout<<i1.toString();

    return 0;
}
