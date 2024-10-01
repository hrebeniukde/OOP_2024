#include <iostream>

#include "developer.h"
#include "jobposition.h"
#include "department.h"

int main() {
    std::string developerName;
    int developerId;
    int developerSalary;
    std::string programmingLanguage;

    std::cout << "Enter developer name: ";
    std::getline(std::cin, developerName);

    std::cout << "Enter developer ID: ";
    std::cin >> developerId;

    std::cout << "Enter developer salary: ";
    std::cin >> developerSalary;

    std::cout << "Enter programming language: ";
    std::cin.ignore();
    std::getline(std::cin, programmingLanguage);

    std::string jobTitle;
    int jobSalary;

    std::cout << "Enter job position title: ";
    std::getline(std::cin, jobTitle);

    std::cout << "Enter job position salary: ";
    std::cin >> jobSalary;

    JobPosition jobPosition;
    jobPosition.setTitle(jobTitle);
    jobPosition.setSalary(jobSalary);

    std::string departmentName;
    std::string departmentManager;

    std::cout << "Enter department name: ";
    std::cin.ignore();
    std::getline(std::cin, departmentName);

    std::cout << "Enter department manager name: ";
    std::getline(std::cin, departmentManager);

    Department department;
    department.setName(departmentName);
    department.setManager(departmentManager);

    Developer developer;
    developer.setName(developerName);
    developer.setId(developerId);
    developer.setSalary(developerSalary);
    developer.setProgrammingLanguage(programmingLanguage);
    developer.setJobPosition(jobPosition);
    developer.setDepartment(&department);

    std::cout << std::endl;
    std::cout << "Developer created successfully!" << std::endl;
    std::cout << "Developer Name: " << developer.getName() << std::endl;
    std::cout << "Developer ID: " << developer.getId() << std::endl;
    std::cout << "Developer Salary: " << developer.getSalary() << std::endl;
    std::cout << "Programming Language: " << developer.getProgrammingLanguage() << std::endl;
    std::cout << "Job Position: " << developer.getJobPosition().getTitle() << std::endl;
    std::cout << "Job Salary: " << developer.getJobPosition().getSalary() << std::endl;
    std::cout << "Department Name: " << developer.getDepartment()->getName() << std::endl;
    std::cout << "Department Manager: " << developer.getDepartment()->getManager() << std::endl;

    return 0;
}
