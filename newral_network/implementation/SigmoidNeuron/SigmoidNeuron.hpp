#ifndef SIGMOIDNEURON_H
#define SIGMOIDNEURON_H

#include "abstract/Neuron.hpp"

// 具象クラス: シグモイドニューロン
class SigmoidNeuron : public Neuron
{
private:
  std::vector<double> weights;
  double bias;

public:
  SigmoidNeuron(int num_inputs);

  // シグモイド関数を使用して出力を計算
  double sigmoid(double x);

  // 入力を処理して出力を返す
  double processInput(const std::vector<double> &inputs) override;
};

#endif // SIGMOIDNEURON_H
