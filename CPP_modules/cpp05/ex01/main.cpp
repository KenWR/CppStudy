#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  std::cout << "============== TESTING BUREAUCRAT AND FORM =============="
            << std::endl;

  // Test 1: Valid Bureaucrat and Form Creation
  try {
    Bureaucrat trump("Donald Trump", 10);
    Form taxForm("Tax Form", 20, 50);

    std::cout << "Created Bureaucrat and Form successfully:" << std::endl;
    std::cout << trump << std::endl;
    std::cout << taxForm << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error in creation: " << e.what() << std::endl;
  }

  std::cout << "\n========================================================\n"
            << std::endl;

  // Test 2: Bureaucrat signs Form successfully
  try {
    Bureaucrat manager("Alice", 15);
    Form report("Project Report", 20, 30);

    std::cout << manager << std::endl;
    std::cout << report << std::endl;

    std::cout << "\nAlice attempts to sign the form:" << std::endl;
    manager.signForm(report); // Should succeed
    std::cout << report << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error during signing: " << e.what() << std::endl;
  }

  std::cout << "\n========================================================\n"
            << std::endl;

  // Test 3: Bureaucrat fails to sign Form due to low grade
  try {
    Bureaucrat clerk("Bob", 50);
    Form report("Confidential Report", 10, 20);

    std::cout << clerk << std::endl;
    std::cout << report << std::endl;

    std::cout << "\nBob attempts to sign the form:" << std::endl;
    clerk.signForm(report); // Should throw GradeTooLowException
  } catch (const std::exception &e) {
    std::cerr << "Error during signing: " << e.what() << std::endl;
  }

  std::cout << "\n========================================================\n"
            << std::endl;

  // Test 4: Bureaucrat signs an already signed Form
  try {
    Bureaucrat president("John", 5);
    Form executiveOrder("Executive Order", 10, 20);

    std::cout << president << std::endl;
    std::cout << executiveOrder << std::endl;

    std::cout << "\nJohn attempts to sign the form:" << std::endl;
    president.signForm(executiveOrder); // Should succeed

    std::cout << "\nJohn attempts to sign the already signed form:"
              << std::endl;
    president.signForm(
        executiveOrder); // Should indicate the form is already signed
  } catch (const std::exception &e) {
    std::cerr << "Error during signing: " << e.what() << std::endl;
  }

  std::cout << "\n========================================================\n"
            << std::endl;

  // Test 5: Invalid Form Creation
  try {
    Form invalidForm("Invalid Form", 0, 200); // Should throw exceptions
  } catch (const Form::GradeTooHighException &e) {
    std::cerr << "Expected Exception (Too High): " << e.what() << std::endl;
  } catch (const Form::GradeTooLowException &e) {
    std::cerr << "Expected Exception (Too Low): " << e.what() << std::endl;
  }

  return 0;
}
