export module Simulator:Bike;
import <iostream>;
import :internals;

export namespace Simulator
{
class BikeSimulator
{
public:
	BikeSimulator() { std::cout << "Bike\n"; }
public:
	void setOdoMeter(double miles) { std::cout << Simulator::convertMilesToKm(miles) << '\n'; }
};
}