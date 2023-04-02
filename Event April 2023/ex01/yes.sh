while true
do
	ls . | rev | cut -c4- | rev
done