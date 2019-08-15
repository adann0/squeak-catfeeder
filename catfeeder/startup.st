StandardFileStream stdout nextPutAll: '[CatFeeder] Launch...'; cr; flush.
FFI new gpioInitialise ;
gpioSetMode:15 with:1 ;
gpioSetMode:25 with:0.
StandardFileStream stdout nextPutAll: '[CatFeeder] Ready... Wait for actions.'; cr; flush.
PushButton new wait.
