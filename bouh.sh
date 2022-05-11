#!/bin/bash

fake_data="$(echo {a..z})"
for i in {1..100}
do
	./client_bonus $1 "$fake_data"
	sleep 0.01
done
