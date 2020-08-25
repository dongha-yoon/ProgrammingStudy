filename=source/$1.cpp

if test -f $filename; then
    echo "File is already exist!"
    exit 1
else
    echo "${filename} is created."
    cp format.cpp "${filename}"
fi
