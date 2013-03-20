#ifndef	__VOC_HH__
#define	__VOC_HH__

#include <string>

class	Voc
{
public:
  Voc(const std::string &left, const std::string &right);
  ~Voc();
  std::string	left() const;
  std::string	right() const;
private:
  std::string	_left;
  std::string	_right;
};

#endif
