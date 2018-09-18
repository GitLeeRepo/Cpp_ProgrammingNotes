// oper_overload_ex1.cpp
//
// Example of overloading the '[]', '==', and '!=' operators

#include <iostream>
#include <string>

struct OrderItem {
    int orderNum = 0;
    int itemNum = 0;
    std::string itemName = ""; 
    OrderItem() {}  // used by new in OrderItems initalizer_list constructor
    OrderItem(int orderNum, int itemNum, std::string itemName)
        : orderNum{orderNum}, itemNum{itemNum}, itemName{itemName} {}
};

class OrderItems {
public:
    // constructor - initialize with list, ex., Vector v =  { 1, 2, 3 }
    OrderItems(std::initializer_list<OrderItem> lst) 
        :elem{new OrderItem[lst.size()]}, sz{static_cast<int>(lst.size())} {
        std::copy(lst.begin(), lst.end(), elem);
    }
    // destructor
    ~OrderItems() { 
        delete[] elem;
    }

    //subscripting access
    OrderItem& operator[](int i) { return elem[i]; }

    // equal if orderItems object has same orderNum
    // for more of an 'in' operator than equality
    bool operator==(int orderNum) {
        return hasOrder(orderNum);
    }

    // not equal if orderItems object doesn't have same orderNum
    // for more of a 'not in' operator than nonequality
    bool operator!=(int orderNum) {
        return !hasOrder(orderNum);
    }

    int size() { return sz; }

private:
    OrderItem* elem;  // pointer to the elements
    int sz;        // number of elements

    bool hasOrder(int orderNum) {
        bool orderFound = false;
        for (auto i = 0; i < sz; i++) {
            if (elem[i].orderNum == orderNum) {
                orderFound = true;
                break;
            }
        }
        return orderFound;
    }
};

int main() {
    using namespace std;

    OrderItems orderItems1 = { OrderItem(1, 1, "one"), OrderItem(1, 2, "two")  };
    OrderItems orderItems2 = { OrderItem(1, 1, "one"), OrderItem(2, 1, "one")  };

    // to keep demo simple use two for loops rather than nested list of OrderItems
    cout << "orderItems1" << endl;
    cout << "-----------" << endl;
    for (auto i = 0; i < orderItems1.size(); i++) {
        cout << "order number: " << orderItems1[i].orderNum << endl;
        cout << "item number: " << orderItems1[i].itemNum << endl;
        cout << "item name: " << orderItems1[i].itemName << endl;
        cout << endl;
    }

    cout << "orderItems2" << endl;
    cout << "-----------" << endl;
    for (auto i = 0; i < orderItems2.size(); i++) {
        cout << "order number: " << orderItems2[i].orderNum << endl;
        cout << "item number: " << orderItems2[i].itemNum << endl;
        cout << "item name: " << orderItems2[i].itemName << endl;
        cout << endl;
    }

    if (orderItems1 == 1) 
        cout << "orderItems1 order number 1 is in the order" << endl;
    if (orderItems1 != 2) 
        cout << "orderItems1 order number 2 is not in the order" << endl;

    if (orderItems2 == 1 && orderItems2 == 2)
        cout << "orderItems2 order number 1 and 2 are in the order" << endl;
    if (orderItems1 != 3) 
        cout << "orderItems2 order number 3 is not in the order" << endl;


    return 0;
}
