#include "pch.h"
#include "available_components.h"

//CAPACITOR MEMBER FUNCTION IMPLEMENTATION

void capacitor::output_component() const {
	std::cout << "\n";
	std::cout.precision(3);
	std::cout << "\tComponent: " << capacitance << "F Capacitor\n";
	std::cout << "\tMagnitude of impedance: " << get_impedance_mod() << "ohm\n";
	std::cout << "\tPhase shift of impedance: " << get_phase_difference() << " radians\n";
}

//INDUCTOR MEMBER FUNCTION IMPLEMENTATION

void inductor::output_component() const  {
	std::cout << "\n";
	std::cout.precision(3);
	std::cout << "\tComponent: " << inductance << "H Inductor\n";
	std::cout << "\tMagnitude of impedance: " << get_impedance_mod() << "ohm\n";
	std::cout << "\tPhase shift of impedance: " << get_phase_difference() << " radians\n";
}

//RESISTOR MEMBER FUNCTION IMPLEMENTATION

void resistor::output_component() const  {
	std::cout << "\n";
	std::cout.precision(3);
	std::cout << "\tComponent: " << resistance << "ohm Resistor\n";
	std::cout << "\tMagnitude of impedance: " << get_impedance_mod() << "ohm\n";
	std::cout << "\tPhase shift of impedance: " << get_phase_difference() << " radians\n";
}

