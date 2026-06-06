#!/usr/bin/env bash
set -e

make -C test build TOOLCHAIN=GCC_ARM
make -C test program TOOLCHAIN=GCC_ARM
