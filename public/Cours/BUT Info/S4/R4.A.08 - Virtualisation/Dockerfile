FROM r408-gcc
LABEL maintainer="Loris<adressemail@gmail.com"
RUN mkdir /work
WORKDIR /work
RUN git -c "http.proxy=129.20.239.11:3128" clone https://github.com/BigPapoo/steganography
RUN http_proxy=http://129.20.239.11:3128 apt-get update
RUN http_proxy=http://129.20.239.11:3128 apt-get install -y cmake
WORKDIR /steganography