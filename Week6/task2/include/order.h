#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <ctime>
#include <set>
#include "customer.h"
#include "product.h"

class Order {
private:
    long id;
    time_t orderDate;
    time_t deliveryDate;
    std::string status;
    Customer customer;
    std::set<Product> products;

public:
    Order(long id, time_t orderDate, time_t deliveryDate, std::string status, Customer customer,
          std::set<Product> products);
    
    Order(long id);

    // Геттеры
    long getId() const;
    time_t getOrderDate() const;
    time_t getDeliveryDate() const;
    const std::string& getStatus() const;
    const std::set<Product>& getProducts() const;

    // Сеттеры
    void setId(long id);
    void setOrderDate(time_t orderDate);
    void setDeliveryDate(time_t deliveryDate);
    void setStatus(const std::string& status);
    void setProducts(const std::set<Product>& products);
};

#endif // ORDER_H

