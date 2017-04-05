#define WIN32_LEAN_AND_MEAN  /* required by xmlrpc-c/server_abyss.hpp */

#include <cassert>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

#ifdef _WIN32
#  include <windows.h>
#else
#  include <unistd.h>
#endif

using namespace std;

#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>

class getAuthKeysMethod : public xmlrpc_c::method {
private:
    string random;
public:
    getAuthKeysMethod(int rnd) {
        // signature and help strings are documentation -- the client
        // can query this information with a system.methodSignature and
        // system.methodHelp RPC.
        this->_signature = "s:s";
            // method's result and two arguments are integers
        this->_help = "This method returns the authentication string. Takes single string as an user ID"; 
        stringstream ss;
        ss<<rnd;

        random = ss.str();
    }
    void execute(xmlrpc_c::paramList const& paramList,
            xmlrpc_c::value *   const  retvalP) {
	std::cout << "DEBUG: in method execute" <<std::endl;        
        std::string const userID(paramList.getString(0));
        
        paramList.verifyEnd(1);
        
        *retvalP = xmlrpc_c::value_string("Hello "+userID+" ("+random+")");
	std::cout << "Hello "+userID+" ("+random+")" <<std::endl;                                             
   
 }
};



int 
main(int           const, 
     const char ** const) {

    std::srand(std::time(0));
    int random = std::rand();

    try {
        xmlrpc_c::registry myRegistry;

        xmlrpc_c::methodPtr const getAuthKeysP(new getAuthKeysMethod(random));

	std::cout<<"Starting server with method: authKeys.get"<<std::endl;

        myRegistry.addMethod("authKeys.get", getAuthKeysP);
        
        xmlrpc_c::serverAbyss myAbyssServer(
            xmlrpc_c::serverAbyss::constrOpt()
            .registryP(&myRegistry)
            .portNumber(8080));
        
        myAbyssServer.run();
        // xmlrpc_c::serverAbyss.run() never returns
        assert(false);
    } catch (exception const& e) {
        cerr << "Something failed.  " << e.what() << endl;
    }
    return 0;
}
