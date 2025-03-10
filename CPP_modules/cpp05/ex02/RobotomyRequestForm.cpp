#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Config.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequest about " + target, 72, 45), target_(target) {
  std::cout << O_YELLOW << "Created RobotomyRequestForm successfully\n "
            << *this << O_RESET;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string &RobotomyRequestForm::getTarget() const { return target_; }

void RobotomyRequestForm::executeConcrete() const {
  std::cout << "Vrrrrrrrr\n" << "Krrrrrrrrk\n" << "Squishing, Sloshing!\n";

  std::srand(std::time(NULL));
  if (std::rand() % 2) {
    std::cout << target_ << " has been robotomized successfully\n\n";
  } else {
    std::cout << "Failed to robotomize " << target_ << "\n\n";
  }
}
