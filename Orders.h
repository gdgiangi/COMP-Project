#pragma once

#include <iostream>
#include <string>
#include<list>
using namespace std;


class Orders {

    
    
public:
    int numberofArmy;
    string terrtory;
    string orderType;
    string fromTerr;
    string toTerr;
    int army;
    int numberOfOrder;
    list<Orders> orderList;
    
    void issueOrders();


};



class Deploy :public Orders {

public:

    Deploy( string to, int army);
    void execute();
    int validate();


};

class Advance :public Orders {

public:
    Advance(string from, string to, int army);
    void execute();
    int validate();
};

class Bomb :public Orders {
public:
    Bomb();
    void execute();
    int validate();
};

class Blockade :public Orders {
public:

    Blockade();
    void execute();
    int validate();
};
class Airlift :public Orders {
public:

    Airlift(string from, string to, int army);
    void execute();
    int validate();
};
class Negotiate :public Orders {
public:

    Negotiate();
    void execute();
    int validate();
};

class OrdersList {

public:
    OrdersList(list <Orders> orderlist);
    list<Orders> listOfOrders;
  
    void  move(int moveFrom , int moveTo);
    void  remove(int removeFrom);

       
};

   
    







// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
