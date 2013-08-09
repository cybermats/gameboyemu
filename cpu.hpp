#pragma once

#include "mmu.hpp"

class Cpu
{
public:
  Cpu(Mmu* mmu);

  
  void reset();
  void execNext();


private:

  typedef void(Cpu::*OpPointer)();
  
  static OpPointer _ops[];
  static OpPointer _cbops[];
   

  Mmu* _mmu;

  // registers
  short _a;
  unsigned char _b;
  unsigned char _c;
  unsigned char _d;
  unsigned char _e;
  unsigned char _h;
  unsigned char _l;
  unsigned char _f;
  unsigned short _sp;
  unsigned short _pc;


  short _ra;
  unsigned char _rb;
  unsigned char _rc;
  unsigned char _rd;
  unsigned char _re;
  unsigned char _rh;
  unsigned char _rl;
  unsigned char _rf;


  unsigned int _ticks;
  unsigned int _totalTicks;

  unsigned char _halt;
  unsigned char _ime;
  unsigned char _stop;

  void rsv()
  {
    _ra = _a;
    _rb = _b;
    _rc = _c;
    _rd = _d;
    _re = _e;
    _rh = _h;
    _rl = _l;
  }

  void rrs()
  {
    _a = _ra;
    _b = _rb;
    _c = _rc;
    _d = _rd;
    _e = _re;
    _h = _rh;
    _l = _rl;
  }


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


  void LDrHLm_b() { _b=_mmu->readByte((_h<<8)+_l); _ticks=2; }
  void LDrHLm_c() { _c=_mmu->readByte((_h<<8)+_l); _ticks=2; }
  void LDrHLm_d() { _d=_mmu->readByte((_h<<8)+_l); _ticks=2; }
  void LDrHLm_e() { _e=_mmu->readByte((_h<<8)+_l); _ticks=2; }
  void LDrHLm_h() { _h=_mmu->readByte((_h<<8)+_l); _ticks=2; }
  void LDrHLm_l() { _l=_mmu->readByte((_h<<8)+_l); _ticks=2; }
  void LDrHLm_a() { _a=_mmu->readByte((_h<<8)+_l); _ticks=2; }

  void LDHLmr_b() { _mmu->writeByte((_h<<8)+_l,_b); _ticks=2; }
  void LDHLmr_c() { _mmu->writeByte((_h<<8)+_l,_c); _ticks=2; }
  void LDHLmr_d() { _mmu->writeByte((_h<<8)+_l,_d); _ticks=2; }
  void LDHLmr_e() { _mmu->writeByte((_h<<8)+_l,_e); _ticks=2; }
  void LDHLmr_h() { _mmu->writeByte((_h<<8)+_l,_h); _ticks=2; }
  void LDHLmr_l() { _mmu->writeByte((_h<<8)+_l,_l); _ticks=2; }
  void LDHLmr_a() { _mmu->writeByte((_h<<8)+_l,_a); _ticks=2; }

  void LDrn_b() { _b=_mmu->readByte(_pc); _pc++; _ticks=2; }
  void LDrn_c() { _c=_mmu->readByte(_pc); _pc++; _ticks=2; }
  void LDrn_d() { _d=_mmu->readByte(_pc); _pc++; _ticks=2; }
  void LDrn_e() { _e=_mmu->readByte(_pc); _pc++; _ticks=2; }
  void LDrn_h() { _h=_mmu->readByte(_pc); _pc++; _ticks=2; }
  void LDrn_l() { _l=_mmu->readByte(_pc); _pc++; _ticks=2; }
  void LDrn_a() { _a=_mmu->readByte(_pc); _pc++; _ticks=2; }

  void LDHLmn() { _mmu->writeByte((_h<<8)+_l, _mmu->readByte(_pc)); _pc++; _ticks=3; }

  void LDBCmA() { _mmu->writeByte((_b<<8)+_c, _a); _ticks=2; }
  void LDDEmA() { _mmu->writeByte((_d<<8)+_e, _a); _ticks=2; }

  void LDmmA() { _mmu->writeByte(_mmu->readWord(_pc), _a); _pc+=2; _ticks=4; }
  void LDAmm() { _a=_mmu->readByte(_mmu->readWord(_pc)); _pc+=2; _ticks=4; }

  void LDABCm() { _a=_mmu->readByte((_b<<8)+_c); _ticks=2; }
  void LDADEm() { _a=_mmu->readByte((_d<<8)+_e); _ticks=2; }


  void LDBCnn() { _c=_mmu->readByte(_pc); _b=_mmu->readByte(_pc+1); _pc+=2; _ticks=3; }
  void LDDEnn() { _e=_mmu->readByte(_pc); _d=_mmu->readByte(_pc+1); _pc+=2; _ticks=3; }
  void LDHLnn() { _l=_mmu->readByte(_pc); _h=_mmu->readByte(_pc+1); _pc+=2; _ticks=3; }
  void LDSPnn() { _sp=_mmu->readWord(_pc); _pc+=2; _ticks=3; }

  void LDHLmm() { unsigned short i=_mmu->readWord(_pc); _pc+=2; _l=_mmu->readByte(i); _h=_mmu->readByte(i+1); _ticks=5; }
  void LDmmHL() { unsigned short i=_mmu->readWord(_pc); _pc+=2; _mmu->writeWord(i,(_h<<8)+_l); _ticks=5; }

  void LDmmSP() { unsigned short i=_mmu->readWord(_pc); _pc+=2; _mmu->writeWord(i, _sp); _ticks=5; }

  void LDHLIA() { _mmu->writeByte((_h<<8)+_l, _a); _l=(_l+1)&255; if(!_l) _h=(_h+1)&255; _ticks=2; }
  void LDAHLI() { _a=_mmu->readByte((_h<<8)+_l); _l=(_l+1)&255; if(!_l) _h=(_h+1)&255; _ticks=2; }

  void LDHLDA() { _mmu->writeByte((_h<<8)+_l, _a); _l=(_l-1)&255; if(_l==255) _h=(_h-1)&255; _ticks=2; }
  void LDAHLD() { _a=_mmu->readByte((_h<<8)+_l); _l=(_l-1)&255; if(_l==255) _h=(_h-1)&255; _ticks=2; }

  void LDAIOn() { _a=_mmu->readByte(0xFF00+_mmu->readByte(_pc)); _pc++; _ticks=3; }
  void LDIOnA() { _mmu->writeByte(0xFF00+_mmu->readByte(_pc),_a); _pc++; _ticks=3; }
  void LDAIOC() { _a=_mmu->readByte(0xFF00+_c); _ticks=2; }
  void LDIOCA() { _mmu->writeByte(0xFF00+_c,_a); _ticks=2; }

  void LDHLSPn() { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; i+=_sp; _h=(i>>8)&255; _l=i&255; _ticks=3; }

  void SWAPr_b() { unsigned char tr=_b; _b=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_b?0:0x80; _ticks=1; }
  void SWAPr_c() { unsigned char tr=_c; _c=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_c?0:0x80; _ticks=1; }
  void SWAPr_d() { unsigned char tr=_d; _d=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_d?0:0x80; _ticks=1; }
  void SWAPr_e() { unsigned char tr=_e; _e=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_e?0:0x80; _ticks=1; }
  void SWAPr_h() { unsigned char tr=_h; _h=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_h?0:0x80; _ticks=1; }
  void SWAPr_l() { unsigned char tr=_l; _l=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_l?0:0x80; _ticks=1; }
  void SWAPr_a() { unsigned char tr=_a; _a=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_a?0:0x80; _ticks=1; }

  /*--- Data processing ---*/
  void ADDr_b() { unsigned char a=_a; _a+=_b; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_b^a)&0x10) _f|=0x20; _ticks=1; }
  void ADDr_c() { unsigned char a=_a; _a+=_c; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_c^a)&0x10) _f|=0x20; _ticks=1; }
  void ADDr_d() { unsigned char a=_a; _a+=_d; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_d^a)&0x10) _f|=0x20; _ticks=1; }
  void ADDr_e() { unsigned char a=_a; _a+=_e; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_e^a)&0x10) _f|=0x20; _ticks=1; }
  void ADDr_h() { unsigned char a=_a; _a+=_h; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_h^a)&0x10) _f|=0x20; _ticks=1; }
  void ADDr_l() { unsigned char a=_a; _a+=_l; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_l^a)&0x10) _f|=0x20; _ticks=1; }
  void ADDr_a() { unsigned char a=_a; _a+=_a; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_a^a)&0x10) _f|=0x20; _ticks=1; }
  void ADDHL() { unsigned char a=_a; unsigned char m=_mmu->readByte((_h<<8)+_l); _a+=m; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^a^m)&0x10) _f|=0x20; _ticks=2; }
  void ADDn() { unsigned char a=_a; unsigned char m=_mmu->readByte(_pc); _a+=m; _pc++; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^a^m)&0x10) _f|=0x20; _ticks=2; }
  void ADDHLBC() { unsigned int hl=(_h<<8)+_l; hl+=(_b<<8)+_c; if(hl>65535) _f|=0x10; else _f&=0xEF; _h=(hl>>8)&255; _l=hl&255; _ticks=3; }
  void ADDHLDE() { unsigned int hl=(_h<<8)+_l; hl+=(_d<<8)+_e; if(hl>65535) _f|=0x10; else _f&=0xEF; _h=(hl>>8)&255; _l=hl&255; _ticks=3; }
  void ADDHLHL() { unsigned int hl=(_h<<8)+_l; hl+=(_h<<8)+_l; if(hl>65535) _f|=0x10; else _f&=0xEF; _h=(hl>>8)&255; _l=hl&255; _ticks=3; }
  void ADDHLSP() { unsigned int hl=(_h<<8)+_l; hl+=_sp; if(hl>65535) _f|=0x10; else _f&=0xEF; _h=(hl>>8)&255; _l=hl&255; _ticks=3; }
  void ADDSPn() { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _sp+=i; _ticks=4; }

  void ADCr_b() { unsigned char a=_a; _a+=_b; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_b^a)&0x10) _f|=0x20; _ticks=1; }
  void ADCr_c() { unsigned char a=_a; _a+=_c; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_c^a)&0x10) _f|=0x20; _ticks=1; }
  void ADCr_d() { unsigned char a=_a; _a+=_d; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_d^a)&0x10) _f|=0x20; _ticks=1; }
  void ADCr_e() { unsigned char a=_a; _a+=_e; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_e^a)&0x10) _f|=0x20; _ticks=1; }
  void ADCr_h() { unsigned char a=_a; _a+=_h; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_h^a)&0x10) _f|=0x20; _ticks=1; }
  void ADCr_l() { unsigned char a=_a; _a+=_l; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_l^a)&0x10) _f|=0x20; _ticks=1; }
  void ADCr_a() { unsigned char a=_a; _a+=_a; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_a^a)&0x10) _f|=0x20; _ticks=1; }
  void ADCHL() { unsigned char a=_a; unsigned char m=_mmu->readByte((_h<<8)+_l); _a+=m; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^m^a)&0x10) _f|=0x20; _ticks=2; }
  void ADCn() { unsigned char a=_a; unsigned char m=_mmu->readByte(_pc); _a+=m; _pc++; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^m^a)&0x10) _f|=0x20; _ticks=2; }

  void SUBr_b() { unsigned char a=_a; _a-=_b; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_b^a)&0x10) _f|=0x20; _ticks=1; }
  void SUBr_c() { unsigned char a=_a; _a-=_c; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_c^a)&0x10) _f|=0x20; _ticks=1; }
  void SUBr_d() { unsigned char a=_a; _a-=_d; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_d^a)&0x10) _f|=0x20; _ticks=1; }
  void SUBr_e() { unsigned char a=_a; _a-=_e; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_e^a)&0x10) _f|=0x20; _ticks=1; }
  void SUBr_h() { unsigned char a=_a; _a-=_h; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_h^a)&0x10) _f|=0x20; _ticks=1; }
  void SUBr_l() { unsigned char a=_a; _a-=_l; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_l^a)&0x10) _f|=0x20; _ticks=1; }
  void SUBr_a() { unsigned char a=_a; _a-=_a; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_a^a)&0x10) _f|=0x20; _ticks=1; }
  void SUBHL() { unsigned char a=_a; unsigned char m=_mmu->readByte((_h<<8)+_l); _a-=m; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^m^a)&0x10) _f|=0x20; _ticks=2; }
  void SUBn() { unsigned char a=_a; unsigned char m=_mmu->readByte(_pc); _a-=m; _pc++; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^m^a)&0x10) _f|=0x20; _ticks=2; }

  void SBCr_b() { unsigned char a=_a; _a-=_b; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_b^a)&0x10) _f|=0x20; _ticks=1; }
  void SBCr_c() { unsigned char a=_a; _a-=_c; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_c^a)&0x10) _f|=0x20; _ticks=1; }
  void SBCr_d() { unsigned char a=_a; _a-=_d; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_d^a)&0x10) _f|=0x20; _ticks=1; }
  void SBCr_e() { unsigned char a=_a; _a-=_e; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_e^a)&0x10) _f|=0x20; _ticks=1; }
  void SBCr_h() { unsigned char a=_a; _a-=_h; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_h^a)&0x10) _f|=0x20; _ticks=1; }
  void SBCr_l() { unsigned char a=_a; _a-=_l; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_l^a)&0x10) _f|=0x20; _ticks=1; }
  void SBCr_a() { unsigned char a=_a; _a-=_a; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_a^a)&0x10) _f|=0x20; _ticks=1; }
  void SBCHL() { unsigned char a=_a; unsigned char m=_mmu->readByte((_h<<8)+_l); _a-=m; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^m^a)&0x10) _f|=0x20; _ticks=2; }
  void SBCn() { unsigned char a=_a; unsigned char m=_mmu->readByte(_pc); _a-=m; _pc++; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^m^a)&0x10) _f|=0x20; _ticks=2; }

  void CPr_b() { short i=_a; i-=_b; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_b^i)&0x10) _f|=0x20; _ticks=1; }
  void CPr_c() { short i=_a; i-=_c; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_c^i)&0x10) _f|=0x20; _ticks=1; }
  void CPr_d() { short i=_a; i-=_d; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_d^i)&0x10) _f|=0x20; _ticks=1; }
  void CPr_e() { short i=_a; i-=_e; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_e^i)&0x10) _f|=0x20; _ticks=1; }
  void CPr_h() { short i=_a; i-=_h; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_h^i)&0x10) _f|=0x20; _ticks=1; }
  void CPr_l() { short i=_a; i-=_l; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_l^i)&0x10) _f|=0x20; _ticks=1; }
  void CPr_a() { short i=_a; i-=_a; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_a^i)&0x10) _f|=0x20; _ticks=1; }
  void CPHL() { short i=_a; unsigned char m=_mmu->readByte((_h<<8)+_l); i-=m; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^i^m)&0x10) _f|=0x20; _ticks=2; }
  void CPn() { short i=_a; unsigned char m=_mmu->readByte(_pc); i-=m; _pc++; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^i^m)&0x10) _f|=0x20; _ticks=2; }

  void DAA() { short a=_a; if((_f&0x20)||((_a&15)>9)) _a+=6; _f&=0xEF; if((_f&0x20)||(a>0x99)) { _a+=0x60; _f|=0x10; } _ticks=1; }

  void ANDr_b() { _a&=_b; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ANDr_c() { _a&=_c; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ANDr_d() { _a&=_d; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ANDr_e() { _a&=_e; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ANDr_h() { _a&=_h; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ANDr_l() { _a&=_l; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ANDr_a() { _a&=_a; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ANDHL() { _a&=_mmu->readByte((_h<<8)+_l); _a&=255; _f=_a?0:0x80; _ticks=2; }
  void ANDn() { _a&=_mmu->readByte(_pc); _pc++; _a&=255; _f=_a?0:0x80; _ticks=2; }

  void ORr_b() { _a|=_b; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ORr_c() { _a|=_c; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ORr_d() { _a|=_d; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ORr_e() { _a|=_e; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ORr_h() { _a|=_h; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ORr_l() { _a|=_l; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ORr_a() { _a|=_a; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void ORHL() { _a|=_mmu->readByte((_h<<8)+_l); _a&=255; _f=_a?0:0x80; _ticks=2; }
  void ORn() { _a|=_mmu->readByte(_pc); _pc++; _a&=255; _f=_a?0:0x80; _ticks=2; }

  void XORr_b() { _a^=_b; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void XORr_c() { _a^=_c; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void XORr_d() { _a^=_d; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void XORr_e() { _a^=_e; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void XORr_h() { _a^=_h; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void XORr_l() { _a^=_l; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void XORr_a() { _a^=_a; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void XORHL() { _a^=_mmu->readByte((_h<<8)+_l); _a&=255; _f=_a?0:0x80; _ticks=2; }
  void XORn() { _a^=_mmu->readByte(_pc); _pc++; _a&=255; _f=_a?0:0x80; _ticks=2; }

  void INCr_b() { _b++; _b&=255; _f=_b?0:0x80; _ticks=1; }
  void INCr_c() { _c++; _c&=255; _f=_c?0:0x80; _ticks=1; }
  void INCr_d() { _d++; _d&=255; _f=_d?0:0x80; _ticks=1; }
  void INCr_e() { _e++; _e&=255; _f=_e?0:0x80; _ticks=1; }
  void INCr_h() { _h++; _h&=255; _f=_h?0:0x80; _ticks=1; }
  void INCr_l() { _l++; _l&=255; _f=_l?0:0x80; _ticks=1; }
  void INCr_a() { _a++; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void INCHLm() { unsigned char i=_mmu->readByte((_h<<8)+_l)+1; i&=255; _mmu->writeByte((_h<<8)+_l,i); _f=i?0:0x80; _ticks=3; }

  void DECr_b() { _b--; _b&=255; _f=_b?0:0x80; _ticks=1; }
  void DECr_c() { _c--; _c&=255; _f=_c?0:0x80; _ticks=1; }
  void DECr_d() { _d--; _d&=255; _f=_d?0:0x80; _ticks=1; }
  void DECr_e() { _e--; _e&=255; _f=_e?0:0x80; _ticks=1; }
  void DECr_h() { _h--; _h&=255; _f=_h?0:0x80; _ticks=1; }
  void DECr_l() { _l--; _l&=255; _f=_l?0:0x80; _ticks=1; }
  void DECr_a() { _a--; _a&=255; _f=_a?0:0x80; _ticks=1; }
  void DECHLm() { unsigned char i=_mmu->readByte((_h<<8)+_l)-1; i&=255; _mmu->writeByte((_h<<8)+_l,i); _f=i?0:0x80; _ticks=3; }

  void INCBC() { _c=(_c+1)&255; if(!_c) _b=(_b+1)&255; _ticks=1; }
  void INCDE() { _e=(_e+1)&255; if(!_e) _d=(_d+1)&255; _ticks=1; }
  void INCHL() { _l=(_l+1)&255; if(!_l) _h=(_h+1)&255; _ticks=1; }
  void INCSP() { _sp=(_sp+1)&65535; _ticks=1; }

  void DECBC() { _c=(_c-1)&255; if(_c==255) _b=(_b-1)&255; _ticks=1; }
  void DECDE() { _e=(_e-1)&255; if(_e==255) _d=(_d-1)&255; _ticks=1; }
  void DECHL() { _l=(_l-1)&255; if(_l==255) _h=(_h-1)&255; _ticks=1; }
  void DECSP() { _sp=(_sp-1)&65535; _ticks=1; }

  /*--- Bit manipulation ---*/
  void BIT0b() { _f&=0x1F; _f|=0x20; _f=(_b&0x01)?0:0x80; _ticks=2; }
  void BIT0c() { _f&=0x1F; _f|=0x20; _f=(_c&0x01)?0:0x80; _ticks=2; }
  void BIT0d() { _f&=0x1F; _f|=0x20; _f=(_d&0x01)?0:0x80; _ticks=2; }
  void BIT0e() { _f&=0x1F; _f|=0x20; _f=(_e&0x01)?0:0x80; _ticks=2; }
  void BIT0h() { _f&=0x1F; _f|=0x20; _f=(_h&0x01)?0:0x80; _ticks=2; }
  void BIT0l() { _f&=0x1F; _f|=0x20; _f=(_l&0x01)?0:0x80; _ticks=2; }
  void BIT0a() { _f&=0x1F; _f|=0x20; _f=(_a&0x01)?0:0x80; _ticks=2; }
  void BIT0m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x01)?0:0x80; _ticks=3; }

  void RES0b() { _b&=0xFE; _ticks=2; }
  void RES0c() { _c&=0xFE; _ticks=2; }
  void RES0d() { _d&=0xFE; _ticks=2; }
  void RES0e() { _e&=0xFE; _ticks=2; }
  void RES0h() { _h&=0xFE; _ticks=2; }
  void RES0l() { _l&=0xFE; _ticks=2; }
  void RES0a() { _a&=0xFE; _ticks=2; }
  void RES0m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xFE; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void SET0b() { _b|=0x01; _ticks=2; }
  void SET0c() { _b|=0x01; _ticks=2; }
  void SET0d() { _b|=0x01; _ticks=2; }
  void SET0e() { _b|=0x01; _ticks=2; }
  void SET0h() { _b|=0x01; _ticks=2; }
  void SET0l() { _b|=0x01; _ticks=2; }
  void SET0a() { _b|=0x01; _ticks=2; }
  void SET0m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x01; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void BIT1b() { _f&=0x1F; _f|=0x20; _f=(_b&0x02)?0:0x80; _ticks=2; }
  void BIT1c() { _f&=0x1F; _f|=0x20; _f=(_c&0x02)?0:0x80; _ticks=2; }
  void BIT1d() { _f&=0x1F; _f|=0x20; _f=(_d&0x02)?0:0x80; _ticks=2; }
  void BIT1e() { _f&=0x1F; _f|=0x20; _f=(_e&0x02)?0:0x80; _ticks=2; }
  void BIT1h() { _f&=0x1F; _f|=0x20; _f=(_h&0x02)?0:0x80; _ticks=2; }
  void BIT1l() { _f&=0x1F; _f|=0x20; _f=(_l&0x02)?0:0x80; _ticks=2; }
  void BIT1a() { _f&=0x1F; _f|=0x20; _f=(_a&0x02)?0:0x80; _ticks=2; }
  void BIT1m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x02)?0:0x80; _ticks=3; }

  void RES1b() { _b&=0xFD; _ticks=2; }
  void RES1c() { _c&=0xFD; _ticks=2; }
  void RES1d() { _d&=0xFD; _ticks=2; }
  void RES1e() { _e&=0xFD; _ticks=2; }
  void RES1h() { _h&=0xFD; _ticks=2; }
  void RES1l() { _l&=0xFD; _ticks=2; }
  void RES1a() { _a&=0xFD; _ticks=2; }
  void RES1m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xFD; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void SET1b() { _b|=0x02; _ticks=2; }
  void SET1c() { _b|=0x02; _ticks=2; }
  void SET1d() { _b|=0x02; _ticks=2; }
  void SET1e() { _b|=0x02; _ticks=2; }
  void SET1h() { _b|=0x02; _ticks=2; }
  void SET1l() { _b|=0x02; _ticks=2; }
  void SET1a() { _b|=0x02; _ticks=2; }
  void SET1m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x02; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void BIT2b() { _f&=0x1F; _f|=0x20; _f=(_b&0x04)?0:0x80; _ticks=2; }
  void BIT2c() { _f&=0x1F; _f|=0x20; _f=(_c&0x04)?0:0x80; _ticks=2; }
  void BIT2d() { _f&=0x1F; _f|=0x20; _f=(_d&0x04)?0:0x80; _ticks=2; }
  void BIT2e() { _f&=0x1F; _f|=0x20; _f=(_e&0x04)?0:0x80; _ticks=2; }
  void BIT2h() { _f&=0x1F; _f|=0x20; _f=(_h&0x04)?0:0x80; _ticks=2; }
  void BIT2l() { _f&=0x1F; _f|=0x20; _f=(_l&0x04)?0:0x80; _ticks=2; }
  void BIT2a() { _f&=0x1F; _f|=0x20; _f=(_a&0x04)?0:0x80; _ticks=2; }
  void BIT2m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x04)?0:0x80; _ticks=3; }

  void RES2b() { _b&=0xFB; _ticks=2; }
  void RES2c() { _c&=0xFB; _ticks=2; }
  void RES2d() { _d&=0xFB; _ticks=2; }
  void RES2e() { _e&=0xFB; _ticks=2; }
  void RES2h() { _h&=0xFB; _ticks=2; }
  void RES2l() { _l&=0xFB; _ticks=2; }
  void RES2a() { _a&=0xFB; _ticks=2; }
  void RES2m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xFB; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void SET2b() { _b|=0x04; _ticks=2; }
  void SET2c() { _b|=0x04; _ticks=2; }
  void SET2d() { _b|=0x04; _ticks=2; }
  void SET2e() { _b|=0x04; _ticks=2; }
  void SET2h() { _b|=0x04; _ticks=2; }
  void SET2l() { _b|=0x04; _ticks=2; }
  void SET2a() { _b|=0x04; _ticks=2; }
  void SET2m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x04; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void BIT3b() { _f&=0x1F; _f|=0x20; _f=(_b&0x08)?0:0x80; _ticks=2; }
  void BIT3c() { _f&=0x1F; _f|=0x20; _f=(_c&0x08)?0:0x80; _ticks=2; }
  void BIT3d() { _f&=0x1F; _f|=0x20; _f=(_d&0x08)?0:0x80; _ticks=2; }
  void BIT3e() { _f&=0x1F; _f|=0x20; _f=(_e&0x08)?0:0x80; _ticks=2; }
  void BIT3h() { _f&=0x1F; _f|=0x20; _f=(_h&0x08)?0:0x80; _ticks=2; }
  void BIT3l() { _f&=0x1F; _f|=0x20; _f=(_l&0x08)?0:0x80; _ticks=2; }
  void BIT3a() { _f&=0x1F; _f|=0x20; _f=(_a&0x08)?0:0x80; _ticks=2; }
  void BIT3m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x08)?0:0x80; _ticks=3; }

  void RES3b() { _b&=0xF7; _ticks=2; }
  void RES3c() { _c&=0xF7; _ticks=2; }
  void RES3d() { _d&=0xF7; _ticks=2; }
  void RES3e() { _e&=0xF7; _ticks=2; }
  void RES3h() { _h&=0xF7; _ticks=2; }
  void RES3l() { _l&=0xF7; _ticks=2; }
  void RES3a() { _a&=0xF7; _ticks=2; }
  void RES3m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xF7; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void SET3b() { _b|=0x08; _ticks=2; }
  void SET3c() { _b|=0x08; _ticks=2; }
  void SET3d() { _b|=0x08; _ticks=2; }
  void SET3e() { _b|=0x08; _ticks=2; }
  void SET3h() { _b|=0x08; _ticks=2; }
  void SET3l() { _b|=0x08; _ticks=2; }
  void SET3a() { _b|=0x08; _ticks=2; }
  void SET3m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x08; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void BIT4b() { _f&=0x1F; _f|=0x20; _f=(_b&0x10)?0:0x80; _ticks=2; }
  void BIT4c() { _f&=0x1F; _f|=0x20; _f=(_c&0x10)?0:0x80; _ticks=2; }
  void BIT4d() { _f&=0x1F; _f|=0x20; _f=(_d&0x10)?0:0x80; _ticks=2; }
  void BIT4e() { _f&=0x1F; _f|=0x20; _f=(_e&0x10)?0:0x80; _ticks=2; }
  void BIT4h() { _f&=0x1F; _f|=0x20; _f=(_h&0x10)?0:0x80; _ticks=2; }
  void BIT4l() { _f&=0x1F; _f|=0x20; _f=(_l&0x10)?0:0x80; _ticks=2; }
  void BIT4a() { _f&=0x1F; _f|=0x20; _f=(_a&0x10)?0:0x80; _ticks=2; }
  void BIT4m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x10)?0:0x80; _ticks=3; }

  void RES4b() { _b&=0xEF; _ticks=2; }
  void RES4c() { _c&=0xEF; _ticks=2; }
  void RES4d() { _d&=0xEF; _ticks=2; }
  void RES4e() { _e&=0xEF; _ticks=2; }
  void RES4h() { _h&=0xEF; _ticks=2; }
  void RES4l() { _l&=0xEF; _ticks=2; }
  void RES4a() { _a&=0xEF; _ticks=2; }
  void RES4m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xEF; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void SET4b() { _b|=0x10; _ticks=2; }
  void SET4c() { _b|=0x10; _ticks=2; }
  void SET4d() { _b|=0x10; _ticks=2; }
  void SET4e() { _b|=0x10; _ticks=2; }
  void SET4h() { _b|=0x10; _ticks=2; }
  void SET4l() { _b|=0x10; _ticks=2; }
  void SET4a() { _b|=0x10; _ticks=2; }
  void SET4m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x10; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void BIT5b() { _f&=0x1F; _f|=0x20; _f=(_b&0x20)?0:0x80; _ticks=2; }
  void BIT5c() { _f&=0x1F; _f|=0x20; _f=(_c&0x20)?0:0x80; _ticks=2; }
  void BIT5d() { _f&=0x1F; _f|=0x20; _f=(_d&0x20)?0:0x80; _ticks=2; }
  void BIT5e() { _f&=0x1F; _f|=0x20; _f=(_e&0x20)?0:0x80; _ticks=2; }
  void BIT5h() { _f&=0x1F; _f|=0x20; _f=(_h&0x20)?0:0x80; _ticks=2; }
  void BIT5l() { _f&=0x1F; _f|=0x20; _f=(_l&0x20)?0:0x80; _ticks=2; }
  void BIT5a() { _f&=0x1F; _f|=0x20; _f=(_a&0x20)?0:0x80; _ticks=2; }
  void BIT5m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x20)?0:0x80; _ticks=3; }

  void RES5b() { _b&=0xDF; _ticks=2; }
  void RES5c() { _c&=0xDF; _ticks=2; }
  void RES5d() { _d&=0xDF; _ticks=2; }
  void RES5e() { _e&=0xDF; _ticks=2; }
  void RES5h() { _h&=0xDF; _ticks=2; }
  void RES5l() { _l&=0xDF; _ticks=2; }
  void RES5a() { _a&=0xDF; _ticks=2; }
  void RES5m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xDF; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void SET5b() { _b|=0x20; _ticks=2; }
  void SET5c() { _b|=0x20; _ticks=2; }
  void SET5d() { _b|=0x20; _ticks=2; }
  void SET5e() { _b|=0x20; _ticks=2; }
  void SET5h() { _b|=0x20; _ticks=2; }
  void SET5l() { _b|=0x20; _ticks=2; }
  void SET5a() { _b|=0x20; _ticks=2; }
  void SET5m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x20; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void BIT6b() { _f&=0x1F; _f|=0x20; _f=(_b&0x40)?0:0x80; _ticks=2; }
  void BIT6c() { _f&=0x1F; _f|=0x20; _f=(_c&0x40)?0:0x80; _ticks=2; }
  void BIT6d() { _f&=0x1F; _f|=0x20; _f=(_d&0x40)?0:0x80; _ticks=2; }
  void BIT6e() { _f&=0x1F; _f|=0x20; _f=(_e&0x40)?0:0x80; _ticks=2; }
  void BIT6h() { _f&=0x1F; _f|=0x20; _f=(_h&0x40)?0:0x80; _ticks=2; }
  void BIT6l() { _f&=0x1F; _f|=0x20; _f=(_l&0x40)?0:0x80; _ticks=2; }
  void BIT6a() { _f&=0x1F; _f|=0x20; _f=(_a&0x40)?0:0x80; _ticks=2; }
  void BIT6m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x40)?0:0x80; _ticks=3; }

  void RES6b() { _b&=0xBF; _ticks=2; }
  void RES6c() { _c&=0xBF; _ticks=2; }
  void RES6d() { _d&=0xBF; _ticks=2; }
  void RES6e() { _e&=0xBF; _ticks=2; }
  void RES6h() { _h&=0xBF; _ticks=2; }
  void RES6l() { _l&=0xBF; _ticks=2; }
  void RES6a() { _a&=0xBF; _ticks=2; }
  void RES6m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xBF; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void SET6b() { _b|=0x40; _ticks=2; }
  void SET6c() { _b|=0x40; _ticks=2; }
  void SET6d() { _b|=0x40; _ticks=2; }
  void SET6e() { _b|=0x40; _ticks=2; }
  void SET6h() { _b|=0x40; _ticks=2; }
  void SET6l() { _b|=0x40; _ticks=2; }
  void SET6a() { _b|=0x40; _ticks=2; }
  void SET6m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x40; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void BIT7b() { _f&=0x1F; _f|=0x20; _f=(_b&0x80)?0:0x80; _ticks=2; }
  void BIT7c() { _f&=0x1F; _f|=0x20; _f=(_c&0x80)?0:0x80; _ticks=2; }
  void BIT7d() { _f&=0x1F; _f|=0x20; _f=(_d&0x80)?0:0x80; _ticks=2; }
  void BIT7e() { _f&=0x1F; _f|=0x20; _f=(_e&0x80)?0:0x80; _ticks=2; }
  void BIT7h() { _f&=0x1F; _f|=0x20; _f=(_h&0x80)?0:0x80; _ticks=2; }
  void BIT7l() { _f&=0x1F; _f|=0x20; _f=(_l&0x80)?0:0x80; _ticks=2; }
  void BIT7a() { _f&=0x1F; _f|=0x20; _f=(_a&0x80)?0:0x80; _ticks=2; }
  void BIT7m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x80)?0:0x80; _ticks=3; }

  void RES7b() { _b&=0x7F; _ticks=2; }
  void RES7c() { _c&=0x7F; _ticks=2; }
  void RES7d() { _d&=0x7F; _ticks=2; }
  void RES7e() { _e&=0x7F; _ticks=2; }
  void RES7h() { _h&=0x7F; _ticks=2; }
  void RES7l() { _l&=0x7F; _ticks=2; }
  void RES7a() { _a&=0x7F; _ticks=2; }
  void RES7m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0x7F; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void SET7b() { _b|=0x80; _ticks=2; }
  void SET7c() { _b|=0x80; _ticks=2; }
  void SET7d() { _b|=0x80; _ticks=2; }
  void SET7e() { _b|=0x80; _ticks=2; }
  void SET7h() { _b|=0x80; _ticks=2; }
  void SET7l() { _b|=0x80; _ticks=2; }
  void SET7a() { _b|=0x80; _ticks=2; }
  void SET7m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x80; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  void RLA() { unsigned char ci=_f&0x10?1:0; unsigned char co=_a&0x80?0x10:0; _a=(_a<<1)+ci; _a&=255; _f=(_f&0xEF)+co; _ticks=1; }
  void RLCA() { unsigned char ci=_a&0x80?1:0; unsigned char co=_a&0x80?0x10:0; _a=(_a<<1)+ci; _a&=255; _f=(_f&0xEF)+co; _ticks=1; }
  void RRA() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_a&1?0x10:0; _a=(_a>>1)+ci; _a&=255; _f=(_f&0xEF)+co; _ticks=1; }
  void RRCA() { unsigned char ci=_a&1?0x80:0; unsigned char co=_a&1?0x10:0; _a=(_a>>1)+ci; _a&=255; _f=(_f&0xEF)+co; _ticks=1; }

  void RLr_b() { unsigned char ci=_f&0x10?1:0; unsigned char co=_b&0x80?0x10:0; _b=(_b<<1)+ci; _b&=255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLr_c() { unsigned char ci=_f&0x10?1:0; unsigned char co=_c&0x80?0x10:0; _c=(_c<<1)+ci; _c&=255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLr_d() { unsigned char ci=_f&0x10?1:0; unsigned char co=_d&0x80?0x10:0; _d=(_d<<1)+ci; _d&=255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLr_e() { unsigned char ci=_f&0x10?1:0; unsigned char co=_e&0x80?0x10:0; _e=(_e<<1)+ci; _e&=255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLr_h() { unsigned char ci=_f&0x10?1:0; unsigned char co=_h&0x80?0x10:0; _h=(_h<<1)+ci; _h&=255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLr_l() { unsigned char ci=_f&0x10?1:0; unsigned char co=_l&0x80?0x10:0; _l=(_l<<1)+ci; _l&=255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLr_a() { unsigned char ci=_f&0x10?1:0; unsigned char co=_a&0x80?0x10:0; _a=(_a<<1)+ci; _a&=255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLHL() { unsigned char i=_mmu->readByte((_h<<8)+_l); unsigned char ci=_f&0x10?1:0; unsigned char co=i&0x80?0x10:0; i=(i<<1)+ci; i&=255; _f=(i)?0:0x80; _mmu->writeByte((_h<<8)+_l,i); _f=(_f&0xEF)+co; _ticks=4; }

  void RLCr_b() { unsigned char ci=_b&0x80?1:0; unsigned char co=_b&0x80?0x10:0; _b=(_b<<1)+ci; _b&=255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLCr_c() { unsigned char ci=_c&0x80?1:0; unsigned char co=_c&0x80?0x10:0; _c=(_c<<1)+ci; _c&=255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLCr_d() { unsigned char ci=_d&0x80?1:0; unsigned char co=_d&0x80?0x10:0; _d=(_d<<1)+ci; _d&=255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLCr_e() { unsigned char ci=_e&0x80?1:0; unsigned char co=_e&0x80?0x10:0; _e=(_e<<1)+ci; _e&=255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLCr_h() { unsigned char ci=_h&0x80?1:0; unsigned char co=_h&0x80?0x10:0; _h=(_h<<1)+ci; _h&=255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLCr_l() { unsigned char ci=_l&0x80?1:0; unsigned char co=_l&0x80?0x10:0; _l=(_l<<1)+ci; _l&=255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLCr_a() { unsigned char ci=_a&0x80?1:0; unsigned char co=_a&0x80?0x10:0; _a=(_a<<1)+ci; _a&=255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RLCHL() { unsigned char i=_mmu->readByte((_h<<8)+_l); unsigned char ci=i&0x80?1:0; unsigned char co=i&0x80?0x10:0; i=(i<<1)+ci; i&=255; _f=(i)?0:0x80; _mmu->writeByte((_h<<8)+_l,i); _f=(_f&0xEF)+co; _ticks=4; }

  void RRr_b() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_b&1?0x10:0; _b=(_b>>1)+ci; _b&=255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRr_c() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_c&1?0x10:0; _c=(_c>>1)+ci; _c&=255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRr_d() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_d&1?0x10:0; _d=(_d>>1)+ci; _d&=255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRr_e() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_e&1?0x10:0; _e=(_e>>1)+ci; _e&=255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRr_h() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_h&1?0x10:0; _h=(_h>>1)+ci; _h&=255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRr_l() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_l&1?0x10:0; _l=(_l>>1)+ci; _l&=255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRr_a() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_a&1?0x10:0; _a=(_a>>1)+ci; _a&=255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRHL() { unsigned char i=_mmu->readByte((_h<<8)+_l); unsigned char ci=_f&0x10?0x80:0; unsigned char co=i&1?0x10:0; i=(i>>1)+ci; i&=255; _mmu->writeByte((_h<<8)+_l,i); _f=(i)?0:0x80; _f=(_f&0xEF)+co; _ticks=4; }

  void RRCr_b() { unsigned char ci=_b&1?0x80:0; unsigned char co=_b&1?0x10:0; _b=(_b>>1)+ci; _b&=255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRCr_c() { unsigned char ci=_c&1?0x80:0; unsigned char co=_c&1?0x10:0; _c=(_c>>1)+ci; _c&=255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRCr_d() { unsigned char ci=_d&1?0x80:0; unsigned char co=_d&1?0x10:0; _d=(_d>>1)+ci; _d&=255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRCr_e() { unsigned char ci=_e&1?0x80:0; unsigned char co=_e&1?0x10:0; _e=(_e>>1)+ci; _e&=255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRCr_h() { unsigned char ci=_h&1?0x80:0; unsigned char co=_h&1?0x10:0; _h=(_h>>1)+ci; _h&=255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRCr_l() { unsigned char ci=_l&1?0x80:0; unsigned char co=_l&1?0x10:0; _l=(_l>>1)+ci; _l&=255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRCr_a() { unsigned char ci=_a&1?0x80:0; unsigned char co=_a&1?0x10:0; _a=(_a>>1)+ci; _a&=255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void RRCHL() { unsigned char i=_mmu->readByte((_h<<8)+_l); unsigned char ci=i&1?0x80:0; unsigned char co=i&1?0x10:0; i=(i>>1)+ci; i&=255; _mmu->writeByte((_h<<8)+_l,i); _f=(i)?0:0x80; _f=(_f&0xEF)+co; _ticks=4; }

  void SLAr_b() { unsigned char co=_b&0x80?0x10:0; _b=(_b<<1)&255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SLAr_c() { unsigned char co=_c&0x80?0x10:0; _c=(_c<<1)&255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SLAr_d() { unsigned char co=_d&0x80?0x10:0; _d=(_d<<1)&255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SLAr_e() { unsigned char co=_e&0x80?0x10:0; _e=(_e<<1)&255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SLAr_h() { unsigned char co=_h&0x80?0x10:0; _h=(_h<<1)&255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SLAr_l() { unsigned char co=_l&0x80?0x10:0; _l=(_l<<1)&255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SLAr_a() { unsigned char co=_a&0x80?0x10:0; _a=(_a<<1)&255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }

  void SLLr_b() { unsigned char co=_b&0x80?0x10:0; _b=((_b<<1)&255)+1; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SLLr_c() { unsigned char co=_c&0x80?0x10:0; _c=((_c<<1)&255)+1; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SLLr_d() { unsigned char co=_d&0x80?0x10:0; _d=((_d<<1)&255)+1; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SLLr_e() { unsigned char co=_e&0x80?0x10:0; _e=((_e<<1)&255)+1; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SLLr_h() { unsigned char co=_h&0x80?0x10:0; _h=((_h<<1)&255)+1; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SLLr_l() { unsigned char co=_l&0x80?0x10:0; _l=((_l<<1)&255)+1; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SLLr_a() { unsigned char co=_a&0x80?0x10:0; _a=((_a<<1)&255)+1; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }

  void SRAr_b() { unsigned char ci=_b&0x80; unsigned char co=_b&1?0x10:0; _b=((_b>>1)+ci)&255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SRAr_c() { unsigned char ci=_c&0x80; unsigned char co=_c&1?0x10:0; _c=((_c>>1)+ci)&255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SRAr_d() { unsigned char ci=_d&0x80; unsigned char co=_d&1?0x10:0; _d=((_d>>1)+ci)&255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SRAr_e() { unsigned char ci=_e&0x80; unsigned char co=_e&1?0x10:0; _e=((_e>>1)+ci)&255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SRAr_h() { unsigned char ci=_h&0x80; unsigned char co=_h&1?0x10:0; _h=((_h>>1)+ci)&255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SRAr_l() { unsigned char ci=_l&0x80; unsigned char co=_l&1?0x10:0; _l=((_l>>1)+ci)&255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SRAr_a() { unsigned char ci=_a&0x80; unsigned char co=_a&1?0x10:0; _a=((_a>>1)+ci)&255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }

  void SRLr_b() { unsigned char co=_b&1?0x10:0; _b=(_b>>1)&255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SRLr_c() { unsigned char co=_c&1?0x10:0; _c=(_c>>1)&255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SRLr_d() { unsigned char co=_d&1?0x10:0; _d=(_d>>1)&255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SRLr_e() { unsigned char co=_e&1?0x10:0; _e=(_e>>1)&255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SRLr_h() { unsigned char co=_h&1?0x10:0; _h=(_h>>1)&255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SRLr_l() { unsigned char co=_l&1?0x10:0; _l=(_l>>1)&255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  void SRLr_a() { unsigned char co=_a&1?0x10:0; _a=(_a>>1)&255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }

  void CPL() { _a ^= 255; _f=_a?0:0x80; _ticks=1; }
  void NEG() { _a=0-_a; _f=(_a<0)?0x10:0; _a&=255; if(!_a) _f|=0x80; _ticks=2; }

  void CCF() { unsigned char ci=_f&0x10?0:0x10; _f=(_f&0xEF)+ci; _ticks=1; }
  void SCF() { _f|=0x10; _ticks=1; }

  /*--- Stack ---*/
  void PUSHBC() { _sp--; _mmu->writeByte(_sp,_b); _sp--; _mmu->writeByte(_sp,_c); _ticks=3; }
  void PUSHDE() { _sp--; _mmu->writeByte(_sp,_d); _sp--; _mmu->writeByte(_sp,_e); _ticks=3; }
  void PUSHHL() { _sp--; _mmu->writeByte(_sp,_h); _sp--; _mmu->writeByte(_sp,_l); _ticks=3; }
  void PUSHAF() { _sp--; _mmu->writeByte(_sp,_a); _sp--; _mmu->writeByte(_sp,_f); _ticks=3; }

  void POPBC() { _c=_mmu->readByte(_sp); _sp++; _b=_mmu->readByte(_sp); _sp++; _ticks=3; }
  void POPDE() { _e=_mmu->readByte(_sp); _sp++; _d=_mmu->readByte(_sp); _sp++; _ticks=3; }
  void POPHL() { _l=_mmu->readByte(_sp); _sp++; _h=_mmu->readByte(_sp); _sp++; _ticks=3; }
  void POPAF() { _f=_mmu->readByte(_sp); _sp++; _a=_mmu->readByte(_sp); _sp++; _ticks=3; }

  /*--- Jump ---*/
  void JPnn() { _pc = _mmu->readWord(_pc); _ticks=3; }
  void JPHL() { _pc=(_h<<8)+_l; _ticks=1; }
  void JPNZnn() { _ticks=3; if((_f&0x80)==0x00) { _pc=_mmu->readWord(_pc); _ticks++; } else _pc+=2; }
  void JPZnn()  { _ticks=3; if((_f&0x80)==0x80) { _pc=_mmu->readWord(_pc); _ticks++; } else _pc+=2; }
  void JPNCnn() { _ticks=3; if((_f&0x10)==0x00) { _pc=_mmu->readWord(_pc); _ticks++; } else _pc+=2; }
  void JPCnn()  { _ticks=3; if((_f&0x10)==0x10) { _pc=_mmu->readWord(_pc); _ticks++; } else _pc+=2; }

  void JRn() { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _ticks=2; _pc+=i; _ticks++; }
  void JRNZn() { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _ticks=2; if((_f&0x80)==0x00) { _pc+=i; _ticks++; } }
  void JRZn()  { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _ticks=2; if((_f&0x80)==0x80) { _pc+=i; _ticks++; } }
  void JRNCn() { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _ticks=2; if((_f&0x10)==0x00) { _pc+=i; _ticks++; } }
  void JRCn()  { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _ticks=2; if((_f&0x10)==0x10) { _pc+=i; _ticks++; } }

  void DJNZn() { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _ticks=2; _b--; if(_b) { _pc+=i; _ticks++; } }

  void CALLnn() { _sp-=2; _mmu->writeWord(_sp,_pc+2); _pc=_mmu->readWord(_pc); _ticks=5; }
  void CALLNZnn() { _ticks=3; if((_f&0x80)==0x00) { _sp-=2; _mmu->writeWord(_sp,_pc+2); _pc=_mmu->readWord(_pc); _ticks+=2; } else _pc+=2; }
  void CALLZnn() { _ticks=3; if((_f&0x80)==0x80) { _sp-=2; _mmu->writeWord(_sp,_pc+2); _pc=_mmu->readWord(_pc); _ticks+=2; } else _pc+=2; }
  void CALLNCnn() { _ticks=3; if((_f&0x10)==0x00) { _sp-=2; _mmu->writeWord(_sp,_pc+2); _pc=_mmu->readWord(_pc); _ticks+=2; } else _pc+=2; }
  void CALLCnn() { _ticks=3; if((_f&0x10)==0x10) { _sp-=2; _mmu->writeWord(_sp,_pc+2); _pc=_mmu->readWord(_pc); _ticks+=2; } else _pc+=2; }


    void RET() { _pc=_mmu->readWord(_sp); _sp+=2; _ticks=3; }
    void RETI() { _ime=1; rrs(); _pc=_mmu->readWord(_sp); _sp+=2; _ticks=3; }
    void RETNZ() { _ticks=1; if((_f&0x80)==0x00) { _pc=_mmu->readWord(_sp); _sp+=2; _ticks+=2; } }
    void RETZ() { _ticks=1; if((_f&0x80)==0x80) { _pc=_mmu->readWord(_sp); _sp+=2; _ticks+=2; } }
    void RETNC() { _ticks=1; if((_f&0x10)==0x00) { _pc=_mmu->readWord(_sp); _sp+=2; _ticks+=2; } }
    void RETC() { _ticks=1; if((_f&0x10)==0x10) { _pc=_mmu->readWord(_sp); _sp+=2; _ticks+=2; } }

    void RST00() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x00; _ticks=3; }
    void RST08() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x08; _ticks=3; }
    void RST10() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x10; _ticks=3; }
    void RST18() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x18; _ticks=3; }
    void RST20() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x20; _ticks=3; }
    void RST28() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x28; _ticks=3; }
    void RST30() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x30; _ticks=3; }
    void RST38() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x38; _ticks=3; }
    void RST40() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x40; _ticks=3; }
    void RST48() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x48; _ticks=3; }
    void RST50() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x50; _ticks=3; }
    void RST58() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x58; _ticks=3; }
    void RST60() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x60; _ticks=3; }

    void NOP() { _ticks=1; }
    void HALT() { _halt=1; _ticks=1; }

    void DI() { _ime=0; _ticks=1; }
    void EI() { _ime=1; _ticks=1; }

    void MAPcb() {
      unsigned char i=_mmu->readByte(_pc); _pc++;
      _pc &= 65535;
      if(_cbops[i])
	(this->*(_cbops[i]))();
      // (*_cbops[i])();
      throw "unknown operand called from MAPcb";
      //      else console.log(i);
    }

    void XX() {
      /*Undefined map entry*/
      unsigned short opc = _pc-1;
      throw "Unimplemented instruction";
      //      LOG.out('Z80', 'Unimplemented instruction at $'+opc.toString(16)+', stopping.');
      _stop=1;
    }
};
