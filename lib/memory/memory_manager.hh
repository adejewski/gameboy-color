#pragma once

#include <span>

#include "io_registers.hh"
#include "memory_layout.hh"
#include "reader_writer.hh"

class MemoryManager : public ReaderWriter {
   private:
    RomBank0& rom0;
    RomBank1& rom1;

    std::span<VramBank, 2> vram;
    uint8_t& vbk;

    ReaderWriter& external_ram;

    WramBank0& wram0;
    std::span<WramBankN, 7> wramN;
    uint8_t& svbk;

    OamBank& oam;
    HramBank& hram;

    IORegisters& io_registers;
    uint8_t& ie;

    [[nodiscard]] uint8_t wram_bank_index() const noexcept {
        const uint8_t bank = svbk & 0x07;
        return bank == 0 ? 0 : bank - 1;
    }

   public:
    MemoryManager(
        RomBank0& rom0,
        RomBank1& rom1,
        std::span<VramBank, 2> vram,
        uint8_t& vbk,
        ReaderWriter& external_ram,
        WramBank0& wram0,
        std::span<WramBankN, 7> wramN,
        uint8_t& svbk,
        OamBank& oam,
        HramBank& hram,
        IORegisters& io_registers,
        uint8_t& ie)
        : rom0(rom0),
          rom1(rom1),
          vram(vram),
          vbk(vbk),
          external_ram(external_ram),
          wram0(wram0),
          wramN(wramN),
          svbk(svbk),
          oam(oam),
          hram(hram),
          io_registers(io_registers),
          ie(ie) {}

    [[nodiscard]] uint8_t read(const uint16_t address) const noexcept override {
        if (address < kRomBank0Base + kRomBankSize) return rom0.read(address);
        if (address < kRomBank1Base + kRomBankSize) return rom1.read(address);
        if (address < kVramBase + kVramBankSize) return vram[vbk & 1].read(address);
        if (address < kExternalRamBase + kExternalRamSize) return external_ram.read(address);
        if (address < kWramBank0Base + kWramBankSize) return wram0.read(address);
        if (address < kWramBankNBase + kWramBankSize) return wramN[wram_bank_index()].read(address);
        if (address < kEchoRamBase + kEchoRamSize) return read(address - kEchoRamOffset);
        if (address < kOamBase + kOamSize) return oam.read(address);
        if (address < kUnusableBase + kUnusableSize) return 0xFF;
        if (address < kIoBase + kIoSize) return io_registers.read(address);
        if (address < kHramBase + kHramSize) return hram.read(address);
        return ie;
    }

    void write(const uint16_t address, const uint8_t value) noexcept override {
        if (address < kRomBank0Base + kRomBankSize) {
            rom0.write(address, value);
            return;
        }
        if (address < kRomBank1Base + kRomBankSize) {
            rom1.write(address, value);
            return;
        }
        if (address < kVramBase + kVramBankSize) {
            vram[vbk & 1].write(address, value);
            return;
        }
        if (address < kExternalRamBase + kExternalRamSize) {
            external_ram.write(address, value);
            return;
        }
        if (address < kWramBank0Base + kWramBankSize) {
            wram0.write(address, value);
            return;
        }
        if (address < kWramBankNBase + kWramBankSize) {
            wramN[wram_bank_index()].write(address, value);
            return;
        }
        if (address < kEchoRamBase + kEchoRamSize) {
            write(address - kEchoRamOffset, value);
            return;
        }
        if (address < kOamBase + kOamSize) {
            oam.write(address, value);
            return;
        }
        if (address < kUnusableBase + kUnusableSize) return;
        if (address < kIoBase + kIoSize) {
            io_registers.write(address, value);
            return;
        }
        if (address < kHramBase + kHramSize) {
            hram.write(address, value);
            return;
        }
        ie = value;
    }
};
