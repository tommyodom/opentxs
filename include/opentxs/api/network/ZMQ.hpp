// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_API_NETWORK_ZMQ_HPP
#define OPENTXS_API_NETWORK_ZMQ_HPP

#include "opentxs/Forward.hpp"

#include "opentxs/Proto.hpp"
#include "opentxs/Types.hpp"

#include <chrono>
#include <memory>
#include <string>

namespace opentxs
{
namespace api
{
namespace network
{
class ZMQ
{
public:
    EXPORT virtual const opentxs::network::zeromq::Context& Context() const = 0;
    EXPORT virtual proto::AddressType DefaultAddressType() const = 0;
    EXPORT virtual std::chrono::seconds KeepAlive() const = 0;
    EXPORT virtual void KeepAlive(
        const std::chrono::seconds duration) const = 0;
    EXPORT virtual std::chrono::seconds Linger() const = 0;
    EXPORT virtual OTZMQContext NewContext() const = 0;
    EXPORT virtual std::chrono::seconds ReceiveTimeout() const = 0;
    EXPORT virtual const Flag& Running() const = 0;
    EXPORT virtual void RefreshConfig() const = 0;
    EXPORT virtual std::chrono::seconds SendTimeout() const = 0;
    EXPORT virtual opentxs::network::ServerConnection& Server(
        const std::string& id) const = 0;
    EXPORT virtual bool SetSocksProxy(const std::string& proxy) const = 0;
    EXPORT virtual std::string SocksProxy() const = 0;
    EXPORT virtual bool SocksProxy(std::string& proxy) const = 0;
    EXPORT virtual ConnectionState Status(const std::string& server) const = 0;

    EXPORT virtual ~ZMQ() = default;

protected:
    ZMQ() = default;

private:
    ZMQ(const ZMQ&) = delete;
    ZMQ(ZMQ&&) = delete;
    ZMQ& operator=(const ZMQ&) = delete;
    ZMQ& operator=(const ZMQ&&) = delete;
};
}  // namespace network
}  // namespace api
}  // namespace opentxs
#endif
