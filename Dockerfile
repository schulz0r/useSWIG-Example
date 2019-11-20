FROM golang:buster

# install deps
RUN apt update && apt install -y swig cmake

WORKDIR /exampleModule/

COPY include include
COPY src src
COPY Example.i ./
COPY CMakeLists.txt ./

WORKDIR /exampleModule/build
RUN cmake .. && make -j

# show that wrapper files have been generated
RUN ls /go/src/example

RUN CGO_ENABLED=1 go build example
