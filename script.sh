#!/bin/bash

VERSION=Squeak5.2-18229-32bit-201810190412-ARMv6

wget http://files.squeak.org/5.2/Squeak5.2-18229-32bit/$VERSION.zip &&
unzip $VERSION.zip &&
$VERSION/bin/squeak $VERSION/shared/Squeak5.2-18229-32bit.image install.sh
#$VERSION/bin/squeak -vm-sound-null -vm-display-null -headless $VERSION/shared/Squeak5.2-18229-32bit.image install.sh
