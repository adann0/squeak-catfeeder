FROM adann0/squeak-headless:latest

RUN wget http://abyz.me.uk/rpi/pigpio/pigpio.tar \
  && tar -xf pigpio.tar \
  && cd PIGPIO \
  && make \
  && make install
  
EXPOSE 8080

