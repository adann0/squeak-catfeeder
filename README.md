# squeak-catfeeder

Un "CatFeeder" en Squeak, avec une interface web pour pouvoir donner facilement à manger au chat à distance, et une image Docker pour déployer rapidement le projet sur un Raspberry Pi. 

<p align="center">
  <img src="http://www.mars.dti.ne.jp/~umejava/images/sqlogo2.jpg">
</p>

    $ pinout
    $ sudo pigpiod

## Docker Image

    $ docker run --device /dev/gpiomem -p 8080:8080 -d adann0/squeak-catfeeder:latest

L'interface web devrait être accessible à http://ip:8080, en cliquant sur la photo du chat le Cervo branché sur le PIN devrait se mettre à tourner et distribuer des croquettes ; la page web devrait maintenant afficher une photo prise à l'instant vu d'en haut du bol de croquette rempli.

3 classes, CatFeeder-FFI, CatFeeder-Tools, CatFeeder-Core, (CatFeeder-Web?)

## Plus de détails


# Sources :

  - Seaside : http://seaside.st/
  - Monticello : http://book.seaside.st/book/getting-started/pharo/monticello
  - PiGPIO : https://github.com/joan2937/pigpio
  - C Library for PiCamera : https://raspberrypi.stackexchange.com/questions/55140/library-to-allow-use-of-pi-camera-in-projects
  - Pharo-VNC-Supervisor : https://github.com/mumez/pharo-vnc-supervisor
  - Seaside Introduction : https://www.youtube.com/watch?v=9pdJxubR8yE&list=PLE08F4511BC5E3A91
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
