#include <gtest/gtest.h>
#include "implementation/SigmoidNeuron/SigmoidNeuron.hpp"

class SigmoindNeuronTest : public ::testing::Test
{
protected:
  SigmoidNeuron neuron{3};
  std::vector<double> inputs;

  void SetUp() override
  {
    inputs = {0.5, 0.2, 0.8};
  }

  void TearDown() override
  {
  }
};

TEST_F(SigmoindNeuronTest, test_processInput)
{
  double output = neuron.processInput(inputs);

  // 出力が0から1の間であることを確認
  EXPECT_GE(output, 0.0);
}
