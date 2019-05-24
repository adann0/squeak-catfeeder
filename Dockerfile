FROM adann0/squeak-headless:latest

WORKDIR /tmp

RUN wget http://abyz.me.uk/rpi/pigpio/pigpio.tar \
  && tar -xf pigpio.tar \
  && cd PIGPIO \
  && make \
  && make install \
  && cd .. \
  && rm -rf PIGPIO
  
EXPOSE 8080

