#include <iostream>
using namespace std;

class EMPLOYEE {
public:
    int Employee_Number;
    string Employee_Name;
    int Basic;
    int DA=12;
    int IT =18;
    int Net_Sal;
    int Gross_Sal;
};

class Flight{
    private:
    int flight_number;
    string Destination;
    float Distance;
    float Fuel=13.2;
    void calculate_fuel(){
        Fuel=Distance<=1000?500:Distance<=2000?1100:2200;
    }
    public:
    Flight():Fuel(13.2){}
    void set_fuel(float f){
        Fuel=f;
    }
    void information_entry(){
        cout<<"please enter you flight number: ";
        cin>>flight_number;
        cout<<"please enter you detination: ";
        cin>>Destination;
        cout<<"enter distance to cover: ";
        cin>>Distance;

        calculate_fuel();
    }

    void info_display(){
        cout << "Flight Number: " << flight_number << endl;
        cout << "Destination: " << Destination << endl;
        cout << "Distance: " << Distance << " km" << endl;
        cout << "Fuel Required: " << Fuel << " liters" << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees in your establishment: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        EMPLOYEE employee;
        cout << "Enter the name of the employee: ";
        cin >> employee.Employee_Name;

        cout << "Enter the employee number: ";
        cin >> employee.Employee_Number;

        cout << "Enter the basic salary: ";
        cin >> employee.Basic;

        cout << "Enter the DA (Dearness Allowance): ";
        cin >> employee.DA;

        cout << "Enter the IT (Income Tax): ";
        cin >> employee.IT;

        employee.Gross_Sal = employee.Basic + employee.DA;
        employee.Net_Sal = employee.Gross_Sal - employee.IT;

        cout << "Employee Name: " << employee.Employee_Name << endl;
        cout << "Employee Number: " << employee.Employee_Number << endl;
        cout << "Gross Salary: " << employee.Gross_Sal << endl;
        cout << "Net Salary: " << employee.Net_Sal << endl;
    }

    Flight flight;

    flight.information_entry();
    flight.info_display();


    return 0;
}