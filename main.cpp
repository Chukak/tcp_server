#include <cstdlib>
#include "include/server.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        if (argc != 3) {
            return 1;
        }
        
        server s(argv[1], argv[2]);
        
        s.run();
        
    } catch (std::exception& e) {
        cout << e.what() << "\n";
        return 1;
    }
    return 0;
}

