#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>

class Customer {
private:
    long id;
    std::string name;
    int tier;

public:
    Customer(long id);
    Customer();
    
    long getId() const;
    void setId(long id);
    
    const std::string &getName() const;
    void setName(const std::string &name);
    
    int getTier() const;
    void setTier(int tier);
    
    friend std::ostream &operator<<(std::ostream &os, const Customer &customer);
};

#endif // CUSTOMER_H

