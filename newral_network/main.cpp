#include <iostream>
#include <vector>
#include "implementation/SigmoidNeuron/SigmoidNeuron.hpp"

int main()
{
  // 入力サイズを指定してシグモイドニューロンを作成
  SigmoidNeuron neuron(3); // 3入力のニューロン

  // ニューロンに与える入力
  std::vector<double> inputs = {0.5, 0.2, 0.8};

  // ニューロンの出力を計算
  double output = neuron.processInput(inputs);

  // 結果を表示
  std::cout << "Neuron output: " << output << std::endl;

  return 0;
}
