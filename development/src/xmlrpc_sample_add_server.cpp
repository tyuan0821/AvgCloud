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
typedef std::map<std::string, xmlrpc_c::value> cstruct;

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
	// take a first param as
        cstruct data(paramList.getStruct(0));
        paramList.verifyEnd(1);
	// take the user name
        xmlrpc_c::value_string userID(data["userID"]);
	// take number of vectors
        xmlrpc_c::value_int numOfVectors(data["numOfVectors"]);
	// take requestingNode
        xmlrpc_c::value_string requestingNode(data["requestingNode"]);
	// take vector type
        xmlrpc_c::value_string vectorType(data["vectorType"]);
	// extract resyncInfo
	xmlrpc_c::value_struct resyncInfoTmp(data["resynchrInfo"]);

        cstruct resyncInfo(static_cast<map<string, xmlrpc_c::value> >(resyncInfoTmp));


	// take the rand name
        xmlrpc_c::value_string rrand(resyncInfo["rand"]);
	// take the auts name
        xmlrpc_c::value_string auts(resyncInfo["auts"]);

// ONLY FOR DEBUG

	std::cout<<"Input data:"
          <<"\n\tuserId: \t"<<userID.cvalue()
	  <<"\n\t# of vectors: \t"<<numOfVectors.cvalue()
	  <<"\n\treq node: \t"<<requestingNode.cvalue()
	  <<"\n\tvector type: \t"<<vectorType.cvalue()
	  <<"\n\tResync info: "
		  <<"\n\t\trand: \t"<<rrand.cvalue()
		  <<"\n\t\tauts: \t"<<auts.cvalue()
	  <<std::endl;

	int i=0;
	int max = numOfVectors.cvalue();
	vector<xmlrpc_c::value> returnData;

// TODO: use the input values from the request to generate vectors
	
	for (i=0; i< max; i++){
        	std::string rand("00000000000000000000000000");
		std::string xres("00001111100000000000000000");
		std::string ck  ("00001111100000022222000000");
		std::string ik  ("00001111100000022222003333");
		std::string autn("aaaa1111100bb0022222cc3333");
			
		map<string, xmlrpc_c::value> autVector;
            		pair<string, xmlrpc_c::value> member1("rand", xmlrpc_c::value_string(rand));
            		autVector.insert(member1);
            		pair<string, xmlrpc_c::value> member2("xres", xmlrpc_c::value_string(xres));
            		autVector.insert(member2);
            		pair<string, xmlrpc_c::value> member3("ck", xmlrpc_c::value_string(ck));
            		autVector.insert(member3);
            		pair<string, xmlrpc_c::value> member4("ik", xmlrpc_c::value_string(ik));
            		autVector.insert(member4);
            		pair<string, xmlrpc_c::value> member5("autn", xmlrpc_c::value_string(autn));
            		autVector.insert(member5);
		
     		xmlrpc_c::value_struct const vector(autVector);
		returnData.push_back(vector);
	}
	xmlrpc_c::value_array array1(returnData);
	*retvalP = array1;

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
