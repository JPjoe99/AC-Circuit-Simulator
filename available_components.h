#pragma once
#include "components.h"
//header file containing all the different component classes, all inherting from the components interface class 

//CAPACITOR CLASS

class capacitor :
	public components
{
private:
	char symbol{ 'C' };
	double frequency{};
	double capacitance{};
	int connection_type{};
public:
	capacitor() : capacitance{ 0 } {}
	capacitor(const double& capacitance_in) : capacitance{ capacitance_in } {}
	capacitor(const double& capacitance_in, const double& frequency_in) : capacitance{ capacitance_in }, frequency{ frequency_in } {}
	~capacitor() {}
	
	//member function overloaded in the header's respective cpp file 
	void output_component() const override;

	//single-line member functions declared inside the class itself 
	void set_frequency(const double& frequency_in) override { frequency = frequency_in;}
	double get_frequency() const override { return frequency;}

	std::complex<double> get_impedance() const override { return std::complex<double>{ 0, -std::pow(capacitance * 2 * 3.141 * get_frequency(), -1) }; }
	double get_impedance_mod() const override { return std::abs(get_impedance()); }
	double get_phase_difference() const override { return std::arg(get_impedance());}

	void set_connection_type(const int& connection_type_in) override { connection_type = connection_type_in;}
	int get_connection_type() const override { return connection_type;}
	char get_symbol() const override { return symbol; }
	components* copy() const override { return new capacitor(*this);}
};

//INDUCTOR CLASS

class inductor :
	public components
{
private:
	char symbol{ 'L' };
	double frequency{};
	double inductance{};
	int connection_type{};
public:
	inductor() : inductance{ 0 } {}
	inductor(const double& inductance_in) : inductance{ inductance_in } {}
	inductor(const double& inductance_in, const double& frequency_in) : inductance{ inductance_in }, frequency{ frequency_in } {}
	~inductor() {}

	//member function overloaded in the header's respective cpp file 
	void output_component() const override;

	//single-line member functions declared inside the class itself 
	void set_frequency(const double& frequency_in) override { frequency = frequency_in;}
	double get_frequency() const override { return frequency;}

	std::complex<double> get_impedance() const override { return std::complex<double>{ 0, inductance * 2 * 3.141 * get_frequency() };}
	double get_impedance_mod() const override { return std::abs(get_impedance());}
	double get_phase_difference() const override { return std::arg(get_impedance());}

	void set_connection_type(const int& connection_type_in) override { connection_type = connection_type_in;}
	int get_connection_type() const override { return connection_type;}
	char get_symbol() const override { return symbol; }
	components* copy() const override { return new inductor(*this);}

};

//RESISTOR CLASS

class resistor :
	public components
{
private:
	char symbol{ 'R' };
	double frequency{};
	double resistance{};
	int connection_type{};
public:
	resistor() : resistance{ 0 } {}
	resistor(const double& resistance_in) : resistance{ resistance_in } {}
	resistor(const double& resistance_in, const double& frequency_in) : resistance{ resistance_in }, frequency{ frequency_in } {}
	~resistor() {}

	//member function overloaded in the header's respective cpp file 
	void output_component() const override;

	//single-line member functions declared inside the class itself 
	void set_frequency(const double& frequency_in) { frequency = frequency_in;}
	double get_frequency() const override { return frequency;}

	std::complex<double> get_impedance() const override { return std::complex<double>{ resistance, 0 };}
	double get_impedance_mod() const override { return std::abs(get_impedance());}
	double get_phase_difference() const override { return std::arg(get_impedance()); }

	void set_connection_type(const int& connection_type_in) override { connection_type = connection_type_in;}
	int get_connection_type() const override { return connection_type;}
	char get_symbol() const override { return symbol; }
	components* copy() const override { return new resistor(*this);}

};
