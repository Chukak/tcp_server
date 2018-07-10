#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

#include <set>
#include "aliases.h"
#include "connection.h"

using namespace pseudonyms;

class connection_manager 
{
public:
    connection_manager(const connection_manager&) = delete;
    connection_manager& operator=(const connection_manager&) = delete;
    
    connection_manager() = default;
    
    /*
     */
    void start(connection::ptr);
    
    /*
     */
    void stop(connection::ptr);
    
    /*
     */
    void stop_all();
    
private:
    std::set<connection::ptr> connections;
};


#endif /* CONNECTION_MANAGER_H */

