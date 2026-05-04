#include "registers.hh"

#include <gtest/gtest.h>

TEST(Registers, MappingToHighRegisters) {
    // Arrange
    Registers regs;

    // Act
    regs.af(0x123F);
    regs.bc(0x123F);
    regs.de(0x234F);
    regs.hl(0x345F);

    // Assert
    EXPECT_EQ(regs.a, 0x12);
    EXPECT_EQ(regs.f, 0x30);
    EXPECT_EQ(regs.b, 0x12);
    EXPECT_EQ(regs.c, 0x3F);
    EXPECT_EQ(regs.d, 0x23);
    EXPECT_EQ(regs.e, 0x4F);
    EXPECT_EQ(regs.h, 0x34);
    EXPECT_EQ(regs.l, 0x5F);
}
