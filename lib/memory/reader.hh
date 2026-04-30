#pragma once

#include <cstdint>

class Reader {
   public:
    virtual ~Reader() = default;
    virtual uint8_t read(const uint16_t address) const = 0;
};
