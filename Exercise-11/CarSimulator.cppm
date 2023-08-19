export module Simulator:Car;
import <iostream>;
import :internals;

export namespace Simulator
{
class CarSimulator
{
public:
	CarSimulator() { std::cout << "Car\n"; }
public:
	void setOdoMeter(double miles) { std::cout << Simulator::convertMilesToKm(miles) << '\n'; }
};
}