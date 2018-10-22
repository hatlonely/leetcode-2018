if [[ $1 == "" ]]; then
    while read line; do
        g++ -std=c++11 $line -lgtest && ./a.out
    done
else
    g++ -std=c++11 $1 -lgtest && ./a.out
fi