#include "cpu.hpp"

Cpu::OpPointer Cpu::_ops[] =
  {
    &Cpu::INCBC
  };

Cpu::OpPointer Cpu::_cbops[] =
  {
    &Cpu::INCBC
  };


Cpu::Cpu(Mmu* mmu)
  : _mmu(mmu)
  , _a(0), _b(0), _c(0), _d(0), _e(0), _h(0), _l(0), _f(0)
  , _ra(0), _rb(0), _rc(0), _rd(0), _re(0), _rh(0), _rl(0), _rf(0)
  , _ticks(0), _totalTicks(0)
  , _halt(0), _ime(0), _stop(0)
{
}
