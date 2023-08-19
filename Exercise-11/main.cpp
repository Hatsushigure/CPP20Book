import Simulator;

int main()
{
	auto bike {Simulator::BikeSimulator()};
	auto car {Simulator::CarSimulator()};
	bike.setOdoMeter(1);
	car.setOdoMeter(2);
	//Simulator::convertMilesToKm(1);	//Will not compile
}