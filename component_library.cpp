#include "pch.h"
#include "component_library.h"

//COMPONENT_LIBRARY MEMBER FUNCTION IMPLEMENTATION

void component_library::add_to_component_library(components* object, const double& frequency_in) {
object->set_frequency(frequency_in);
library_of_components.emplace_back(object);
object->output_component();
}

void component_library::output_component_library() const {
	std::cout << "Number of components in the component library: " << library_of_components.size() << "\n";
	//checking that the component library has a size to begin with
	if (library_of_components.size() != 0) {
		for (unsigned int i = 0; i < library_of_components.size(); i++) {
			std::cout << "Component " << i + 1 << std::right;
			library_of_components[i]->output_component();
		}
	}
	else if (library_of_components.size() == 0) {
		std::cout << "Component library contains no components.";
	}
	std::cout << std::endl;
}