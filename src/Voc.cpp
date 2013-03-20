#include "Voc.hh"

Voc::Voc(const std::string &left, const std::string &right) : _left(left), _right(right)
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
