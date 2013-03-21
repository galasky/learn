#include "Voc.hh"

Voc::Voc(const std::string &left, const std::string &right) : _left(left), _right(right), _ok(false)
{

}

Voc::~Voc()
{

}

std::string	Voc::left() const
{
  return (_left);
}

std::string	Voc::right() const
{
  return (_right);
}

bool		Voc::isOk() const
{
  return (_ok);
}

void		Voc::ok()
{
  _ok = true;
}
