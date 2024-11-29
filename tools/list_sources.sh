echo listing sources in $1
echo sources found:
echo set\(SOURCES > $1
find src/ -name *.cpp | sed 's/^/\t/' | tee -a $1
find src/ -name *.hpp | sed 's/^/\t/' | tee -a $1
find src/ -name *.h | sed 's/^/\t/' | tee -a $1
echo \) >> $1
