#pragma once

#include "mmu.hpp"

class Cpu
{
public:
  Cpu(Mmu* mmu);

  
  void reset();
  void exec();


private:

  typedef void(*OpPointer)();
  OpPointer *_ops[];
  OpPointer *_cbops[];
  

  Mmu* _mmu;

  // registers
  unsigned char _a;
  unsigned char _b;
  unsigned char _c;
  unsigned char _d;
  unsigned char _e;
  unsigned char _h;
  unsigned char _l;
  unsigned char _f;
  unsigned short _sp;
  unsigned short _pc;
  unsigned int _ticks;

  unsigned int _totalTicks;

  void LDrr_bb() { _b = _b; _ticks = 1; }
  void LDrr_bc() { _b = _c; _ticks = 1; }
  void LDrr_bd() { _b = _d; _ticks = 1; }
  void LDrr_be() { _b = _e; _ticks = 1; }
  void LDrr_bh() { _b = _h; _ticks = 1; }
  void LDrr_bl() { _b = _l; _ticks = 1; }
  void LDrr_ba() { _b = _a; _ticks = 1; }

  void LDrr_cb() { _c = _b; _ticks = 1; }
  void LDrr_cc() { _c = _c; _ticks = 1; }
  void LDrr_cd() { _c = _d; _ticks = 1; }
  void LDrr_ce() { _c = _e; _ticks = 1; }
  void LDrr_ch() { _c = _h; _ticks = 1; }
  void LDrr_cl() { _c = _l; _ticks = 1; }
  void LDrr_ca() { _c = _a; _ticks = 1; }

  void LDrr_db() { _d = _b; _ticks = 1; }
  void LDrr_dc() { _d = _c; _ticks = 1; }
  void LDrr_dd() { _d = _d; _ticks = 1; }
  void LDrr_de() { _d = _e; _ticks = 1; }
  void LDrr_dh() { _d = _h; _ticks = 1; }
  void LDrr_dl() { _d = _l; _ticks = 1; }
  void LDrr_da() { _d = _a; _ticks = 1; }

  void LDrr_eb() { _e = _b; _ticks = 1; }
  void LDrr_ec() { _e = _c; _ticks = 1; }
  void LDrr_ed() { _e = _d; _ticks = 1; }
  void LDrr_ee() { _e = _e; _ticks = 1; }
  void LDrr_eh() { _e = _h; _ticks = 1; }
  void LDrr_el() { _e = _l; _ticks = 1; }
  void LDrr_ea() { _e = _a; _ticks = 1; }

  void LDrr_hb() { _h = _b; _ticks = 1; }
  void LDrr_hc() { _h = _c; _ticks = 1; }
  void LDrr_hd() { _h = _d; _ticks = 1; }
  void LDrr_he() { _h = _e; _ticks = 1; }
  void LDrr_hh() { _h = _h; _ticks = 1; }
  void LDrr_hl() { _h = _l; _ticks = 1; }
  void LDrr_ha() { _h = _a; _ticks = 1; }

  void LDrr_lb() { _l = _b; _ticks = 1; }
  void LDrr_lc() { _l = _c; _ticks = 1; }
  void LDrr_ld() { _l = _d; _ticks = 1; }
  void LDrr_le() { _l = _e; _ticks = 1; }
  void LDrr_lh() { _l = _h; _ticks = 1; }
  void LDrr_ll() { _l = _l; _ticks = 1; }
  void LDrr_la() { _l = _a; _ticks = 1; }

  void LDrr_ab() { _a = _b; _ticks = 1; }
  void LDrr_ac() { _a = _c; _ticks = 1; }
  void LDrr_ad() { _a = _d; _ticks = 1; }
  void LDrr_ae() { _a = _e; _ticks = 1; }
  void LDrr_ah() { _a = _h; _ticks = 1; }
  void LDrr_al() { _a = _l; _ticks = 1; }
  void LDrr_aa() { _a = _a; _ticks = 1; }




};
