builddir := "builddir"

default: build

setup:
    meson setup {{ builddir }}

build:
    meson compile -C {{ builddir }}

run: build
    ./{{ builddir }}/src/gameboy-color

clean:
    meson compile -C {{ builddir }} --clean

wipe:
    meson setup {{ builddir }} --wipe
