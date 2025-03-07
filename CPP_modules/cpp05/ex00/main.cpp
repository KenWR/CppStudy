#include <iostream>

#include "Bureaucrat.hpp"
#include "Config.hpp"

int main() {
  std::cout << O_BOLD << "=========== CPP MODULE 05 / EX 00 ===========\n\n"
            << O_RESET;

  std::cout << O_BOLD << "===== Test 1: Valid Bureaucrat Creation =====\n"
            << O_RESET;
  try {
    Bureaucrat trump("President", Bureaucrat::kHighestGrade_);
    std::cout << "Donald Trump: " << trump << '\n';

    Bureaucrat biden("Clerk", Bureaucrat::kLowestGrade_);
    std::cout << "Joe Biden: " << biden << '\n';
  } catch (const std::exception &e) {
    std::cerr << O_RED << O_RED << "Error in creation: " << e.what() << '\n'
              << O_RESET << O_RESET;
  }

  std::cout << O_BOLD << "=============================================\n\n"
            << O_RESET;

  std::cout << O_BOLD << "==== Test 2: Invalid Bureaucrat Creation ====\n"
            << O_RESET;
  try {
    Bureaucrat einstein("Chief Scientist",
                        0); // Should throw GradeTooHighException
    std::cout << "Albert Einstein: " << einstein << '\n';
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << O_RED << "Albert Einstein: " << e.what() << '\n' << O_RESET;
  }

  try {
    Bureaucrat tesla("Engineer", 200); // Should throw GradeTooLowException
    std::cout << "Nikola Tesla: " << tesla << '\n';
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << O_RED << "Nikola Tesla: " << e.what() << '\n' << O_RESET;
  }

  std::cout << O_BOLD << "=============================================\n\n"
            << O_RESET;

  std::cout << O_BOLD << "=== Test 3: Increment and Decrement Grades ==\n"
            << O_RESET;
  try {
    Bureaucrat elon("DOGE Leader", 100);
    std::cout << "Elon musk: " << elon << '\n';

    std::cout << O_DIM << "Increasing...\n" << O_RESET;
    elon.incrementGrade();
    std::cout << "After Increment: " << elon << '\n';

    std::cout << O_DIM << "Decreasing...\n" << O_RESET;
    elon.decrementGrade();
    std::cout << "After Decrement: " << elon << '\n';

    std::cout << O_DIM << "Setting grade...\n" << O_RESET;
    elon.setGrade(2);
    std::cout << "Set grade to 2: " << elon << '\n';

    std::cout << O_DIM << "Increasing...\n" << O_RESET;
    elon.incrementGrade(); // Should work
    std::cout << "After Increment: " << elon << '\n';

    elon.incrementGrade(); // Should throw GradeTooHighException
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << O_RED << "Elon musk: " << e.what() << '\n' << O_RESET;
  }

  try {
    Bureaucrat Bob("Junior Clerk", 149);

    std::cout << "Bob: " << Bob << '\n';

    std::cout << "Decreasing...\n" << O_RESET;
    Bob.decrementGrade();
    std::cout << "After Decrement: " << Bob << '\n';

    std::cout << "Decreasing...\n" << O_RESET;
    Bob.decrementGrade(); // Should throw GradeTooLowException
    std::cout << "After Decrement: " << Bob << '\n';
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << O_RED << "Bob: " << e.what() << '\n' << O_RESET;
  }

  std::cout << O_BOLD << "=============================================\n\n"
            << O_RESET;

  std::cout << O_BOLD << "============== Test 4: setGrade =============\n"
            << O_RESET;
  try {
    Bureaucrat charlie("Intern", 50);
    std::cout << "Charlie: " << charlie << '\n';

    std::cout << O_DIM << "Setting grade...\n" << O_RESET;
    charlie.setGrade(1); // Valid set
    std::cout << "After setting grade to 1: " << charlie << '\n';

    std::cout << O_DIM << "Setting grade...\n" << O_RESET;
    charlie.setGrade(200); // Invalid set, should throw GradeTooLowException
    std::cout << "After setting grade to 150: " << charlie << '\n';
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << O_RED << "Charlie: " << e.what() << '\n' << O_RESET;
  }

  try {
    Bureaucrat daisy("Supervisor", 10);
    std::cout << "Daisy: " << daisy << '\n';

    std::cout << O_DIM << "Setting grade...\n" << O_RESET;
    daisy.setGrade(0); // Invalid set, should throw GradeTooHighException
    std::cout << "After setting grade to 0: " << daisy << '\n';
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << O_RED << "Daisy: " << e.what() << '\n' << O_RESET;
  }

  std::cout << O_BOLD << "=============================================\n\n"
            << O_RESET;
}
