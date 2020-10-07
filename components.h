#pragma once
#include "pch.h"
//creating a component interface 

class components
{
public:
	virtual ~components() {}
	virtual void set_frequency(const double& frequency_in) = 0;
	virtual double get_frequency() const = 0;
	virtual std::complex<double> get_impedance() const = 0;
	virtual double get_impedance_mod() const = 0;
	virtual double get_phase_difference() const = 0;
	virtual void output_component() const = 0;
	virtual char get_symbol() const = 0;
	virtual void set_connection_type(const int& connection_type_in) = 0;
	virtual int get_connection_type() const = 0;
	virtual components* copy() const = 0;
};