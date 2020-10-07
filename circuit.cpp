#include "pch.h"
#include "circuit.h"

//CIRCUIT CLASS MEMBER FUNCTION IMPLEMENTATION

//implementation of the output_circuit member function 
void circuit::output_circuit_library() {
	//output the contents of the circuit here
	std::cout << "Circuit contents:\n";
	for (unsigned int i = 0; i < circuit_library.size(); i++) {
		std::cout << "Component " << i + 1;
		circuit_library[i]->output_component();
	}
	std::cout << std::endl;
	//then output the final impedance and phase shift of the circuit, as well as printing the circuit
	print_circuit();
}

//implementation of the calculate_parallel member function 
double circuit::calculate_parallel() {
	double inverse_impedance{};
	if (parallel_impedances.size() > 0) {
		for (size_t i = 0; i < parallel_impedances.size(); i++) {
			inverse_impedance += (1 / parallel_impedances[i]);
		}
		return 1 / inverse_impedance;
	}
	else {
		return 0;
	}
}

//implementation of the output_impedance member function 
void circuit::output_impedence() const {
	std::cout << "\nImpedance of the circuit = " << circuit_impedance << "ohms\n";
	std::cout << "Phase of shift of the circuit = " << circuit_phase_shift << "radians\n";
}

//implementation of the add_in_series member function 
void circuit::add_in_series() {
	//set a series connection type to the component
	circuit_library[circuit_library.size() - 1]->set_connection_type(0);
	series_impedances += circuit_library[circuit_library.size() - 1]->get_impedance_mod();
	circuit_impedance = series_impedances + calculate_parallel();
	circuit_phase_shift += circuit_library[circuit_library.size() - 1]->get_phase_difference();
	series_counter--;
	std::cout << std::endl;
}

//implemention of the add_to_parallel_branch member function 
void circuit::add_to_parallel_branch() {
	//set parallel connection type to the component
	circuit_library[circuit_library.size() - 1]->set_connection_type(1);
	circuit_phase_shift += circuit_library[circuit_library.size() - 1]->get_phase_difference();
	//create a new entry into the parallel impedances vector if this is a new parallel branch
	if (symbols[branch_number].size() == 0) {
		parallel_impedances.push_back(circuit_library[circuit_library.size() - 1]->get_impedance_mod());
	}
	//keep adding to current parallel branch 
	else {
		parallel_impedances[parallel_impedances.size() - 1] = parallel_impedances[parallel_impedances.size() - 1]
			+ circuit_library[circuit_library.size() - 1]->get_impedance_mod();

	}
	symbols[branch_number].emplace_back(circuit_library[circuit_library.size() - 1]->get_symbol());
	circuit_impedance = series_impedances + calculate_parallel();
	std::cout << std::endl;
}

//implementation of the update_branch_number member function 
void circuit::update_branch_number() {
	branch_number++;
	parallel_counter--;
}

//implementation of the print_circuit member function 
void circuit::print_circuit() {
	size_t max_branch_size{};
	size_t series_no{};
	for (size_t i = 0; i < symbols.size(); i++) {
		if (symbols[i].size() > max_branch_size) {
			max_branch_size = symbols[i].size();
		}
	}
	for (size_t i = 0; i < symbols.size(); i++) {
		symbols[i].resize(max_branch_size);
	}
	if (symbols.size() > 0) {
		for (size_t j = 0; j < symbols[0].size(); j++) {
			for (size_t i = 0; i < symbols.size(); i++) {
				if (symbols[i][j] == '\0') {
					symbols[i][j] = '|';
				}
			}
		}
	}
	for (size_t i = 0; i < circuit_library.size();i++) {
		if (circuit_library[i]->get_connection_type() == 0) {
			std::cout << "----" << circuit_library[i]->get_symbol();
			series_no++;
		}
	}
	int width = 5 * (series_no - symbols.size());
	if (series_no == 0) {
		for (int i = 0; i < (5 * parallel_counter); i++) {
			std::cout << '-';
		}
	}
	if (series_no >= symbols.size()) {
		std::cout << '-';
	}
	else if (series_no < symbols.size()) {
		for (size_t i = 0; i < 1 + 5 * (symbols.size() - series_no); i++) {
			std::cout << '-';
		}
	}
	std::cout << "\n|";
	for (size_t i = 0; i < symbols.size(); i++) {
		std::cout << std::setw(5) << '|';
	}
	if (series_no > symbols.size()) {
		std::cout << std::setw(width) << '|';
	}
	if (symbols.size() > 0) {
		if (!symbols[0].empty()) {
			std::cout << "\n|";
		}
		else {
			std::cout << std::endl;
		}
	}
	else {
		std::cout << std::endl;
	}
	if (symbols.size() > 0) {
		for (size_t j = 0; j < symbols[0].size(); j++) {
			for (size_t i = 0; i < symbols.size(); i++) {
				std::cout << std::setw(5) << symbols[i][j];
			}
			if (series_no > symbols.size()) {
				std::cout << std::setw(width) << '|';
			}
			std::cout << "\n|";
			for (size_t i = 0; i < symbols.size(); i++) {
				std::cout << std::setw(5) << '|';
			}
			if (series_no > symbols.size()) {
				std::cout << std::setw(width) << '|';
			}
			if (j != symbols[0].size() - 1) {
				std::cout << "\n|";
			}
			else {
				std::cout << std::endl;
			}
		}
	}
	if (series_no > symbols.size()) {
		for (size_t i = 0; i < 1 + (5 * series_no); i++) {
			std::cout << '-';
		}
	}
	else {
		for (size_t i = 0; i < 1 + (5 * symbols.size()); i++) {
			std::cout << '-';
		}
	}
}