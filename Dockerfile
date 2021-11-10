FROM ubuntu

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y git build-essential libtool pkg-config autoconf automake shtool autotools-dev libusb-1.0-0-dev

# COPY ../.. /tmp/ott/
WORKDIR /tmp
RUN git clone https://github.com/tihmstar/libgeneral.git
WORKDIR /tmp/libgeneral
RUN ./autogen.sh --enable-static --disable-shared --enable-debug
RUN make
RUN make install

RUN apt-get install -y python3 python3-dev python3-apt python3-distutils

WORKDIR /tmp
RUN git clone https://github.com/libimobiledevice/libplist.git
WORKDIR /tmp/libplist
RUN ./autogen.sh
RUN make
RUN make install

RUN apt-get install -y git build-essential libtool pkg-config autoconf automake shtool autotools-dev libusb-1.0-0-dev libimobiledevice-dev

WORKDIR /tmp
COPY . /tmp/usbmuxd2/
WORKDIR /tmp/usbmuxd2

RUN ls -la

RUN git submodule init
RUN git submodule update

RUN ./autogen.sh  --enable-debug
RUN make

