#!/bin/bash

VERSION=5.2
ARCH=32bit
ARM=Linux-ARM
RELEASE=Squeak$VERSION-18229-$ARCH
IMAGE=$RELEASE-All-in-One

wget http://files.squeak.org/$VERSION/$RELEASE/$IMAGE.zip &&
unzip $IMAGE.zip &&
./$IMAGE.app/Contents/$ARM/bin/squeak -vm-sound-null -vm-display-null -headless $IMAGE.app/Contents/Resources/$RELEASE.image /install.st
#$VERSION/bin/squeak -vm-sound-null -vm-display-null -headless $VERSION/shared/Squeak5.2-18229-32bit.image install.sh
