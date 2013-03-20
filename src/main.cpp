#include <iostream>
#include "Learn.hh"

int	main(int ac, char **av)
{
  Learn learn;
  std::string path;

  if (ac == 2)
    {
      path.append(av[1]);
      learn.load(path);
      learn.exec();
   }
  else
    std::cout << "USAGE : ./learn LISTE_DE_VOCABULAIRE" << std::endl;
  return (0);
}
