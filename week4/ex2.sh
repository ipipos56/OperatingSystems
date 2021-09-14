gcc -o ex2 ex2.c

pstree
./ex2

for i in {1..20}; do
  sleep 1
  pstree
done
