#pragma once
#include "component_library.h"
//header file containing the circuit class 

class circuit
{
protected:
	std::vector<components*> circuit_library;
	std::vector<double> parallel_impedances;
	double series_impedances{};
	std::vector<std::vector<char>> symbols;
	double circuit_impedance{};
	double circuit_phase_shift{};
	int series_counter{};
	int parallel_counter{};
	int branch_number{};
public:
	circuit(const int& series_counter_in, const int& parallel_counter_in) : series_counter(series_counter_in), parallel_counter(parallel_counter_in) {
		symbols.resize(parallel_counter);
	}
	~circuit() {
		for (auto it = circuit_library.begin(); it < circuit_library.end(); it++) {
			delete* it;
		}
		circuit_library.clear();
	}
	//member functions of the circuit class to be defined in its respective cpp file
	void print_circuit();
	void output_impedence() const;
	void output_circuit_library();
	void add_in_series();
	void add_to_parallel_branch();
	double calculate_parallel();
	void update_branch_number();

	//member functions declared in the class itself
	int get_series_counter() const { return series_counter; }
	int get_parallel_counter() const { return parallel_counter; }
	int get_branch_number() const { return branch_number; }
	int get_branch_size() const { return symbols[branch_number].size(); }
	void add_component_to_circuit(const int& component_in, component_library* library_in) { circuit_library.push_back(library_in->copy(component_in)); }
};