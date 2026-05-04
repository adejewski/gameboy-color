#pragma once

#include <cstdint>
#include <cstdio>

#include "memory.hh"
#include "reader_writer.hh"

class IORegisters : public ReaderWriter {
   private:
    // Joypad
    static constexpr uint16_t kJoypAddress = 0xFF00;

    // Serial transfer
    static constexpr uint16_t kSbAddress = 0xFF01;
    static constexpr uint16_t kScAddress = 0xFF02;

    // Timer and divider
    static constexpr uint16_t kDivAddress = 0xFF04;
    static constexpr uint16_t kTimaAddress = 0xFF05;
    static constexpr uint16_t kTmaAddress = 0xFF06;
    static constexpr uint16_t kTacAddress = 0xFF07;

    // Interrupts
    static constexpr uint16_t kIfAddress = 0xFF0F;

    // Audio - channel 1 (square + sweep)
    static constexpr uint16_t kNr10Address = 0xFF10;
    static constexpr uint16_t kNr11Address = 0xFF11;
    static constexpr uint16_t kNr12Address = 0xFF12;
    static constexpr uint16_t kNr13Address = 0xFF13;
    static constexpr uint16_t kNr14Address = 0xFF14;

    // Audio - channel 2 (square)
    static constexpr uint16_t kNr21Address = 0xFF16;
    static constexpr uint16_t kNr22Address = 0xFF17;
    static constexpr uint16_t kNr23Address = 0xFF18;
    static constexpr uint16_t kNr24Address = 0xFF19;

    // Audio - channel 3 (wave)
    static constexpr uint16_t kNr30Address = 0xFF1A;
    static constexpr uint16_t kNr31Address = 0xFF1B;
    static constexpr uint16_t kNr32Address = 0xFF1C;
    static constexpr uint16_t kNr33Address = 0xFF1D;
    static constexpr uint16_t kNr34Address = 0xFF1E;

    // Audio - channel 4 (noise)
    static constexpr uint16_t kNr41Address = 0xFF20;
    static constexpr uint16_t kNr42Address = 0xFF21;
    static constexpr uint16_t kNr43Address = 0xFF22;
    static constexpr uint16_t kNr44Address = 0xFF23;

    // Audio - master
    static constexpr uint16_t kNr50Address = 0xFF24;
    static constexpr uint16_t kNr51Address = 0xFF25;
    static constexpr uint16_t kNr52Address = 0xFF26;

    // Wave pattern RAM (block, 16 bytes)
    static constexpr uint16_t kWaveRamBase = 0xFF30;
    static constexpr size_t kWaveRamSize = 0x10;

    // LCD
    static constexpr uint16_t kLcdcAddress = 0xFF40;
    static constexpr uint16_t kStatAddress = 0xFF41;
    static constexpr uint16_t kScyAddress = 0xFF42;
    static constexpr uint16_t kScxAddress = 0xFF43;
    static constexpr uint16_t kLyAddress = 0xFF44;
    static constexpr uint16_t kLycAddress = 0xFF45;
    static constexpr uint16_t kOamDmaAddress = 0xFF46;
    static constexpr uint16_t kBgpAddress = 0xFF47;
    static constexpr uint16_t kObp0Address = 0xFF48;
    static constexpr uint16_t kObp1Address = 0xFF49;
    static constexpr uint16_t kWyAddress = 0xFF4A;
    static constexpr uint16_t kWxAddress = 0xFF4B;

    // CGB system control
    static constexpr uint16_t kKey0Address = 0xFF4C;
    static constexpr uint16_t kKey1Address = 0xFF4D;
    static constexpr uint16_t kVramSelectAddress = 0xFF4F;
    static constexpr uint16_t kBootRomMappingAddress = 0xFF50;

    // VRAM DMA (CGB)
    static constexpr uint16_t kHdma1Address = 0xFF51;
    static constexpr uint16_t kHdma2Address = 0xFF52;
    static constexpr uint16_t kHdma3Address = 0xFF53;
    static constexpr uint16_t kHdma4Address = 0xFF54;
    static constexpr uint16_t kHdma5Address = 0xFF55;

    // Infrared (CGB)
    static constexpr uint16_t kRpAddress = 0xFF56;

    // BG/OBJ palettes (CGB)
    static constexpr uint16_t kBcpsAddress = 0xFF68;
    static constexpr uint16_t kBcpdAddress = 0xFF69;
    static constexpr uint16_t kOcpsAddress = 0xFF6A;
    static constexpr uint16_t kOcpdAddress = 0xFF6B;
    static constexpr uint16_t kOpriAddress = 0xFF6C;

    // WRAM bank select (CGB)
    static constexpr uint16_t kWramBankSelectAddress = 0xFF70;

    struct JOYP {
        uint8_t right_or_a : 1;
        uint8_t left_or_b : 1;
        uint8_t up_or_select : 1;
        uint8_t down_or_start : 1;
        uint8_t select_dpad : 1;
        uint8_t select_buttons : 1;
        uint8_t unused : 2;
    };
    static_assert(sizeof(JOYP) == 1);
    uint8_t sb{0};

   public:
    [[nodiscard]] uint8_t read([[maybe_unused]] const uint16_t address) const noexcept override {
        // FIXME(adejewski): Unimplemented fix me later
        return 0xFF;
    }

    void write(const uint16_t address, const uint8_t value) noexcept override {
        // FIXME(adejewski): Only implement serial for testing
        switch (address) {
            case kSbAddress: {
                sb = value;
            } break;
            case kScAddress: {
                if (value == 0x81) {
                    std::putchar(sb);
                    std::fflush(stdout);
                }
            } break;
        }
    }
};
