# squeak-catfeeder

Un "CatFeeder" en Squeak, avec une interface web pour pouvoir donner facilement à manger au chat à distance, une caméra pour vérifier que la nourriture ait été distribuée, et une image Docker pour déployer rapidement le projet sur un Raspberry Pi. 

<p align="center">
  <img src="http://www.mars.dti.ne.jp/~umejava/images/sqlogo2.jpg">
</p>

    $ pinout
    $ sudo pigpiod

## Docker Image

    $ docker run --device /dev/gpiomem -p 8080:8080 -d adann0/squeak-catfeeder:latest

L'interface web devrait être accessible à http://ip:3131. Une icone est visible pour donner à manger au chat, et un live-stream pour vérifier que le bol ait bien été rempli.

## How to recreate the Squeak CatFeeder

You'll need at least a fresh image of Squeak 5.2b on a Raspberry Pi with a GPIO Interface (pigpiod is the native deamon for Raspberry GPIO), with FFI installed from SqueakMap.

I use FFI to import some functions from pigpio.h instead of using RaspberryPiGPIO from SqueakMap Catalog, that doesn't work for me ; so whatever it will be a more light image, and I have to use FFI so it's a good deal.

So I made these few methods :

    gpioInitialise
      <cdecl: long 'gpioInitialise' (void) module:  '/usr/lib/libpigpio.so' >
      ^self externalCallFailed

    gpioSetMode: c1 with: c2
      <cdecl: long 'gpioSetMode' (long long) module:  '/usr/lib/libpigpio.so' >
      ^self externalCallFailed
	
    gpioPWM: c1 with: c2
      <cdecl: long 'gpioPWM' (long long) module:  '/usr/lib/libpigpio.so' >
      ^self externalCallFailed

    gpioTerminate
      <cdecl: void 'gpioTerminate' (void) module:  '/usr/lib/libpigpio.so' >
      ^self externalCallFailed

    sleep: anInteger
      anInteger seconds asDelay wait.


And I call them all in a last method like this :

    feed:pin with:sec
      <subclass_name> new gpioInitialise;
      gpioSetMode:pin with:1;
      gpioPWM:pin with:192;
      sleep:sec;
      gpioTerminate.

Next I made a small webserver, I was using Seaside, but It crash when I click on the page at "gpioTerminate" so... I switch to a simple WebServer that just provide a livestream and a redirection when the page "/feed" is visited to feed the cat.

    (WebServer reset default)
      listenOn: 9999.
		
    WebServer default addService: '/' action:[:req|
      req send200Response: 'CatFeeder'.
    ].

    WebServer default addService: '/feed' action:[:req|
      FFI new feed.
      req send302Response: '/'. "redirect"
    ].

## Plus de détails


# Sources :

  - Seaside : http://seaside.st/
  - Monticello : http://book.seaside.st/book/getting-started/pharo/monticello
  - PiGPIO : https://github.com/joan2937/pigpio
  - C Library for PiCamera : https://raspberrypi.stackexchange.com/questions/55140/library-to-allow-use-of-pi-camera-in-projects
  - Pharo-VNC-Supervisor : https://github.com/mumez/pharo-vnc-supervisor
  - Seaside Introduction : https://www.youtube.com/watch?v=9pdJxubR8yE&list=PLE08F4511BC5E3A91
  - Raspberry Camera Live Stream : https://tutorials-raspberrypi.com/raspberry-pi-security-camera-livestream-setup/
  - Questions/Recherches :
    - Accès GPIO via Docker (SOF) : https://stackoverflow.com/questions/30059784/docker-access-to-raspberry-pi-gpio-pins
    - Compatibilité GPIO-Squeak : 
      - Des soucis avec le package SqueakMap "RaspberryPi GPIO" (dernière version de 2017) et Squeak 5.4 
      - https://blog.adafruit.com/2018/11/26/sysfs-is-dead-long-live-libgpiod-libgpiod-for-linux-circuitpython/
      - Du coup il faudrait faire quelque chose du genre FFI+pigpio (une des librairies natives installés sur Raspbian)
    - Prototypes/fonctions : 
      - https://www.raspberrypi.org/documentation/usage/gpio/python/README.md
      - https://www.raspberrypi.org/documentation/usage/gpio/scratch1/README.md
      - https://elinux.org/RPi_GPIO_Code_Samples
