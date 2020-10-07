#pragma once
#include "available_components.h"
//header file containing the component_library class 

class component_library
{
private:
	std::vector<components*> library_of_components;
public:
	component_library() {
		library_of_components.emplace_back(new resistor(500, 1e7));
		library_of_components.emplace_back(new capacitor(500, 1e7));
		library_of_components.emplace_back(new inductor(500, 1e7));
	}
	component_library(const double& frequency_in) {
		library_of_components.emplace_back(new resistor(500, frequency_in));
		library_of_components.emplace_back(new capacitor(500, frequency_in));
		library_of_components.emplace_back(new inductor(500, frequency_in));
	}
	~component_library() {
		for (auto it = library_of_components.begin(); it < library_of_components.end(); it++) {
			delete* it;
		}
		library_of_components.clear();
	}
	//declaring the member functions of this class 
	void add_to_component_library(components* object, const double& frequency_in);
	void output_component_library() const;
	//single-lined member functions defined in the class itself
	components* copy(const int& component_choice) const { return library_of_components[component_choice - 1]->copy();}
	int get_library_size() const { return library_of_components.size();}
};