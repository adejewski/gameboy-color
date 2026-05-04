#include <array>
#include <print>

#include "memory/cartridge.hh"
#include "memory/memory.hh"
#include "memory/memory_manager.hh"

Cartridge cartridge;

std::array<VramBank, 2> vram;
uint8_t vbk;

Memory<kExternalRamSize, kExternalRamBase> external_ram;

WramBank0 wram0;
std::array<WramBankN, 7> wramN;
uint8_t svbk;

OamBank oam;
HramBank hram;

IORegisters io_registers;
uint8_t ie;
auto memory_manager = MemoryManager{
    cartridge.bank0(),
    cartridge.bank1(),
    vram,
    vbk,
    external_ram,
    wram0,
    wramN,
    svbk,
    oam,
    hram,
    io_registers,
    ie};

int main() {
    std::println("Gameboy emulator started");
    return 0;
}
