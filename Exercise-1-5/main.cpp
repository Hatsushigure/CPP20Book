#include <iostream>
#include <format>
import AirlineTicket;

void printTicket(const AirlineTicket& ticket);

int main()
{
	AirlineTicket t1("John Smith", 114514, false);
	AirlineTicket t2("Jim Brown", 1919810, true);
	printTicket(t1);
	printTicket(t2);
}

void printTicket(const AirlineTicket& ticket)
{
	using std::cout, std::format;

	cout << format("Passenger: {}\n", ticket.passengerName());
	cout << format("Route length: {} miles\n", ticket.numberOfMiles());
	cout << format("Cost: ${:.2f}\n", ticket.calcPrice());
}
