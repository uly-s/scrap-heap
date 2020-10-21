#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void read_file(string file_name, vector<int>& inputs, vector<int>& outputs)
{
  ifstream input(file_name);

  int x, y;

  int val = 10000;

  while(input >> x >> y)
  {
    inputs.push_back(val++);
    outputs.push_back(y);
  }

  cout << "DONE READING\n";
}

void print_vec(vector<int>& vec, char dir='v')
{
  for(int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " ";
    if(i % 100 == 0)
    {
      cout << "\n";
    }
  }
}

void init_graph(int size, vector<int>& nodes, vector<vector<int*>>& edges)
{
  nodes.resize(size);

  for (int i = 0; i < size; i++)
  {
    nodes[i] = i - (size / 2);
  }

  edges.resize(size);
  for (int i = 0; i < size; i++)
  {
    edges[i].resize(size);

    edges[i][0] = &nodes[i];

    for (int j = 1; j < size; j++)
    {
      edges[i][j] = &nodes[size - j];
    }
  }
}


