| print |

print := [:msg | | str |
    str := ' ---> ', msg.
    FileStream stdout nextPutAll: str; nextPut: Character lf; flush.
    Transcript cr; show: str].

print value: 'Installing Metacello'.
Installer ensureRecentMetacello.

print value: 'Installing Seaside'.
Metacello new
 baseline:'Seaside3';
 repository: 'github://SeasideSt/Seaside:master/repository';
 load.
 
print value: 'Done'.
 
