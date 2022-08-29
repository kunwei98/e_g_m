#include "DarcyPressure1.h"

registerMooseObject("e_gApp", DarcyPressure1);

InputParameters
DarcyPressure1::validParams()
{
  InputParameters params = ADKernelGrad::validParams();
  params.addClassDescription("Compute the diffusion term for Darcy pressure ($p$) equation: "
                             "$-\\nabla \\cdot \\frac{\\mathbf{K}}{\\mu} \\nabla p = 0$");

  return params;
}

DarcyPressure1::DarcyPressure1(const InputParameters & parameters)
  : ADKernelGrad(parameters),

    // 为变量设置默认值
    _permeability(0.8451e-09),
    _viscosity(7.98e-04)
{
}

// 构建PDE左侧的式子
ADRealVectorValue
DarcyPressure1::precomputeQpResidual()
{
  // 由于基类ADKernel的特性，不需要返回grad_test（基类ADKernel会自动完成这一步）。
  return (_permeability / _viscosity) * _grad_u[_qp];
}
