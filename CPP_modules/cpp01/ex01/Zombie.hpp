#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
  std::string name_;

public:
  void announce(void);
  void setName(std::string name);

  Zombie();
  Zombie(const Zombie &copy);
  Zombie &operator=(const Zombie &src);
  ~Zombie();
};

Zombie *zombieHorde(int N, std::string name);

#endif