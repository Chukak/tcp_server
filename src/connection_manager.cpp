#include "../include/connection_manager.h"

/*
 */
void connection_manager::start(connection::ptr c)
{
    connections.insert(c);
    c->start();
}

/*
 */
void connection_manager::stop(connection::ptr c)
{
    connections.erase(c);
    c->stop();
}

/*
 */
void connection_manager::stop_all()
{
    for (auto& c : connections) {
        c->stop();
    }
    connections.clear();
}

