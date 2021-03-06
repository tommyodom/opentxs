// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

// IWYU pragma: begin_exports
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include <lucre/bank.h>
#pragma GCC diagnostic pop
// IWYU pragma: end_exports

#include <string>

namespace opentxs::blind
{
class LucreDumper
{
    std::string m_str_dumpfile;

public:
    LucreDumper();
    ~LucreDumper() = default;
};
}  // namespace opentxs::blind
