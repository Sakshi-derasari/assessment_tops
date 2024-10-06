#include <iostream>
#include <cmath>
using namespace std;

const double CostPerHour = 18.50;
const double CostPerMinute = 0.40;
const double CostOfDinner = 20.70;

class Event {
private:
    string eventName;
    string firstandlastname;
    int numberOfGuests;
    int numberOfMinutes;
    int numberOfServers;
    double costForOneServer;
    double totalFoodCost;
    double totalCost;
    double averageCost;
    double depositAmount;

public:
    void getEventDetails() { // Function to get event details
        cout<<"Enter the name of the event"<<endl;
        getline(cin, eventName);
        
        cout<<"Enter your first and last name"<<endl;
        cin.ignore();
        getline(cin,firstandlastname);
        
        cout<<"Enter the number of guests"<<endl;
        cin>>numberOfGuests;
        
        cout<<endl<<"Enter the number of minutes for the event"<<endl;
        cin>>numberOfMinutes;
    }

    // Function to calculate the number of servers required
    void calculateServers() {
        numberOfServers = ceil(static_cast<double>(numberOfGuests) / 20);
    }

    // Function to calculate the cost for one server
    void calculateCostForOneServer() {
        double cost1 = (numberOfMinutes / 60) * CostPerHour;     // Hourly cost
        double cost2 = (numberOfMinutes % 60) * CostPerMinute;   // Minute-based cost
        costForOneServer = cost1 + cost2;
    }

    void calculateFoodCost() {
        totalFoodCost = numberOfGuests * CostOfDinner;
    }

    void calculateTotalCost() {
        totalCost = totalFoodCost + (costForOneServer * numberOfServers);
    }

    void calculateAverageCost() {
        averageCost = totalFoodCost / numberOfGuests;
    }

    void calculateDepositAmount() {
        depositAmount = totalCost * 0.25;
    }

    void displayEventDetails() {
        cout<<"***********Event estimate for : rakesh kharva***********"<<endl;
        cout<<"Number of Server: "<<numberOfServers<<endl;
        cout<<"The Cost for Server: "<<costForOneServer<<endl;
        cout<<"The cost for food is: "<<totalFoodCost<<endl;
        cout<<"Average Cost Per Person: "<<averageCost<<endl;
        cout<<endl<<"Total Cost is: "<<totalCost<<endl;
        cout<<"PLease deposite a 25% deposite to reserve the event"<<endl;
        cout<<"The deposite needed is: "<<depositAmount<<endl;
    }

    void estimateCost() {
        getEventDetails();
        calculateServers();
        calculateCostForOneServer();
        calculateFoodCost();
        calculateAverageCost();
        calculateTotalCost();
        calculateDepositAmount();
        displayEventDetails();
    }
};

int main() {
    char choice;
    do {
        Event myEvent;
        myEvent.estimateCost();

        cout << "\nWould you like to estimate another event? (y/n): ";
        cin >> choice;
        cin.ignore();
        if (choice == 'n' || choice == 'N') {
            break;
        }
    } while (true);
}