#/bin/sh

if [ $# -lt 1 ]; then
    echo "must pass a #"
    exit
fi

export out=out
export c=/home/wally/cppCheck/cppcheck-1.61
export I=/home/wally/trunk/base/include

if [ $# -lt 2 ]; then 
    ## this is 'quick' mode
    $c/cppcheck  --report-progress --enable=all --std=c89 -v $1 2>$out
    exit
fi

## this is long run
echo "running -- this may take some time "
$c/cppcheck  --report-progress --enable=all --std=c89 -I$I -UNCO -v $1 2>$out
