#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "aliases.h"
#include <boost/asio.hpp>
#include "connection.h"
#include "connection_manager.h"

using namespace pseudonyms;

using uint = unsigned int;

class server
{
public:
    using acceptor = boost::asio::ip::tcp::acceptor;
    
    /*
     */
    server(const server&) = delete;
    server& operator=(const server&) = delete;
    
    /*
     */
    explicit server(const std::string& addr, const std::string& port);
    
    /*
     */
    void run();
    
private:
    
    /*
     */
    void do_await_stop();
    
    /*
     */
    void do_accept();

    io_context io;
    acceptor acceptor_;
    connection_manager connection_manager_;
    boost::asio::signal_set signals;
    
};


#endif /* SERVER_H */

