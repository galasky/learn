#ifndef	__LEARN_HH__
#define	__LEARN_HH__

#include <vector>
#include <string>
#include "Voc.hh"

class	Learn
{
public:
  Learn();
  ~Learn();
  void	load(const std::string &path);
  void	exec();
private:
  void	add_voc(const std::string &line);
  std::vector<Voc *>			_voc;
  int					_nb;
  float					_ratio;
  int					_repTrue;
  int					_repFalse;
};

#endif	//__LEARN_HH__
