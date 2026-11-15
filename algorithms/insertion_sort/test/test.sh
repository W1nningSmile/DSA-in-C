for i in 10 50 100 1000 10000 100000; do
  shuf -i 1-1000000 -n $i > unsorted.txt
  echo "i=$i"
  (time ./main > /dev/null) 2>&1
done
