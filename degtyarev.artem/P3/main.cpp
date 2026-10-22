#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{  
  // int argc = 4;
  // const char *argv[] = {"./1", "1", "lab.txt", "a.out"};
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
    if (!(in >> rows >> cols) || rows < 0 || cols < 0) 
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
    
    size_t cnt_cols = 0;
    for (size_t j = 0; j < cols; ++j)
    { 
      bool flag = false;
      for (size_t i = 0; i < rows; ++i)
      {
        if (i!=0 && arr[i][j] == arr[i-1][j])
        {
          flag = true;
          break;
        }
      }
      if (flag == false)
      {
        ++cnt_cols;
      }
    }

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j<cols; ++j)
      {   
        std::cout << arr[i][j] << ' ';
      }
      std::cout << '\n';
    }
    // std::cout << cnt_cols << '\n';
    

    std::ofstream out(argv[3]);
    out << cnt_cols;
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

    int  **arr = (int **)malloc(rows * sizeof(int*));
    for (size_t i = 0; i < rows; ++i)
    {
      arr[i] = (int *)malloc(cols * sizeof(int));
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

    size_t cnt_cols = 0;
    for (size_t j = 0; j < cols; ++j)
    { 
      bool flag = false;
      for (size_t i = 0; i < rows; ++i)
      {
        if (i!=0 && arr[i][j] == arr[i-1][j])
        {
          flag = true;
          break;
        }
      }
      if (flag == false)
      {
        ++cnt_cols;
      }
    }

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j<cols; ++j)
      {   
        std::cout << arr[i][j] << ' ';
      }
      std::cout << '\n';
    }
    std::cout << cnt_cols << '\n';

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
  {
    std::cout << "First parameter isnt a number or out of range\n";
    return 1;
  }
  }
}

