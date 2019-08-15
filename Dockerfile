FROM adann0/squeak-headless:armv7

WORKDIR /tmp

RUN wget http://abyz.me.uk/rpi/pigpio/pigpio.tar \
  && tar -xf pigpio.tar \
  && cd PIGPIO \
  && make \
  && make install \
  && cd .. \
  && rm -rf PIGPIO

RUN wget https://www28.zippyshare.com/d/DAhGpJDo/30596/catfeeder.zip

COPY ./catfeeder/share /squeak/share
