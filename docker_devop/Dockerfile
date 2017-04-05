FROM alpine

#ENV https_proxy 'http://172.23.0.100:8080'
#ENV http_proxy 'http://172.23.0.100:8080'

#RUN echo "http://dl-cdn.alpinelinux.org/alpine/edge/testing"  >> /etc/apk/repositories
#RUN echo "http://dl-cdn.alpinelinux.org/alpine/edge/main"  >> /etc/apk/repositories
#RUN echo "http://dl-cdn.alpinelinux.org/alpine/edge/community"  >> /etc/apk/repositories

RUN apk add --update \
    bash \
    curl-dev \
    g++ \
    git \
    make \
    openrc \
    openssh \
    python \
    vim \
 && rm -rf /var/cache/apk/*

RUN mkdir -p /lib/gtest/ /lib/xmlrpc_c/ \
   && mkdir -p /root/workspace 

COPY lib  /lib
#COPY .ssh /home/ci/
COPY startup.sh /root/
COPY .git-prompt.sh /root/
COPY .bashrc /root/
WORKDIR /root

#RUN rc-update add sshd && /etc/init.d/sshd start
#EXPOSE 22

CMD ["bash"]


