#pragma once

// 根据PDE的形式选择对应的Kernel基类
#include "ADKernelGrad.h"

/**
 * 计算方程的残差贡献: K（渗透率） / mu（流体粘性） * grad_test（测试函数的梯度） * grad_u（待求解值的梯度）.
 */
class DarcyPressure1 : public ADKernelGrad
{
public:
  static InputParameters validParams();

  DarcyPressure1(const InputParameters & parameters);

protected:
  /// ADKernel的派生类必须重写precomputeQpResidual
  virtual ADRealVectorValue precomputeQpResidual() override;

  /// 存储已知变量渗透性和流体粘性
  const Real _permeability;
  const Real _viscosity;
};
