// Copyright Takatoshi Kondo 2018
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#if !defined(MQTT_SSL_IMPLEMENTATION_HPP)
#define MQTT_SSL_IMPLEMENTATION_HPP

#if defined(MQTT_USE_TLS)
#if defined(MQTT_USE_GNU_TLS)
#include <boost/asio/gnutls.hpp>
#include <gnutls/gnutls.h>
# define ERR_GET_REASON(l)       (int)( (l)         & 0xFFFL)
#else
#include <boost/asio/ssl.hpp>
#endif // defined(MQTT_USE_GNU_TLS)
#endif // defined(MQTT_USE_TLS)

#if defined(MQTT_USE_TLS)
#if defined(MQTT_USE_GNU_TLS)
namespace ssl = boost::asio::gnutls;
#else
namespace ssl = boost::asio::ssl;
#endif // defined(MQTT_USE_GNU_TLS)
#endif // defined(MQTT_USE_TLS)

#endif // MQTT_SSL_IMPLEMENTATION_HPP
