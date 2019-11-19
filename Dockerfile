FROM golang:buster

# install deps
RUN apt update && apt install -y swig cmake

WORKDIR /exampleModule/

COPY include include
COPY src src
COPY Example.i ./
COPY CMakeLists.txt ./

WORKDIR /exampleModule/build
RUN cmake -DOUTPUT_DIR="/go/src/example" .. && make -j

RUN CGO_ENABLED=1 go build example
