#include "SigmoidNeuron.hpp"
#include <cmath>
#include <cstdlib>

// コンストラクタで重みとバイアスを初期化
SigmoidNeuron::SigmoidNeuron(int num_inputs)
{
  weights.resize(num_inputs);
  for (int i = 0; i < num_inputs; ++i)
  {
    weights[i] = (rand() % 1000) / 1000.0; // 0から1の間でランダム
  }
  bias = (rand() % 1000) / 1000.0;
}

// シグモイド関数
double SigmoidNeuron::sigmoid(double x)
{
  return 1.0 / (1.0 + exp(-x));
}

// 入力信号を処理して出力を計算
double SigmoidNeuron::processInput(const std::vector<double> &inputs)
{
  double sum = bias;
  for (size_t i = 0; i < inputs.size(); ++i)
  {
    sum += inputs[i] * weights[i];
  }

  // シグモイド関数で出力を得る
  return sigmoid(sum);
}
