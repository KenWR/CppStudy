#ifndef FTSED_HPP
#define FTSED_HPP

#include <string>

class FtSed {
private:
  std::string &src_;
  size_t src_length_;
  std::string &dest_;
  size_t dest_length_;

  FtSed();

public:
  // getter & setter
  const std::string &GetSrc(void) const;
  const std::string &GetDest(void) const;
  void SetSrc(const std::string &str);
  void SetDest(const std::string &str);

  // logic functions
  void srcToDest(std::string &str);

  // special member functions
  FtSed(std::string &src, std::string &dest);
  FtSed(const FtSed &copy);
  FtSed &operator=(const FtSed &src);
  ~FtSed();
};

#endif