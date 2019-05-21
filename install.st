Installer ensureRecentMetacello.

print value: 'Installing Seaside'.
Metacello new
 baseline:'Seaside3';
 repository: 'github://SeasideSt/Seaside:master/repository';
 load
