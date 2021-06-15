echo "----user ID----"
echo $USER
echo "----path----"
pwd
echo "----active users in file USERS----"
echo $who > USERS
echo "----home----"
ls ~
echo "----third line----"
cat main.cpp | head -n 3
echo "----hello world----"
cat main.cpp
echo "----execute----"
g++ main.cpp -o main.out
./main.out >> hello
echo "----calendar in birth----"
cal 07 2000 >> birth
