// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include "opentxs/Forward.hpp"

#include <string>

namespace opentxs
{

class DhtConfig
{
public:
    bool enable_dht_ = false;
    const int64_t default_port_ = 4222;
    int64_t listen_port_ = 4222;
    int64_t nym_publish_interval_ = 60 * 5;
    int64_t nym_refresh_interval_ = 60 * 60 * 1;
    int64_t server_publish_interval_ = 60 * 5;
    int64_t server_refresh_interval_ = 60 * 60 * 1;
    int64_t unit_publish_interval_ = 60 * 5;
    int64_t unit_refresh_interval_ = 60 * 60 * 1;
    std::string bootstrap_url_ = "bootstrap.ring.cx";
    std::string bootstrap_port_ = "4222";
};

}  // namespace opentxs
