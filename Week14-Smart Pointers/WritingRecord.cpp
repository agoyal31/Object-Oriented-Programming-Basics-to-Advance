/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/08/19
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"
#include <memory>

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (size_t i = 0; i < emp.size(); ++i) {
			for (size_t j = 0; j < sal.size(); ++j) {
				if (emp[i].id == sal[j].id) {
					EmployeeWage* obj = new EmployeeWage(emp[i].name, sal[j].salary);

					try {
						obj->rangeValidator();
						if(sal.is_valid_sin(sal[j].id)) {
							activeEmp.operator+=(obj);
							delete obj;
						}
						else {
							throw std::string("Invalid sin!");
						}					
					}
					catch(...) {
						delete obj;
						throw std::string ("*** Employees salaray range is not valid");
					}
				}
			}
		}
		
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		for (size_t i = 0; i < emp.size(); ++i) {
			for (size_t j = 0; j < sal.size(); ++j) {
				if (emp[i].id == sal[j].id) {
					std::unique_ptr<EmployeeWage> obj(new EmployeeWage(emp[i].name, sal[j].salary));

					try {
						obj->rangeValidator();
						if (sal.is_valid_sin(sal[j].id)) {
							activeEmp.operator+=(std::move(obj));
						}
						else {
							throw std::string("Invalid sin!");
						}
					}
					catch (...) {
						throw std::string("There si an eroor");
					}
				}
			}
		}

		return activeEmp;
	}
}