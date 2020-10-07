#include "pch.h"
#include "circuit.h"
#include "global_functions.h"


int main() {

    //ask the user for the frequency of their circuit, and applying error validation to the input using the error_handle function
    double AC_frequency{};
    std::cout << "Please enter the frequency of your AC circuit(in Hz): ";
    std::cin >> AC_frequency;
    error_handle(AC_frequency);
    //creating an instance of the component_library, allocating memory on the heap 
    component_library* library = new component_library(AC_frequency);
    //set up a loop for the entire program so that the end of each option should return to the original menu of the program
    int program_loop{ 0 };
    while (program_loop == 0) {
        //using the formatting functions in global_functions.h to print the menu of the program in a visually appealing way
        char_layout('*');
        string_layout("MENU");
        string_layout(" 1 - Add a new component to the component library");
        string_layout(" 2 - Make a circuit");
        string_layout(" 3 - View the component library");
        string_layout(" 4 - Exit the program");
        char_layout('*');

        //take the user's option choice and apply some error validaiton to it
        std::cout << "\nPlease select an option from the menu: ";
        int option{};
        std::cin >> option;
        error_handle(option, 1, 4);
        //will then run the piece of code that corresponds to the user's option choice

        //OPTION 1 - this option will allow the user to add a new component to the component library
        if (option == 1) {
            int option1_loop{ 1 };
            while (option1_loop == 1) {
                int component_choice{};
                std::cout << "What type of component would you like to create?\n";
                std::cout << "\t1 - Resistor\n\t2 - Capacitor\n\t3 - Inductor\nPlease select an option: ";
                std::cin >> component_choice;
                //using error_function from global_functions.h to error validate the user's input for component_choice
                error_handle(component_choice, 1, 3);
                double value_in{};

                //switch statement
                switch (component_choice) {
                    //case 1 will add a new resistor to the component library
                case 1:  std::cout << "Please enter the resistance of the resistor(in Ohms): ";
                    std::cin >> value_in;
                    error_handle(value_in);
                    library->add_to_component_library(new resistor(value_in), AC_frequency);
                    break;
                    //case 2 will add a new capacitor to the component library 
                case 2: std::cout << "Please enter the capacitance of the capacitor(in F): ";
                    std::cin >> value_in;
                    error_handle(value_in);
                    library->add_to_component_library(new capacitor(value_in), AC_frequency);
                    break;
                    //case 3 will add a new inductor to the component library
                case 3: std::cout << "Please enter the inductance of the inductor(in H): ";
                    std::cin >> value_in;
                    error_handle(value_in);
                    library->add_to_component_library(new inductor(value_in), AC_frequency);
                    break;
                }

                //asks the user to either add a new component or return to the program menu
                std::cout << "\nWould you like to add another component to the component library?\n";
                std::cout << "\t1 - YES\n\t2 - NO\nPlease select an option: ";
                std::cin >> option;
                error_handle(option, 1, 2);
                if (option == 1) {
                    option1_loop = 1;
                }
                else if (option == 2) {
                    std::cout << "Returning to the menu.\n";
                    option1_loop = 0;
                }
            }
        }

        //OPTION 2 - this option will begin the process of creating a circuit using the components in the component library

        else if (option == 2) {
            //first establish how many series components and parallel branches the user's circuit will have 
            int series_counter_in{};
            int parallel_counter_in{};
            std::cout << "How many series components will this circuit contain?: ";
            std::cin >> series_counter_in;
            error_handle(series_counter_in);
            std::cout << "How many parallel branches will this circuit contain?: ";
            std::cin >> parallel_counter_in;
            error_handle(parallel_counter_in);
            std::cout << std::endl;

            //creating an instance of the circuit class, allocating memory on the heap, and then outputting the contents of the component library  
            circuit* new_circuit = new circuit(series_counter_in, parallel_counter_in);
            library->output_component_library();

            int option2_loop{};
            while (option2_loop == 0) {
                int component_choice{};
                if (series_counter_in > 0) {
                    std::cout << "First consider which components you'd like to add in series\n";
                    //while loop to add the series components to the circuit library 
                    while (new_circuit->get_series_counter() > 0) {
                        std::cout << "SERIES COMPONENTS REMAINING: " << new_circuit->get_series_counter() << std::endl;
                        std::cout << "Please enter which components you'd like to add in series to the circuit: ";
                        std::cin >> component_choice;
                        error_handle(component_choice, 1, library->get_library_size());
                        new_circuit->add_component_to_circuit(component_choice, library);
                        new_circuit->add_in_series();
                    }
                }

                if (parallel_counter_in > 0) {
                    std::cout << "Now consider which components you'd like to add to the parallel branches\n";
                    //while loop to add component to the paralle branches of the circuit
                    while (new_circuit->get_parallel_counter() > 0) {
                        std::cout << "PARALLEL BRANCH: " << new_circuit->get_branch_number() + 1 << std::endl;
                        std::cout << "SIZE OF BRANCH: " << new_circuit->get_branch_size() << std::endl << std::endl;
                        std::cout << "Please add a component to this branch(Press 0 to move to the next branch): ";
                        std::cin >> component_choice;
                        error_handle(component_choice, 0, library->get_library_size());
                        if (component_choice == 0) {
                            //move on to the next branch if the user enters 0 
                            new_circuit->update_branch_number();
                            std::cout << "PARALLEL BRANCHES REMAINING: " << new_circuit->get_parallel_counter() << std::endl << std::endl;
                        }
                        else {
                            new_circuit->add_component_to_circuit(component_choice, library);
                            new_circuit->add_to_parallel_branch();
                        }
                    }
                }
                //once all components have been added, the final circuit will be displayed, along with the circuit contents and circuit impedance/phase shift
                new_circuit->output_circuit_library();
                new_circuit->output_impedence();
                //calling the circuit destructor, deleting all the components in the circuit library as well as the circuit itself
                delete new_circuit;
                std::cout << "\nPress ENTER to return to the menu: ";
                std::cin.get();
                std::cin.ignore(1000, '\n');
                option2_loop = 1;
            }
        }

        //OPTION 3 - this option will print out all the components in the component library

        else if (option == 3) {
            library->output_component_library();
            std::cout << "\nPress ENTER to return to the menu: ";
            std::cin.get();
            std::cin.ignore(1000, '\n');
        }

        //OPTION 4 - this option will end the program loop, and the end the program

        else if (option == 4) {
            //calling the library's destructor, deleting all the compoonents in the library as well as the library itself
            delete library;
            //exiting the program loop 
            program_loop = 1;
        }
    }
    return 0;
}