#ifndef NEURON_H
#define NEURON_H

#include <vector>

// 抽象クラス: ニューロン
class Neuron
{
public:
  virtual ~Neuron() {}

  // ニューロンの入力信号を処理し、出力を返す純粋仮想関数
  virtual double processInput(const std::vector<double> &inputs) = 0;
};

#endif // NEURON_H
