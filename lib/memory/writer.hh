#pragma once

#include <cstdint>

class Writer {
   public:
    virtual ~Writer() = default;
    virtual void write(const uint16_t address, const uint8_t data) = 0;
};
