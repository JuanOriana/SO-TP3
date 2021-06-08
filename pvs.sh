#!/bin/bash
pvs-studio-analyzer trace -- make
pvs-studio-analyzer analyze
plog-converter -a '64:1,2,3;GA:1,2,3;OP:1,2,3' -t tasklist -o report.tasks PVS-Studio.log
rm -f strace_out
rm -f PVS-Studio.log