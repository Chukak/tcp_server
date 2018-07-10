#ifndef ALIASES_H
#define ALIASES_H

#include <boost/asio.hpp>


namespace pseudonyms {
    using tcp = boost::asio::ip::tcp;
    using sock = boost::asio::ip::tcp::socket;
    using io_context = boost::asio::io_context;
    using endpoint = boost::asio::ip::tcp::endpoint;
    using sys_ec = boost::system::error_code;
}

#endif /* ALIASES_H */

