#pragma once

#include <cassert>
#include <cstddef>
#include <cstdint>

#include "reader_writer.hh"

template <size_t kSize, uint16_t kBase, bool kReadOnly = false>
class Memory : public ReaderWriter {
   private:
    uint8_t data[kSize] = {0};

   public:
    [[nodiscard]] size_t size() const noexcept {
        return kSize;
    }

    [[nodiscard]] uint8_t read(const uint16_t address) const noexcept override {
        assert(kBase <= address && address < kBase + kSize);
        return data[address - kBase];
    }

    void write(const uint16_t address, const uint8_t value) noexcept override {
        if constexpr (!kReadOnly) {
            assert(kBase <= address && address < kBase + kSize);
            data[address - kBase] = value;
        }
    }
};
