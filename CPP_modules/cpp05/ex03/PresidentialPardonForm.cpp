#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Config.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardon " + target, 25, 5), target_(target) {
  std::cout << O_YELLOW << "Created PresidentialPardonForm successfully\n "
            << *this << O_RESET;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string &PresidentialPardonForm::getTarget() const { return target_; }

void PresidentialPardonForm::executeConcrete() const {
  std::cout << target_ << " has been pardoned by Zafod Beeblebrox\n";
}
