echo set\(SOURCES > $1
find src/ -name *.cpp | sed 's/^/\t/' >> $1
find src/ -name *.hpp | sed 's/^/\t/' >> $1
find src/ -name *.h | sed 's/^/\t/' >> $1
echo \) >> $1
