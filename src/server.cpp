#include "../include/server.h"
#include <boost/lexical_cast.hpp>


server::server(const std::string& addr, const std::string& port) :
    io(),
    acceptor_(io),
    signals(io)
{
    signals.add(SIGINT);
    signals.add(SIGTERM);
#ifdef SIGQUIT
    signals.add(SIGQUIT);
#endif
    
    do_await_stop();
    
    tcp::endpoint endpoint;
    try {
        endpoint = tcp::endpoint(boost::asio::ip::address::from_string(addr), 
                    boost::lexical_cast<int>(port)); 
    } catch (boost::bad_lexical_cast& e) {
        tcp::resolver resolver(io);
        endpoint = *resolver.resolve(addr, port).begin(); 
    }
    acceptor_.open(endpoint.protocol());
    acceptor_.set_option(acceptor::reuse_address(true));
    acceptor_.bind(endpoint);
    acceptor_.listen();
    
    do_accept();
}

void server::run() 
{
    for (unsigned i = 0; i < boost::thread::hardware_concurrency(); i++) {
        boost::thread *t = new boost::thread([this](){
            io.run();
        });
        threads.add_thread(t);
    }
    threads.join_all();
}

void server::do_accept()
{
    acceptor_.async_accept(
        [this](const sys_ec& ec, sock s)
        {
            if (acceptor_.is_open()) { 
                if (!ec) {
                    connection_manager_.start(
                        boost::make_shared<connection>(s, connection_manager_)); 
                }
                do_accept(); 
            }
        });
}

void server::do_await_stop()
{
    signals.async_wait(
        [this](const sys_ec& ec, size_t)
        {
            acceptor_.close();
            connection_manager_.stop_all();
        });
}