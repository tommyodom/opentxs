// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_API_CRYPTO_SYMMETRIC_HPP
#define OPENTXS_API_CRYPTO_SYMMETRIC_HPP

#include "opentxs/Forward.hpp"

#include "opentxs/Proto.hpp"

#include <cstdint>

namespace opentxs
{
namespace api
{
namespace crypto
{
class Symmetric
{
public:
    EXPORT virtual std::size_t IvSize(
        const proto::SymmetricMode mode) const = 0;
    EXPORT virtual OTSymmetricKey Key(
        const OTPasswordData& password,
        const proto::SymmetricMode mode =
            proto::SMODE_CHACHA20POLY1305) const = 0;
    EXPORT virtual OTSymmetricKey Key(
        const proto::SymmetricKey& serialized,
        const proto::SymmetricMode mode) const = 0;
    EXPORT virtual OTSymmetricKey Key(
        const OTPassword& seed,
        const std::uint64_t operations = 0,
        const std::uint64_t difficulty = 0,
        const proto::SymmetricMode mode = proto::SMODE_CHACHA20POLY1305,
        const proto::SymmetricKeyType type = proto::SKEYTYPE_ARGON2) const = 0;

    EXPORT virtual ~Symmetric() = default;

protected:
    Symmetric() = default;

private:
    Symmetric(const Symmetric&) = delete;
    Symmetric(Symmetric&&) = delete;
    Symmetric& operator=(const Symmetric&) = delete;
    Symmetric& operator=(Symmetric&&) = delete;
};
}  // namespace crypto
}  // namespace api
}  // namespace opentxs
#endif
