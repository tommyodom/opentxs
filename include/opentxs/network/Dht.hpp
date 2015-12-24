/************************************************************
 *
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  EMAIL:
 *  fellowtraveler@opentransactions.org
 *
 *  WEBSITE:
 *  http://www.opentransactions.org/
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This Source Code Form is subject to the terms of the
 *   Mozilla Public License, v. 2.0. If a copy of the MPL
 *   was not distributed with this file, You can obtain one
 *   at http://mozilla.org/MPL/2.0/.
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will
 *   be useful, but WITHOUT ANY WARRANTY; without even the
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A
 *   PARTICULAR PURPOSE.  See the Mozilla Public License
 *   for more details.
 *
 ************************************************************/

#ifndef OPENTXS_NETWORK_DHT_HPP
#define OPENTXS_NETWORK_DHT_HPP

#if OT_DHT
#include <opendht.h>

#include <opentxs/core/Contract.hpp>

namespace opentxs
{

class OTData;

//Singlton class for providing an interface to OpenDHT.
class Dht
{
private:
    Dht() = delete;
    Dht(Dht const&) = delete;
    Dht& operator=(Dht const&) = delete;

    Dht(int port);

    void Init(int port);
    dht::DhtRunner* node_ = nullptr;
    static Dht* instance_;

public:
    EXPORT static Dht& Node(int port = 4222);
    EXPORT void Insert(
        const std::string& key,
        OTData& value,
        dht::Dht::DoneCallbackSimple cb={});
    EXPORT void Insert(
        const std::string& key,
        std::string& value,
        dht::Dht::DoneCallbackSimple cb={});
    EXPORT void Insert(
        const std::string ID,
        const Contract& contract);
    EXPORT void Retrieve(
        const std::string& key,
        dht::Dht::GetCallback vcb,
        dht::Dht::DoneCallbackSimple dcb={},
        dht::Value::Filter f = dht::Value::AllFilter());
    dht::DhtRunner* p();
    void Cleanup();
    ~Dht();
};

}  // namespace opentxs
#endif // OT_DHT
#endif // OPENTXS_NETWORK_DHT_HPP
