for entry in ./*.in
do
	$1 < "$entry" > ${entry::-3}.ans
done
