FROM ubuntu:18.04

MAINTAINER ak <slisandr@student.21-school.ru>

COPY . /app

WORKDIR /app

RUN apt-get update
RUN apt-get install -y gcc make grep gawk valgrind
RUN make

CMD ./check_all.sh
