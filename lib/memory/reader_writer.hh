#pragma once

#include "reader.hh"
#include "writer.hh"

class ReaderWriter
    : public Reader
    , public Writer {};
