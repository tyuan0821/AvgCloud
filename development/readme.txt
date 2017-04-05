You can run the interactive docker image with

source runDocker.sh 

in the console you can:
 - work in the /src directory (mounted from the host system, changes are
   persistent after log off)
 - add new software with:
   apk add --update <software name>
 - compile xml server:
   cd /src && make
 - run test server:
   cd /src && ./runserver.sh
 - run example client:
   cd /src && runclient.sh

you can also find the compiled version of xmlrpc library under:
 /xmlrpc/advanced
together with tools, examples and library files. See also project page
   http://xmlrpc-c.sourceforge.net/downloading.php

exit will close the docker session (all data except stored in /src will be
lost*)








*not 100% true - but close

