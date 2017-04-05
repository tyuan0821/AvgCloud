FROM alpine

RUN apk add --update \
   curl \
   curl-dev \
   g++ \
   make \
   subversion \
 && rm -rf /var/cache/apk/*
 
RUN mkdir /xmlrpc
RUN cd /xmlrpc && \
   svn checkout http://svn.code.sf.net/p/xmlrpc-c/code/advanced 

RUN cd /xmlrpc/advanced/ &&\
  ./configure && \
  make &&\
  make install 
  
RUN cd /xmlrpc/advanced/tools/ &&\
   make &&\
   make install
   
RUN cd /xmlrpc/advanced/examples/cpp/ &&\
   make
   
EXPOSE 8080
CMD ["/xmlrpc/advanced/examples/cpp/xmlrpc_sample_add_server"]

