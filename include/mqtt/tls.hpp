// Copyright Takatoshi Kondo 2020
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#if !defined(MQTT_TLS_HPP)
#define MQTT_TLS_HPP

#if defined(MQTT_USE_TLS)

#if !defined(MQTT_TLS_INCLUDE)
#define MQTT_TLS_INCLUDE <boost/asio/ssl.hpp>
#endif // !defined(MQTT_TLS_INCLUDE)

#include MQTT_TLS_INCLUDE

#if !defined(MQTT_TLS_NS)
#define MQTT_TLS_NS boost::asio::ssl
#endif // !defined(MQTT_TLS_NS)

#include <mqtt/namespace.hpp>

namespace MQTT_NS {
namespace tls = MQTT_TLS_NS;

inline constexpr bool is_tls_short_read(int error_val)
{
#if defined(MQTT_TLS_ERROR_COMPARISON)
    return MQTT_TLS_ERROR_COMPARISON(error_val);
#elif defined(SSL_R_SHORT_READ)
    return ERR_GET_REASON(error_val) == SSL_R_SHORT_READ;
#else  // defined(SSL_R_SHORT_READ)
    return ERR_GET_REASON(error_val) == tls::error::stream_truncated;
#endif // defined(MQTT_TLS_ERROR_COMPARISON)
    return false;
}

} // namespace MQTT_NS


#if defined(MQTT_USE_WS)

#if !defined(MQTT_TLS_WS_INCLUDE)
#define MQTT_TLS_WS_INCLUDE <boost/beast/websocket/ssl.hpp>
#endif // !defined(MQTT_TLS_WS_INCLUDE)

#include MQTT_TLS_WS_INCLUDE

#endif // defined(MQTT_USE_WS)

#endif // defined(MQTT_USE_TLS)


#endif // MQTT_TLS_HPP
