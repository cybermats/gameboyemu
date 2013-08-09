#include "cpu.hpp"



Cpu::Cpu(Mmu* mmu)
  : _mmu(mmu)
  , _a(0), _b(0), _c(0), _d(0), _e(0), _h(0), _l(0), _f(0)
  , _ra(0), _rb(0), _rc(0), _rd(0), _re(0), _rh(0), _rl(0), _rf(0)
  , _ticks(0), _totalTicks(0)
  , _halt(0), _ime(0), _stop(0)
{
}

void Cpu::reset()
{
}

void Cpu::execNext()
{
}


Cpu::OpPointer Cpu::_ops[] =
  {
// 00
    &Cpu::NOP,		&Cpu::LDBCnn,	&Cpu::LDBCmA,	&Cpu::INCBC,
    &Cpu::INCr_b,	&Cpu::DECr_b,	&Cpu::LDrn_b,	&Cpu::RLCA,
    &Cpu::LDmmSP,	&Cpu::ADDHLBC,	&Cpu::LDABCm,	&Cpu::DECBC,
    &Cpu::INCr_c,	&Cpu::DECr_c,	&Cpu::LDrn_c,	&Cpu::RRCA,
    // 10
    &Cpu::DJNZn,	&Cpu::LDDEnn,	&Cpu::LDDEmA,	&Cpu::INCDE,
    &Cpu::INCr_d,	&Cpu::DECr_d,	&Cpu::LDrn_d,	&Cpu::RLA,
    &Cpu::JRn,		&Cpu::ADDHLDE,	&Cpu::LDADEm,	&Cpu::DECDE,
    &Cpu::INCr_e,	&Cpu::DECr_e,	&Cpu::LDrn_e,	&Cpu::RRA,
    // 20
    &Cpu::JRNZn,	&Cpu::LDHLnn,	&Cpu::LDHLIA,	&Cpu::INCHL,
    &Cpu::INCr_h,	&Cpu::DECr_h,	&Cpu::LDrn_h,	&Cpu::DAA,
    &Cpu::JRZn,	&Cpu::ADDHLHL,	&Cpu::LDAHLI,	&Cpu::DECHL,
    &Cpu::INCr_l,	&Cpu::DECr_l,	&Cpu::LDrn_l,	&Cpu::CPL,
    // 30
    &Cpu::JRNCn,	&Cpu::LDSPnn,	&Cpu::LDHLDA,	&Cpu::INCSP,
    &Cpu::INCHLm,	&Cpu::DECHLm,	&Cpu::LDHLmn,	&Cpu::SCF,
    &Cpu::JRCn,	&Cpu::ADDHLSP,	&Cpu::LDAHLD,	&Cpu::DECSP,
    &Cpu::INCr_a,	&Cpu::DECr_a,	&Cpu::LDrn_a,	&Cpu::CCF,
    // 40
    &Cpu::LDrr_bb,	&Cpu::LDrr_bc,	&Cpu::LDrr_bd,	&Cpu::LDrr_be,
    &Cpu::LDrr_bh,	&Cpu::LDrr_bl,	&Cpu::LDrHLm_b,	&Cpu::LDrr_ba,
    &Cpu::LDrr_cb,	&Cpu::LDrr_cc,	&Cpu::LDrr_cd,	&Cpu::LDrr_ce,
    &Cpu::LDrr_ch,	&Cpu::LDrr_cl,	&Cpu::LDrHLm_c,	&Cpu::LDrr_ca,
    // 50
    &Cpu::LDrr_db,	&Cpu::LDrr_dc,	&Cpu::LDrr_dd,	&Cpu::LDrr_de,
    &Cpu::LDrr_dh,	&Cpu::LDrr_dl,	&Cpu::LDrHLm_d,	&Cpu::LDrr_da,
    &Cpu::LDrr_eb,	&Cpu::LDrr_ec,	&Cpu::LDrr_ed,	&Cpu::LDrr_ee,
    &Cpu::LDrr_eh,	&Cpu::LDrr_el,	&Cpu::LDrHLm_e,	&Cpu::LDrr_ea,
    // 60
    &Cpu::LDrr_hb,	&Cpu::LDrr_hc,	&Cpu::LDrr_hd,	&Cpu::LDrr_he,
    &Cpu::LDrr_hh,	&Cpu::LDrr_hl,	&Cpu::LDrHLm_h,	&Cpu::LDrr_ha,
    &Cpu::LDrr_lb,	&Cpu::LDrr_lc,	&Cpu::LDrr_ld,	&Cpu::LDrr_le,
    &Cpu::LDrr_lh,	&Cpu::LDrr_ll,	&Cpu::LDrHLm_l,	&Cpu::LDrr_la,
    // 70
  &Cpu::LDHLmr_b,	&Cpu::LDHLmr_c,	&Cpu::LDHLmr_d,	&Cpu::LDHLmr_e,
    &Cpu::LDHLmr_h,	&Cpu::LDHLmr_l,	&Cpu::HALT,		&Cpu::LDHLmr_a,
    &Cpu::LDrr_ab,	&Cpu::LDrr_ac,	&Cpu::LDrr_ad,	&Cpu::LDrr_ae,
    &Cpu::LDrr_ah,	&Cpu::LDrr_al,	&Cpu::LDrHLm_a,	&Cpu::LDrr_aa,
    // 80
    &Cpu::ADDr_b,	&Cpu::ADDr_c,	&Cpu::ADDr_d,	&Cpu::ADDr_e,
    &Cpu::ADDr_h,	&Cpu::ADDr_l,	&Cpu::ADDHL,		&Cpu::ADDr_a,
    &Cpu::ADCr_b,	&Cpu::ADCr_c,	&Cpu::ADCr_d,	&Cpu::ADCr_e,
    &Cpu::ADCr_h,	&Cpu::ADCr_l,	&Cpu::ADCHL,		&Cpu::ADCr_a,
    // 90
    &Cpu::SUBr_b,	&Cpu::SUBr_c,	&Cpu::SUBr_d,	&Cpu::SUBr_e,
    &Cpu::SUBr_h,	&Cpu::SUBr_l,	&Cpu::SUBHL,		&Cpu::SUBr_a,
    &Cpu::SBCr_b,	&Cpu::SBCr_c,	&Cpu::SBCr_d,	&Cpu::SBCr_e,
    &Cpu::SBCr_h,	&Cpu::SBCr_l,	&Cpu::SBCHL,		&Cpu::SBCr_a,
    // A0
    &Cpu::ANDr_b,	&Cpu::ANDr_c,	&Cpu::ANDr_d,	&Cpu::ANDr_e,
    &Cpu::ANDr_h,	&Cpu::ANDr_l,	&Cpu::ANDHL,		&Cpu::ANDr_a,
    &Cpu::XORr_b,	&Cpu::XORr_c,	&Cpu::XORr_d,	&Cpu::XORr_e,
    &Cpu::XORr_h,	&Cpu::XORr_l,	&Cpu::XORHL,		&Cpu::XORr_a,
    // B0
    &Cpu::ORr_b,	&Cpu::ORr_c,		&Cpu::ORr_d,		&Cpu::ORr_e,
    &Cpu::ORr_h,	&Cpu::ORr_l,		&Cpu::ORHL,		&Cpu::ORr_a,
    &Cpu::CPr_b,	&Cpu::CPr_c,		&Cpu::CPr_d,		&Cpu::CPr_e,
    &Cpu::CPr_h,	&Cpu::CPr_l,		&Cpu::CPHL,		&Cpu::CPr_a,
    // C0
    &Cpu::RETNZ,	&Cpu::POPBC,		&Cpu::JPNZnn,	&Cpu::JPnn,
    &Cpu::CALLNZnn,	&Cpu::PUSHBC,	&Cpu::ADDn,		&Cpu::RST00,
    &Cpu::RETZ,	&Cpu::RET,		&Cpu::JPZnn,		&Cpu::MAPcb,
    &Cpu::CALLZnn,	&Cpu::CALLnn,	&Cpu::ADCn,		&Cpu::RST08,
    // D0
    &Cpu::RETNC,	&Cpu::POPDE,		&Cpu::JPNCnn,	&Cpu::XX,
    &Cpu::CALLNCnn,	&Cpu::PUSHDE,	&Cpu::SUBn,		&Cpu::RST10,
    &Cpu::RETC,	&Cpu::RETI,		&Cpu::JPCnn,		&Cpu::XX,
    &Cpu::CALLCnn,	&Cpu::XX,		&Cpu::SBCn,		&Cpu::RST18,
    // E0
    &Cpu::LDIOnA,	&Cpu::POPHL,		&Cpu::LDIOCA,	&Cpu::XX,
    &Cpu::XX,		&Cpu::PUSHHL,	&Cpu::ANDn,		&Cpu::RST20,
    &Cpu::ADDSPn,	&Cpu::JPHL,		&Cpu::LDmmA,		&Cpu::XX,
    &Cpu::XX,		&Cpu::XX,		&Cpu::XORn,		&Cpu::RST28,
    // F0
    &Cpu::LDAIOn,	&Cpu::POPAF,		&Cpu::LDAIOC,	&Cpu::DI,
    &Cpu::XX,		&Cpu::PUSHAF,	&Cpu::ORn,		&Cpu::RST30,
    &Cpu::LDHLSPn,	&Cpu::XX,		&Cpu::LDAmm,		&Cpu::EI,
    &Cpu::XX,		&Cpu::XX,		&Cpu::CPn,		&Cpu::RST38
    
  };

Cpu::OpPointer Cpu::_cbops[] =
  {
    // CB00
    &Cpu::RLCr_b,	&Cpu::RLCr_c,	&Cpu::RLCr_d,	&Cpu::RLCr_e,
    &Cpu::RLCr_h,	&Cpu::RLCr_l,	&Cpu::RLCHL,		&Cpu::RLCr_a,
    &Cpu::RRCr_b,	&Cpu::RRCr_c,	&Cpu::RRCr_d,	&Cpu::RRCr_e,
    &Cpu::RRCr_h,	&Cpu::RRCr_l,	&Cpu::RRCHL,		&Cpu::RRCr_a,
    // CB10
    &Cpu::RLr_b,	&Cpu::RLr_c,		&Cpu::RLr_d,		&Cpu::RLr_e,
    &Cpu::RLr_h,	&Cpu::RLr_l,		&Cpu::RLHL,		&Cpu::RLr_a,
    &Cpu::RRr_b,	&Cpu::RRr_c,		&Cpu::RRr_d,		&Cpu::RRr_e,
    &Cpu::RRr_h,	&Cpu::RRr_l,		&Cpu::RRHL,		&Cpu::RRr_a,
    // CB20
    &Cpu::SLAr_b,	&Cpu::SLAr_c,	&Cpu::SLAr_d,	&Cpu::SLAr_e,
    &Cpu::SLAr_h,	&Cpu::SLAr_l,	&Cpu::XX,		&Cpu::SLAr_a,
    &Cpu::SRAr_b,	&Cpu::SRAr_c,	&Cpu::SRAr_d,	&Cpu::SRAr_e,
    &Cpu::SRAr_h,	&Cpu::SRAr_l,	&Cpu::XX,		&Cpu::SRAr_a,
    // CB30
    &Cpu::SWAPr_b,	&Cpu::SWAPr_c,	&Cpu::SWAPr_d,	&Cpu::SWAPr_e,
    &Cpu::SWAPr_h,	&Cpu::SWAPr_l,	&Cpu::XX,		&Cpu::SWAPr_a,
    &Cpu::SRLr_b,	&Cpu::SRLr_c,	&Cpu::SRLr_d,	&Cpu::SRLr_e,
    &Cpu::SRLr_h,	&Cpu::SRLr_l,	&Cpu::XX,		&Cpu::SRLr_a,
    // CB40
    &Cpu::BIT0b,	&Cpu::BIT0c,		&Cpu::BIT0d,		&Cpu::BIT0e,
    &Cpu::BIT0h,	&Cpu::BIT0l,		&Cpu::BIT0m,		&Cpu::BIT0a,
    &Cpu::BIT1b,	&Cpu::BIT1c,		&Cpu::BIT1d,		&Cpu::BIT1e,
    &Cpu::BIT1h,	&Cpu::BIT1l,		&Cpu::BIT1m,		&Cpu::BIT1a,
    // CB50
    &Cpu::BIT2b,	&Cpu::BIT2c,		&Cpu::BIT2d,		&Cpu::BIT2e,
    &Cpu::BIT2h,	&Cpu::BIT2l,		&Cpu::BIT2m,		&Cpu::BIT2a,
    &Cpu::BIT3b,	&Cpu::BIT3c,		&Cpu::BIT3d,		&Cpu::BIT3e,
    &Cpu::BIT3h,	&Cpu::BIT3l,		&Cpu::BIT3m,		&Cpu::BIT3a,
    // CB60
    &Cpu::BIT4b,	&Cpu::BIT4c,		&Cpu::BIT4d,		&Cpu::BIT4e,
    &Cpu::BIT4h,	&Cpu::BIT4l,		&Cpu::BIT4m,		&Cpu::BIT4a,
    &Cpu::BIT5b,	&Cpu::BIT5c,		&Cpu::BIT5d,		&Cpu::BIT5e,
    &Cpu::BIT5h,	&Cpu::BIT5l,		&Cpu::BIT5m,		&Cpu::BIT5a,
    // CB70
    &Cpu::BIT6b,	&Cpu::BIT6c,		&Cpu::BIT6d,		&Cpu::BIT6e,
    &Cpu::BIT6h,	&Cpu::BIT6l,		&Cpu::BIT6m,		&Cpu::BIT6a,
    &Cpu::BIT7b,	&Cpu::BIT7c,		&Cpu::BIT7d,		&Cpu::BIT7e,
    &Cpu::BIT7h,	&Cpu::BIT7l,		&Cpu::BIT7m,		&Cpu::BIT7a,
    // CB80
    &Cpu::RES0b,	&Cpu::RES0c,		&Cpu::RES0d,		&Cpu::RES0e,
    &Cpu::RES0h,	&Cpu::RES0l,		&Cpu::RES0m,		&Cpu::RES0a,
    &Cpu::RES1b,	&Cpu::RES1c,		&Cpu::RES1d,		&Cpu::RES1e,
    &Cpu::RES1h,	&Cpu::RES1l,		&Cpu::RES1m,		&Cpu::RES1a,
    // CB90
    &Cpu::RES2b,	&Cpu::RES2c,		&Cpu::RES2d,		&Cpu::RES2e,
    &Cpu::RES2h,	&Cpu::RES2l,		&Cpu::RES2m,		&Cpu::RES2a,
    &Cpu::RES3b,	&Cpu::RES3c,		&Cpu::RES3d,		&Cpu::RES3e,
    &Cpu::RES3h,	&Cpu::RES3l,		&Cpu::RES3m,		&Cpu::RES3a,
    // CBA0
    &Cpu::RES4b,	&Cpu::RES4c,		&Cpu::RES4d,		&Cpu::RES4e,
    &Cpu::RES4h,	&Cpu::RES4l,		&Cpu::RES4m,		&Cpu::RES4a,
    &Cpu::RES5b,	&Cpu::RES5c,		&Cpu::RES5d,		&Cpu::RES5e,
    &Cpu::RES5h,	&Cpu::RES5l,		&Cpu::RES5m,		&Cpu::RES5a,
    // CBB0
    &Cpu::RES6b,	&Cpu::RES6c,		&Cpu::RES6d,		&Cpu::RES6e,
    &Cpu::RES6h,	&Cpu::RES6l,		&Cpu::RES6m,		&Cpu::RES6a,
    &Cpu::RES7b,	&Cpu::RES7c,		&Cpu::RES7d,		&Cpu::RES7e,
    &Cpu::RES7h,	&Cpu::RES7l,		&Cpu::RES7m,		&Cpu::RES7a,
    // CBC0
    &Cpu::SET0b,	&Cpu::SET0c,		&Cpu::SET0d,		&Cpu::SET0e,
    &Cpu::SET0h,	&Cpu::SET0l,		&Cpu::SET0m,		&Cpu::SET0a,
    &Cpu::SET1b,	&Cpu::SET1c,		&Cpu::SET1d,		&Cpu::SET1e,
    &Cpu::SET1h,	&Cpu::SET1l,		&Cpu::SET1m,		&Cpu::SET1a,
    // CBD0
    &Cpu::SET2b,	&Cpu::SET2c,		&Cpu::SET2d,		&Cpu::SET2e,
    &Cpu::SET2h,	&Cpu::SET2l,		&Cpu::SET2m,		&Cpu::SET2a,
    &Cpu::SET3b,	&Cpu::SET3c,		&Cpu::SET3d,		&Cpu::SET3e,
    &Cpu::SET3h,	&Cpu::SET3l,		&Cpu::SET3m,		&Cpu::SET3a,
    // CBE0
    &Cpu::SET4b,	&Cpu::SET4c,		&Cpu::SET4d,		&Cpu::SET4e,
    &Cpu::SET4h,	&Cpu::SET4l,		&Cpu::SET4m,		&Cpu::SET4a,
    &Cpu::SET5b,	&Cpu::SET5c,		&Cpu::SET5d,		&Cpu::SET5e,
    &Cpu::SET5h,	&Cpu::SET5l,		&Cpu::SET5m,		&Cpu::SET5a,
    // CBF0
    &Cpu::SET6b,	&Cpu::SET6c,		&Cpu::SET6d,		&Cpu::SET6e,
    &Cpu::SET6h,	&Cpu::SET6l,		&Cpu::SET6m,		&Cpu::SET6a,
    &Cpu::SET7b,	&Cpu::SET7c,		&Cpu::SET7d,		&Cpu::SET7e,
    &Cpu::SET7h,	&Cpu::SET7l,		&Cpu::SET7m,		&Cpu::SET7a,
  };


