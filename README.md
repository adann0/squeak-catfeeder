# squeak-catfeeder

Un "CatFeeder" en Squeak, avec une interface web pour pouvoir donner facilement à manger au chat à distance, et une image Docker pour déployer rapidement le projet sur un Raspberry Pi. 

<p align="center">
  <img src="http://www.mars.dti.ne.jp/~umejava/images/sqlogo2.jpg">
</p>

    $ pinout
    $ sudo pigpiod

## Docker Image

    $ docker run --device /dev/gpiomem -p 8080:8080 -d adann0/squeak-catfeeder:latest

L'interface web devrait être accessible à http://ip:8080, en cliquant sur la photo du chat le Cervo branché sur le PIN spécifié sur la page "Settings" devrait se mettre à tourner et distribuer des croquettes. Le nombre de pulsations peut-être ajusté, comme une sécurité (ne permettre qu'un certain nombre de fois la distribution par heure malgré le nombre répété de click sur le site).

# Sources :

  - Seaside : http://seaside.st/
  - Pharo + Docker : https://www.clever-cloud.com/blog/guests/2015/01/05/smalltalk-in-the-cloud/
  - GPIO + Docker : https://stackoverflow.com/questions/30059784/docker-access-to-raspberry-pi-gpio-pins
  - NuScratch Installation in Squeak 5.x : http://wiki.squeak.org/squeak/1263
  - Alternative : 
      - https://www.framboise314.fr/wp-content/uploads/2017/11/05_01_servomoteur.pdf
      - https://blog.adafruit.com/2018/11/26/sysfs-is-dead-long-live-libgpiod-libgpiod-for-linux-circuitpython/
      - Voir avec Sysfs+FileStream ou FFI
  - Pour des prototypes : 
      - https://www.raspberrypi.org/documentation/usage/gpio/python/README.md
      - https://www.raspberrypi.org/documentation/usage/gpio/scratch1/README.md
      - https://elinux.org/RPi_GPIO_Code_Samples
  - SqueakMap :
      - http://www.squeaksource.com/NuScratch/
  - https://github.com/JumpIntoSqueak/squeak-docker
  - https://en.scratch-wiki.info/wiki/Squeak_Tutorial
