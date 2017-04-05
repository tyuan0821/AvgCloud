unset http_proxy
unset https_proxy

/xmlrpc/xmlrpc http://172.17.0.5:8080/RPC2 authKeys.get s/"$1"

