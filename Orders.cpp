
#include "Orders.h"
#include <iostream>
#include<iterator>





Deploy::Deploy(string to, int army) {
	numberofArmy = army;
	toTerr = to;
}

Advance::Advance(string from,string to, int army) {
	fromTerr = from;
	toTerr = to;
	numberofArmy = army;
}

Airlift::Airlift(string from, string to, int army) {
	fromTerr = from;
	toTerr = to;
	numberofArmy = army;
}


OrdersList::OrdersList(list<Orders> LOfOrders) {

    this->listOfOrders = LOfOrders;
}

//Methods 
void Orders::issueOrders() {

    // variables to read input data and use to pass to the constrcotrs 
    string orderType;
    int numberOfarmy;
    string toT;
    string fromT;



    // Request input data for the type of Orders and it's informatino and then pass Sub Orders class to create objects 
    // once user finish the Orders , will need to  press x to exit the whiel loop 


    while (true) {
        cout << "Select the order type (Deploy , Advance , Bomb, Airlift , Negotiate ,Blockcade) Or press x to exit ";
        cin >> orderType;

        if (orderType == "Deploy") {
            cout << "Enter the number of solder you want to deploy" << endl;
            cin >> numberOfarmy;

            cout << "to which terrotory you wish to deploy your army ? " << endl;
            cin >> toT;

            orderList.push_front(Deploy(toT, numberOfarmy));

        }

        if (orderType == "Advance") {
            cout << "How many armies would like to advance?" << endl;
            cin >> numberOfarmy;

            cout << "From which terrotory you wish to deploy your army ? " << endl;
            cin >> fromT;


            cout << "To which terrotory you wish to deploy your army ? " << endl;
            cin >> toT;
            orderList.push_front(Advance(fromT, toT, numberOfarmy));

        }

        if (orderType == "AirLift") {
            cout << "How many armies would like to air lift?" << endl;
            cin >> numberOfarmy;

            cout << "From which terrotory you wish to lift your army ? " << endl;
            cin >> fromT;


            cout << "To which terrotory you wish to send your army ? " << endl;
            cin >> toT;
            orderList.push_front(Airlift(fromT, toT, numberOfarmy));

        }

        // other order types will be implemented in further points when more info provided  

        if (orderType == "x")
            break;
    }

    OrdersList o = OrdersList(orderList);
}


// to be completed 
void OrdersList::move(int from, int to) {

	for (std::list<Orders>::iterator it = listOfOrders.begin(); it != listOfOrders.end(); ++it) {


		std::cout << it->numberofArmy << endl;
		std::cout << it->toTerr << endl;
		std::cout << it->fromTerr << endl;
	}
}

// to be completed 
void OrdersList::remove(int from) {

    //for (std::list<Orders>::iterator it = listOfOrders.begin(); it != listOfOrders.end(); ++it) {


    
}
	
// to be completed 
int Deploy::validate() {

	return 0;
}
	void Deploy::execute() {

		//if(validate)
		cout << "execute" << endl;
		for (std::list<Orders>::iterator it = orderList.begin(); it != orderList.end(); ++it) {
        cout << it->numberofArmy <<"armies will be deployed to "<<toTerr <<endl;
		
		}
	}



    void Advance::execute() {

        //if(validate)
        cout << "execute" << endl;
        for (std::list<Orders>::iterator it = orderList.begin(); it != orderList.end(); ++it) {
            cout << it->numberofArmy << "armies will be advanced from "<<fromTerr<<"to " << toTerr << endl;

        }
    }

    
    void Airlift::execute() {

        //if(validate)
        cout << "execute" << endl;
        for (std::list<Orders>::iterator it = orderList.begin(); it != orderList.end(); ++it) {
            cout << it->numberofArmy << "armies will be air lifted  from " << fromTerr << "to " << toTerr << endl;

        }
    }