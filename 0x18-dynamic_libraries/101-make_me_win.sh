#!/bin/bash
gcc -shared -o 101-winning.so -fPIC 101-winning.c
cp 101-winning.so /tmp/101-winning.so
echo -e '#!/bin/bash\n\nrm 101-winning.so\nrm 101-make_me_win.sh\n' > /tmp/run_me.sh
chmod +x /tmp/run_me.sh
