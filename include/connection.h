#ifndef CONNECTION_H
#define CONNECTION_H

#include <array>
#include "aliases.h"
#include <boost/make_shared.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace pseudonyms;

class connection_manager;

class connection : public boost::enable_shared_from_this<connection>
{
public:
    
    using ptr = boost::shared_ptr<connection>;
    
    /*
     */
    connection(const connection&) = delete;
    connection& operator=(const connection&) = delete;
    
    /*
     */
    void start();
    
    /*
     */
    void stop();
    
    /*
     */
    sock& socket() { return socket_; }
    
    /*
     */
    explicit connection(sock& s, connection_manager& manager); 
    
private:
    
    /*
     */
    void do_read();
    
    /*
     */
    void do_write();
    
    sock socket_;
    std::array<char, 8192> buffer_;
    connection_manager& connection_manager_;
    endpoint endpoint_;
        
};

#endif /* CONNECTION_H */

