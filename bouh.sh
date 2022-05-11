#!/bin/bash

fake_data="$(echo {a..z})"
for i in {1..300}
do
	./client $1 "$fake_data"
	sleep 0.1
done
