#pragma once

#include "memory.hh"

// ROM
static constexpr size_t kRomBankSize = 0x4000;
static constexpr uint16_t kRomBank0Base = 0x0000;
static constexpr uint16_t kRomBank1Base = 0x4000;

using RomBank0 = Reader;
using RomBank1 = Reader;

// VRAM
static constexpr size_t kVramBankSize = 0x2000;
static constexpr uint16_t kVramBase = 0x8000;

using VramBank = Memory<kVramBankSize, kVramBase>;

// External RAM (cartridge)
static constexpr size_t kExternalRamSize = 0x2000;
static constexpr uint16_t kExternalRamBase = 0xA000;

// WRAM
static constexpr size_t kWramBankSize = 0x1000;
static constexpr uint16_t kWramBank0Base = 0xC000;
static constexpr uint16_t kWramBankNBase = 0xD000;

using WramBank0 = Memory<kWramBankSize, kWramBank0Base>;
using WramBankN = Memory<kWramBankSize, kWramBankNBase>;

// Echo RAM (mirrors 0xC000-0xDDFF)
static constexpr uint16_t kEchoRamBase = 0xE000;
static constexpr size_t kEchoRamSize = 0x1E00;
static constexpr uint16_t kEchoRamOffset = 0x2000;

// OAM
static constexpr size_t kOamSize = 0xA0;
static constexpr uint16_t kOamBase = 0xFE00;

using OamBank = Memory<kOamSize, kOamBase>;

// Unusable region
static constexpr uint16_t kUnusableBase = 0xFEA0;
static constexpr size_t kUnusableSize = 0x60;

// I/O registers
static constexpr uint16_t kIoBase = 0xFF00;
static constexpr size_t kIoSize = 0x80;

// HRAM
static constexpr size_t kHramSize = 0x7F;
static constexpr uint16_t kHramBase = 0xFF80;

using HramBank = Memory<kHramSize, kHramBase>;

// Interrupt enable register
static constexpr uint16_t kInterruptEnableAddress = 0xFFFF;
