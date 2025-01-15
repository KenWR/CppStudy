#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  std::cout << "============== CPP MODULE 05 / EX 00 =============="
            << std::endl;

  // Test 1: Valid Bureaucrat Creation
  try {
    Bureaucrat trump("President", Bureaucrat::kHighestGrade_);
    Bureaucrat biden("Clerk", Bureaucrat::kLowestGrade_);

    std::cout << "Created Bureaucrats successfully:" << std::endl;
    std::cout << "Donald Trump: " << trump << std::endl;
    std::cout << "Joe Biden: " << biden << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Error in creation: " << e.what() << std::endl;
  }

  std::cout << "\n=============================================\n" << std::endl;

  // Test 2: Invalid Bureaucrat Creation
  try {
    Bureaucrat einstein("Chief Scientist",
                        0);  // Should throw GradeTooHighException
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << "Albert Einstein: " << e.what() << std::endl;
  }

  try {
    Bureaucrat tesla("Engineer", 200);  // Should throw GradeTooLowException
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << "Nikola Tesla: " << e.what() << std::endl;
  }

  std::cout << "\n=============================================\n" << std::endl;

  // Test 3: Increment and Decrement Grades
  try {
    Bureaucrat officer("Lieutenant", 100);

    std::cout << "Initial: " << "Officer Alex: " << officer << std::endl;

    officer.incrementGrade();
    std::cout << "After Increment: " << "Officer Alex: " << officer
              << std::endl;

    officer.decrementGrade();
    std::cout << "After Decrement: " << "Officer Alex: " << officer
              << std::endl;

    // Increment to max grade to test exception
    officer.setGrade(2);
    officer.incrementGrade();  // Should work
    std::cout << "After setting grade to 2 and incrementing: "
              << "Officer Alex: " << officer << std::endl;

    officer.incrementGrade();  // Should throw GradeTooHighException
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << "Officer Alex: " << e.what() << std::endl;
  }

  try {
    Bureaucrat assistant("Junior Clerk", 149);

    std::cout << "Initial: " << "Assistant Bob: " << assistant << std::endl;

    assistant.decrementGrade();
    std::cout << "After Decrement: " << "Assistant Bob: " << assistant
              << std::endl;

    assistant.decrementGrade();  // Should throw GradeTooLowException
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << "Assistant Bob: " << e.what() << std::endl;
  }

  std::cout << "\n=============================================\n" << std::endl;

  // Test 4: setGrade
  try {
    Bureaucrat intern("Intern", 50);

    std::cout << "Initial: " << "Intern Charlie: " << intern << std::endl;

    intern.setGrade(1);  // Valid set
    std::cout << "After setting grade to 1: " << "Intern Charlie: " << intern
              << std::endl;

    intern.setGrade(200);  // Invalid set, should throw GradeTooLowException
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << "Intern Charlie: " << e.what() << std::endl;
  }

  try {
    Bureaucrat supervisor("Supervisor", 10);

    supervisor.setGrade(0);  // Invalid set, should throw GradeTooHighException
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << "Supervisor Daisy: " << e.what() << std::endl;
  }

  std::cout << "\n=============================================\n" << std::endl;

  // Test 5: Output Operator
  Bureaucrat manager("Manager", 75);
  std::cout << "Testing Output Operator: " << "Manager Evelyn: " << manager
            << std::endl;

  return 0;
}
