FILENAME=$1;

./asm/asm "resources/champions/examples/"$FILENAME".s"
mv "resources/champions/examples/"$FILENAME".cor" .
hexdump -Cv $FILENAME".cor" > mine
hexdump -Cv "resources/champions/examples/compiled/"$FILENAME".cor" > orig
rm $FILENAME".cor"
diff mine orig
