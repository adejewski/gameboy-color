#pragma once

#include <cstdint>

struct Registers {
    uint8_t a = 0;
    uint8_t f = 0;

    uint8_t b = 0;
    uint8_t c = 0;

    uint8_t d = 0;
    uint8_t e = 0;

    uint8_t h = 0;
    uint8_t l = 0;

    uint16_t pc = 0;
    uint16_t sp = 0;

    [[nodiscard]] uint16_t af() const noexcept {
        return (a << 8) | f;
    }
    void af(const uint16_t v) noexcept {
        a = v >> 8;
        f = v & 0xF0;
    }

    [[nodiscard]] uint16_t bc() const noexcept {
        return (b << 8) | c;
    }
    void bc(const uint16_t v) noexcept {
        b = v >> 8;
        c = v & 0xFF;
    }

    [[nodiscard]] uint16_t de() const noexcept {
        return (d << 8) | e;
    }
    void de(const uint16_t v) noexcept {
        d = v >> 8;
        e = v & 0xFF;
    }

    [[nodiscard]] uint16_t hl() const noexcept {
        return (h << 8) | l;
    }
    void hl(const uint16_t v) noexcept {
        h = v >> 8;
        l = v & 0xFF;
    }
};
