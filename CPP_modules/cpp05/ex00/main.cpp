#include <iostream>

#include "Bureaucrat.hpp"
#include "Config.hpp"

int main()
{
    std::cout << O_BOLD << "=========== CPP MODULE 05 / EX 00 ===========\n\n" << O_RESET;

    std::cout << O_BOLD << "===== Test 1: Valid Bureaucrat Creation =====\n" << O_RESET;
    try
    {
        Bureaucrat trump("President", Bureaucrat::kHighestGrade_);
        std::cout << "Donald Trump: " << trump << '\n';

<<<<<<< HEAD
    std::cout << "Created Bureaucrats successfully:" << std::endl;
    std::cout << "Donald Trump: " << trump << std::endl;
    std::cout << "Joe Biden: " << biden << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error in creation: " << e.what() << std::endl;
  }
=======
        Bureaucrat biden("Clerk", Bureaucrat::kLowestGrade_);
        std::cout << "Joe Biden: " << biden << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << O_RED << O_RED << "Error in creation: " << e.what() << '\n' << O_RESET << O_RESET;
    }
>>>>>>> 479d114753cba58f6ee434eb558808859178f5ae

    std::cout << O_BOLD << "=============================================\n\n" << O_RESET;

<<<<<<< HEAD
  // Test 2: Invalid Bureaucrat Creation
  try {
    Bureaucrat einstein("Chief Scientist",
                        0); // Should throw GradeTooHighException
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << "Albert Einstein: " << e.what() << std::endl;
  }

  try {
    Bureaucrat tesla("Engineer", 200); // Should throw GradeTooLowException
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << "Nikola Tesla: " << e.what() << std::endl;
  }
=======
    std::cout << O_BOLD << "==== Test 2: Invalid Bureaucrat Creation ====\n" << O_RESET;
    try
    {
        Bureaucrat einstein("Chief Scientist", 0); // Should throw GradeTooHighException
        std::cout << "Albert Einstein: " << einstein << '\n';
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << O_RED << "Albert Einstein: " << e.what() << '\n' << O_RESET;
    }

    try
    {
        Bureaucrat tesla("Engineer", 200); // Should throw GradeTooLowException
        std::cout << "Nikola Tesla: " << tesla << '\n';
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << O_RED << "Nikola Tesla: " << e.what() << '\n' << O_RESET;
    }
>>>>>>> 479d114753cba58f6ee434eb558808859178f5ae

    std::cout << O_BOLD << "=============================================\n\n" << O_RESET;

    std::cout << O_BOLD << "=== Test 3: Increment and Decrement Grades ==\n" << O_RESET;
    try
    {
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

<<<<<<< HEAD
    // Increment to max grade to test exception
    officer.setGrade(2);
    officer.incrementGrade(); // Should work
    std::cout << "After setting grade to 2 and incrementing: "
              << "Officer Alex: " << officer << std::endl;

    officer.incrementGrade(); // Should throw GradeTooHighException
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << "Officer Alex: " << e.what() << std::endl;
  }
=======
        elon.incrementGrade(); // Should throw GradeTooHighException
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << O_RED << "Elon musk: " << e.what() << '\n' << O_RESET;
    }

    try
    {
        Bureaucrat Bob("Junior Clerk", 149);
>>>>>>> 479d114753cba58f6ee434eb558808859178f5ae

        std::cout << "Bob: " << Bob << '\n';

        std::cout << "Decreasing...\n" << O_RESET;
        Bob.decrementGrade();
        std::cout << "After Decrement: " << Bob << '\n';

        std::cout << "Decreasing...\n" << O_RESET;
        Bob.decrementGrade(); // Should throw GradeTooLowException
        std::cout << "After Decrement: " << Bob << '\n';
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << O_RED << "Bob: " << e.what() << '\n' << O_RESET;
    }

<<<<<<< HEAD
    assistant.decrementGrade(); // Should throw GradeTooLowException
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << "Assistant Bob: " << e.what() << std::endl;
  }
=======
    std::cout << O_BOLD << "=============================================\n\n" << O_RESET;
>>>>>>> 479d114753cba58f6ee434eb558808859178f5ae

    std::cout << O_BOLD << "============== Test 4: setGrade =============\n" << O_RESET;
    try
    {
        Bureaucrat charlie("Intern", 50);
        std::cout << "Charlie: " << charlie << '\n';

        std::cout << O_DIM << "Setting grade...\n" << O_RESET;
        charlie.setGrade(1); // Valid set
        std::cout << "After setting grade to 1: " << charlie << '\n';

        std::cout << O_DIM << "Setting grade...\n" << O_RESET;
        charlie.setGrade(200); // Invalid set, should throw GradeTooLowException
        std::cout << "After setting grade to 150: " << charlie << '\n';
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << O_RED << "Charlie: " << e.what() << '\n' << O_RESET;
    }

<<<<<<< HEAD
    intern.setGrade(1); // Valid set
    std::cout << "After setting grade to 1: " << "Intern Charlie: " << intern
              << std::endl;

    intern.setGrade(200); // Invalid set, should throw GradeTooLowException
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << "Intern Charlie: " << e.what() << std::endl;
  }

  try {
    Bureaucrat supervisor("Supervisor", 10);

    supervisor.setGrade(0); // Invalid set, should throw GradeTooHighException
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << "Supervisor Daisy: " << e.what() << std::endl;
  }

  std::cout << "\n=============================================\n" << std::endl;

  // Test 5: Output Operator
  Bureaucrat manager("Manager", 75);
  std::cout << "Testing Output Operator: " << "Manager Evelyn: " << manager
            << std::endl;

  return 0;
=======
    try
    {
        Bureaucrat daisy("Supervisor", 10);
        std::cout << "Daisy: " << daisy << '\n';

        std::cout << O_DIM << "Setting grade...\n" << O_RESET;
        daisy.setGrade(0); // Invalid set, should throw GradeTooHighException
        std::cout << "After setting grade to 0: " << daisy << '\n';
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << O_RED << "Daisy: " << e.what() << '\n' << O_RESET;
    }

    std::cout << O_BOLD << "=============================================\n\n" << O_RESET;
>>>>>>> 479d114753cba58f6ee434eb558808859178f5ae
}
