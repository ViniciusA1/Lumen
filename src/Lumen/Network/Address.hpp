#pragma once

#include <cstdint>
#include <string>

using ENetAddress = struct _ENetAddress;

namespace Lumen
{

class Address
{
public:
    Address();
    Address(const ::ENetAddress &address);
    Address(std::string host, uint16_t port);

    [[nodiscard]] std::string GetIP() const;
    [[nodiscard]] uint16_t GetPort() const;
    [[nodiscard]] std::string ToString() const;

    void SetHost(const std::string &host);
    void SetPort_(uint16_t port);

    bool operator==(const Address &other) const;
    bool operator!=(const Address &other) const;

    operator ::ENetAddress() const;

private:
    std::string m_Host;
    uint16_t m_Port;
};

} // namespace Lumen