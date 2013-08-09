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


  inline void LDrr_bb() { _b = _b; _ticks = 1; }
  inline void LDrr_bc() { _b = _c; _ticks = 1; }
  inline void LDrr_bd() { _b = _d; _ticks = 1; }
  inline void LDrr_be() { _b = _e; _ticks = 1; }
  inline void LDrr_bh() { _b = _h; _ticks = 1; }
  inline void LDrr_bl() { _b = _l; _ticks = 1; }
  inline void LDrr_ba() { _b = _a; _ticks = 1; }

  inline void LDrr_cb() { _c = _b; _ticks = 1; }
  inline void LDrr_cc() { _c = _c; _ticks = 1; }
  inline void LDrr_cd() { _c = _d; _ticks = 1; }
  inline void LDrr_ce() { _c = _e; _ticks = 1; }
  inline void LDrr_ch() { _c = _h; _ticks = 1; }
  inline void LDrr_cl() { _c = _l; _ticks = 1; }
  inline void LDrr_ca() { _c = _a; _ticks = 1; }

  inline void LDrr_db() { _d = _b; _ticks = 1; }
  inline void LDrr_dc() { _d = _c; _ticks = 1; }
  inline void LDrr_dd() { _d = _d; _ticks = 1; }
  inline void LDrr_de() { _d = _e; _ticks = 1; }
  inline void LDrr_dh() { _d = _h; _ticks = 1; }
  inline void LDrr_dl() { _d = _l; _ticks = 1; }
  inline void LDrr_da() { _d = _a; _ticks = 1; }

  inline void LDrr_eb() { _e = _b; _ticks = 1; }
  inline void LDrr_ec() { _e = _c; _ticks = 1; }
  inline void LDrr_ed() { _e = _d; _ticks = 1; }
  inline void LDrr_ee() { _e = _e; _ticks = 1; }
  inline void LDrr_eh() { _e = _h; _ticks = 1; }
  inline void LDrr_el() { _e = _l; _ticks = 1; }
  inline void LDrr_ea() { _e = _a; _ticks = 1; }

  inline void LDrr_hb() { _h = _b; _ticks = 1; }
  inline void LDrr_hc() { _h = _c; _ticks = 1; }
  inline void LDrr_hd() { _h = _d; _ticks = 1; }
  inline void LDrr_he() { _h = _e; _ticks = 1; }
  inline void LDrr_hh() { _h = _h; _ticks = 1; }
  inline void LDrr_hl() { _h = _l; _ticks = 1; }
  inline void LDrr_ha() { _h = _a; _ticks = 1; }

  inline void LDrr_lb() { _l = _b; _ticks = 1; }
  inline void LDrr_lc() { _l = _c; _ticks = 1; }
  inline void LDrr_ld() { _l = _d; _ticks = 1; }
  inline void LDrr_le() { _l = _e; _ticks = 1; }
  inline void LDrr_lh() { _l = _h; _ticks = 1; }
  inline void LDrr_ll() { _l = _l; _ticks = 1; }
  inline void LDrr_la() { _l = _a; _ticks = 1; }

  inline void LDrr_ab() { _a = _b; _ticks = 1; }
  inline void LDrr_ac() { _a = _c; _ticks = 1; }
  inline void LDrr_ad() { _a = _d; _ticks = 1; }
  inline void LDrr_ae() { _a = _e; _ticks = 1; }
  inline void LDrr_ah() { _a = _h; _ticks = 1; }
  inline void LDrr_al() { _a = _l; _ticks = 1; }
  inline void LDrr_aa() { _a = _a; _ticks = 1; }


  inline void LDrHLm_b() { _b=_mmu->readByte((_h<<8)+_l); _ticks=2; }
  inline void LDrHLm_c() { _c=_mmu->readByte((_h<<8)+_l); _ticks=2; }
  inline void LDrHLm_d() { _d=_mmu->readByte((_h<<8)+_l); _ticks=2; }
  inline void LDrHLm_e() { _e=_mmu->readByte((_h<<8)+_l); _ticks=2; }
  inline void LDrHLm_h() { _h=_mmu->readByte((_h<<8)+_l); _ticks=2; }
  inline void LDrHLm_l() { _l=_mmu->readByte((_h<<8)+_l); _ticks=2; }
  inline void LDrHLm_a() { _a=_mmu->readByte((_h<<8)+_l); _ticks=2; }

  inline void LDHLmr_b() { _mmu->writeByte((_h<<8)+_l,_b); _ticks=2; }
  inline void LDHLmr_c() { _mmu->writeByte((_h<<8)+_l,_c); _ticks=2; }
  inline void LDHLmr_d() { _mmu->writeByte((_h<<8)+_l,_d); _ticks=2; }
  inline void LDHLmr_e() { _mmu->writeByte((_h<<8)+_l,_e); _ticks=2; }
  inline void LDHLmr_h() { _mmu->writeByte((_h<<8)+_l,_h); _ticks=2; }
  inline void LDHLmr_l() { _mmu->writeByte((_h<<8)+_l,_l); _ticks=2; }
  inline void LDHLmr_a() { _mmu->writeByte((_h<<8)+_l,_a); _ticks=2; }

  inline void LDrn_b() { _b=_mmu->readByte(_pc); _pc++; _ticks=2; }
  inline void LDrn_c() { _c=_mmu->readByte(_pc); _pc++; _ticks=2; }
  inline void LDrn_d() { _d=_mmu->readByte(_pc); _pc++; _ticks=2; }
  inline void LDrn_e() { _e=_mmu->readByte(_pc); _pc++; _ticks=2; }
  inline void LDrn_h() { _h=_mmu->readByte(_pc); _pc++; _ticks=2; }
  inline void LDrn_l() { _l=_mmu->readByte(_pc); _pc++; _ticks=2; }
  inline void LDrn_a() { _a=_mmu->readByte(_pc); _pc++; _ticks=2; }

  inline void LDHLmn() { _mmu->writeByte((_h<<8)+_l, _mmu->readByte(_pc)); _pc++; _ticks=3; }

  inline void LDBCmA() { _mmu->writeByte((_b<<8)+_c, _a); _ticks=2; }
  inline void LDDEmA() { _mmu->writeByte((_d<<8)+_e, _a); _ticks=2; }

  inline void LDmmA() { _mmu->writeByte(_mmu->readWord(_pc), _a); _pc+=2; _ticks=4; }
  inline void LDAmm() { _a=_mmu->readByte(_mmu->readWord(_pc)); _pc+=2; _ticks=4; }

  inline void LDABCm() { _a=_mmu->readByte((_b<<8)+_c); _ticks=2; }
  inline void LDADEm() { _a=_mmu->readByte((_d<<8)+_e); _ticks=2; }


  inline void LDBCnn() { _c=_mmu->readByte(_pc); _b=_mmu->readByte(_pc+1); _pc+=2; _ticks=3; }
  inline void LDDEnn() { _e=_mmu->readByte(_pc); _d=_mmu->readByte(_pc+1); _pc+=2; _ticks=3; }
  inline void LDHLnn() { _l=_mmu->readByte(_pc); _h=_mmu->readByte(_pc+1); _pc+=2; _ticks=3; }
  inline void LDSPnn() { _sp=_mmu->readWord(_pc); _pc+=2; _ticks=3; }

  inline void LDHLmm() { unsigned short i=_mmu->readWord(_pc); _pc+=2; _l=_mmu->readByte(i); _h=_mmu->readByte(i+1); _ticks=5; }
  inline void LDmmHL() { unsigned short i=_mmu->readWord(_pc); _pc+=2; _mmu->writeWord(i,(_h<<8)+_l); _ticks=5; }

  inline void LDmmSP() { unsigned short i=_mmu->readWord(_pc); _pc+=2; _mmu->writeWord(i, _sp); _ticks=5; }

  inline void LDHLIA() { _mmu->writeByte((_h<<8)+_l, _a); _l=(_l+1)&255; if(!_l) _h=(_h+1)&255; _ticks=2; }
  inline void LDAHLI() { _a=_mmu->readByte((_h<<8)+_l); _l=(_l+1)&255; if(!_l) _h=(_h+1)&255; _ticks=2; }

  inline void LDHLDA() { _mmu->writeByte((_h<<8)+_l, _a); _l=(_l-1)&255; if(_l==255) _h=(_h-1)&255; _ticks=2; }
  inline void LDAHLD() { _a=_mmu->readByte((_h<<8)+_l); _l=(_l-1)&255; if(_l==255) _h=(_h-1)&255; _ticks=2; }

  inline void LDAIOn() { _a=_mmu->readByte(0xFF00+_mmu->readByte(_pc)); _pc++; _ticks=3; }
  inline void LDIOnA() { _mmu->writeByte(0xFF00+_mmu->readByte(_pc),_a); _pc++; _ticks=3; }
  inline void LDAIOC() { _a=_mmu->readByte(0xFF00+_c); _ticks=2; }
  inline void LDIOCA() { _mmu->writeByte(0xFF00+_c,_a); _ticks=2; }

  inline void LDHLSPn() { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; i+=_sp; _h=(i>>8)&255; _l=i&255; _ticks=3; }

  inline void SWAPr_b() { unsigned char tr=_b; _b=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_b?0:0x80; _ticks=1; }
  inline void SWAPr_c() { unsigned char tr=_c; _c=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_c?0:0x80; _ticks=1; }
  inline void SWAPr_d() { unsigned char tr=_d; _d=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_d?0:0x80; _ticks=1; }
  inline void SWAPr_e() { unsigned char tr=_e; _e=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_e?0:0x80; _ticks=1; }
  inline void SWAPr_h() { unsigned char tr=_h; _h=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_h?0:0x80; _ticks=1; }
  inline void SWAPr_l() { unsigned char tr=_l; _l=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_l?0:0x80; _ticks=1; }
  inline void SWAPr_a() { unsigned char tr=_a; _a=((tr&0xF)<<4)|((tr&0xF0)>>4); _f=_a?0:0x80; _ticks=1; }

  /*--- Data processing ---*/
  inline void ADDr_b() { unsigned char a=_a; _a+=_b; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_b^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADDr_c() { unsigned char a=_a; _a+=_c; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_c^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADDr_d() { unsigned char a=_a; _a+=_d; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_d^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADDr_e() { unsigned char a=_a; _a+=_e; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_e^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADDr_h() { unsigned char a=_a; _a+=_h; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_h^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADDr_l() { unsigned char a=_a; _a+=_l; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_l^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADDr_a() { unsigned char a=_a; _a+=_a; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_a^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADDHL() { unsigned char a=_a; unsigned char m=_mmu->readByte((_h<<8)+_l); _a+=m; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^a^m)&0x10) _f|=0x20; _ticks=2; }
  inline void ADDn() { unsigned char a=_a; unsigned char m=_mmu->readByte(_pc); _a+=m; _pc++; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^a^m)&0x10) _f|=0x20; _ticks=2; }
  inline void ADDHLBC() { unsigned int hl=(_h<<8)+_l; hl+=(_b<<8)+_c; if(hl>65535) _f|=0x10; else _f&=0xEF; _h=(hl>>8)&255; _l=hl&255; _ticks=3; }
  inline void ADDHLDE() { unsigned int hl=(_h<<8)+_l; hl+=(_d<<8)+_e; if(hl>65535) _f|=0x10; else _f&=0xEF; _h=(hl>>8)&255; _l=hl&255; _ticks=3; }
  inline void ADDHLHL() { unsigned int hl=(_h<<8)+_l; hl+=(_h<<8)+_l; if(hl>65535) _f|=0x10; else _f&=0xEF; _h=(hl>>8)&255; _l=hl&255; _ticks=3; }
  inline void ADDHLSP() { unsigned int hl=(_h<<8)+_l; hl+=_sp; if(hl>65535) _f|=0x10; else _f&=0xEF; _h=(hl>>8)&255; _l=hl&255; _ticks=3; }
  inline void ADDSPn() { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _sp+=i; _ticks=4; }

  inline void ADCr_b() { unsigned char a=_a; _a+=_b; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_b^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADCr_c() { unsigned char a=_a; _a+=_c; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_c^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADCr_d() { unsigned char a=_a; _a+=_d; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_d^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADCr_e() { unsigned char a=_a; _a+=_e; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_e^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADCr_h() { unsigned char a=_a; _a+=_h; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_h^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADCr_l() { unsigned char a=_a; _a+=_l; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_l^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADCr_a() { unsigned char a=_a; _a+=_a; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^_a^a)&0x10) _f|=0x20; _ticks=1; }
  inline void ADCHL() { unsigned char a=_a; unsigned char m=_mmu->readByte((_h<<8)+_l); _a+=m; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^m^a)&0x10) _f|=0x20; _ticks=2; }
  inline void ADCn() { unsigned char a=_a; unsigned char m=_mmu->readByte(_pc); _a+=m; _pc++; _a+=(_f&0x10)?1:0; _f=(_a>255)?0x10:0; _a&=255; if(!_a) _f|=0x80; if((_a^m^a)&0x10) _f|=0x20; _ticks=2; }

  inline void SUBr_b() { unsigned char a=_a; _a-=_b; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_b^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SUBr_c() { unsigned char a=_a; _a-=_c; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_c^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SUBr_d() { unsigned char a=_a; _a-=_d; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_d^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SUBr_e() { unsigned char a=_a; _a-=_e; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_e^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SUBr_h() { unsigned char a=_a; _a-=_h; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_h^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SUBr_l() { unsigned char a=_a; _a-=_l; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_l^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SUBr_a() { unsigned char a=_a; _a-=_a; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_a^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SUBHL() { unsigned char a=_a; unsigned char m=_mmu->readByte((_h<<8)+_l); _a-=m; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^m^a)&0x10) _f|=0x20; _ticks=2; }
  inline void SUBn() { unsigned char a=_a; unsigned char m=_mmu->readByte(_pc); _a-=m; _pc++; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^m^a)&0x10) _f|=0x20; _ticks=2; }

  inline void SBCr_b() { unsigned char a=_a; _a-=_b; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_b^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SBCr_c() { unsigned char a=_a; _a-=_c; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_c^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SBCr_d() { unsigned char a=_a; _a-=_d; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_d^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SBCr_e() { unsigned char a=_a; _a-=_e; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_e^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SBCr_h() { unsigned char a=_a; _a-=_h; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_h^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SBCr_l() { unsigned char a=_a; _a-=_l; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_l^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SBCr_a() { unsigned char a=_a; _a-=_a; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^_a^a)&0x10) _f|=0x20; _ticks=1; }
  inline void SBCHL() { unsigned char a=_a; unsigned char m=_mmu->readByte((_h<<8)+_l); _a-=m; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^m^a)&0x10) _f|=0x20; _ticks=2; }
  inline void SBCn() { unsigned char a=_a; unsigned char m=_mmu->readByte(_pc); _a-=m; _pc++; _a-=(_f&0x10)?1:0; _f=(_a<0)?0x50:0x40; _a&=255; if(!_a) _f|=0x80; if((_a^m^a)&0x10) _f|=0x20; _ticks=2; }

  inline void CPr_b() { short i=_a; i-=_b; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_b^i)&0x10) _f|=0x20; _ticks=1; }
  inline void CPr_c() { short i=_a; i-=_c; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_c^i)&0x10) _f|=0x20; _ticks=1; }
  inline void CPr_d() { short i=_a; i-=_d; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_d^i)&0x10) _f|=0x20; _ticks=1; }
  inline void CPr_e() { short i=_a; i-=_e; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_e^i)&0x10) _f|=0x20; _ticks=1; }
  inline void CPr_h() { short i=_a; i-=_h; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_h^i)&0x10) _f|=0x20; _ticks=1; }
  inline void CPr_l() { short i=_a; i-=_l; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_l^i)&0x10) _f|=0x20; _ticks=1; }
  inline void CPr_a() { short i=_a; i-=_a; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^_a^i)&0x10) _f|=0x20; _ticks=1; }
  inline void CPHL() { short i=_a; unsigned char m=_mmu->readByte((_h<<8)+_l); i-=m; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^i^m)&0x10) _f|=0x20; _ticks=2; }
  inline void CPn() { short i=_a; unsigned char m=_mmu->readByte(_pc); i-=m; _pc++; _f=(i<0)?0x50:0x40; i&=255; if(!i) _f|=0x80; if((_a^i^m)&0x10) _f|=0x20; _ticks=2; }

  inline void DAA() { short a=_a; if((_f&0x20)||((_a&15)>9)) _a+=6; _f&=0xEF; if((_f&0x20)||(a>0x99)) { _a+=0x60; _f|=0x10; } _ticks=1; }

  inline void ANDr_b() { _a&=_b; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ANDr_c() { _a&=_c; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ANDr_d() { _a&=_d; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ANDr_e() { _a&=_e; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ANDr_h() { _a&=_h; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ANDr_l() { _a&=_l; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ANDr_a() { _a&=_a; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ANDHL() { _a&=_mmu->readByte((_h<<8)+_l); _a&=255; _f=_a?0:0x80; _ticks=2; }
  inline void ANDn() { _a&=_mmu->readByte(_pc); _pc++; _a&=255; _f=_a?0:0x80; _ticks=2; }

  inline void ORr_b() { _a|=_b; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ORr_c() { _a|=_c; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ORr_d() { _a|=_d; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ORr_e() { _a|=_e; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ORr_h() { _a|=_h; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ORr_l() { _a|=_l; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ORr_a() { _a|=_a; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void ORHL() { _a|=_mmu->readByte((_h<<8)+_l); _a&=255; _f=_a?0:0x80; _ticks=2; }
  inline void ORn() { _a|=_mmu->readByte(_pc); _pc++; _a&=255; _f=_a?0:0x80; _ticks=2; }

  inline void XORr_b() { _a^=_b; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void XORr_c() { _a^=_c; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void XORr_d() { _a^=_d; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void XORr_e() { _a^=_e; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void XORr_h() { _a^=_h; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void XORr_l() { _a^=_l; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void XORr_a() { _a^=_a; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void XORHL() { _a^=_mmu->readByte((_h<<8)+_l); _a&=255; _f=_a?0:0x80; _ticks=2; }
  inline void XORn() { _a^=_mmu->readByte(_pc); _pc++; _a&=255; _f=_a?0:0x80; _ticks=2; }

  inline void INCr_b() { _b++; _b&=255; _f=_b?0:0x80; _ticks=1; }
  inline void INCr_c() { _c++; _c&=255; _f=_c?0:0x80; _ticks=1; }
  inline void INCr_d() { _d++; _d&=255; _f=_d?0:0x80; _ticks=1; }
  inline void INCr_e() { _e++; _e&=255; _f=_e?0:0x80; _ticks=1; }
  inline void INCr_h() { _h++; _h&=255; _f=_h?0:0x80; _ticks=1; }
  inline void INCr_l() { _l++; _l&=255; _f=_l?0:0x80; _ticks=1; }
  inline void INCr_a() { _a++; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void INCHLm() { unsigned char i=_mmu->readByte((_h<<8)+_l)+1; i&=255; _mmu->writeByte((_h<<8)+_l,i); _f=i?0:0x80; _ticks=3; }

  inline void DECr_b() { _b--; _b&=255; _f=_b?0:0x80; _ticks=1; }
  inline void DECr_c() { _c--; _c&=255; _f=_c?0:0x80; _ticks=1; }
  inline void DECr_d() { _d--; _d&=255; _f=_d?0:0x80; _ticks=1; }
  inline void DECr_e() { _e--; _e&=255; _f=_e?0:0x80; _ticks=1; }
  inline void DECr_h() { _h--; _h&=255; _f=_h?0:0x80; _ticks=1; }
  inline void DECr_l() { _l--; _l&=255; _f=_l?0:0x80; _ticks=1; }
  inline void DECr_a() { _a--; _a&=255; _f=_a?0:0x80; _ticks=1; }
  inline void DECHLm() { unsigned char i=_mmu->readByte((_h<<8)+_l)-1; i&=255; _mmu->writeByte((_h<<8)+_l,i); _f=i?0:0x80; _ticks=3; }

  inline void INCBC() { _c=(_c+1)&255; if(!_c) _b=(_b+1)&255; _ticks=1; }
  inline void INCDE() { _e=(_e+1)&255; if(!_e) _d=(_d+1)&255; _ticks=1; }
  inline void INCHL() { _l=(_l+1)&255; if(!_l) _h=(_h+1)&255; _ticks=1; }
  inline void INCSP() { _sp=(_sp+1)&65535; _ticks=1; }

  inline void DECBC() { _c=(_c-1)&255; if(_c==255) _b=(_b-1)&255; _ticks=1; }
  inline void DECDE() { _e=(_e-1)&255; if(_e==255) _d=(_d-1)&255; _ticks=1; }
  inline void DECHL() { _l=(_l-1)&255; if(_l==255) _h=(_h-1)&255; _ticks=1; }
  inline void DECSP() { _sp=(_sp-1)&65535; _ticks=1; }

  /*--- Bit manipulation ---*/
  inline void BIT0b() { _f&=0x1F; _f|=0x20; _f=(_b&0x01)?0:0x80; _ticks=2; }
  inline void BIT0c() { _f&=0x1F; _f|=0x20; _f=(_c&0x01)?0:0x80; _ticks=2; }
  inline void BIT0d() { _f&=0x1F; _f|=0x20; _f=(_d&0x01)?0:0x80; _ticks=2; }
  inline void BIT0e() { _f&=0x1F; _f|=0x20; _f=(_e&0x01)?0:0x80; _ticks=2; }
  inline void BIT0h() { _f&=0x1F; _f|=0x20; _f=(_h&0x01)?0:0x80; _ticks=2; }
  inline void BIT0l() { _f&=0x1F; _f|=0x20; _f=(_l&0x01)?0:0x80; _ticks=2; }
  inline void BIT0a() { _f&=0x1F; _f|=0x20; _f=(_a&0x01)?0:0x80; _ticks=2; }
  inline void BIT0m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x01)?0:0x80; _ticks=3; }

  inline void RES0b() { _b&=0xFE; _ticks=2; }
  inline void RES0c() { _c&=0xFE; _ticks=2; }
  inline void RES0d() { _d&=0xFE; _ticks=2; }
  inline void RES0e() { _e&=0xFE; _ticks=2; }
  inline void RES0h() { _h&=0xFE; _ticks=2; }
  inline void RES0l() { _l&=0xFE; _ticks=2; }
  inline void RES0a() { _a&=0xFE; _ticks=2; }
  inline void RES0m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xFE; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void SET0b() { _b|=0x01; _ticks=2; }
  inline void SET0c() { _b|=0x01; _ticks=2; }
  inline void SET0d() { _b|=0x01; _ticks=2; }
  inline void SET0e() { _b|=0x01; _ticks=2; }
  inline void SET0h() { _b|=0x01; _ticks=2; }
  inline void SET0l() { _b|=0x01; _ticks=2; }
  inline void SET0a() { _b|=0x01; _ticks=2; }
  inline void SET0m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x01; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void BIT1b() { _f&=0x1F; _f|=0x20; _f=(_b&0x02)?0:0x80; _ticks=2; }
  inline void BIT1c() { _f&=0x1F; _f|=0x20; _f=(_c&0x02)?0:0x80; _ticks=2; }
  inline void BIT1d() { _f&=0x1F; _f|=0x20; _f=(_d&0x02)?0:0x80; _ticks=2; }
  inline void BIT1e() { _f&=0x1F; _f|=0x20; _f=(_e&0x02)?0:0x80; _ticks=2; }
  inline void BIT1h() { _f&=0x1F; _f|=0x20; _f=(_h&0x02)?0:0x80; _ticks=2; }
  inline void BIT1l() { _f&=0x1F; _f|=0x20; _f=(_l&0x02)?0:0x80; _ticks=2; }
  inline void BIT1a() { _f&=0x1F; _f|=0x20; _f=(_a&0x02)?0:0x80; _ticks=2; }
  inline void BIT1m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x02)?0:0x80; _ticks=3; }

  inline void RES1b() { _b&=0xFD; _ticks=2; }
  inline void RES1c() { _c&=0xFD; _ticks=2; }
  inline void RES1d() { _d&=0xFD; _ticks=2; }
  inline void RES1e() { _e&=0xFD; _ticks=2; }
  inline void RES1h() { _h&=0xFD; _ticks=2; }
  inline void RES1l() { _l&=0xFD; _ticks=2; }
  inline void RES1a() { _a&=0xFD; _ticks=2; }
  inline void RES1m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xFD; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void SET1b() { _b|=0x02; _ticks=2; }
  inline void SET1c() { _b|=0x02; _ticks=2; }
  inline void SET1d() { _b|=0x02; _ticks=2; }
  inline void SET1e() { _b|=0x02; _ticks=2; }
  inline void SET1h() { _b|=0x02; _ticks=2; }
  inline void SET1l() { _b|=0x02; _ticks=2; }
  inline void SET1a() { _b|=0x02; _ticks=2; }
  inline void SET1m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x02; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void BIT2b() { _f&=0x1F; _f|=0x20; _f=(_b&0x04)?0:0x80; _ticks=2; }
  inline void BIT2c() { _f&=0x1F; _f|=0x20; _f=(_c&0x04)?0:0x80; _ticks=2; }
  inline void BIT2d() { _f&=0x1F; _f|=0x20; _f=(_d&0x04)?0:0x80; _ticks=2; }
  inline void BIT2e() { _f&=0x1F; _f|=0x20; _f=(_e&0x04)?0:0x80; _ticks=2; }
  inline void BIT2h() { _f&=0x1F; _f|=0x20; _f=(_h&0x04)?0:0x80; _ticks=2; }
  inline void BIT2l() { _f&=0x1F; _f|=0x20; _f=(_l&0x04)?0:0x80; _ticks=2; }
  inline void BIT2a() { _f&=0x1F; _f|=0x20; _f=(_a&0x04)?0:0x80; _ticks=2; }
  inline void BIT2m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x04)?0:0x80; _ticks=3; }

  inline void RES2b() { _b&=0xFB; _ticks=2; }
  inline void RES2c() { _c&=0xFB; _ticks=2; }
  inline void RES2d() { _d&=0xFB; _ticks=2; }
  inline void RES2e() { _e&=0xFB; _ticks=2; }
  inline void RES2h() { _h&=0xFB; _ticks=2; }
  inline void RES2l() { _l&=0xFB; _ticks=2; }
  inline void RES2a() { _a&=0xFB; _ticks=2; }
  inline void RES2m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xFB; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void SET2b() { _b|=0x04; _ticks=2; }
  inline void SET2c() { _b|=0x04; _ticks=2; }
  inline void SET2d() { _b|=0x04; _ticks=2; }
  inline void SET2e() { _b|=0x04; _ticks=2; }
  inline void SET2h() { _b|=0x04; _ticks=2; }
  inline void SET2l() { _b|=0x04; _ticks=2; }
  inline void SET2a() { _b|=0x04; _ticks=2; }
  inline void SET2m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x04; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void BIT3b() { _f&=0x1F; _f|=0x20; _f=(_b&0x08)?0:0x80; _ticks=2; }
  inline void BIT3c() { _f&=0x1F; _f|=0x20; _f=(_c&0x08)?0:0x80; _ticks=2; }
  inline void BIT3d() { _f&=0x1F; _f|=0x20; _f=(_d&0x08)?0:0x80; _ticks=2; }
  inline void BIT3e() { _f&=0x1F; _f|=0x20; _f=(_e&0x08)?0:0x80; _ticks=2; }
  inline void BIT3h() { _f&=0x1F; _f|=0x20; _f=(_h&0x08)?0:0x80; _ticks=2; }
  inline void BIT3l() { _f&=0x1F; _f|=0x20; _f=(_l&0x08)?0:0x80; _ticks=2; }
  inline void BIT3a() { _f&=0x1F; _f|=0x20; _f=(_a&0x08)?0:0x80; _ticks=2; }
  inline void BIT3m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x08)?0:0x80; _ticks=3; }

  inline void RES3b() { _b&=0xF7; _ticks=2; }
  inline void RES3c() { _c&=0xF7; _ticks=2; }
  inline void RES3d() { _d&=0xF7; _ticks=2; }
  inline void RES3e() { _e&=0xF7; _ticks=2; }
  inline void RES3h() { _h&=0xF7; _ticks=2; }
  inline void RES3l() { _l&=0xF7; _ticks=2; }
  inline void RES3a() { _a&=0xF7; _ticks=2; }
  inline void RES3m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xF7; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void SET3b() { _b|=0x08; _ticks=2; }
  inline void SET3c() { _b|=0x08; _ticks=2; }
  inline void SET3d() { _b|=0x08; _ticks=2; }
  inline void SET3e() { _b|=0x08; _ticks=2; }
  inline void SET3h() { _b|=0x08; _ticks=2; }
  inline void SET3l() { _b|=0x08; _ticks=2; }
  inline void SET3a() { _b|=0x08; _ticks=2; }
  inline void SET3m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x08; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void BIT4b() { _f&=0x1F; _f|=0x20; _f=(_b&0x10)?0:0x80; _ticks=2; }
  inline void BIT4c() { _f&=0x1F; _f|=0x20; _f=(_c&0x10)?0:0x80; _ticks=2; }
  inline void BIT4d() { _f&=0x1F; _f|=0x20; _f=(_d&0x10)?0:0x80; _ticks=2; }
  inline void BIT4e() { _f&=0x1F; _f|=0x20; _f=(_e&0x10)?0:0x80; _ticks=2; }
  inline void BIT4h() { _f&=0x1F; _f|=0x20; _f=(_h&0x10)?0:0x80; _ticks=2; }
  inline void BIT4l() { _f&=0x1F; _f|=0x20; _f=(_l&0x10)?0:0x80; _ticks=2; }
  inline void BIT4a() { _f&=0x1F; _f|=0x20; _f=(_a&0x10)?0:0x80; _ticks=2; }
  inline void BIT4m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x10)?0:0x80; _ticks=3; }

  inline void RES4b() { _b&=0xEF; _ticks=2; }
  inline void RES4c() { _c&=0xEF; _ticks=2; }
  inline void RES4d() { _d&=0xEF; _ticks=2; }
  inline void RES4e() { _e&=0xEF; _ticks=2; }
  inline void RES4h() { _h&=0xEF; _ticks=2; }
  inline void RES4l() { _l&=0xEF; _ticks=2; }
  inline void RES4a() { _a&=0xEF; _ticks=2; }
  inline void RES4m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xEF; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void SET4b() { _b|=0x10; _ticks=2; }
  inline void SET4c() { _b|=0x10; _ticks=2; }
  inline void SET4d() { _b|=0x10; _ticks=2; }
  inline void SET4e() { _b|=0x10; _ticks=2; }
  inline void SET4h() { _b|=0x10; _ticks=2; }
  inline void SET4l() { _b|=0x10; _ticks=2; }
  inline void SET4a() { _b|=0x10; _ticks=2; }
  inline void SET4m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x10; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void BIT5b() { _f&=0x1F; _f|=0x20; _f=(_b&0x20)?0:0x80; _ticks=2; }
  inline void BIT5c() { _f&=0x1F; _f|=0x20; _f=(_c&0x20)?0:0x80; _ticks=2; }
  inline void BIT5d() { _f&=0x1F; _f|=0x20; _f=(_d&0x20)?0:0x80; _ticks=2; }
  inline void BIT5e() { _f&=0x1F; _f|=0x20; _f=(_e&0x20)?0:0x80; _ticks=2; }
  inline void BIT5h() { _f&=0x1F; _f|=0x20; _f=(_h&0x20)?0:0x80; _ticks=2; }
  inline void BIT5l() { _f&=0x1F; _f|=0x20; _f=(_l&0x20)?0:0x80; _ticks=2; }
  inline void BIT5a() { _f&=0x1F; _f|=0x20; _f=(_a&0x20)?0:0x80; _ticks=2; }
  inline void BIT5m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x20)?0:0x80; _ticks=3; }

  inline void RES5b() { _b&=0xDF; _ticks=2; }
  inline void RES5c() { _c&=0xDF; _ticks=2; }
  inline void RES5d() { _d&=0xDF; _ticks=2; }
  inline void RES5e() { _e&=0xDF; _ticks=2; }
  inline void RES5h() { _h&=0xDF; _ticks=2; }
  inline void RES5l() { _l&=0xDF; _ticks=2; }
  inline void RES5a() { _a&=0xDF; _ticks=2; }
  inline void RES5m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xDF; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void SET5b() { _b|=0x20; _ticks=2; }
  inline void SET5c() { _b|=0x20; _ticks=2; }
  inline void SET5d() { _b|=0x20; _ticks=2; }
  inline void SET5e() { _b|=0x20; _ticks=2; }
  inline void SET5h() { _b|=0x20; _ticks=2; }
  inline void SET5l() { _b|=0x20; _ticks=2; }
  inline void SET5a() { _b|=0x20; _ticks=2; }
  inline void SET5m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x20; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void BIT6b() { _f&=0x1F; _f|=0x20; _f=(_b&0x40)?0:0x80; _ticks=2; }
  inline void BIT6c() { _f&=0x1F; _f|=0x20; _f=(_c&0x40)?0:0x80; _ticks=2; }
  inline void BIT6d() { _f&=0x1F; _f|=0x20; _f=(_d&0x40)?0:0x80; _ticks=2; }
  inline void BIT6e() { _f&=0x1F; _f|=0x20; _f=(_e&0x40)?0:0x80; _ticks=2; }
  inline void BIT6h() { _f&=0x1F; _f|=0x20; _f=(_h&0x40)?0:0x80; _ticks=2; }
  inline void BIT6l() { _f&=0x1F; _f|=0x20; _f=(_l&0x40)?0:0x80; _ticks=2; }
  inline void BIT6a() { _f&=0x1F; _f|=0x20; _f=(_a&0x40)?0:0x80; _ticks=2; }
  inline void BIT6m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x40)?0:0x80; _ticks=3; }

  inline void RES6b() { _b&=0xBF; _ticks=2; }
  inline void RES6c() { _c&=0xBF; _ticks=2; }
  inline void RES6d() { _d&=0xBF; _ticks=2; }
  inline void RES6e() { _e&=0xBF; _ticks=2; }
  inline void RES6h() { _h&=0xBF; _ticks=2; }
  inline void RES6l() { _l&=0xBF; _ticks=2; }
  inline void RES6a() { _a&=0xBF; _ticks=2; }
  inline void RES6m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0xBF; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void SET6b() { _b|=0x40; _ticks=2; }
  inline void SET6c() { _b|=0x40; _ticks=2; }
  inline void SET6d() { _b|=0x40; _ticks=2; }
  inline void SET6e() { _b|=0x40; _ticks=2; }
  inline void SET6h() { _b|=0x40; _ticks=2; }
  inline void SET6l() { _b|=0x40; _ticks=2; }
  inline void SET6a() { _b|=0x40; _ticks=2; }
  inline void SET6m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x40; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void BIT7b() { _f&=0x1F; _f|=0x20; _f=(_b&0x80)?0:0x80; _ticks=2; }
  inline void BIT7c() { _f&=0x1F; _f|=0x20; _f=(_c&0x80)?0:0x80; _ticks=2; }
  inline void BIT7d() { _f&=0x1F; _f|=0x20; _f=(_d&0x80)?0:0x80; _ticks=2; }
  inline void BIT7e() { _f&=0x1F; _f|=0x20; _f=(_e&0x80)?0:0x80; _ticks=2; }
  inline void BIT7h() { _f&=0x1F; _f|=0x20; _f=(_h&0x80)?0:0x80; _ticks=2; }
  inline void BIT7l() { _f&=0x1F; _f|=0x20; _f=(_l&0x80)?0:0x80; _ticks=2; }
  inline void BIT7a() { _f&=0x1F; _f|=0x20; _f=(_a&0x80)?0:0x80; _ticks=2; }
  inline void BIT7m() { _f&=0x1F; _f|=0x20; _f=(_mmu->readByte((_h<<8)+_l)&0x80)?0:0x80; _ticks=3; }

  inline void RES7b() { _b&=0x7F; _ticks=2; }
  inline void RES7c() { _c&=0x7F; _ticks=2; }
  inline void RES7d() { _d&=0x7F; _ticks=2; }
  inline void RES7e() { _e&=0x7F; _ticks=2; }
  inline void RES7h() { _h&=0x7F; _ticks=2; }
  inline void RES7l() { _l&=0x7F; _ticks=2; }
  inline void RES7a() { _a&=0x7F; _ticks=2; }
  inline void RES7m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i&=0x7F; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void SET7b() { _b|=0x80; _ticks=2; }
  inline void SET7c() { _b|=0x80; _ticks=2; }
  inline void SET7d() { _b|=0x80; _ticks=2; }
  inline void SET7e() { _b|=0x80; _ticks=2; }
  inline void SET7h() { _b|=0x80; _ticks=2; }
  inline void SET7l() { _b|=0x80; _ticks=2; }
  inline void SET7a() { _b|=0x80; _ticks=2; }
  inline void SET7m() { unsigned char i=_mmu->readByte((_h<<8)+_l); i|=0x80; _mmu->writeByte((_h<<8)+_l,i); _ticks=4; }

  inline void RLA() { unsigned char ci=_f&0x10?1:0; unsigned char co=_a&0x80?0x10:0; _a=(_a<<1)+ci; _a&=255; _f=(_f&0xEF)+co; _ticks=1; }
  inline void RLCA() { unsigned char ci=_a&0x80?1:0; unsigned char co=_a&0x80?0x10:0; _a=(_a<<1)+ci; _a&=255; _f=(_f&0xEF)+co; _ticks=1; }
  inline void RRA() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_a&1?0x10:0; _a=(_a>>1)+ci; _a&=255; _f=(_f&0xEF)+co; _ticks=1; }
  inline void RRCA() { unsigned char ci=_a&1?0x80:0; unsigned char co=_a&1?0x10:0; _a=(_a>>1)+ci; _a&=255; _f=(_f&0xEF)+co; _ticks=1; }

  inline void RLr_b() { unsigned char ci=_f&0x10?1:0; unsigned char co=_b&0x80?0x10:0; _b=(_b<<1)+ci; _b&=255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLr_c() { unsigned char ci=_f&0x10?1:0; unsigned char co=_c&0x80?0x10:0; _c=(_c<<1)+ci; _c&=255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLr_d() { unsigned char ci=_f&0x10?1:0; unsigned char co=_d&0x80?0x10:0; _d=(_d<<1)+ci; _d&=255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLr_e() { unsigned char ci=_f&0x10?1:0; unsigned char co=_e&0x80?0x10:0; _e=(_e<<1)+ci; _e&=255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLr_h() { unsigned char ci=_f&0x10?1:0; unsigned char co=_h&0x80?0x10:0; _h=(_h<<1)+ci; _h&=255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLr_l() { unsigned char ci=_f&0x10?1:0; unsigned char co=_l&0x80?0x10:0; _l=(_l<<1)+ci; _l&=255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLr_a() { unsigned char ci=_f&0x10?1:0; unsigned char co=_a&0x80?0x10:0; _a=(_a<<1)+ci; _a&=255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLHL() { unsigned char i=_mmu->readByte((_h<<8)+_l); unsigned char ci=_f&0x10?1:0; unsigned char co=i&0x80?0x10:0; i=(i<<1)+ci; i&=255; _f=(i)?0:0x80; _mmu->writeByte((_h<<8)+_l,i); _f=(_f&0xEF)+co; _ticks=4; }

  inline void RLCr_b() { unsigned char ci=_b&0x80?1:0; unsigned char co=_b&0x80?0x10:0; _b=(_b<<1)+ci; _b&=255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLCr_c() { unsigned char ci=_c&0x80?1:0; unsigned char co=_c&0x80?0x10:0; _c=(_c<<1)+ci; _c&=255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLCr_d() { unsigned char ci=_d&0x80?1:0; unsigned char co=_d&0x80?0x10:0; _d=(_d<<1)+ci; _d&=255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLCr_e() { unsigned char ci=_e&0x80?1:0; unsigned char co=_e&0x80?0x10:0; _e=(_e<<1)+ci; _e&=255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLCr_h() { unsigned char ci=_h&0x80?1:0; unsigned char co=_h&0x80?0x10:0; _h=(_h<<1)+ci; _h&=255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLCr_l() { unsigned char ci=_l&0x80?1:0; unsigned char co=_l&0x80?0x10:0; _l=(_l<<1)+ci; _l&=255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLCr_a() { unsigned char ci=_a&0x80?1:0; unsigned char co=_a&0x80?0x10:0; _a=(_a<<1)+ci; _a&=255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RLCHL() { unsigned char i=_mmu->readByte((_h<<8)+_l); unsigned char ci=i&0x80?1:0; unsigned char co=i&0x80?0x10:0; i=(i<<1)+ci; i&=255; _f=(i)?0:0x80; _mmu->writeByte((_h<<8)+_l,i); _f=(_f&0xEF)+co; _ticks=4; }

  inline void RRr_b() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_b&1?0x10:0; _b=(_b>>1)+ci; _b&=255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRr_c() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_c&1?0x10:0; _c=(_c>>1)+ci; _c&=255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRr_d() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_d&1?0x10:0; _d=(_d>>1)+ci; _d&=255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRr_e() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_e&1?0x10:0; _e=(_e>>1)+ci; _e&=255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRr_h() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_h&1?0x10:0; _h=(_h>>1)+ci; _h&=255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRr_l() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_l&1?0x10:0; _l=(_l>>1)+ci; _l&=255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRr_a() { unsigned char ci=_f&0x10?0x80:0; unsigned char co=_a&1?0x10:0; _a=(_a>>1)+ci; _a&=255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRHL() { unsigned char i=_mmu->readByte((_h<<8)+_l); unsigned char ci=_f&0x10?0x80:0; unsigned char co=i&1?0x10:0; i=(i>>1)+ci; i&=255; _mmu->writeByte((_h<<8)+_l,i); _f=(i)?0:0x80; _f=(_f&0xEF)+co; _ticks=4; }

  inline void RRCr_b() { unsigned char ci=_b&1?0x80:0; unsigned char co=_b&1?0x10:0; _b=(_b>>1)+ci; _b&=255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRCr_c() { unsigned char ci=_c&1?0x80:0; unsigned char co=_c&1?0x10:0; _c=(_c>>1)+ci; _c&=255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRCr_d() { unsigned char ci=_d&1?0x80:0; unsigned char co=_d&1?0x10:0; _d=(_d>>1)+ci; _d&=255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRCr_e() { unsigned char ci=_e&1?0x80:0; unsigned char co=_e&1?0x10:0; _e=(_e>>1)+ci; _e&=255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRCr_h() { unsigned char ci=_h&1?0x80:0; unsigned char co=_h&1?0x10:0; _h=(_h>>1)+ci; _h&=255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRCr_l() { unsigned char ci=_l&1?0x80:0; unsigned char co=_l&1?0x10:0; _l=(_l>>1)+ci; _l&=255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRCr_a() { unsigned char ci=_a&1?0x80:0; unsigned char co=_a&1?0x10:0; _a=(_a>>1)+ci; _a&=255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void RRCHL() { unsigned char i=_mmu->readByte((_h<<8)+_l); unsigned char ci=i&1?0x80:0; unsigned char co=i&1?0x10:0; i=(i>>1)+ci; i&=255; _mmu->writeByte((_h<<8)+_l,i); _f=(i)?0:0x80; _f=(_f&0xEF)+co; _ticks=4; }

  inline void SLAr_b() { unsigned char co=_b&0x80?0x10:0; _b=(_b<<1)&255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SLAr_c() { unsigned char co=_c&0x80?0x10:0; _c=(_c<<1)&255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SLAr_d() { unsigned char co=_d&0x80?0x10:0; _d=(_d<<1)&255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SLAr_e() { unsigned char co=_e&0x80?0x10:0; _e=(_e<<1)&255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SLAr_h() { unsigned char co=_h&0x80?0x10:0; _h=(_h<<1)&255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SLAr_l() { unsigned char co=_l&0x80?0x10:0; _l=(_l<<1)&255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SLAr_a() { unsigned char co=_a&0x80?0x10:0; _a=(_a<<1)&255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }

  inline void SLLr_b() { unsigned char co=_b&0x80?0x10:0; _b=((_b<<1)&255)+1; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SLLr_c() { unsigned char co=_c&0x80?0x10:0; _c=((_c<<1)&255)+1; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SLLr_d() { unsigned char co=_d&0x80?0x10:0; _d=((_d<<1)&255)+1; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SLLr_e() { unsigned char co=_e&0x80?0x10:0; _e=((_e<<1)&255)+1; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SLLr_h() { unsigned char co=_h&0x80?0x10:0; _h=((_h<<1)&255)+1; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SLLr_l() { unsigned char co=_l&0x80?0x10:0; _l=((_l<<1)&255)+1; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SLLr_a() { unsigned char co=_a&0x80?0x10:0; _a=((_a<<1)&255)+1; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }

  inline void SRAr_b() { unsigned char ci=_b&0x80; unsigned char co=_b&1?0x10:0; _b=((_b>>1)+ci)&255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SRAr_c() { unsigned char ci=_c&0x80; unsigned char co=_c&1?0x10:0; _c=((_c>>1)+ci)&255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SRAr_d() { unsigned char ci=_d&0x80; unsigned char co=_d&1?0x10:0; _d=((_d>>1)+ci)&255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SRAr_e() { unsigned char ci=_e&0x80; unsigned char co=_e&1?0x10:0; _e=((_e>>1)+ci)&255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SRAr_h() { unsigned char ci=_h&0x80; unsigned char co=_h&1?0x10:0; _h=((_h>>1)+ci)&255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SRAr_l() { unsigned char ci=_l&0x80; unsigned char co=_l&1?0x10:0; _l=((_l>>1)+ci)&255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SRAr_a() { unsigned char ci=_a&0x80; unsigned char co=_a&1?0x10:0; _a=((_a>>1)+ci)&255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }

  inline void SRLr_b() { unsigned char co=_b&1?0x10:0; _b=(_b>>1)&255; _f=(_b)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SRLr_c() { unsigned char co=_c&1?0x10:0; _c=(_c>>1)&255; _f=(_c)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SRLr_d() { unsigned char co=_d&1?0x10:0; _d=(_d>>1)&255; _f=(_d)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SRLr_e() { unsigned char co=_e&1?0x10:0; _e=(_e>>1)&255; _f=(_e)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SRLr_h() { unsigned char co=_h&1?0x10:0; _h=(_h>>1)&255; _f=(_h)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SRLr_l() { unsigned char co=_l&1?0x10:0; _l=(_l>>1)&255; _f=(_l)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }
  inline void SRLr_a() { unsigned char co=_a&1?0x10:0; _a=(_a>>1)&255; _f=(_a)?0:0x80; _f=(_f&0xEF)+co; _ticks=2; }

  inline void CPL() { _a ^= 255; _f=_a?0:0x80; _ticks=1; }
  inline void NEG() { _a=0-_a; _f=(_a<0)?0x10:0; _a&=255; if(!_a) _f|=0x80; _ticks=2; }

  inline void CCF() { unsigned char ci=_f&0x10?0:0x10; _f=(_f&0xEF)+ci; _ticks=1; }
  inline void SCF() { _f|=0x10; _ticks=1; }

  /*--- Stack ---*/
  inline void PUSHBC() { _sp--; _mmu->writeByte(_sp,_b); _sp--; _mmu->writeByte(_sp,_c); _ticks=3; }
  inline void PUSHDE() { _sp--; _mmu->writeByte(_sp,_d); _sp--; _mmu->writeByte(_sp,_e); _ticks=3; }
  inline void PUSHHL() { _sp--; _mmu->writeByte(_sp,_h); _sp--; _mmu->writeByte(_sp,_l); _ticks=3; }
  inline void PUSHAF() { _sp--; _mmu->writeByte(_sp,_a); _sp--; _mmu->writeByte(_sp,_f); _ticks=3; }

  inline void POPBC() { _c=_mmu->readByte(_sp); _sp++; _b=_mmu->readByte(_sp); _sp++; _ticks=3; }
  inline void POPDE() { _e=_mmu->readByte(_sp); _sp++; _d=_mmu->readByte(_sp); _sp++; _ticks=3; }
  inline void POPHL() { _l=_mmu->readByte(_sp); _sp++; _h=_mmu->readByte(_sp); _sp++; _ticks=3; }
  inline void POPAF() { _f=_mmu->readByte(_sp); _sp++; _a=_mmu->readByte(_sp); _sp++; _ticks=3; }

  /*--- Jump ---*/
  inline void JPnn() { _pc = _mmu->readWord(_pc); _ticks=3; }
  inline void JPHL() { _pc=(_h<<8)+_l; _ticks=1; }
  inline void JPNZnn() { _ticks=3; if((_f&0x80)==0x00) { _pc=_mmu->readWord(_pc); _ticks++; } else _pc+=2; }
  inline void JPZnn()  { _ticks=3; if((_f&0x80)==0x80) { _pc=_mmu->readWord(_pc); _ticks++; } else _pc+=2; }
  inline void JPNCnn() { _ticks=3; if((_f&0x10)==0x00) { _pc=_mmu->readWord(_pc); _ticks++; } else _pc+=2; }
  inline void JPCnn()  { _ticks=3; if((_f&0x10)==0x10) { _pc=_mmu->readWord(_pc); _ticks++; } else _pc+=2; }

  inline void JRn() { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _ticks=2; _pc+=i; _ticks++; }
  inline void JRNZn() { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _ticks=2; if((_f&0x80)==0x00) { _pc+=i; _ticks++; } }
  inline void JRZn()  { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _ticks=2; if((_f&0x80)==0x80) { _pc+=i; _ticks++; } }
  inline void JRNCn() { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _ticks=2; if((_f&0x10)==0x00) { _pc+=i; _ticks++; } }
  inline void JRCn()  { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _ticks=2; if((_f&0x10)==0x10) { _pc+=i; _ticks++; } }

  inline void DJNZn() { unsigned char i=_mmu->readByte(_pc); if(i>127) i=-((~i+1)&255); _pc++; _ticks=2; _b--; if(_b) { _pc+=i; _ticks++; } }

  inline void CALLnn() { _sp-=2; _mmu->writeWord(_sp,_pc+2); _pc=_mmu->readWord(_pc); _ticks=5; }
  inline void CALLNZnn() { _ticks=3; if((_f&0x80)==0x00) { _sp-=2; _mmu->writeWord(_sp,_pc+2); _pc=_mmu->readWord(_pc); _ticks+=2; } else _pc+=2; }
  inline void CALLZnn() { _ticks=3; if((_f&0x80)==0x80) { _sp-=2; _mmu->writeWord(_sp,_pc+2); _pc=_mmu->readWord(_pc); _ticks+=2; } else _pc+=2; }
  inline void CALLNCnn() { _ticks=3; if((_f&0x10)==0x00) { _sp-=2; _mmu->writeWord(_sp,_pc+2); _pc=_mmu->readWord(_pc); _ticks+=2; } else _pc+=2; }
  inline void CALLCnn() { _ticks=3; if((_f&0x10)==0x10) { _sp-=2; _mmu->writeWord(_sp,_pc+2); _pc=_mmu->readWord(_pc); _ticks+=2; } else _pc+=2; }


  inline void RET() { _pc=_mmu->readWord(_sp); _sp+=2; _ticks=3; }
  inline void RETI() { _ime=1; rrs(); _pc=_mmu->readWord(_sp); _sp+=2; _ticks=3; }
  inline void RETNZ() { _ticks=1; if((_f&0x80)==0x00) { _pc=_mmu->readWord(_sp); _sp+=2; _ticks+=2; } }
  inline void RETZ() { _ticks=1; if((_f&0x80)==0x80) { _pc=_mmu->readWord(_sp); _sp+=2; _ticks+=2; } }
  inline void RETNC() { _ticks=1; if((_f&0x10)==0x00) { _pc=_mmu->readWord(_sp); _sp+=2; _ticks+=2; } }
  inline void RETC() { _ticks=1; if((_f&0x10)==0x10) { _pc=_mmu->readWord(_sp); _sp+=2; _ticks+=2; } }

  inline void RST00() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x00; _ticks=3; }
  inline void RST08() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x08; _ticks=3; }
  inline void RST10() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x10; _ticks=3; }
  inline void RST18() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x18; _ticks=3; }
  inline void RST20() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x20; _ticks=3; }
  inline void RST28() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x28; _ticks=3; }
  inline void RST30() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x30; _ticks=3; }
  inline void RST38() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x38; _ticks=3; }
  inline void RST40() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x40; _ticks=3; }
  inline void RST48() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x48; _ticks=3; }
  inline void RST50() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x50; _ticks=3; }
  inline void RST58() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x58; _ticks=3; }
  inline void RST60() { rsv(); _sp-=2; _mmu->writeWord(_sp,_pc); _pc=0x60; _ticks=3; }

  inline void NOP() { _ticks=1; }
  inline void HALT() { _halt=1; _ticks=1; }

  inline void DI() { _ime=0; _ticks=1; }
  inline void EI() { _ime=1; _ticks=1; }

  inline void MAPcb() {
    unsigned char i=_mmu->readByte(_pc); _pc++;
    _pc &= 65535;
    if(_cbops[i])
      (this->*(_cbops[i]))();
    // (*_cbops[i])();
    throw "unknown operand called from MAPcb";
    //      else console.log(i);
  }

  inline void XX() {
    /*Undefined map entry*/
    unsigned short opc = _pc-1;
    throw "Unimplemented instruction" + opc;
    //      LOG.out('Z80', 'Unimplemented instruction at $'+opc.toString(16)+', stopping.');
    _stop=1;
  }
};
