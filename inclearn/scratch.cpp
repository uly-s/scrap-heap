#include <iostream>
#include <fstream>
#include "experiments.h"

#define INPUT_SIZE 10000
#define GRAPH_SIZE 1000

using namespace std;



int main()
{
  vector<int> inputs;
  vector<int> outputs;

  read_file("data.txt", inputs, outputs);

  //print_vec(inputs);
  //print_vec(outputs);

  for(int i = 0; i < INPUT_SIZE; i++)
  {
    inputs[i] = 10000 + (int) rand() % (INPUT_SIZE - 1);
  }

  vector<int> nodes;
  vector<vector<int*>> edges;



  init_graph(GRAPH_SIZE, nodes, edges);

  int error_max = INPUT_SIZE;
  int error = error_max;
  int iter = 0;

  int x = 0;
  int y = 0;

  while(error > (error_max / 100))
  {
    int index = (int) rand() % (INPUT_SIZE - 1);

    int x_val = inputs[index];
    int y_val = outputs[index];

    int sum = 0;

    for(int i = 0; i < GRAPH_SIZE; i++)
    {
      sum += (*edges[0][i]);
    }

    int new_sum = 0;

    int mut_x = (int) rand() % (GRAPH_SIZE - 1);
    int mut_y = (int) rand() % (GRAPH_SIZE - 1);

    

    for(int i = 0; i < GRAPH_SIZE; i++)
    {
      if (i != mut_x)
        new_sum += (*edges[0][i]);
      else
        new_sum += nodes[mut_y];
    }

    if (new_sum < sum)
    {
      edges[0][mut_x] = &nodes[mut_y];
      error -= sum - new_sum;
    }

    //if(iter++ > 1000)
    //  break;
  }

  cout << error << endl;

  


  return 0;
}