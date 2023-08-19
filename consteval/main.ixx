consteval double inchToMm(double inch) { return inch * 25.4; }

int main()
{
	double dynamic_inch {9.0};
	double mm2 {inchToMm(dynamic_inch)};	//won't compile
}