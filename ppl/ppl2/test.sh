# Nathan Huffman

#! /usr/bin/env bash
# use command ./test.sh to run test file

EXE=./simple.exe
DIR="inputs/inputs/"

pass=(expr1 expr3 for1 for2 for3 for4 if1 if2 if3 if4 read1 repeat1 while1 write1)
fail=(expr2 expr4 if5 if6 if7 if8 read2 repeat2 repeat3 repeat4 while2 while3 write2)

make

echo ---PASS---

for p in ${pass[@]}; do
    $EXE < ${DIR}${p}_pass.smp
done

echo ---FAIL---

for f in ${fail[@]}; do
    $EXE < ${DIR}${f}_fail.smp
done