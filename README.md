# squeak-catfeeder

Un distributeur de croquette pour chat en Squeak avec une image Docker pour déployer rapidement le projet sur un Raspberry Pi. Le chat appuie sur le bouton et les croquettes tombent.

<p align="center">
  <img src="http://www.mars.dti.ne.jp/~umejava/images/sqlogo2.jpg">
</p>

Pour voir les différents PIN du GPIO sur le Raspberry :

    $ pinout

## Docker Image

    $ docker run --device /dev/gpiomem -d adann0/squeak-catfeeder:latest

Le push button se branche sur le GPIO i et j. Le Servo sur le GPIO x, y et z.

## Recréer l'image

    $ git clone https://github.com/adann0/squeak-catfeeder.git &&
    cd squeak-catfeeder &&
    docker build . -f Dockerfile &&
    



## Le Bug du Crash de la VM

Lorsque l'on click sur "Feed" sur l'interface web, le servo tourne, et lorsque Squeak appel la fonction gpioStop(), la VM plante. Pourtant j'ai testé la fonction gpioStop() qui ne pose aucun problème lorsque la méthode est appelé autrement que par un click sur la page web, et j'ai testé le click sur la page web sur une methode renvoyant quelque chose d'autre et ça ne fait pas planter la VM... J'ai au début pensé que c'était à cause d'un upgrade sur Seaside, mais en faisant un serveur web classique sur Squeak, le bug était toujours là... Et ma version de Squeak est la même que lorsque ça fonctionnait. Deux solutions, pigpio qui a peut-être changé quelque chose, ou Raspbian.

Docker relance la VM si celle-ci plante, et comme feeder par le web n'est la que en dernier recours je ne mettrais pas plus de temps sur ce bug je pense... On verra sur Docker si le bug est toujours la. Il reste le push button a faire et la caméra (je pensais a tord que je pourrais faire des ptit trucs sur Squeak avec la caméra mais elle n'utilise par les pin gpio...)

Voici une vidéo ou j'explique comment retrouver ce bug en partant de la VM backup du projet : (a faire)

Solution ? https://github.com/OpenSmalltalk/opensmalltalk-vm/releases/tag/r3732#linux

## Plus de détails


# Sources :

  - Seaside : http://seaside.st/
  - Monticello : http://book.seaside.st/book/getting-started/pharo/monticello
  - PiGPIO : https://github.com/joan2937/pigpio
  - C Library for PiCamera : https://raspberrypi.stackexchange.com/questions/55140/library-to-allow-use-of-pi-camera-in-projects
  - Pharo-VNC-Supervisor : https://github.com/mumez/pharo-vnc-supervisor
  - Seaside Introduction : https://www.youtube.com/watch?v=9pdJxubR8yE&list=PLE08F4511BC5E3A91
  - Raspberry Camera Live Stream : https://tutorials-raspberrypi.com/raspberry-pi-security-camera-livestream-setup/
  - Squeak CheatSheet : https://wiki.squeak.org/squeak/5699
  - Squeak from Command Line : http://forum.world.st/Command-Line-Squeak-Scripting-Status-tp59746p59748.html
  - Squeak vers Stdout : http://forum.world.st/Using-squeak-with-a-script-tp4935336p4935527.html
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
