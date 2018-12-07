#!/bin/bash
filename='ISP.txt'
echo $filename
#exec < $filename


ISP_NAME=$(grep "starthub" ISP.txt | awk -F '_' '{print $2}')
echo $ISP_NAME
