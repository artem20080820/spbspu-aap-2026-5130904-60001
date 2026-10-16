#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
  if (argc<4)
  {
    std::cerr << "Not enough arguments";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments";
    return 1;
  }
  
  switch (*argv[1])
  {
  case '1':
  {
    std::ifstream in(argv[2]);
    int rows, cols;
    if (!(in >> rows >> cols) || rows <= 0 || cols <= 0) 
    { 
      std::cerr << "Error reading file\n";
      return 2;
    }

    int arr[rows][cols];
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j<cols; ++j)
      {   
        if (!(in >> arr[i][j]))
        {
            std::cerr << "Error reading file\n";
            return 2;
        }
      }
    }

    std::ofstream out(argv[3]);
    out << rows << " " << cols;
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j<cols; ++j)
      {   
        out << " " << arr[i][j];
      }
    }
    std::cout << '\n';
    return 0;
  }

  case '2':
  {
    std::ifstream in(argv[2]);
    int rows, cols;
    if (!(in >> rows >> cols))
    {
      std::cerr << "Error reading file\n";
      return 2;
    }

    int **arr = new int* [rows];
    for (size_t i = 0; i < rows; ++i)
    {
      arr[i] = new int [cols];
    }

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        if (!(in >> arr[i][j]))
        {
          std::cerr << "Error reading file\n";
          return 2;
        }
      }
    }

    std::ofstream out(argv[3]);
    out << rows << " " << cols;

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        out << " " << arr[i][j];
      }
    }
    std::cout << '\n'; 
    return 0;
  }

  default:
    std::cout << "First parameter isnt a number or out of range\n";
    return 1;
  }
}
