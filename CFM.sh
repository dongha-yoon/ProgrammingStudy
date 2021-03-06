#Cpp_File_Manager.sh

# execution
#   $./CFM.sh [make/build/exec] [filename] (without.cpp)

# arg = "$1"
filename=source/$1.cpp
execfile=execution/$1
function makecpp(){
    if test -f $filename; then
        echo "File is already exist!"
        exit 1
    else
        echo "${filename} is created."
        cp format.cpp "${filename}"
    fi
}
function build(){
    if test -f $filename; then
        g++ -o "$execfile" "$filename"
    else
        echo "There's no file name of $2.cpp"
        exit 2
    fi
}
function execute(){
    if test -f $filename; then
        "./$execfile"
    else
        build
        "./$execfile"
    fi
}

if [ "$2" == "-make" ]; then
    makecpp
elif [ "$2" == "-build" ]; then
    build
elif [ "$2" == "-exec" ]; then
    execute
else
    echo "please enter valid parameter"
fi


