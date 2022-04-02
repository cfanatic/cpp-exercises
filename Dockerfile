FROM ubuntu:focal

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update
RUN apt-get -y install \
    git \
    nano \
    cmake \
    protobuf-compiler \
    gcc \
    g++

RUN git clone https://github.com/cfanatic/cpp-exercises.git /src/cpp-exercises
RUN mkdir /src/cpp-exercises/build
WORKDIR /src/cpp-exercises/build
RUN cmake ..
RUN make

# provide possibility to override which command is executed when container is run
ENV PATH=".:${PATH}"
CMD [ "/src/cpp-exercises/build/cpp-exercises-debug" ]
