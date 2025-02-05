FROM r408-gcc AS compilo
LABEL maintainer="Loris<adressemail@gmail.com"
RUN mkdir /work
WORKDIR /work
RUN git -c "http.proxy=129.20.239.11:3128" clone https://github.com/BigPapoo/steganography
RUN http_proxy=http://129.20.239.11:3128 apt-get update
RUN http_proxy=http://129.20.239.11:3128 apt-get install -y cmake
WORKDIR steganography
RUN mkdir build
WORKDIR build
RUN cmake _DCMAKE_BUILD_TYPE=Release ..
RUN make -j 4
RUN mv steganography /usr/local/bin/
WORKDIR /

FROM r408-ubuntu:23.04
COPY --from=compilo /usr/local/bin/steganography /usr/local/bin/