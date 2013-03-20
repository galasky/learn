#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Learn.hh"

Learn::Learn()
{
  int	seed;

  _nb = 0;
  _repTrue = 0;
  _repFalse = 0;
  seed = time(NULL);
  srand((seed == time(NULL)) ? seed-- : seed);
}

Learn::~Learn()
{

}

int     random(int a, int b)
{
  return rand()%(b-a) +a;
}

void	Learn::add_voc(const std::string &line)
{
  std::string	left;
  std::string	right;
  int		i = -1;

  while (line[++i] != '=' && line[i])
    left += line[i];
  if (line[i] == '\0')
    {
      std::cout << "\033[H\033[2J";      
      std::cout << "ERROR LINE " << _nb + 1 << " :\t\t\"" << line << "\""<< std::endl << std::endl;
      std::cout << "Exemple good line :";
      std::cout << "\t\"Voiture = car\"" << std::endl;
      exit(0);
    }
  while (line[++i] != '\0')
    right += line[i];
  _voc.push_back(new Voc(left, right));
  _nb++;
}

void	Learn::load(const std::string &path)
{
  std::ifstream	file;
  std::string	line;

  file.open(path.c_str());
  if (file.is_open()) 
    {
      while (!file.eof()) 
	{
	  getline(file, line);
	  add_voc(line);
	}
      file.close();
    }
  std::cout << _nb << " line loaded" << std::endl;
}

void	Learn::exec()
{
  int		max;
  int		nb;
  std::string	rep;

  std::cout << "\033[H\033[2J";
  std::cout << "Nombre de questions : ";
  std::cin >> max;
  for (int i = 0; i < max; i++)
    {
      nb = random(0, _nb);
      std::cout << "\033[H\033[2J";
      std::cout << "N° " << i +1 << ": ";
      std::cout << _voc[nb]->left() << std::endl;
      std::cout << "avez-vous la reponse ? (y/n)" << std::endl;
      std::cin >> rep;
      std::cout << std::endl << "la reponse etait : " << _voc[nb]->right() << std::endl;
      if (rep == "y")
	{
	  std::cout << std::endl << "avez-vous juste ? (y/n)" << std::endl;
	  std::cin >> rep;
	  if (rep == "y")
	    _repTrue++;
	  else
	    _repFalse++;
	}
      else
	{
	  usleep(3000000);
	  _repFalse++;
	}
    }
  std::cout << "\033[H\033[2J";
  std::cout << "Auto evaluation terminee!" << std::endl << std::endl;
  std::cout << "Vous avez " << _repTrue << " de reponses justes sur " << max << " questions" << std::endl;
  std::cout << "Cela vous fait un ratio de " << ((float) _repTrue) / max << std::endl;
}