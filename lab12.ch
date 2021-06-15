#-------6-----------
a = 9
b = 11
if [$a -eq $b ]
then 
echo "true, $a = $b"
elseif [ $a -ge $b ]
	c = a - b
else
	c = b - a
echo "false, diff btwn = $c"
fi
#-------7----------
cp main.cpp testmain
#-------8---------
if [ -x "cmd.ch" ]
then 
cat cmd.ch
else
echo "false"
fi

#------10-------
i=0
while IFS= read -r line
do 
cat testmain | head -n $i
i=$((i+1))
done < testmain
#------11-------
for i in `ls /home/go`
do
	if [ -w /home/go/$i ]
	then
	echo "true"
	else
	echo "false"
	fi
done
#------12-------

read -s -t 4 -p "enter your password: " pass
if [ $pass = "hello" ]
then
read -p "enter your name: " name
echo "hello $name"
g++ main.cpp -o main.out
./main.out >> hello
./main.out
else
echo "wrong password"
fi
