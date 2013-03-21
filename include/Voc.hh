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
  bool		isOk() const;
  void		ok();
private:
  std::string	_left;
  std::string	_right;
  bool		_ok;
};

#endif
