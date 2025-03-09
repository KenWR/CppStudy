#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <limits.h>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Config.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreation at " + target, 145, 137), target_(target) {
  std::cout << O_YELLOW << "Created ShrubberyCreationForm successfully\n "
            << *this << O_RESET;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string &ShrubberyCreationForm::getTarget() const { return target_; }

void ShrubberyCreationForm::executeConcrete() const {
  std::ofstream file((target_ + "_shrubbery").c_str(), std::ios::trunc);

  if (!file.is_open()) {
    std::cerr << "Failed to open file\n";
    return;
  }

  file << "                                                          .\n"
       << "                                               .         ;  \n"
       << "                  .              .              ;%     ;;   \n"
       << "                    ,           ,                :;%  %;   \n"
       << "                     :         ;                   :;%;'     .,\n"
       << "            ,.        %;     %;            ;        %;'    ,;\n"
       << "              ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
       << "               %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
       << "                ;%;      %;        ;%;        % ;%;  ,%;'\n"
       << "                 `%;.     ;%;     %;'         `;%%;.%;'\n"
       << "                  `:;%.    ;%%. %@;        %; ;@%;%',,,,·\n"
       << "                     `:%;.  :;bd%;          %;@%;'\n"
       << "                       `@%:.  :;%.         ;@@%;'   \n"
       << "                         `@%.  `;@%.      ;@@%;         \n"
       << "                           `@%%. `@%%    ;@@%;        \n"
       << "                             ;@%. :@%%  %@@%;       \n"
       << "                               %@bd%%%bd%%:;     \n"
       << "                                 #@%%%%%:;;\n"
       << "                                 %@@%%%::;\n"
       << "                                 %@@@%(o);  . '         \n"
       << "                                 %@@@o%;:(.,'  ///       \n"
       << "                             `.. %@@@o%::;         \n"
       << "                                `)@@@o%::;    /     \n"
       << "                                 %@@(o)::;        \n"
       << "                                .%@@@@%::;         \n"
       << "                                ;%@@@@%::;.,          \n"
       << "                               ;%@@@@%%:;;;. \n"
       << "                           ...;%@@@@@%%:;;;;,..  \n";

  std::cout << O_YELLOW << "Shrubbery has been created\n" << O_RESET;
}
