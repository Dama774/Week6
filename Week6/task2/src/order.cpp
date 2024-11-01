#include "order.h"

Order::Order(long id, time_t orderDate, time_t deliveryDate, std::string status, Customer customer,
             std::set<Product> products)
    : id(id), orderDate(orderDate), deliveryDate(deliveryDate), status(status), customer(customer), products(products) {}

Order::Order(long id) : id(id), orderDate(0), deliveryDate(0), status(""), customer(Customer()), products() {}

long Order::getId() const {
    return id;
}

time_t Order::getOrderDate() const {
    return orderDate;
}

time_t Order::getDeliveryDate() const {
    return deliveryDate;
}

const std::string& Order::getStatus() const {
    return status;
}

const std::set<Product>& Order::getProducts() const {
    return products;
}

void Order::setId(long id) {
    this->id = id;
}

void Order::setOrderDate(time_t orderDate) {
    this->orderDate = orderDate;
}

void Order::setDeliveryDate(time_t deliveryDate) {
    this->deliveryDate = deliveryDate;
}

void Order::setStatus(const std::string& status) {
    this->status = status;
}

void Order::setProducts(const std::set<Product>& products) {
    this->products = products;
}

