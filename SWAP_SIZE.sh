#!/bin/bash 

pool_size=$1
SWAP_SIZE=$(($pool_size -$pool_size % 10000))
echo "SWAP_SIZE is" $SWAP_SIZE
