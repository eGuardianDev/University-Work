#!/bin/bash


for i in {1..11}
do 
	racket $i.rkt | grep "#f"
done
