#include <iostream>

#include "Bureaucrat.hpp"
#include "Config.hpp"

int main() {
  std::cout << "============== CPP MODULE 05 / EX 00 =============="
            << std::endl;

  std::cout << BOLD << "Test 1: Valid Bureaucrat Creation\n" << RESET;
  try {
    Bureaucrat trump("President", Bureaucrat::kHighestGrade_);
    std::cout << "Created Bureaucrats successfully:" << std::endl;
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
    Bureaucrat elon("DOGE Leader", 100);
    std::cout << "Created Bureaucrats successfully:" << std::endl;

    std::cout << "Elon musk: " << elon << std::endl;

    elon.incrementGrade();
    std::cout << "After Increment: " << "Elon musk: " << elon
              << std::endl;

    elon.decrementGrade();
    std::cout << "After Decrement: " << "Elon musk: " << elon
              << std::endl;

    // Increment to max grade to test exception
    elon.setGrade(2);
    elon.incrementGrade();  // Should work
    std::cout << "After setting grade to 2 and incrementing: "
              << "Elon musk: " << elon << std::endl;

    elon.incrementGrade();  // Should throw GradeTooHighException
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cerr << "Elon musk: " << e.what() << std::endl;
  }

  try {
    Bureaucrat Bob("Junior Clerk", 149);

    std::cout << "Initial: " << "Bob: " << Bob << std::endl;

    Bob.decrementGrade();
    std::cout << "After Decrement: " << "Bob: " << Bob
              << std::endl;

    Bob.decrementGrade();  // Should throw GradeTooLowException
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cerr << "Bob: " << e.what() << std::endl;
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
