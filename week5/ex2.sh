if [[ ! -f ex2.txt ]]; then echo 1 >> ex2.txt; fi

while true; do

  until ln ex2.txt ex2.txt.lock &>/dev/null; do
    sleep 1
  done
  
  expr $(tail -n 1 ex2.txt) + 1 >> ex2.txt;


  rm -f ex2.txt.lock;
done
