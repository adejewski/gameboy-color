builddir := "builddir"

default: build

setup:
    meson setup {{ builddir }}

build:
    meson compile -C {{ builddir }}

run: build
    ./{{ builddir }}/src/gameboy-color

test: build
    meson test -C {{ builddir }}

nix-setup:
    nix develop --command just setup

nix-wipe:
    nix develop --command just wipe

nix-build:
    nix develop --command just build

nix-run:
    nix develop --command just run

nix-test:
    nix develop --command just test

clean:
    meson compile -C {{ builddir }} --clean

wipe:
    meson setup {{ builddir }} --wipe
