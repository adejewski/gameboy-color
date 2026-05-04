#pragma once

#include <cassert>
#include <cstdint>
#include <span>
#include <vector>

#include "reader.hh"

class Cartridge {
   private:
    std::vector<uint8_t> rom;

    template <size_t kBase>
    class Viewer : public Reader {
       private:
        const Cartridge& cartridge;

       public:
        explicit Viewer(Cartridge& cartridge)
            : cartridge(cartridge) {}

        [[nodiscard]] uint8_t read(const uint16_t address) const noexcept override {
            assert(address < cartridge.rom.size());
            return cartridge.rom[address];
        }
    };

    Viewer<0x0000> bank0_view{*this};
    Viewer<0x4000> bank1_view{*this};

   public:
    void load(std::span<const uint8_t> data) {
        rom.assign_range(data);
    }

    [[nodiscard]] Reader& bank0() {
        return bank0_view;
    }
    [[nodiscard]] Reader& bank1() {
        return bank1_view;
    }
};
