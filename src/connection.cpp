#include "../include/connection.h"

#include "../include/connection_manager.h"

connection::connection(sock& s, connection_manager& manager) : 
    socket_(std::move(s)), 
    connection_manager_(manager)
{
}

void connection::start()
{
    do_write();
    do_read();
}

void connection::stop()
{
    socket_.close();
}

void connection::do_read()
{
    socket_.async_read_some(boost::asio::buffer(buffer_), 
        [this](const sys_ec& ec, size_t bytes_tr) 
        {
            if (!ec) {
                do_read(); 
            }
            else if (ec != boost::asio::error::operation_aborted) {
                connection_manager_.stop(shared_from_this()); 
            }
        });
}

void connection::do_write()
{
    boost::asio::async_write(socket_, boost::asio::buffer("<h1>Hi!<h1>\n"), 
        [this](const sys_ec& ec, size_t) 
        {
            if (!ec) {
                sys_ec ignored_ec;
                socket_.shutdown(sock::shutdown_both,
                        ignored_ec);
            }
            
            if (ec != boost::asio::error::operation_aborted) {
                connection_manager_.stop(shared_from_this()); 
            }
        });
}
