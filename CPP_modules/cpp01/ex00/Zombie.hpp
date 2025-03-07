#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
  std::string name_;

public:
  void announce(void);

  Zombie();                             // Default constructor
  Zombie(std::string name);             // Parameterized constructor
  Zombie(const Zombie &copy);           // Copy constructor
  Zombie &operator=(const Zombie &src); // Assignment operator overload
  ~Zombie(void);                        // DESTRUCTOR
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif